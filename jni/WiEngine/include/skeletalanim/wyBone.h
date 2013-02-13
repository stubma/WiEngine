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
#ifndef __wyBone_h__
#define __wyBone_h__

#include "wyNode.h"

class wySkeletalSprite;

/**
 * bone
 */
class WIENGINE_API wyBone : public wyObject {
public:
	/// bone pointer list
	typedef vector<wyBone*> BonePtrList;
	
	/// bone transform state
	struct State {
		/// x offset
		float x;
		
		/// y offset
		float y;
		
		/// rotation in degree, positive value means counter-clockwise, x axis is zero degree
		float rotation;
		
		/// x scale
		float scaleX;
		
		/// y scale
		float scaleY;
		
		/// bone node
		wyNode* node;
	};
	
private:
	/// parent bone
	wyBone* m_parent;

	/// bone length
	float m_length;
	
	/// current state
	State m_originalState;
	
	/// child bones
	BonePtrList m_children;
	
	/// state map
	typedef map<wySkeletalSprite*, State> StateMap;
	StateMap m_stateMap;

protected:
	wyBone();
	
	/// set parent
	void setParent(wyBone* parent) { m_parent = parent; }

public:
	virtual ~wyBone();

	/**
	 * create a bone class
	 *
	 * @param parent parent bone, or NULL if no parent
	 */
	static wyBone* make();
	
	/// add child bone
	void addChild(wyBone* bone);
	
	/// get children bone list
	BonePtrList& getChildren() { return m_children; }

	/// get parent bone
	wyBone* getParent() { return m_parent; }

	/// set length
	void setLength(float len) { m_length = len; }

	/// get length
	float getLength() { return m_length; }
	
	/// get bone state for an owner
	State& getState(wySkeletalSprite* owner);
	
	/// remove state for an owner
	void clearState(wySkeletalSprite* owner);

	/// get original x offset
	State& getOriginalState() { return m_originalState; }
};

#endif // __wyBone_h__
