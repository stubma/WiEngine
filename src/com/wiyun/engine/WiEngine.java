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
package com.wiyun.engine;

import javax.microedition.khronos.opengles.GL10;

/**
 * \if English
 * some global constants
 * \else
 * 定义了一些全局常量
 * \endif
 */
public class WiEngine {
	/**
	 * \if English
	 * log tag for WiEngine
	 * \else
	 * WiEngine的log标记
	 * \endif
	 */
	public static final String LOG = "libwiengine";

	/**
	 * \if English
	 * trace flag, if set to true, more log is printed
	 * \else
	 * 调试标志
	 * \endif
	 */
	public static final boolean TRACE = false;
	
	/**
	 * \if English
	 * debug flag for output performance info
	 * \else
	 * 性能调试标志
	 * \endif
	 */
	public static final boolean LOG_PERFORMANCE = false;

	/**
	 * \if English
	 * Default source blending mode
	 * \else
	 * WiEngine缺省源渲染方式
	 * \endif
	 */
	public static final int DEFAULT_BLEND_SRC = GL10.GL_SRC_ALPHA;

	/**
	 * \if English
	 * Default target blending mode
	 * \else
	 * WiEngine缺省目标渲染方式
	 * \endif
	 */
	public static final int DEFAULT_BLEND_DST = GL10.GL_ONE_MINUS_SRC_ALPHA;
}