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

/**
 * \if English
 * Object group in TMX map
 * \else
 * TMX地图中的对象组
 * \endif
 */
public class TMXObjectGroup extends BaseWYObject {
	public static TMXObjectGroup from(int pointer) {
		return pointer == 0 ? null : new TMXObjectGroup(pointer);
	}
	
	protected TMXObjectGroup() {
		nativeInit();
	}
	
	protected TMXObjectGroup(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit();
	
	/**
	 * \if English
	 * Add property to object group
	 *
	 * @param key property name
	 * @param value property value
	 * \else
	 * 添加ObectGroup属性，如属性已存在，则不操作。
	 *
	 * @param key 属性名
	 * @param value 属性值
	 * \endif
	 */
	public native void addProperty(String key, String value);

	/**
	 * \if English
	 * Query property of object group
	 *
	 * @param name property name
	 * @return property value, or NULL if not found
	 * \else
	 * 查询ObectGroup的属性值
	 *
	 * @param name 属性名
	 * @return 返回属性名name的值，如无此属性则返回NULL。
	 * \endif
	 */
	public native String getProperty(String name);

	/**
	 * \if English
	 * Get object by name
	 *
	 * @param name object name
	 * @return {@link TMXObject}, or NULL if not found
	 * \else
	 * 根据名字获得ObectGroup的一个对象
	 *
	 * @param name 对象的名字
	 * @return {@link TMXObject}，如没找到则返回NULL。
	 * \endif
	 */
	public TMXObject getObject(String name) {
		return TMXObject.from(nativeGetObject(name));
	}
	
	private native int nativeGetObject(String name);
	
	/**
	 * \if English
	 * Get object at specified index. If an object doesn't have a name, we can get it
	 * by index. The index increases from zero and follow the order in TMX.
	 *
	 * @param index index of object
	 * @return {@link TMXObject}, or NULL if index is invalid
	 * \else
	 * 根据索引获得对象, 如果一个对象没有名字, 可以用这个方式得到对象. 对象的索引按照它们
	 * 在tmx中出现的顺序从0开始
	 *
	 * @param index 对象索引
	 * @return {@link TMXObject}, 如果索引不合法则返回NULL
	 * \endif
	 */
	public TMXObject getObjectAt(int index) {
		return TMXObject.from(nativeGetObjectAt(index));
	}

	private native int nativeGetObjectAt(int index);
	
	/**
	 * \if English
	 * Get object count in object group
	 *
	 * @return object count
	 * \else
	 * 得到对象的个数
	 *
	 * @return 对象个数
	 * \endif
	 */
	public native int getObjectCount();

	/**
	 * \if English
	 * Set object group name
	 *
	 * @param name name string, the string will be copied so it is safe to release it after method returns
	 * \else
	 * 设置对象组名称
	 *
	 * @param name 名称, 其内容会被拷贝, 因此setName返回后可以释放该指针
	 * \endif
	 */
	public native void setName(String name);

	/**
	 * \if English
	 * Get object group name
	 *
	 * @return name, caller should not release it
	 * \else
	 * 得到对象组名称
	 *
	 * @return 名称字符串, 调用者不需要释放
	 * \endif
	 */
	public native String getName();

	/**
	 * \if English
	 * Set offset x
	 *
	 * @param x x offset
	 * \else
	 * 设置对象组在地图中的像素偏移x值
	 *
	 * @param x x偏移值
	 * \endif
	 */
	public native void setOffsetX(float x);

	/**
	 * \if English
	 * Get offset x
	 *
	 * @return x offset
	 * \else
	 * 得到对象组在地图中的像素偏移x值
	 *
	 * @return x便宜值
	 * \endif
	 */
	public native float getOffsetX();

	/**
	 * \if English
	 * Set offset y
	 *
	 * @param y y offset
	 * \else
	 * 设置对象组在地图中的像素偏移y值
	 *
	 * @param y y偏移值
	 * \endif
	 */
	public native void setOffsetY(float y);

	/**
	 * \if English
	 * Get offset y
	 *
	 * @return y offset
	 * \else
	 * 得到对象组在地图中的像素偏移y值
	 *
	 * @return y便宜值
	 * \endif
	 */
	public native float getOffsetY();
	
	/**
	 * \if English
	 * Set color
	 *
	 * @param color color, format is 0xaarrggbb
	 * \else
	 * 设置颜色
	 *
	 * @param color 颜色值, 格式0xaarrggbb
	 * \endif
	 */
	public native void setColor(int color);

	/**
	 * \if English
	 * Get color
	 *
	 * @return color in 0xaarrggbb format
	 * \else
	 * 得到颜色属性
	 *
	 * @return 颜色
	 * \endif
	 */
	public native int getColor();

	/**
	 * \if English
	 * Get opacity
	 *
	 * @return opacity property of object group, from 0 to 1
	 * \else
	 * 得到透明度属性
	 *
	 * @return 透明度属性, 从0到1
	 * \endif
	 */
	public native float getOpacity();

	/**
	 * \if English
	 * Set opacity
	 *
	 * @param opacity opacity property, from 0 to 1
	 * \else
	 * 设置透明度属性
	 *
	 * @param opacity 透明度, 从0到1
	 * \endif
	 */
	public native void setOpacity(float opacity);
}
