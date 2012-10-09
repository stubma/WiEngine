package com.wiyun.engine.actions;


/**
 * \if English
 * repeat an action, you can control repeat times
 * \else
 * 根据设置重复次数，重复执行动作的封装
 * \endif
 */
public class RepeatForever extends Action {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param other action to be repeated
	 * @param times repeat times
	 * \else
	 * 静态构造函数
	 *
	 * @param other 具体要执行的\link FiniteTimeAction FiniteTimeAction\endlink指针
	 * @param times 动作重复的次数
	 * \endif
	 */
    public static RepeatForever make(FiniteTimeAction action) {
        return new RepeatForever(action);
    }

    protected RepeatForever(FiniteTimeAction action) {
    	nativeInit(action);
    }
    
    /**
     * 从底层指针获得一个RepeatForever的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link RepeatForever}
     */
    public static RepeatForever from(int pointer) {
    	return pointer == 0 ? null : new RepeatForever(pointer);
    }
    
    protected RepeatForever(int pointer) {
    	super(pointer);
    }

	private native void nativeInit(FiniteTimeAction action);
	
	@Override
	public Action copy() {
		return new RepeatForever(nativeCopy());
	}
	
	@Override
	public Action reverse() {
		return new RepeatForever(nativeReverse());
	}
}
