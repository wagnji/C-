// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


// DuokehuServer.cpp : Ϊ��ͻ��ṩ����ķ������˳���
//

#include<iostream>
#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h>
#include<string.h>
#pragma comment (lib,"ws2_32.lib")
#pragma warning(disable :4996)
#define SERVER_PORT "8888"
#define BUFFER_LEN  512
using namespace std;

int main(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;
	struct addrinfo hints, *result = NULL;
	struct sockaddr_in clientaddr;
	char sendbuf[BUFFER_LEN];
	char recvbuf[BUFFER_LEN];
	int iResult, isendResult;

	memset(recvbuf, 0, BUFFER_LEN * sizeof(char));
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;
	iResult = getaddrinfo(NULL, SERVER_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error %d\n", iResult);
		WSACleanup();
		return 1;
	}

	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET) {
		printf("socket failed with error %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}
	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		printf("listen failed with error %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	for (;;) {
		int addrlenth = sizeof(clientaddr);
		ClientSocket = accept(ListenSocket, (struct sockaddr*) & clientaddr, &addrlenth);
		if (iResult == INVALID_SOCKET) {
			printf("accept failed with error %d\n", WSAGetLastError());
			closesocket(ListenSocket);
			WSACleanup();
			return 1;
		}

		char* peeraddr = inet_ntoa(clientaddr.sin_addr);
		int i = 0;
		do {
			iResult = recv(ClientSocket, recvbuf, BUFFER_LEN, 0);
			if (iResult > 0)
			{
				i++;
				printf("���ܵĵ�%d����Ϣ\n", i);//��ʾ�յ�����Ϣ��
				printf("�ֽڳ���: %d\n", iResult);//��ʾ�ֽڳ���
				printf("������Ϣ: %s\n", recvbuf);//��ʾ���յ���Ϣ
				printf("��ԴIP: %s\n\n", peeraddr);//��ʾ�յ�����Ϣ���Է���IP��ַ
				ZeroMemory(&recvbuf, sizeof(hints));
				isendResult = send(ClientSocket, sendbuf, strlen(sendbuf), 0);
				if (isendResult == SOCKET_ERROR) {
					printf("send failed with error %d\n", WSAGetLastError());
					closesocket(ClientSocket);
					WSACleanup();
					break;
				}
			}
			else if (iResult == 0) {
				printf("Connection closing...\n");
				iResult = shutdown(ClientSocket, SD_SEND);
				if (iResult == SOCKET_ERROR) {
					printf("shutdown failed with error %d\n", WSAGetLastError());
					closesocket(ClientSocket);
					WSACleanup();
					break;
				}
				closesocket(ClientSocket);
				WSACleanup();
				break;
			}
			else {
				printf("�û����˳�\n");
				iResult = shutdown(ClientSocket, SD_SEND);
				if (iResult == SOCKET_ERROR) {
					printf("shutdown failed with error %d\n", WSAGetLastError());
					closesocket(ClientSocket);
					WSACleanup();
					break;
				}
			}

		} while (iResult > 0);
	}

	closesocket(ListenSocket);
	WSACleanup();
	return 0;
}


