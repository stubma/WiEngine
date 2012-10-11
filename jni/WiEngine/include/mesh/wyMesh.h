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
#ifndef __wyMesh_h__
#define __wyMesh_h__

#include "wyBuffer.h"
#include "wyShaderVariable.h"

/**
 * @class wyMesh
 *
 * \if English
 * \c wyMesh is used to store rendering data. All visible elements in a scene are
 * represented by meshes.
 * \else
 * \c wyMesh保存了可见元素的渲染数据
 * \endif
 */
class WIENGINE_API wyMesh : public wyObject {
protected:
	/// vertex data structure
	struct Vertex {
		/// vertex position
		kmVec3 pos;

		/// texture coordinates
		kmVec2 tex;

		/// color
		kmVec4 color;
	};

public:
	/**
	 * \if English
	 * primitive modes
	 * \else
	 * 顶点渲染方式
	 * \endif
	 */
	enum Mode {
        /**
         * A primitive is a single point in space. The size of the points
         * can be specified with {@link Mesh#setPointSize(float) }.
         */
        POINTS,

        /**
         * A primitive is a line segment. Every two vertices specify
         * a single line. {@link Mesh#setLineWidth(float) } can be used
         * to set the width of the lines.
         */
        LINES,

        /**
         * A primitive is a line segment. The first two vertices specify
         * a single line, while subsequent vertices are combined with the
         * previous vertex to make a line. {@link Mesh#setLineWidth(float) } can
         * be used to set the width of the lines.
         */
        LINE_STRIP,

        /**
         * Identical to {@link #LineStrip} except that at the end
         * the last vertex is connected with the first to form a line.
         * {@link Mesh#setLineWidth(float) } can be used
         * to set the width of the lines.
         */
        LINE_LOOP,

        /**
         * A primitive is a triangle. Each 3 vertices specify a single
         * triangle.
         */
        TRIANGLES,

        /**
         * Similar to {@link #Triangles}, the first 3 vertices
         * specify a triangle, while subsequent vertices are combined with
         * the previous two to form a triangle.
         */
        TRIANGLE_STRIP,

        /**
         * Similar to {@link #Triangles}, the first 3 vertices
         * specify a triangle, each 2 subsequent vertices are combined
         * with the very first vertex to make a triangle.
         */
        TRIANGLE_FAN,
	};

	/**
	 * \if English
	 * connection to a shader attribute
	 * \else
	 * 连接shader中某个属性参数
	 * \endif
	 */
	struct AttributeConnection {
		/**
		 * \if English
		 * attribute name
		 * \else
		 * 属性参数名称
		 * \endif
		 */
		const char* name;

		/**
		 * \if English
		 * attribute value
		 * \else
		 * 属性参数值
		 * \endif
		 */
		wyShaderVariable::Value value;

		/**
		 * \if English
		 * attribute type
		 * \else
		 * 属性参数类型
		 * \endif
		 */
		wyShaderVariable::Type type;
	};

protected:
	/// drawing mode
	Mode m_mode;

	/// attribute list
	vector<AttributeConnection*>* m_attrConnections;

	/// level of detail buffers, start from detail 0
	vector<wyBuffer*>* m_lodLevels;

	/// point size for point mesh
	float m_pointSize;

	/// line width of line mesh
	float m_lineWidth;

private:
	static void releaseAttributeConnection(AttributeConnection* conn);

protected:
	wyMesh();

public:
	virtual ~wyMesh();

	/**
	 * \if English
	 * Make a connection between mesh data to an attribute parameter
	 *
	 * @param name name of attribute
	 * @param buf data buffer object
	 * @param offset byte offset of attribute data in buffer
	 * @param components how many components of one vertex attribute
	 * \else
	 * 添加一个属性参数绑定
	 *
	 * @param name 属性参数名称
	 * @param buf 数据缓冲区
	 * @param offset 起始偏移
	 * @param components 一个顶点的数据部件数
	 * \endif
	 */
	void connectAttribute(const char* name, wyBuffer* buf, int offset, int components);

	/**
	 * \if English
	 * Connect a float attribute
	 *
	 * @param name attribute name
	 * @param v float value
	 * \else
	 * 添加一个浮点属性参数绑定
	 *
	 * @param name 属性参数名称
	 * @param v 浮点数
	 * \endif
	 */
	void connectAttribute(const char* name, float v);

	/**
	 * \if English
	 * Connect a 2d vector attribute
	 *
	 * @param name attribute name
	 * @param v 2d vector
	 * \else
	 * 添加一个2维向量属性参数绑定
	 *
	 * @param name 属性参数名称
	 * @param v 2维向量
	 * \endif
	 */
	void connectAttribute(const char* name, kmVec2& v);

	/**
	 * \if English
	 * Connect a 3d vector attribute
	 *
	 * @param name attribute name
	 * @param v 3d vector
	 * \else
	 * 添加一个3维向量属性参数绑定
	 *
	 * @param name 属性参数名称
	 * @param v 3维向量
	 * \endif
	 */
	void connectAttribute(const char* name, kmVec3& v);

