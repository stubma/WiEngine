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
#include "wyAttachment.h"
#include "wyBoneTransform.h"
#include "wySlotTransform.h"

wySkeleton* wySpineLoader::loadSkeleton(wyJSONObject* jo, float scale) {
	wySkeleton* skeleton = wySkeleton::make();

	// parse bones
	wyJSONArray* bonesJA = jo->optJSONArray("bones");
	int size = bonesJA->getLength();
	for(int i = 0; i < size; i++) {
		// get key and json for this bone
		wyJSONObject* boneJO = bonesJA->optJSONObject(i);
        const char* key = boneJO->optString("name");

		// get parent bone for this bone
		const char* parentKey = boneJO->optString("parent");
		wyBone* parent = parentKey == NULL ? NULL : skeleton->getBone(parentKey);

		// create this bone
		wyBone* bone = wyBone::make();
		
		// add to parent
		if(parent)
			parent->addChild(bone);

		// set other property
		wyBone::State& state = bone->getOriginalState();
		bone->setName(key);
		bone->setLength(boneJO->optFloat("length") * scale);
		state.x = boneJO->optFloat("x") * scale;
		state.y = boneJO->optFloat("y") * scale;
		state.rotation = boneJO->optFloat("rotation");
		state.scaleX = boneJO->optFloat("scaleX", 1);
		state.scaleY = boneJO->optFloat("scaleY", 1);

		// add bone
		skeleton->addBone(bone);
	}

	// parse slots
	wyJSONArray* slotsJA = jo->optJSONArray("slots");
	size = slotsJA->getLength();
	for(int i = 0; i < size; i++) {
		// get key and json for this slot
		wyJSONObject* slotJO = slotsJA->optJSONObject(i);
        const char* key = slotJO->optString("name");

		// get bone for this slot
		const char* boneKey = slotJO->optString("bone");
		wyBone* bone = skeleton->getBone(boneKey);

		// create slot
		wySlot* slot = wySlot::make(bone);

		// set name
		slot->setName(key);

		// set color
		wySlot::State& state = slot->getOriginalState();
		state.color = slotJO->optInt("color", 0xffffffff);

		// set active skin attachment name
		const char* attName = slotJO->optString("attachment");
		if(attName) {
			state.activeAttachmentName = wyUtils::copy(attName);
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
                
                // name attribute, if not existent, use the key from the surrounding JSON map
                const char* name = attachmentJO->optString("name");

				// create skin attachment
				wyAttachment* skinAtt = wyAttachment::make();
				skinAtt->setName(name ? name : attKey);

				// set other property
				skinAtt->setX(attachmentJO->optFloat("x") * scale);
				skinAtt->setY(attachmentJO->optFloat("y") * scale);
				skinAtt->setRotation(attachmentJO->optFloat("rotation"));
				skinAtt->setScaleX(attachmentJO->optFloat("scaleX", 1));
				skinAtt->setScaleY(attachmentJO->optFloat("scaleY", 1));

				// add attachment
				slot->addAttachment(skinAtt);
			}
		}
	}

	// return
	return skeleton;
}

