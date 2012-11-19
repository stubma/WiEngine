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
#ifndef __wyIAP_h__
#define __wyIAP_h__

#include "wyObject.h"
#include "wyIAPBackend.h"
#include "wyIAPListener.h"
#include "wyIAPConfig.h"

// supported backends name list
#define IAP_BACKEND_APP_STORE "App Store"
#define IAP_BACKEND_ANDROID_MARKET "Android Market"

/**
 * @class wyIAP
 *
 * Universal in-app purchase encapsulation. It abstracts general interface for
 * different in-app purchase platform so it can save effort when developing iap
 * module for a cross-platform game.
 *
 * \par
 * So wyIAP is just an interface and real implementation can be thought as
 * "backend". Every backend has a name, for example: "App Store" is the name of
 * iOS IAP backend.
 */
class IAP_API wyIAP : public wyObject {
private:
	/// all supported backend instance
	vector<wyIAPBackend*>* m_backends;

	/// active backend
	wyIAPBackend* m_activeBackend;
	
	/// IAP listener, wyIAP doesn't retain them
	vector<wyIAPListener*>* m_listeners;

protected:
	wyIAP();

public:
	virtual ~wyIAP();
	static wyIAP* getInstance();
	static wyIAP* getInstanceNoCreate();

	/**
	 * Register a payment backend in wyIAP
	 *
	 * @param subclass of \link wyIAPBackend wyIAPBackend\endlink
	 */
	void registerBackend(wyIAPBackend* backend);

	/**
	 * Get active backend, or NULL if no active backend set
	 *
	 * @return \link wyIAPBackend wyIAPBackend\endlink subclass
	 */
	wyIAPBackend* getActiveBackend() { return m_activeBackend; }

	/**
	 * Check whether a payment backend is available for IAP
	 *
	 * @param name name of backend
	 */
	bool isBackendAvailable(const char* name);

	/**
	 * Enable one backend as current backend to be used to perform IAP.
	 * If backend is not found, then do nothing
	 *
	 * @param name name of backend to be enabled.
	 */
	void enableBackend(const char* name);
	
	/**
	 * Add listener of IAP event
	 * 
	 * @param l listener object which implement \link wyIAPListener wyIAPListener\endlink interface
	 */
	void addListener(wyIAPListener* l);
	
	/**
	 * Remove listener of IAP event
	 * 
	 * @param l listener object which implement \link wyIAPListener wyIAPListener\endlink interface
	 */
	void removeListener(wyIAPListener* l);
	
	/**
	 * Get IAP listener vector
	 * 
	 * @return vector of all IAP listeners
	 */
	vector<wyIAPListener*>* getListeners() { return m_listeners; }
	
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
	void configBackend(const char* key, const char* value);

	/**
	 * Buy a product, can specify quantity if not one
	 *
	 * @param productId product unique identifier
	 * @param quantity quantity to buy, default is 1
	 */
	void buy(const char* productId, int quantity = 1);
    
    /**
     * Restore products which are bought already. It can't work for
     * consumable product
     */
    void restoreTransactions();
    
    /**
     * Verify a receipt data of a transaction
     * 
     * @param pid product identifier
     * @param receipt data of receipt, its format may dependent backend implementation
     * @param length byte length of \c receipt
     * @param sandbox true means verify receipt in sandbox mode
     */
    void verifyTransaction(const char* pid, const void* receipt, size_t length, bool sandbox = false);
};

#endif // __wyIAP_h__
