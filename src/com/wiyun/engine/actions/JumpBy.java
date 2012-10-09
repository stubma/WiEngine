package com.wiyun.engine.actions;

/**
 * \if English
 * A node jumps from current position to elsewhere, the jumping can be adjusted by offset, height and times
 * \else
 * 节点跳跃的动作封装,根据设置偏移量，高度，跳跃次数进行移动
 * \endif
 */
public class JumpBy extends IntervalAction {
	/**
	 * \if English
	 * static constructor
	 *
	 * @param duration duration time of action
	 * @param x jump offset in x axis
	 * @param y jump offset in y axis
	 * @param height height of jumping
	 * @param jumps times of jumping
	 * @return \link JumpBy JumpBy\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param x 节点偏移x轴距离
	 * @param y 节点偏移y轴距离
	 * @param height 节点跳跃的高度
	 * @param jumps 节点跳跃的次数
	 * @return \link JumpBy JumpBy\endlink
	 * \endif
	 */
    public static JumpBy make(float duration, float x, float y, float height, int jumps) {
        return new JumpBy(duration, x, y, height, jumps);
    }

    protected JumpBy(float duration, float x, float y, float height, int jumps) {
    	nativeInit(duration, x, y, height, jumps);
    }
    
    private native void nativeInit(float duration, float x, float y, float height, int jumps);

    public static JumpBy from(int pointer) {
    	return pointer == 0 ? null : new JumpBy(pointer);
    }
    
    protected JumpBy(int pointer) {
    	super(pointer);
	}

	@Override
    public IntervalAction copy() {
        return new JumpBy(nativeCopy());
    }

    @Override
    public IntervalAction reverse() {
        return new JumpBy(nativeReverse());
    }
}
