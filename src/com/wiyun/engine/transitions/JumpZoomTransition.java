package com.wiyun.engine.transitions;

import com.wiyun.engine.nodes.Scene;

/**
 * 旧场景缩小后跳跃出屏幕，新场景跳跃进屏幕再放大到正常大小。
 */
public class JumpZoomTransition extends TransitionScene {
	/**
	 * 静态构造函数
	 *
	 * @param duration 场景切换的时间
	 * @param inScene 准备载入的\link Scene Scene对象指针\endlink. 如果不为NULL, 则
	 * 		载出场景自动设置为当前场景. 如果为NULL, 则载入场景和载出场景都不设置. 需要在之后再
	 * 		自行设置. 一般如果是想在popScene的时候, 需要把这个参数设置为NULL, 这样\link Director Director\endlink
	 * 		会自动设置载入和载出场景.
	 * @return {@link JumpZoomTransition}
	 */
    public static JumpZoomTransition make(float duration, Scene inScene) {
        return new JumpZoomTransition(duration, inScene);
    }

    protected JumpZoomTransition(float duration, Scene inScene) {
    	nativeInit(duration, inScene);
    }
    
    /**
     * 从底层指针获得一个JumpZoomTransition的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link JumpZoomTransition}
     */
    public static JumpZoomTransition from(int pointer) {
    	return pointer == 0 ? null : new JumpZoomTransition(pointer);
    }
    
    protected JumpZoomTransition(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(float duration, Scene inScene);
}
