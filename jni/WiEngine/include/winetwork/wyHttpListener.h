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
 * \if English
 * Http event listener, used in asynchronous mode. All methods is executed
 * in GL thread
 * \else
 * Http事件监听器, 仅用于异步执行模式. 所有的方法都保证在GL线程里执行
 * \endif
 */
class WINETWORK_API wyHttpListener {
public:
	/**
	 * \if English
	 * Invoked when http get response from remote server
	 *
	 * @param response \link wyHttpResponse wyHttpResponse\endlink, this object
	 * 		is valid until \c onHttpFinishLoading or \c onHttpLoadingFailed
	 * \else
	 * 当远端服务器返回响应时调用
	 *
	 * @param response \link wyHttpResponse wyHttpResponse\endlink, 这个对象在成功或
	 * 		失败的回调事件之前都是有效的
	 * \endif
	 */
	virtual void onHttpReceiveResponse(wyHttpResponse* response) {}

	/**
	 * \if English
	 * Invoked when body data segment is received
	 *
	 * @param buffer buffer of body data last received. Callback should not release
	 * 		this pointer. Data in this buffer will be overwrited before next time calling so
	 * 		you must copy it if you want to save it.
	 * @param length byte length in \c buffer
	 * \else
	 * 当收到包体数据时被调用
	 *
	 * @param buffer 包体数据指针, 这里面的数据会在下次调用这个回调时被清除, 因此如果你要保存
	 * 		这些数据, 必须拷贝. 该指针不需要回调接受者负责释放.
	 * @param length \c buffer中的数据字节数
	 * \endif
	 */
	virtual void onHttpReceiveData(const char* buffer, size_t length) {}

	/**
	 * \if English
	 * Invoked when http loading is finished
	 *
	 * @param response response object. This object will be released after this callback returns.
	 * 		You must retain it if you want to keep it for later use
	 * \else
	 * 当然http请求完成时调用
	 *
	 * @param response 响应对象, 这个回调完成之后, 该对象会被释放. 如果你希望保留用作其它用途, 必须retain它
	 * \endif
	 */
	virtual void onHttpFinishLoading(wyHttpResponse* response) {}

	/**
	 * \if English
	 * Invoked when failed to load http request. This method will be invoked after
	 * \c onHttpReceiveResponse, and then you should not get \c onHttpReceiveData and
	 * \c onHttpFinishLoading callback.
	 *
	 * @param response response object. This object will be released after this callback returns.
	 * 		You must retain it if you want to keep it for later use
	 * \else
	 * 当http请求失败时调用. 这个调用会在\c onHttpReceiveResponse之后发生, 且你将不再收到
	 * \c onHttpReceiveData和\c onHttpFinishLoading回调
	 *
	 * @param response 响应对象, 这个回调完成之后, 该对象会被释放. 如果你希望保留用作其它用途, 必须retain它
	 * \endif
	 */
	virtual void onHttpLoadingFailed(wyHttpResponse* response) {}
};

#endif // __wyHttpListener_h__
