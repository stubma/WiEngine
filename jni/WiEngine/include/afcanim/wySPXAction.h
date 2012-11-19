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
#ifndef __wySPXAction_h__
#define __wySPXAction_h__

#include "wyObject.h"
#include "wySPXConstants.h"

class wySPXLoader;

/**
 * @typedef wySPXActionFrame
 *
 * frame info in animation
 */
typedef struct wySPXActionFrame {
	/**
	 * frame index
	 */
	int index;

	/**
	 * duration of frame
	 */
	float duration;
} wySPXActionFrame;

/**
 * @class wySPXAction
 *
 * Info bean for one SpriteX animation
 */
class WIENGINE_API wySPXAction : public wyObject {
	friend class wySPXLoader;

public:
	/**
	 * transform of anmation
	 */
	wySPXTransform m_transform;

	/**
	 * frame count in this animation
	 */
	int m_frameCount;

	/**
	 * max tile count of frame
	 */
	int m_maxFrameTile;

	/**
	 * frame info
	 */
	wySPXActionFrame* m_frames;

private:
	wySPXAction();

public:
	virtual ~wySPXAction();
};

#endif // __wySPXAction_h__
