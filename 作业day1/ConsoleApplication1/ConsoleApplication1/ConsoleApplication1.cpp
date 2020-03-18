// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#include<winsock2.h>
#pragma comment(lib,"ws2_32")

/*
struct protoent
{
	char FAR *p_name;			//��ʽЭ����
	char FAR *FAR *p_aliases;	//�����б�
	short p_proto;				//Э���
}
*/
//�ú���������ص�Э����Ϣ���ɹ�ʱ�������Э�����ơ�������Э���ţ�
//����ʱ���ӡ��������Ϣ
void proto_print(struct protoent *proto_info,const char * *proto_name,int proto)

{
	char **list_p;
	if(proto_info == NULL)
	{
		printf("______________________________\n");
		if(proto_name)
			printf("can't get protocol information:%s\n",proto_name);
		else 
			printf("can't get protocol information by number:%d\n",proto);
	}
	else 
	{
		printf("________________________________\n");
		printf("offical name: %s\n",proto_info->p_name);
		for(list_p = proto_info->p_aliases;*list_p != NULL; list_p++)
		{
			printf("alias:%s\n",*list_p);
		}
		printf("protocol : %d\n",proto_info->p_proto);
	}
}
int main()
{
	const char *proto_name[] = {"tcp","ipv6","esp"};
	int i,name_cnt = sizeof(proto_name) / sizeof(proto_name[0]);
	int proto_number[] = {1,8,51};
	int proto_cnt = sizeof(proto_number) / sizeof(proto_number[0]);
	struct protoent *proto_info;
	WSADATA wsaData;
	WSAStartup( (MAKEWORD(2,0)), &wsaData);	
	printf("\n[getprotobynumber] get protocol by number\n");
	for(i = 0 ; i<proto_cnt ; i++)
	{
		proto_info = getprotobynumber(proto_number[i]);
		proto_print(proto_info,NULL,proto_number[i]);
	}
	WSACleanup();
	return 0;
}


