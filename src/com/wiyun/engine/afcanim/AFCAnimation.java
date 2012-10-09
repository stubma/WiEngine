package com.wiyun.engine.afcanim;

import com.wiyun.engine.BaseWYObject;

/**
 * \if English
 * This class represents an animation in AFC architecture
 * \else
 * 这个类只代表一个动画，包含了这个动画的所有帧信息.
 * \endif
 */
public class AFCAnimation extends BaseWYObject {
	public static AFCAnimation from(int pointer) {
		return pointer == 0 ? null : new AFCAnimation(pointer);
	}
	
	protected AFCAnimation(int pointer) {
		super(pointer);
	}
	
	/**
	 * \if English
	 * Get frame count in this animation
	 *
	 * @return frame count
	 * \else
	 * 得到动画中的帧数
	 *
	 * @return 帧数
	 * \endif
	 */
	public native int getFrameCount();

	/**
	 * \if English
	 * Get frame at specified index
	 *
	 * @param index index, starts from 0
	 * @return \link AFCFrame AFCFrame\endlink object, or NULL if index is invalid
	 * \else
	 * 得到某个位置处的帧
	 *
	 * @param index 帧索引
	 * @return \link AFCFrame AFCFrame\endlink对象, 如果索引非法, 返回NULL
	 * \endif
	 */
	public AFCFrame getFrameAt(int index) {
		return AFCFrame.from(nativeGetFrameAt(index));
	}
	
	private native int nativeGetFrameAt(int index);
}
