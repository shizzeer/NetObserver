#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <winsock2.h>
#include <exception>

#pragma comment(lib, "ws2_32.lib")

#include "../include/sniffer.h"

Sniffer::Sniffer()
{
	int startupResult = 0;
	startupResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (startupResult != 0) {
		throw std::exception("Exception: WSAStartup fail unexpectedly.");
	}
	snifferSock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
	if (snifferSock == INVALID_SOCKET) {
		WSACleanup();
		std::cerr << WSAGetLastError();
		throw std::exception("Exception: Failed while creating socket.");
	}
}

Sniffer::~Sniffer()
{
	WSACleanup();
	closesocket(snifferSock);
}