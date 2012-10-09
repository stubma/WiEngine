package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 翻页动作。 
 */
public class PageTurn3D extends Grid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格行列数
	 * @return 动作实例
	 */
	public static PageTurn3D make(float duration, WYGridSize gSize) {
		return new PageTurn3D(duration, gSize);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格行列数
	 */
	protected PageTurn3D(float duration, WYGridSize gSize) {
		nativeInit(duration, gSize.x, gSize.y);
	}
	
    /**
     * 从底层指针获得一个PageTurn3D的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link PageTurn3D}
     */
    public static PageTurn3D from(int pointer) {
    	return pointer == 0 ? null : new PageTurn3D(pointer);
    }
	
	protected PageTurn3D(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY);
	
	@Override
	public Grid3DAction copy() {
		return new PageTurn3D(nativeCopy());
	}
}
