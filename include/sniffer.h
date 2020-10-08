#pragma once
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

class Sniffer
{
public:
	/* deklaracja defaultowego konstruktora. Mowimy kompilatorowi, ze bedziemy tworzyc wlasny
	konstruktor, a on ma nie definiowac swojego. */
	Sniffer();
	~Sniffer();
private:
	WSAData wsaData;
	SOCKET snifferSock = INVALID_SOCKET;
};