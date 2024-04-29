#pragma once



class logger {
public:
	static void log_message(const char* message);
};


#define LOG(...) logger::log_message(##__VA_ARGS__)
