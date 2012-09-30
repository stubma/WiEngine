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
 * \if English
 * Callback definition of IAP process
 * \else
 * IAP过程的回调定义
 * \endif
 */
class IAP_API wyIAPListener {
public:
    /**
     * \if English
     * Error code for IAP event
     * \else
     * IAP回调中的错误代码定义
     * \endif
     */
    enum Error {
        /**
         * \if English
         * no error
         * \else
         * 没有错误
         * \endif
         */
        E_OK, 
        
        /**
         * \if English
         * General error
         * \else
         * 其他错误代码描述不了的一般性错误
         * \endif
         */
        E_GENERAL,
        
        /**
         * \if English
         * Backend can't support IAP now
         * \else
         * 当前后端服务不可用
         * \endif
         */
        E_SERVICE_UNAVAILABLE,

        /**
         * \if English
         * IAP is not enabled for current user
         * \else
         * 当前用户账号没有使用IAP的权限
         * \endif
         */
        E_USER_NOT_AUTHORIZED,
        
        /**
         * \if English
         * Can't find info of product user want to buy
         * \else
         * 找不到要购买的物品信息
         * \endif
         */
        E_NO_PRODUCT,

        /**
         * \if English
         * User cancelled
         * \else
         * 用户取消了购买操作
         * \endif
         */
        E_CANCELLED
    };
    
public:
	/**
	 * \if English
	 * Invoked when product is failed to be purchased
	 *
	 * @param pid product identifier
     * @param code error code
     * @param errorMsg error message, but may be NULL
	 * \else
	 * 当物品购买失败时被调用
	 * 
	 * @param pid 物品标识符
     * @param code 错误代码
     * @param errorMsg 错误消息, 可能为NULL
	 * \endif
	 */
	virtual void onBuyProductFailed(const char* pid, Error code, const char* errorMsg) {}
    
    /**
     * \if English
     * Invoked when product is purchased successfully
     * 
     * @param pid product identifier
     * @param receipt data of receipt, its format may dependent on backend implementation. If
     *      you are not sure what format it is, the best way to verify is calling \c verify method
     *      of \link wyIAP wyIAP\endlink. The data is hold by WiEngine so you must copy it if you
     *      want to keep it for later use
     * @param length byte length of \c receipt
     * \else
     * 物品购买成功后调用
     * 
     * @param pid 物品标识符
     * @param receipt 本次购买的发票信息, 它的具体格式可能依赖于后端. 如果你确定知道其格
     *      式, 可以自己校验, 但是校验过程显然不是平台可移植的, 因此如无特别必要, 推荐使
     *      用\link wyIAP wyIAP\endlink的\c verify方法进行校验. 该数据由WiEngine内部
     *      负责释放, 如果需要保存发票数据后面使用, 必须拷贝一份.
     * @param length \c receipt数据的字节长度
     * \endif
     */
    virtual void onBuyProductOK(const char* pid, const void* receipt, size_t length) {}
    
    /**
     * \if English
     * Invoked when a product is refunded by user. Some backend may not trigger this callback.
     *
     * @param pid product idenifier
     * @param receipt data of receipt, its format may dependent on backend implementation. If
     *      you are not sure what format it is, the best way to verify is calling \c verify method
     *      of \link wyIAP wyIAP\endlink. The data is hold by WiEngine so you must copy it if you
     *      want to keep it for later use
     * @param length byte length of \c receipt
     * \else
     * 当用户对某个产品申请了退款时, 这个方法被触发. 不过有些后端也许不支持这个回调, 比如App Store没有此类回调
     *
     * @param pid 物品标识符
     * @param receipt 发票信息, 它的具体格式可能依赖于后端. 如果你确定知道其格
     *      式, 可以自己校验, 但是校验过程显然不是平台可移植的, 因此如无特别必要, 推荐使
     *      用\link wyIAP wyIAP\endlink的\c verify方法进行校验. 该数据由WiEngine内部
     *      负责释放, 如果需要保存发票数据后面使用, 必须拷贝一份.
     * @param length \c receipt数据的字节长度
     * \endif
     */
    virtual void onBuyProductRefunded(const char* pid, const void* receipt, size_t length) {}

    /**
     * \if English
     * Invoked when user buy a product but that product was purchased already
     *
     * @param pid product identifier
     * @param receipt data of receipt, its format may dependent on backend implementation. If
     *      you are not sure what format it is, the best way to verify is calling \c verify method
     *      of \link wyIAP wyIAP\endlink. The data is hold by WiEngine so you must copy it if you
     *      want to keep it for later use
     * @param length byte length of \c receipt
     * \else
     * 当用户购买一个物品, 但是该物品用户之前已经买过时, 该方法被调用.
     *
     * @param pid 物品标识符
     * @param receipt 本次购买的发票信息, 它的具体格式可能依赖于后端. 如果你确定知道其格
     *      式, 可以自己校验, 但是校验过程显然不是平台可移植的, 因此如无特别必要, 推荐使
     *      用\link wyIAP wyIAP\endlink的\c verify方法进行校验. 该数据由WiEngine内部
     *      负责释放, 如果需要保存发票数据后面使用, 必须拷贝一份.
     * @param length \c receipt数据的字节长度
     * \endif
     */
    virtual void onBuyProductRestored(const char* pid, const void* receipt, size_t length) {}
    
    /**
     * \if English
     * Invoked when failed to verify receipt data
     *
     * @param pid product identifier
     * @param code error code
     * @param errorMsg error message, may be NULL
     * \else
     * 校验发票数据失败时调用
     * 
     * @param pid 物品标识符
     * @param code 错误代码
     * @param errorMsg 错误消息, 可能为NULL
     * \endif
     */
    virtual void onVerifyReceiptFailed(const char* pid, Error code, const char* errorMsg) {}
    
    /**
     * \if English
     * Invoked when receipt is verified OK
     * 
     * @param pid product identifier
     * \else
     * 当发票校验有效后调用
     *
     * @param pid 物品标识符
     * \endif
     */
    virtual void onVerifyReceiptOK(const char* pid) {}
};

#endif // __wyIAPListener_h__
