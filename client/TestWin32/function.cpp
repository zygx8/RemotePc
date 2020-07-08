#include "stdafx.h"
#include "function.h"
//头文件
#include <winsock2.h>
#include <windows.h>

//库文件
#pragma comment(lib, "ws2_32.lib")

#define _WINSOCK_DEPRECATED_NO_WARNINGS

SOCKET s;


int InitSocket() {
	//windows很特殊，需要单独调用api来进行网络的初始化和反初始化
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	//初始化操作
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		return 0;
	}

	//1. socket 创建一个套接字（可以理解成管道的pipe句柄，用于后续的数据传输接口）
	s = socket(
		AF_INET, //INET协议簇
		SOCK_STREAM, //表示使用的是TCP协议
		0);
	if (s == INVALID_SOCKET) {
		return 0;
	}

	//2. bind /listen   绑定/监听端口
	// IP 地址： 类似于网络中的家庭地址（很多网络应用）
	// 端口： 用于区分是哪个应用的数据，只是一个编号0-65535， 3389端口 RDP 80端口 网页浏览器 http
	// 53 dns 443 https 135/137 20/21 ftp  pop3/smtp 25
	// 一个应用软件可以使用多少个端口？
	//看这里有多少个tcp连接
	//源ip:源端口          ---------------  目标ip：目标端口      

	//挑选一个本机其他软件没有使用的端口来使用
	//sockaddr s; //用于 描述Ip和端口的结构体,不好用，因为内部是一个数组
	sockaddr_in addr; //用于替换sockaddr结构体，两者大小一致
	int nLength = sizeof(sockaddr_in);
	addr.sin_family = AF_INET; //写死
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); //固定套路，填写外网ip 或本地ip 127.0.0.1
	addr.sin_port = htons(10087); //h:host to n:network short 坑， 网络字节序（大尾方式）和本地字节序（小尾方式）

	return 1;
}