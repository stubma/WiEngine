package com.wiyun.engine.transitions;

import com.wiyun.engine.nodes.Scene;

/**
 * \if English
 * Transition which uses suck effect
 * \else
 * 使用吸入效果的转场类
 * \endif
 */
public class SuckTransition extends TransitionScene {
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param duration transition duration time in seconds
	 * @param inScene the scene will be switched in. If not NULL, then out scene is current scene.
	 * 		If NULL, the out scene is not set also and somebody must set them after make returns. Generally
	 * 		you will set \c inScene NULL when uses popSceneWithTransition and \link Director Director\endlink
	 * 		will set in and out scene automatically.
	 * @param suckX x position of sucking
	 * @param suckY y position of sucking
	 * @return \link SuckTransition SuckTransition\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 场景切换的时间
	 * @param inScene 准备载入的\link Scene Scene对象指针\endlink. 如果不为NULL, 则
	 * 		载出场景自动设置为当前场景. 如果为NULL, 则载入场景和载出场景都不设置. 需要在之后再
	 * 		自行设置. 一般如果是想在popScene的时候, 需要把这个参数设置为NULL, 这样\link Director Director\endlink
	 * 		会自动设置载入和载出场景.
	 * @param suckX 吸入点的x位置
	 * @param suckY 吸入点的y位置
	 * @return \link SuckTransition SuckTransition\endlink
	 * \endif
	 */
	public static SuckTransition make(float duration, Scene inScene, float suckX, float suckY) {
		return new SuckTransition(duration, inScene, suckX, suckY);
	}

	protected SuckTransition(float duration, Scene inScene, float suckX, float suckY) {
		nativeInit(duration, inScene, suckX, suckY);
	}
	
    /**
     * 从底层指针获得一个SuckTransition的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link SuckTransition}
     */
    public static SuckTransition from(int pointer) {
    	return pointer == 0 ? null : new SuckTransition(pointer);
    }
    
    protected SuckTransition(int pointer) {
    	super(pointer);
    }
	
	private native void nativeInit(float duration, Scene inScene, float suckX, float suckY);
}
