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
#ifndef __wyMWFileData_h__
#define __wyMWFileData_h__

#include "wyAFCFileData.h"

/**
 * @struct wyMWFileData
 *
 * \if English
 * A bean of anu file
 * \else
 * 封装了从anu文件里面读取出来的原始数据, 它可能包含多个动画. 从逻辑上来说,
 * 一个\link wyMWFileData wyMWFileData\endlink 就对应
 * 了一个anu文件
 * \endif
 */
class WIENGINE_API wyMWFileData : public wyAFCFileData {
public:
	/**
	 * \if English
	 * image count of this file referred
	 * \else
	 * 动画中牵涉到的图片集个数
	 * \endif
	 */
	unsigned int m_numOfImage;

	/**
	 * \if English
	 * animation count in this file
	 * \else
	 * 动画个数
	 * \endif
	 */
	int m_numOfAnimation;

	/**
	 * Animation table
	 *  index of frames in the frameTable for Animation
	 *  FORMAT:
	 *    1. [frametable-start][frametable-end]
	 *    2. [frametable-start][frametable-end]
	 *    3. [frametable-start][frametable-end]
	 */
	short* m_animationTable;

	/**
	 * Animation Frame Table
	 * Golbal frame list
	 *  FORMAT
	 *      1. [FRAME-INDEX][delay][xinc][yinc]
	 * 		2. [FRAME-INDEX][delay][xinc][yinc]
	 * 		3. [FRAME-INDEX][delay][xinc][yinc]
	 * 		4. [FRAME-INDEX][delay][xinc][yinc]
	 * 		5. [FRAME-INDEX][delay][xinc][yinc]
	 *      6. [FRAME-INDEX][delay][xinc][yinc]
	 * 		7. [FRAME-INDEX][delay][xinc][yinc]
	 * 		8. [FRAME-INDEX][delay][xinc][yinc]
	 * 		9. [FRAME-INDEX][delay][xinc][yinc]
	 * 		10.[FRAME-INDEX][delay][xinc][yinc]
	 */
	short* m_frameTable;

	/**
	 * Frame Pool Table
	 *  Contian information about certain clip inside a frame
	 *  FORMAT
	 *
	 *       [CLIP INDEX][X][Y][FLAG]
	 *       [CLIP INDEX][X][Y][FLAG]   - FRAME 0
	 *       [CLIP INDEX][X][Y][FLAG]
	 *       [CLIP INDEX][X][Y][FLAG]
	 *       [CLIP INDEX][X][Y][FLAG]  - FRAME 1
	 *       [CLIP INDEX][X][Y][FLAG]
	 *       [CLIP INDEX][X][Y][FLAG]
	 *       [CLIP INDEX][X][Y][FLAG]
	 *       [CLIP INDEX][X][Y][FLAG]   - FRAME 2
	 *       [CLIP INDEX][X][Y][FLAG]
	 */
	short* m_framePoolTable;

	/**
	 * Clip Pool Table
	 *  FORMAT
	 *  Image
	 *  	[x][y][w][h]
	 *  	[x][y][w][h]
	 *  	[x][y][w][h]
	 *
	 *  Ellipse
	 *  	[w][h][startAngle][endAngle][color]
	 *  	[w][h][startAngle][endAngle][color]
	 *  	[w][h][startAngle][endAngle][color]
	 *
	 *  Line
	 *     [x2][y2][color]
	 *     [x2][y2][color]
	 *
	 *  Rect
	 *     [w][h][color]
	 *     [w][h][color]
	 *
	 *  RoundedRect
	 *     [w][h][arcwidth][archeight][color]
	 *     [w][h][arcwidth][archeight][color]
	 *
	 *  PositionerRoundedRect
	 *     [w][h]
	 *     [w][h]
	 */
	short* m_imageClipPool;
	int*   m_ellipseClipPool;
	int*   m_lineClipPool;
	int*   m_rectangleClipPool;
	int*   m_roundedRectangleClipPool;
	short* m_positionerRectangleClipPool;

	/**
	 * Animation table
	 *  indicate the start-end index of the global frame in framePoolTable which store clip information
	 *  can be retrived by using frameTable[x*4]*2 and frameTable[x*4]*2+1
	 *  FORMAT:
	 *  frameTableIndex[0] = [startIndex in frameTable for frame 0][endIndex]
	 *  frameTableIndex[1] = [startIndex in frameTable for frame 1][endIndex]
	 */
	short* m_frameTableIndex;

	short* m_imageIndex;

public:
	wyMWFileData();
	virtual ~wyMWFileData();
};

#endif // __wyMWFileData_h__
