#include "stdafx.h"
#include "function.h"
//ͷ�ļ�
#include <winsock2.h>
#include <windows.h>

//���ļ�
#pragma comment(lib, "ws2_32.lib")

#define _WINSOCK_DEPRECATED_NO_WARNINGS

SOCKET s;


int InitSocket() {
	//windows�����⣬��Ҫ��������api����������ĳ�ʼ���ͷ���ʼ��
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	//��ʼ������
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		return 0;
	}

	//1. socket ����һ���׽��֣��������ɹܵ���pipe��������ں��������ݴ���ӿڣ�
	s = socket(
		AF_INET, //INETЭ���
		SOCK_STREAM, //��ʾʹ�õ���TCPЭ��
		0);
	if (s == INVALID_SOCKET) {
		return 0;
	}

	//2. bind /listen   ��/�����˿�
	// IP ��ַ�� �����������еļ�ͥ��ַ���ܶ�����Ӧ�ã�
	// �˿ڣ� �����������ĸ�Ӧ�õ����ݣ�ֻ��һ�����0-65535�� 3389�˿� RDP 80�˿� ��ҳ����� http
	// 53 dns 443 https 135/137 20/21 ftp  pop3/smtp 25
	// һ��Ӧ���������ʹ�ö��ٸ��˿ڣ�
	//�������ж��ٸ�tcp����
	//Դip:Դ�˿�          ---------------  Ŀ��ip��Ŀ��˿�      

	//��ѡһ�������������û��ʹ�õĶ˿���ʹ��
	//sockaddr s; //���� ����Ip�Ͷ˿ڵĽṹ��,�����ã���Ϊ�ڲ���һ������
	sockaddr_in addr; //�����滻sockaddr�ṹ�壬���ߴ�Сһ��
	int nLength = sizeof(sockaddr_in);
	addr.sin_family = AF_INET; //д��
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); //�̶���·����д����ip �򱾵�ip 127.0.0.1
	addr.sin_port = htons(10087); //h:host to n:network short �ӣ� �����ֽ��򣨴�β��ʽ���ͱ����ֽ���Сβ��ʽ��

	return 1;
}