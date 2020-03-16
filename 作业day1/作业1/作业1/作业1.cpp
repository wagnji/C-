// 作业1.cpp : 定义控制台应用程序的入口点。
//




// DuokehuServer.cpp : 为多客户提供服务的服务器端程序。
//


#include "stdafx.h"
#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h>
#pragma comment (lib,"ws2_32.lib")
#define SERVER_PORT "8888"
#define BUFFER_LEN  512

int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA wsaData;
	SOCKET ListenSocket=INVALID_SOCKET;
	SOCKET ClientSocket=INVALID_SOCKET;
	struct addrinfo hints,*result=NULL;
	struct sockaddr_in clientaddr;
	char sendbuf[BUFFER_LEN];
	char recvbuf[BUFFER_LEN];
	int iResult,isendResult;
	memset(recvbuf,0,BUFFER_LEN*sizeof(char));
	iResult=WSAStartup(MAKEWORD(2,2),&wsaData);
	if(iResult!=0)
	{
		printf("WSAStartup failed with error: &d\n",iResult);
		return 1;
	}
	ZeroMemory(&hints,sizeof(hints));
	hints.ai_family=AF_INET;
	hints.ai_socktype=SOCK_STREAM;
	hints.ai_protocol=IPPROTO_TCP;
	hints.ai_flags=AI_PASSIVE;
	iResult=getaddrinfo(NULL,SERVER_PORT,&hints,&result);
	if(iResult!=0){
		printf("getaddrinfo failed with error %d\n",iResult);
		WSACleanup();
		return 1;
	}

	ListenSocket=socket(result->ai_family,result->ai_socktype,result->ai_protocol);
	if(ListenSocket==INVALID_SOCKET){
		printf("socket failed with error %d\n",WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	iResult=bind(ListenSocket,result->ai_addr,(int)result->ai_addrlen);
	if(iResult==SOCKET_ERROR){
		printf("bind failed with error %d\n",WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}
	freeaddrinfo(result);

	iResult=listen(ListenSocket,SOMAXCONN);
	if(iResult==SOCKET_ERROR){
		printf("listen failed with error %d\n",WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	for(;;){
		int addrlenth=sizeof(clientaddr);
		ClientSocket=accept(ListenSocket,(sockaddr*)&clientaddr,&addrlenth);
		if(iResult==INVALID_SOCKET){
			printf("accept failed with error %d\n",WSAGetLastError());
			closesocket(ListenSocket);
			WSACleanup();
			return 1;
			}
		
			char *peeraddr=	inet_ntoa(clientaddr.sin_addr);

		do{
			iResult=recv(ClientSocket,recvbuf,BUFFER_LEN,0);
			if(iResult>0){
				printf("Received message: %s, from client: %s\n",recvbuf,peeraddr);//显示收到的信息及对方的IP地址
				strcpy(sendbuf,"Hello from server!");//给发送缓冲区sendbuf赋初值
				strcat(sendbuf,peeraddr);//将服务器问候字符串后跟该客户端的IP地址，作为新的sendbuf内容。
				isendResult=send(ClientSocket,sendbuf,strlen(sendbuf),0);
				if(isendResult==SOCKET_ERROR){
					printf("send failed with error %d\n",WSAGetLastError());
					closesocket(ClientSocket);
					WSACleanup();
					break;
				}
				printf("Bytes sent: %d\n",isendResult);
			}
			else if(iResult==0){
				printf("Connection closing...\n");
				iResult=shutdown(ClientSocket,SD_SEND);
				if(iResult==SOCKET_ERROR){
					printf("shutdown failed with error %d\n",WSAGetLastError());
					closesocket(ClientSocket);
					WSACleanup();
					break;
				}
				closesocket(ClientSocket);
				WSACleanup();
				break;
			}
			else{
				printf("recv failed with error:%d\n",WSAGetLastError());
				iResult=shutdown(ClientSocket,SD_SEND);
				if(iResult==SOCKET_ERROR){
					printf("shutdown failed with error %d\n",WSAGetLastError());
					closesocket(ClientSocket);
					WSACleanup();
					break;
					}
				}
	
		}while(iResult>0);

	}

	closesocket(ListenSocket);
	WSACleanup();
	return 0;
}

