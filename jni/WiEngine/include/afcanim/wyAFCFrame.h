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
 * \if English
 * A frame in an animation
 * \else
 * 帧数据对象, 它代表了一个动画里的一帧. 一帧由多个Clip(分片)组成,
 * 分片可以是图片, 也可以是某个区域.
 * \endif
 */
class WIENGINE_API wyAFCFrame : public wyObject {
private:
	/**
	 * \if English
	 * Clip list, all are \link wyAFCClip wyAFCClip\endlink object
	 * \else
	 * clip列表, 都是\link wyAFCClip wyAFCClip\endlink对象
	 * \endif
	 */
	wyArray* m_clipList;

	/**
	 * \if English
	 * Duration time of frame
	 * \else
	 * 帧持续时间
	 * \endif
	 */
	float m_delay;

	/**
	 * \if English
	 * true means \c m_delay is not a time but a frame count duration
	 * \else
	 * true表示\c m_delay不是一个时间单位, 而是一个帧数, 比如2表示这一个动画帧
	 * 要维持2帧的时间
	 * \endif
	 */
	bool m_useTickDelay;

	/**
	 * \if English
	 * offset relative to previous frame
	 * \else
	 * 这一帧相对于上一帧的偏移
	 * \endif
	 */
	wyPoint m_inc;
    
    /**
     * \if English
     * true means frame is flipped in x axis
     * \else
     * true表示帧在x轴上翻转
     * \endif
     */
    bool m_flipX;
    
    /**
     * \if English
     * true means frame is flipped in y axis
     * \else
     * true表示帧在y轴上翻转
     * \endif
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
	 * \if English
	 * Get clip count in this animation
	 *
	 * @return clip count
	 * \else
	 * 得到帧中的分片数
	 *
	 * @return 分片数
	 * \endif
	 */
	int getClipCount() { return m_clipList->num; }

	/**
	 * \if English
	 * Get clip count of specific type
	 *
	 * @param type clip type
	 * @return clip count of that type
	 * \else
	 * 得到某种类型分片的个数
	 *
	 * @param type 分片类型
	 * @return 某种类型分片的个数
	 * \endif
	 */
	int getClipCount(wyAFCClipType type);

	/**
	 * \if English
	 * Add a clip to frame
	 *
	 * @param clip \link wyAFCClip wyAFCClip\endlink
	 * \else
	 * 添加一个分片到帧中
	 *
	 * @param clip \link wyAFCClip wyAFCClip\endlink
	 * \endif
	 */
	void addClip(wyAFCClip* clip);

	/**
	 * \if English
	 * Get clip at specified index
	 *
	 * @param index index, starts from 0
	 * @return \link wyAFCClip wyAFCClip\endlink object, or NULL if index is invalid
	 * \else
	 * 得到某个位置处的分片
	 *
	 * @param index 分片索引
	 * @return \link wyAFCClip wyAFCClip\endlink对象, 如果索引非法, 返回NULL
	 * \endif
	 */
	wyAFCClip* getClipAt(int index) { return (wyAFCClip*)wyArrayGet(m_clipList, index); }

	/**
	 * \if English
	 * Get clip by index and the clip must be given type
	 *
	 * @param type clip type
	 * @para index index of clip with same types, so it may not reflect actuall position
	 * 		in clip array
	 * @return \link wyAFCClip wyAFCClip\endlink, or NULL if not found
	 * \else
	 * 得到某个类型的第几个分片
	 *
	 * @param type 分片类型
	 * @param index 分片索引, 这个索引只计算同样类型的分片, 因此它不一定反映分片在
	 * 		数组中的实际位置
	 * @return \link wyAFCClip wyAFCClip\endlink, 如果没有找到, 则返回NULL
	 * \endif
	 */
	wyAFCClip* getClipAt(wyAFCClipType type, int index);

	/**
	 * \if English
	 * Set frame duration time
	 *
	 * @param delay frame duration time in second
	 * \else
	 * 设置帧持续时间
	 *
	 * @param delay 帧持续时间
	 * \endif
	 */
	void setDelay(float delay) { m_delay = delay; }

	/**
	 * \if English
	 * Get frame duration time, maybe in tick or seconds
	 *
	 * @return frame duration time in tick or seconds
	 * \else
	 * 得到帧持续时间, 返回的时间单位不一定是秒, 也可能是tick数
	 *
	 * @return 帧持续tick数或者秒数
	 * \endif
	 */
	float getDelay() { return m_delay; }

	/**
	 * \if English
	 * is \c m_delay a tick value?
	 *
	 * @return true means \c m_delay is not time, but frames
	 * \else
	 * \c m_delay是否是一个帧数延迟
	 *
	 * @return true表示\c m_delay不是时间, 而是帧数
	 * \endif
	 */
	bool isUseTickDelay() { return m_useTickDelay; }

	/**
	 * \if English
	 * Set using tick delay or not
	 *
	 * @param flag true means \c m_delay is frames, not time
	 * \else
	 * 设置是否使用帧数指定帧显示时间
	 *
	 * @param flag true表示\c m_delay不是时间, 而是帧数
	 * \endif
	 */
	void setUseTickDelay(bool flag) { m_useTickDelay = flag; }

	/**
	 * \if English
	 * Get offset relative to previous frame
	 *
	 * @return offset relative to previous frame
	 * \else
	 * 得到相对于上一帧的偏移
	 *
	 * @return 相对于上一帧的偏移
	 * \endif
	 */
	wyPoint getIncrementation() { return m_inc; }

	/**
	 * \if English
	 * Set offset relative to previous frame
	 *
	 * @param inc offset relative to previous frame
	 * \else
	 * 设置相对于上一帧的偏移
	 *
	 * @param inc 相对于上一帧的偏移
	 * \endif
	 */
	void setIncrementation(wyPoint inc) { m_inc = inc; }
    
    /**
     * \if English
     * Get x flip flag
     * 
     * @return true means frame is flipped in x axis
     * \else
     * 获得x翻转标志
     * 
     * @return true表示帧在x轴上翻转
     * \endif
     */
    bool isFlipX() { return m_flipX; }
    
    /**
     * \if English
     * Set x flip flag
     * 
     * @param flag true means frame is flipped in x axis
     * \else
     * 设置x翻转标志
     * 
     * @param flag true表示帧在x轴上翻转
     * \endif
     */
    void setFlipX(bool flag) { m_flipX = flag; }
    
    /**
     * \if English
     * Get y flip flag
     * 
     * @return true means frame is flipped in y axis
     * \else
     * 获得y翻转标志
     * 
     * @return true表示帧在y轴上翻转
     * \endif
     */
    bool isFlipY() { return m_flipY; }
    
    /**
     * \if English
     * Set y flip flag
     * 
     * @param flag true means frame is flipped in y axis
     * \else
     * 设置y翻转标志
     * 
     * @param flag true表示帧在y轴上翻转
     * \endif
     */
    void setFlipY(bool flag) { m_flipY = flag; }
};

#endif // __wyAFCFrame_h__
