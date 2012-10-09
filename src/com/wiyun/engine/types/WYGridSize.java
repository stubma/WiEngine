package com.wiyun.engine.types;

/**
 * 二维网格尺寸。每个格子叫做Tile.
 */
public class WYGridSize {
	/**
	 * 横向有多少格
	 */
	public int x;
	
	/**
	 * 纵向有多少格 
	 */
	public int y;
	
	/**
	 * 创建网格尺寸对象，初始化成0行0列
	 * 
	 * @return {@link WYGridSize}实例
	 */
	public static WYGridSize makeZero() {
		return new WYGridSize(0, 0);
	}

	/**
	 * 创建网格尺寸对象
	 * 
	 * @param x 横向格子数
	 * @param y 纵向格子数
	 * @return {@link WYGridSize}实例
	 */
	public static WYGridSize make(final int x, final int y) {
		return new WYGridSize(x, y);
	}

	/**
	 * 构造函数
	 * 
	 * @param x 横向格子数
	 * @param y 纵向格子数
	 */
	protected WYGridSize(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	/**
	 * 重用当前实例，修改横向和纵向格子数
	 * 
	 * @param x 新的横向格子数
	 * @param y 新的纵向格子数
	 */
	public void reuse(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	@Override
    public String toString() {
        return "<" + x + ", " + y + ">";
    }
}
