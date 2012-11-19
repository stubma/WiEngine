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
#ifndef __wyHttpResponse_h__
#define __wyHttpResponse_h__

#include "wyNetworkConfig.h"
#include "wyMemoryOutputStream.h"
#include <sys/types.h>

class wyHttpRequest;

/**
 * @class wyHttpResponse
 *
 * Http response
 */
class WINETWORK_API wyHttpResponse : public wyObject {
private:
	/// related http request
	wyHttpRequest* m_request;

protected:
	/// read buffer
	wyMemoryOutputStream* m_body;

protected:
	wyHttpResponse();

public:
	virtual ~wyHttpResponse();

	/**
	 * Set related request object, internal used only
	 */
	void setRequest(wyHttpRequest* request);

	/**
	 * Get related request object
	 */
	wyHttpRequest* getRequest() { return m_request; }

	/**
	 * Get returned http header, it only returns first matched header
	 *
	 * @param name header name
	 * @return header string value, caller should release it. NULL returns if not found
	 */
	virtual const char* getHeader(const char* name) = 0;

	/**
	 * Get status code
	 */
	virtual int getStatusCode() = 0;

	/**
	 * Get response body. If this response is a result of synchronously executed
	 * http request, then the body should be fully loaded. If you execute request
	 * asynchronously, you should call \c read and then \c getBody will return bytes
	 * read by last \c read calling. Next \c read calling will overwrite buffer data.
	 *
	 * @return body data buffer. caller should not release it. If caller want to save
	 * 		the data, must copy it.
	 */
	virtual const char* getBody();

	/**
	 * Returns length of body read by last \c read calling
	 */
	virtual size_t getBodyLength();
};

#endif // __wyHttpResponse_h__
