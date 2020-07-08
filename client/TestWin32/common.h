#pragma once

//定义一些公共的结构体等


//定义一些宏，来表示包的具体处理类型
///cmd类型数据
#define PACKET_REQ_CMD  10001 //REQ requset CMD 表示cmd类型请求数据 客户端--> 服务端
#define PACKET_RLY_CMD  10002 //RLY reply   CMD 表示cmd类型回复数据 服务端--> 客户端
///键盘类型数据
#define PACKET_REQ_KEYBOARD  20001 //REQ requset 键盘 表示键盘类型请求数据 客户端--> 服务端
#define PACKET_RLY_KEYBOARD  20002 //RLY reply   键盘 表示键盘类型回复数据 服务端--> 客户端


//对齐 按1字节对齐
#pragma  pack(push) //表示原有的结构体对齐值大小压栈
#pragma pack(1)
struct MyPacket{
	unsigned int type; //表示包类型
	unsigned int length; //表示长度
	char data[1]; //定义一个1字节的数组，柔性数组
};
#pragma  pack(pop) //表示原有的结构体对齐值大小出栈