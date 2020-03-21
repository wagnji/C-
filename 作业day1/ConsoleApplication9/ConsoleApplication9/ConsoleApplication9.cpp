// ShuruxinxClient.cpp : �ͻ��˳����û����ԴӼ���������Ϣ�����͸���������
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

#define SERVER_PORT "8888"
#define BUFFER_LEN 512

int main(int argc, char* argv[])
{
	struct addrinfo* result = NULL, *ptr = NULL, hints;
	WSADATA wsaData;
	SOCKET ConnectSocket;
	char sendbuf[BUFFER_LEN];
	char recvbuf[BUFFER_LEN];
	int iResult;

	if (argc != 1) {
		printf("Usage: %s server ip address\n", argv[0]);
		return 1;
	}

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	iResult = getaddrinfo(argv[1], SERVER_PORT, &hints, &result);//���������argv[1]��ָ���ķ�������Ϣд��result
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	ConnectSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);//ʹ��resultָ������Ϣ�����׽���
	if (ConnectSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	iResult = connect(ConnectSocket, result->ai_addr, result->ai_addrlen);//ʹ���׽���ConnectSocket��result��ָ���ķ�������������
	if (iResult == SOCKET_ERROR) {
		printf("connect failed with error: %ld\n", iResult);
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}
	freeaddrinfo(result);//�ͷŶ�̬��

	while (gets_s(sendbuf) != NULL)//�Ӽ��̻�ȡ�����ַ���  
	{
		if (*sendbuf == 'X')
		{
			closesocket(ConnectSocket);
			return 0;
		}
		iResult = send(ConnectSocket, sendbuf, strlen(sendbuf), 0);
		if (iResult == SOCKET_ERROR) //�ֽ���
		{
			printf("send failed with error: %d\n", WSAGetLastError());
			closesocket(ConnectSocket);
			WSACleanup();
			return 1;
		}
		printf("�ֽڳ���: %d\n", iResult);
		do
		{
			memset(recvbuf, 0, BUFFER_LEN * sizeof(char));
			iResult = recv(ConnectSocket, recvbuf, strlen(recvbuf), 0);
			if (iResult > 0)
			{
				printf("�ӿͻ��˽��յ���Ϣ�� %d\n", recvbuf);
			}
			else if (iResult == 0)
			{
				printf("���ͳɹ�\n\n");
			}
			else
			{
				printf("recv failed with error:%d\n", WSAGetLastError());
			}
		} while (iResult > 0);
	}

	closesocket(ConnectSocket);
	WSACleanup();
	return 0;
}