#pragma once


#ifdef LOG_WINDWS 
typedef void* HANDLE;


#pragma once
#endif // 


class log_platform {
public:
	
	void platform_setup();
	void platform_window_log(const char* message);
	void platform_debug_out_message(int id);


	short levels[5] = { 64,4,6,78,8 };


#ifdef LOG_WINDWS 
	HANDLE console_handle;


#pragma once
#endif // 



};
