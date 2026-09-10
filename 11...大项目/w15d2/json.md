了解json
Json入门教程：了解Json基本的概念
json数据类型
```
● number：数字型，和JavaScript的number完全一致；包括整型和浮点
● boolean：就是JavaScript的true或false；相当于c++中的bool类型
● string：就是JavaScript的string；相当于c++的string类型
● null：就是JavaScript的null；相当于C的NULL类型
● array：就是JavaScript的Array表示方式——[]；相当于C的数组
● object：就是JavaScript的{ ... }表示方式。相当于C++的类或者C的结构体
```
注意：json的数据类型在源码实现中和具体的编程语言有关，比如boolean在C中并没有相应的类型，C相关的实现库可能会用0和1表示。
格式规范
```
● json以大括号起始和结尾（最常见），本质上6种基本类型都可
● 内容都是以键值对的形式存在
● 所有的键都是字符串
● 值的类型不一定，属于JavaScript 的基本数据类型
● 每个键值对以,分割
● 最后一个键值对不加逗号
```
```json
{
  "name": "小明",
  "age": 14,
  "gender": true,
  "height": 1.65,
  "grade": null,
  "skills": [
    "JavaScript",
    "Java",
    "Python",
    "Lisp"
  ]
}
```
json格式校验
https://www.json-online.com/check/
JSON基本操作
Json序列化：可以理解为利用程序生成Json字符串的过程。
Json反序列化：可以理解为利用程序将已有的Json字符串解析出我们需要的值的过程。
cJson
官方地址
cJSON的github地址（这个不用看，相当于官方源码地址）
https://github.com/DaveGamble/cJSON

关键接口梳理
```c
/****************************通用数据结构/接口****************************/
/* 类型定义 */
#define cJSON_False 0
#define cJSON_True 1
#define cJSON_NULL 2
#define cJSON_Number 3
#define cJSON_String 4
#define cJSON_Array 5
#define cJSON_Object 6

/* CJSON核心结构体 */
typedef struct cJSON {
	struct cJSON *next,*prev;	/* next/prev allow you to walk array/object chains. Alternatively, use GetArraySize/GetArrayItem/GetObjectItem */
	struct cJSON *child;		/* An array or object item will have a child pointer pointing to a chain of the items in the array/object. */

	int type;					/* 节点的类型，取值是上面的6种 */

	char *valuestring;			/* 如果类型是cJSON_String，那么值会被存到这里 */
	int valueint;				/* 如果类型是cJSON_Number，且是整型，那么值会被存到这里 */
	double valuedouble;			/* 如果类型是cJSON_Number，且是浮点型，那么值会被存到这里 */

	char *string;				/* 键*/
} cJSON;


//释放节点的内存，防止内存泄露
void   cJSON_Delete(cJSON *c);
/****************************反序列化相关接口****************************/
//把传入的字符串转成cJSON的结构（反序列化）
cJSON *cJSON_Parse(const char *value);
//获取数组的大小
int	  cJSON_GetArraySize(cJSON *array);
//从array数组中获取第item个子节点
cJSON *cJSON_GetArrayItem(cJSON *array, int index);
//获取object大节点名字叫string的子节点
cJSON *cJSON_GetObjectItem(cJSON *object,const char *string);
//判断object大节点中是否有名字叫string的小节点
int cJSON_HasObjectItem(cJSON *object,const char *string);

/****************************序列化相关接口****************************/
//把cJSON结构转成字符串（序列化），调用后需要配合free接口释放malloc的内存
char  *cJSON_Print(cJSON *item);
//无格式化序列化，节省内存，调用后需要配合free接口释放malloc的内存
char  *cJSON_PrintUnformatted(cJSON *item);

//创建一个普通节点
cJSON *cJSON_CreateObject(void);
//创建一个数组节点
cJSON *cJSON_CreateArray(void);
//把item节点增加到array的数组节点中
void cJSON_AddItemToArray(cJSON *array, cJSON *item);
//把item节点增加到object中作为子节点，item节点的键名为string
void cJSON_AddItemToObject(cJSON *object, const char *string, cJSON *item);

//创建各种类型的cJSON节点
cJSON *cJSON_CreateNull(void);
cJSON *cJSON_CreateTrue(void);
cJSON *cJSON_CreateFalse(void);
cJSON *cJSON_CreateBool(int b);
cJSON *cJSON_CreateNumber(double num);  //这个接口只需要传入整形形参，double会自动强转
cJSON *cJSON_CreateString(const char *string);
cJSON *cJSON_CreateArray(void);
cJSON *cJSON_CreateObject(void);
```
练习
反序列化
使用cJSON库对下面的JSON文件进行反序列化操作（将下面内容存为文件，读取后解析即可）。
```json
{
	"ver": "1.0",
	"login": {
		"user": "zhangsan",
		"pwd": 1234
	},
	"data": [{
      "key": 1,
      "type": 2,
      "val": "10"
    },
    {
      "key": 2,
      "type": 1,
      "val": "0"
    },
    {
      "key": 3,
      "type": 3,
      "val": "22.5"
    }
	]
}
```
序列化
使用cJSON库序列化出下面的JSON内容。
```json
{
  "name": "小明",
  "age": 14,
  "gender": true,
  "height": 1.65,
  "grade": null,
  "skills": [
    "JavaScript",
    "Java",
    "Python",
    "Lisp"
  ]
}
```
JSON内容本身的合法性，与键值对在对象中的书写顺序无关。
编译注意事项
gcc *.c -o test -lm，*.c代表的是编译这个目录里所有的C文件，而cJSON.c需要依赖一些数学函数，所以需要加入-lm链接math库。
