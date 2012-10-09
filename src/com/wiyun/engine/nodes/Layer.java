package com.wiyun.engine.nodes;


/**
 * \if English
 * Layer is a container for other nodes. Its size by default is set
 * to surface view size and relativeAnchorPoint flag is false
 * \else
 * 层的封装, 层的缺省大小是和屏幕一样大，且relativeAnchorPoint标志
 * 缺省是false
 * \endif
 */
public class Layer extends Node {
	public static Layer make() {
		return new Layer();
	}
	
	protected Layer() {
	}
	
    /**
     * 从底层指针获得一个Layer的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Layer}
     */
    public static Layer from(int pointer) {
    	return pointer == 0 ? null : new Layer(pointer);
    }
    
    protected Layer(int pointer) {
    	super(pointer);
    }
    
	private native void nativeInit();
	
	protected void doNativeInit() {
		nativeInit();
	}
}
