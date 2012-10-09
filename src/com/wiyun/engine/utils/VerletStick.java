package com.wiyun.engine.utils;

import com.wiyun.engine.BaseWYObject;

/**
 * \if English
 * Segment of between two \link VerletPoint VerletPoint\endlink
 * \else
 * 封装两个\link VerletPoint VerletPoint\endlink, 代表了链接这两个点
 * 的一个线段
 * \endif
 */
public class VerletStick extends BaseWYObject {
	public static VerletStick make(VerletPoint a, VerletPoint b) {
		return new VerletStick(a, b);
	}
	
	public static VerletStick from(int pointer) {
		return pointer == 0 ? null : new VerletStick(pointer);
	}
	
	protected VerletStick(VerletPoint a, VerletPoint b) {
		nativeInit(a, b);
	}
	
	protected VerletStick(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(VerletPoint a, VerletPoint b);
	
	/**
	 * \if English
	 * Contract this segment to approach original length. It is not done
	 * immediately but repeatly.
	 *
	 * @param reverse true means treat a point as b, treat b as a
	 * \else
	 * 收缩线段，使得两点距离逐渐回复到原始距离。这个收缩过程不是一下子
	 * 完成的，这使得绳子看起来有一定的弹性。
	 *
	 * @param reverse true表示把a点当成b点, b点当成a点
	 * \endif
	 */
	public native void contract(boolean reverse);

	/**
	 * \if English
	 * Get point a
	 *
	 * @return \link VerletPoint VerletPoint\endlink
	 * \else
	 * 得到点A
	 *
	 * @return \link VerletPoint VerletPoint\endlink
	 * \endif
	 */
	public VerletPoint getPointA() {
		return VerletPoint.from(nativeGetPointA());
	}
	
	private native int nativeGetPointA();

	/**
	 * \if English
	 * Get point b
	 *
	 * @return \link VerletPoint VerletPoint\endlink
	 * \else
	 * 得到点b
	 *
	 * @return \link VerletPoint VerletPoint\endlink
	 * \endif
	 */
	public VerletPoint getPointB() {
		return VerletPoint.from(nativeGetPointB());
	}
	
	private native int nativeGetPointB();

	/**
	 * \if English
	 * Get original length
	 *
	 * @return original length
	 * \else
	 * 得到原始长度
	 *
	 * @return 原始长度
	 * \endif
	 */
	public native float getLength();

	/**
	 * \if English
	 * Get current length
	 *
	 * @return current length
	 * \else
	 * 得到当前长度
	 *
	 * @return 当前长度
	 * \endif
	 */
	public native float getCurrentLength();
}
