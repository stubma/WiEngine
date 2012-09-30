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
package com.wiyun.engine.afcanim;

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.types.WYPoint;

/**
 * \if English
 * A frame in an animation
 * \else
 * 帧数据对象, 它代表了一个动画里的一帧. 一帧由多个Clip(分片)组成,
 * 分片可以是图片, 也可以是某个区域.
 * \endif
 */
public class AFCFrame extends BaseWYObject {
	public static AFCFrame from(int pointer) {
		return pointer == 0 ? null : new AFCFrame(pointer);
	}
	
	protected AFCFrame(int pointer) {
		super(pointer);
	}
	
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
	public native int getClipCount();

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
	public native int getClipCount(int type);

	/**
	 * \if English
	 * Get clip at specified index
	 *
	 * @param index index, starts from 0
	 * @return \link AFCClip AFCClip\endlink object, or NULL if index is invalid
	 * \else
	 * 得到某个位置处的分片
	 *
	 * @param index 分片索引
	 * @return \link AFCClip AFCClip\endlink对象, 如果索引非法, 返回NULL
	 * \endif
	 */
	public AFCClip getClipAt(int index) {
		return AFCClip.from(nativeGetClipAt(index));
	}
	
	private native int nativeGetClipAt(int index);

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
	public native float getDelay();

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
	public WYPoint getIncrementation() {
		WYPoint p = WYPoint.makeZero();
		nativeGetIncrementation(p);
		return p;
	}
	
	private native void nativeGetIncrementation(WYPoint p);
	
	/**
	 * \if English
	 * Get clip by index and the clip must be given type
	 *
	 * @param type clip type
	 * @para index index of clip with same types, so it may not reflect actuall position
	 * 		in clip array
	 * @return \link AFCClip AFCClip\endlink, or NULL if not found
	 * \else
	 * 得到某个类型的第几个分片
	 *
	 * @param type 分片类型
	 * @param index 分片索引, 这个索引只计算同样类型的分片, 因此它不一定反映分片在
	 * 		数组中的实际位置
	 * @return \link AFCClip AFCClip\endlink, 如果没有找到, 则返回NULL
	 * \endif
	 */
	public AFCClip getClipAt(int type, int index) {
		return AFCClip.from(nativeGetClipAt(type, index));
	}
	
	private native int nativeGetClipAt(int type, int index);
	
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
	public native boolean isFlipX();
    
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
	public native boolean isFlipY();
}
