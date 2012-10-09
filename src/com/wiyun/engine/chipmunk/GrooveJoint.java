package com.wiyun.engine.chipmunk;

import com.wiyun.engine.types.WYPoint;

/**
 * 槽式接合 
 */
public class GrooveJoint extends Constraint {
	public static GrooveJoint make(Body b1, Body b2, WYPoint grooveA, WYPoint grooveB, WYPoint anchor) {
		return new GrooveJoint(b1, b2, grooveA.x, grooveA.y, grooveB.x, grooveB.y, anchor.x, anchor.y);
	}
	
	protected GrooveJoint(Body b1, Body b2, float grooveAX, float grooveAY, float grooveBX, float grooveBY, float anchorX, float anchorY) {
		init(b1, b2, grooveAX, grooveAY, grooveBX, grooveBY, anchorX, anchorY);
	}

	private native void init(Body b1, Body b2, float grooveAX, float grooveAY, float grooveBX, float grooveBY, float anchorX, float anchorY);
	
	public static GrooveJoint from(int pointer) {
		return pointer == 0 ? null : new GrooveJoint(pointer);
	}
	
	protected GrooveJoint(int pointer) {
		super(pointer);
	}
	
	/**
	 * 得到锚点2的x位置
	 * 
	 * @return 锚点2的x位置
	 */
	public native float getAnchor2X();
	
	/**
	 * 得到锚点2的y位置
	 * 
	 * @return 锚点2的y位置
	 */
	public native float getAnchor2Y();
	
	/**
	 * 得到锚点2
	 * 
	 * @return 锚点2
	 */
	public WYPoint getAnchor2() {
		return WYPoint.make(getAnchor2X(), getAnchor2Y());
	}
	
	/**
	 * 设置锚点2
	 * 
	 * @param p {@link WYPoint}
	 */
	public void setAnchor2(WYPoint p) {
		setAnchor2(p.x, p.y);
	}
	
	/**
	 * 设置锚点2
	 * 
	 * @param x 锚点2的x位置
	 * @param y 锚点2的y位置
	 */
	public native void setAnchor2(float x, float y);
}
