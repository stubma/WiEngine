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
#ifndef __wyHashSet_h__
#define __wyHashSet_h__

#include "wyArray.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct wyHashSetBin
 *
 * wyHashSetBin's form the linked lists in the chained hash table.
 */
typedef struct WIENGINE_API wyHashSetBin {
	// Pointer to the element.
	void* elt;
	// Hash value of the element.
	size_t hash;
	// Next element in the chain.
	struct wyHashSetBin *next;
} wyHashSetBin;

// Equality function. Returns true if ptr is equal to elt.
typedef int (*wyHashSetEqlFunc)(void* ptr, void* elt);
// Used by wyHashSetInsert(). Called to transform the ptr into an element.
typedef void* (*wyHashSetTransFunc)(void* ptr, void* data);

/**
 * @struct wyHashSet
 *
 * 哈希表结构定义
 */
typedef struct WIENGINE_API wyHashSet {
	// Number of elements stored in the table.
	int entries;
	// Number of cells in the table.
	int size;

	wyHashSetEqlFunc eql;
	wyHashSetTransFunc trans;

	// Default value returned by wyHashSetFind() when no element is found.
	// Defaults to NULL.
	void* default_value;

	// The table and recycled bins
	wyHashSetBin **table, *pooledBins;

	wyArray *allocatedBuffers;
} wyHashSet;

// Basic allocation/destruction functions.
WIENGINE_API void wyHashSetDestroy(wyHashSet *set);
WIENGINE_API wyHashSet *wyHashSetNew(int size, wyHashSetEqlFunc eqlFunc, wyHashSetTransFunc trans);

// Insert an element into the set, returns the element.
// If it doesn't already exist, the transformation function is applied.
WIENGINE_API void* wyHashSetInsert(wyHashSet *set, size_t hash, void* ptr, void* data);
WIENGINE_API void* wyHashSetCustomInsert(wyHashSet *set, size_t hash, void* ptr, void* data, wyHashSetTransFunc transFunc, wyHashSetEqlFunc eqlFunc);

// Remove and return an element from the set.
WIENGINE_API void* wyHashSetRemove(wyHashSet *set, size_t hash, void* ptr);
WIENGINE_API void* wyHashSetCustomRemove(wyHashSet *set, size_t hash, void* ptr, wyHashSetEqlFunc eqlFunc);

// Find an element in the set. Returns the default value if the element isn't found.
WIENGINE_API void* wyHashSetFind(wyHashSet *set, size_t hash, void* ptr);
WIENGINE_API void* wyHashSetCustomFind(wyHashSet *set, size_t hash, void* ptr, wyHashSetEqlFunc eqlFunc);

// Iterate over a hashset.
typedef bool (*wyHashSetIterFunc)(void* elt, void* data);
WIENGINE_API void wyHashSetEach(wyHashSet *set, wyHashSetIterFunc func, void* data);

// Iterate over a hashset, drop the element if the func returns false.
typedef bool (*wyHashSetFilterFunc)(void* elt, void* data);
WIENGINE_API void wyHashSetFilter(wyHashSet *set, wyHashSetFilterFunc func, void* data);

#ifdef __cplusplus
}
#endif

#endif // __wyHashSet_h__
