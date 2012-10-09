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
#ifndef __wyArcticConstants_h__
#define __wyArcticConstants_h__

/**
 * @typedef wyArcticFlags
 *
 * \if English
 * flags used in ASprite file
 * \else
 * ASprite格式文件中可能用到的标志位常量
 * \endif
 */
typedef enum {
	/// export encoded images for each module
	AS_IMAGE_MODULES = (1 << 0),

	/// export PNG additional info (CRCs) for each module
	AS_PNG_CRC = (1 << 1),

	// keep original palette (do not optimize colors)
	AS_KEEP_PAL = (1 << 2),

	// move transparency as the first color(s)
	AS_TRANSP_FIRST = (1 << 4),

	// move transparency as the last color(s)
	AS_TRANSP_LAST = (1 << 5),

	// export alpha data for each module
	AS_IMAGE_ALPHA = (1 << 6),

	// export modules (w and h)
	AS_MODULES = (1 << 8),

	// export w, h for each module as short
	AS_MODULES_WH_SHORT = (1 << 9),

	// export image index for each module
	AS_MODULES_IMG = (1 << 10),

	// export x, y for each module
	AS_MODULES_XY = (1 << 11),

	// export x, y for each module as short
	AS_MODULES_XY_SHORT = (1 << 12),

	// export frames
	AS_FRAMES = (1 << 16),

	// export fm offsets as short (default is byte)
	AS_FM_OFF_SHORT = (1 << 17),

	// export fm number as short (default is byte)
	AS_FM_NUM_SHORT = (1 << 18),

	// export frame rect
	AS_FRAME_RC = (1 << 19),

	// export collision rect
	AS_FRAME_COL_RC = (1 << 20),

	// export anims
	AS_ANIMS = (1 << 24),

	// export af offsets as short (default is byte)
	AS_AF_OFF_SHORT = (1 << 25),

	// export af number as short (default is byte)
	AS_AF_NUM_SHORT = (1 << 26)
} wyArcticFlags;

/**
 * @typedef wyArcticFrameModuleFlags
 *
 * \if English
 * Flags used in arctic frame module
 * \else
 * 在ASprite的帧分片信息中使用的标志位定义
 * \endif
 */
typedef enum {
	/**
	 * \if English
	 * flipped in x axis
	 * \else
	 * x轴翻转
	 * \endif
	 */
	AS_FLIP_X = 0x01,

	/**
	 * \if English
	 * flipped in y axis
	 * \else
	 * y轴翻转
	 * \endif
	 */
	AS_FLIP_Y = 0x02,

	/**
	 * \if English
	 * rotoated by 90 degree, in clockwise direction
	 * \else
	 * 顺时针90度旋转
	 * \endif
	 */
	AS_ROT_90 = 0x04,

	/**
	 * \if English
	 * reversed
	 * \else
	 * 保留给用户自定义
	 * \endif
	 */
	AS_USER0 = 0x10,

	/**
	 * \if English
	 * reversed
	 * \else
	 * 保留给用户自定义
	 * \endif
	 */
	AS_USER1 = 0x20,

	/**
	 * \if English
	 * it is not a module, it is a reference to other frame
	 * \else
	 * 使用的是Hyper frames
	 * \endif
	 */
	AS_HYPER_FM = 0x10,

	/**
	 * \if English
	 * attach box
	 * \else
	 * 攻击框
	 * \endif
	 */
	AS_ATTACK_BOX = 0x40,

	/**
	 * \if English
	 * extended index mask
	 * \else
	 * 扩展索引位的掩码
	 * \endif
	 */
	AS_INDEX_EX_MASK = 0xC0
} wyArcticFrameModuleFlags;

/**
 * \if English
 * how many bits should extended index shift to right
 * \else
 * 扩展索引需要右移的位数
 * \endif
 */
#define AS_INDEX_EX_SHIFT 2

#endif // __wyArcticConstants_h__
