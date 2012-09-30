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
#include "wyAFCFrame.h"

bool wyAFCFrame::releaseClip(wyArray* arr, void* ptr, int index, void* data) {
	wyAFCClip* c = (wyAFCClip*)ptr;
	wyObjectRelease(c);
	return true;
}

wyAFCFrame::wyAFCFrame() :
		m_clipList(wyArrayNew(5)),
		m_delay(0),
        m_flipX(false),
        m_flipY(false),
		m_useTickDelay(false),
		m_inc(wypZero) {
}

wyAFCFrame::~wyAFCFrame() {
	wyArrayEach(m_clipList, releaseClip, NULL);
	wyArrayDestroy(m_clipList);
}

wyAFCFrame* wyAFCFrame::make() {
	wyAFCFrame* f = WYNEW wyAFCFrame();
	return (wyAFCFrame*)f->autoRelease();
}

void wyAFCFrame::addClip(wyAFCClip* clip) {
	if(clip) {
		wyArrayPush(m_clipList, clip);
		clip->retain();
	}
}

int wyAFCFrame::getClipCount(wyAFCClipType type) {
	int count = 0;
	for(int i = 0; i < m_clipList->num; i++) {
		wyAFCClip* clip = getClipAt(i);
		if(clip->getType() == type)
			count++;
	}
	return count;
}

wyAFCClip* wyAFCFrame::getClipAt(wyAFCClipType type, int index) {
	for(int i = 0; i < m_clipList->num; i++) {
		wyAFCClip* clip = getClipAt(i);
		if(clip->getType() == type) {
			index--;
			if(index < 0)
				return clip;
		}
	}

	return NULL;
}
