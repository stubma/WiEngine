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
 * \if English
 * Universal in-app purchase encapsulation. It abstracts general interface for
 * different in-app purchase platform so it can save effort when developing iap
 * module for a cross-platform game.
 *
 * \par
 * So wyIAP is just an interface and real implementation can be thought as
 * "backend". Every backend has a name, for example: "App Store" is the name of
 * iOS IAP backend.
 * \else
 * 统一的应用内支付接口定义. 其对不同的支付实现进行封装, 抽象出一些通用的接口方法来简化
 * 应用内支付的跨平台开发. 当然由于进行了一定程度的再封装, 可能对于某个平台的特有功能
 * 会不支持, 但是对于最普遍的情况, 使用wyIAP可以节省支付代码的平台迁移工作量.
 *
 * \par
 * 一种支付平台在这里称为wyIAP的后端, 都有一个名称, 比如苹果的实现就叫做"App Store",
 * wyIAP使用这些名称表示特定的后端, 可以查询某个后端是否可用, 甚至随时切换到另外的后端.
 * \endif
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
	 * \if English
	 * Register a payment backend in wyIAP
	 *
	 * @param subclass of \link wyIAPBackend wyIAPBackend\endlink
	 * \else
	 * 在wyIAP中注册一个IAP后端实现
	 *
	 * @param backend \link wyIAPBackend wyIAPBackend\endlink的子类
	 * \endif
	 */
	void registerBackend(wyIAPBackend* backend);

	/**
	 * \if English
	 * Get active backend, or NULL if no active backend set
	 *
	 * @return \link wyIAPBackend wyIAPBackend\endlink subclass
	 * \else
	 * 得到当前的后端, 如果没有设置当前后端, 返回NULL
	 *
	 * @return \link wyIAPBackend wyIAPBackend\endlink子类
	 * \endif
	 */
	wyIAPBackend* getActiveBackend() { return m_activeBackend; }

	/**
	 * \if English
	 * Check whether a payment backend is available for IAP
	 *
	 * @param name name of backend
	 * \else
	 * 检查当前的运行环境中是否可以使用某个后端IAP实现. 这不光要求后端实现是存在的, 同时
	 * 也会通知后端进行必要的检查以决定当前的系统环境是否可以进行IAP.
	 *
	 * @param name 后端实现的名称
	 * \endif
	 */
	bool isBackendAvailable(const char* name);

	/**
	 * \if English
	 * Enable one backend as current backend to be used to perform IAP.
	 * If backend is not found, then do nothing
	 *
	 * @param name name of backend to be enabled.
	 * \else
	 * 使某个后端称为当前后端, 后面的支付操作都通过这个后端进行. 如果指定名称的后端没有找到,
	 * 则不做任何事
	 *
	 * @param name 后端的名称
	 * \endif
	 */
	void enableBackend(const char* name);
	
	/**
	 * \if English
	 * Add listener of IAP event
	 * 
	 * @param l listener object which implement \link wyIAPListener wyIAPListener\endlink interface
	 * \else
	 * 添加一个IAP事件监听器
	 *
	 * @param l 实现了\link wyIAPListener wyIAPListener\endlink接口的IAP事件监听器类
	 * \endif
	 */
	void addListener(wyIAPListener* l);
	
	/**
	 * \if English
	 * Remove listener of IAP event
	 * 
	 * @param l listener object which implement \link wyIAPListener wyIAPListener\endlink interface
	 * \else
	 * 删除一个IAP事件监听器
	 *
	 * @param l 实现了\link wyIAPListener wyIAPListener\endlink接口的IAP事件监听器类
	 * \endif
	 */
	void removeListener(wyIAPListener* l);
	
	/**
	 * \if English
	 * Get IAP listener vector
	 * 
	 * @return vector of all IAP listeners
	 * \else
	 * 得到IAP监听器列表
	 *
	 * @return IAP事件监听器列表
	 * \endif
	 */
	vector<wyIAPListener*>* getListeners() { return m_listeners; }
	
	/**
	 * \if English
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
	 * \else
	 * 配置后端. 这个方法依赖于后端具体的实现, 不同的后端可能接受不同的参数, 你需要自己确定传入的
	 * 参数对当前后端是有效的. 这个方法必须在enableBackend之后调用.
	 *
	 * \par
	 * Android Market后端可以指定public_key参数
	 *
	 * \par
	 * App Store后端不需要任何参数
	 *
	 * @param key 参数的键
	 * @param value 参数的值
	 * \endif
	 */
	void configBackend(const char* key, const char* value);

	/**
	 * \if English
	 * Buy a product, can specify quantity if not one
	 *
	 * @param productId product unique identifier
	 * @param quantity quantity to buy, default is 1
	 * \else
	 * 购买一个物品
	 *
	 * @param productId 物品的唯一标识符
	 * @param quantity 购买的数量, 缺省是1
	 * \endif
	 */
	void buy(const char* productId, int quantity = 1);
    
    /**
     * \if English
     * Restore products which are bought already. It can't work for
     * consumable product
     * \else
     * 请求获得之前已经购买过的道具信息. 对于消耗性道具这没有用处
     * \endif
     */
    void restoreTransactions();
    
    /**
     * \if English
     * Verify a receipt data of a transaction
     * 
     * @param pid product identifier
     * @param receipt data of receipt, its format may dependent backend implementation
     * @param length byte length of \c receipt
     * @param sandbox true means verify receipt in sandbox mode
     * \else
     * 校验一次交易的发票数据
     * 
     * @param pid 物品标识符
     * @param receipt 发票数据, 其具体格式依赖于具体的后端实现
     * @param length \c receipt的字节长度
     * @param sandbox true表示进行调试性质的验证
     * \endif
     */
    void verifyTransaction(const char* pid, const void* receipt, size_t length, bool sandbox = false);
};

#endif // __wyIAP_h__
