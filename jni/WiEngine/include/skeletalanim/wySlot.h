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
class wySkinAttachment;

/**
 * slot act as a container for something, and a slot is bound with a bone.
 */
class WIENGINE_API wySlot : public wyObject {
private:
	/// bone
	wyBone* m_bone;

	/// color
	wyColor4B m_color;

	/// attachments
	typedef vector<wyAttachment*> AttachmentPtrList;
	AttachmentPtrList m_attachments;

	/// active skin attachment name
	const char* m_activeSkinAttachmentName;
	
	/// related sprite
	wySpriteEx* m_sprite;

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
	
	/// set sprite
	void setSprite(wySpriteEx* sprite) { m_sprite = sprite; }
	
	/// get sprite
	wySpriteEx* getSprite() { return m_sprite; }

	/// get bone
	wyBone* getBone() { return m_bone; }

	/// set color
	void setColor(wyColor4B color) { m_color = color; }

	/// get color
	wyColor4B getColor() { return m_color; }

	/// add attachment
	void addAttachment(wyAttachment* a);

	/// set active skin attachment name
	void setActiveSkinAttachmentName(const char* name);

	/// get active skin attachment name, caller should NOT release returned string
	const char* getActiveSkinAttachmentName() { return m_activeSkinAttachmentName; }

	/// get active skin attachment, or NULL if not set
	wySkinAttachment* getActiveSkinAttachment();
};

#endif // __wySlot_h__
