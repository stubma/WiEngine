package com.wiyun.engine.actions;

/**
 * \if English
 * Rotate a node. For a node, position value means clockwise and negative value means
 * counter-clockwise.
 * \else
 * 节点旋转的动作封装,根据设置旋转起始度数进行节点旋转
 * \endif
 */
public class RotateTo extends IntervalAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time in seconds
	 * @param startAngle start angle in degree
	 * @param endAngle end angle in degree
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param startAngle 节点初始的角度
	 * @param endAngle 节点目标的角度
	 * \endif
	 */
    public static RotateTo make(float duration, float startAngle, float endAngle) {
        return new RotateTo(duration, startAngle, endAngle);
    }

    protected RotateTo(float duration, float startAngle, float endAngle) {
    	nativeInit(duration, startAngle, endAngle);
    }
   
    public static RotateTo from(int pointer) {
    	return pointer == 0 ? null : new RotateTo(pointer);
    }
    
    protected RotateTo(int pointer) {
    	super(pointer);
	}

	private native void nativeInit(float duration, float startAngle, float endAngle);

    @Override
    public IntervalAction copy() {
        return new RotateTo(nativeCopy());
    }
    
    @Override
    public IntervalAction reverse() {
    	return new RotateTo(nativeReverse());
    }
}
