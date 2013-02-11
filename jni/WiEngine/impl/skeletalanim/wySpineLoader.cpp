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
#include "wySpineLoader.h"
#include "wyJSONObject.h"
#include "wyJSONArray.h"
#include "wyJSONParser.h"
#include "wyUtils.h"
#include "wySkinAttachment.h"

wySkeleton* wySpineLoader::loadSkeleton(wyJSONObject* jo, float scale) {
	wySkeleton* skeleton = wySkeleton::make();

	// parse bones
	wyJSONObject* bonesJO = jo->optJSONObject("bones");
	int size = bonesJO->getLength();
	for(int i = 0; i < size; i++) {
		// get key and json for this bone
		const char* key = bonesJO->keyAt(i);
		wyJSONObject* boneJO = bonesJO->optJSONObject(i);

		// get parent bone for this bone
		const char* parentKey = boneJO->optString("parent");
		wyBone* parent = parentKey == NULL ? NULL : skeleton->getBone(parentKey);

		// create this bone
		wyBone* bone = wyBone::make(parent);

		// set other property
		bone->setName(key);
		bone->setLength(boneJO->optFloat("length"));
		bone->setX(boneJO->optFloat("x"));
		bone->setY(boneJO->optFloat("y"));
		bone->setRotation(boneJO->optFloat("rotation"));
		bone->setScaleX(boneJO->optFloat("scale_x", 1));
		bone->setScaleY(boneJO->optFloat("scale_y", 1));

		// add bone
		skeleton->addBone(bone);
	}

	// parse slots
	wyJSONObject* slotsJO = jo->optJSONObject("slots");
	size = slotsJO->getLength();
	for(int i = 0; i < size; i++) {
		// get key and json for this slot
		const char* key = slotsJO->keyAt(i);
		wyJSONObject* slotJO = slotsJO->optJSONObject(i);

		// get bone for this slot
		const char* boneKey = slotJO->optString("bone");
		wyBone* bone = skeleton->getBone(boneKey);

		// create slot
		wySlot* slot = wySlot::make(bone);

		// set name
		slot->setName(key);

		// set color
		int color = slotJO->optInt("color", 0xffffffff);
		slot->setColor(wyc4bFromInteger(color));

		// set active skin attachment name
		const char* attName = slotJO->optString("attachment");
		if(attName) {
			slot->setActiveSkinAttachmentName(attName);
		}

		// add slot
		skeleton->addSlot(slot);
	}

	// parse skin attachment
	wyJSONObject* skinsJO = jo->optJSONObject("skins");
	size = skinsJO->getLength();
	for(int i = 0; i < size; i++) {
		wyJSONObject* skinJO = skinsJO->optJSONObject(i);
		int slotSize = skinJO->getLength();
		for(int j = 0; j < slotSize; j++) {
			// get slot
			const char* slotKey = skinJO->keyAt(j);
			wySlot* slot = skeleton->getSlot(slotKey);
			if(!slot)
				continue;

			// get json of attachments
			wyJSONObject* attachmentsJO = skinJO->optJSONObject(j);
			int attSize = attachmentsJO->getLength();

			// parse every attachment
			for(int k = 0; k < attSize; k++) {
				// get attachment name
				const char* attKey = attachmentsJO->keyAt(k);
				wyJSONObject* attachmentJO = attachmentsJO->optJSONObject(k);

				// create skin attachment
				wySkinAttachment* skinAtt = wySkinAttachment::make();
				skinAtt->setName(attKey);

				// set other property
				skinAtt->setX(attachmentJO->optFloat("x"));
				skinAtt->setY(attachmentJO->optFloat("y"));
				skinAtt->setRotation(attachmentJO->optFloat("rotation"));
				skinAtt->setScaleX(attachmentJO->optFloat("scale_x", 1));
				skinAtt->setScaleY(attachmentJO->optFloat("scale_y", 1));

				// add attachment
				slot->addAttachment(skinAtt);
			}
		}
	}

	// return
	return skeleton;
}

wySkeleton* wySpineLoader::loadSkeleton(int resId) {
	float scale;
	char* data = wyUtils::loadRaw(resId, NULL, &scale);
	wyFree(data);
	return loadSkeleton(wyJSONObject::make(resId), scale);
}

wySkeleton* wySpineLoader::loadSkeleton(const char* path, bool isFile) {
	return loadSkeleton(wyJSONObject::make(path, isFile), wyDevice::density / wyDevice::defaultInDensity);
}

wySkeleton* wySpineLoader::loadSkeleton(const char* raw, size_t length) {
	return loadSkeleton(wyJSONObject::make(raw, length), wyDevice::density / wyDevice::defaultInDensity);
}

wySkeleton* wySpineLoader::loadMemorySkeleton(const char* mfsName) {
	return loadSkeleton(wyJSONObject::make(mfsName), wyDevice::density / wyDevice::defaultInDensity);
}
