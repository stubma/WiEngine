package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;


/**
 * 贴图节点，封装一个{@link Texture2D}对象。
 */
public class TextureNode extends Node {
	public static TextureNode from(int pointer) {
		return new TextureNode(pointer);
	}
	
	protected TextureNode() {
	}
	
    protected TextureNode(int pointer) {
    	super(pointer);
    }
    
    @Override
    protected void doNativeInit() {
    	nativeInit();
    }
    
    private native void nativeInit();
    
	/**
	 * 得到是否渲染的时候要反向x轴
	 * 
	 * @return true表示渲染时要在x方向翻转图片
	 */
	public native boolean isFlipX();

	/**
	 * 是否渲染的时候要反向x轴
	 * 
	 * @param flipX true表示渲染时要在x方向翻转图片
	 */
	public native void setFlipX(boolean flipX);

	/**
	 * 得到是否渲染的时候要反向y轴
	 * 
	 * @return true表示渲染时要在y方向翻转图片
	 */
	public native boolean isFlipY();

	/**
	 * 是否渲染的时候要反向y轴
	 * 
	 * @param flipY true表示渲染时要在y方向翻转图片
	 */
	public native void setFlipY(boolean flipY);
	
	/**
	 * 是否打开抖动
	 *
	 * @return true表示打开抖动, false表示不打开抖动
	 */
	public native boolean isDither();

	/**
	 * 设置是否打开抖动
	 *
	 * @param flag true表示打开抖动, false表示不打开抖动
	 */
	public native void setDither(boolean flag);
	
    public native void setDisplayFrame(Frame frame);

    public native void setDisplayFrame(int animId, int frameIndex);

    public native boolean isFrameDisplayed(Frame frame);

    public Frame getDisplayFrame() {
    	return new SpriteFrame(nativeGetDisplayFrame());
    }
    
    private native int nativeGetDisplayFrame();

    public native void addAnimation(Animation anim);

    public Animation getAnimationById(int id) {
    	return Animation.from(nativeGetAnimationById(id));
    }
    
    private native int nativeGetAnimationById(int id);
    
	/**
	 * 设置画图时所用的贴图区域，单位为像素
	 * 
	 * @param rect 矩形区域
	 */
	public native void setTextureRect(WYRect rect);
	
	private native void nativeGetTextureRect(WYRect rect);

	/**
	 * 获得当前使用的贴图区域，单位为像素
	 * 
	 * @return 矩形区域
	 */	
	public WYRect getTextureRect() {
		WYRect rect = WYRect.makeZero();
		nativeGetTextureRect(rect);
		return rect;
	}
	
	/**
	 * 设置图片来源是一个图片集，且被顺时针旋转了90度
	 *
	 * @param flag true表示图片来源是一个图片集，且被顺时针旋转了90度
	 */
	public native void setRotatedZwoptex(boolean flag);

	/**
	 * 是否图片来源是一个图片集，且被顺时针旋转了90度
	 *
	 * @return true表示图片来源是一个图片集，且被顺时针旋转了90度
	 */
	public native boolean isRotatedZwoptex();
	
	/**
	 * 设置是否自动拉伸贴图以便能匹配节点大小
	 *
	 * @param flag true表示自动拉伸贴图以便能匹配节点大小
	 */
	public native void setAutoFit(boolean flag);

	/**
	 * 是否自动拉伸贴图以便能匹配节点大小
	 *
	 * @return true表示自动拉伸贴图以便能匹配节点大小
	 */
	public native boolean isAutoFit();
	
	/**
	 * 将自身包装成一个\link SpriteFrame SpriteFrame\endlink, 生成的\link SpriteFrame SpriteFrame\endlink
	 * 的duration是0, 需要在返回后由开发者设置.
	 */
	public SpriteFrame makeFrame() {
		return SpriteFrame.from(nativeMakeFrame());
	}
	
	private native int nativeMakeFrame();
}