package com.wiyun.engine.chipmunk;


/**
 * 弯曲弹簧 
 */
public class DampedRotarySpring extends Constraint {
	/**
	 * 自定义的力矩更新器 
	 */
	public static interface ITorqueUpdater {
		/**
		 * 更新力矩
		 * 
		 * @param springPointer DampedRotarySpring底层结构指针
		 * @param relativeAngle 相对角度
		 * @return 计算出的力矩
		 */
		public float updateTorque(int springPointer, float relativeAngle);
	}
	
	public static DampedRotarySpring make(Body b1, Body b2, float restAngle, float stiffness, float damping) {
		return new DampedRotarySpring(b1, b2, restAngle, stiffness, damping);
	}
	
	public static DampedRotarySpring from(int pointer) {
		return pointer == 0 ? null : new DampedRotarySpring(pointer);
	}
	
	protected DampedRotarySpring(int pointer) {
		super(pointer);
	}
	
	protected DampedRotarySpring(Body b1, Body b2, float restAngle, float stiffness, float damping) {
		init(b1, b2, restAngle, stiffness, damping);
	}

	private native void init(Body b1, Body b2, float restAngle, float stiffness, float damping);
	
	/**
	 * 设置力矩更新器
	 * 
	 * @param updater {@link ITorqueUpdater}, 为null时表示取消力矩更新器
	 */
	public native void setTorqueUpdater(ITorqueUpdater updater);
	
	/**
	 * 获得无外力时的角度
	 * 
	 * @return 无外力时的角度
	 */
	public native float getRestAngle();
	
	/**
	 * 设置无外力时的角度
	 * 
	 * @param a 无外力时的角度
	 */
	public native void setRestAngle(float a);
	
	/**
	 * 获得刚度
	 * 
	 * @return 刚度
	 */
	public native float getStiffness();
	
	/**
	 * 设置刚度
	 * 
	 * @param stiffness 刚度
	 */
	public native void setStiffness(float stiffness);
	
	/**
	 * 获得阻尼
	 * 
	 * @return 阻尼
	 */
	public native float getDamping();
	
	/**
	 * 设置阻尼
	 * 
	 * @param damping 阻尼
	 */
	public native void setDamping(float damping);
}
