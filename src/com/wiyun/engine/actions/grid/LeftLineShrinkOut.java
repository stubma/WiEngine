package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 把屏幕分成若干列，从左边开始收缩每列。 
 */
public class LeftLineShrinkOut extends TiledGrid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格尺寸
	 * @return 动作实例
	 */
	public static LeftLineShrinkOut make(float duration, WYGridSize gSize) {
		return new LeftLineShrinkOut(duration, gSize);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格尺寸
	 */
	protected LeftLineShrinkOut(float duration, WYGridSize gSize) {
		nativeInit(duration, gSize.x, gSize.y);
	}
	
    /**
     * 从底层指针获得一个LeftLineShrinkOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link LeftLineShrinkOut}
     */
    public static LeftLineShrinkOut from(int pointer) {
    	return pointer == 0 ? null : new LeftLineShrinkOut(pointer);
    }
	
	protected LeftLineShrinkOut(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY);
	
	@Override
	public TiledGrid3DAction copy() {
		return new LeftLineShrinkOut(nativeCopy());
	}
}
