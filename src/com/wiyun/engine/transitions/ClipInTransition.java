package com.wiyun.engine.transitions;

import com.wiyun.engine.nodes.Scene;

/**
 * \if English
 * Incoming scene uses clip in action to show it gradually
 * \else
 * 新的场景通过\link ClipIn ClipIn\endlink逐渐显示盖掉旧场景
 * \endif
 */
public class ClipInTransition extends TransitionScene {
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param duration transition duration time in seconds
	 * @param inScene new scene
	 * @param direction clip grows direction
	 * @return \link ClipInTransition ClipInTransition\endlink
	 * \else
	 * 静态构造方法
	 *
	 * @param duration 转场持续时间
	 * @param inScene 新场景
	 * @param direction 裁剪区域变化方向
	 * @return \link ClipInTransition ClipInTransition\endlink
	 * \endif
	 */
	public static ClipInTransition make(float duration, Scene inScene, int direction) {
		return new ClipInTransition(duration, inScene, direction);
	}

	protected ClipInTransition(float duration, Scene inScene, int direction) {
		nativeInit(duration, inScene, direction);
	}
	
    public static ClipInTransition from(int pointer) {
    	return pointer == 0 ? null : new ClipInTransition(pointer);
    }
    
    protected ClipInTransition(int pointer) {
    	super(pointer);
    }
	
	private native void nativeInit(float duration, Scene inScene, int direction);
}
