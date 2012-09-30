
/*
 * Copyright 2010 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#if WINDOWS

#include "SkTypes.h"
#include <stdarg.h>
#include <stdio.h>
#include <Windows.h>

static const size_t kBufferSize = 2048;

void Windows_SkDebugf(const char format[], ...) {
    char    buffer[kBufferSize + 1];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, kBufferSize, format, args);
    va_end(args);

    OutputDebugStringA(buffer);
    printf(buffer);
}

#endif // #if WINDOWS