wySkeletalAnimation* wySpineLoader::loadAnimation(wyJSONObject* jo, float scale) {
	wySkeletalAnimation* anim = wySkeletalAnimation::make();
	
	// duration time
	float duration = 0;
	
	// get bones object
	wyJSONObject* bonesJO = jo->optJSONObject("bones");
	if(bonesJO) {
		// iterate every bone
		int size = bonesJO->getLength();
		for(int i = 0; i < size; i++) {
			// get bone key and bone transform json object
			const char* boneKey = bonesJO->keyAt(i);
			wyJSONObject* btJO = bonesJO->optJSONObject(i);
			
			// create transform
			wyBoneTransform* bt = wyBoneTransform::make();
			bt->setBoneName(boneKey);
			
			// get rotation key frames
			wyJSONArray* rkfListJA = btJO->optJSONArray("rotate");
			if(rkfListJA) {
				int kfCount = rkfListJA->getLength();
				for(int j = 0; j < kfCount; j++) {
					// get time and angle
					wyJSONObject* rkfJO = rkfListJA->optJSONObject(j);
					wyBoneTransform::RotationKeyFrame kf;
					kf.time = rkfJO->optFloat("time");
					kf.angle = rkfJO->optFloat("angle");
					
					// save max time as duration
					duration = MAX(duration, kf.time);
					
					// get interpolator
					wyJSONArray* curveJA = rkfJO->optJSONArray("curve");
					if(curveJA) {
						kf.interpolator.type = wyTransform::BEZIER;
						kf.interpolator.cp1X = curveJA->optFloat(0);
						kf.interpolator.cp1Y = curveJA->optFloat(1);
						kf.interpolator.cp2X = curveJA->optFloat(2);
						kf.interpolator.cp2Y = curveJA->optFloat(3);
					} else {
						const char* curveStr = rkfJO->optString("curve");
						if(curveStr && !strcmp(curveStr, "stepped"))
							kf.interpolator.type = wyTransform::STEP;
						else
							kf.interpolator.type = wyTransform::LINEAR;
					}
					
					// add key frame
					bt->addRotationKeyFrame(kf);
				}
			} // end if(rkfListJO)
			
			// get translation key frames
			wyJSONArray* tkfListJA = btJO->optJSONArray("translate");
			if(tkfListJA) {
				int kfCount = tkfListJA->getLength();
				for(int j = 0; j < kfCount; j++) {
					// get time, x and y
					wyJSONObject* tkfJO = tkfListJA->optJSONObject(j);
					wyBoneTransform::TranslationKeyFrame kf;
					kf.time = tkfJO->optFloat("time");
					kf.x = tkfJO->optFloat("x") * scale;
					kf.y = tkfJO->optFloat("y") * scale;
					
					// save max time as duration
					duration = MAX(duration, kf.time);
					
					// get interpolator
					wyJSONArray* curveJA = tkfJO->optJSONArray("curve");
					if(curveJA) {
						kf.interpolator.type = wyTransform::BEZIER;
						kf.interpolator.cp1X = curveJA->optFloat(0);
						kf.interpolator.cp1Y = curveJA->optFloat(1);
						kf.interpolator.cp2X = curveJA->optFloat(2);
						kf.interpolator.cp2Y = curveJA->optFloat(3);
					} else {
						const char* curveStr = tkfJO->optString("curve");
						if(curveStr && !strcmp(curveStr, "stepped"))
							kf.interpolator.type = wyTransform::STEP;
						else
							kf.interpolator.type = wyTransform::LINEAR;
					}
					
					// add key frame
					bt->addTranslationKeyFrame(kf);
				}
			} // end if(tkfListJO)
			
			// get scale key frames
			wyJSONArray* skfListJA = btJO->optJSONArray("scale");
			if(skfListJA) {
				int kfCount = skfListJA->getLength();
				for(int j = 0; j < kfCount; j++) {
					// get time, x and y
					wyJSONObject* skfJO = skfListJA->optJSONObject(j);
					wyBoneTransform::ScaleKeyFrame kf;
					kf.time = skfJO->optFloat("time");
					kf.scaleX = skfJO->optFloat("x");
					kf.scaleY = skfJO->optFloat("y");
					
					// save max time as duration
					duration = MAX(duration, kf.time);
					
					// get interpolator
					wyJSONArray* curveJA = skfJO->optJSONArray("curve");
					if(curveJA) {
						kf.interpolator.type = wyTransform::BEZIER;
						kf.interpolator.cp1X = curveJA->optFloat(0);
						kf.interpolator.cp1Y = curveJA->optFloat(1);
						kf.interpolator.cp2X = curveJA->optFloat(2);
						kf.interpolator.cp2Y = curveJA->optFloat(3);
					} else {
						const char* curveStr = skfJO->optString("curve");
						if(curveStr && !strcmp(curveStr, "stepped"))
							kf.interpolator.type = wyTransform::STEP;
						else
							kf.interpolator.type = wyTransform::LINEAR;
					}
					
					// add key frame
					bt->addScaleKeyFrame(kf);
				}
			} // end if(skfListJO)
			
			// add transform
			anim->addTransform(bt);
		} // end for
	} // end if(bonesJO)

	// get slots json
	wyJSONObject* slotsJO = jo->optJSONObject("slots");
	if(slotsJO) {
		// iterate every slot
		int size = slotsJO->getLength();
		for(int i = 0; i < size; i++) {
			// get slot key and slot transform json object
			const char* slotKey = slotsJO->keyAt(i);
			wyJSONObject* stJO = slotsJO->optJSONObject(i);
			
			// create transform
			wySlotTransform* st = wySlotTransform::make();
			st->setSlotName(slotKey);
			
			// get slot skin key frames
			wyJSONArray* skfListJA = stJO->optJSONArray("attachment");
			if(skfListJA) {
				int kfCount = skfListJA->getLength();
				for(int j = 0; j < kfCount; j++) {
					// get time and skin name
                    wyJSONObject* skfJO = skfListJA->optJSONObject(j);
					wySlotTransform::SkinKeyFrame kf;
					kf.time = skfJO->optFloat("time");
					kf.skinName = wyUtils::copy(skfJO->optString("name"));
					
					// save max time as duration
					duration = MAX(duration, kf.time);
					
					// interpolator for skin transform is always STEP
					kf.interpolator.type = wyTransform::STEP;
					
					// add key frame
					// addSkinKeyFrame doesn't copy skin name, so no need to release it
					st->addSkinKeyFrame(kf);
				}
			}
			
			// get slot color key frame
			wyJSONArray* ckfListJA = stJO->optJSONArray("color");
			if(ckfListJA) {
				int kfCount = ckfListJA->getLength();
				for(int j = 0; j < kfCount; j++) {
					// get time and color
					wyJSONObject* ckfJO = ckfListJA->optJSONObject(j);
					wySlotTransform::ColorKeyFrame kf;
					kf.time = ckfJO->optFloat("time");
					kf.color = ckfJO->optInt("color", 0xffffffff);
					
					// save max time as duration
					duration = MAX(duration, kf.time);
					
					// get interpolator
					wyJSONArray* curveJA = ckfJO->optJSONArray("curve");
					if(curveJA) {
						kf.interpolator.type = wyBoneTransform::BEZIER;
						kf.interpolator.cp1X = curveJA->optFloat(0);
						kf.interpolator.cp1Y = curveJA->optFloat(1);
						kf.interpolator.cp2X = curveJA->optFloat(2);
						kf.interpolator.cp2Y = curveJA->optFloat(3);
					} else {
						const char* curveStr = ckfJO->optString("curve");
						if(curveStr && !strcmp(curveStr, "stepped"))
							kf.interpolator.type = wyBoneTransform::STEP;
						else
							kf.interpolator.type = wyBoneTransform::LINEAR;
					}
					
					// add key frame
					st->addColorKeyFrame(kf);
				}
			}
			
			// add transform
			anim->addTransform(st);
		} // end for
	} // end if(slotsJO)

	// set duration
	anim->m_duration = duration;

	// return
	return anim;
}

