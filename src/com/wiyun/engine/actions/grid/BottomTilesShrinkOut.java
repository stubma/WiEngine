package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 把屏幕分成网格，从底部开始收缩每行的网格。
 */
public class BottomTilesShrinkOut extends TiledGrid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格行列个数
	 * @return 动作实例
	 */
	public static BottomTilesShrinkOut make(float duration, WYGridSize gSize) {
		return new BottomTilesShrinkOut(duration, gSize);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格行列个数
	 */
	protected BottomTilesShrinkOut(float duration, WYGridSize gSize) {
		nativeInit(duration, gSize.x, gSize.y);
	}
	
    /**
     * 从底层指针获得一个BottomTilesShrinkOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link BottomTilesShrinkOut}
     */
    public static BottomTilesShrinkOut from(int pointer) {
    	return pointer == 0 ? null : new BottomTilesShrinkOut(pointer);
    }
	
	protected BottomTilesShrinkOut(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY);
	
	@Override
	public TiledGrid3DAction copy() {
		return new BottomTilesShrinkOut(nativeCopy());
	}
}
