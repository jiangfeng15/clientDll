#ifndef CLIENTDLL_H
#define CLIENTDLL_H
#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)

#include <winsock2.h>
#pragma comment (lib,"ws2_32.lib")//winsockʹ�õĿ⺯��

extern "C" DLLEXPORT bool InitSocket();

extern "C" DLLEXPORT char * SendToServer(char sendbuf[], int nBuf);

#endif