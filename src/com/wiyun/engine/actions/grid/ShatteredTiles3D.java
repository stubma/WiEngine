package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 网格混乱效果。它和抖动效果起始本质上相同，只不过它只做一次，所以它没有动画效果。
 */
public class ShatteredTiles3D extends TiledGrid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param range 网格混乱程度
	 * @param shatterZ 是否在z轴方向上混淆
	 * @return 动作实例
	 */
	public static ShatteredTiles3D make(float duration, WYGridSize gridSize, int range, boolean shatterZ) {
		return new ShatteredTiles3D(duration, gridSize, range, shatterZ);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param range 网格混乱程度
	 * @param shatterZ 是否在z轴方向上混淆
	 */
	protected ShatteredTiles3D(float duration, WYGridSize gridSize, int range, boolean shatterZ) {
		nativeInit(duration, gridSize.x, gridSize.y, range, shatterZ);
	}
	
    /**
     * 从底层指针获得一个ShatteredTiles3D的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ShatteredTiles3D}
     */
    public static ShatteredTiles3D from(int pointer) {
    	return pointer == 0 ? null : new ShatteredTiles3D(pointer);
    }
	
	protected ShatteredTiles3D(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY, int range, boolean shatterZ);

	@Override
	public TiledGrid3DAction copy() {
		return new ShatteredTiles3D(nativeCopy());
	}
}
