
#ifdef LOG_WINDWS 
#include "log_platform.h"
#include <Windows.h>
#include <string>
void log_platform::platform_setup() {
	console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
}



void log_platform::platform_window_log(const char* message) {
	SetConsoleTextAttribute(console_handle, 7);
	OutputDebugStringA(message);
	long length = strlen(message);
	LPDWORD number_written = 0;
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), message, (DWORD)length, number_written, 0);



}

void log_platform::platform_debug_out_message(int id){
	SetConsoleTextAttribute(console_handle, id);
	std::string in_int = std::to_string(id);
	//in_int.append("\n");
	const char* message = in_int.c_str();
	OutputDebugStringA(message);
	long length = strlen(message);
	LPDWORD number_written = 0;
	WriteConsoleA(
		GetStdHandle(STD_OUTPUT_HANDLE), 
		message, 
		(DWORD)length, 
		number_written, 
		0);

	SetConsoleTextAttribute(console_handle, 7);
}
#endif // 
