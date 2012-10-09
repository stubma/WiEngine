package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 把屏幕分成若干列，从右边开始收缩每列。 
 */
public class RightLineShrinkOut extends TiledGrid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格尺寸
	 * @return 动作实例
	 */
	public static RightLineShrinkOut make(float duration, WYGridSize gSize) {
		return new RightLineShrinkOut(duration, gSize);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格尺寸
	 */
	protected RightLineShrinkOut(float duration, WYGridSize gSize) {
		nativeInit(duration, gSize.x, gSize.y);
	}
	
    /**
     * 从底层指针获得一个RightLineShrinkOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link RightLineShrinkOut}
     */
    public static RightLineShrinkOut from(int pointer) {
    	return pointer == 0 ? null : new RightLineShrinkOut(pointer);
    }
	
	protected RightLineShrinkOut(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY);
	
	@Override
	public TiledGrid3DAction copy() {
		return new RightLineShrinkOut(nativeCopy());
	}
}
