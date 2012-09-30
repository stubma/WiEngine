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

#if ANDROID

#ifndef __wyHttpResponse_android_h__
#define __wyHttpResponse_android_h__

#include "wyHttpResponse.h"
#include <jni.h>

/**
 * @class wyHttpResponse_android
 *
 * http response implementation for android
 */
class wyHttpResponse_android : public wyHttpResponse {
private:
	/// http response in java side
	jobject m_jResponse;

	/// content stream
	jobject m_jContentStream;

protected:
	wyHttpResponse_android(jobject response);

public:
	virtual ~wyHttpResponse_android();

	/**
	 * Create android http response object from a java side
	 * http response
	 */
	static wyHttpResponse_android* make(jobject response);

	/// @see wyHttpResponse::getHeader
	virtual const char* getHeader(const char* name);

	/// @see wyHttpResponse::getStatusCode
	virtual int getStatusCode();

	/**
	 * Read response body content. Read data will be saved in body buffer and you
	 * can retrieve it by \c getBody
	 *
	 * @param max max read byte
	 * @return actual read byte, or -1 means end is reached, -2 means error
	 */
	ssize_t read(size_t max);

	/// get body memory buffer
	wyMemoryOutputStream* getBodyStream() { return m_body; }
};

#endif // __wyHttpResponse_android_h__

#endif // #if ANDROID
