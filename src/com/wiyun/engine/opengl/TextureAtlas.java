/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
package com.wiyun.engine.opengl;

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYQuad2D;
import com.wiyun.engine.types.WYQuad3D;

/**
 * {@link TextureAtlas}是支持图片集的基础类。它将一张大图载入内存中，并且维护一个四边形列表，
 * 每个四边形对应着大图的某块位置，从而可以从大图得到单幅图片。 
 */
public class TextureAtlas extends BaseWYObject {
	public static final int DEFAULT_CAPACITY = 29;
	
	/**
	 * 得到当前四边形个数，也就是依赖于这个图片集的AtlasSprite个数
	 * 
	 * @return 当前四边形个数
	 */
	public native int getTotalQuads();
	
	/**
	 * 得到下一个AtlasSprite的可用索引
	 * 
	 * @return 下一个AtlasSprite的可用索引
	 */
	public native int getNextAvailableIndex();

	/**
	 * 得到目前能容纳的四边形个数
	 * 
	 * @return 能容纳的四边形个数
	 */
	public native int getCapacity();

	/**
	 * 得到贴图对象
	 * 
	 * @return {@link Texture2D}
	 */
	public Texture2D getTexture() {
		return new Texture2D(nativeGetTexture());
	}
	
	private native int nativeGetTexture();

	/**
	 * 设置贴图对象
	 * 
	 * @param tex {@link Texture2D} 
	 */
	public native void setTexture(Texture2D tex);

	/**
	 * 是否有颜色数组
	 * 
	 * @return true表示渲染贴图的时候有颜色数组
	 */
	public native boolean isWithColorArray();
	
	/**
	 * 包装一个Texture2D实例, 创建一个TextureAtlas实例, 
	 * 这个方法始终创建新的{@link TextureAtlas}
	 * 
	 * @param tex {@link Texture2D}实例，通过Texture2D的系列make方法创建
	 * @return {@link TextureAtlas}
	 */
	public static TextureAtlas make(Texture2D tex) {
		return new TextureAtlas(tex, DEFAULT_CAPACITY);
	}
	
	/**
	 * 构造函数
	 * 
	 * @param tex {@link Texture2D}
	 * @param capacity 初始容量
	 */
	protected TextureAtlas(Texture2D tex, int capacity) {
		mPointer = nativeNew(tex, capacity);
	}
	
	protected TextureAtlas() {
	}

	/**
	 * 从底层指针获得一个TextureAtlas的java对象
	 * 
	 * @param pointer 从native端拿到的对象指针
	 */	
	public static TextureAtlas from(int pointer) {
		return pointer == 0 ? null : new TextureAtlas(pointer);
	}
	
	protected TextureAtlas(int pointer) {
		super(pointer);
	}
	
	private native int nativeNew(Texture2D tex, int capacity);

	@Override
	public String toString() {
		return String.format("<%s = %08X | getTotalQuads = %d>", TextureAtlas.class, this, getTotalQuads());
	}
	
	/**
	 * 更新某个位置的四边形数据
	 * 
	 * @param quadT 四边形的贴图坐标
	 * @param quadV 四边形的顶点坐标
	 * @param index 四边形索引
	 */
	public native void updateQuad(WYQuad2D quadT, WYQuad3D quadV, int index);

	/**
	 * 更新某个顶点的颜色
	 * 
	 * @param color {@link WYColor4B}
	 * @param index 顶点索引
	 */
	public native void updateColor(WYColor4B color, int index);
	
	/**
	 * 在缓存中添加顶点和纹理,放到队列中最后
	 *
	 * @param texCoords 纹理\link WYQuad2D WYQuad2D结构\endlink
	 * @param vertexCoords 顶点\link WYQuad3D WYQuad3D结构\endlink
	 * @return 新添加的四边形在atlas中的索引
	 */
	public native int appendQuad(WYQuad2D texCoords, WYQuad3D vertexCoords);

