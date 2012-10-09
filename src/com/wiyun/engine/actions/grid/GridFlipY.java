package com.wiyun.engine.actions.grid;


/**
 * 旋转Y轴180度 
 */
public class GridFlipY extends Grid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @return 动作实例
	 */
	public static GridFlipY make(float duration) {
		return new GridFlipY(duration);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 */
	protected GridFlipY(float duration) {
		nativeInit(duration);
	}
	
    /**
     * 从底层指针获得一个GridFlipY的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link GridFlipY}
     */
    public static GridFlipY from(int pointer) {
    	return pointer == 0 ? null : new GridFlipY(pointer);
    }
	
	protected GridFlipY(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(float duration);

	@Override
	public Grid3DAction copy() {
		return new GridFlipY(nativeCopy());
	}
}
