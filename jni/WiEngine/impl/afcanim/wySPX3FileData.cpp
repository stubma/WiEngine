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
#include "wySPX3FileData.h"

wySPX3FileData::wySPX3FileData() :
		m_version(0),
		m_tileSetCount(0),
		m_frameCount(0),
		m_actionCount(0),
		m_tileSets(wyArrayNew(5)),
		m_frames(wyArrayNew(40)),
		m_actions(wyArrayNew(10)) {
}

wySPX3FileData::~wySPX3FileData() {
	wyArrayEach(m_tileSets, releaseObject, NULL);
	wyArrayDestroy(m_tileSets);

	wyArrayEach(m_frames, releaseObject, NULL);
	wyArrayDestroy(m_frames);

	wyArrayEach(m_actions, releaseObject, NULL);
	wyArrayDestroy(m_actions);
}

wySPX3FileData* wySPX3FileData::make() {
	wySPX3FileData* fd = WYNEW wySPX3FileData();
	return (wySPX3FileData*)fd->autoRelease();
}

bool wySPX3FileData::releaseObject(wyArray* arr, void* ptr, int index, void* data) {
	((wyObject*)ptr)->release();
	return true;
}
