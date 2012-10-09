package com.wiyun.engine.astar;

/**
 * A*六边形地图状况tile封装
 */
public class HexagonAStarMap extends AStarMap {
	/**
	 * 构造函数
	 *
	 * @param width 横向tile数量
	 * @param height 纵向tile数量
	 */
	public static HexagonAStarMap make(int width, int height) {
		return new HexagonAStarMap(width, height);
	}
	
	protected HexagonAStarMap(int width, int height) {
		doNativeInit(width, height);
	}

	public static RectAStarMap from(int pointer) {
		return pointer == 0 ? null : new RectAStarMap(pointer);
	}

	protected HexagonAStarMap(int pointer) {
		super(pointer);
	}

	protected void doNativeInit(int width, int height) {
		nativeInit(width, height);
	}

	private native void nativeInit(int width, int height);

}
