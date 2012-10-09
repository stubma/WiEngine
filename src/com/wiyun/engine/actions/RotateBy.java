package com.wiyun.engine.actions;


/**
 * \if English
 * rotate a node by specified angle, in degree
 * \else
 * 节点旋转的动作封装,根据设置旋转度数进行节点旋转
 * \endif
 */
public class RotateBy extends IntervalAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time of action, in seconds
	 * @param angle angle in degree to be rotated
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param angle 旋转度数
	 * \endif
	 */
    public static RotateBy make(float duration, float angle) {
        return new RotateBy(duration, angle);
    }

    protected RotateBy(float duration, float angle) {
    	nativeInit(duration, angle);
    }
    
    private native void nativeInit(float duration, float angle);

    public static RotateBy from(int pointer) {
    	return pointer == 0 ? null : new RotateBy(pointer);
    }
    
    protected RotateBy(int pointer) {
    	super(pointer);
	}

	@Override
    public IntervalAction copy() {
        return new RotateBy(nativeCopy());
    }

    @Override
    public IntervalAction reverse() {
        return new RotateBy(nativeReverse());
    }
}
