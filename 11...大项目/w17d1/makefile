MQTT:MQTTClient_subscribe_copy.c cJSON.c
	sudo gcc $^ -o $@ -lpaho-mqtt3c -lm

sever:server_opencv.c cJSON.c
	gcc $^ -o $@ -lsqlite3 -lm
	
db:db_logger.c
	gcc $< -o $@ 