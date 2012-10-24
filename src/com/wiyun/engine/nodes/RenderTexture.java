package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;

/**
 * 设置自定义frame buffer，使渲染结果保存在贴图中。用于实现一些特殊效果。 
 */
public class RenderTexture extends Node {
	/**
	 * Create a render texture with specified size
	 *
	 * @param width width in pixel
	 * @param height height in pixel
	 */
	public static RenderTexture make(int width, int height) {
		return new RenderTexture(width, height);
	}
	
	/**
	 * Create a render texture which is full screen size
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
	 * Start render something into texture. You can specify background color of
	 * texture
	 *
	 * @param r red component of background
	 * @param g green component of background
	 * @param b blue component of background
	 * @param a alpha component of background
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
	 * End render redirecting
	 */
	public native void endRender();
	
	/**
	 * Clear texture with a color
	 *
	 * @param r red component of background
	 * @param g green component of background
	 * @param b blue component of background
	 * @param a alpha component of background
	 */
	public native void clear(float r, float g, float b, float a);
	
	/**
	 * Get \link Texture2D Texture2D\endlink object from render texture
	 *
	 * @return \link Texture2D Texture2D\endlink
	 */
	public Texture2D createTexture() {
		return Texture2D.from(nativeCreateTexture());
	}
	
	private native int nativeCreateTexture();
}
