package com.wiyun.engine.actions;

import com.wiyun.engine.types.WYLagrangeConfig;
import com.wiyun.engine.types.WYPoint;

/**
 * \if English
 * Move a \link Node Node\endlink in track of Lagrange curve
 * \else
 * 节点按照拉格朗日曲线轨迹运动的动作封装
 * \endif
 */
public class Lagrange extends IntervalAction {
	/**
	 * \if English
	 * Static factory method
	 *
	 * @param duration duration time in second
	 * @param config \link WYLagrangeConfig WYLagrangeConfig\endlink structure to describe lagrange curve
	 * @return \link Lagrange Lagrange\endlink
	 * \else
	 * 静态构造方法
	 *
	 * @param duration 动作持续的时间
	 * @param config 拉格朗日曲线的描述结构, \link WYLagrangeConfig WYLagrangeConfig\endlink
	 * @return \link Lagrange Lagrange\endlink
	 * \endif
	 */
	public static Lagrange make(float duration, WYLagrangeConfig config) {
		return new Lagrange(duration, config);
	}

	protected Lagrange(float duration, WYLagrangeConfig config) {
		nativeInit(duration, config);
	}

    public static Lagrange from(int pointer) {
    	return pointer == 0 ? null : new Lagrange(pointer);
    }
    
	protected Lagrange(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(float duration, WYLagrangeConfig config);
	
	@Override
	public IntervalAction copy() {
		return new Lagrange(nativeCopy());
	}
	
	@Override
	public IntervalAction reverse() {
		return new Lagrange(nativeReverse());
	}
	
	/**
	 * \if English
	 * Enable auto rotate, it means the node move by lagrange path will be aligned
	 * with path direction.
	 *
	 * @param flag true means enable auto rotate
	 * @param angleDelta the delta to be added to path direction. Position value means
	 * 		clockwise, negative value means counter-clockwise
	 * \else
	 * 是否打开自动旋转，打开自动旋转表示移动的节点会自动保持和路径方向一致.
	 *
	 * @param flag true表示打开自动旋转
	 * @param angleDelta 预设的角度，假如是-90，而当前路径的朝向是180度，那么最终节点将被设置为90度.
	 * 		这里正值表示顺时针旋转，负值表示逆时针旋转
	 * \endif
	 */
	public native void setAutoRotate(boolean flag, float angleDelta);
	
	/**
	 * \if English
	 * set pin point, only available when auto rotate flag is false
	 *
	 * @param p global coordinate of pin point
	 * \else
	 * 设置pin point, pin point仅当auto rotate为false时才有效
	 *
	 * @param p pin point的全局坐标
	 * \endif
	 */
	public void setPinPoint(WYPoint p) {
		setPinPoint(p.x, p.y);
	}

	/**
	 * \if English
	 * set pin point, only available when auto rotate flag is false
	 *
	 * @param x global x location of pin point
	 * @param y global y location of pin point
	 * \else
	 * 设置pin point, pin point仅当auto rotate为false时才有效
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
