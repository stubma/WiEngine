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
 * \if English
 * module info of arctic sprite
 * \else
 * ASprite中的module信息
 * \endif
 */
typedef struct wyArcticModule {
	/**
	 * \if English
	 * image index
	 * \else
	 * 分片所属的图片索引
	 * \endif
	 */
	int imageIndex;

	/**
	 * \if English
	 * tile image x position in atlas
	 * \else
	 * 分片图片在图片集中的左上角x位置
	 * \endif
	 */
	short x;

	/**
	 * \if English
	 * tile image y position in atlas
	 * \else
	 * 分片图片在图片集中的左上角y位置
	 * \endif
	 */
	short y;

	/**
	 * \if English
	 * tile image width in atlas
	 * \else
	 * 分片图片的宽度
	 * \endif
	 */
	short w;

	/**
	 * \if English
	 * tile image height in atlas
	 * \else
	 * 分片图片的高度
	 * \endif
	 */
	short h;
} wyArcticModule;

/**
 * @struct wyArcticFrameModule
 *
 * \if English
 * frame module info
 * \else
 * 分片在帧中的信息
 * \endif
 */
typedef struct wyArcticFrameModule {
	/**
	 * \if English
	 * index of module
	 * \else
	 * 分片的索引
	 * \endif
	 */
	short index;

	/**
	 * \if English
	 * module x position in frame
	 * \else
	 * 分片在帧中的x位置
	 * \endif
	 */
	short x;

	/**
	 * \if English
	 * module y position in frame
	 * \else
	 * 分片在帧中的y位置
	 * \endif
	 */
	short y;

	/**
	 * \if English
	 * module flag, bits 6, 7 are extension for module index
	 * \else
	 * 分片标志位, 高2位用于分片索引的扩展
	 * \endif
	 */
	unsigned char flags;
} wyArcticFrameModule;

/**
 * @struct wyArcticFrame
 *
 * \if English
 * frame info in arctic file
 * \else
 * ASprite中的帧信息
 * \endif
 */
typedef struct wyArcticFrame {
	/**
	 * \if English
	 * module count in frame
	 * \else
	 * 帧内的分片数
	 * \endif
	 */
	short moduleCount;

	/**
	 * \if English
	 * index of first module. The index indicates data position in \c m_frameModules
	 * of \link wyArcticFileData wyArcticFileData\endlink
	 * \else
	 * 第一个分片的索引, 之后的分片依次排列在之后. 这个索引指的是\link wyArcticFileData wyArcticFileData\endlink
	 * 中\c m_frameModules的索引位置
	 * \endif
	 */
	short firstModuleIndex;
	
	/**
	 * \if English
	 * count of collision rect belongs to this frame
	 * \else
	 * 属于这个帧的碰撞矩形个数
	 * \endif
	 */
	short collisionRectCount;
	
	/**
	 * \if English
	 * buffer of collision rects, the (x, y) is top left corner
	 * \else
	 * 碰撞矩形缓冲区, 矩形的(x, y)为左上角
	 * \endif
	 */
	wyRect* collisionRects;
} wyArcticFrame;

/**
 * @typedef wyArcticAnimationFrame
 *
 * \if Enlgish
 * info of frame in an animation
 * \else
 * 动画内一帧的描述信息
 * \endif
 */
typedef struct wyArcticAnimationFrame {
	/**
	 * \if English
	 * index of frame
	 * \else
	 * 帧索引
	 * \endif
	 */
	short index;

	/**
	 * \if English
	 * delay time of this frame, it is not a normal time value and it is
	 * very similar with motion welder. So actually we need set an unit
	 * interval to evaluate final time
	 * \else
	 * 帧的持续时间, 这个值和motion welder类似, 并不是一个实际的时间, 而是一个无单位
	 * 的数字, 因此需要设置一个单位时间才能计算出最终时间
	 * \endif
	 */
	short delay;

	/**
	 * \if English
	 * x offset of frame
	 * \else
	 * 帧的x偏移
	 * \endif
	 */
	short offsetX;

	/**
	 * \if English
	 * y offset of frame. Y axis of arctic is reversed to opengl, so need negate it
	 * when calculate AFC frame offset
	 * \else
	 * 帧的y偏移, Arctic的y坐标轴方向是和opengl相关的, 因此转换时需要取负值
	 * \endif
	 */
	short offsetY;

	/**
	 * \if English
	 * flags of frame, bits 6, 7 are extension for frame index
	 * \else
	 * 帧标志, 高2位用于帧索引扩展
	 * \endif
	 */
	unsigned char flags;
} wyArcticAnimationFrame;

