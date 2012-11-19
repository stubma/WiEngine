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
#ifndef __wyHttpListener_h__
#define __wyHttpListener_h__

#include "wyNetworkConfig.h"

class wyHttpResponse;

/**
 * @class wyHttpListener
 *
 * Http event listener, used in asynchronous mode. All methods is executed
 * in GL thread
 */
class WINETWORK_API wyHttpListener {
public:
	/**
	 * Invoked when http get response from remote server
	 *
	 * @param response \link wyHttpResponse wyHttpResponse\endlink, this object
	 * 		is valid until \c onHttpFinishLoading or \c onHttpLoadingFailed
	 */
	virtual void onHttpReceiveResponse(wyHttpResponse* response) {}

	/**
	 * Invoked when body data segment is received
	 *
	 * @param buffer buffer of body data last received. Callback should not release
	 * 		this pointer. Data in this buffer will be overwrited before next time calling so
	 * 		you must copy it if you want to save it.
	 * @param length byte length in \c buffer
	 */
	virtual void onHttpReceiveData(const char* buffer, size_t length) {}

	/**
	 * Invoked when http loading is finished
	 *
	 * @param response response object. This object will be released after this callback returns.
	 * 		You must retain it if you want to keep it for later use
	 */
	virtual void onHttpFinishLoading(wyHttpResponse* response) {}

	/**
	 * Invoked when failed to load http request. This method will be invoked after
	 * \c onHttpReceiveResponse, and then you should not get \c onHttpReceiveData and
	 * \c onHttpFinishLoading callback.
	 *
	 * @param response response object. This object will be released after this callback returns.
	 * 		You must retain it if you want to keep it for later use
	 */
	virtual void onHttpLoadingFailed(wyHttpResponse* response) {}
};

#endif // __wyHttpListener_h__
