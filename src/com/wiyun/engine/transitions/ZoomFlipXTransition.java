package com.wiyun.engine.transitions;

import com.wiyun.engine.nodes.Scene;

/**
 * 新旧场景沿x轴旋转180度，同时有一定的缩放
 */
public class ZoomFlipXTransition extends TransitionScene {
	/**
	 * 静态构造函数
	 *
	 * @param duration 场景切换的时间
	 * @param inScene 准备载入的\link Scene Scene对象指针\endlink. 如果不为NULL, 则
	 * 		载出场景自动设置为当前场景. 如果为NULL, 则载入场景和载出场景都不设置. 需要在之后再
	 * 		自行设置. 一般如果是想在popScene的时候, 需要把这个参数设置为NULL, 这样\link Director Director\endlink
	 * 		会自动设置载入和载出场景.
	 * @param toLeft 标识向左还是向右旋转，true为向左
	 * @param scale 缩放比
	 * @return {@link ZoomFlipXTransition}
	 */
    public static ZoomFlipXTransition make(float duration, Scene inScene, boolean toLeft, float scale) {
        return new ZoomFlipXTransition(duration, inScene, toLeft, scale);
    }

    protected ZoomFlipXTransition(float duration, Scene inScene, boolean toLeft, float scale) {
    	nativeInit(duration, inScene, toLeft, scale);
    }
    
    /**
     * 从底层指针获得一个ZoomFlipXTransition的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ZoomFlipXTransition}
     */
    public static ZoomFlipXTransition from(int pointer) {
    	return pointer == 0 ? null : new ZoomFlipXTransition(pointer);
    }
    
    protected ZoomFlipXTransition(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(float duration, Scene inScene, boolean toLeft, float scale);
}
