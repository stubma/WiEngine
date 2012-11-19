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
#ifndef __wyDevice_h__
#define __wyDevice_h__

#include "wyGlobal.h"

/**
 * low resolution, 120 dpi
 */
#define DENSITY_LDPI 0.75f

/**
 * medium resolution, 160 dpi
 */
#define DENSITY_MDPI 1.f

/**
 * high resolution, 240 dpi
 */
#define DENSITY_HDPI 1.5f

/**
 * @typedef wyScaleMode
 *
 * Screen adaption mode constant
 */
typedef enum {
	/**
	 * Scale resource based on resource's density and screen's density. This is the
	 * default mode.
	 */
	SCALE_MODE_BY_DENSITY,

	/**
	 * \par
	 * Set a base size for game and engine will follow this size anywhere. A
	 * small base size will drop down image quality in large screen, and a large base
	 * size may consume more memory. So you should choose a best base size to fit as
	 * many screens as possible, meanwhile gaining acceptable image quality.
	 *
	 * \par
	 * Once base size mode is used, WiEngine will not auto scale images
	 */
	SCALE_MODE_BASE_SIZE_FIT_XY
} wyScaleMode;

/**
 * @class wyDevice
 *
 * Abstraction interface for a mobile equipment, it provides device level
 * API for upper layer
 */
class WIENGINE_API wyDevice {
public:
	/**
	 * Screen adaption mode
	 */
	static wyScaleMode scaleMode;

	/**
	 * Density of current screen
	 */
	static float density;

	/**
	 * Font ensity of current screen
	 */
	static float scaledDensity;

	/**
	 * Default input density of resources and it is only used when resource
	 * density can't be determined.
	 */
	static float defaultInDensity;

	/**
	 * System api level. For android, it is the number defined in BUILD.VERSION.SDK_INT.
	 * For iOS, the system version string "x.y" is converted in formula x * 100 + y
	 */
	static int apiLevel;

	/**
	 * Max texture size supported by this device
	 */
	static int maxTextureSize;

	/**
	 * base width, only used in base size mode
	 */
	static int baseWidth;

	/**
	 * base height, only used in base size mode
	 */
	static int baseHeight;

	/**
	 * the scale rate of base width and screen width
	 */
	static float baseScaleX;

	/**
	 * the scale rate of base height and screen height
	 */
	static float baseScaleY;

	/**
	 * \par
	 * Current window width in pixels
	 *
	 * \par
	 * If current mode is density mode, then it is width of surface view. However,
	 * surface view is not known until it is created so this field will be initialized
	 * as screen width.
	 *
	 * \par
	 * If current mode is base size mode, then it is base width user set
	 */
	static int winWidth;

	/**
	 * \par
	 * Current window height in pixels
	 *
	 * \par
	 * If current mode is density mode, then it is height of surface view. However,
	 * surface view is not known until it is created so this field will be initialized
	 * as screen height.
	 *
	 * \par
	 * If current mode is base size mode, then it is base height user set
	 */
	static int winHeight;

	/**
	 * The real height of surface view
	 */
	static int realWidth;

	/**
	 * The real height of surface view
	 */
	static int realHeight;
	
public:
	/**
	 * Get ISO 639-1 language code of current system language
	 *
	 * @return ISO 639-1 language code, caller should not release returned string
	 */
	static const char* getLanguage();

	/**
	 * Get ISO 3166-1 country code of current system country
	 *
	 * @return ISO 3166-1 country code, caller should not release returned string
	 */
	static const char* getCountry();

	/**
	 * Get an unique identifier which can represent this device
	 *
	 * \note
	 * in Android platform, you need add READ_PHONE_STATE and ACCESS_WIFI_STATE permission
	 * to make this method works
	 *
	 * @return unique identifier, caller should not release it. Returns NULL if can't get
	 */
	static const char* getDeviceId();

	/**
	 * Check whether this device has external storage available. If external
	 * storage is ready, then path likes "/sdcard/abc.png" should works.
	 *
	 * \note
	 * For iOS and Mac OS X, this always returns true
	 *
	 * @return true means external storage is available, false means not
	 */
	static bool hasExternalStorage();
};

#endif // __wyDevice_h__
