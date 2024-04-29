#include"logger.h"
#include <iostream>

void logger::log_message(const char* message)
{
	std::cout << message << std::endl;
}
