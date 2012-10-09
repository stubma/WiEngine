package com.wiyun.engine.actions;

import com.wiyun.engine.types.WYHypotrochoidConfig;
import com.wiyun.engine.types.WYPoint;

/**
 * \if English
 * A hypotrochoid is a roulette traced by a point attached to a circle of
 * radius r rolling around the inside of a fixed circle of radius R,
 * where the point is a distance d from the center of the interior circle.
 * Special cases include the hypocycloid with d = r and the ellipse with R = 2r.
 * http://en.wikipedia.org/wiki/Hypotrochoid
 * \else
 * 内旋轮线(hypotrochoid)是追踪附着在围绕半径为 R 的固定的圆内侧滚转的半径为 r 的圆上的一个点得到的转迹线,
 * 这个点到内部滚动的圆的中心的距离是 d.
 * 特殊情况包括 d = r 的内摆线和 R = 2r 的椭圆。
 * http://en.wikipedia.org/wiki/Hypotrochoid
 * \endif
 */
public class Hypotrochoid extends IntervalAction {
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param duration duration time of action
	 * @param c \link WYHypotrochoidConfig WYHypotrochoidConfig\endlink
	 * @return \link Hypotrochoid Hypotrochoid\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param c \link WYHypotrochoidConfig WYHypotrochoidConfig\endlink
	 * @return \link Hypotrochoid Hypotrochoid\endlink
	 * \endif
	 */
	public static Hypotrochoid make(float duration, WYHypotrochoidConfig c) {
		return new Hypotrochoid(duration, c);
	}

	protected Hypotrochoid(float duration, WYHypotrochoidConfig config) {
		nativeInit(duration, config);
	}
	
    public static Hypotrochoid from(int pointer) {
    	return pointer == 0 ? null : new Hypotrochoid(pointer);
    }
    
	protected Hypotrochoid(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(float duration, WYHypotrochoidConfig config);
	
	@Override
	public IntervalAction copy() {
		return new Hypotrochoid(nativeCopy());
	}

	@Override
	public IntervalAction reverse() {
		return null;
	}

	/**
	 * \if English
	 * Enable auto rotate, it means the node move by bezier path will be aligned
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
