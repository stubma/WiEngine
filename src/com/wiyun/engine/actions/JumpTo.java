package com.wiyun.engine.actions;

/**
 * \if English
 * A node jumps from a position to elsewhere, the jumping can be adjusted by offset, height and times
 * \else
 * 节点跳跃的动作封装,根据设置起始点，结束点，高度，跳跃次数进行移动
 * \endif
 */
public class JumpTo extends IntervalAction {
	/**
	 * \if English
	 * static constructor
	 *
	 * @param duration duration time of jumping
	 * @param startX start x position of jumping
	 * @param startY start y position of jumping
	 * @param endX end x position of jumping
	 * @param endY end y position of jumping
	 * @param height height of jumping
	 * @param jumps times of jumping
	 * @return \link JumpTo JumpTo\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param startX 起始点x轴坐标
	 * @param startY 起始点y轴坐标
	 * @param endX 结束点y轴坐标
	 * @param endY 结束点y轴坐标
	 * @param height 节点跳跃的高度
	 * @param jumps 节点跳跃的次数
	 * @return \link JumpTo JumpTo\endlink
	 * \endif
	 */
    public static JumpTo make(float duration, float startX, float startY, float endX, float endY, float height, int jumps) {
        return new JumpTo(duration, startX, startY, endX, endY, height, jumps);
    }
  
    protected JumpTo(float duration, float startX, float startY, float endX, float endY, float height, int jumps) {
    	nativeInit(duration, startX, startY, endX, endY, height, jumps);
    }
    
    /**
     * 从底层指针获得一个JumpTo的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link JumpTo}
     */
    public static JumpTo from(int pointer) {
    	return pointer == 0 ? null : new JumpTo(pointer);
    }
    
    protected JumpTo(int pointer) {
    	super(pointer);
	}

	private native void nativeInit(float duration, float startX, float startY, float endX, float endY, float height, int jumps);

    @Override
    public IntervalAction copy() {
        return new JumpTo(nativeCopy());
    }
    
    @Override
    public IntervalAction reverse() {
    	return new JumpTo(nativeReverse());
    }
}
