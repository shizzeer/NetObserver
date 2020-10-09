#pragma once
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

class Sniffer
{
public:
	Sniffer();
	bool setNetworkingInterface();
	bool bindSnifferSocket();
	void setSniffingMode();
	~Sniffer();
private:
	WSAData wsaData;
	SOCKET snifferSock = INVALID_SOCKET;
	sockaddr_in netInterface;
};