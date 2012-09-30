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
#ifndef __wyBaseGrid_h__
#define __wyBaseGrid_h__

#include "wyGlobal.h"
#include "wyGrabber.h"
#include <stdbool.h>

class wyNode;

/**
 * @class wyBaseGrid
 *
 * \if English
 * Base class of grid
 * \else
 * 网格封装，是网格的基类
 * \endif
 */
class WIENGINE_API wyBaseGrid : public wyObject {
protected:
	/// row count
	int m_gridX;

	/// column count
	int m_gridY;

	/// grid pixel width
	float m_width;

	/// grid pixel height
	float m_height;

	/**
	 * \if English
	 * width of a single grid unit
	 * \else
	 * 单个网格的宽度
	 * \endif
	 */
	float m_stepWidth;

	/**
	 * \if English
	 * height of a single grid unit
	 * \else
	 * 单个网格的高度
	 * \endif
	 */
	float m_stepHeight;

	/**
	 * \if English
	 * flag indicating whether the grid is active
	 * \else
	 * 网格状态是否激活，true为激活
	 * \endif
	 */
	bool m_active;

	/**
	 * \if English
	 * flag indicating whether the grid can be reused
	 * \else
	 * 网格是否可被重用，0为不可重用
	 * \endif
	 */
	int m_reuseGrid;

	/**
	 * \if English
	 * used to capture the current screenshot to a texture, see \link wyGrabber wyGrabber\endlink
	 * \else
	 * 用于抓取缓冲区内容到贴图中\link wyGrabber wyGrabber对象指针\endlink
	 * \endif
	 */
	wyGrabber* m_grabber;

	// buffers
	GLfloat* m_vertices;
	GLfloat* m_texCoords;
	GLfloat* m_originalVertices;
	GLushort* m_indices;

protected:
	/**
	 * constructor
	 *
	 * @param w pixel width of grid
	 * @param h pixel height of grid
	 * @param c row count of the grid
	 * @param r column count of the grid
	 */
	wyBaseGrid(float w, float h, int c, int r);

public:
	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyBaseGrid();

	/**
	 * \if English
	 * blit the grid effect to the physical screen
	 * \else
	 * 完成网格效果的渲染，子类需要实现这个方法
	 * \endif
	 */
	virtual void blit() = 0;

	/**
	 * \if English
	 * reuse this grid, a common scenario is recover this grid to its initial status
	 * \else
	 * 重用网格，子类需要实现这个方法来完成重用逻辑，一般来说就是恢复到初始状态。
	 * \endif
	 */
	virtual void reuse() = 0;

	/**
	 * \if English
	 * this function is called before node's draw function is called
	 * \else
	 * 在一帧绘制之前被调用
	 * \endif
	 */
	virtual void beforeDraw();

	/**
	 * \if English
	 * this function is called after node's draw funciton is called
	 *
	 * @param node the target node object which the current grid is applied on, \link wyNode wyNode\endlink
	 * \else
	 * 如果网格功能被启用，则一帧渲染完后会调用此方法
	 *
	 * @param node 网格的目标节点\link wyNode wyNode对象指针\endlink
	 * \endif
	 */
	virtual void afterDraw(wyNode* node);

	/**
	 * \if English
	 * add the count how much times the grid can be reused
	 *
	 * @param add the count to be added
	 * \else
	 * 增加重用次数
	 *
	 * @param add 要增加的重用次数
	 * \endif
	 */
	void addReuseCount(int add) { m_reuseGrid += add; }

	/**
	 * \if English
	 * check whether the grid can be reused
	 *
	 * @return true means grid can be reused
	 * \else
	 * 检查是否应该重用网格
	 *
	 * @return 如果网格的重用计数还不为0，则返回true
	 * \endif
	 */
	bool isReuseGrid() { return m_reuseGrid > 0; }

	/**
	 * \if English
	 * acitvate or deactivate the grid
	 * @param flag true means activating, false means deactivating
	 * \else
	 * 设置网格激活标志
	 *
	 * @param flag true表示激活，false表示不激活
	 * \endif
	 */
	void setActive(bool flag);

	/**
	 * \if English
	 * get whether the grid is active
	 * @return true means active
	 * \else
	 * 得到网格是否激活的标志, 一个激活的网格会
	 *
	 * @return true表示网格当前是激活的
	 * \endif
	 */
	bool isActive() { return m_active; }

	/**
	 * \if English
	 * get width of a single grid unit
	 *
	 * @return width of grid unit
	 * \else
	 * 得到单个网格的宽度
	 *
	 * @return 单个网格的宽度
	 * \endif
	 */
	float getStepWidth() { return m_stepWidth; }

	/**
	 * \if English
	 * get height of a single grid unit
	 *
	 * @return height of grid unit
	 * \else
	 * 得到单个网格的高度
	 *
	 * @return 单个网格的高度
	 * \endif
	 */
	float getStepHeight() { return m_stepHeight; }

	/**
	 * \if English
	 * get row count
	 *
	 * @return row count
	 * \else
	 * 得到网格行数
	 *
	 * @return 网格行数
	 * \endif
	 */
	int getGridX() { return m_gridX; }

	/**
	 * \if English
	 * get column count
	 *
	 * @return column count
	 * \else
	 * 得到网格列数
	 *
	 * @return 网格列数
	 * \endif
	 */
	int getGridY() { return m_gridY; }

	/**
	 * \if English
	 * set the width of the whole grid
	 *
	 * @param x the width of the whole grid, in pixels
	 * \else
	 * 设置网格总宽度
	 *
	 * @param x 网格总象素宽度
	 * \endif
	 */
	void setGridX(int x) { m_gridX = x; }

	/**
	 * \if English
	 * set the height of the whole grid
	 *
	 * @param y the height of the whole grid, in pixels
	 * \else
	 * 设置网格总高度
	 *
	 * @param y 网格总象素高度
	 * \endif
	 */
	void setGridY(int y) { m_gridY = y; }
};

#endif // __wyBaseGrid_h__
