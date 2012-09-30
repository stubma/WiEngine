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

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYPointList;
import com.wiyun.engine.types.WYSize;

/**
 * \if English
 * Object in TMX object group
 * \else
 * TMX地图中定义的对象
 * \endif
 */
public class TMXObject extends BaseWYObject {
	/**
	 * \if English
	 * Object type
	 * \else
	 * 对象类型
	 * \endif
	 */
	public enum Type {
		/**
		 * \if English
		 * Normal object, just a collection of key-value pairs
		 * \else
		 * 普通对象, 只有一些键值对属性
		 * \endif
		 */
		NORMAL,

		/**
		 * \if English
		 * Polygon object, can get vertex points
		 * \else
		 * 多边形对象, 由一系列点描述
		 * \endif
		 */
		POLYGON,

		/**
		 * \if English
		 * Polyline object, first and last point is not connected
		 * \else
		 * 非闭合多边形, 由一系列点描述
		 * \endif
		 */
		POLYLINE
	};
	
	public static TMXObject from(int pointer) {
		return pointer == 0 ? null : new TMXObject(pointer);
	}
	
	protected TMXObject() {
		nativeInit();
	}
	
	protected TMXObject(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit();

	/**
	 * \if English
	 * Get a property value by a key
	 *
	 * @param key key string
	 * @return value string, or NULL if not found. caller should NOT release it
	 * \else
	 * 根据键查询对象属性
	 *
	 * @param key 键
	 * @return 属性字符串, NULL表示没找到. 调用者不需要负责释放指针
	 * \endif
	 */
	public native String getProperty(String key);
	
	/**
	 * \if English
	 * Get object type
	 * \else
	 * 得到对象类型
	 * \endif
	 */
	public Type getType() {
		return Type.values()[nativeGetType()];
	}
	
	private native int nativeGetType();
	
	/**
	 * \if English
	 * A quick way to get object position
	 *
	 * @return position, in tmx map coordinates based on map type
	 * \else
	 * 一个快速得到对象位置的方法
	 *
	 * @return 对象位置, 坐标是相对于tmx地图的, 跟tmx地图类型有关, 比如正交和六角都是以左上角
	 * 		为原点. 而对角是以最上面的菱形的顶点为原点, 且x, y轴都是斜向的.
	 * \endif
	 */
	public WYPoint getPosition() {
		WYPoint p = WYPoint.makeZero();
		nativeGetPosition(p);
		return p;
	}

	private native void nativeGetPosition(WYPoint p);

	/**
	 * \if English
	 * A quick way to get object size, but not all objects have a size
	 *
	 * @return size of object
	 * \else
	 * 一个快速得到对象大小的方法, 但不是所有对象都有大小
	 *
	 * @return 对象大小
	 * \endif
	 */
	public WYSize getSize() {
		WYSize s = WYSize.makeZero();
		nativeGetSize(s);
		return s;
	}

	private native void nativeGetSize(WYSize s);
	
	/**
	 * \if English
	 * Get point list, only used for POLYGON or POLYLINE object
	 *
	 * @return \link WYPointList WYPointList\endlink
	 * \else
	 * 得到点列表, 如果对象不是POLYGON或POLYLINE则无意义
	 *
	 * @return \link WYPointList WYPointList\endlink
	 * \endif
	 */
	public WYPointList getPoints() {
		WYPointList plist = new WYPointList();
		nativeGetPoints(plist);
		return plist;
	}

	private native void nativeGetPoints(WYPointList plist);
}
