/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wyLayer_h__
#define __wyLayer_h__

#include "wyNode.h"

/**
 * @class wyLayer
 *
 * \if English
 * Layer is a container for other nodes. Its size by default is set
 * to surface view size and relativeAnchorPoint flag is false
 * \else
 * 层的封装, 层的缺省大小是和屏幕一样大，且relativeAnchorPoint标志
 * 缺省是false
 * \endif
 */
class WIENGINE_API wyLayer : public wyNode {
public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 * \else
	 * 静态构造函数
	 * \endif
	 */
	static wyLayer* make();

	/**
	 * \if English
	 * constructor
	 * \else
	 * 构造函数
	 * \endif
	 */
	wyLayer();

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyLayer();
};

#endif // __wyLayer_h__
