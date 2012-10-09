package com.wiyun.engine.actions;

import com.wiyun.engine.nodes.Animation;

/**
 * \if English
 * Encapsulate animation action, it requires a \link Animation Animation\endlink object which
 * provides frame info
 * \else
 * 动画播放动作的封装
 * \endif
 */
public class Animate extends IntervalAction {
	/**
	 * \if English
	 * Static factory method
	 *
	 * @param anim \link Animation Animation\endlink pointer
	 * \else
	 * 静态构造函数
	 *
	 * @param anim 动画\link Animation Animation\endlink 对象指针
	 * \endif
	 */
	public static Animate make(Animation anim) {
		if(anim == null) {
			throw new IllegalArgumentException("Animate: argument Animation must be non-null");
		}
		return new Animate(anim, false);
	}

	/**
	 * \if English
	 * Static factory method
	 *
	 * @param anim \link Animation Animation\endlink pointer
	 * @param fillAfter false indicating restore to original frame when animation ends, or true
	 * 		indicating keep last frame, default is false
	 * \else
	 * 静态构造函数
	 *
	 * @param anim 动画\link Animation Animation\endlink 对象指针
	 * @param fillAfter 动作停止后是否回到sprite的原始图片，true为不回到，false表示回到原来的图片. 缺省是false
	 * \endif
	 */
	public static Animate make(Animation anim, boolean fillAfter) {
		if(anim == null) {
			throw new IllegalArgumentException("Animate: argument Animation must be non-null");
		}
		return new Animate(anim, fillAfter);
	}

	protected Animate(Animation anim, boolean fillAfter) {
		nativeInit(anim, fillAfter);
	}
	
	private native void nativeInit(Animation anim, boolean fillAfter);

    public static Animate from(int pointer) {
    	return pointer == 0 ? null : new Animate(pointer);
    }
    
	protected Animate(int pointer) {
		super(pointer);
	}
	
	@Override
	public IntervalAction copy() {
		return new Animate(nativeCopy());
	}
	
	@Override
	public IntervalAction reverse() {
		return new Animate(nativeReverse());
	}
}
