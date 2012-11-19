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
#ifndef __wyAFCFrame_h__
#define __wyAFCFrame_h__

#include "wyObject.h"
#include "wyArray.h"
#include "wyTypes.h"
#include "wyAFCClip.h"

/**
 * @class wyAFCFrame
 *
 * A frame in an animation
 */
class WIENGINE_API wyAFCFrame : public wyObject {
private:
	/**
	 * Clip list, all are \link wyAFCClip wyAFCClip\endlink object
	 */
	wyArray* m_clipList;

	/**
	 * Duration time of frame
	 */
	float m_delay;

	/**
	 * true means \c m_delay is not a time but a frame count duration
	 */
	bool m_useTickDelay;

	/**
	 * offset relative to previous frame
	 */
	wyPoint m_inc;
    
    /**
     * true means frame is flipped in x axis
     */
    bool m_flipX;
    
    /**
     * true means frame is flipped in y axis
     */
    bool m_flipY;

private:
	static bool releaseClip(wyArray* arr, void* ptr, int index, void* data);

protected:
	wyAFCFrame();

public:
	virtual ~wyAFCFrame();
	static wyAFCFrame* make();

	/**
	 * Get clip count in this animation
	 *
	 * @return clip count
	 */
	int getClipCount() { return m_clipList->num; }

	/**
	 * Get clip count of specific type
	 *
	 * @param type clip type
	 * @return clip count of that type
	 */
	int getClipCount(wyAFCClipType type);

	/**
	 * Add a clip to frame
	 *
	 * @param clip \link wyAFCClip wyAFCClip\endlink
	 */
	void addClip(wyAFCClip* clip);

	/**
	 * Get clip at specified index
	 *
	 * @param index index, starts from 0
	 * @return \link wyAFCClip wyAFCClip\endlink object, or NULL if index is invalid
	 */
	wyAFCClip* getClipAt(int index) { return (wyAFCClip*)wyArrayGet(m_clipList, index); }

	/**
	 * Get clip by index and the clip must be given type
	 *
	 * @param type clip type
	 * @para index index of clip with same types, so it may not reflect actuall position
	 * 		in clip array
	 * @return \link wyAFCClip wyAFCClip\endlink, or NULL if not found
	 */
	wyAFCClip* getClipAt(wyAFCClipType type, int index);

	/**
	 * Set frame duration time
	 *
	 * @param delay frame duration time in second
	 */
	void setDelay(float delay) { m_delay = delay; }

	/**
	 * Get frame duration time, maybe in tick or seconds
	 *
	 * @return frame duration time in tick or seconds
	 */
	float getDelay() { return m_delay; }

	/**
	 * is \c m_delay a tick value?
	 *
	 * @return true means \c m_delay is not time, but frames
	 */
	bool isUseTickDelay() { return m_useTickDelay; }

	/**
	 * Set using tick delay or not
	 *
	 * @param flag true means \c m_delay is frames, not time
	 */
	void setUseTickDelay(bool flag) { m_useTickDelay = flag; }

	/**
	 * Get offset relative to previous frame
	 *
	 * @return offset relative to previous frame
	 */
	wyPoint getIncrementation() { return m_inc; }

	/**
	 * Set offset relative to previous frame
	 *
	 * @param inc offset relative to previous frame
	 */
	void setIncrementation(wyPoint inc) { m_inc = inc; }
    
    /**
     * Get x flip flag
     * 
     * @return true means frame is flipped in x axis
     */
    bool isFlipX() { return m_flipX; }
    
    /**
     * Set x flip flag
     * 
     * @param flag true means frame is flipped in x axis
     */
    void setFlipX(bool flag) { m_flipX = flag; }
    
    /**
     * Get y flip flag
     * 
     * @return true means frame is flipped in y axis
     */
    bool isFlipY() { return m_flipY; }
    
    /**
     * Set y flip flag
     * 
     * @param flag true means frame is flipped in y axis
     */
    void setFlipY(bool flag) { m_flipY = flag; }
};

#endif // __wyAFCFrame_h__
