package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;
import com.wiyun.engine.types.WYPoint;

/**
 * 透镜效果。 使目标看起来好像在放大镜下。 
 */
public class Lens3D extends Grid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param pos 透镜中心位置
	 * @param radius 透镜半径
	 * @param lensEffect 透镜凹凸程度
	 * @return 动作实例
	 */
	public static Lens3D make(float duration, WYGridSize gridSize, WYPoint pos, float radius, float lensEffect) {
		return make(duration, gridSize, pos.x, pos.y, radius, lensEffect);
	}
	
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param centerX 透镜中心位置x坐标
	 * @param centerY 透镜中心位置y坐标 
	 * @param radius 透镜半径
	 * @param lensEffect 透镜凹凸程度
	 * @return 动作实例
	 */
	public static Lens3D make(float duration, WYGridSize gridSize, float centerX, float centerY, float radius, float lensEffect) {
		return make(duration, gridSize, centerX, centerY, 0, 0, radius, 0, lensEffect);
	}
	
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param centerX 透镜中心位置x坐标
	 * @param centerY 透镜中心位置y坐标 
	 * @param deltaX 透镜横向移动距离
	 * @param deltaY 透镜纵向移动距离
	 * @param radius 透镜半径
	 * @param deltaRadius 透镜半径变化量
	 * @param lensEffect 透镜凹凸程度
	 * @return 动作实例
	 */
	public static Lens3D make(float duration, WYGridSize gridSize, float centerX, float centerY, 
			float deltaX, float deltaY, float radius, float deltaRadius, float lensEffect) {
		return new Lens3D(duration, gridSize, centerX, centerY, deltaX, deltaY, radius, deltaRadius, lensEffect);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gridSize 网格行列数
	 * @param centerX 透镜中心位置x坐标
	 * @param centerY 透镜中心位置y坐标 
	 * @param deltaX 透镜横向移动距离
	 * @param deltaY 透镜纵向移动距离
	 * @param radius 透镜半径
	 * @param deltaRadius 透镜半径变化量
	 * @param lensEffect 透镜凹凸程度
	 */
	protected Lens3D(float duration, WYGridSize gridSize, float centerX, float centerY, 
			float deltaX, float deltaY, float radius, float deltaRadius, float lensEffect) {
		nativeInit(duration, gridSize.x, gridSize.y, centerX, centerY, deltaX, deltaY, radius, deltaRadius, lensEffect);
	}
	
    /**
     * 从底层指针获得一个Lens3D的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Lens3D}
     */
    public static Lens3D from(int pointer) {
    	return pointer == 0 ? null : new Lens3D(pointer);
    }
	
	protected Lens3D(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY, float centerX, float centerY,
		float deltaX, float deltaY, float radius, float deltaRadius, float lensEffect);

	@Override
	public Grid3DAction copy() {
		return new Lens3D(nativeCopy());
	}
}
