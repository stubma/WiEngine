package com.wiyun.engine.actions;

import com.wiyun.engine.types.WYPoint;


/**
 * \if English
 * Move a node
 * \else
 * 节点移动的动作封装, 根据设置偏移量进行移动
 * \endif
 */
public class MoveBy extends IntervalAction {
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param duration duration time of action
	 * @param x offset in x axis
	 * @param y offset in y axis
	 * @return \link MoveBy MoveBy\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param x 节点偏移x轴距离
	 * @param y 节点偏移y轴距离
	 * @return \link MoveBy MoveBy\endlink
	 * \endif
	 */
    public static MoveBy make(float duration, float x, float y) {
        return new MoveBy(duration, x, y);
    }

    protected MoveBy(float duration, float x, float y) {
    	nativeInit(duration, x, y);
    }
    
    private native void nativeInit(float duration, float x, float y);

    public static MoveBy from(int pointer) {
    	return pointer == 0 ? null : new MoveBy(pointer);
    }
    
    protected MoveBy(int pointer) {
    	super(pointer);
	}

	@Override
    public IntervalAction copy() {
        return new MoveBy(nativeCopy());
    }

    @Override
    public IntervalAction reverse() {
        return new MoveBy(nativeReverse());
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
