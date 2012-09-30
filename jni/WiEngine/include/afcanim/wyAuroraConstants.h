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
#ifndef __wyAuroraConstants_h__
#define __wyAuroraConstants_h__

/**
 * @typedef wyAuroraFlags
 *
 * \if English
 * Flags used in BSprite file
 * \else
 * AuroraGT将它的导出文件格式称为BSprite, 这是BSprite文件中的标志位定义
 * \endif
 */
typedef enum {
	// export modules
	BS_MODULES = 1,

	// export x, y for each module
	BS_MODULES_XY = 1 << 1,

	// export image index for each module
	BS_MODULES_IMG = 1 << 2,

	// export w, h for each module as short
	BS_MODULES_WH_SHORT = 1 << 4,

	// export x, y for each module as short
	BS_MODULES_XY_SHORT = 1 << 5,

	// export frames
	BS_FRAMES = 1 << 8,

	// don't export first frame module index
	BS_NO_FM_START = 1 << 9,

	// export fm offsets as shorts
	BS_FM_OFF_SHORT = 1 << 10,

	// export number of frame module as byte
	BS_NFM_1_BYTE = 1 << 11,

	// do not export frame bound rect
	BS_SKIP_FRAME_RC = 1 << 12,

	// export frame collision rect
	BS_FRAME_COLL_RC = 1 << 13,

	// export palette used by the module
	BS_FM_PALETTE = 1 << 14,

	// export frame rects
	BS_FRAME_RECTS = 1 << 15,

	// export anims
	BS_ANIMS = 1 << 16,

	// don't export first animation frame index
	BS_NO_AF_START = 1 << 17,

	// export animation frame offsets as shorts
	BS_AF_OFF_SHORT = 1 << 18,

	// export number of animation frame as byte
	BS_NAF_1_BYTE = 1 << 19,

	// export encoded images for each module
	BS_MODULE_IMAGES = 1 << 24,

	// export PNG additional info (CRCs) for each module
	BS_PNG_CRC = 1 << 25,

	// keep original palette (do not optimize colors)
	BS_KEEP_PAL = 1 << 26,

	// move transparency as the first color(s)
	BS_TRANSP_FIRST = 1 << 27,

	// move transparency as the last color(s)
	BS_TRANSP_LAST = 1 << 28,

	// export sprite image as an PNG with CRCs for each palette
	BS_SINGLE_IMAGE	= 1 << 29,
} wyAuroraFlags;

/**
 * @typedef wyAuroraModuleType
 *
 * \if English
 * type of module in BSprite
 * \else
 * BSprite中的分片类型
 * \endif
 */
typedef enum {
	// unknown type
	BSM_UNKNOWN,

	// image module
	BSM_IMAGE,

	// it is a rect
	BSM_RECT,

	// it is a filled rect
	BSM_FILL_RECT,

	// it is a marker
	BSM_MARKER
} wyAuroraModuleType;

/**
 * @typedef wyAuroraFrameModuleFlags
 *
 * \if English
 * Flags used in arctic frame module
 * \else
 * 在BSprite的帧分片信息中使用的标志位定义
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
	BS_FLIP_X = 0x01,

	/**
	 * \if English
	 * flipped in y axis
	 * \else
	 * y轴翻转
	 * \endif
	 */
	BS_FLIP_Y = 0x02,

	/**
	 * \if English
	 * rotoated by 90 degree, in clockwise direction
	 * \else
	 * 顺时针90度旋转
	 * \endif
	 */
	BS_ROT_90 = 0x04,

	/**
	 * \if English
	 * reversed
	 * \else
	 * 保留给用户自定义
	 * \endif
	 */
	BS_USER0 = 0x10,

	/**
	 * \if English
	 * reversed
	 * \else
	 * 保留给用户自定义
	 * \endif
	 */
	BS_USER1 = 0x20,

	/**
	 * \if English
	 * it is not a module, it is a reference to other frame
	 * \else
	 * 使用的是Hyper frames
	 * \endif
	 */
	BS_HYPER_FM = 0x10,

	/**
	 * \if English
	 * attach box
	 * \else
	 * 攻击框
	 * \endif
	 */
	BS_ATTACK_BOX = 0x40,

	/**
	 * \if English
	 * extended index mask
	 * \else
	 * 扩展索引位的掩码
	 * \endif
	 */
	BS_INDEX_EX_MASK = 0xC0
} wyAuroraFrameModuleFlags;

/**
 * \if English
 * how many bits should extended index shift to right
 * \else
 * 扩展索引需要右移的位数
 * \endif
 */
#define BS_INDEX_EX_SHIFT 2

/**
 * \if English
 * Version 3 of BSprite file
 * \else
 * BSprite文件格式第三版
 * \endif
 */
#define BS_VERSION_3 0x03DF

#endif // __wyAuroraConstants_h__
