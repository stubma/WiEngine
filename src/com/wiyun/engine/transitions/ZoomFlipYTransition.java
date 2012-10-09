package com.wiyun.engine.transitions;

import com.wiyun.engine.nodes.Scene;

/**
 * 新旧场景沿y轴旋转180度，同时有一定的缩放
 */
public class ZoomFlipYTransition extends TransitionScene {
	/**
	 * 静态构造函数
	 *
	 * @param duration 场景切换的时间
	 * @param inScene 准备载入的\link Scene Scene对象指针\endlink. 如果不为NULL, 则
	 * 		载出场景自动设置为当前场景. 如果为NULL, 则载入场景和载出场景都不设置. 需要在之后再
	 * 		自行设置. 一般如果是想在popScene的时候, 需要把这个参数设置为NULL, 这样\link Director Director\endlink
	 * 		会自动设置载入和载出场景.
	 * @param toTop 标识向上还是向下旋转，true为向上
	 * @param scale 缩放比
	 * @return {@link ZoomFlipYTransition}
	 */
    public static ZoomFlipYTransition make(float duration, Scene inScene, boolean toTop, float scale) {
        return new ZoomFlipYTransition(duration, inScene, toTop, scale);
    }

    protected ZoomFlipYTransition(float duration, Scene inScene, boolean toTop, float scale) {
    	nativeInit(duration, inScene, toTop, scale);
    }
    
    /**
     * 从底层指针获得一个ZoomFlipYTransition的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ZoomFlipYTransition}
     */
    public static ZoomFlipYTransition from(int pointer) {
    	return pointer == 0 ? null : new ZoomFlipYTransition(pointer);
    }
    
    protected ZoomFlipYTransition(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(float duration, Scene inScene, boolean toTop, float scale);
}
