package com.wiyun.engine.actions;


/**
 * \if English
 * Accelerate or deaccelerate an action
 * \else
 * 加减速动作。相当于快镜头慢镜头，可以指定一个速度因子，比如2，则目标动作将会加快2倍。
 * \endif
 */
public class Speed extends Action {
	protected Action mOther;
	protected float mSpeed;

	/**
	 * \if English
	 * get coefficient of speed
	 *
	 * @return coefficient of speed
	 * \else
	 * 获得加速或减速的速率
	 *
	 * @return 加速或减速的速率
	 * \endif
	 */
	public native float getSpeed();

	/**
	 * \if English
	 * set coefficient of speed
	 *
	 * @param speed Coefficient of speed, if larger than 1 then it means acceleration.
	 * 		Can't set a negative value
	 * \else
	 * 设置加速或减速的速率
	 *
	 * @param speed 加速或减速的速率，大于1为加速
	 * \endif
	 */
	public native void setSpeed(float speed);

	/**
	 * \if English
	 * static factory method
	 *
	 * @param action the \link Action Action\endlink need to be speed up or down
	 * @param speed the coefficient of speed up or down
	 * \else
	 * 静态构造函数
	 *
	 * @param action 具体执行的 \link Action Action\endlink对象指针
	 * @param speed 加速或减速的速率，大于1为加速，取值必须大于0
	 * \endif
	 */
	public static Speed make(Action action, float speed) {
		return new Speed(action, speed);
	}

	/**
	 * 构造函数
	 * 
	 * @param action 要加速或者减速的动作
	 * @param speed 速度因子
	 */
	protected Speed(Action action, float speed) {
		nativeInit(action, speed);
	}

	public static Speed from(int pointer) {
    	return pointer == 0 ? null : new Speed(pointer);
    }
	
	protected Speed(int pointer) {
		super(pointer);
	}

	private native void nativeInit(Action action, float speed);

	@Override
	public Speed copy() {
		return new Speed(nativeCopy());
	}
	
	@Override
	public Action reverse() {
		return new Speed(nativeReverse());
	}
}
