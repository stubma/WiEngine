package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 波浪效果，3D表示z轴也会发生波浪变化。
 */
public class Waves3D extends Grid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param amplitude 幅度
	 * @param waves 波浪数
	 * @return 动作实例
	 */
	public static Waves3D make(float duration, WYGridSize gridSize, float amplitude, int waves) {
		return new Waves3D(duration, gridSize, amplitude, waves);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param amplitude 幅度
	 * @param waves 波浪数
	 */
	protected Waves3D(float duration, WYGridSize gridSize, float amplitude, int waves) {
		nativeInit(duration, gridSize.x, gridSize.y, amplitude, waves);
	}
	
    /**
     * 从底层指针获得一个Waves3D的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Waves3D}
     */
    public static Waves3D from(int pointer) {
    	return pointer == 0 ? null : new Waves3D(pointer);
    }
    
	protected Waves3D(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY, float amplitude, int waves);

	@Override
	public Grid3DAction copy() {
		return new Waves3D(nativeCopy());
	}
}
