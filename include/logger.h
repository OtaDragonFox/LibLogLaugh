#pragma once
#include "log_platform.h"

// Logger inspired by the kohi Game engine project.
// implementation will be changed down the line!

enum log_level {
	TRACE,
	WARNG,
	ERROR,
	FATAL
};

class logger{
public:
	logger() {}
	void setup();
	static logger& get() { return log_instance; }

	void log_message(log_level level, const char* message, ...);
	log_platform platform_element;
	static logger log_instance;

	const long msg_length = 1024;
	char* out_message;
	const char* msg_lead[4]{"[TRACE]","[WARNG]","[ERROR]","[FATAL]" };
	char* formatted_message;
	void shutdown();
private:
	bool is_initialized = false;
};

#define LFATAL log_level::FATAL
#define LERROR log_level::ERROR
#define LWARNG log_level::WARNG
#define LTRACE log_level::TRACE

#define LOGGER() logger::get()
#define LOG(level, message, ...) logger::get().log_message(level,message,##__VA_ARGS__)
