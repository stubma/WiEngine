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
#include <string.h>
#include "wyArray.h"
#include "wyLog.h"
#include <stdlib.h>

static bool release(wyArray* arr, void* ptr, int index, void* data) {
	wyArrayDestroy((wyArray*)ptr);
	return true;
}

static bool noLockedEach(wyArray *arr, wyArrayIterator iterFunc, void* data) {
	for (int i = 0; i < arr->num; i++)
		iterFunc(arr, arr->arr[i], i, data);
	return true;
}

bool wyArrayIsEmpty(wyArray* arr) {
	return arr == NULL || arr->num == 0;
}

wyArray* wyArrayNew(int size) {
	wyArray* arr = (wyArray *) calloc(1, sizeof(wyArray));

	arr->num = 0;
	size = (size ? size : 4);
	arr->max = size;
	arr->arr = (void**) malloc(size * sizeof(void*));

	return arr;
}

void wyArrayDestroy(wyArray *arr) {
	if(!arr)
		return;

	if(arr->locked) {
		LOGW("Try to destroy array when iteration, please use wyArrayConcurrentEach instead");
	} else {
		free(arr->arr);
		free(arr);
	}
}

void wyArrayPushAll(wyArray* src, wyArray* dst) {
	for(int i = 0; i < src->num; i++) {
		void* obj = wyArrayGet(src, i);
		wyArrayPush(dst, obj);
	}
}

void wyArrayPush(wyArray *arr, void* object) {
	if(arr->locked) {
		LOGW("Concurrent modification for array, please use wyArrayConcurrentEach instead");
		return;
	}

	if (arr->num == arr->max) {
		arr->max *= 2;
		arr->arr = (void**) realloc(arr->arr, arr->max * sizeof(void*));
	}

	arr->arr[arr->num] = object;
	arr->num++;
}

void wyArrayRemoveAllIn(wyArray* src, wyArray* removeList) {
	for(int i = 0; i < removeList->num; i++) {
		void* obj = wyArrayGet(removeList, i);
		wyArrayDeleteObj(src, obj, NULL, NULL);
	}
}

void wyArrayClear(wyArray* arr) {
	for (int i = 0; i < arr->num; i++) {
		arr->arr[i] = NULL;
	}
	arr->num = 0;
}

void* wyArrayPop(wyArray *arr) {
	if(arr == NULL) {
		return NULL;
	}

	if(arr->locked) {
		LOGW("Concurrent modification for array, please use wyArrayConcurrentEach instead");
		return NULL;
	}

	// if empty, return NULL
	if(arr->num <= 0)
		return NULL;

	// pop out top element
	arr->num--;
	void* value = arr->arr[arr->num];
	arr->arr[arr->num] = NULL;
	return value;
}

void* wyArrayPeek(wyArray* arr) {
	if(arr->num <= 0)
		return NULL;
	else
		return arr->arr[arr->num - 1];
}

void* wyArrayGet(wyArray* arr, int idx) {
	if(idx < 0 || idx >= arr->num)
		return NULL;

	return arr->arr[idx];
}

void wyArrayInsert(wyArray* arr, void* obj, int idx) {
	if(idx < 0 || idx > arr->num)
		return;

	if(arr->locked) {
		LOGW("Concurrent modification for array, please use wyArrayConcurrentEach instead");
		return;
	}

	if(idx == arr->num)
		wyArrayPush(arr, obj);
	else {
		if (arr->num == arr->max) {
			arr->max *= 2;
			arr->arr = (void**) realloc(arr->arr, arr->max * sizeof(void*));
		}

		memmove(arr->arr + idx + 1, arr->arr + idx, sizeof(void*) * (arr->num - idx));
		arr->arr[idx] = obj;
		arr->num++;
	}
}

void* wyArrayDeleteIndex(wyArray *arr, int idx) {
	if(idx < 0 || idx >= arr->num)
		return NULL;

	if(arr->locked) {
		LOGW("Concurrent modification for array, please use wyArrayConcurrentEach instead");
		return NULL;
	}

	// memory move
	void* ret = arr->arr[idx];
	if(idx < arr->num - 1)
		memmove(arr->arr + idx, arr->arr + idx + 1, (arr->num - idx - 1) * sizeof(void*));

	// decrease count
	arr->num--;

	return ret;
}

void* wyArrayDeleteObj(wyArray* arr, void* obj, wyArrayComparator comparator, void* data) {
	if(arr->locked) {
		LOGW("Concurrent modification for array, please use wyArrayConcurrentEach instead");
		return NULL;
	}

	for (int i = 0; i < arr->num; i++) {
		if(comparator == NULL) {
			if (arr->arr[i] == obj) {
				return wyArrayDeleteIndex(arr, i);
			}
		} else if(comparator(arr->arr[i], obj, data)) {
			return wyArrayDeleteIndex(arr, i);
		}
	}

	return NULL;
}

void wyArrayConcurrentEach(wyArray* arr, wyArrayIterator iterFunc, void* data) {
	int num = arr->num;
	void** arrCopy = (void**)calloc(num, sizeof(void*));
	memcpy(arrCopy, arr->arr, num * sizeof(void*));
	for (int i = 0; i < num; i++) {
		if(!iterFunc(arr, arrCopy[i], i, data))
			break;
	}
	free(arrCopy);
}

void wyArrayEach(wyArray *arr, wyArrayIterator iterFunc, void* data) {
	arr->locked = true;
	for (int i = 0; i < arr->num; i++) {
		if(!iterFunc(arr, arr->arr[i], i, data))
			break;
	}
	arr->locked = false;
}

int wyArrayIndexOf(wyArray* arr, void* obj, wyArrayComparator comparator, void* data) {
	for (int i = 0; i < arr->num; i++) {
		if(comparator == NULL) {
			if (arr->arr[i] == obj)
				return i;
		} else if(comparator(arr->arr[i], obj, data)) {
			return i;
		}
	}

	return -1;
}
