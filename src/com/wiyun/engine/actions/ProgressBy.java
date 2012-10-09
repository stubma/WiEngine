package com.wiyun.engine.actions;


/**
 * \if English
 * Progress action which depends on a \link ProgressTimer ProgressTimer\endlink
 * node
 * \else
 * 使节点称为进度条显示的动作封装，根据指定变化的百分比执行动作
 * \endif
 */
public class ProgressBy extends IntervalAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time
	 * @param deltaPercent delta percentage
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param deltaPercent 节点变化的百分比，取值0到100
	 * \endif
	 */
	public static ProgressBy make(float duration, float deltaPercent) {
		return new ProgressBy(duration, deltaPercent);
	}
	
	protected ProgressBy(float duration, float deltaPercent) {
		nativeInit(duration, deltaPercent);
	}
	
    /**
     * 从底层指针获得一个ProgressBy的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ProgressBy}
     */
    public static ProgressBy from(int pointer) {
    	return pointer == 0 ? null : new ProgressBy(pointer);
    }
	
	protected ProgressBy(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, float deltaPercent);

	@Override
	public IntervalAction copy() {
		return new ProgressBy(nativeCopy());
	}

	@Override
	public IntervalAction reverse() {
		return new ProgressBy(nativeReverse());
	}
}
