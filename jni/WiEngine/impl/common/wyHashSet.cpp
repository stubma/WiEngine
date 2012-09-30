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
#include "wyHashSet.h"
#include <stdlib.h>
#include "wyLog.h"

#define BUFFER_BYTES (32*1024)

static int primes[] = {
	5,
	13,
	23,
	47,
	97,
	193,
	389,
	769,
	1543,
	3079,
	6151,
	12289,
	24593,
	49157,
	98317,
	196613,
	393241,
	786433,
	1572869,
	3145739,
	6291469,
	12582917,
	25165843,
	50331653,
	100663319,
	201326611,
	402653189,
	805306457,
	1610612741,
	0
};

static inline int next_prime(int n) {
	int i = 0;
	while(n > primes[i]) {
		i++;
	}

	return primes[i];
}

static inline void recycleBin(wyHashSet *set, wyHashSetBin *bin) {
	bin->next = set->pooledBins;
	set->pooledBins = bin;
	bin->elt = NULL;
}

static wyHashSetBin* getUnusedBin(wyHashSet *set) {
	wyHashSetBin *bin = set->pooledBins;

	if(bin) {
		set->pooledBins = bin->next;
		return bin;
	} else {
		// Pool is exhausted, make more
		int count = BUFFER_BYTES / sizeof(wyHashSetBin);

		wyHashSetBin *buffer = (wyHashSetBin *)malloc(BUFFER_BYTES);
		wyArrayPush(set->allocatedBuffers, buffer);

		// push all but the first one, return the first instead
		for(int i = 1; i < count; i++)
			recycleBin(set, buffer + i);
		return buffer;
	}
}

static int setIsFull(wyHashSet *set) {
	return (set->entries >= set->size);
}

static bool freeWrap(wyArray* arr, void* ptr, int index, void* unused) {
	free(ptr);
	return true;
}

void wyHashSetDestroy(wyHashSet *set) {
	free(set->table);
	wyArrayEach(set->allocatedBuffers, freeWrap, NULL);
	wyArrayDestroy(set->allocatedBuffers);
	free(set);
}

wyHashSet *
wyHashSetNew(int size, wyHashSetEqlFunc eqlFunc, wyHashSetTransFunc trans) {
	wyHashSet* set = (wyHashSet *)calloc(1, sizeof(wyHashSet));
	set->size = next_prime(size);
	set->entries = 0;
	set->eql = eqlFunc;
	set->trans = trans;
	set->default_value = NULL;
	set->table = (wyHashSetBin **)calloc(set->size, sizeof(wyHashSetBin *));
	set->pooledBins = NULL;
	set->allocatedBuffers = wyArrayNew(0);
	return set;
}

static void wyHashSetResize(wyHashSet *set) {
	// Get the next approximate doubled prime.
	int newSize = next_prime(set->size + 1);
	// Allocate a new table.
	wyHashSetBin **newTable = (wyHashSetBin **)calloc(newSize,
	        sizeof(wyHashSetBin *));

	// Iterate over the chains.
	for(int i = 0; i < set->size; i++) {
		// Rehash the bins into the new table.
		wyHashSetBin *bin = set->table[i];
		while(bin) {
			wyHashSetBin *next = bin->next;

			int idx = bin->hash % newSize;
			bin->next = newTable[idx];
			newTable[idx] = bin;

			bin = next;
		}
	}

	free(set->table);

	set->table = newTable;
	set->size = newSize;
}

void* wyHashSetInsert(wyHashSet *set, size_t hash, void* ptr, void* data) {
	return wyHashSetCustomInsert(set, hash, ptr, data, set->trans, set->eql);
}

void* wyHashSetCustomInsert(wyHashSet *set, size_t hash, void* ptr, void* data, wyHashSetTransFunc transFunc, wyHashSetEqlFunc eqlFunc) {
	int idx = hash % set->size;

	// Find the bin with the matching element.
	wyHashSetBin *bin = set->table[idx];
	while(bin && !eqlFunc(ptr, bin->elt))
		bin = bin->next;

	// Create it necessary.
	if(!bin) {
		bin = getUnusedBin(set);
		bin->hash = hash;
		bin->elt = transFunc(ptr, data); // Transform the pointer.

		bin->next = set->table[idx];
		set->table[idx] = bin;

		set->entries++;

		// Resize the set if it's full.
		if(setIsFull(set))
			wyHashSetResize(set);
	}

	return bin->elt;
}

void* wyHashSetRemove(wyHashSet *set, size_t hash, void* ptr) {
	return wyHashSetCustomRemove(set, hash, ptr, set->eql);
}

void* wyHashSetCustomRemove(wyHashSet *set, size_t hash, void* ptr, wyHashSetEqlFunc eqlFunc) {
	int idx = hash % set->size;

	// Pointer to the previous bin pointer.
	wyHashSetBin **prev_ptr = &set->table[idx];
	// Pointer the the current bin.
	wyHashSetBin *bin = set->table[idx];

	// Find the bin
	while(bin && !eqlFunc(ptr, bin->elt)) {
		prev_ptr = &bin->next;
		bin = bin->next;
	}

	// Remove it if it exists.
	if(bin) {
		// Update the previous bin pointer to point to the next bin.
		(*prev_ptr) = bin->next;
		set->entries--;

		void* return_value = bin->elt;

		recycleBin(set, bin);

		return return_value;
	}

	return NULL;
}

void* wyHashSetFind(wyHashSet *set, size_t hash, void* ptr) {
	return wyHashSetCustomFind(set, hash, ptr, set->eql);
}

void* wyHashSetCustomFind(wyHashSet *set, size_t hash, void* ptr, wyHashSetEqlFunc eqlFunc) {
	int idx = hash % set->size;
	wyHashSetBin *bin = set->table[idx];
	while(bin && !eqlFunc(ptr, bin->elt))
		bin = bin->next;

	return (bin ? bin->elt : set->default_value);
}

void wyHashSetEach(wyHashSet *set, wyHashSetIterFunc func, void* data) {
	for(int i = 0; i < set->size; i++) {
		wyHashSetBin *bin = set->table[i];
		bool bSatisfied = false;
		while(bin) {
			wyHashSetBin *next = bin->next;
			if(func(bin->elt, data)) {
				bin = next;
			} else {
				bSatisfied = true;
				break;
			}
		}
		
		if(bSatisfied)
			break;
	}
}

void wyHashSetFilter(wyHashSet *set, wyHashSetFilterFunc func, void* data) {
	// Iterate over all the chains.
	for(int i = 0; i < set->size; i++) {
		// The rest works similarly to wyHashSetRemove() above.
		wyHashSetBin **prev_ptr = &set->table[i];
		wyHashSetBin *bin = set->table[i];
		while(bin) {
			wyHashSetBin *next = bin->next;

			if(func(bin->elt, data)) {
				prev_ptr = &bin->next;
			} else {
				(*prev_ptr) = next;

				set->entries--;
				recycleBin(set, bin);
			}

			bin = next;
		}
	}
}
