package com.wiyun.engine.actions;


/**
 * \if English
 * Change alpha of node from one value to another value
 * \else
 * 节点透明度变化效果的动作封装
 * \endif
 */
public class FadeTo extends IntervalAction {
	/**
	 * \if English
	 * static constructor
	 *
	 * @param duration duration time of action
	 * @param fromAlpha start alpha, range from 0 to 255
	 * @param toAlpha end alpha, range from 0 to 255
	 * @return {@link FadeTo}
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param fromAlpha 起始透明度，取值0到255，255为不透明，0为透明
	 * @param toAlpha 目标透明度，取值0到255，255为不透明，0为透明
	 * @return {@link FadeTo}
	 * \endif
	 */
    public static FadeTo make(float duration, int fromAlpha, int toAlpha) {
        return new FadeTo(duration, fromAlpha, toAlpha, false);
    }
    
	/**
	 * \if English
	 * static constructor
	 *
	 * @param duration duration time of action
	 * @param fromAlpha start alpha, range from 0 to 255
	 * @param toAlpha end alpha, range from 0 to 255
	 * @param includeChildren true indicating modify alpha value of child nodes recursively
	 * @return {@link FadeTo}
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param fromAlpha 起始透明度，取值0到255，255为不透明，0为透明
	 * @param toAlpha 目标透明度，取值0到255，255为不透明，0为透明
	 * @param includeChildren true表示同时修改所有子节点的alpha值
	 * @return {@link FadeTo}
	 * \endif
	 */
    public static FadeTo make(float duration, int fromAlpha, int toAlpha, boolean includeChildren) {
    	return new FadeTo(duration, fromAlpha, toAlpha, includeChildren);
    }

    protected FadeTo(float duration, int fromAlpha, int toAlpha, boolean includeChildren) {
    	nativeInit(duration, fromAlpha, toAlpha, includeChildren);
    }

    public static FadeTo from(int pointer) {
    	return pointer == 0 ? null : new FadeTo(pointer);
    }
    
    public FadeTo(int pointer) {
    	super(pointer);
	}

	private native void nativeInit(float duration, int fromAlpha, int toAlpha, boolean includeChildren);

    @Override
    public IntervalAction copy() {
        return new FadeTo(nativeCopy());
    }
    
    @Override
    public IntervalAction reverse() {
    	return new FadeTo(nativeReverse());
    }
}
