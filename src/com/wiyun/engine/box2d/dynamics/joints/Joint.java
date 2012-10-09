package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.types.WYPoint;

public class Joint extends BaseObject {
	// limit state for rope joint
	public static final int LIMIT_STATE_INACTIVE = 0;
	public static final int LIMIT_STATE_AT_LOWER = 1;
	public static final int LIMIT_STATE_AT_UPPER = 2;
	public static final int LIMIT_STATE_EQUAL = 3;
	
	public static Joint from(int pointer) {
		return pointer == 0 ? null : new Joint(pointer);
	}
	
	protected Joint() {
	}

	protected Joint(int pointer) {
		super(pointer);
	}
	
	/**
	 * 获得连接点的刚体A
	 * 
	 * @return {@link Body}
	 */
	public Body getBodyA() {
		return Body.from(nativeGetBodyA());
	}
	
	private native int nativeGetBodyA();
	
	/**
	 * 获得连接点的刚体B
	 * 
	 * @return {@link Body}
	 */
	public Body getBodyB() {
		return Body.from(nativeGetBodyB());
	}
	
	private native int nativeGetBodyB();
	
	/**
	 * 获得锚点a, 坐标为box2d的全局坐标
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getAnchorA() {
		WYPoint a = WYPoint.makeZero();
		nativeGetAnchorA(a);
		return a;
	}
	
	private native void nativeGetAnchorA(WYPoint a);
	
	/**
	 * 获得锚点b, 坐标为box2d的全局坐标
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getAnchorB() {
		WYPoint a = WYPoint.makeZero();
		nativeGetAnchorB(a);
		return a;
	}
	
	private native void nativeGetAnchorB(WYPoint a);
	
	
	/**
	 * Get the reaction force given the inverse time step.
	 * Unit is N.
	 */
	public WYPoint getReactionForce(float inv_dt) {
		WYPoint a = WYPoint.makeZero();
		nativeGetReactionForce(a, inv_dt);
		return a;
	}
	
	private native void nativeGetReactionForce(WYPoint p, float inv_dt);

	/**
	 * Get the reaction torque given the inverse time step.
	 * Unit is N*m. This is always zero for a distance joint.
	 */
	public native float getReactionTorque(float inv_dt);
	
	/**
	 * 得到用户自定义数据对象
	 * 
	 * @return {@link Object}
	 */
	public native Object getUserData();
	
	/**
	 * 设置用户自定义数据对象
	 * 
	 * @param obj {@link Object}
	 */
	public native void setUserData(Object obj);
}
