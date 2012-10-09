package com.wiyun.engine.types;


/**
 * 用来表示坐标的类, 和{@link WYPoint}的区别是成员是整数类型.
 */
public class WYDimension {
	public int x, y;
	
	/**
	 * 生成一个全0的WYDimension
	 * 
	 * @return {@link WYDimension}
	 */
	public static WYDimension makeZero() {
		return new WYDimension(0, 0);
	}
	
	/**
	 * 生成一个WYDimension数组
	 * 
	 * @param size 数组大小
	 * @return {@link WYDimension}数组
	 */
	public static WYDimension[] makeArray(int size) {
		WYDimension[] p = new WYDimension[size];
		for(int i = 0; i < size; i++)
			p[i] = makeZero();
		return p;
	}
	
	protected WYDimension() {
		this(0, 0);
	}

	protected WYDimension(int x, int y) {
		this.x = x;
		this.y = y;
	}

	@Override
	public String toString() {
		return "(" + x + ", " + y + ")";
	}

	public static boolean isEqual(WYDimension p1, WYDimension p2) {
		return p1.x == p2.x && p1.y == p2.y;
	}

	/**
	 * Helper macro that creates a WYPoint
	 *
	 * @return WYPoint
	 */
	public static WYDimension make(int x, int y) {
		return new WYDimension(x, y);
	}
}
