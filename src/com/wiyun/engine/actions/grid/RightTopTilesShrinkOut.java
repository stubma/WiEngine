package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 把屏幕分成网格，从右上部开始收缩网格。
 */
public class RightTopTilesShrinkOut extends TiledGrid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格尺寸
	 * @return 动作实例
	 */
	public static RightTopTilesShrinkOut make(float duration, WYGridSize gSize) {
		return new RightTopTilesShrinkOut(duration, gSize);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格尺寸
	 */
	protected RightTopTilesShrinkOut(float duration, WYGridSize gSize) {
		nativeInit(duration, gSize.x, gSize.y);
	}
	
    /**
     * 从底层指针获得一个RightTopTilesShrinkOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link RightTopTilesShrinkOut}
     */
    public static RightTopTilesShrinkOut from(int pointer) {
    	return pointer == 0 ? null : new RightTopTilesShrinkOut(pointer);
    }
	
	protected RightTopTilesShrinkOut(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY);
	
	@Override
	public TiledGrid3DAction copy() {
		return new RightTopTilesShrinkOut(nativeCopy());
	}
}
