// 控制屏幕显示
// led
// led开时
#define LED_OPEN "page0.led.txt=\"开\"\xff\xff\xffpage0.p0.pic=11\xff\xff\xffpage0.led.pco=64520\xff\xff\xff"		//当屏幕从串口接收到前面的字符串时，会让led灯开关在屏幕上显示“开”（注意字符串里的内容必须完全相同才能生效）
// led关时
#define LED_OPEN"page0.led.txt=\"关\"\xff\xff\xffpage0.p0.pic=10\xff\xff\xffpage0.led.pco=65535\xff\xff\xff"

// FAN
// FAN开时
#define LED_OPEN"page0.FAN.txt=\"开\"\xff\xff\xffpage0.p2.pic=13\xff\xff\xffpage0.FAN.pco=28086\xff\xff\xff"	//让风扇开关在屏幕上显示“”
// FAN关时
#define LED_OPEN"page0.FAN.txt=\"关\"\xff\xff\xffpage0.p2.pic=12\xff\xff\xffpage0.FAN.pco=65535\xff\xff\xff"

// 窗帘
// 窗帘半开时
#define LED_OPEN"page0.curtain.txt=\"半开\"\xff\xff\xffpage0.p1.pic=21\xff\xff\xffpage0.curtain.pco=7837\xff\xff\xff"	//让窗帘开关在屏幕上显示“”
// 窗帘全开时
#define LED_OPEN"page0.curtain.txt=\"全开\"\xff\xff\xffpage0.p1.pic=22\xff\xff\xffpage0.curtain.pco=7837\xff\xff\xff"
// 窗帘关时
#define LED_OPEN"page0.curtain.txt=\"关\"\xff\xff\xffpage0.p1.pic=20\xff\xff\xffpage0.curtain.pco=65535\xff\xff\xff"

// 水泵
// 水泵开时
#define LED_OPEN"page0.pump.txt=\"开\"\xff\xff\xffpage0.p3.pic=15\xff\xff\xffpage0.pump.pco=32464\xff\xff\xff"	//让水泵开关在屏幕上显示“开”
// 水泵关时
#define LED_OPEN"page0.pump.txt=\"关\"\xff\xff\xffpage0.p3.pic=14\xff\xff\xffpage0.pump.pco=65535\xff\xff\xff"

// 蜂鸣器
// 蜂鸣器开时
#define LED_OPEN"page0.BEEP.txt=\"开\"\xff\xff\xffpage0.p4.pic=19\xff\xff\xffpage0.BEEP.pco=64677\xff\xff\xff"	//让水泵开关在屏幕上显示“开”
// 蜂鸣器关时
#define LED_OPEN"page0.BEEP.txt=\"关\"\xff\xff\xffpage0.p4.pic=18\xff\xff\xffpage0.BEEP.pco=65535\xff\xff\xff"

// 火焰传感器
// 有火焰
#define LED_OPEN"page1.p1.pic=26\xff\xff\xff"
// 无火焰
#define LED_OPEN"page1.p1.pic=25\xff\xff\xff"

// 烟雾传感器
// 烟雾超量
#define LED_OPEN"page1.p2.pic=28\xff\xff\xff"	
// 空气正常
"page1.p2.pic=27\xff\xff\xff"

// 温度显示
"page1.hum.val=366\xff\xff\xff"	//这里假设采集到的数据是36.6（注意他没有小数的概念，需要转换成纯数字）
// 湿度显示
"page1.tem.val=366\xff\xff\xff"	//这里假设采集到的数据是36.6（注意他没有小数的概念，需要转换成纯数字）

// 光照
"page2.light.txt=\"308\"\xff\xff\xff"	//这里假设采集到的数据是308

// 红外检测
// 无遮挡
"page2.distance.txt=\"无遮挡\"\xff\xff\xffpage2.j0.val=0\xff\xff\xffpage2.p1.pic=32\xff\xff\xffpage2.distance.pco=65535\xff\xff\xff"	//这里假设采集到的数据是无遮挡
// 有遮挡
"page2.distance.txt=\"有遮挡\"\xff\xff\xffpage2.j0.val=100\xff\xff\xffpage2.p1.pic=31\xff\xff\xffpage2.distance.pco=32799\xff\xff\xff"

// 控制开关
// led
当led按下为关时，会向串口发送"led = 关"
当led按下为开时，会向串口发送"led = 开"
// FAN
当FAN按下为关时，会向串口发送"FAN = 关"
当FAN按下为开时，会向串口发送"FAN = 开"
// 步进电机（窗帘）
当窗帘按下为关时，会向串口发送"curtain = 关"
当窗帘按下为半开时，会向串口发送"curtain = 半开"
当窗帘按下为全开时，会向串口发送"curtain = 全开"
// 水泵
当水泵按下为关时，会向串口发送"pump = 关"
当水泵按下为开时，会向串口发送"pump = 开"
// 蜂鸣器
当蜂鸣器按下为关时，会向串口发送"BEEP = 关"
当蜂鸣器按下为开时，会向串口发送"BEEP = 开"

