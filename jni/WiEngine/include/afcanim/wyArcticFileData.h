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
#ifndef __wyArcticFileData_h__
#define __wyArcticFileData_h__

#include "wyAFCFileData.h"
#include "wyTypes.h"

class wyArcticLoader;
class wyArcticManager;

/**
 * @struct wyArcticModule
 *
 * module info of arctic sprite
 */
typedef struct wyArcticModule {
	/**
	 * image index
	 */
	int imageIndex;

	/**
	 * tile image x position in atlas
	 */
	short x;

	/**
	 * tile image y position in atlas
	 */
	short y;

	/**
	 * tile image width in atlas
	 */
	short w;

	/**
	 * tile image height in atlas
	 */
	short h;
} wyArcticModule;

/**
 * @struct wyArcticFrameModule
 *
 * frame module info
 */
typedef struct wyArcticFrameModule {
	/**
	 * index of module
	 */
	short index;

	/**
	 * module x position in frame
	 */
	short x;

	/**
	 * module y position in frame
	 */
	short y;

	/**
	 * module flag, bits 6, 7 are extension for module index
	 */
	unsigned char flags;
} wyArcticFrameModule;

/**
 * @struct wyArcticFrame
 *
 * frame info in arctic file
 */
typedef struct wyArcticFrame {
	/**
	 * module count in frame
	 */
	short moduleCount;

	/**
	 * index of first module. The index indicates data position in \c m_frameModules
	 * of \link wyArcticFileData wyArcticFileData\endlink
	 */
	short firstModuleIndex;
	
	/**
	 * count of collision rect belongs to this frame
	 */
	short collisionRectCount;
	
	/**
	 * buffer of collision rects, the (x, y) is top left corner
	 */
	wyRect* collisionRects;
} wyArcticFrame;

/**
 * @typedef wyArcticAnimationFrame
 *
 * \if Enlgish
 * info of frame in an animation
 */
typedef struct wyArcticAnimationFrame {
	/**
	 * index of frame
	 */
	short index;

	/**
	 * delay time of this frame, it is not a normal time value and it is
	 * very similar with motion welder. So actually we need set an unit
	 * interval to evaluate final time
	 */
	short delay;

	/**
	 * x offset of frame
	 */
	short offsetX;

	/**
	 * y offset of frame. Y axis of arctic is reversed to opengl, so need negate it
	 * when calculate AFC frame offset
	 */
	short offsetY;

	/**
	 * flags of frame, bits 6, 7 are extension for frame index
	 */
	unsigned char flags;
} wyArcticAnimationFrame;

/**
 * info of arctic animation
 */
typedef struct wyArcticAnimation {
	/**
	 * frame count in this animation
	 */
	short frameCount;

	/**
	 * index of first frame in animation frames list. The index indicates data position in
	 * \c m_animationFrames of \link wyArcticFileData wyArcticFileData\endlink
	 */
	short firstFrameIndex;
} wyArcticAnimation;

/**
 * @class wyArcticFileData
 *
 * File data object for Arctic editor. It uses little endian byte order. In ASprite,
 * positive direction of x axis is right, positive of y is down and original point is
 * top left corner
 */
class WIENGINE_API wyArcticFileData : public wyAFCFileData {
	friend class wyArcticLoader;
	friend class wyArcticManager;

public:
	/**
	 * version of arctic file format
	 */
	int m_version;

	/**
	 * flags of arctic sprite file
	 */
	int m_flags;

	/**
	 * total number of modules
	 */
	int m_moduleCount;

	/**
	 * data of all modules
	 */
	wyArcticModule* m_modules;

	/**
	 * frame module count of all frames
	 */
	int m_frameModuleCount;

	/**
	 * data of all frame modules
	 */
	wyArcticFrameModule* m_frameModules;

	/**
	 * frame count
	 */
	int m_frameCount;

	/**
	 * data of all frames
	 */
	wyArcticFrame* m_frames;

	/**
	 * frame count in all animations
	 */
	int m_animationFrameCount;

	/**
	 * data of all animation frames
	 */
	wyArcticAnimationFrame* m_animationFrames;

	/**
	 * count of animations
	 */
	int m_animationCount;

	/**
	 * data of all animations
	 */
	wyArcticAnimation* m_animations;

protected:
	wyArcticFileData();

public:
	virtual ~wyArcticFileData();
	static wyArcticFileData* make();
};

#endif // __wyArcticFileData_h__
