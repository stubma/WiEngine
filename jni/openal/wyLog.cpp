#if WINDOWS

#include <stdarg.h>
#include <stdio.h>
#include <windows.h>
#include "wyLog.h"

static const size_t kBufferSize = 2048;

#if __cplusplus
extern "C" {
#endif

void __win_log_print(const char format[], ...) {
	char buffer[kBufferSize + 1];
	va_list args;
	va_start(args, format);
	vsnprintf(buffer, kBufferSize, format, args);
	va_end(args);

	OutputDebugString(buffer);
	OutputDebugString("\n");
	printf(buffer);
	printf("\n");
}

#if __cplusplus
}
#endif

#endif // #if WINDOWS