	/**
	 * 插入一个四边形
	 * 
	 * @param texCoords 贴图坐标
	 * @param vertexCoords 顶点坐标
	 * @param index 四边形索引位置
	 */
	public native void insertQuad(WYQuad2D texCoords, WYQuad3D vertexCoords, int index);

	/**
	 * 删除指定位置的四边形
	 * 
	 * @param index 四边形索引
	 */
	public native void removeQuad(int index);
	
	/**
	 * 删除一定范围内的四边形
	 *
	 * @param start 删除的起始索引
	 * @param count 删除的四边形个数
	 */
	public native void removeQuads(int start, int count);

	/**
	 * 删除所有四边形数据
	 */
	public native void removeAllQuads();

	/**
	 * 修改四边形容量
	 * 
	 * @param newCapacity 新的容量
	 */
	public native void resizeCapacity(int newCapacity);
	
    /**
     * 得到贴图实际象素高度
     */
    public native int getPixelHeight();

    /**
     * 得到贴图实际象素宽度
     */
    public native int getPixelWidth();
    
    /**
     * 得到贴图可绘制区域高度
     * 
     * @return 可绘制区域高度
     */
    public native float getHeight();
    
    /**
     * 得到贴图可绘制区域宽度
     * 
     * @return 可绘制区域宽度
     */
    public native float getWidth();
    
    /**
     * 得到贴图可绘制区域的高度和实际高度的比值，这个比值小于等于1
     * 
     * @return 可绘制区域的高度和实际高度的比值
     */
    public native float getHeightScale();
    
    /**
     * 得到贴图可绘制区域的宽度和实际宽度的比值，这个比值小于等于1
     * 
     * @return 可绘制区域的宽度和实际宽度的比值
     */
    public native float getWidthScale();

	/**
	 * 绘制所有的四边形
	 */
	public native void draw();
	
	/**
	 * 绘制指定位置的一个四边形
	 * 
	 * @param quadIndex 四边形的位置索引，如果不是合理范围，无效果
	 */
	public native void drawOne(int quadIndex);

	/**
	 * 绘制指定的四边形个数
	 * 
	 * @param numOfQuads 四边形个数
	 */
	public native void draw(int numOfQuads);
	
	/**
	 * 设置atlas的缺省颜色, 调用这个方法将会打开atlas的颜色数组
	 *
	 * @param color \link WYColor4B WYColor4B\endlink
	 */
	public native void setColor(WYColor4B color);
	
	/**
	 * \if English
	 * Get color of texture atlas
	 * \else
	 * 得到当前颜色
	 * \endif
	 */
	public WYColor4B getColor() {
		WYColor4B color = new WYColor4B();
		nativeGetColor(color);
		return color;
	}
	
	private native void nativeGetColor(WYColor4B color);

	/**
	 * \if English
	 * Set atlas alpha
	 * \else
	 * 设置atlas的透明度
	 * \endif
	 */
	public native void setAlpha(int alpha);
	
	/**
	 * 把自己的一个四边形拷贝到另外一个\link TextureAtlas TextureAtlas\endlink 节点中
	 *
	 * @param from 要拷贝的四边形索引位置，如果范围不合法，则什么也不做
	 * @param destAtlas 目标\link TextureAtlas TextureAtlas\endlink
	 */
	public native void copyTo(int from, TextureAtlas destAtlas);
	
	/**
	 * 把自己的一个四边形拷贝到传入的指针中
	 *
	 * @param from 要拷贝的四边形索引位置，如果范围不合法，则什么也不做
	 * @param quadT 保存贴图坐标，一个\link WYQuad2D WYQuad2D\endlink
	 * @param quadV 保存顶点坐标，一个\link WYQuad3D WYQuad3D\endlink
	 */
	public native void copyTo(int from, WYQuad2D quadT, WYQuad3D quadV);
}
