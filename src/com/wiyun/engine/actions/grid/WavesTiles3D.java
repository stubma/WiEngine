package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 网格波浪效果。
 */
public class WavesTiles3D extends TiledGrid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param amplitude 幅度
	 * @param waves 波浪数
	 * @return 动作实例
	 */
	public static WavesTiles3D make(float duration, WYGridSize gridSize, float amplitude, int waves) {
		return new WavesTiles3D(duration, gridSize, amplitude, waves);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param amplitude 幅度
	 * @param waves 波浪数
	 */
	protected WavesTiles3D(float duration, WYGridSize gridSize, float amplitude, int waves) {
		nativeInit(duration, gridSize.x, gridSize.y, amplitude, waves);
	}
	
    /**
     * 从底层指针获得一个WavesTiles3D的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link WavesTiles3D}
     */
    public static WavesTiles3D from(int pointer) {
    	return pointer == 0 ? null : new WavesTiles3D(pointer);
    }
	
	protected WavesTiles3D(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY, float amplitude, int waves);

	@Override
	public TiledGrid3DAction copy() {
		return new WavesTiles3D(nativeCopy());
	}
}
