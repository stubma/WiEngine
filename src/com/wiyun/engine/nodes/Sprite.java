package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;

/**
 * 图片对象
 */ 
public class Sprite extends TextureNode {
    /**
     * 从png资源文件中创建图片节点。这个API主要为了兼容目的存在，如果为了从
     * 其它文件格式中创建Sprite，请使用Texture2D的make系列方法创建Texture2D
     * 对象，再创建Sprite
     * 
     * @param resId 图片资源id
     * @return 图片对象
     */
    public static Sprite make(int resId) {
    	return new Sprite((Texture2D)Texture2D.makePNG(resId).autoRelease());
    }

    /**
     * 从一个贴图对象中创建图片节点
     * 
     * @param tex {@link Texture2D}
     * @return 图片对象
     */
    public static Sprite make(Texture2D tex) {
        return new Sprite(tex);
    }

    /**
     * 从一个贴图对象中创建图片节点
     * 
     * @param tex {@link Texture2D}
     * @param texRect 贴图区域，单位为像素
     * @return 图片对象
     */
    public static Sprite make(Texture2D tex, WYRect texRect) {
    	return new Sprite(tex, texRect);
    }
    
    /**
     * 构造函数
     * 
     * @param tex {@link Texture2D}
     */
    protected Sprite(Texture2D tex) {
    	nativeInit(tex);
    }

    /**
     * 构造函数
     * 
     * @param tex {@link Texture2D}
     * @param texRect 贴图区域矩形
     */
    protected Sprite(Texture2D tex, WYRect texRect) {
    	nativeInit(tex);
    	setTextureRect(texRect);
    }
    
    /**
     * 从底层指针获得一个Sprite的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Sprite}
     */
    public static Sprite from(int pointer) {
    	return pointer == 0 ? null : new Sprite(pointer);
    }
    
    protected Sprite(int pointer) {
    	super(pointer);
    }
    
    @Override
    protected void doNativeInit() {
    }
    
    private native void nativeInit(Texture2D tex);
}
