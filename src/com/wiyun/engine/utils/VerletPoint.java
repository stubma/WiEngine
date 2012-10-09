package com.wiyun.engine.utils;

import com.wiyun.engine.BaseWYObject;

/**
 * \if English
 * A point in a verlet rope
 * \else
 * 封装绳子中的一点，这个点跟踪其之前的某个位置状态, 从而可以计算变化幅度
 * \endif
 */
public class VerletPoint extends BaseWYObject {
	public static VerletPoint make() {
		return new VerletPoint();
	}
	
	public static VerletPoint from(int pointer) {
		return pointer == 0 ? null : new VerletPoint(pointer);
	}
	
	protected VerletPoint() {
		nativeInit();
	}
	
	protected VerletPoint(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit();
	
	/**
	 * \if English
	 * Set position
	 *
	 * @param x x position
	 * @param y y position
	 * \else
	 * 设置位置
	 *
	 * @param x x位置
	 * @param y y位置
	 * \endif
	 */
	public native void setPosition(float x, float y);

	/**
	 * \if English
	 * Update point
	 * \else
	 * 让原始值变成当前值，当前值加上和原来原始值的差值
	 * \endif
	 */
	public native void update();

	/**
	 * \if English
	 * Apply gravity to this point
	 *
	 * @param dt delta time
	 * \else
	 * 应用重力
	 *
	 * @param dt delta时间
	 * \endif
	 */
	public native void applyGravity(float dt);

	/**
	 * \if English
	 * Set x position
	 *
	 * @param x x position
	 * \else
	 * 设置x位置
	 *
	 * @param x x位置
	 * \endif
	 */
	public native void setX(float x);

	/**
	 * \if English
	 * Set y position
	 *
	 * @param y y position
	 * \else
	 * 设置y位置
	 *
	 * @param y y位置
	 * \endif
	 */
	public native void setY(float y);

	/**
	 * \if English
	 * Get x position
	 *
	 * @return x position
	 * \else
	 * 得到x值
	 *
	 * @return x值
	 * \endif
	 */
	public native float getX();

	/**
	 * \if English
	 * Get y position
	 *
	 * @return y position
	 * \else
	 * 得到y值
	 *
	 * @return y值
	 * \endif
	 */
	public native float getY();

	/**
	 * \if English
	 * Attenuate waving
	 *
	 * @param percent percent to be reduced
	 * \else
	 * 衰减，用于控制振荡幅度
	 *
	 * @param percent 衰减幅度
	 * \endif
	 */
	public native void attenuate(float percent);

	/**
	 * \if English
	 * Clone this point object
	 *
	 * @return \link wyVerletPoint wyVerletPoint\endlink
	 * \else
	 * 复制一份verlet point对象，返回的对象已经被autorelease
	 *
	 * @return \link wyVerletPoint wyVerletPoint\endlink
	 * \endif
	 */
	public VerletPoint copy() {
		return VerletPoint.from(nativeCopy());
	}
	
	private native int nativeCopy();
}
