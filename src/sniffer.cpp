#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <winsock2.h>
#include <exception>
#include <ws2tcpip.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

#include "../include/sniffer.h"

#define RANDOM_OS_PORT 0
#define LOCAL_IP L"127.0.0.1"

Sniffer::Sniffer()
{
	int startupResult = 0;
	startupResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (startupResult != 0) {
		throw std::exception("Exception: WSAStartup fail unexpectedly.");
	}
	snifferSock = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
	if (snifferSock == INVALID_SOCKET) {
		WSACleanup();
		std::cerr << "Error code: " << WSAGetLastError();
		throw std::exception("Exception: Failed while creating socket.");
	}
}

bool Sniffer::setNetworkingInterface()
{
	int errorCode = 1;
	netInterface.sin_family = AF_INET;
	netInterface.sin_port = RANDOM_OS_PORT;
	errorCode = InetPton(AF_INET, LOCAL_IP, &netInterface.sin_addr.s_addr);
	if (errorCode < 0) {
		std::cerr << "Fail while IP address initialization\r\n";
		std::cerr << "Error code: " << WSAGetLastError();
		return false;
	}
	return true;
}

bool Sniffer::bindSnifferSocket()
{
	int bindingErrorCode = 0;
	bindingErrorCode = bind(snifferSock, reinterpret_cast<const sockaddr*>(&netInterface),
		sizeof(netInterface));
	if (bindingErrorCode == SOCKET_ERROR) {
		std::cerr << "Error code: " << WSAGetLastError();
		return false;
	}
	return true;
}

void Sniffer::setSniffingMode()
{
	/* Second thing to do */
}

Sniffer::~Sniffer()
{
	WSACleanup();
	closesocket(snifferSock);
}