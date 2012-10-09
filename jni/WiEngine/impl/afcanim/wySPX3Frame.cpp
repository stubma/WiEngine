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
#include "wySPX3Frame.h"
#include <stdlib.h>

wySPX3Frame::wySPX3Frame() :
		m_flags(0),
		m_patchCount(0),
		m_collisionCount(0),
		m_patches(NULL),
		m_collisionRects(NULL) {
	memset(&m_rect, 0, sizeof(wySPX3Tile));
}

wySPX3Frame::~wySPX3Frame() {
	if(m_patches) {
		wySPX3Patch* p = m_patches;
		for(int i = 0; i < m_patchCount; i++, p++) {
			if(p->type == SPX_PATCH_SHAPE) {
				if(p->shape.params)
					wyFree(p->shape.params);
			}
		}

		wyFree(m_patches);
	}

	if(m_collisionRects)
		wyFree(m_collisionRects);
}

wySPX3Frame* wySPX3Frame::make() {
	wySPX3Frame* ts = WYNEW wySPX3Frame();
	return (wySPX3Frame*)ts->autoRelease();
}
