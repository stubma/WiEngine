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
#ifndef __wyIAPListener_h__
#define __wyIAPListener_h__

#include "wyIAPConfig.h"

/**
 * @class wyIAPListener
 *
 * Callback definition of IAP process
 */
class IAP_API wyIAPListener {
public:
    /**
     * Error code for IAP event
     */
    enum Error {
        /**
         * no error
         */
        E_OK, 
        
        /**
         * General error
         */
        E_GENERAL,
        
        /**
         * Backend can't support IAP now
         */
        E_SERVICE_UNAVAILABLE,

        /**
         * IAP is not enabled for current user
         */
        E_USER_NOT_AUTHORIZED,
        
        /**
         * Can't find info of product user want to buy
         */
        E_NO_PRODUCT,

        /**
         * User cancelled
         */
        E_CANCELLED
    };
    
public:
	/**
	 * Invoked when product is failed to be purchased
	 *
	 * @param pid product identifier
     * @param code error code
     * @param errorMsg error message, but may be NULL
	 */
	virtual void onBuyProductFailed(const char* pid, Error code, const char* errorMsg) {}
    
    /**
     * Invoked when product is purchased successfully
     * 
     * @param pid product identifier
     * @param receipt data of receipt, its format may dependent on backend implementation. If
     *      you are not sure what format it is, the best way to verify is calling \c verify method
     *      of \link wyIAP wyIAP\endlink. The data is hold by WiEngine so you must copy it if you
     *      want to keep it for later use
     * @param length byte length of \c receipt
     */
    virtual void onBuyProductOK(const char* pid, const void* receipt, size_t length) {}
    
    /**
     * Invoked when a product is refunded by user. Some backend may not trigger this callback.
     *
     * @param pid product idenifier
     * @param receipt data of receipt, its format may dependent on backend implementation. If
     *      you are not sure what format it is, the best way to verify is calling \c verify method
     *      of \link wyIAP wyIAP\endlink. The data is hold by WiEngine so you must copy it if you
     *      want to keep it for later use
     * @param length byte length of \c receipt
     */
    virtual void onBuyProductRefunded(const char* pid, const void* receipt, size_t length) {}

    /**
     * Invoked when user buy a product but that product was purchased already
     *
     * @param pid product identifier
     * @param receipt data of receipt, its format may dependent on backend implementation. If
     *      you are not sure what format it is, the best way to verify is calling \c verify method
     *      of \link wyIAP wyIAP\endlink. The data is hold by WiEngine so you must copy it if you
     *      want to keep it for later use
     * @param length byte length of \c receipt
     */
    virtual void onBuyProductRestored(const char* pid, const void* receipt, size_t length) {}
    
    /**
     * Invoked when failed to verify receipt data
     *
     * @param pid product identifier
     * @param code error code
     * @param errorMsg error message, may be NULL
     */
    virtual void onVerifyReceiptFailed(const char* pid, Error code, const char* errorMsg) {}
    
    /**
     * Invoked when receipt is verified OK
     * 
     * @param pid product identifier
     */
    virtual void onVerifyReceiptOK(const char* pid) {}
};

#endif // __wyIAPListener_h__
