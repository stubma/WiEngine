package com.wiyun.engine.transitions;

import com.wiyun.engine.nodes.Scene;
import com.wiyun.engine.types.WYColor3B;

/**
 * 一个颜色层由透明变成不透明，再由不透明变成透明
 */
public class ColorFadeTransition extends TransitionScene {
	/**
	 * 静态构造函数
	 *
	 * @param duration 场景切换的时间
	 * @param inScene 准备载入的\link Scene Scene对象指针\endlink. 如果不为NULL, 则
	 * 		载出场景自动设置为当前场景. 如果为NULL, 则载入场景和载出场景都不设置. 需要在之后再
	 * 		自行设置. 一般如果是想在popScene的时候, 需要把这个参数设置为NULL, 这样\link Director Director\endlink
	 * 		会自动设置载入和载出场景.
	 * @param rgb 颜色层颜色\link Color3B Color3B结构\endlink
	 * @return {@link ColorFadeTransition}
	 */
    public static ColorFadeTransition make(float duration, Scene inScene, WYColor3B rgb) {
        return new ColorFadeTransition(duration, inScene, rgb);
    }

    /**
     * initializes the transition with a duration and with an RGB color
     */
    protected ColorFadeTransition(float duration, Scene inScene, WYColor3B rgb) {
    	nativeInit(duration, inScene, rgb);
    }
    
    /**
     * 从底层指针获得一个ColorFadeTransition的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ColorFadeTransition}
     */
    public static ColorFadeTransition from(int pointer) {
    	return pointer == 0 ? null : new ColorFadeTransition(pointer);
    }
    
    protected ColorFadeTransition(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(float duration, Scene inScene, WYColor3B rgb);

    /**
     * initializes the transition with a duration
     */
    public ColorFadeTransition(float duration, Scene inScene) {
        this(duration, inScene, new WYColor3B(0, 0, 0));
    }
}
