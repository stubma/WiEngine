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
#ifndef __wyMultiplexLayer_h__
#define __wyMultiplexLayer_h__

#include "wyLayer.h"
#include "wyArray.h"

/**
 * @class wyMultiplexLayer
 * \if English
 * a type of layer wrapping multiple layers
 * \else
 * 多显示层的封装
 * \endif
 */
class WIENGINE_API wyMultiplexLayer : public wyLayer {
protected:
	/**
	 * \if English
	 * array of layers, \link wyArray wyArray\endlink
	 * \else
	 * 显示层\link wyArray wyArray对象指针\endlink
	 * \endif
	 */
	wyArray* m_layers;

	/**
	 * \if English
	 * index of the laying being active
	 * \else
	 * 当前启用的显示层索引
	 * \endif
	 */
	int m_enabledLayer;

private:
	static bool releaseLayer(wyArray* arr, void* ptr, int index, void* data);

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 * \else
	 * 静态构造函数
	 * \endif
	 */
	static wyMultiplexLayer* make();

	/**
	 * \if English
	 * constructor
	 * \else
	 * 构造函数
	 * \endif
	 */
	wyMultiplexLayer();

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyMultiplexLayer();

	/**
	 * \if English
	 * add one layer
	 *
	 * @param layer \link wyLayer wyLayer\endlink
	 * \else
	 * 添加显示层
	 *
	 * @param layer 被添加的显示层\link wyLayer wyLayer对象指针\endlink
	 * \endif
	 */
	void addLayer(wyLayer* layer);

	/**
	 * \if English
	 * remove one layer
	 *
	 * @param index index of layer to be removed
	 * \else
	 * 根据索引删除显示层
	 *
	 * @param index 被删除的显示层索引
	 * \endif
	 */
	void removeLayer(int index);

	/**
	 * \if English
	 * set one layer to be displayed
	 *
	 * @param index index of the layer to be displayed
	 * \else
	 * 切换显示层
	 *
	 * @param index 启动的显示层索引
	 * \endif
	 */
	void switchTo(int index);

	/**
	 * \if English
	 * get the layer being displayed
	 *
	 * @return index of the layer being displayed
	 * \else
	 * 得到当前启用的显示层索引
	 *
	 * @return 当前启用的显示层索引
	 * \endif
	 */
	int getEnabledLayer() { return m_enabledLayer; }
};

#endif // __wyMultiplexLayer_h__
