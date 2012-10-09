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
#ifndef __wyJavaResourceDecoder_h__
#define __wyJavaResourceDecoder_h__

#if ANDROID

#include "wyResourceDecoder.h"
#include <jni.h>

/**
 * @class wyJavaResourceDecoder
 *
 * \if English
 * This class is just a wrapper of java side resource decoder
 * \else
 * 用于支持Java端实现资源解码器
 * \endif
 */
class wyJavaResourceDecoder : public wyResourceDecoder {
private:
	jobject m_jDecoder;

protected:
	wyJavaResourceDecoder(jobject decoder);

public:
	virtual ~wyJavaResourceDecoder();

	/**
	 * \if English
	 * Create resource decoder which call back to java layer
	 *
	 * @param decoder java side decoder implementation
	 * @return \link wyJavaResourceDecoder wyJavaResourceDecoder\endlink
	 * \else
	 * 创建一个资源解码器, 这个解码器其实是调用java端的实现
	 *
	 * @param decoder java端解码器实现
	 * @return \link wyJavaResourceDecoder wyJavaResourceDecoder\endlink
	 * \endif
	 */
	static wyJavaResourceDecoder* make(jobject decoder);

	/// @see wyResourceDecoder::decode
	virtual const char* decode(const char* data, size_t length, size_t* outLen);
};

#endif // #if ANDROID

#endif // __wyJavaResourceDecoder_h__
