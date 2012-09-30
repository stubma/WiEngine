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

/**
 * A 2D Quad. 8 floats
 */
public class WYQuad2D {
	public static final int GL_SIZE = 4 * 2 * 4;
	
	// bottom left
	public float bl_x, bl_y;
	
	// bottom right
	public float br_x, br_y;

	// top left
	public float tl_x, tl_y;
	
	// top right
	public float tr_x, tr_y;

	public WYQuad2D(float a, float b, float c, float d, float e, float f, float g, float h) {
		bl_x = a;
		bl_y = b;
		br_x = c;
		br_y = d;
		tl_x = e;
		tl_y = f;
		tr_x = g;
		tr_y = h;
	}

	public WYQuad2D() {
		this(new float[] {
				0, 0, 0, 0, 0, 0, 0, 0
		});
	}

	public WYQuad2D(float[] f) {
		this(f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
	}

	public float[] glFormat() {
		return new float[] {
				bl_x, bl_y, br_x, br_y, tl_x, tl_y, tr_x, tr_y
		};
	}

	@Override
	public String toString() {
		return "CCQuad2: ( " + tl_x + ", " + tl_y + " " + tr_x + ", " + tr_y + " " + bl_x + ", " + bl_y + " " + br_x + ", " + br_y + " )";
	}
}