/**
 * \if English
 * info of arctic animation
 * \else
 * ASprite动画信息
 * \endif
 */
typedef struct wyArcticAnimation {
	/**
	 * \if English
	 * frame count in this animation
	 * \else
	 * 动画内的帧数
	 * \endif
	 */
	short frameCount;

	/**
	 * \if English
	 * index of first frame in animation frames list. The index indicates data position in
	 * \c m_animationFrames of \link wyArcticFileData wyArcticFileData\endlink
	 * \else
	 * 第一个动画帧索引, 以后的帧按顺序在之后排列, 这个索引是指
	 * \link wyArcticFileData wyArcticFileData\endlink中的\c m_animationFrames
	 * 的索引位置
	 * \endif
	 */
	short firstFrameIndex;
} wyArcticAnimation;

/**
 * @class wyArcticFileData
 *
 * \if English
 * File data object for Arctic editor. It uses little endian byte order. In ASprite,
 * positive direction of x axis is right, positive of y is down and original point is
 * top left corner
 * \else
 * 北极编辑器的导出文件数据对象, 文件内的数据使用little endian字节序. ASprite文件中的坐标系是
 * x往右增加, y往下增加, 原点在左上角. 所以转到WiEngine中时需要注意转换
 * \endif
 */
class WIENGINE_API wyArcticFileData : public wyAFCFileData {
	friend class wyArcticLoader;
	friend class wyArcticManager;

public:
	/**
	 * \if English
	 * version of arctic file format
	 * \else
	 * ASprite文件格式版本
	 * \endif
	 */
	int m_version;

	/**
	 * \if English
	 * flags of arctic sprite file
	 * \else
	 * 动画文件的头部标志位
	 * \endif
	 */
	int m_flags;

	/**
	 * \if English
	 * total number of modules
	 * \else
	 * 分片总数
	 * \endif
	 */
	int m_moduleCount;

	/**
	 * \if English
	 * data of all modules
	 * \else
	 * 所有的分片数据
	 * \endif
	 */
	wyArcticModule* m_modules;

	/**
	 * \if English
	 * frame module count of all frames
	 * \else
	 * 所有的帧内分片加起来之和
	 * \endif
	 */
	int m_frameModuleCount;

	/**
	 * \if English
	 * data of all frame modules
	 * \else
	 * 所有的帧内分片信息
	 * \endif
	 */
	wyArcticFrameModule* m_frameModules;

	/**
	 * \if English
	 * frame count
	 * \else
	 * 所有的帧数
	 * \endif
	 */
	int m_frameCount;

	/**
	 * \if English
	 * data of all frames
	 * \else
	 * 所有的帧数据
	 * \endif
	 */
	wyArcticFrame* m_frames;

	/**
	 * \if English
	 * frame count in all animations
	 * \else
	 * 所有动画中的帧总和
	 * \endif
	 */
	int m_animationFrameCount;

	/**
	 * \if English
	 * data of all animation frames
	 * \else
	 * 所有动画帧的数据
	 * \endif
	 */
	wyArcticAnimationFrame* m_animationFrames;

	/**
	 * \if English
	 * count of animations
	 * \else
	 * 动画总数
	 * \endif
	 */
	int m_animationCount;

	/**
	 * \if English
	 * data of all animations
	 * \else
	 * 所有动画的数据
	 * \endif
	 */
	wyArcticAnimation* m_animations;

protected:
	wyArcticFileData();

public:
	virtual ~wyArcticFileData();
	static wyArcticFileData* make();
};

#endif // __wyArcticFileData_h__
