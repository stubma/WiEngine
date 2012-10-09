package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.box2d.dynamics.Body;

public abstract class JointDef extends BaseObject {
	public static final int TYPE_UNKNOWN = 0;
	public static final int TYPE_REVOLUTE = 1;
	public static final int TYPE_PRISMATIC = 2;
	public static final int TYPE_DISTANCE = 3;
	public static final int TYPE_PULLEY = 4;
	public static final int TYPE_MOUSE = 5;
	public static final int TYPE_GEAR = 6;
	public static final int TYPE_LINE = 7;
	public static final int TYPE_WELD = 8;
	public static final int TYPE_FRICTION = 9;
	public static final int TYPE_ROPE = 10;
	
	protected JointDef() {
	}

	protected JointDef(int pointer) {
		super(pointer);
	}
	
	/**
	 * 获得连接点类型
	 * 
	 * @return 连接点类型
	 */
	public native int getType();
	
	/**
	 * 设置刚体a
	 * 
	 * @param b {@link Body}
	 */
	public native void setBodyA(Body b);
	
	/**
	 * 设置刚体b
	 * 
	 * @param b {@link Body}
	 */
	public native void setBodyB(Body b);
	
	/**
	 * 设置true表示被Joint连接的两个刚体可以产生碰撞
	 * 
	 * @param flag true表示被Joint连接的两个刚体可以产生碰撞
	 */
	public native void setCollideConnected(boolean flag);
	
	/**
	 * 两个刚体是否可以产生碰撞
	 * 
	 * @return true表示两个刚体可以产生碰撞
	 */
	public native boolean isCollideConnected();
	
	/**
	 * 销毁连结点定义对象
	 */
	public native void destroy();
	
	/**
	 * 获得刚体a
	 * 
	 * @return {@link Body}
	 */
	public Body getBodyA() {
		return Body.from(nativeGetBodyA());
	}
	
	private native int nativeGetBodyA();
	
	/**
	 * 获得刚体B
	 * 
	 * @return {@link Body}
	 */
	public Body getBodyB() {
		return Body.from(nativeGetBodyB());
	}
	
	private native int nativeGetBodyB();
}
