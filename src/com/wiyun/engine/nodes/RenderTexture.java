package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYBlendFunc;
import com.wiyun.engine.types.WYColor3B;

/**
 * 设置自定义frame buffer，使渲染结果保存在贴图中。用于实现一些特殊效果。 
 */
public class RenderTexture extends Node {
	/**
	 * \if English
	 * Create a render texture with specified size
	 *
	 * @param width width in pixel
	 * @param height height in pixel
	 * \else
	 * 静态构造函数
	 *
	 * @param width 宽度
	 * @param height 高度
	 * \endif
	 */
	public static RenderTexture make(int width, int height) {
		return new RenderTexture(width, height);
	}
	
	/**
	 * \if English
	 * Create a render texture which is full screen size
	 * \else
	 * 创建一个全屏大小的渲染贴图
	 * \endif
	 */
	public static RenderTexture make() {
		return new RenderTexture();
	}
	
	protected RenderTexture(int width, int height) {
		nativeInit(width, height);
	}
	
	public RenderTexture() {
		nativeInit();
	}
	
    /**
     * 从底层指针获得一个RenderTexture的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link RenderTexture}
     */
    public static RenderTexture from(int pointer) {
    	return pointer == 0 ? null : new RenderTexture(pointer);
    }
    
    protected RenderTexture(int pointer) {
    	super(pointer);
    }
    
	@Override
	protected void doNativeInit() {
	}
	
	private native void nativeInit();
	private native void nativeInit(int width, int height);
	
	/**
	 * \if English
	 * Start render something into texture. You can specify background color of
	 * texture
	 *
	 * @param r red component of background
	 * @param g green component of background
	 * @param b blue component of background
	 * @param a alpha component of background
	 * \else
	 * Render之前调用, 开始讲渲染操作重定向到贴图中. 这个方法可以指定贴图背景色
	 *
	 * @param r 背景色的红色部分
	 * @param g 背景色的绿色部分
	 * @param b 背景色的蓝色部分
	 * @param a 背景色的透明度
	 * \endif
	 */
	public native void beginRender(float r, float g, float b, float a);
	
	/**
	 * \if English
	 * Start render something into texture
	 * \else
	 * Render之前调用, 开始讲渲染操作重定向到贴图中
	 * \endif
	 */
	public native void beginRender();
	
	/**
	 * \if English
	 * End render redirecting
	 * \else
	 * Render之后调用, 结束渲染重定向
	 * \endif
	 */
	public native void endRender();
	
	/**
	 * \if English
	 * Clear texture with a color
	 *
	 * @param r red component of background
	 * @param g green component of background
	 * @param b blue component of background
	 * @param a alpha component of background
	 * \else
	 * 用某个颜色清空贴图内容
	 *
	 * @param r 背景色的红色部分
	 * @param g 背景色的绿色部分
	 * @param b 背景色的蓝色部分
	 * @param a 背景色的透明度
	 * \endif
	 */
	public native void clear(float r, float g, float b, float a);
	
    public WYBlendFunc getBlendFunc() {
    	return new WYBlendFunc(getBlendFuncSrc(), getBlendFuncDst());
    }
    
    private native int getBlendFuncSrc();
    private native int getBlendFuncDst();
    
    public void setBlendFunc(WYBlendFunc blendFunc) {
    	nativeSetBlendFunc(blendFunc.src, blendFunc.dst);
    }
    
    private native void nativeSetBlendFunc(int src, int dst);
	
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
	
	/**
	 * \if English
	 * Get \link Texture2D Texture2D\endlink object from render texture
	 *
	 * @return \link Texture2D Texture2D\endlink
	 * \else
	 * 从当前对象得到一个\link Texture2D Texture2D\endlink对象
	 *
	 * @return \link Texture2D Texture2D\endlink
	 * \endif
	 */
	public Texture2D createTexture() {
		return Texture2D.from(nativeCreateTexture());
	}
	
	private native int nativeCreateTexture();
}
