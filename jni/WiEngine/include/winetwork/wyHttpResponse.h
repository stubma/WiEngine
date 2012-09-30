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
#ifndef __wyHttpResponse_h__
#define __wyHttpResponse_h__

#include "wyNetworkConfig.h"
#include "wyMemoryOutputStream.h"
#include <sys/types.h>

class wyHttpRequest;

/**
 * @class wyHttpResponse
 *
 * \if English
 * Http response
 * \else
 * HTTP响应类
 * \endif
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
	 * \if English
	 * Set related request object, internal used only
	 * \else
	 * 设置相关的请求对象, 仅内部使用
	 * \endif
	 */
	void setRequest(wyHttpRequest* request);

	/**
	 * \if English
	 * Get related request object
	 * \else
	 * 得到这个响应相关的请求对象
	 * \endif
	 */
	wyHttpRequest* getRequest() { return m_request; }

	/**
	 * \if English
	 * Get returned http header, it only returns first matched header
	 *
	 * @param name header name
	 * @return header string value, caller should release it. NULL returns if not found
	 * \else
	 * 得到http头, 只会返回第一个匹配的头
	 *
	 * @param name 头名称
	 * @return http头的字符串值, 调用者要负责释放. 如果没有找到, 返回NULL
	 * \endif
	 */
	virtual const char* getHeader(const char* name) = 0;

	/**
	 * \if English
	 * Get status code
	 * \else
	 * 得到状态码
	 * \endif
	 */
	virtual int getStatusCode() = 0;

	/**
	 * \if English
	 * Get response body. If this response is a result of synchronously executed
	 * http request, then the body should be fully loaded. If you execute request
	 * asynchronously, you should call \c read and then \c getBody will return bytes
	 * read by last \c read calling. Next \c read calling will overwrite buffer data.
	 *
	 * @return body data buffer. caller should not release it. If caller want to save
	 * 		the data, must copy it.
	 * \else
	 * 得到响应的包体内容, 如果这个响应是通过同步执行得到的, 则所有的包体应该都已经读完. 如果
	 * 你是异步执行请求, 则这个方法只返回上一次\c read调用读取的内容, 下次\c read会冲掉缓冲区的
	 * 内容
	 *
	 * @return 包体数据缓冲区, 调用者不需要释放. 如果需要保留数据, 调用者需要拷贝内容
	 * \endif
	 */
	virtual const char* getBody();

	/**
	 * \if English
	 * Returns length of body read by last \c read calling
	 * \else
	 * 返回上一次\c read操作读取到的包体的字节数
	 * \endif
	 */
	virtual size_t getBodyLength();
};

#endif // __wyHttpResponse_h__
