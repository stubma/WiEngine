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
package com.wiyun.engine.types;


public class WYRect implements ICopyable {
    public WYPoint origin;
    public WYSize size;

    private WYRect() {
        this(0, 0, 0, 0);
    }
    
    private WYRect(final WYPoint origin, final WYSize size) {
        this(origin.x, origin.y, size.width, size.height);
    }
    
    /**
     * 创建一个空的矩形，参数都是0
     * 
     * @return {@link WYRect}
     */
    public static WYRect makeZero() {
    	return new WYRect();
    }

    public static WYRect make(final WYPoint origin, final WYSize size) {
        return new WYRect(origin.x, origin.y, size.width, size.height);
    }

    public static WYRect make(float x, float y, float w, float h) {
        return new WYRect(x, y, w, h);
    }

    private WYRect(float x, float y, float w, float h) {
        origin = WYPoint.make(x, y);
        size = WYSize.make(w, h);
    }
    
    public Object copy() {
    	return new WYRect(origin.x, origin.y, size.width, size.height);
    }
    
    /**
     * 判断当前矩形是否和另外一个矩形有交集。矩形的origin是在左下角。
     * 
     * @param r {@link WYPoint}，矩形的origin是在左下角。
     * @return true表示有交集
     */
    public boolean isIntersect(WYRect r) {
    	return isIntersect(r.origin.x, r.origin.y + r.size.height, r.origin.x + r.size.width, r.origin.y);
    }
    
	/**
	 * 判断当前矩形是否和另外一个矩形有交集。矩形的origin是在左下角。
	 * 
	 * @param l left
	 * @param t top
	 * @param r right
	 * @param b bottom
	 * @return true表示有交集
	 */
	public boolean isIntersect(float l, float t, float r, float b) {
		if(origin.x < r && l < origin.x + size.width && origin.y < t && b < origin.y + size.height) {
			return true;
		}

		return false;
	}

    @Override
	public String toString() {
        return "((" + origin.x + ", " + origin.y + "),(" + size.width + ", " + size.height + "))";
    }

    public boolean isEqualTo(WYRect r) {
        return WYPoint.isEqual(origin, r.origin) && WYSize.isEqual(size, r.size);
    }

    /**
     * 检查是否当前矩形包含了一个点，矩形的origin表示的是
     * 左下角
     * 
     * @param aPoint {@link WYPoint}
     * @return true表示当前矩形包含<code>aPoint</code>
     */
    public boolean containsPoint(WYPoint aPoint) {
    	return containsPoint(aPoint.x, aPoint.y);
    }
    
    /**
     * 检查是否当前矩形包含了一个点，矩形的origin表示的是
     * 左下角
     * 
	 * @param x 点的x位置
	 * @param y 点的y位置
     * @return true表示当前矩形包含指定
     */
	public boolean containsPoint(float x, float y) {
        return ((x >= minX())
                && (y >= minY())
                && (x < maxX())
                && (y < maxY()));
	}

    /**
     * 检查是否当前矩形包含了另外一个矩形，矩形的origin表示的是
     * 左下角
     * 
     * @param bRect {@link WYRect}
     * @return true表示当前矩形包含<code>bRect</code>
     */
    public boolean containsRect(WYRect bRect) {
        return (!bRect.isEmpty()
                && (minX() <= bRect.minX())
                && (minY() <= bRect.minY())
                && (maxX() >= bRect.maxX())
                && (maxY() >= bRect.maxY()));
    }
    
    public void applyTransform(WYAffineTransform transform) {
    	WYPoint other = WYPoint.make(origin.x + size.width, origin.y + size.height);
    	transform.transform(origin);
    	transform.transform(other);
    	size.width = other.x - origin.x;
    	size.height = other.y - origin.y;
    }
    
    /**
     * Returns the greatest x-coordinate value still inside aRect.
     */
    public float maxX() {
        return origin.x + size.width;
    }

    /**
     * Returns the greatest y-coordinate value still inside aRect.
     */
    public float maxY() {
        return origin.y + size.height;
    }

    /**
     * Returns the x-coordinate of aRect's middle point.
     */
    public float midX() {
        return origin.x + (float) (size.width / 2.0);
    }

    /**
     * Returns the y-coordinate of aRect's middle point.
     */
    public float midY() {
        return origin.y + (float) (size.height / 2.0);
    }

    /**
     * Returns the least x-coordinate value still inside aRect.
     */
    public float minX() {
        return origin.x;
    }

    /**
     * Returns the least y-coordinate value still inside aRect.
     */
    public float minY() {
        return origin.y;
    }

    public boolean isEmpty() {
        return (!(size.width > 0 && size.height > 0));
    }

    private enum Edge {
        MinXEdge,
        MinYEdge,
        MaxXEdge,
        MaxYEdge,
    }

    private static WYRect sRect = new WYRect();
    private static WYRect rRect = new WYRect();

    public void divideRect(WYRect[] slice, WYRect[] remainder, float amount, WYRect.Edge edge) {
        if (slice == null)
            slice = new WYRect[] { sRect };

        if (remainder == null)
            remainder = new WYRect[] { rRect };

        if (isEmpty()) {
            slice[0] = WYRect.make(0, 0, 0, 0);
            remainder[0] = WYRect.make(0, 0, 0, 0);
            return;
        }

        switch (edge) {
            case MinXEdge:
                if (amount > size.width) {
                    slice[0] = this;
                    remainder[0] = WYRect.make(maxX(),
                            origin.y,
                            0,
                            size.height);
                } else {
                    slice[0] = WYRect.make(origin.x,
                            origin.y,
                            amount,
                            size.height);
                    remainder[0] = WYRect.make(slice[0].maxX(),
                            origin.y,
                            maxX() - slice[0].maxX(),
                            size.height);
                }
                break;
            case MinYEdge:
                if (amount > size.height) {
                    slice[0] = this;
                    remainder[0] = WYRect.make(origin.x,
                            maxY(),
                            size.width, 0);
                } else {
                    slice[0] = WYRect.make(origin.x,
                            origin.y,
                            size.width,
                            amount);
                    remainder[0] = WYRect.make(origin.x,
                    		slice[0].maxY(),
                            size.width,
                            maxY() - slice[0].maxY());
                }
                break;
            case MaxXEdge:
                if (amount > size.width) {
                    slice[0] = this;
                    remainder[0] = WYRect.make(origin.x,
                            origin.y,
                            0,
                            size.height);
                } else {
                    slice[0] = WYRect.make(maxX() - amount,
                            origin.y,
                            amount,
                            size.height);
                    remainder[0] = WYRect.make(origin.x,
                            origin.y,
                            slice[0].minX() - origin.x,
                            size.height);
                }
                break;
            case MaxYEdge:
                if (amount > size.height) {
                    slice[0] = this;
                    remainder[0] = WYRect.make(origin.x,
                            origin.y,
                            size.width,
                            0);
                } else {
                    slice[0] = WYRect.make(origin.x,
                            maxY() - amount,
                            size.width,
                            amount);
                    remainder[0] = WYRect.make(origin.x,
                            origin.y,
                            size.width,
                            slice[0].minY() - origin.y);
                }
                break;
            default:
                break;
        }
    }
}
