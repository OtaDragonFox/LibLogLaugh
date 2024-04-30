#include"logger.h"
#include <iostream>

logger::logger()
{
	platform_element.platform_setup();

	for (int i = 0; i < 256; i++)
	{
		platform_element.platform_debug_out_message(i);
		
		platform_element.platform_window_log(" ");
	}
}

void logger::log_message(const char* message)
{
	std::cout << message << std::endl;
}
