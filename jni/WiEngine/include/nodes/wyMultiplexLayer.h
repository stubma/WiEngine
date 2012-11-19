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
#ifndef __wyMultiplexLayer_h__
#define __wyMultiplexLayer_h__

#include "wyLayer.h"
#include "wyArray.h"

/**
 * @class wyMultiplexLayer
 * a type of layer wrapping multiple layers
 */
class WIENGINE_API wyMultiplexLayer : public wyLayer {
protected:
	/**
	 * array of layers, \link wyArray wyArray\endlink
	 */
	wyArray* m_layers;

	/**
	 * index of the laying being active
	 */
	int m_enabledLayer;

private:
	static bool releaseLayer(wyArray* arr, void* ptr, int index, void* data);

public:
	/**
	 * factory function, used to create a new instance with autoRelease enabled
	 */
	static wyMultiplexLayer* make();

	/**
	 * constructor
	 */
	wyMultiplexLayer();

	/**
	 * destructor
	 */
	virtual ~wyMultiplexLayer();

	/**
	 * add one layer
	 *
	 * @param layer \link wyLayer wyLayer\endlink
	 */
	void addLayer(wyLayer* layer);

	/**
	 * remove one layer
	 *
	 * @param index index of layer to be removed
	 */
	void removeLayer(int index);

	/**
	 * set one layer to be displayed
	 *
	 * @param index index of the layer to be displayed
	 */
	void switchTo(int index);

	/**
	 * get the layer being displayed
	 *
	 * @return index of the layer being displayed
	 */
	int getEnabledLayer() { return m_enabledLayer; }
};

#endif // __wyMultiplexLayer_h__
