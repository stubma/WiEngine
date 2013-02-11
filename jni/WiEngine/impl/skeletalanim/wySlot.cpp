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
#include "wySlot.h"
#include "wyBone.h"
#include "wyUtils.h"
#include "wySkinAttachment.h"

wySlot::wySlot(wyBone* bone) :
		m_bone(bone),
		m_color(wyc4bWhite),
		m_activeSkinAttachmentName(NULL),
		m_sprite(NULL) {
	wyObjectRetain(m_bone);
}

wySlot::~wySlot() {
	wyObjectRelease(m_bone);
	for(AttachmentPtrList::iterator iter = m_attachments.begin(); iter != m_attachments.end(); iter++) {
		wyObjectRelease(*iter);
	}
	if(m_activeSkinAttachmentName) {
		wyFree((void*)m_activeSkinAttachmentName);
	}
}

wySlot* wySlot::make(wyBone* bone) {
	wySlot* s = WYNEW wySlot(bone);
	return (wySlot*)s->autoRelease();
}

void wySlot::addAttachment(wyAttachment* a) {
	m_attachments.push_back(a);
	wyObjectRetain(a);
}

void wySlot::setActiveSkinAttachmentName(const char* name) {
	if(m_activeSkinAttachmentName) {
		wyFree((void*)m_activeSkinAttachmentName);
		m_activeSkinAttachmentName = NULL;
	}
	m_activeSkinAttachmentName = wyUtils::copy(name);
}

wySkinAttachment* wySlot::getActiveSkinAttachment() {
	if(!m_activeSkinAttachmentName)
		return NULL;

	for(AttachmentPtrList::iterator iter = m_attachments.begin(); iter != m_attachments.end(); iter++) {
		if(!strcmp((*iter)->getName(), m_activeSkinAttachmentName))
			return (wySkinAttachment*)*iter;
	}

	return NULL;
}