	/**
	 * \if English
	 * Connect a 4d vector attribute
	 *
	 * @param name attribute name
	 * @param v 4d vector
	 * \else
	 * 添加一个4维向量属性参数绑定
	 *
	 * @param name 属性参数名称
	 * @param v 4维向量
	 * \endif
	 */
	void connectAttribute(const char* name, kmVec4& v);

	/**
	 * \if English
	 * Get mesh mode
	 *
	 * @return mesh mode
	 * \else
	 * 得到网格渲染模式
	 *
	 * @return 渲染模式
	 * \endif
	 */
	Mode getMode() { return m_mode; }

	/**
	 * \if English
	 * Get number of LOD datas
	 *
	 * @return number of LOD datas, maybe zero if no LOD data
	 * \else
	 * 得到LOD数据个数
	 *
	 * @return LOD数据个数, 如果没有LOD数据, 返回0
	 * \endif
	 */
	int getNumberOfLodLevel() { return m_lodLevels == NULL ? 0 : m_lodLevels->size(); }

	/**
	 * \if English
	 * Set level of detail data buffers
	 *
	 * @param buffers buffer list
	 * @param count count of buffers
	 * \else
	 * 设置LOD数据缓冲区
	 *
	 * @param buffers 缓冲区指针
	 * @param count 缓冲区个数
	 * \endif
	 */
	void setLodLevels(wyBuffer** buffers, int count);

	/**
	 * \if English
	 * Get indices buffer of specified level of detail, if lod level is not set then returns
	 * NULL
	 *
	 * @param lodLevel level of detail
	 * @return \link wyBuffer wyBuffer\endlink, or NULL if no lod set or \c lodLevel exceeds range
	 * \else
	 * 得到某个精细度的索引缓冲区, 如果没有设置过lod数据, 则返回NULL
	 *
	 * @param lodLevel 精细度
	 * @return \link wyBuffer wyBuffer\endlink, 如果没有设置lod数据或者\c lodLevel超出范围, 返回NULL
	 * \endif
	 */
	wyBuffer* getLodLevelBuffer(int lodLevel);

	/**
	 * \if English
	 * Get list of all connected attributes
	 *
	 * @return list of all connected attributes
	 * \else
	 * 得到所有相关属性参数
	 *
	 * @return 相关属性参数列表
	 * \endif
	 */
	vector<AttributeConnection*>* getConnections() { return m_attrConnections; }

	/**
	 * \if English
	 * Get first connected buffer, only valid if mesh has interleaved attribute bound
	 *
	 * @return first buffer object, or NULL if not found
	 * \else
	 * 得到第一个绑定的数据缓冲区, 仅当mesh有一个交织缓冲区类型的属性参数绑定时有效
	 *
	 * @return 第一个缓冲区对象, 如果没有, 返回NULL
	 * \endif
	 */
	wyBuffer* getFirstConnectedBuffer();

	/**
	 * \if English
	 * Set indices buffer
	 *
	 * @param buffer indices buffer
	 * \else
	 * 设置索引缓冲区
	 *
	 * @param buffer 索引缓冲区
	 * \endif
	 */
	void setIndices(wyBuffer* buffer);

	/**
	 * \if English
	 * Get indices buffer
	 *
	 * @return indices buffer, or NULL if not set
	 * \else
	 * 得到索引缓冲区
	 *
	 * @return 索引缓冲区, 如果没有设置过, 返回NULL
	 * \endif
	 */
	wyBuffer* getIndices();

	/**
	 * \if English
	 * Set line width, useful for line mesh
	 *
	 * @param lineWidth line width
	 * \else
	 * 设置线宽, 对线式网格有效
	 *
	 * @param lineWidth 线宽
	 * \endif
	 */
	void setLineWidth(float lineWidth) { m_lineWidth = lineWidth; }

	/**
	 * \if English
	 * Get line width
	 *
	 * @return line width
	 * \else
	 * 得到线宽
	 *
	 * @return 线宽
	 * \endif
	 */
	float getLineWidth() { return m_lineWidth; }

	/**
	 * \if English
	 * Set point size, useful for point mesh
	 *
	 * @param size point size
	 * \else
	 * 设置点大小, 对点式网格有效
	 *
	 * @param size 点大小
	 * \endif
	 */
	void setPointSize(float size) { m_pointSize = size; }

	/**
	 * \if English
	 * Get point size
	 *
	 * @return point size
	 * \else
	 * 得到点大小
	 *
	 * @return 点大小
	 * \endif
	 */
	float getPointSize() { return m_pointSize; }

	/**
	 * Get element count in mesh buffer
	 *
	 * @return element count
	 */
	virtual int getElementCount() = 0;
};

#endif // __wyMesh_h__
