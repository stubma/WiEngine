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
#ifndef __wyArray_h__
#define __wyArray_h__

#include <stdbool.h>
#include "wyGlobal.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct wyArray
 *
 * 提供基本的数组功能，也可以当成堆栈使用
 */
typedef struct WIENGINE_API wyArray {
	/// count of element in array
	int num;

	/// capacity of array memory
	int max;

	// pointer of element array
	void** arr;

	/// flag indicating array is locked or not
	bool locked;
} wyArray;

/**
 * 元素枚举函数指针。
 *
 * @param arr wyArray指针
 * @param ptr 元素指针
 * @param index 元素在arr中的索引位置
 * @param data 附加数据
 */
typedef bool (*wyArrayIterator)(wyArray* arr, void* ptr, int index, void* data);

/**
 * 元素比较器
 *
 * @param elementPtr wyArray中的元素指针
 * @param ptr 需要和wyArray中元素比较的指针
 * @param data 附加数据
 */
typedef bool (*wyArrayComparator)(void* elementPtr, void* ptr, void* data);

/**
 * 创建一个新的wyArray结构
 *
 * @param size wyArray的初始容量
 */
WIENGINE_API wyArray* wyArrayNew(int size);

/**
 * 销毁wyArray结构
 *
 * @param arr 需要销毁的wyArray指针
 */
WIENGINE_API void wyArrayDestroy(wyArray* arr);

/**
 * 判断wyArray中是否没有元素
 *
 * @param arr wyArray指针
 * @return true表示wyArray为空，false表示有元素
 */
WIENGINE_API bool wyArrayIsEmpty(wyArray* arr);

/**
 * 清空wyArray中的元素，这个方法不会释放元素，因此如果元素需要销毁，要记住
 * 先销毁再清空
 *
 * @param arr wyArray指针
 */
WIENGINE_API void wyArrayClear(wyArray* arr);

/**
 * 将某个列表中的所有对象都复制到另外一个列表中
 *
 * @param src 源\link wyArray wyArray\endlink
 * @param dst 目标\link wyArray wyArray\endlink
 */
WIENGINE_API void wyArrayPushAll(wyArray* src, wyArray* dst);

/**
 * 在wyArray的末尾追加一个元素，也可以认为是在顶部添加一个元素，这样可以把wyArray
 * 当成一个堆栈使用
 *
 * @param arr wyArray指针
 * @param object 元素的指针
 */
WIENGINE_API void wyArrayPush(wyArray* arr, void* object);

/**
 * 从一个数组中删除和另外一个数组的相同元素
 *
 * @param src 要删除元素的数组
 * @param removeList 和src中的共同元素将被删除
 */
WIENGINE_API void wyArrayRemoveAllIn(wyArray* src, wyArray* removeList);

/**
 * 删除wyArray末尾的元素，也可以认为是从顶部弹出元素，这样可以把wyArray当成一个
 * 堆栈使用
 *
 * @param arr wyArray指针
 * @return 元素指针
 */
WIENGINE_API void* wyArrayPop(wyArray* arr);

/**
 * 获得wyArray末尾的元素，但不会把元素从wyArray中删除
 *
 * @param arr wyArray指针
 * @return 元素指针
 */
WIENGINE_API void* wyArrayPeek(wyArray* arr);

/**
 * 获得指定位置处的元素
 *
 * @param arr wyArray指针
 * @param idx 索引位置, 从0开始
 * @return 元素指针
 */
WIENGINE_API void* wyArrayGet(wyArray* arr, int idx);

/**
 * 在指定位置处插入元素，之前位于这个位置以及之后的元素将向后移动
 *
 * @param arr wyArray指针
 * @param obj 要插入的元素指针
 * @param idx 要插入的位置
 */
WIENGINE_API void wyArrayInsert(wyArray* arr, void* obj, int idx);

/**
 * 在wyArray中寻找某个元素
 *
 * @param arr wyArray指针
 * @param obj 要查找的元素指针
 * @param comparator 元素比较器，如果为NULL，则直接进行指针比较
 * @param data 附加数据，会被传递给comparator, 可以为NULL
 * @return 元素在wyArray中的索引位置，如果没有找到，返回-1
 */
WIENGINE_API int wyArrayIndexOf(wyArray* arr, void* obj, wyArrayComparator comparator, void* data);

/**
 * 删除某个位置的元素，这个位置之后的元素将被前移
 *
 * @param arr wyArray指针
 * @param idx 要删除的位置
 * @return 被删除的元素指针，如果idx不合法，则返回NULL
 */
WIENGINE_API void* wyArrayDeleteIndex(wyArray* arr, int idx);

/**
 * 删除某个元素，被删除元素之后的元素将被前移
 *
 * @param arr wyArray指针
 * @param obj 要删除的元素指针
 * @param comparator 元素比较器，如果为NULL，则直接进行指针比较
 * @param data 附加数据，会被传递给comparator, 可以为NULL
 * @return 被删除的元素指针，如果obj在不存在于arr中，则返回NULL
 */
WIENGINE_API void* wyArrayDeleteObj(wyArray* arr, void* obj, wyArrayComparator comparator, void* data);

/**
 * 枚举所有元素。这个操作支持并发操作，即在枚举过程中，可以对wyArray进行修改。但是修改不会立刻对
 * 枚举操作生效，因为这个方法会先复制一份元素列表再进行枚举。
 *
 * @param arr wyArray指针
 * @param iterFunc 枚举函数，每个元素都被传递给iterFunc
 * @param data 附加数据，会被传递给iterFunc
 */
WIENGINE_API void wyArrayConcurrentEach(wyArray* arr, wyArrayIterator iterFunc, void* data);

/**
 * 枚举所有元素，这个操作不支持并发，即在枚举过程中，不能对wyArray进行修改。
 *
 * @param arr wyArray指针
 * @param iterFunc 枚举函数，每个元素都被传递给iterFunc
 * @param data 附加数据，会被传递给iterFunc
 */
WIENGINE_API void wyArrayEach(wyArray* arr, wyArrayIterator iterFunc, void* data);

#ifdef __cplusplus
}
#endif

#endif // __wyArray_h__
