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
#ifndef __wyColorMatrix_h__
#define __wyColorMatrix_h__

#include "wyObject.h"

/**
 * @class wyColorMatrix
 *
 * \if English
 * 5x4 matrix for transforming the color+alpha components of a Bitmap.
 * The matrix is stored in a single array, and its treated as follows:
 *  [ a, b, c, d, e,
 *    f, g, h, i, j,
 *    k, l, m, n, o,
 *    p, q, r, s, t ]
 *
 * \par
 * When applied to a color [r, g, b, a], the resulting color is computed as
 * (after clamping)
 *   R' = a*R + b*G + c*B + d*A + e;
 *   G' = f*R + g*G + h*B + i*A + j;
 *   B' = k*R + l*G + m*B + n*A + o;
 *   A' = p*R + q*G + r*B + s*A + t;
 * \else
 * 一个5x4的颜色转换矩阵, 这个矩阵以一个20个浮点数的数组来表示:
 *  [ a, b, c, d, e,
 *    f, g, h, i, j,
 *    k, l, m, n, o,
 *    p, q, r, s, t ]
 *
 * \par
 * 当应用到一个颜色[r, g, b, a]上时, 结果颜色经过矩阵运行并取值在区间[0, 1]:
 *   R' = a*R + b*G + c*B + d*A + e;
 *   G' = f*R + g*G + h*B + i*A + j;
 *   B' = k*R + l*G + m*B + n*A + o;
 *   A' = p*R + q*G + r*B + s*A + t;
 * \endif
 */
class WIENGINE_API wyColorMatrix : public wyObject {
private:
	/**
	 * \if English
	 * matrix elements array
	 * \else
	 * 矩阵元素
	 * \endif
	 */
	float m_matrix[20];

protected:
	wyColorMatrix();

public:
	virtual ~wyColorMatrix();

	/**
	 * \if English
	 * create a matrix
	 *
	 * @param m matrix elements, must have 20 elements. elements will be copied so
	 * 		caller can release the pointer when make returns. if m is NULL then create
	 * 		an identity color matrix
	 * @return \link wyColorMatrix wyColorMatrix\endlink
	 * \else
	 * 创建一个颜色矩阵
	 *
	 * @param m 矩阵元素, 必须包含20个浮点数. 元素内容会被拷贝, 因此make返回后调用者可以释放指针.
	 * 		如果m为NULL, 则创建一个单位颜色矩阵
	 * @return \link wyColorMatrix wyColorMatrix\endlink
	 * \endif
	 */
	static wyColorMatrix* make(float* m = NULL);

	/**
	 * \if English
	 * reset matrix to identity
	 * \else
	 * 重置矩阵为单位矩阵
	 * \endif
	 */
	void reset();

	/**
	 * \if English
	 * get matrix elements
	 *
	 * @return matrix element pointer, caller should not release it
	 * \else
	 * 得到矩阵元素
	 *
	 * @return 矩阵元素, 调用者不需要释放
	 * \endif
	 */
	float* getMatrix() { return m_matrix; }

	/**
	 * \if English
	 * copy elements of other matrix
	 *
	 * @param m other \link wyColorMatrix wyColorMatrix\endlink object
	 * \else
	 * 复制其它矩阵内容
	 *
	 * @param m 要复制的\link wyColorMatrix wyColorMatrix\endlink对象
	 * \endif
	 */
	void setMatrix(wyColorMatrix* m);

	/**
	 * \if English
	 * copy elements from a float array, float array must at least contain 20 float number
	 *
	 * @param m float array
	 * \else
	 * 从一个浮点数组设置矩阵元素, 数组至少要有20个浮点数
	 *
	 * @param m 浮点数组
	 * \endif
	 */
	void setMatrix(float* m);

    /**
     * \if English
     * Set this color matrix to scale by the specified values.
     *
     * @param rScale scale of red
     * @param gScale scale of green
     * @param bScale scale of blue
     * @param aScale scale of alpha
     * \else
     * 设置颜色矩阵的缩放值
     *
     * @param rScale 红色的缩放值
     * @param gScale 绿色的缩放值
     * @param bScale 蓝色的缩放值
     * @param aScale 透明度的缩放值
     * \endif
     */
    void setScale(float rScale, float gScale, float bScale, float aScale);

    /**
     * \if English
     * Set the rotation on a color axis by the specified values.
     *
     * @param axis axis value
     * 		axis=0 correspond to a rotation around the RED color
     * 		axis=1 correspond to a rotation around the GREEN color
     * 		axis=2 correspond to a rotation around the BLUE color
     * @param degrees rotation degrees
     * \else
     * 旋转颜色矩阵
     *
     * @param axis 旋转轴
     * 		0表示按照红色旋转
     * 		1表示按照绿色旋转
     * 		2表示按照蓝色旋转
     * @param degrees 旋转角度
     * \endif
     */
    void setRotate(int axis, float degrees);

    /**
     * \if English
     * Set this color matrix to the concatenation of the two specified
     * color matrices, such that the resulting color matrix has the same effect
     * as applying matB and then applying matA. It is legal for either matA or
     * matB to be the same color matrix as this.
     *
     * @param matA matrix A
     * @param matB matrix B
     * \else
     * 当前矩阵变成两个矩阵的组合, 其效果相当于先使用矩阵A, 再使用矩阵B.
     *
     * @param matA 矩阵A, 可以为当前矩阵
     * @param matB 矩阵B, 可以为当前矩阵
     * \endif
     */
    void setConcat(wyColorMatrix* matA, wyColorMatrix* matB);

    /**
     * \if English
     * Concat this colormatrix with the specified prematrix. This is logically
     * the same as calling setConcat(this, prematrix);
     *
     * @param prematrix matrix to be concated
     * \else
     * 前置连接一个矩阵
     *
     * @param prematrix 要连接的矩阵
     * \endif
     */
    void preConcat(wyColorMatrix* prematrix) { setConcat(this, prematrix); }

    /**
     * \if English
     * Concat this colormatrix with the specified postmatrix. This is logically
     * the same as calling setConcat(postmatrix, this);
     *
     * @param postmatrix matrix to be concated
     * \else
     * 后置连接一个矩阵
     *
     * @param postmatrix 要连接的矩阵
     * \endif
     */
    void postConcat(wyColorMatrix* postmatrix) { setConcat(postmatrix, this); }

    /**
     * \if English
     * Set the matrix to affect the saturation of colors. A value of 0 maps the
     * color to gray-scale. 1 is identity.
     *
     * @param sat saturation, from 0 from 1
     * \else
     * 设置颜色矩阵的饱和度修正参数, 取值从0到1, 0表示把颜色转换为灰度, 1表示不变
     *
     * @param sat 饱和度, 从0到1
     * \endif
     */
    void setSaturation(float sat);

    /**
     * \if English
     * Set the matrix to convert RGB to YUV
     * \else
     * 设置颜色矩阵, 用来把rgb颜色转变成yuv颜色
     * \endif
     */
    void setRGB2YUV();

    /**
     * \if English
     * Set the matrix to convert from YUV to RGB
     * \else
     * 设置颜色矩阵, 用来把yuv颜色转换为rgb颜色
     * \endif
     */
    void setYUV2RGB();

    /**
     * \if English
     * set the matrix to convert image to digital nagative
     * \else
     * 设置颜色矩阵, 将图片转换为底片效果
     * \endif
     */
    void setNegative();
};

#endif // __wyColorMatrix_h__
