package com.wiyun.engine.chipmunk;

import com.wiyun.engine.types.WYPoint;

/**
 * 碰撞仲裁者。负责监测两个物体的碰撞，计算接触点等信息。 
 */
public class Arbiter {
	// underlying cpArbiter struct pointer
	int mPointer;
	
	public static Arbiter from(int pointer) {
		return pointer == 0 ? null : new Arbiter(pointer);
	}
	
	/**
	 * 构造函数
	 */
	protected Arbiter() {
	}
	
	protected Arbiter(int pointer) {
		mPointer = pointer;
	}
	
	public void setPointer(int pointer) {
		mPointer = pointer;
	}
	
	@Override
	public boolean equals(Object o) {
		if(o instanceof Arbiter)
			return ((Arbiter)o).mPointer == mPointer;
		else
			return false;
	}
	
	@Override
	public int hashCode() {
		return mPointer;
	}
	
	/**
	 * 得到发生碰撞的两个物体中的A物体。所谓A物体只是在注册碰撞处理器时，
	 * 碰撞类型等于collisionType1参数的物体
	 * 
	 * @return A物体
	 */
	public Shape getShapeA() {
		int pointer = nativeGetShapeA();
		return Shape.from(pointer);
	}
	
	/**
	 * 得到发生碰撞的两个物体中的B物体。所谓A物体只是在注册碰撞处理器时，
	 * 碰撞类型等于collisionType2参数的物体
	 * 
	 * @return B物体
	 */
	public Shape getShapeB() {
		int pointer = nativeGetShapeB();
		return Shape.from(pointer);
	}
	
	/**
	 * 得到某个接触点的法线
	 * 
	 * @param contactIndex 接触点的索引
	 * @return 法线矢量
	 */
	public WYPoint getNormal(int contactIndex) {
		return WYPoint.make(getNormalX(contactIndex), getNormalY(contactIndex));
	}
	
	/**
	 * 得到某个接触点的坐标
	 * 
	 * @param contactIndex 接触点的索引
	 * @return {@link WYPoint}
	 */
	public WYPoint getContactPoint(int contactIndex) {
		return WYPoint.make(getContactPointX(contactIndex), getContactPointY(contactIndex));
	}
	
	/**
	 * 得到某个接触点的坐标
	 * 
	 * @param contactIndex 接触点的索引
	 */
	private native float getContactPointX(int contactIndex);
	private native float getContactPointY(int contactIndex);
	
	/**
	 * 检查是否两个物体是第一次碰撞
	 * 
	 * @return true表示这是两个物体的第一次相撞
	 */
	public native boolean isFirstContact();
	
	/**
	 * 获得撞击的冲力大小
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getTotalImpulse() {
		return WYPoint.make(getTotalImpulseX(), getTotalImpulseY());
	}
	
	/**
	 * 获得撞击的冲力大小
	 */
	private native float getTotalImpulseX();
	private native float getTotalImpulseY();
	
	/**
	 * 考虑摩擦前提下，获得撞击的冲力大小
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getTotalImpulseWithFriction() {
		return WYPoint.make(getTotalImpulseWithFrictionX(), getTotalImpulseWithFrictionY());
	}
	
	/**
	 * 考虑摩擦前提下，获得撞击的冲力大小
	 */
	private native float getTotalImpulseWithFrictionX();
	private native float getTotalImpulseWithFrictionY();
	
	/**
	 * 获得撞击点的个数
	 * 
	 * @return 撞击点的个数
	 */
	public native int getContactPointCount();
	
	/**
	 * 得到某个接触点的法线， 它会调用savePoint()保存结果
	 * 
	 * @param contactIndex 接触点的索引
	 */
	private native float getNormalX(int contactIndex);
	private native float getNormalY(int contactIndex);
	
	/**
	 * 得到发生碰撞的两个物体中的A物体。所谓A物体只是在注册碰撞处理器时，
	 * 碰撞类型等于collisionType1参数的物体
	 * 
	 * @return A物体的底层结构指针
	 */
	private native int nativeGetShapeA();
	
	/**
	 * 得到发生碰撞的两个物体中的B物体。所谓A物体只是在注册碰撞处理器时，
	 * 碰撞类型等于collisionType2参数的物体
	 * 
	 * @return B物体的底层结构指针
	 */
	private native int nativeGetShapeB();
	
	/**
	 * 得到arbiter的时间戳
	 * 
	 * @return 时间戳
	 */
	public native int getTimeStamp();
}
