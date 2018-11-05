#ifndef CLIENTDLL_H
#define CLIENTDLL_H
#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)

#include <winsock2.h>
#pragma comment (lib,"ws2_32.lib")//winsock使用的库函数

extern "C" DLLEXPORT bool InitSocket();

extern "C" DLLEXPORT char * SendToServer(char sendbuf[], int nBuf);

#endif