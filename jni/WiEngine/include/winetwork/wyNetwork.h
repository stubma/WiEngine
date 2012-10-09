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
#ifndef __wyNetwork_h__
#define __wyNetwork_h__

#include "wyNetworkConfig.h"

/**
 * @class wyNetwork
 *
 * \if English
 * Global utility class of WiNetwork module
 * \else
 * WiEngine网络模块中的一个全局工具类
 * \endif
 */
class WINETWORK_API wyNetwork {
private:
	/// is WiNetwork module inited?
	static bool s_inited;

public:
	/**
	 * \if English
	 * Network type definition
	 * \else
	 * 网络类型定义
	 * \endif
	 */
	enum NetworkType {
		/**
		 * \if English
		 * No network available
		 * \else
		 * 没有可用网络
		 * \endif
		 */
		NONE,

		/**
		 * \if English
		 * Unknown network type
		 * \else
		 * 未知网络类型
		 * \endif
		 */
		UNKNOWN,

		/**
		 * \if English
		 * 2G network, gprs
		 * \else
		 * 2G网络, gprs
		 * \endif
		 */
		G2,

		/**
		 * \if English
		 * Edge network
		 * \else
		 * 2.5G, edge网络
		 * \endif
		 */
		EDGE,

		/**
		 * \if English
		 * 3G network
		 * \else
		 * 3G网络
		 * \endif
		 */
		G3,

		/**
		 * \if English
		 * WiFi network
		 * \else
		 * 无线网络
		 * \endif
		 */
		WIFI
	};

public:
	/**
	 * \if English
	 * Initialize network module
	 * \else
	 * 初始化网络模块
	 * \endif
	 */
	static void init();

	/**
	 * \if English
	 * Clean up network layer
	 * \else
	 * 清除网络模块, 释放资源
	 * \endif
	 */
	static void cleanup();

	/**
	 * \if English
	 * Get network type
	 * \else
	 * 得到可用的网络类型
	 * \endif
	 * \see wyNetwork::NetworkType
	 */
	static NetworkType getNetworkType();

	/**
	 * \if English
	 * A quick shortcut for getNetworkType() return result checking
	 * \else
	 * 一个简单的方法, 专门用来判断当前是否已经有WiFi连接. 实际上调用的是\c getNetworkType
	 * \endif
	 */
	static bool hasWifi() { return getNetworkType() == WIFI; }
};

#endif // __wyNetwork_h__
