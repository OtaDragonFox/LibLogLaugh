#pragma once
#include <platform/log_platform.h>



class logger {
public:
	logger();
	
	void log_message(const char* message);
	
	log_platform platform_element;

};


#define LOG(...) logger::log_message(##__VA_ARGS__)