wySkeleton* wySpineLoader::loadSkeleton(int resId) {
	float scale;
	char* data = wyUtils::loadRaw(resId, NULL, &scale);
	wyFree(data);
	wySkeleton* skeleton = loadSkeleton(wyJSONObject::make(resId), scale);
	skeleton->setSource(wySkeleton::RESOURCE);
	return skeleton;
}

wySkeleton* wySpineLoader::loadSkeleton(const char* path, bool isFile) {
	wySkeleton* skeleton = loadSkeleton(wyJSONObject::make(path, isFile), wyDevice::density / wyDevice::defaultInDensity);
	skeleton->setSource(isFile ? wySkeleton::FILE_SYSTEM : wySkeleton::ASSETS);
	skeleton->setPath(path);
	return skeleton;
}

wySkeleton* wySpineLoader::loadMemorySkeleton(const char* mfsName) {
	wySkeleton* skeleton = loadSkeleton(wyJSONObject::make(mfsName), wyDevice::density / wyDevice::defaultInDensity);
	skeleton->setSource(wySkeleton::MEMORY_FILE_SYSTEM);
	skeleton->setPath(mfsName);
	return skeleton;
}

wySkeletalAnimation* wySpineLoader::loadAnimation(int resId) {
	float scale;
	char* data = wyUtils::loadRaw(resId, NULL, &scale);
	wyFree(data);
	return loadAnimation(wyJSONObject::make(resId), scale);
}

wySkeletalAnimation* wySpineLoader::loadAnimation(const char* path, bool isFile) {
	return loadAnimation(wyJSONObject::make(path, isFile), wyDevice::density / wyDevice::defaultInDensity);
}

wySkeletalAnimation* wySpineLoader::loadMemoryAnimation(const char* mfsName) {
	return loadAnimation(wyJSONObject::make(mfsName), wyDevice::density / wyDevice::defaultInDensity);
}
