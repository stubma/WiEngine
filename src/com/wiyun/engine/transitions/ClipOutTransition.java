package com.wiyun.engine.transitions;

import com.wiyun.engine.nodes.Scene;

/**
 * \if English
 * Old scene uses clip out action to hide itself gradually so new scene becomes visible
 * \else
 * 旧的场景通过\link ClipOut ClipOut\endlink逐渐隐藏从而显示新场景
 * \endif
 */
public class ClipOutTransition extends TransitionScene {
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param duration transition duration time in seconds
	 * @param inScene new scene
	 * @param direction clip shrink direction
	 * @return \link ClipOutTransition ClipOutTransition\endlink
	 * \else
	 * 静态构造方法
	 *
	 * @param duration 转场持续时间
	 * @param inScene 新场景
	 * @param direction 裁剪区域收缩方向
	 * @return \link ClipOutTransition ClipOutTransition\endlink
	 * \endif
	 */
	public static ClipOutTransition make(float duration, Scene inScene, int direction) {
		return new ClipOutTransition(duration, inScene, direction);
	}

	protected ClipOutTransition(float duration, Scene inScene, int direction) {
		nativeInit(duration, inScene, direction);
	}
	
    public static ClipOutTransition from(int pointer) {
    	return pointer == 0 ? null : new ClipOutTransition(pointer);
    }
    
    protected ClipOutTransition(int pointer) {
    	super(pointer);
    }
	
	private native void nativeInit(float duration, Scene inScene, int direction);
}
