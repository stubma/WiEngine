package com.wiyun.engine.transitions;

import com.wiyun.engine.nodes.Scene;

/**
 * 新旧场景在一定角度上翻转180度
 */
public class FlipAngularTransition extends TransitionScene {
	/**
	 * 静态构造函数
	 *
	 * @param duration 场景切换的时间
	 * @param inScene 准备载入的\link Scene Scene对象指针\endlink. 如果不为NULL, 则
	 * 		载出场景自动设置为当前场景. 如果为NULL, 则载入场景和载出场景都不设置. 需要在之后再
	 * 		自行设置. 一般如果是想在popScene的时候, 需要把这个参数设置为NULL, 这样\link Director Director\endlink
	 * 		会自动设置载入和载出场景.
	 * @param toLeft 标识向左还是向右旋转，true为向左
	 * @return {@link FlipAngularTransition}
	 */
    public static FlipAngularTransition make(float duration, Scene inScene, boolean toLeft) {
        return new FlipAngularTransition(duration, inScene, toLeft);
    }

    protected FlipAngularTransition(float duration, Scene inScene, boolean toLeft) {
    	nativeInit(duration, inScene, toLeft);
    }
    
    /**
     * 从底层指针获得一个FlipAngularTransition的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link FlipAngularTransition}
     */
    public static FlipAngularTransition from(int pointer) {
    	return pointer == 0 ? null : new FlipAngularTransition(pointer);
    }
    
    protected FlipAngularTransition(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(float duration, Scene inScene, boolean toLeft);
}