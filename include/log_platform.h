#pragma once


#ifdef LOG_WINDWS 
typedef void* HANDLE;


#pragma once
#endif // 


class log_platform {
public:
	
	void platform_setup();
	void platform_window_log(int level,const char* message);
	void platform_debug_out_message(int id);


	short levels[4] = { 8,6,78,64 };


#ifdef LOG_WINDWS 
	HANDLE console_handle;


	const short* log_colors[5]{};
#pragma once
#endif // 
public:

};





