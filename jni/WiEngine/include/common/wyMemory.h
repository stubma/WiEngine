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
#ifndef __wyMemory_h__
#define __wyMemory_h__

#include "wyGlobal.h"

// uncomment it if want to enable memory tracking
#define MEMORY_TRACKING

#ifdef MEMORY_TRACKING

extern "C" WIENGINE_API void* _wyMalloc(size_t size, const char* file, int line, const char* logTag);
extern "C" WIENGINE_API void* _wyCalloc(size_t nitems, size_t size, const char* file, int line);
extern "C" WIENGINE_API void* _wyRealloc(void* ptr, size_t size, const char* file, int line);
extern "C" WIENGINE_API void _wyFree(void* ptr, const char* file, int line);

inline void* operator new(size_t n, const char* file, int line) {
	return _wyMalloc(n, file, line, "NEW");
}

inline void* operator new[](size_t n, const char* file, int line) {
	return _wyMalloc(n, file, line, "NEW[]");
}

inline void operator delete(void* p, const char* file, int line) {
	_wyFree(p, file, line);
}

inline void operator delete(void* p) throw() {
	_wyFree(p, __FILE__, __LINE__);
}

inline void operator delete[](void* p) throw() {
	_wyFree(p, __FILE__, __LINE__);
}

#define wyMalloc(size) _wyMalloc(size, __FILE__, __LINE__, "MALLOC")
#define wyCalloc(nitems, size) _wyCalloc(nitems, size, __FILE__, __LINE__)
#define wyRealloc(ptr, size) _wyRealloc(ptr, size, __FILE__, __LINE__)
#define wyFree(ptr) _wyFree(ptr, __FILE__, __LINE__)
#define WYNEW new(__FILE__, __LINE__)
#define WYDELETE(object) delete object
#define WYNEWARR(t, s) new(__FILE__, __LINE__) t[(s)]
#define WYDELETEARR(object) delete[] (object)

#else

#define wyMalloc malloc
#define wyCalloc calloc
#define wyRealloc realloc
#define wyFree free
#define WYNEW new
#define WYDELETE(object) delete object
#define WYNEWARR(t, s) new t[(s)]
#define WYDELETEARR(object) delete[] (object)

#endif // #if MEMORY_TRACKING

#endif // __wyMemory_h__
