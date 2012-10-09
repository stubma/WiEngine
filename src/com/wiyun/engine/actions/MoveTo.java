package com.wiyun.engine.actions;

import com.wiyun.engine.types.WYPoint;


/**
 * \if English
 * Move a node from a place to other place. You should set start and end position
 * for node.
 * \else
 * 节点移动的动作封装,根据设置起始点，结束点进行移动
 * \endif
 */
public class MoveTo extends IntervalAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time of this action, in second
	 * @param startX start x position
	 * @param startY start y position
	 * @param endX end x position
	 * @param endY end y position
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param startX 起始点x轴坐标
	 * @param startY 起始点y轴坐标
	 * @param endX 结束点y轴坐标
	 * @param endY 结束点y轴坐标
	 * \endif
	 */
    public static MoveTo make(float duration, float startX, float startY, float endX, float endY) {
        return new MoveTo(duration, startX, startY, endX, endY);
    }
    
    protected MoveTo(float duration, float startX, float startY, float endX, float endY) {
    	nativeInit(duration, startX, startY, endX, endY);
    }
    
    public static MoveTo from(int pointer) {
    	return pointer == 0 ? null : new MoveTo(pointer);
    }
    
    protected MoveTo(int pointer) {
    	super(pointer);
	}

	private native void nativeInit(float duration, float startX, float startY, float endX, float endY);
    
    @Override
    public IntervalAction copy() {
        return new MoveTo(nativeCopy());
    }
    
    @Override
    public IntervalAction reverse() {
    	return new MoveTo(nativeReverse());
    }
    
	/**
	 * \if English
	 * set pin point
	 *
	 * @param p global coordinate of pin point
	 * \else
	 * 设置pin point
	 *
	 * @param p pin point的全局坐标
	 * \endif
	 */
	public void setPinPoint(WYPoint p) {
		setPinPoint(p.x, p.y);
	}

	/**
	 * \if English
	 * set pin point
	 *
	 * @param x global x location of pin point
	 * @param y global y location of pin point
	 * \else
	 * 设置pin point
	 *
	 * @param x pin point的全局x位置
	 * @param y pin point的全局y位置
	 * \endif
	 */
	public native void setPinPoint(float x, float y);

	/**
	 * \if English
	 * get pin point
	 *
	 * @return global coordinate of pin point
	 * \else
	 * 得到pin point
	 *
	 * @return pin point的全局坐标
	 * \endif
	 */
	public WYPoint getPinPoint() {
		WYPoint p = WYPoint.makeZero();
		nativeGetPinPoint(p);
		return p;
	}
	
	private native void nativeGetPinPoint(WYPoint p);

	/**
	 * \if English
	 * clear pin point
	 * \else
	 * 清除掉pin point, 这样节点移动时将不再自动对准pin point
	 * \endif
	 */
	public native void clearPinPoint();

	/**
	 * \if English
	 * set angle delta of pin point rotation
	 *
	 * @param angle to be added to node rotation
	 * \else
	 * 设置附加角度, 仅当pin point被设置时有效
	 *
	 * @param delta 附加角度
	 * \endif
	 */
	public native void setPinAngleDelta(float delta);

	/**
	 * \if English
	 * get angle delta
	 *
	 * @return angle delta
	 * \else
	 * 得到附加角度
	 *
	 * @return 附加角度
	 * \endif
	 */
	public native float getPinAngleDelta();
}
