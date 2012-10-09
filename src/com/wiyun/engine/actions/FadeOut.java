package com.wiyun.engine.actions;


/**
 * \if English
 * Fade out a node, it changes alpha of node from 1 to 0
 * \else
 * 淡出动作。目标的alpha会渐渐变成0。目标对象必须实现Node.ITransparent接口。
 * \endif
 */
public class FadeOut extends IntervalAction {
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param duration duration time of action
	 * @return \link FadeOut FadeOut\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @return \link FadeOut FadeOut\endlink
	 * \endif
	 */
    public static FadeOut make(float duration) {
        return new FadeOut(duration, false);
    }
    
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param duration duration time of action
	 * @param includeChildren true indicating modify alpha value of child nodes recursively
	 * @return \link FadeOut FadeOut\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param includeChildren true表示同时修改所有子节点的alpha值, 缺省是false
	 * @return \link FadeOut FadeOut\endlink
	 * \endif
	 */
    public static FadeOut make(float duration, boolean includeChildren) {
    	return new FadeOut(duration, includeChildren);
    }

    protected FadeOut(float duration, boolean includeChildren) {
    	nativeInit(duration, includeChildren);
    }

    public static FadeOut from(int pointer) {
    	return pointer == 0 ? null : new FadeOut(pointer);
    }
    
    protected FadeOut(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(float duration, boolean includeChildren);
    
    @Override
    public IntervalAction copy() {
    	return new FadeOut(nativeCopy());
    }

    @Override
    public IntervalAction reverse() {
        return new FadeIn(nativeReverse());
    }
}
