package com.wiyun.engine.actions;


/**
 * \if English
 * Move a node to specfied place. This action doesn't have reverse action and
 * execute instantly.
 * \else
 * 放置动作. 目标会被置于某个位置. 这是一个瞬发动作, 且无反向动作.
 * 调用reverse方法会抛出{@link UnsupportedOperationException}异常
 * \endif
 */
public class Place extends InstantAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param x x offset to be added
	 * @param y y offset to be added
	 * \else
	 * 静态构造函数
	 *
	 * @param x 目标位置x轴偏移量
	 * @param y 目标位置y轴偏移量
	 * \endif
	 */
    public static Place make(float x, float y) {
        return new Place(x, y);
    }

    protected Place(float x, float y) {
    	nativeInit(x, y);
    }
    
    /**
     * 从底层指针获得一个Place的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Place}
     */
    public static Place from(int pointer) {
    	return pointer == 0 ? null : new Place(pointer);
    }
    
    protected Place(int pointer) {
    	super(pointer);
	}

	private native void nativeInit(float x, float y);

    @Override
    public Place copy() {
        return new Place(nativeCopy());
    }
    
    @Override
    public InstantAction reverse() {
    	throw new UnsupportedOperationException("Place doesn't have reverse action");
    }
}
