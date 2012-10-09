package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 把屏幕分成若干行，从顶部开始收缩每行。 
 */
public class TopLineShrinkOut extends TiledGrid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格尺寸
	 * @return 动作实例
	 */
	public static TopLineShrinkOut make(float duration, WYGridSize gSize) {
		return new TopLineShrinkOut(duration, gSize);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格尺寸
	 */
	protected TopLineShrinkOut(float duration, WYGridSize gSize) {
		nativeInit(duration, gSize.x, gSize.y);
	}
	
    /**
     * 从底层指针获得一个TopLineShrinkOut的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link TopLineShrinkOut}
     */
    public static TopLineShrinkOut from(int pointer) {
    	return pointer == 0 ? null : new TopLineShrinkOut(pointer);
    }
	
	protected TopLineShrinkOut(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY);
	
	@Override
	public TiledGrid3DAction copy() {
		return new TopLineShrinkOut(nativeCopy());
	}
}
