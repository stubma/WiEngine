package com.wiyun.engine.actions.grid;



/**
 * 旋转x轴180度。 
 */
public class GridFlipX extends Grid3DAction {
	/**
	 * 创建动作实例
	 * 
	 * @param duration 动作持续时间
	 * @return 动作实例
	 */
	public static GridFlipX make(float duration) {
		return new GridFlipX(duration);
	}

	/**
	 * 构造函数
	 * 
	 * @param duration 动作持续时间
	 */
	protected GridFlipX(float duration) {
		nativeInit(duration);
	}
	
    /**
     * 从底层指针获得一个GridFlipX的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link GridFlipX}
     */
    public static GridFlipX from(int pointer) {
    	return pointer == 0 ? null : new GridFlipX(pointer);
    }
    
	protected GridFlipX(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(float duration);

	@Override
	public Grid3DAction copy() {
		return new GridFlipX(nativeCopy());
	}
}
