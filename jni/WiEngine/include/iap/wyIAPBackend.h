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
#ifndef __wyIAPBackend_h__
#define __wyIAPBackend_h__

#include "wyObject.h"
#include "wyIAPListener.h"
#include "wyIAPConfig.h"

/**
 * @class wyIAPBackend
 *
 * Backend base class
 */
class IAP_API wyIAPBackend : public wyObject {
protected:
	wyIAPBackend();
	
public:
	virtual ~wyIAPBackend();

	/**
	 * Is backend available for payment
	 *
	 * @return true means this backend can be used to IAP
	 */
	virtual bool isAvailable() = 0;

	/**
	 * Buy a product, can specify quantity if not one
	 *
	 * @param productId product unique identifier
	 * @param quantity quantity to buy, default is 1
	 */
	virtual void buy(const char* productId, int quantity = 1) = 0;
    
    /**
     * Restore products which are bought already. It can't work for
     * consumable product
     */
    virtual void restoreTransactions() = 0;
    
    /**
     * Verify a receipt data of a transaction
     * 
     * @param pid product identifier
     * @param receipt data of receipt, its format may dependent backend implementation
     * @param length byte length of \c receipt
     * @param sandbox true means verify receipt in sandbox mode
     */
    virtual void verifyTransaction(const char* pid, const void* receipt, size_t length, bool sandbox = false) = 0;

	/**
	 * Config backend. It depends on backend so you must ensure current backend
	 * understand those parameters you sent. This method must be called after
	 * \c enableBackend
	 *
	 * \par
	 * For android market backend, parameter can be:
	 * \c public_key: used to secure the transaction
	 *
	 * \par
	 * For app store backend, no parameter can be set
	 *
	 * @param key parameter key
	 * @param value parameter value
	 */
	virtual void config(const char* key, const char* value) = 0;

	/// notify IAP listener
	void notifyOnBuyProductFailed(const char* pid, wyIAPListener::Error code, const char* errorMsg);
    void notifyOnBuyProductOK(const char* pid, const void* receipt, size_t length);
    void notifyOnBuyProductRefunded(const char* pid, const void* receipt, size_t length);
    void notifyOnBuyProductRestored(const char* pid, const void* receipt, size_t length);
    void notifyOnVerifyReceiptFailed(const char* pid, wyIAPListener::Error code, const char* errorMsg);
    void notifyOnVerifyReceiptOK(const char* pid);
};

#endif // __wyIAPBackend_h__
