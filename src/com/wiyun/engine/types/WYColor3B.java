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

public class WYColor3B {
	public int r;
	public int g;
	public int b;
	
	public static WYColor3B make(int r, int g, int b) {
		return new WYColor3B(r, g, b);
	}

	public WYColor3B() {
		r = 0xff;
		g = 0xff;
		b = 0xff;
	}

	public WYColor3B(int rr, int gg, int bb) {
		r = rr;
		g = gg;
		b = bb;
	}

	public byte[] glFormat() {
		return new byte[] {
				(byte)r, (byte)g, (byte)b
		};
	}
	
	public WYColor4F toColor4F() {
		return new WYColor4F(r / 255f, g / 255f, b / 255f, 1f);
	}

	@Override
	public String toString() {
		return "< r=" + r + ", g=" + g + ", b=" + b + " >";
	}
}
