package com.wiyun.engine.actions;


/**
 * 重复动作. 将一个已有动作重复指定次数.
 */
public class Repeat extends IntervalAction {
    /**
     * 创建动作实例
     * 
     * @param action 一个已有的动作, 必须是{@link FiniteTimeAction}子类
     * @param times 重复次数
     * @return 动作实例
     */
    public static Repeat make(FiniteTimeAction action, int times) {
        return new Repeat(action, times);
    }

    /**
     * 构造函数
     * 
     * @param action 一个已有的动作, 必须是{@link FiniteTimeAction}子类
     * @param times 重复次数
     */
    protected Repeat(FiniteTimeAction action, int times) {
    	nativeInit(action, times);
    }
    
    /**
     * 从底层指针获得一个Repeat的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Repeat}
     */
    public static Repeat from(int pointer) {
    	return pointer == 0 ? null : new Repeat(pointer);
    }
    
    protected Repeat(int pointer) {
    	super(pointer);
	}

	private native void nativeInit(FiniteTimeAction action, int times);
    
    @Override
    public IntervalAction copy() {
    	return new Repeat(nativeCopy());
    }
    
    @Override
    public IntervalAction reverse() {
    	return new Repeat(nativeReverse());
    }
}
