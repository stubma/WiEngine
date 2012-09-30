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
package com.wiyun.engine.utils;

import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;

/**
 * A helper class for convert value based on current display resultions
 */
public class ResolutionIndependent {
	/**
	 * Convert a point to current resolution
	 * 
	 * @param p {@link WYPoint} object, the point object should use 160dpi value and its unit is
	 * 		assumed as DIP
	 * @return converted point object, actually it is same as point passed in
	 */
	public static WYPoint resolve(WYPoint p) {
		p.x = resolveDp(p.x);
		p.y = resolveDp(p.y);
		return p;
	}
	
	/**
	 * Convert a point to current resolution
	 * 
	 * @param s {@link WYSize} object, the size object should use 160dpi value and its unit is
	 * 		assumed as DIP
	 * @return converted size object, actually it is same as size passed in
	 */
	public static final WYSize resolve(WYSize s) {
		s.width = resolveDp(s.width);
		s.height = resolveDp(s.height);
		return s;
	}
	
	/**
	 * Convert a point to current resolution
	 * 
	 * @param r {@link WYRect} object, the rect object should use 160dpi value and its unit is
	 * 		assumed as DIP
	 * @return converted rect object, actually it is same as rect passed in
	 */
	public static WYRect resolve(WYRect r) {
		r.origin = resolve(r.origin);
		r.size = resolve(r.size);
		return r;
	}
	
	/**
	 * 把一个dp值转换为像素值
	 * 
	 * @param v dp值
	 * @return 像素值
	 */
	public native static float resolveDp(float v);
	
	/**
	 * 把一个sp值转换为像素值
	 * 
	 * @param v sp值
	 * @return 像素值
	 */
	public native static float resolveSp(float v);
}
