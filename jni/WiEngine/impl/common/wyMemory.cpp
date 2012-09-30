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
#include "wyMemory.h"
#include "wyLog.h"
#include <memory.h>

#ifdef MEMORY_TRACKING

// uncomment if you want to log every allocation in console
//#define LOG_ALLOC

/*
 * record max size
 */

#define MEMORY_RECORD_INDEX_SIZE 0x10000
#define MEMORY_RECORD_INDEX_MASK 0xFFFF

/// memory record structure
typedef struct wyMemoryRecord {
	/**
	 * start address of allocated memory
	 */
	void* start;

	/**
	 * memory size
	 */
	int size;

	/**
	 * source file name where allocation occurs
	 */
	const char* file;

	/**
	 * source file line where allocation occurs
	 */
	int line;

	/**
	 * next record
	 */
	struct wyMemoryRecord* next;
} wyMemoryRecord;

/*
 * record array and summary info
 */

static wyMemoryRecord* sMemoryRecord[MEMORY_RECORD_INDEX_SIZE] = { 0 };
static int sTotalUsedMemory = 0;
static int sMaxUsedMemory = 0;
static int sTotalAlloc = 0;
static int sTotalFree = 0;

#ifdef __cplusplus
extern "C" {
#endif

void addRecord(wyMemoryRecord* r) {
	// get hash position
	int hash = (uintptr_t)r->start & MEMORY_RECORD_INDEX_MASK;
	wyMemoryRecord* pTemp = sMemoryRecord[hash];
	wyMemoryRecord* pPrev = NULL;

	// find a block whose start address is larger than incoming record
	while (pTemp) {
		if (pTemp->start > r->start) {
			break;
		}
		pPrev = pTemp;
		pTemp = pTemp->next;
	}

	// insert new record into linked list
	if (pPrev == NULL) {
		sMemoryRecord[hash] = r;
		if (pTemp) {
			r->next = pTemp;
		}
	} else {
		r->next = pPrev->next;
		pPrev->next = r;
	}

	// update statistics
	sTotalUsedMemory += r->size;
	sMaxUsedMemory = (sMaxUsedMemory > sTotalUsedMemory ? sMaxUsedMemory : sTotalUsedMemory);
	sTotalAlloc++;
}

wyMemoryRecord* findRecord(void* p) {
	int hash = (uintptr_t)p & MEMORY_RECORD_INDEX_MASK;
	wyMemoryRecord* pTemp = sMemoryRecord[hash];
	wyMemoryRecord* r = NULL;
	while (pTemp) {
		if (pTemp->start == p) {
			r = pTemp;
			break;
		}
		pTemp = pTemp->next;
	}
	return r;
}

wyMemoryRecord* removeRecord(wyMemoryRecord* r) {
	int hash = (uintptr_t)r->start & MEMORY_RECORD_INDEX_MASK;
	wyMemoryRecord* pTemp = sMemoryRecord[hash];
	wyMemoryRecord* pPrev = NULL;
	while(pTemp) {
		if(pTemp == r) {
			break;
		}
		pPrev = pTemp;
		pTemp = pTemp->next;
	}

	// didn't find?
	if(pTemp != r) {
		LOGD("[MEMRECORD] Unmatched record (%x)(record=%x):%d [%s:%d]", r->start, r, r->size, r->file, r->line);
		return NULL;
	}

	// remove record
	if(pTemp == sMemoryRecord[hash]) {
		sMemoryRecord[hash] = pTemp->next;
	} else {
		pPrev->next = pTemp->next;
	}

	// statistics
	sTotalUsedMemory -= r->size;
	sTotalFree++;

	// return record
	r->next = NULL;
	return r;
}

void wyMemoryUsageReport() {
	LOGD("[MEMREPORT] peak %d bytes, now %d bytes, alloc %d times, free %d times",
				  sMaxUsedMemory, sTotalUsedMemory, sTotalAlloc, sTotalFree);
}

void wyMemoryDumpRecord(bool fullLog) {
	int leak = 0;
	int leakNum = 0;
	for (int i = 0; i < MEMORY_RECORD_INDEX_SIZE; i++) {
		wyMemoryRecord* r = sMemoryRecord[i];
		while(r) {
			if(fullLog || 
#ifdef WINDOWS
				strstr(r->file, "wiengine") == NULL
#else
				strstr(r->file, "WiEngine") == NULL
#endif
				) {
				LOGD("%d.[MEMRECORD](%x)(record=%x):%d [%s:%d]", ++leakNum, r->start, r, r->size, r->file, r->line);
				leak += r->size;
			}

			r = r->next;
		}
	}

	if(leakNum > 0) {
		LOGD("[MEMRECORD] total leak = %d", leak);
	} else {
		LOGD("[MEMRECORD] no memory leak, congratulations!");
	}
}

void* _wyMalloc(size_t size, const char* file, int line, const char* logTag) {
	// null pointer for zero size
	if (size == 0)
		return NULL;

	void* p = malloc(size);
	if (p) {
		wyMemoryRecord* r = (wyMemoryRecord*)malloc(sizeof(wyMemoryRecord));
		if(!r) {
			free(p);
			p = NULL;
		} else {
			r->start = p;
			r->size = size;
			r->file = file;
			r->line = line;
			r->next = NULL;
			addRecord(r);
		}

#if LOG_ALLOC
		LOGD("[%s](%x)(record=%x):%d [%s:%d]", logTag, r->start, r, size, r->file, r->line);
#endif
	}

	return p;
}

void* _wyCalloc(size_t nitems, size_t size, const char* file, int line) {
	void* ptr = _wyMalloc(nitems * size, file, line, "CALLOC");
	memset(ptr, 0, nitems * size);
	return ptr;
}

void* _wyRealloc(void* ptr, size_t size, const char* file, int line) {
	wyMemoryRecord* r = findRecord(ptr);
	if(r) {
		// realloc
		void* newPtr = _wyMalloc(size, file, line, "REALLOC");
		memcpy(newPtr, ptr, r->size);
		free(ptr);

		// remove record
		removeRecord(r);
		free(r);

		return newPtr;
	} else {
		return realloc(ptr, size);
	}
}

void _wyFree(void* ptr, const char* file, int line) {
	// basic validation
	if(!ptr)
		return;

	// find record and remove it
	wyMemoryRecord* r = findRecord(ptr);
	if(r) {
		removeRecord(r);
		free(r);
	}

	// even record is not found, we must release it
	free(ptr);
}

#ifdef __cplusplus
}
#endif

#endif // #if MEMORY_TRACKING
