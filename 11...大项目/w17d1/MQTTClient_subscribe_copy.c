/*******************************************************************************
 * Copyright (c) 2012, 2017 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution.
 *
 * The Eclipse Public License is available at
 *   http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Ian Craggs - initial contribution
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MQTTClient.h"
#include "cJSON.h"

#define ADDRESS "tcp://192.168.1.142:1883"
#define CLIENTID "XIAOPGW"
#define TOPIC_D "DOWN"
#define TOPIC_U "UP" // 发布主题
#define PAYLOAD "Hello World!"
#define QOS 1
#define TIMEOUT 10000L

volatile MQTTClient_deliveryToken deliveredtoken;

void delivered(void *context, MQTTClient_deliveryToken dt)
{
    printf("Message with token value %d delivery confirmed\n", dt);
    deliveredtoken = dt;
}

int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    int i;
    char *payloadptr;

    printf("Message arrived\n");
    printf("     topic: %s\n", topicName);
    printf("   message: ");

    payloadptr = message->payload;
    // for(i=0; i<message->payloadlen; i++)
    // {
    //     putchar(*payloadptr++);
    // }
    // putchar('\n');

    cJSON *rtree = cJSON_Parse(payloadptr);
    if (rtree == NULL)
    {
        perror("tree->");
        return -1;
    }
    cJSON *Rname = cJSON_GetObjectItem(rtree, "name");
    cJSON *Rage = cJSON_GetObjectItem(rtree, "age");
    cJSON *Rmsg = cJSON_GetObjectItem(rtree, "msg");
    printf("name:%s\nage:%d\nmsg:%s\n\n\n", Rname->valuestring, Rage->valueint, Rmsg->valuestring);

    

    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

void connlost(void *context, char *cause)
{
    printf("\nConnection lost\n");
    printf("     cause: %s\n", cause);
}

int main(int argc, char *argv[])
{
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer; //
    MQTTClient_deliveryToken token;                             // 用于追踪发布状态//
    int rc;
    int ch;

    MQTTClient_create(&client, ADDRESS, CLIENTID,
                      MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered);

    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }
    MQTTClient_subscribe(client, TOPIC_D, QOS);
    printf("链接\n");
    char send[2048] = {};
    while (1)
    {
        scanf("%s", send);
        cJSON *stree = cJSON_CreateObject();
        if (stree == NULL)
        {
            perror("tree->");
            return -1;
        }

        cJSON_AddItemToObject(stree, "name", cJSON_CreateString("XIAOPGW"));
        cJSON_AddItemToObject(stree, "age", cJSON_CreateNumber(314526));
        cJSON_AddItemToObject(stree, "msg", cJSON_CreateString(send));

        char *tree = cJSON_Print(stree);
        // printf("%s\n", tree);

        memset(send, 0, sizeof(send));

        /* 4. 构造消息体 */
        pubmsg.payload = tree;
        pubmsg.payloadlen = (int)strlen(tree);
        pubmsg.qos = QOS;
        pubmsg.retained = 0; // 不保留消息

        /* 5. 发布消息（非阻塞，立即返回） */
        MQTTClient_publishMessage(client, TOPIC_U, &pubmsg, &token);
        printf("消息已发出，令牌 %d\n", token);

        /* 6. 等待 Broker 确认（阻塞，直至超时或确认） */
        rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
        if (rc == MQTTCLIENT_SUCCESS)
        {
            printf("消息送达确认，令牌 %d\n", token);
        }
        else
        {
            printf("等待确认失败，返回码 %d\n", rc);
        }
        cJSON_Delete(stree);
        free(tree);
    }

    // do
    // {
    //     ch = getchar();
    // } while (ch != 'Q' && ch != 'q');

    MQTTClient_unsubscribe(client, TOPIC_D);
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    return rc;
}
