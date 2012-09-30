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
package com.wiyun.engine.tmx;

import com.wiyun.engine.nodes.Node;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYPoint;

/**
 * \if English
 * TMX tile map class. Every layer in TMX map is a \link wyTMXLayer wyTMXLayer\endlink class and
 * also child node of it.
 * \else
 * 这是TMX地图的顶层类, TMX地图中的每一层都是一个\link wyTMXLayer wyTMXLayer\endlink类, 也是它的子节点
 * \endif
 */
public class TMXTileMap extends Node {
	// map orientation
	public static final int ORIENTATION_ORTHOGONAL = 1;
	public static final int ORIENTATION_ISOMETRIC = 2;
	public static final int ORIENTATION_HEXAGONAL = 3;
	
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param resId tmx file resource id
	 * @param tex textures of tileset, if more than one tileset, append other texture after this
	 * @return \link TMXTileMap TMXTileMap\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param resId .tmx文件的资源ID
	 * @param tex tileset的贴图, 如果有其它tileset, 依次追加贴图对象
	 * @return \link TMXTileMap TMXTileMap\endlink
	 * \endif
	 */
	public static TMXTileMap make(int resId, Texture2D... tex) {
		return new TMXTileMap(resId, tex);
	}
	
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param path tmx file path
	 * @param isFile true means \c path is an absolute path in file system, or false if \c path
	 * 		is a relative path under assets
	 * @param tex textures of tileset, if more than one tileset, append other texture after this
	 * @return \link TMXTileMap TMXTileMap\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param path tmx文件的路径
	 * @param isFile true表示path是一个文件系统路径, false表示这是一个assets下的相对路径
	 * @param tex tileset的贴图, 如果有其它tileset, 依次追加贴图对象
	 * @return \link TMXTileMap TMXTileMap\endlink
	 * \endif
	 */
	public static TMXTileMap make(String path, boolean isFile, Texture2D... tex) {
		return new TMXTileMap(path, isFile, tex);
	}
	
	protected TMXTileMap(int resId, Texture2D... tex) {
		nativeInit(resId, tex);
	}

	protected TMXTileMap(String path, boolean isFile, Texture2D... tex) {
		nativeInit(path, isFile, tex);
	}
	
    /**
     * 从底层指针获得一个TMXTileMap的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link TMXTileMap}
     */
    public static TMXTileMap from(int pointer) {
    	return pointer == 0 ? null : new TMXTileMap(pointer);
    }
    
    protected TMXTileMap(int pointer) {
    	super(pointer);
    }
	
	@Override
	protected void doNativeInit() {
	}
	
	private native void nativeInit(int resId, Texture2D... tex);
	private native void nativeInit(String path, boolean isFile, Texture2D... tex);
	
	/**
	 * 根据名字获得层
	 * 
	 * @param name 层的名字
	 * @return {@link TMXLayer}
	 */
	public TMXLayer getTMXLayer(String name) {
		return new TMXLayer(nativeGetTMXLayer(name));
	}
	
	private native int nativeGetTMXLayer(String name);
	
	/**
	 * 根据索引得到\link TMXLayer TMXLayer\endlink
	 *
	 * @param index layer的索引, 从0开始
	 * @return \link TMXLayer TMXLayer\endlink, 如果索引范围不合法, 返回NULL
	 */
	public TMXLayer getTMXLayerAt(int index) {
		return new TMXLayer(nativeGetTMXLayerAt(index));
	}
	
	private native int nativeGetTMXLayerAt(int index);

	/**
	 * 根据名字获得对象组
	 * 
	 * @param name 对象组的名称
	 * @return {@link TMXObjectGroup}
	 */
	public TMXObjectGroup getObjectGroup(String name) {
		return TMXObjectGroup.from(nativeGetObjectGroup(name));
	}
	
	private native int nativeGetObjectGroup(String name);
	
	/**
	 * 得到地图的属性数据
	 * 
	 * @param key 属性关键字
	 * @return 属性值，为字符串形式，如果实际上整数，需要调用者进行转换
	 */
	public native String getProperty(String key);
	
	/**
	 * 根据网格id得到网格的属性表
	 * 
	 * @param gid 网格id
	 * @param key 属性关键字
	 * @return 属性值，为字符串形式，如果实际上整数，需要调用者进行转换
	 */
	public native String getTileProperties(int gid, String key);

	public native int getMapWidth();

	public native int getMapHeight();

	public native float getTileWidth();

	public native float getTileHeight();

	public native int getOrientation();
	
	/**
	 * \if English
	 * Set to true if you want to render objects outline, for debug purpose.
	 * By default it is false
	 * \else
	 * 设置是否渲染自定义对象的轮廓, 仅用于调试目的. 缺省是false
	 * \endif
	 */
	public native void setDebugDrawObjects(boolean flag);
	
	/**
	 * \if English
	 * Convert a point from node to TMX coordinate space
	 *
	 * @param p point in node space
	 * @return point in TMX space
	 * \else
	 * 把一个点的坐标从节点空间转换到TMX空间
	 *
	 * @param p 要转换的点
	 * @return 转换到TMX空间后的点
	 * \endif
	 */
	public WYPoint nodeToTMXSpace(WYPoint p) {
		WYPoint out = WYPoint.makeZero();
		nativeNodeToTMXSpace(p, out);
		return out;
	}
	
	private native void nativeNodeToTMXSpace(WYPoint p, WYPoint out);

	/**
	 * \if English
	 * Convert a point from TMX to node coordinate space
	 *
	 * @param p point in TMX space
	 * @return point in node space
	 * \else
	 * 把一个点的坐标从TMX空间转换到节点空间
	 *
	 * @param p 要转换的点
	 * @return 转换到节点空间后的点
	 * \endif
	 */
	public WYPoint tmxToNodeSpace(WYPoint p) {
		WYPoint out = WYPoint.makeZero();
		nativeTMXToNodeSpace(p, out);
		return out;
	}
	
	private native void nativeTMXToNodeSpace(WYPoint p, WYPoint out);
	
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
