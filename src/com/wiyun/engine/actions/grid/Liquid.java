package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 液体效果。使目标对象呈现流动的效果。
 */
public class Liquid extends Grid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param amplitude 幅度
	 * @param waves 波数
	 * @return 动作实例
	 */
	public static Liquid make(float duration, WYGridSize gridSize, float amplitude, float waves) {
		return make(duration, gridSize, amplitude, 0, waves);
	}

	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param amplitude 幅度
	 * @param deltaAmplitude 幅度变化量
	 * @param waves 波数
	 * @return 动作实例
	 */
	public static Liquid make(float duration, WYGridSize gridSize, float amplitude, float deltaAmplitude, float waves) {
		return new Liquid(duration, gridSize, amplitude, deltaAmplitude, waves);
	}
	
	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param amplitude 幅度
	 * @param deltaAmplitude 幅度变化量
	 * @param waves 波数
	 */
	protected Liquid(float duration, WYGridSize gridSize, float amplitude, float deltaAmplitude, float waves) {
		nativeInit(duration, gridSize.x, gridSize.y, amplitude, deltaAmplitude, waves);
	}
	
    /**
     * 从底层指针获得一个Liquid的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Liquid}
     */
    public static Liquid from(int pointer) {
    	return pointer == 0 ? null : new Liquid(pointer);
    }
	
	protected Liquid(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY, float amplitude, float deltaAmplitude, float waves);

	@Override
	public Grid3DAction copy() {
		return new Liquid(nativeCopy());
	}
}
