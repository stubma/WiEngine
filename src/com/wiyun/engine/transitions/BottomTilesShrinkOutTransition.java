package com.wiyun.engine.transitions;

import com.wiyun.engine.nodes.Scene;

/**
 * 旧的场景的底部网格逐渐消失，从而显示出新场景
 */
public class BottomTilesShrinkOutTransition extends TransitionScene {
	/**
	 * 静态构造函数
	 *
	 * @param duration 动画持续时间
	 * @param inScene 准备载入的\link Scene Scene对象指针\endlink. 如果不为NULL, 则
	 * 		载出场景自动设置为当前场景. 如果为NULL, 则载入场景和载出场景都不设置. 需要在之后再
	 * 		自行设置. 一般如果是想在popScene的时候, 需要把这个参数设置为NULL, 这样\link Director Director\endlink
	 * 		会自动设置载入和载出场景.
	 * @return {@link BottomTilesShrinkOutTransition}
	 */
    public static BottomTilesShrinkOutTransition make(float duration, Scene inScene) {
        return new BottomTilesShrinkOutTransition(duration, inScene, 0, 0);
    }
    
	/**
	 * 静态构造函数
	 *
	 * @param duration 动画持续时间
	 * @param inScene 准备载入的\link Scene Scene对象指针\endlink. 如果不为NULL, 则
	 * 		载出场景自动设置为当前场景. 如果为NULL, 则载入场景和载出场景都不设置. 需要在之后再
	 * 		自行设置. 一般如果是想在popScene的时候, 需要把这个参数设置为NULL, 这样\link Director Director\endlink
	 * 		会自动设置载入和载出场景.
	 * @param rows 格子行数
	 * @param cols 格子列数
	 * @return {@link BottomTilesShrinkOutTransition}
	 */
    public static BottomTilesShrinkOutTransition make(float duration, Scene inScene, int rows, int cols) {
    	return new BottomTilesShrinkOutTransition(duration, inScene, rows, cols);
    }
    
    /**
     * 构造函数
     * 
     * @param duration 动画持续时间
     * @param inScene 新场景
     * @param rows 格子行数
     * @param cols 格子列数
     */
    protected BottomTilesShrinkOutTransition(float duration, Scene inScene, int rows, int cols) {
    	nativeInit(duration, inScene, rows, cols);
    }
    
    /**
     * 从底层指针获得一个BottomTilesShrinkOutTransition的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link BottomTilesShrinkOutTransition}
     */
    public static BottomTilesShrinkOutTransition from(int pointer) {
    	return pointer == 0 ? null : new BottomTilesShrinkOutTransition(pointer);
    }
    
    protected BottomTilesShrinkOutTransition(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(float duration, Scene inScene, int rows, int cols);
}
