# STM32（51-04 SPI 数码管 LCD）
# 1.SPI总线
## 简单介绍
SPI接口是Motorola 首先提出的全双工三/四线同步串行外围接口采用主从模式（Master Slave）架构。
时钟由Master控制，在时钟移位脉冲下，数据按位传输，高位在前，低位在后（MSB first）；SPI接口有2根单向数据线，为全双工通信。
SPI总线被广泛地使用在FLASH、ADC、LCD等设备与MCU间，要求通讯速率较高的场合。
## SPI的拓扑结构
![alt text](images/image.png)
SPI总线通常会有四根线，分别是时钟线，串行输出数据线，串行输入数据线，片选线。
1.SCLK：时钟线，时钟信号由主机产生
2.MOSI：主机输出，从机输入
3.MISO：主机输入，从机输出
4.NSS：片选线，选择通信的从机，低电平有效。
三线的使用场景：在引脚资源受限的情况下
单工：只保留一根单向的数据线。
半双工：只保留一根双向的数据线。
![alt text](images/image-1.png)
## SPI的时序单元
起始条件：SS从高电平切换到低电平
结束条件：SS从低电平切换到高电平
## SPI字节交换原理
![alt text](images/image-2.png)
●字节交换原理基于位进行交换的。
●位交换分为了两部分：移入和移出。
●移出：就是把当前移位寄存器的最高位写到信号线上，然后整体向左移动一位。
●移入（采样）：读取信号线上的电平状态，然后把读取到的电平状态放到移位寄存器的最低位。
●移入和移出是主机和从机同时进行的。
●按照时钟线约定好的上升沿和下降沿。

主机产生时钟信号并且输送给从机，在SPI通信开始前，主机将要发送的数据写入到发送数据寄存器，数据被传送到发送移位寄存器，根据SPI的工作模式，在特定的时钟边沿触发数据移位操作。主机通过MOSI引脚将移位寄存器中的数据逐位发送给从机，同时从机通过MISO引脚将自身的数据逐位发送给主机，实现主机与从机之间的字节交换。
## SPI的工作模式
SPI的工作模式由CPOL（时钟极性）以及CPHA（时钟相位）共同决定。将SPI分为了四种工作模式。主机和从机需要在相同的模式下才能工作。主机按照从机支持的模式去配置的。

![alt text](images/image-3.png)
采样为字节交换原理中的移入操作
1. 当CPOL = 0，CPHA = 0
空闲状态，时钟线为低电平
数据在奇数边沿被采样，上升沿被采样，下降沿数据发生变化。
2. 当CPOL =0，CPHA =1
空闲状态，时钟线为低电平
数据在偶数边沿被采样，下降沿被采样，上升沿数据发生变化。
3. 当CPOL =1，CPHA =0
空闲状态，时钟线为高电平
数据在奇数边沿被采样，下降沿被采样，上升沿数据发生变化。
4. 当CPOL =1，CPHA =1
空闲状态，时钟线为高电平
数据在偶数边沿被采样，上升沿被采样，下降沿数据发生变化。
![alt text](images/image-4.png)

# 2. 数码管
## 简单介绍
LED数码管（LED Segment Displays）是由8个发光二极管构成，并按照一定的图形及排列封装在一起的显示器件。其中7个LED构成7笔字形，1个LED构成小数点（固有时称为八段数码管）。
LED数码管有两大类，一类是共阴极接法，另一类是共阳极接法，共阴极就是7段的显示字码共用一个电源的负极，是高电平点亮，共阳极就是7段的显示字码共用一个电源的正极，是低电平点亮。

![alt text](images/image-5.png)

## 74HC595分析
### 简单介绍
https://blog.csdn.net/ReCclay/article/details/78245642  
### 开发板上的595芯片
在我们开发板的数码管的旁边，就有两个级联的595芯片
       实物图                           芯片原理图
![alt text](images/image-6.png)

### 原理图分析
![alt text](images/image-7.png)
总结：一个输入，多个输出，一脚控多脚，串行转并行
数码管的连接显示
![alt text](images/image-8.png)

我们本次所使用的是一款四段共阴极八位数码管，每个数码管的使能相对独立，各个数码管使用对应的三极管（NPN）进行使能控制。
由于数码管所需的管脚较多，我们使用SPI总线+74HC595（背过）芯片实现对数码管的控制。
![alt text](images/image-9.png)
通过分析原理图我们找到了芯片连接74HC595的控制引脚
![alt text](images/image-10.png)
```c
1. SPI2_SCK:时钟线----PB13
2. SPI2_MOSI:主机输出，从机输入----PB15
3. SPI2_NSS:片选----PB12-----GPIO_OUTPUT
4. SPI2_MISO:主机输入-----不关心 PB14

```
![alt text](images/image-11.png)

