package com.wiyun.engine.astar;

/**
 * A*矩形地图状况tile封装
 */
public class RectAStarMap extends AStarMap {
	/**
	 * 构造函数
	 *
	 * @param width 横向tile数量
	 * @param height 纵向tile数量
	 * @param isAllowDiagonal 是否允许斜线查找, true为允许
	 */
	public static RectAStarMap make(int width, int height, boolean isAllowDiagonal) {
		return new RectAStarMap(width, height, isAllowDiagonal);
	}
	
	protected RectAStarMap(int width, int height, boolean isAllowDiagonal) {
		doNativeInit(width, height, isAllowDiagonal);
	}

	public static RectAStarMap from(int pointer) {
		return pointer == 0 ? null : new RectAStarMap(pointer);
	}

	protected RectAStarMap(int pointer) {
		super(pointer);
	}

	protected void doNativeInit(int width, int height, boolean isAllowDiagonal) {
		nativeInit(width, height, isAllowDiagonal);
	}

	private native void nativeInit(int width, int height,
			boolean isAllowDiagonal);
	
}
