package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 把屏幕划分为网格，从左下角开始，收缩每个tile。 
 */
public class LeftBottomTilesShrinkOut extends TiledGrid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格尺寸
	 * @return 动作实例
	 */
	public static LeftBottomTilesShrinkOut make(float duration, WYGridSize gSize) {
		return new LeftBottomTilesShrinkOut(duration, gSize);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格尺寸
	 */
	protected LeftBottomTilesShrinkOut(float duration, WYGridSize gSize) {
		nativeInit(duration, gSize.x, gSize.y);
	}
	
    /**
     * 从底层指针获得一个LeftBottomTilesShrinkOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link LeftBottomTilesShrinkOut}
     */
    public static LeftBottomTilesShrinkOut from(int pointer) {
    	return pointer == 0 ? null : new LeftBottomTilesShrinkOut(pointer);
    }
	
	protected LeftBottomTilesShrinkOut(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY);
	
	@Override
	public TiledGrid3DAction copy() {
		return new LeftBottomTilesShrinkOut(nativeCopy());
	}
}
