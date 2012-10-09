/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "wyGlobal.h"
#include <pthread.h>
#include "wyResourceDecoder.h"
#if WINDOWS
	#include <windows.h>
#endif

// global lock
pthread_mutex_t gMutex;
pthread_mutex_t gCondMutex;

// gl thread id
static pthread_t gGLThreadId;

// resource decoder
wyResourceDecoder* gResDecoder = NULL;

// current thread id, int
ssize_t currentThreadId() {
	// get current thread id
#if WINDOWS
	return (ssize_t)pthread_self().p;
#else
	return (ssize_t)pthread_self();
#endif
}

// is gl thread
bool isGLThread() {
	// in pthread-win32, pthread_t is a struct
#if WINDOWS
	return pthread_self().p == gGLThreadId.p;
#else
	return pthread_self() == gGLThreadId;
#endif
}

// tag current thread as GL thread
void tagGLThread() {
	gGLThreadId = pthread_self();
}

// get time
#if WINDOWS
int gettimeofday(struct timeval* tp, void* tzp) {
    time_t clock;
	struct tm tm;
	SYSTEMTIME wtm;

	GetLocalTime(&wtm);
	tm.tm_year = wtm.wYear - 1900;
	tm.tm_mon = wtm.wMonth - 1;
	tm.tm_mday = wtm.wDay;
	tm.tm_hour = wtm.wHour;
	tm.tm_min = wtm.wMinute;
	tm.tm_sec = wtm.wSecond;
	tm. tm_isdst = -1;
	clock = mktime(&tm);
	tp->tv_sec = clock;
	tp->tv_usec = wtm.wMilliseconds * 1000;

	return 0;
}

void usleep(int waitTime) {
    __int64 time1 = 0, time2 = 0, freq = 0;

    QueryPerformanceCounter((LARGE_INTEGER*)&time1);
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);

    do {
        QueryPerformanceCounter((LARGE_INTEGER*)&time2);
    } while((time2 - time1) < waitTime);
}
#endif

// math operation
#if WINDOWS
double round(double r) {
    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}
#endif
