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
 * Http request
 */
class WINETWORK_API wyHttpRequest : public wyObject {
public:
	/**
	 * Http method
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
	 * Static creator
	 *
	 * @param url url
	 * @param method optional, default is GET
	 * @return http request object
	 */
	static wyHttpRequest* make(const char* url, Method method = GET);

	/**
	 * Set HTTP method
	 */
	void setMethod(Method m) { m_method = m; }

	/**
	 * Get HTTP method
	 */
	Method getMethod() { return m_method; }

	/**
	 * Add a string parameter to http request
	 *
	 * @param key parameter key, it will be copied so you can release it after returns
	 * @param value parameter value C string, in utf-8 encoding, it will be copied
	 * 		so you can release it after returns
	 */
	void addParameter(const char* key, const char* value);

	/**
	 * Add a blob parameter to http request
	 *
	 * @param key parameter key, it will be copied so you can release it after returns
	 * @param blob raw data, it will be copied so you can release it after returns
	 * @param length byte length of \c blob
	 */
	void addParameter(const char* key, const char* blob, size_t length);

	/**
	 * Add a header to http request
	 *
	 * @param key header name, it will be copied so you can release it after returns
	 * @param value header value, it will be copied so you can release it after returns
	 */
	void addHeader(const char* key, const char* value);

	/**
	 * Set http connection timeout time in milliseconds. If not set, default
	 * timeout is 30 seconds
	 */
	void setTimeout(int timeout) { m_timeout = timeout; }

	/**
	 * Get http connection timeout time in miiliseconds
	 */
	int getTimeout() { return m_timeout; }

	/**
	 * Execute this request synchronously, and returns a http response object
	 *
	 * @return \link wyHttpResponse wyHttpResponse\endlink
	 */
	virtual wyHttpResponse* syncExec() = 0;

	/**
	 * Execute this request asynchronously, it returns immediately and http event is sent
	 * to callback passed in
	 *
	 * @param listener http event call, default is NULL. NULL means you don't want know those events
	 */
	virtual void asyncExec(wyHttpListener* listener = NULL) = 0;

	/**
	 * Cancel an asynchronous request
	 */
	void cancel() { m_cancelled = true; }

	/**
	 * Is this request cancelled?
	 */
	bool isCancelled() { return m_cancelled; }
};

#endif // __wyHttpRequest_h__
