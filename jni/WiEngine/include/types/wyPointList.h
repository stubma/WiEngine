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
#ifndef __wyPointList_h__
#define __wyPointList_h__

/**
 * @struct wyPointList
 *
 * \if English
 * Maintain a buffer of points
 * \else
 * 点缓冲, 维护一系列的点
 * \endif
 */
class WIENGINE_API wyPointList {
private:
	/**
	 * \if English
	 * point buffer
	 * \else
	 * 点缓冲区
	 * \endif
	 */
	wyPoint* m_buffer;

	/**
	 * \if English
	 * point count
	 * \else
	 * 点数量
	 * \endif
	 */
	int m_count;

	/**
	 * \if English
	 * capacity of buffer, in point, not bytes
	 * \else
	 * 点缓冲区的容量, 表示能容纳多少个点, 不是字节数
	 * \endif
	 */
	int m_capacity;

public:
	wyPointList();
	virtual ~wyPointList();

	/**
	 * \if English
	 * Add a point
	 * \else
	 * 添加一个点
	 * \endif
	 */
	void addPoint(float x, float y);

	/**
	 * \if English
	 * Add a point
	 * \else
	 * 添加一个点
	 * \endif
	 */
	void addPoint(wyPoint p) { addPoint(p.x, p.y); }

	/**
	 * \if English
	 * Add all points from another point list
	 *
	 * @param plist point list to be copied from
	 * \else
	 * 添加另一个点列表中的所有点
	 *
	 * @param plist 要拷贝的点列表
	 * \endif
	 */
	void addPoints(wyPointList& plist);

	/**
	 * \if English
	 * delete point at given index
	 * \else
	 * 删除指定位置的点
	 * \endif
	 */
	void deletePointAt(int index);

	/**
	 * \if English
	 * Get point buffer
	 * \else
	 * 得到点缓冲区
	 * \endif
	 */
	wyPoint* getBuffer() { return m_buffer; }

	/**
	 * \if English
	 * Get point count
	 * \else
	 * 得到点数
	 * \endif
	 */
	int getCount() { return m_count; }

	/**
	 * \if English
	 * Clear all points
	 * \else
	 * 重置点数为0
	 * \endif
	 */
	void clear();

	/**
	 * \if English
	 * Get point at given index
	 *
	 * @param index point index
	 * @return \link wyPoint wyPoint\endlink
	 * \else
	 * 得到指定位置的点
	 *
	 * @param index 点索引
	 * @return \link wyPoint wyPoint\endlink
	 * \endif
	 */
	wyPoint getPointAt(int index);
};

#endif // __wyPointList_h__
