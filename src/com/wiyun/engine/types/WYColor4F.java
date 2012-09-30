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

public class WYColor4F {
	public float r;
	public float g;
	public float b;
	public float a;
	
	public static WYColor4F make(float r, float g, float b, float a) {
		return new WYColor4F(r, g, b, a);
	}

	public WYColor4F() {
		r = g = b = a = 1.0f;
	}

	public WYColor4F(float rr, float gg, float bb, float aa) {
		r = rr;
		g = gg;
		b = bb;
		a = aa;
	}

	public WYColor4F(WYColor4F c) {
		r = c.r;
		g = c.g;
		b = c.b;
		a = c.a;
	}

	public WYColor4F(WYColor4B c) {
		r = c.r / 0xFF;
		g = c.g / 0xFF;
		b = c.b / 0xFF;
		a = c.a / 0xFF;
	}

	public WYColor4F(WYColor3B c) {
		r = c.r / 0xFF;
		g = c.g / 0xFF;
		b = c.b / 0xFF;
		a = 1.0f;
	}

	public float[] glFormat() {
		return new float[] {
				r, g, b, a
		};
	}

	@Override
	public String toString() {
		return "< r=" + r + ", g=" + g + ", b=" + b + ", a=" + a + " >";
	}
}
