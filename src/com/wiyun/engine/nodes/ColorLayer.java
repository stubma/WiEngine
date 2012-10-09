package com.wiyun.engine.nodes;

import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYColor4B;

/**
 * 带颜色的层。它是{@link Layer}子类，支持设置背景色。
 */
public class ColorLayer extends Layer {
    /**
     * 创建层, 颜色透明
     * 
     * @return 层实例
     */
    public static ColorLayer make() {
        return new ColorLayer();
    }
    
    /**
     * 创建层
     * 
     * @param color 层背景色
     * @return 层实例
     */
    public static ColorLayer make(WYColor4B color) {
        return new ColorLayer(color);
    }

    /**
     * 构造函数
     */
    protected ColorLayer() {
    	nativeInit(WYColor4B.make(0, 0, 0, 0));
    }
    
    /**
     * 构造函数
     * 
     * @param color 层背景色
     */
    protected ColorLayer(WYColor4B color) {
    	nativeInit(color);
    }
    
    /**
     * 从底层指针获得一个ColorLayer的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ColorLayer}
     */
    public static ColorLayer from(int pointer) {
    	return pointer == 0 ? null : new ColorLayer(pointer);
    }
    
    protected ColorLayer(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(WYColor4B color);
    
    @Override
    protected void doNativeInit() {
    }

    public native int getAlpha();

    public native void setAlpha(int alpha);
    
	public WYColor3B getColor() {
		WYColor3B color = new WYColor3B();
		nativeGetColor(color);
		return color;
	}
	
	private native void nativeGetColor(WYColor3B color);
	
	public void setColor(WYColor3B color) {
		nativeSetColor(color.r, color.g, color.b);
	}
	
	private native void nativeSetColor(int r, int g, int b);
}