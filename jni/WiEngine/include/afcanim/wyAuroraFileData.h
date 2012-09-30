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
 * \if English
 * module info of aurora sprite
 * \else
 * BSprite中的module信息
 * \endif
 */
typedef struct wyAuroraModule {
	/**
	 * \if English
	 * type of module
	 * \else
	 * 分片类型
	 * \endif
	 */
	wyAuroraModuleType type;

	/**
	 * \if English
	 * image index, only meaningful for image module
	 * \else
	 * 图片分片， 仅当分片类型是\c BSM_IMAGE时有效
	 * \endif
	 */
	int imageIndex;

	/**
	 * \if English
	 * color of module, useless for some types
	 * \else
	 * 分片的颜色， 对某些类型的分片无用
	 * \endif
	 */
	int color;

	/**
	 * \if English
	 * tile x position in atlas
	 * \else
	 * 分片左上角x位置
	 * \endif
	 */
	short x;

	/**
	 * \if English
	 * tile y position in atlas
	 * \else
	 * 分片左上角y位置
	 * \endif
	 */
	short y;

	/**
	 * \if English
	 * module width
	 * \else
	 * 分片宽度
	 * \endif
	 */
	short w;

	/**
	 * \if English
	 * module height
	 * \else
	 * 分片高度
	 * \endif
	 */
	short h;
} wyAuroraModule;

/**
 * @struct wyAuroraFrameModule
 *
 * \if English
 * frame module info
 * \else
 * 分片在帧中的信息
 * \endif
 */
typedef struct wyAuroraFrameModule {
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
	 * palette index
	 * \else
	 * 调色板索引
	 * \endif
	 */
	short palette;

	/**
	 * \if English
	 * module flag, bits 6, 7 are extension for module index
	 * \else
	 * 分片标志位, 高2位用于分片索引的扩展
	 * \endif
	 */
	unsigned char flags;
} wyAuroraFrameModule;

/**
 * @struct wyAuroraFrame
 *
 * \if English
 * frame info in aurora file
 * \else
 * BSprite中的帧信息
 * \endif
 */
typedef struct wyAuroraFrame {
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
	 * of \link wyAuroraFileData wyAuroraFileData\endlink
	 * \else
	 * 第一个分片的索引, 之后的分片依次排列在之后. 这个索引指的是\link wyAuroraFileData wyAuroraFileData\endlink
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
	 * bound rect of frame
	 * \else
	 * 帧的矩形位置
	 * \endif
	 */
	wyRect bound;
} wyAuroraFrame;

/**
 * @typedef wyAuroraAnimationFrame
 *
 * \if Enlgish
 * info of frame in an animation
 * \else
 * 动画内一帧的描述信息
 * \endif
 */
typedef struct wyAuroraAnimationFrame {
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
	 * y offset of frame. Y axis of aurora is reversed to opengl, so need negate it
	 * when calculate AFC frame offset
	 * \else
	 * 帧的y偏移, Aurora的y坐标轴方向是和opengl相关的, 因此转换时需要取负值
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
} wyAuroraAnimationFrame;

/**
 * \if English
 * info of aurora animation
 * \else
 * BSprite动画信息
 * \endif
 */
typedef struct wyAuroraAnimation {
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
	 * \c m_animationFrames of \link wyAuroraFileData wyAuroraFileData\endlink
	 * \else
	 * 第一个动画帧索引, 以后的帧按顺序在之后排列, 这个索引是指
	 * \link wyAuroraFileData wyAuroraFileData\endlink中的\c m_animationFrames
	 * 的索引位置
	 * \endif
	 */
	short firstFrameIndex;
} wyAuroraAnimation;

/**
 * @class wyAuroraFileData
 *
 * \if English
 * File data object for export file of AuroraGT, a gameloft game designer. The exported file is called
 * BSprite, and it uses little endian byte order. In BSprite, positive direction of x axis is right,
 * positive of y is down and original point is top left corner
 * \else
 * Gameloft的AuroraGT编辑器的导出文件数据对象, 文件内的数据使用little endian字节序. 它的导出文件叫做BSprite, 在BSprite
 * 文件中的坐标系是x往右增加, y往下增加, 原点在左上角. 所以转到WiEngine中时需要注意转换
 * \endif
 */
class WIENGINE_API wyAuroraFileData : public wyAFCFileData {
	friend class wyAuroraLoader;
	friend class wyAuroraManager;

public:
	/**
	 * \if English
	 * version of aurora file format
	 * \else
	 * BSprite文件格式版本
	 * \endif
	 */
	int m_version;

	/**
	 * \if English
	 * flags of aurora sprite file
	 * \else
	 * 动画文件的头部标志位
	 * \endif
	 */
	int m_flags;

	/**
	 * \if English
	 * image atlas count
	 * \else
	 * 图片集个数
	 * \endif
	 */
	int m_imageCount;

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
	wyAuroraModule* m_modules;

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
	wyAuroraFrameModule* m_frameModules;

	/**
	 * \if English
	 * collision rect count
	 * \else
	 * 碰撞矩形的个数
	 * \endif
	 */
	int m_collisionRectCount;

	/**
	 * \if English
	 * buffer of collision rects
	 * \else
	 * 碰撞矩形缓冲区
	 * \endif
	 */
	wyRect* m_collisionRects;

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
	wyAuroraFrame* m_frames;

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
	wyAuroraAnimationFrame* m_animationFrames;

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
	wyAuroraAnimation* m_animations;

protected:
	wyAuroraFileData();

public:
	virtual ~wyAuroraFileData();
	static wyAuroraFileData* make();
};

#endif // __wyAuroraFileData_h__
