package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;

/**
 * 网络跳跃。每个Tile形成上下跳跃的效果。 
 */
public class JumpTiles3D extends TiledGrid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格行列数
	 * @param amplitude 动作幅度
	 * @param jumps 跳跃次数
	 * @return 动作实例
	 */
	public static JumpTiles3D make(float duration, WYGridSize gSize, float amplitude, int jumps) {
		return new JumpTiles3D(duration, gSize, amplitude, jumps);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 * @param gSize 网格行列数
	 * @param amplitude 动作幅度
	 * @param jumps 跳跃次数
	 */
	protected JumpTiles3D(float duration, WYGridSize gSize, float amplitude, int jumps) {
		nativeInit(duration, gSize.x, gSize.y, amplitude, jumps);
	}
	
    /**
     * 从底层指针获得一个JumpTiles3D的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link JumpTiles3D}
     */
    public static JumpTiles3D from(int pointer) {
    	return pointer == 0 ? null : new JumpTiles3D(pointer);
    }
    
	protected JumpTiles3D(int pointer) {
		super(pointer);
	}

	private native void nativeInit(float duration, int gridX, int gridY, float amplitude, int jumps);

	@Override
	public TiledGrid3DAction copy() {
		return new JumpTiles3D(nativeCopy());
	}
}
