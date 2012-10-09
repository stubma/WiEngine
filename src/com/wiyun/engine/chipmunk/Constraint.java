package com.wiyun.engine.chipmunk;


/**
 * 物体之间的关联，基类 
 */
public class Constraint {
	// underlying struct pointer
	int mPointer;
	
	/**
	 * 从底层指针生成java对象
	 * 
	 * @param pointer 底层java对象
	 * @return {@link Constraint}
	 */
	public static Constraint from(int pointer) {
		return pointer == 0 ? null : new Constraint(pointer);
	}
	
	public Constraint() {
	}
	
	protected Constraint(int pointer) {
		mPointer = pointer;
	}
	
	public void setPointer(int pointer) {
		mPointer = pointer;
	}
	
	@Override
	public boolean equals(Object o) {
		if(o instanceof Constraint)
			return ((Constraint)o).mPointer == mPointer;
		else
			return false;
	}
	
	@Override
	public int hashCode() {
		return mPointer;
	}
	
	/**
	 * 销毁底层资源
	 */
	public native void destroy();
	
	/**
	 * 设置连接点能承受的最大力量
	 * 
	 * @param maxForce 连接点能承受的最大力量
	 */
	public native void setMaxForce(float maxForce);
	
	/**
	 * 得到连接点能承受的最大力量
	 * 
	 * @return 连接点能承受的最大力量
	 */
	public native float getMaxForce();
	
	/**
	 * 设置偏差系数
	 * 
	 * @param bias 偏差系数
	 */
	public native void setBias(float bias);
	
	/**
	 * 得到偏差系数
	 * 
	 * @return 偏差系数
	 */
	public native float getBias();
	
	/**
	 * 设置最大偏差系数
	 * 
	 * @param max 最大偏差系数
	 */
	public native void setMaxBias(float max);
	
	/**
	 * 得到最大偏差系数
	 * 
	 * @return 最大偏差系数
	 */
	public native float getMaxBias();
}
