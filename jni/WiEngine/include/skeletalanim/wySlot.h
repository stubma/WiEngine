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
#ifndef __wySlot_h__
#define __wySlot_h__

#include "wyObject.h"
#include "wyTypes.h"
#include "wyAttachment.h"

class wyBone;
class wySpriteEx;
class wySkeletalSprite;

/**
 * slot act as a container for something, and a slot is bound with a bone.
 */
class WIENGINE_API wySlot : public wyObject {
public:
	/// slot transform state
	struct State {
		/// color
		int color;
		
		/// active skin attachment name, wySlot doesn't copy it, so doesn't free it
		const char* activeAttachmentName;
		
		/// sprite, wySlot doesn't retain it
		wySpriteEx* sprite;
	};
    
    /// flags of slot
    enum Flag {
        /// slot attachment is fixed
        FIXED_ATTACHMENT = 0x1,
        
        /// bone color is fixed
        FIXED_COLOR = 0x2
    };
	
private:
	/// bone
	wyBone* m_bone;

	/// attachments
	typedef vector<wyAttachment*> AttachmentPtrList;
	AttachmentPtrList m_attachments;
    
    /// attachment map
    typedef map<const char*, wyAttachment*, wyStrPredicate> AttachmentMap;
    AttachmentMap m_attachmentMap;
	
	/// original state
	/// activeAttachmentName of original state need to be releaseds
	State m_originalState;
    
    /// flags
    int m_flags;
	
	/// state map for owner
	typedef map<wySkeletalSprite*, State> StateMap;
	StateMap m_stateMap;

protected:
	wySlot(wyBone* bone);

public:
	virtual ~wySlot();

	/**
	 * create a bone class
	 *
	 * @param parent parent bone, or NULL if no parent
	 */
	static wySlot* make(wyBone* bone);

	/// get bone
	wyBone* getBone() { return m_bone; }

	/// add attachment
	void addAttachment(wyAttachment* a);

	/// get active skin attachment for an owner, or NULL if not set
	wyAttachment* getActiveAttachment(wySkeletalSprite* owner);
    
    /// get attachment by its name, or NULL if not found
    wyAttachment* getAttachment(const char* name);
    
    /// get first attachment, or NULL if none
    wyAttachment* getFirstAttachment();
	
	/// get original state
	State& getOriginalState() { return m_originalState; }
	
	/// get state for an owner
	State& getState(wySkeletalSprite* owner);
	
	/// clear state of an owner
	void clearState(wySkeletalSprite* owner);
    
    /// add a flag
    void addFlag(Flag f) { m_flags |= f; }
    
    /// remove a flag
    void removeFlag(Flag f) { m_flags &= ~f; }
    
    /// get flag
    int getFlags() { return m_flags; }
    
    /// clear flags
    void clearFlags() { m_flags = 0; }
    
    /// has flag?
    bool hasFlag(Flag f) { return (m_flags & f) != 0; }
};

#endif // __wySlot_h__
