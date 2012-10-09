package com.wiyun.engine.actions;

/**
 * \if English
 * Fade in a node, it changes alpha of node from 0 to 255
 * \else
 * 淡入动作。目标的alpha会渐渐变成255。目标对象必须实现Node.ITransparent接口。
 * \endif
 */
public class FadeIn extends IntervalAction {
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param duration duration time of this action
	 * @return \link FadeIn FadeIn\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @return \link FadeIn FadeIn\endlink
	 * \endif
	 */
    public static FadeIn make(float duration) {
        return new FadeIn(duration, false);
    }
    
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param duration duration time of this action
	 * @param includeChildren true indicating modify alpha value of child nodes recursively
	 * @return \link FadeIn FadeIn\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param includeChildren true表示同时修改所有子节点的alpha值, 缺省是false
	 * @return \link FadeIn FadeIn\endlink
	 * \endif
	 */
    public static FadeIn make(float duration, boolean includeChildren) {
    	return new FadeIn(duration, includeChildren);
    }

    protected FadeIn(float duration, boolean includeChildren) {
    	nativeInit(duration, includeChildren);
    }
    
    public static FadeIn from(int pointer) {
    	return pointer == 0 ? null : new FadeIn(pointer);
    }
    
    protected FadeIn(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(float duration, boolean includeChildren);
    
    @Override
    public IntervalAction copy() {
    	return new FadeIn(nativeCopy());
    }

    @Override
    public IntervalAction reverse() {
        return new FadeOut(nativeReverse());
    }
}
