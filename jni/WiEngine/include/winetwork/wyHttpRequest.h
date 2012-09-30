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
#ifndef __wyHttpRequest_h__
#define __wyHttpRequest_h__

#include "wyNetworkConfig.h"
#include "wyObject.h"
#include "wyGlobal.h"
#include "wyHttpListener.h"

class wyHttpResponse;

/**
 * @class wyHttpRequest
 *
 * \if English
 * Http request
 * \else
 * HTTP请求类
 * \endif
 */
class WINETWORK_API wyHttpRequest : public wyObject {
public:
	/**
	 * \if English
	 * Http method
	 * \else
	 * HTTP方法
	 * \endif
	 */
	enum Method {
		GET,
		POST,
		DELETE,
		PUT
	};

protected:
	/// http request parameter
	struct Parameter {
		/// parameter key
		const char* key;

		/// parameter value
		const char* value;

		/// parameter value length in bytes
		size_t length;

		/// parameter is blob or c string?
		bool blob;
	};

	/// http header
	struct Header {
		const char* key;
		const char* value;
	};

protected:
	/// url
	const char* m_url;

	/// method
	Method m_method;

	/// parameters
	vector<Parameter>* m_parameters;

	/// customized headers
	vector<Header>* m_headers;

	/// connection timeout value in milliseconds, default is 30 seconds
	int m_timeout;

	/// cancelled flag
	bool m_cancelled;

private:
	/// release parameter
	static void releaseParameter(Parameter& p);

	/// release header
	static void releaseHeader(Header& h);

protected:
	/**
	 * Constructor
	 *
	 * @param url url
	 * @param method http method
	 */
	wyHttpRequest(const char* url, Method method);

	/**
	 * Build full url for get/delete method, returned string
	 * should be release by caller
	 */
	const char* buildQueryString();
    
    /// return true means has blob type parameter
	bool hasBlobParam();

public:
	virtual ~wyHttpRequest();

	/**
	 * \if English
	 * Static creator
	 *
	 * @param url url
	 * @param method optional, default is GET
	 * @return http request object
	 * \else
	 * 静态构造函数
	 *
	 * @param url 请求地址
	 * @param method HTTP方法, 缺省是GET
	 * @return HTTP请求对象
	 * \endif
	 */
	static wyHttpRequest* make(const char* url, Method method = GET);

	/**
	 * \if English
	 * Set HTTP method
	 * \else
	 * 设置http方法
	 * \endif
	 */
	void setMethod(Method m) { m_method = m; }

	/**
	 * \if English
	 * Get HTTP method
	 * \else
	 * 得到http方法
	 * \endif
	 */
	Method getMethod() { return m_method; }

	/**
	 * \if English
	 * Add a string parameter to http request
	 *
	 * @param key parameter key, it will be copied so you can release it after returns
	 * @param value parameter value C string, in utf-8 encoding, it will be copied
	 * 		so you can release it after returns
	 * \else
	 * 添加一个字符串形式的参数
	 *
	 * @param key 参数键值. 它的内容会被复制, 因此返回后可以释放
	 * @param value 参数字符串, 必须是utf-8编码. 它的内容会被复制, 因此返回后可以释放
	 * \endif
	 */
	void addParameter(const char* key, const char* value);

	/**
	 * \if English
	 * Add a blob parameter to http request
	 *
	 * @param key parameter key, it will be copied so you can release it after returns
	 * @param blob raw data, it will be copied so you can release it after returns
	 * @param length byte length of \c blob
	 * \else
	 * 添加一个二进制参数
	 *
	 * @param key 参数键值. 它的内容会被复制, 因此返回后可以释放
	 * @param blob 二进制数据. 它的内容会被复制, 因此返回后可以释放
	 * @param length \c blob的字节长度
	 * \endif
	 */
	void addParameter(const char* key, const char* blob, size_t length);

	/**
	 * \if English
	 * Add a header to http request
	 *
	 * @param key header name, it will be copied so you can release it after returns
	 * @param value header value, it will be copied so you can release it after returns
	 * \else
	 * 添加一个http头
	 *
	 * @param key http头名称. 它的内容会被复制, 因此返回后可以释放
	 * @param value http头数据. 它的内容会被复制, 因此返回后可以释放
	 * \endif
	 */
	void addHeader(const char* key, const char* value);

	/**
	 * \if English
	 * Set http connection timeout time in milliseconds. If not set, default
	 * timeout is 30 seconds
	 * \else
	 * 设置http连接超时时间, 单位是毫秒. 如果不设置, 缺省是30秒
	 * \endif
	 */
	void setTimeout(int timeout) { m_timeout = timeout; }

	/**
	 * \if English
	 * Get http connection timeout time in miiliseconds
	 * \else
	 * 得到http连接超时时间
	 * \endif
	 */
	int getTimeout() { return m_timeout; }

	/**
	 * \if English
	 * Execute this request synchronously, and returns a http response object
	 *
	 * @return \link wyHttpResponse wyHttpResponse\endlink
	 * \else
	 * 同步执行这个http请求, 并返回一个响应对象
	 *
	 * @return \link wyHttpResponse wyHttpResponse\endlink
	 * \endif
	 */
	virtual wyHttpResponse* syncExec() = 0;

	/**
	 * \if English
	 * Execute this request asynchronously, it returns immediately and http event is sent
	 * to callback passed in
	 *
	 * @param listener http event call, default is NULL. NULL means you don't want know those events
	 * \else
	 * 异步执行http请求, 方法会立刻返回, 之后的事件通过回调传递
	 *
	 * @param listener 回调事件监听器, 缺省为NULL, NULL表示不你不需要这些事件
	 * \endif
	 */
	virtual void asyncExec(wyHttpListener* listener = NULL) = 0;

	/**
	 * \if English
	 * Cancel an asynchronous request
	 * \else
	 * 取消一个异步的http请求
	 * \endif
	 */
	void cancel() { m_cancelled = true; }

	/**
	 * \if English
	 * Is this request cancelled?
	 * \else
	 * 这个请求是否已被取消
	 * \endif
	 */
	bool isCancelled() { return m_cancelled; }
};

#endif // __wyHttpRequest_h__
