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
#include "wyCombineColorFilter.h"
#include <stdarg.h>

wyCombineColorFilter::wyCombineColorFilter() :
		m_filters(wyArrayNew(5)) {
}

wyCombineColorFilter::~wyCombineColorFilter() {
	wyArrayEach(m_filters, releaseFilter, NULL);
	wyArrayDestroy(m_filters);
}

bool wyCombineColorFilter::releaseFilter(wyArray* arr, void* ptr, int index, void* data) {
	wyObjectRelease((wyObject*)ptr);
	return true;
}

wyCombineColorFilter* wyCombineColorFilter::make(wyColorFilter* filter1, ...) {
	wyCombineColorFilter* f = WYNEW wyCombineColorFilter();
	f->addFilter(filter1);

	va_list filters;
	va_start(filters, filter1);
    for(wyColorFilter* now = va_arg(filters, wyColorFilter*); now != NULL; now = va_arg(filters, wyColorFilter*)) {
    	f->addFilter(now);
    }
	va_end(filters);

	return (wyCombineColorFilter*)f->autoRelease();
}

void wyCombineColorFilter::addFilter(wyColorFilter* filter) {
	if(filter) {
		wyArrayPush(m_filters, filter);
		filter->retain();
	}
}

void wyCombineColorFilter::apply(void* data, int width, int height) {
	for(int i = 0; i < m_filters->num; i++) {
		wyColorFilter* f = (wyColorFilter*)wyArrayGet(m_filters, i);
		f->apply(data, width, height);
	}
}
