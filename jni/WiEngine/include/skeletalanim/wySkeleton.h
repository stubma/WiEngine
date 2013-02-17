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
#ifndef __wySkeleton_h__
#define __wySkeleton_h__

#include "wyObject.h"
#include "wyBone.h"
#include "wySlot.h"
#include "wySkin.h"
#include "wyTexture2D.h"

/**
 * general skeleton model
 */
class WIENGINE_API wySkeleton : public wyObject {
public:
	/// where the skeleton is loaded from
	enum Source {
		RESOURCE,
		ASSETS,
		FILE_SYSTEM,
		MEMORY_FILE_SYSTEM
	};
	
	/// slot list type
	typedef vector<wySlot*> SlotPtrList;
    
    /// default skin name
    static const char* DEFALT_SKIN_NAME;
	
private:
	/// bone map
	typedef map<const char*, wyBone*, wyStrPredicate> BoneMap;
	BoneMap m_boneMap;

	/// slot map
	typedef map<const char*, wySlot*, wyStrPredicate> SlotMap;
	SlotMap m_slotMap;
    
    /// skin map
    typedef map<const char*, wySkin*, wyStrPredicate> SkinMap;
    SkinMap m_skinMap;

	/// slot display list
	SlotPtrList m_slotDisplayList;
	
	/// source to load related resource
	Source m_source;
	
	/// path of skeleton file, used when source is not resource
	const char* m_path;

protected:
	wySkeleton();

public:
	virtual ~wySkeleton();
	static wySkeleton* make();
    
    /// create related texture from a relative image path
    static wyTexture2D* createRelatedTexture(wySkeleton* s, const char* name);

	/// add a bone, do nothing if bone with same name is existent
	void addBone(wyBone* bone);

	/// add a slot, do nothing if slot with same name is existent
	void addSlot(wySlot* slot);
    
    /// add a skin, do nothing if skin with same name is existent
    void addSkin(wySkin* skin);
	
	/// get root bone
	wyBone* getRootBone();

	/// get bone by name
	wyBone* getBone(const char* name);

	/// get slot by name
	wySlot* getSlot(const char* name);
    
    /// get skin by name
    wySkin* getSkin(const char* name);
	
	/// get slot display list
	SlotPtrList& getSlotDisplayList() { return m_slotDisplayList; }
	
	/// set source
	void setSource(Source s) { m_source = s; }
	
	/// get source
	Source getSource() { return m_source; }
	
	/// set path
	void setPath(const char* path);
	
	/// get path, caller should NOT release it
	const char* getPath() { return m_path; }

	/// dump info, for debug
	void dump();
};

#endif // __wySkeleton_h__
