package com.wiyun.engine.transitions;

import com.wiyun.engine.nodes.Scene;

/**
 * 旧场景从不透明变成透明，新场景从透明变成不透明
 */
public class CrossFadeTransition extends TransitionScene {
	/**
	 * 静态构造函数
	 *
	 * @param duration 场景切换的时间
	 * @param inScene 准备载入的\link Scene Scene对象指针\endlink. 如果不为NULL, 则
	 * 		载出场景自动设置为当前场景. 如果为NULL, 则载入场景和载出场景都不设置. 需要在之后再
	 * 		自行设置. 一般如果是想在popScene的时候, 需要把这个参数设置为NULL, 这样\link Director Director\endlink
	 * 		会自动设置载入和载出场景.
	 * @return {@link CrossFadeTransition}
	 */
    public static CrossFadeTransition make(float duration, Scene inScene) {
        return new CrossFadeTransition(duration, inScene);
    }

    /**
     * initializes the transition with a duration
     */
    protected CrossFadeTransition(float duration, Scene inScene) {
    	nativeInit(duration, inScene);
    }
    
    /**
     * 从底层指针获得一个CrossFadeTransition的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link CrossFadeTransition}
     */
    public static CrossFadeTransition from(int pointer) {
    	return pointer == 0 ? null : new CrossFadeTransition(pointer);
    }
    
    protected CrossFadeTransition(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(float duration, Scene inScene);
}
