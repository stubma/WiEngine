#if WINDOWS

#include <stdarg.h>
#include <stdio.h>
#include <windows.h>
#include "kazmath/wyLog.h"

void __win_log_print(const char format[], ...) {
	char buffer[2049];
	va_list args;
	va_start(args, format);
	vsnprintf(buffer, 2048, format, args);
	va_end(args);

	OutputDebugString(buffer);
	OutputDebugString("\n");
	printf(buffer);
	printf("\n");
}

#endif // #if WINDOWS
