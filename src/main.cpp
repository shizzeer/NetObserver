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
		if (!sniffer.setNetworkingInterface()) {
			std::cerr << "Error with setting sniffer's networking \
						  interface\r\n";
			return -2;
		}
		if (!sniffer.bindSnifferSocket()) {
			std::cerr << "Fail with binding sniffer\'s socket\r\n";
			return -3;
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\r\n";
		return -1;
	}

	return 0;
}
