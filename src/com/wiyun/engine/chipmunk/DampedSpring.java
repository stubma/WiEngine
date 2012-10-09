package com.wiyun.engine.chipmunk;
import com.wiyun.engine.types.WYPoint;


/**
 * 弹簧连接 
 */
public class DampedSpring extends Constraint {
	/**
	 * 自定义的弹簧力量更新器 
	 */
	public static interface IForceUpdater {
		/**
		 * 更新弹簧力量
		 * 
		 * @param springPointer DampedSpring底层结构指针
		 * @param distance 物体的距离
		 * @return 计算出的力量
		 */
		public float updateForce(int springPointer, float distance);
	}
	
	public static DampedSpring make(Body b1, Body b2, WYPoint anchor1, WYPoint anchor2, float restLength, float stiffness, float damping) {
		return new DampedSpring(b1, b2, anchor1.x, anchor1.y, anchor2.x, anchor2.y, restLength, stiffness, damping);
	}
	
	public static DampedSpring from(int pointer) {
		return pointer == 0 ? null : new DampedSpring(pointer);
	}
	
	protected DampedSpring(int pointer) {
		super(pointer);
	}
	
	protected DampedSpring(Body b1, Body b2, float anchor1X, float anchor1Y, float anchor2X, float anchor2Y, float restLength, float stiffness, float damping) {
		init(b1, b2, anchor1X, anchor1Y, anchor2X, anchor2Y, restLength, stiffness, damping);
	}

	private native void init(Body b1, Body b2, float anchor1X, float anchor1Y, float anchor2X, float anchor2Y, float restLength, float stiffness, float damping);
	
	/**
	 * 设置力量更新器
	 * 
	 * @param updater {@link IForceUpdater}, 为null表示取消力量更新器
	 */
	public native void setForceUpdater(IForceUpdater updater);
	
	/**
	 * 得到弹簧的自然长度
	 * 
	 * @return 无作用力时的弹簧长度
	 */
	public native float getRestLength();
	
	/**
	 * 得到弹簧的刚度系数
	 * 
	 * @return 刚度系数
	 */
	public native float getStiffness();
	
	/**
	 * 得到弹簧的衰减系数
	 * 
	 * @return 衰减系数
	 */
	public native float getDamping();
	
	/**
	 * 设置自然长度
	 * 
	 * @param len 自然长度
	 */
	public native void setRestLength(float len);
	
	/**
	 * 设置刚度
	 * 
	 * @param stiffness 刚度
	 */
	public native void setStiffness(float stiffness);
	
	/**
	 * 设置阻尼
	 * 
	 * @param damping 阻尼
	 */
	public native void setDamping(float damping);
	
	/**
	 * 得到锚点1的x位置
	 * 
	 * @return 锚点1的x位置
	 */
	public native float getAnchor1X();
	
	/**
	 * 得到锚点1的y位置
	 * 
	 * @return 锚点1的y位置
	 */
	public native float getAnchor1Y();
	
	/**
	 * 得到锚点1
	 * 
	 * @return 锚点1
	 */
	public WYPoint getAnchor1() {
		return WYPoint.make(getAnchor1X(), getAnchor1Y());
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
	 * 设置锚点1
	 * 
	 * @param p {@link WYPoint}
	 */
	public void setAnchor1(WYPoint p) {
		setAnchor1(p.x, p.y);
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
	 * 设置锚点1
	 * 
	 * @param x 锚点1的x位置
	 * @param y 锚点1的y位置
	 */
	public native void setAnchor1(float x, float y);
	
	/**
	 * 设置锚点2
	 * 
	 * @param x 锚点2的x位置
	 * @param y 锚点2的y位置
	 */
	public native void setAnchor2(float x, float y);
}
