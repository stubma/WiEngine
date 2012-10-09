package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;

/**
 * 点9精灵图片对象. 可以对一个图片指定一个可缩放区域, 这样一个小图片可以被缩放
 * 为任意大小. 这类似于Android提供的.9图片格式, 不过并不支持不连续的缩放区域.
 *
 * 目前NinePatchSprite不支持旋转过的图片集图片, 即rotated属性为true的图片集
 * 图片尚不支持
 */
public class NinePatchSprite extends Node {
	/**
	 * 构造\link NinePatchSprite NinePatchSprite对象指针\endlink
	 *
	 * @param tex \link Texture2D Texture2D对象指针\endlink
	 * @param patchRect 图片中被拉伸的矩形区域, 坐标相对于图片, 以图片的左上角为原点
	 * @return \link NinePatchSprite NinePatchSprite对象指针\endlink
	 */
	public static NinePatchSprite make(Texture2D tex, WYRect patchRect) {
		WYRect r = WYRect.make(0, 0, tex.getWidth(), tex.getHeight());
		return make(tex, r, patchRect);
	}
	
	/**
	 * 构造\link NinePatchSprite NinePatchSprite对象指针\endlink
	 *
	 * @param tex \link Texture2D Texture2D对象指针\endlink
	 * @param texRect 如果tex代表了一个图片集, 则可以通过\c texRect 指定图片集中的图片矩形
	 * @param patchRect 图片中被拉伸的矩形区域, 坐标相对于图片, 以图片的左上角为原点
	 * @return \link NinePatchSprite NinePatchSprite对象指针\endlink
	 */
	public static NinePatchSprite make(Texture2D tex, WYRect texRect, WYRect patchRect) {
		return new NinePatchSprite(tex, texRect, patchRect);
	}
	
	public static NinePatchSprite from(int pointer) {
		return pointer == 0 ? null : new NinePatchSprite(pointer);
	}
	
	protected NinePatchSprite() {
	}
	
    protected NinePatchSprite(int pointer) {
    	super(pointer);
    }
    
    protected NinePatchSprite(Texture2D tex, WYRect texRect, WYRect patchRect) {
    	nativeInit(tex, texRect, patchRect);
    }
    
    @Override
    protected void doNativeInit() {
    }
    
    private native void nativeInit(Texture2D tex, WYRect texRect, WYRect patchRect);
    
    public Texture2D getTexture() {
        return Texture2D.from(nativeGetTexture());
    }
    
    private native int nativeGetTexture();
    public native void setTexture(Texture2D texture);
	
	/**
	 * 设置画图时所用的贴图区域，单位为像素
	 * 
	 * @param rect 矩形区域
	 */
	public native void setTextureRect(WYRect rect);
	
	private native void nativegetTextureRect(WYRect rect);

	/**
	 * 获得当前使用的贴图区域，单位为像素
	 * 
	 * @return 矩形区域
	 */	
	public WYRect getTextureRect() {
		WYRect rect = WYRect.makeZero();
		nativegetTextureRect(rect);
		return rect;
	}
}
