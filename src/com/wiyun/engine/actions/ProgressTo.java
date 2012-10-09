package com.wiyun.engine.actions;


/**
 * \if English
 * progress a node, this action can only impose to \link wyProgressTimer wyProgressTimer\endlink
 * \else
 * 使节点称为进度条显示的动作封装，根据指定变化到的百分比执行动作
 * \endif
 */
public class ProgressTo extends IntervalAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time in seconds
	 * @param from start percentage, from 0 to 100
	 * @param to end percentage from 0 to 100
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param from 节点起始显示百分比，取值0到100
	 * @param to 节点结束显示百分比，取值0到100
	 * \endif
	 */
	public static ProgressTo make(float duration, float from, float to) {
		return new ProgressTo(duration, from, to);
	}
	
	protected ProgressTo(float duration, float from, float to) {
		nativeInit(duration, from, to);
	}
	
    /**
     * 从底层指针获得一个ProgressTo的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ProgressTo}
     */
    public static ProgressTo from(int pointer) {
    	return pointer == 0 ? null : new ProgressTo(pointer);
    }

	protected ProgressTo(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(float duration, float from, float to);

	@Override
	public IntervalAction copy() {
		return new ProgressTo(nativeCopy());
	}

	@Override
	public IntervalAction reverse() {
		return new ProgressTo(nativeReverse());
	}
}
