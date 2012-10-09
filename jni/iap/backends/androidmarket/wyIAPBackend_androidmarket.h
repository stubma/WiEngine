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

#ifndef __wyIAPBackend_androidmarket_h__
#define __wyIAPBackend_androidmarket_h__

#include "wyIAPBackend.h"

/**
 * @class wyIAPBackend_androidmarket
 *
 * Implemention of Android Market IAP
 */
class wyIAPBackend_androidmarket : public wyIAPBackend {
public:
	/// receipt data for android market IAP
	struct Receipt {
		const char* pid;
		const char* signedData;
		const char* signature;
	};

private:
	/// billing service object in java side
	jobject m_billingService;

protected:
	wyIAPBackend_androidmarket();

public:
	virtual ~wyIAPBackend_androidmarket();
	static wyIAPBackend_androidmarket* make();

	/// @see wyIAPBackend::isAvailable
	virtual bool isAvailable();

	/// @see wyIAPBackend::buy
	virtual void buy(const char* productId, int quantity = 1);
    
    /// @see wyIAPBackend::restoreTransactions
    virtual void restoreTransactions();
    
    /// @see wyIAPBackend::verifyTransaction
    virtual void verifyTransaction(const char* pid, const void* receipt, size_t length, bool sandbox = false);

    /// @see wyIAPBackend::config
    virtual void config(const char* key, const char* value);
};

#endif // __wyIAPBackend_androidmarket_h__

#endif // #if ANDROID
