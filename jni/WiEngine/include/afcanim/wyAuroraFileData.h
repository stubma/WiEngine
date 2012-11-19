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
#ifndef __wyAuroraFileData_h__
#define __wyAuroraFileData_h__

#include "wyAFCFileData.h"
#include "wyAuroraConstants.h"
#include "wyTypes.h"

class wyAuroraLoader;
class wyAuroraManager;

/**
 * @struct wyAuroraModule
 *
 * module info of aurora sprite
 */
typedef struct wyAuroraModule {
	/**
	 * type of module
	 */
	wyAuroraModuleType type;

	/**
	 * image index, only meaningful for image module
	 */
	int imageIndex;

	/**
	 * color of module, useless for some types
	 */
	int color;

	/**
	 * tile x position in atlas
	 */
	short x;

	/**
	 * tile y position in atlas
	 */
	short y;

	/**
	 * module width
	 */
	short w;

	/**
	 * module height
	 */
	short h;
} wyAuroraModule;

/**
 * @struct wyAuroraFrameModule
 *
 * frame module info
 */
typedef struct wyAuroraFrameModule {
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
	 * palette index
	 */
	short palette;

	/**
	 * module flag, bits 6, 7 are extension for module index
	 */
	unsigned char flags;
} wyAuroraFrameModule;

/**
 * @struct wyAuroraFrame
 *
 * frame info in aurora file
 */
typedef struct wyAuroraFrame {
	/**
	 * module count in frame
	 */
	short moduleCount;

	/**
	 * index of first module. The index indicates data position in \c m_frameModules
	 * of \link wyAuroraFileData wyAuroraFileData\endlink
	 */
	short firstModuleIndex;

	/**
	 * count of collision rect belongs to this frame
	 */
	short collisionRectCount;

	/**
	 * bound rect of frame
	 */
	wyRect bound;
} wyAuroraFrame;

/**
 * @typedef wyAuroraAnimationFrame
 *
 * \if Enlgish
 * info of frame in an animation
 */
typedef struct wyAuroraAnimationFrame {
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
	 * y offset of frame. Y axis of aurora is reversed to opengl, so need negate it
	 * when calculate AFC frame offset
	 */
	short offsetY;

	/**
	 * flags of frame, bits 6, 7 are extension for frame index
	 */
	unsigned char flags;
} wyAuroraAnimationFrame;

/**
 * info of aurora animation
 */
typedef struct wyAuroraAnimation {
	/**
	 * frame count in this animation
	 */
	short frameCount;

	/**
	 * index of first frame in animation frames list. The index indicates data position in
	 * \c m_animationFrames of \link wyAuroraFileData wyAuroraFileData\endlink
	 */
	short firstFrameIndex;
} wyAuroraAnimation;

/**
 * @class wyAuroraFileData
 *
 * File data object for export file of AuroraGT, a gameloft game designer. The exported file is called
 * BSprite, and it uses little endian byte order. In BSprite, positive direction of x axis is right,
 * positive of y is down and original point is top left corner
 */
class WIENGINE_API wyAuroraFileData : public wyAFCFileData {
	friend class wyAuroraLoader;
	friend class wyAuroraManager;

public:
	/**
	 * version of aurora file format
	 */
	int m_version;

	/**
	 * flags of aurora sprite file
	 */
	int m_flags;

	/**
	 * image atlas count
	 */
	int m_imageCount;

	/**
	 * total number of modules
	 */
	int m_moduleCount;

	/**
	 * data of all modules
	 */
	wyAuroraModule* m_modules;

	/**
	 * frame module count of all frames
	 */
	int m_frameModuleCount;

	/**
	 * data of all frame modules
	 */
	wyAuroraFrameModule* m_frameModules;

	/**
	 * collision rect count
	 */
	int m_collisionRectCount;

	/**
	 * buffer of collision rects
	 */
	wyRect* m_collisionRects;

	/**
	 * frame count
	 */
	int m_frameCount;

	/**
	 * data of all frames
	 */
	wyAuroraFrame* m_frames;

	/**
	 * frame count in all animations
	 */
	int m_animationFrameCount;

	/**
	 * data of all animation frames
	 */
	wyAuroraAnimationFrame* m_animationFrames;

	/**
	 * count of animations
	 */
	int m_animationCount;

	/**
	 * data of all animations
	 */
	wyAuroraAnimation* m_animations;

protected:
	wyAuroraFileData();

public:
	virtual ~wyAuroraFileData();
	static wyAuroraFileData* make();
};

#endif // __wyAuroraFileData_h__
