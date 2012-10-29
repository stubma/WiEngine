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
 * \c wyMesh is used to store rendering data. All visible elements in a scene are
 * represented by meshes.
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
	/// primitive modes
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

	/// connection to a shader attribute
	struct AttributeConnection {
		/// attribute name
		const char* name;

		/// attribute value
		wyShaderVariable::Value value;

		/// attribute type
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
	 * Is this mesh just a reference?
	 *
	 * @return true means the mesh is not real, just a reference to other mesh
	 */
	virtual bool isReference() { return false; }

	/**
	 * Get list of all connected attributes
	 *
	 * @return list of all connected attributes
	 */
	virtual vector<AttributeConnection*>* getConnections() { return m_attrConnections; }

	/**
	 * Get number of LOD datas
	 *
	 * @return number of LOD datas, maybe zero if no LOD data
	 */
	virtual int getNumberOfLodLevel() { return m_lodLevels == NULL ? 0 : m_lodLevels->size(); }

	/**
	 * Get mesh mode
	 *
	 * @return mesh mode
	 */
	virtual Mode getMode() { return m_mode; }

	/**
	 * Get indices buffer of specified level of detail, if lod level is not set then returns
	 * NULL
	 *
	 * @param lodLevel level of detail
	 * @return \link wyBuffer wyBuffer\endlink, or NULL if no lod set or \c lodLevel exceeds range
	 */
	virtual wyBuffer* getLodLevelBuffer(int lodLevel);

	/**
	 * Get first connected buffer, only valid if mesh has interleaved attribute bound
	 *
	 * @return first buffer object, or NULL if not found
	 */
	virtual wyBuffer* getFirstConnectedBuffer();

	/**
	 * Make a connection between mesh data to an attribute parameter
	 *
	 * @param name name of attribute
	 * @param buf data buffer object
	 * @param offset byte offset of attribute data in buffer
	 * @param components how many components of one vertex attribute
	 */
	void connectAttribute(const char* name, wyBuffer* buf, int offset, int components);

	/**
	 * Connect a float attribute
	 *
	 * @param name attribute name
	 * @param v float value
	 */
	void connectAttribute(const char* name, float v);

	/**
	 * Connect a 2d vector attribute
	 *
	 * @param name attribute name
	 * @param v 2d vector
	 */
	void connectAttribute(const char* name, kmVec2& v);

	/**
	 * Connect a 3d vector attribute
	 *
	 * @param name attribute name
	 * @param v 3d vector
	 */
	void connectAttribute(const char* name, kmVec3& v);

	/**
	 * Connect a 4d vector attribute
	 *
	 * @param name attribute name
	 * @param v 4d vector
	 */
	void connectAttribute(const char* name, kmVec4& v);

	/**
	 * Set level of detail data buffers
	 *
	 * @param buffers buffer list
	 * @param count count of buffers
	 */
	void setLodLevels(wyBuffer** buffers, int count);

	/**
	 * Set line width, useful for line mesh
	 *
	 * @param lineWidth line width
	 */
	void setLineWidth(float lineWidth) { m_lineWidth = lineWidth; }

	/**
	 * Get line width
	 *
	 * @return line width
	 */
	virtual float getLineWidth() { return m_lineWidth; }

	/**
	 * Set point size, useful for point mesh
	 *
	 * @param size point size
	 */
	void setPointSize(float size) { m_pointSize = size; }

	/**
	 * Get point size
	 *
	 * @return point size
	 */
	virtual float getPointSize() { return m_pointSize; }

	/**
	 * Get element count in mesh buffer
	 *
	 * @return element count
	 */
	virtual int getElementCount() = 0;

	/**
	 * Get render offset, it specified render start element position.
	 * By default, it is just zero.
	 *
	 * When the mesh has indices, the offset should be defined by render mode.
	 * For example, if render mode is triangle, then offset 1 means renderer should
	 * skip 3 indices.
	 *
	 * \note
	 * This method is intended to be overrided by subclass and used internally.
	 */
	virtual int getOffset() { return 0; }
};

#endif // __wyMesh_h__
