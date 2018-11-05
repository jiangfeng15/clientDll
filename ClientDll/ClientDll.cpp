#include "ClientDll.h"

SOCKET m_socket;
bool InitSocket()
{
	int ERR;
	WORD wVersionRequested;
	WSADATA wsadata;
	
	SOCKADDR_IN sockaddr_client;
	wVersionRequested = MAKEWORD(2,2);
	ERR = WSAStartup(wVersionRequested,&wsadata);
	if(ERR != 0)
	{
		return false;
	}
	m_socket = socket(AF_INET,SOCK_STREAM,0);

	//初始化套接字地址
	sockaddr_client.sin_family = AF_INET;
	sockaddr_client.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	sockaddr_client.sin_port = htons(61001);

	//向服务器发送建立连接请求
	int ret = connect(m_socket,(sockaddr *)&(sockaddr_client),sizeof(sockaddr_client));
	if(ret!=0)
	{
		return false;
	}
	return true;
}

char *  SendToServer(char sendbuf[], int nBuf)
{
	char recvbuf[1024]={0x00};
	int nSendLen, nRecvLen;
	nSendLen = send(m_socket, sendbuf, nBuf, 0);
	if(nSendLen == nBuf)
	{
		nRecvLen = recv(m_socket, recvbuf, 1024, 0);
	}
	return recvbuf;
}

BOOL WINAPI DllMain(HINSTANCE hinstDll, DWORD fdwReason, LPVOID lpvReserved)
{
	switch(fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		{
			InitSocket();
			char sendbuf[1024]={0x00};
			char *recvbuf=NULL;
			memset(sendbuf,0x00, sizeof(sendbuf));
			strcpy(sendbuf, "1234");
			recvbuf = SendToServer(sendbuf, 4);
		}
	case DLL_PROCESS_DETACH:
		{
		}
		break;
	}
	return	TRUE;
}