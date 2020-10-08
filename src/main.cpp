#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <windows.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

#include "../include/sniffer.h"

int main()
{
	try {
		Sniffer sniffer;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\r\n";
		return -1;
	}

	return 0;
}
