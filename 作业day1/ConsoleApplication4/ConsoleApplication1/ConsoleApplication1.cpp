#include <stdio.h>
#include <tchar.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <WinBase.h>
#pragma warning(disable:4996)

#pragma comment (lib,"ws2_32.lib")

#define SERVER_PORT "27015"
#define BUFFER_LEN 512

int _tmain(int argc, _TCHAR * argv[])
{
	struct addrinfo* result = NULL, * ptr = NULL, hints;
	WSADATA wsaData;
	SOCKET ConnectSocket;
	char sendbuf[BUFFER_LEN];
	char recvbuf[BUFFER_LEN];
	int iResult;
	printf("客户端：\n");
	/*if (argc != 2) {
		printf("Usage: %s server ip address\n", argv[0]);
		return 1;
	}
*/
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: d%\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	iResult = getaddrinfo((PCSTR)argv[1], SERVER_PORT, &hints, &result);//将输入参数argv[1]中指定的服务器信息写入result
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();			
		return 1;
	}

	ConnectSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);//使用result指定的信息创建套接字
	if (ConnectSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	iResult = connect(ConnectSocket, result->ai_addr, result->ai_addrlen);//使用套接字ConnectSocket向result中指定的服务器请求连�?
	if (iResult == SOCKET_ERROR) {
		printf("connect failed with error: %ld\n", iResult);
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}
	freeaddrinfo(result);//释放动态分配的地址信息结构体result

	while (gets_s(sendbuf) != NULL) {//从键盘获取输入字符串
		if (*sendbuf == 'Q') {
			closesocket(ConnectSocket);
			return 0;
		}
		iResult = send(ConnectSocket, sendbuf, strlen(sendbuf), 0);
		if (iResult == SOCKET_ERROR) {
			printf("send failed with error: %ld\n", iResult);
			closesocket(ConnectSocket);
			WSACleanup();
			return 1;
		}
		printf("Sent bytes: %d\n", iResult);
		do {
			memset(recvbuf, 0, BUFFER_LEN * sizeof(char));
			iResult = recv(ConnectSocket, recvbuf, strlen(recvbuf), 0);
			if (iResult > 0) {
				printf("Received message from client: %s\n", recvbuf);

			}
			else if (iResult == 0) {
				printf("Connection closed\n");
			}
			else {
				printf("recv failed with error:d\n", WSAGetLastError());
			}
		} while (iResult > 0);
	}

	closesocket(ConnectSocket);
	WSACleanup();
	return 0;
}