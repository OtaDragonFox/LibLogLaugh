#include"logger.h"
#include <iostream>
#include <cstdarg>



logger logger::log_instance;


void logger::setup()
{
	platform_element.platform_setup();
	//for (int i = 0; i < 256; i++)
	//{
	//	platform_element.platform_debug_out_message(i);
	//	
	//	platform_element.platform_window_log(" ");
	//}

	out_message = new(char[msg_length]);
	formatted_message = new(char[msg_length]);
	
}

void logger::log_message(log_level level, const char* message, ...)
{
	
		//this feels like very insecure code o.o

		bool is_error = level < log_level::FATAL;
		memset(out_message, 0, sizeof(out_message));

		va_list arg_ptr;
		va_start(arg_ptr, message);
		vsnprintf(out_message, msg_length, message, arg_ptr);
		va_end(arg_ptr);

		sprintf(formatted_message, "%s%s\n", msg_lead[level], out_message);

		// platform specific output.
		platform_element.platform_window_log(level,formatted_message);
}

void logger::shutdown()
{
	free(out_message);
	free(formatted_message);


}
