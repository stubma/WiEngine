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
#ifndef __wyBuildConfig_h__
#define __wyBuildConfig_h__

/**
 * define this macro to enable memory tracing feature, that will help you
 * debug memory release problem. when not needed, comment it
 */
#define WY_CFLAG_MEMORY_TRACKING

/**
 * optimize math operation, when not needed, comment it
 */
#define WY_CFLAG_OPTIMIZE_MATH

/**
 * This macro enable screenshot mode. It will run game in 60 fps
 * and save every frame in sd card, of course it will slow down game
 * speed.
 *
 * What you should do:
 * 1. sd card is available
 * 2. uncomment this definition
 * 3. re-compile WiEngine and re-compile your game
 * 4. run you game
 * 5. find screenshot in /sdcard/WiEngine folder. for other platform, the path will be mapped.
 */
//#define WY_CFLAG_SCREENSHOT_MODE

#endif // __wyBuildConfig_h__