![alt text](images/image-12.png)

# 3.LCD
## 原理

![alt text](images/image-13.png)

## ILI9341（显示驱动芯片）
1. ILI9341是一个支持分辨率为240RGBx320点阵的a-TFT LCD 的262144（2^18）色单片驱动器。这个单片驱动器包含了一个720通道的源极驱动器（source driver)，一个320通道的栅极驱动器（gate driver），172800字节的GRAM用于显示240RGB x 320分辨率的图片数据，一套电源支持电路。
2. ILI9341提供8位/9位/16位/18位的并行MCU数据总线，6位/16位/18位RGB接口数据总线以及3或4线SPI接口（serial peripheral interface）。通过窗口地址函数，显示区域被指定在GRAM内。这个指定的窗口区域可以被有选择地更新，因此显示区域能够同时被显示在静态图像的区域内。
3. ILI9341的IO接口电压工作于1.65V-3.3V。一种合并的电压跟随电路，用以产生驱动液晶显示器的电压电平。ILI9341支持full color ，8-color显示模式，支持由软件控制的精确电源睡眠模式。这些功能使ILI9341成为类似于移动电话，小电话，MP3需要电池长效工作的中等或小尺寸便携产品的理想驱动器。

## 原理图
![alt text](images/image-14.png)
```
SPI1——NSS    PA4
SPI1——SCK    PA5
SPI1——MISO   PA6
SPI1——MOSI   PA7

LCD——RESET   PA8      屏幕的复位引荐，将所有的颜色设置为初始的状态
```

![alt text](images/image-15.png)




```c
/* USER CODE BEGIN 0 */
//定义一个保存了所有数字显示状态的数组
const uint8_t number[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; //数字显示

//定义一个用于保存想要显示的数字的变量
volatile uint16_t show_number = 0x1234;	//使用volatile使变量不被优化，每次都刷新读取

//数码管显示函数
void led_dispaly()
{
	uint8_t which_where_data[2] = {0x00, 0x00};		//创建一个用于保存段选与位选的数组
	
	//使用switch进行判断，由于一次只能点亮一个，需要引入一个变量进行自增，循环对应各数码管
	static uint8_t choose = 0;		//用于位循环
	
	switch(choose)
	{
		case 0:
			which_where_data[0] = 0x08;	//1-4位顺序为 0x01	0x02	0x04	0x08
			which_where_data[1] = number[show_number & 0x000F];	//将想要显示的数字与之相&，就相当于盖上了其他位
		
			//SPI传输函数，参数为使用的SPI通道、要传输的数据、数据长度、超时时间
			HAL_SPI_Transmit(&hspi2,which_where_data,2,10);
		
			//进行锁存操作，等效于写入一高一低电平
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
			HAL_Delay(1);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
		
			choose++;	//移动至下一位
		break;
		case 1:
			which_where_data[0] = 0x04;	//1-4位顺序为 0x01	0x02	0x04	0x08
			which_where_data[1] = number[show_number>>4 & 0x000F];	// >>4	取第三位

			//SPI传输函数，参数为使用的SPI通道、要传输的数据、数据长度、超时时间
			HAL_SPI_Transmit(&hspi2,which_where_data,2,10);
			//进行锁存操作，等效于写入一高一低电平
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
			HAL_Delay(1);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
			choose++;	//移动至下一位
		break;
		case 2:
			which_where_data[0] = 0x02;	//1-4位顺序为 0x01	0x02	0x04	0x08
			which_where_data[1] = number[show_number>>8 & 0x000F];
			//SPI传输函数，参数为使用的SPI通道、要传输的数据、数据长度、超时时间
			HAL_SPI_Transmit(&hspi2,which_where_data,2,10);		
			//进行锁存操作，等效于写入一高一低电平
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
			HAL_Delay(1);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
		
			choose++;	//移动至下一位
		break;
		case 3:
			which_where_data[0] = 0x01;//1-4位顺序为 0x01	0x02	0x04	0x08
		which_where_data[1] = number[show_number>>12 & 0x000F];	
			//SPI传输函数，参数为使用的SPI通道、要传输的数据、数据长度、超时时间
			HAL_SPI_Transmit(&hspi2,which_where_data,2,10);	
			//进行锁存操作，等效于写入一高一低电平
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
			HAL_Delay(1);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
			choose = 0;	//移动循环
		break;
	}	
}
/* USER CODE END 0 */


```