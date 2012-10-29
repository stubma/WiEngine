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
#ifndef __wyMeshRef_h__
#define __wyMeshRef_h__

#include "wyMesh.h"
#include "WiEngine-Classes.h"

/**
 * A reference to other mesh
 */
class WIENGINE_API wyMeshRef : public wyMesh {
private:
	/// source mesh
	wyMesh* m_mesh;

	/// render offset
	int m_offset;

	/// element count
	int m_elementCount;

protected:
	/**
	 * Constructor
	 *
	 * @param mesh source mesh
	 */
	wyMeshRef(wyMesh* mesh);

public:
	virtual ~wyMeshRef();

	/**
	 * Create a mesh reference
	 *
	 * @param mesh source mesh
	 */
	static wyMeshRef* make(wyMesh* mesh);

	/// @see wyMesh::isReference
	virtual bool isReference() { return true; }

	/// @see wyMesh::getElementCount
	virtual int getElementCount() { return m_elementCount; }

	/// @see wyMesh::getOffset
	virtual int getOffset() { return m_offset; }

	/// @see wyMesh::getConnections
	virtual vector<AttributeConnection*>* getConnections() { return m_mesh->getConnections(); }

	/// @see wyMesh::getNumberOfLodLevel
	virtual int getNumberOfLodLevel() { return m_mesh->getNumberOfLodLevel(); }

	/// @see wyMesh::getMode
	virtual Mode getMode() { return m_mesh->getMode(); }

	/// @see wyMesh::getLodLevelBuffer
	virtual wyBuffer* getLodLevelBuffer(int lodLevel) { return m_mesh->getLodLevelBuffer(lodLevel); }

	/// @see wyMesh::getFirstConnectedBuffer
	virtual wyBuffer* getFirstConnectedBuffer() { return m_mesh->getFirstConnectedBuffer(); }

	/// @see wyMesh::getLineWidth
	virtual float getLineWidth() { return m_mesh->getLineWidth(); }

	/// @see wyMesh::getPointSize
	virtual float getPointSize() { return m_mesh->getPointSize(); }

	/// set element count
	void setElementCount(int c) { m_elementCount = c; }

	/// set render offset
	void setOffset(int offset) { m_offset = offset; }

	/// set source mesh
	void setMesh(wyMesh* mesh);

	/// get source mesh
	wyMesh* getMesh() { return m_mesh; }
};

#endif // __wyMeshRef_h__
