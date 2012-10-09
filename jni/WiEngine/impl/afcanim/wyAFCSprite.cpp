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
#include "wyAFCSprite.h"
#include "wyLog.h"
#include "wyPrimitives.h"
#include <stdarg.h>

#if ANDROID
#include "wyUtils_android.h"

extern jmethodID g_mid_IAFCSpriteCallback_onAFCAnimationFrameChanged;
extern jmethodID g_mid_IAFCSpriteCallback_onAFCAnimationEnded;
#endif

wyAFCSprite::wyAFCSprite() :
		m_spriteList(wyArrayNew(10)),
		m_sheetList(wyArrayNew(5)),
		m_mappingList(wyArrayNew(5)),
		m_animationData(NULL),
		m_curAnimationIndex(-1),
		m_curFrame(0),
		m_numOfFrame(0),
		m_frameDuration(0),
		m_isTickDelay(false),
		m_forceTickMode(false),
		m_elapsed(0),
		m_unitInterval(0),
		m_isReverse(false),
		m_loop(0),
		m_isAnimationEnded(false),
		m_paused(false),
		m_debugDrawFrameRect(false),
		m_debugDrawCollisionRect(false),
		m_color(wyc4bWhite),
		m_blendFunc(wybfDefault),
		m_callback(NULL),
#if ANDROID
		m_jCallback(NULL),
#endif
		m_frameOffset(wypZero),
		m_ignoreFrameOffset(false),
		m_flipX(false),
		m_flipY(false),
		m_data(NULL) {
}

wyAFCSprite::~wyAFCSprite() {
	if(m_callback != NULL) {
		wyFree(m_callback);
		m_callback = NULL;
	}
#if ANDROID
	if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->DeleteGlobalRef(m_jCallback);
		m_jCallback = NULL;
	}
#endif
	wyArrayEach(m_spriteList, releaseObject, NULL);
	wyArrayDestroy(m_spriteList);
	wyArrayEach(m_sheetList, releaseObject, NULL);
	wyArrayDestroy(m_sheetList);
	wyArrayEach(m_mappingList, releaseObject, NULL);
	wyArrayDestroy(m_mappingList);
	wyObjectRelease(m_animationData);
}

bool wyAFCSprite::releaseObject(wyArray* arr, void* ptr, int index, void* data) {
	wyObjectRelease((wyObject*)ptr);
	return true;
}

void wyAFCSprite::invokeOnAFCAnimationFrameChanged() {
	if(m_callback != NULL) {
		if(m_callback->onAFCAnimationFrameChanged != NULL)
			m_callback->onAFCAnimationFrameChanged(this, m_data);
	}
#if ANDROID
	else if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->CallVoidMethod(m_jCallback, g_mid_IAFCSpriteCallback_onAFCAnimationFrameChanged, (jint)this);
	}
#endif
}

void wyAFCSprite::invokeOnAFCAnimationEnded() {
	if(m_callback != NULL) {
		if(m_callback->onAFCAnimationEnded != NULL)
			m_callback->onAFCAnimationEnded(this, m_data);
	}
#if ANDROID
	else if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->CallVoidMethod(m_jCallback, g_mid_IAFCSpriteCallback_onAFCAnimationEnded, (jint)this);
	}
#endif
}

void wyAFCSprite::setAnimationData(wyAFCAnimation* data) {
	wyObjectRetain(data);
	wyObjectRelease(m_animationData);
	m_animationData = data;
}

void wyAFCSprite::initSpriteFromAnimationData() {
	int maxClipNum = 0;
	for(int i = 0; i < m_numOfFrame; i++) {
		wyAFCFrame* fd = m_animationData->getFrameAt(i);
		maxClipNum = MAX(fd->getClipCount(), maxClipNum);
	}

	int numDifference = maxClipNum - m_spriteList->num;
	for(int i = 0; i < numDifference; i++) {
		wySpriteEx* sprite = WYNEW wySpriteEx();
		sprite->setColor(m_color);
		wyArrayPush(m_spriteList, sprite);
	}
}

void wyAFCSprite::replaceTextures(wyTexture2D* tex, ...) {
	// release old batch nodes
	wyArrayEach(m_spriteList, releaseObject, NULL);
	wyArrayClear(m_spriteList);
	wyArrayEach(m_sheetList, releaseObject, NULL);
	wyArrayClear(m_sheetList);

	// for first texture
	wySpriteBatchNode* sheet = wySpriteBatchNode::make(tex);
	wyArrayPush(m_sheetList, sheet);
	sheet->retain();

	// create new sprite batch node for new set of textures
	va_list textures;
	va_start(textures, tex);
	for(wyTexture2D* t = va_arg(textures, wyTexture2D*); t != NULL; t = va_arg(textures, wyTexture2D*)) {
		sheet = wySpriteBatchNode::make(t);
		wyArrayPush(m_sheetList, sheet);
		sheet->retain();
	}
	va_end(textures);

	// start animation from very beginning
	if(m_curAnimationIndex >= 0)
		playAnimation(m_curAnimationIndex);
}

void wyAFCSprite::replaceTextures(wyTexture2D** tex, int count) {
	/*
	 * 这里我们不首先释放老的batchnode, 这是因为如果replaceTextures传进来
	 * 的贴图有部分和以前一样, 那么如果先释放老的, 会导致这些贴图对象被释放,
	 * 从而后面再创建新的batchnode就会有问题. 这个道理和setter里面要先retain
	 * 进来的, 再release老的是一个道理
	 */

	// create new sprite batch node for new set of textures
	wyArray* tmp = wyArrayNew(count);
	for(int i = 0; i < count; i++) {
		wySpriteBatchNode* sheet = wySpriteBatchNode::make(tex[i]);
		wyArrayPush(tmp, sheet);
		sheet->retain();
	}

	// release old batch nodes
	wyArrayEach(m_spriteList, releaseObject, NULL);
	wyArrayClear(m_spriteList);
	wyArrayEach(m_sheetList, releaseObject, NULL);
	wyArrayDestroy(m_sheetList);
	m_sheetList = tmp;

	// start animation from very beginning
	if(m_curAnimationIndex >= 0)
		playAnimation(m_curAnimationIndex);
}

void wyAFCSprite::initFrameOffset() {
	m_frameOffset.x = m_frameOffset.y = 0;
	if(m_isReverse) {
		// because reverse, so we need calculate frame offset first
		int frameCount = m_animationData->getFrameCount();
		for(int i = 0; i < frameCount; i++) {
			wyAFCFrame* frameData = m_animationData->getFrameAt(i);
			wyPoint inc = frameData->getIncrementation();
			m_frameOffset.x += inc.x;
			m_frameOffset.y += inc.y;
		}
	}
}

void wyAFCSprite::adjustFrameOffset(wyAFCFrame* frameData) {
	wyPoint inc = frameData->getIncrementation();
	if(m_isReverse) {
		m_frameOffset.x -= inc.x;
		m_frameOffset.y -= inc.y;
	} else {
		m_frameOffset.x += inc.x;
		m_frameOffset.y += inc.y;
	}
}

void wyAFCSprite::updateColor() {
	for(int i = 0; i < m_spriteList->num; i++) {
		wySpriteEx* sprite = (wySpriteEx*)wyArrayGet(m_spriteList, i);
		sprite->setColor(m_color);
	}
}

void wyAFCSprite::setBlendFunc(wyBlendFunc func) {
	m_blendFunc = func;
	for(int i = 0; i < m_sheetList->num; i++) {
		wySpriteBatchNode* bn = (wySpriteBatchNode*)wyArrayGet(m_sheetList, i);
		//bn->setBlendFunc(func);
	}
}

void wyAFCSprite::setAlpha(int alpha) {
	m_color.a = alpha;
	updateColor();
}

wyColor3B wyAFCSprite::getColor() {
	wyColor3B c = {
		m_color.r,
		m_color.g,
		m_color.b
	};
	return c;
}

void wyAFCSprite::setColor(wyColor3B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	updateColor();
}

void wyAFCSprite::setColor(wyColor4B color) {
	m_color.r = color.r;
	m_color.g = color.g;
	m_color.b = color.b;
	m_color.a = color.a;
	updateColor();
}

void wyAFCSprite::visit() {
	// TODO gles2
//	if(!m_visible)
//		return;
//
//	// should push matrix to avoid disturb current matrix
//	glPushMatrix();
//
//	// if grid is set, prepare grid
//	if(m_grid != NULL && m_grid->isActive()) {
//		m_grid->beforeDraw();
//		transformAncestors();
//	}
//
//	// transform for myself
//	transform();
//
//	// check clip
//	if(m_hasClip)
//		doClip();
//
//	// draw self
//	draw();
//
//	// restore
//	if(m_hasClip)
//		glDisable(GL_SCISSOR_TEST);
//
//	// if grid is set, end grid
//	if(m_grid != NULL && m_grid->isActive()) {
//		m_grid->afterDraw(this);
//	}
//
//	// pop matrix
//	glPopMatrix();
}

void wyAFCSprite::draw() {
	// TODO gles2
//	// if no draw flag is set, call wyNode::draw and it
//	// will decide forward drawing to java layer or not
//	if(m_noDraw) {
//		wyNode::draw();
//		return;
//	}
//
//	// is current frame valid?
//	if(m_curFrame < 0 || m_curFrame >= m_animationData->getFrameCount())
//		return;
//
//	// reset marker of all sheet to zero
//	for(int i = 0; i < m_spriteList->num; i++) {
//		wySpriteEx* sprite = (wySpriteEx*)wyArrayGet(m_spriteList, i);
//		if(sprite->isVisible()) {
//			wySpriteBatchNode* sheet = (wySpriteBatchNode*)sprite->getParent();
//			sheet->setMarker(0);
//		} else {
//			break;
//		}
//	}
//
//	// draw based on clip order
//	int numOfQuads = 0;
//	wySpriteBatchNode* lastSheet = NULL;
//	for(int i = 0; i < m_spriteList->num; i++) {
//		wySpriteEx* sprite = (wySpriteEx*)wyArrayGet(m_spriteList, i);
//		if(sprite->isVisible()) {
//			wySpriteBatchNode* sheet = (wySpriteBatchNode*)sprite->getParent();
//			if(sheet != lastSheet) {
//				// draw last sheet
//				if(numOfQuads != 0) {
//					lastSheet->drawFromMarker(numOfQuads);
//				}
//
//				// change last sheet and reset number of quads
//				lastSheet = sheet;
//				numOfQuads = 1;
//			} else {
//				numOfQuads++;
//			}
//		}
//	}
//
//	// draw last sheet
//	if(numOfQuads != 0) {
//		lastSheet->drawFromMarker(numOfQuads);
//	}
//
//	// check debug draw flag
//	if(m_debugDrawFrameRect) {
//		wyRect bound = getFrameRect();
//		glColor4f(0, 1, 0, 1);
//		wyDrawRect2(bound);
//		glColor4f(1, 1, 1, 1);
//	}
//	if(m_debugDrawCollisionRect) {
//		glColor4f(0, 1, 0, 1);
//		wyAFCAnimation* anim = getCurrentAnimationData();
//		if(anim) {
//			wyAFCFrame* frame = anim->getFrameAt(m_curFrame);
//			if(frame) {
//				int count = frame->getClipCount();
//				for (int i = 0; i < count; i++) {
//					wyAFCClip* clip = frame->getClipAt(i);
//					if(clip->getType() == AFC_CLIP_COLLISION_RECT) {
//						wyAFCClipData& data = clip->getData();
//						wyRect r = wyr(data.clipPos.x - data.cr.size.width / 2,
//								data.clipPos.y - data.cr.size.height / 2,
//								data.cr.size.width,
//								data.cr.size.height);
//
//						// check flip flag
//						if(m_flipX) {
//							r.x = -r.x - r.width;
//						}
//						if(m_flipY) {
//							r.y = -r.y - r.height;
//						}
//
//						// draw it
//						wyDrawRect2(r);
//					}
//				}
//			}
//		}
//		glColor4f(1, 1, 1, 1);
//	}
}

void wyAFCSprite::addChild(wyNode* child, int z, int tag) {
    wySpriteBatchNode* bn = dynamic_cast<wySpriteBatchNode*>(child);
    if(!bn){
        LOGW("wyMWSprite::addChild: Can't add a non-wySpriteBatchNode as child");
        return;
    }

    wyNode::addChild(child, z, tag);
}

void wyAFCSprite::playAnimation(int index, wyAFCClipMapping* mapping) {
	// validate index
	if(index < 0 || index >= getAnimationCount()) {
		LOGW("wyAFCSprite::playAnimation: index %d is out of range", index);
		return;
	}

	// refresh animation data
	setAnimationData(getAnimationAt(index, mapping));

	// reset frame index and ensure sprite pool is big enough
	m_numOfFrame = m_animationData->getFrameCount();
	initSpriteFromAnimationData();

	// reset loop count
	m_tmpLoop = m_loop;

	// set first frame, if reverse, need start from last frame
	m_isAnimationEnded = false;
	initFrameOffset();
	if(m_isReverse) {
		setFrameIndex(m_numOfFrame - 1);
	} else {
		setFrameIndex(0);
	}

	// save current animation index
	m_curAnimationIndex = index;
}

void wyAFCSprite::playAnimation(int index, int mappingTag) {
	playAnimation(index, getClipMappingByTag(mappingTag));
}

void wyAFCSprite::setFrameIndex(int index) {
	bool frameChanged = m_curFrame != index;
	m_curFrame = index;

	// clear all clip sprite from batch node
	for(int i = 0; i < m_spriteList->num; i++) {
		wySpriteEx* sprite = (wySpriteEx*)wyArrayGet(m_spriteList, i);
		if(sprite->isVisible()) {
			wySpriteBatchNode* sheet = (wySpriteBatchNode*)sprite->getParent();
			if(sheet)
				sheet->removeAllChildren(true);
		} else {
			break;
		}
	}

	// get frame data and adjust frame offset
	wyAFCFrame* frameData = m_animationData->getFrameAt(index);
	adjustFrameOffset(frameData);
    
    // is frame flipped
    bool frameFlipX = frameData->isFlipX();
    bool frameFlipY = frameData->isFlipY();
    
    // flip or not?
    bool flipX = m_flipX != frameFlipX;
    bool flipY = m_flipY != frameFlipY;

	// since not all clip data are image clip
	int imageClipIndex = 0;
	for (int i = 0; i < frameData->getClipCount(); i++) {
		wyAFCClip* clip = frameData->getClipAt(i);
		wyAFCClipData& clipData = clip->getData();

		// it is a image clip
		wyAFCClipType clipType = clip->getType();
		if(clipType == AFC_CLIP_IMAGE) {
			// get clip pos with frame increment added
			wyPoint clipPos = wypAdd(clipData.clipPos, m_ignoreFrameOffset ? wypZero : m_frameOffset);

			// check flip flag
			if(flipX)
				clipPos.x = -clipPos.x;
			if(flipY)
				clipPos.y = -clipPos.y;

			// get related sprite sheet, if the sheet in data is NULL, then we use original sheet
			wySpriteBatchNode* sheet = clipData.i.sheet;
			if(!sheet)
				sheet = (wySpriteBatchNode*) wyArrayGet(m_sheetList, clipData.i.imageIndex);

			// create sprite frame and set it to clip sprite
			wySpriteFrame* tempSpriteFrame = wySpriteFrame::make(0, sheet->getTexture(), clipData.i.rect);
			wySpriteEx* sprite = (wySpriteEx*) wyArrayGet(m_spriteList, imageClipIndex);
			sprite->setDisplayFrame(tempSpriteFrame);
			sprite->setVisible(true);

			// set sprite position, because clipPos is center position so just set it
			sprite->setPosition(clipPos.x, clipPos.y);

			// set flipX flag
			sprite->setFlipX(clipData.i.flipX);

			// check wyAFCSprite flip settings
			// no flipY needed for sprite because flipY is just a flipX with 180 degree rotation
			float rotation = clipData.i.rotation;
			if(flipX) {
				sprite->setFlipX(!sprite->isFlipX());
				rotation = 360 - rotation;
			}
			if(flipY) {
				sprite->setFlipX(!sprite->isFlipX());
				rotation = 180 - rotation;
			}

			// rotate it
			sprite->setRotation(rotation);

			// add sprite to sheet
			sheet->addChildLocked(sprite);
			sprite->setColor(m_color);
			imageClipIndex++;
		}
	}

	// reset elapse and duration
	m_elapsed = 0;
	m_frameDuration = frameData->getDelay();

	// use tick mode or not
	m_isTickDelay = m_forceTickMode ? true : frameData->isUseTickDelay();

	// if force tick mode but frame is not, then we need reset duration to 1 tick
	if(m_forceTickMode && !frameData->isUseTickDelay())
		m_frameDuration = 1;

	// finally we can compute the real duration
	if(m_isTickDelay && m_unitInterval != 0)
		m_frameDuration *= m_unitInterval;

	// notify callback
	if(frameChanged)
		invokeOnAFCAnimationFrameChanged();

	/*
	 * cached sprite may be more than current frame clips, so hide unused sprites
	 */
	for (int i = imageClipIndex; i < m_spriteList->num; i++) {
		wySpriteEx* sprite = (wySpriteEx*) wyArrayGet(m_spriteList, i);
		sprite->setVisible(false);
	}
}

void wyAFCSprite::setFlipX(bool flipX) {
	m_flipX = flipX;

	// if node is running, update frame immediately
	if(m_running) {
		setFrameIndex(m_curFrame);
	}
}

void wyAFCSprite::setFlipY(bool flipY) {
	m_flipY = flipY;

	// if node is running, update frame immediately
	if(m_running) {
		setFrameIndex(m_curFrame);
	}
}

void wyAFCSprite::tick(float delta) {
	if(m_paused || m_isAnimationEnded && m_tmpLoop == 0) {
		return;
	}

	// add delta to elapsed time
	// or add 1 seconds for tick mode
	if(m_isTickDelay && m_unitInterval == 0) {
		m_elapsed += 1;
	} else {
		m_elapsed += delta;
	}

	if(m_elapsed >= m_frameDuration) {
		//end of animation in reverse mode
		int nextFrame;
		bool ended = false;
		if(m_isReverse && m_curFrame == 0) {
			nextFrame = m_numOfFrame - 1;
			ended = true;
		} else if(!m_isReverse && m_curFrame == m_numOfFrame - 1) {
			// end of animation in forward mode
			nextFrame = 0;
			ended = true;
		} else {
			nextFrame = m_curFrame + (m_isReverse ? -1 : 1);
		}

		// if animation ended
		if(ended) {
			// re-init frame offset
			initFrameOffset();

			// if the animation doesn't need looping
			// set m_isAnimationEnded to true
			if(m_tmpLoop == 0) {
				m_isAnimationEnded = ended;
			} else if(m_tmpLoop > 0) {
				m_tmpLoop--;
			}

			// notify callback in every loop
			invokeOnAFCAnimationEnded();
		}

		// if not end, set next frame
		if(!m_isAnimationEnded) {
			setFrameIndex(nextFrame);
		}
	}
}

void wyAFCSprite::setLoopCount(int loop) {
	// to make loop count correct, subtract one for first loop
	if(loop > 0)
		loop--;

	m_loop = loop;
	m_tmpLoop = loop;
}

void wyAFCSprite::setUnitInterval(float interval) {
	m_unitInterval = interval;

	// adjust current frame delay
	if(m_animationData) {
		wyAFCFrame* frameData = m_animationData->getFrameAt(m_curFrame);
		if(frameData) {
			if(m_isTickDelay)
				m_frameDuration = frameData->getDelay() * m_unitInterval;
		}
	}
}

void wyAFCSprite::setAFCSpriteCallback(wyAFCSpriteCallback* callback, void* data) {
	if(callback == NULL) {
		if(m_callback != NULL) {
			wyFree(m_callback);
			m_data = NULL;
			m_callback = NULL;
		}
	} else {
		if(m_callback == NULL)
			m_callback = (wyAFCSpriteCallback*)wyMalloc(sizeof(wyAFCSpriteCallback));
		m_data = data;
		memcpy(m_callback, callback, sizeof(wyAFCSpriteCallback));
	}
}

#if ANDROID

void wyAFCSprite::setAFCSpriteCallback(jobject callback) {
	JNIEnv* env = wyUtils::getJNIEnv();
	if(m_jCallback != NULL) {
		env->DeleteGlobalRef(m_jCallback);
		m_jCallback = NULL;
	}
	if(callback != NULL) {
		m_jCallback = env->NewGlobalRef(callback);
	}
}

#endif // #if ANDROID

int wyAFCSprite::getCollisionRectCount() {
	wyAFCAnimation* anim = getCurrentAnimationData();
	if(anim) {
		wyAFCFrame* frame = anim->getFrameAt(m_curFrame);
		if(frame) {
			return frame->getClipCount(AFC_CLIP_COLLISION_RECT);
		}
	}

	return 0;
}

wyRect wyAFCSprite::getCollisionRect(int index) {
	wyRect ret = wyrZero;
	wyAFCAnimation* anim = getCurrentAnimationData();
	if(anim) {
		wyAFCFrame* frame = anim->getFrameAt(m_curFrame);
		if(frame) {
			wyAFCClip* clip = frame->getClipAt(AFC_CLIP_COLLISION_RECT, index);
			if(clip) {
				wyAFCClipData& data = clip->getData();
				ret.width = data.cr.size.width;
				ret.height = data.cr.size.height;
				ret.x = data.clipPos.x - ret.width / 2;
				ret.y = data.clipPos.y - ret.height / 2;

				if(m_flipX) {
					ret.x = -ret.x - ret.width;
				}
				if(m_flipY) {
					ret.y = -ret.y - ret.height;
				}
			}
		}
	}

	return ret;
}

wyRect wyAFCSprite::getCollisionRectRelativeToParent(int index) {
	wyRect r = getCollisionRect(index);
	wyAffineTransform t = getTransformMatrix();
	r = wyaTransformRect(t, r);
	return r;
}

wyRect wyAFCSprite::getCollisionRectRelativeToWorld(int index) {
	wyRect r = getCollisionRect(index);
	wyAffineTransform t = getNodeToWorldTransform();
	r = wyaTransformRect(t, r);
	return r;
}

wyRect wyAFCSprite::getFrameRect() {
	wyRect ret = wyrZero;
	bool first = true;
	wyAFCAnimation* anim = getCurrentAnimationData();
	if(anim) {
		wyAFCFrame* frame = anim->getFrameAt(m_curFrame);
		if(frame) {
			int count = frame->getClipCount(AFC_CLIP_IMAGE);
			for (int i = 0; i < count; i++) {
				wySpriteEx* sprite = (wySpriteEx*) wyArrayGet(m_spriteList, i);
				if(first) {
					ret = wyr(sprite->getOriginX(), sprite->getOriginY(), sprite->getWidth(), sprite->getHeight());
					first = false;
				} else {
					ret = wyrCombine(ret, wyr(sprite->getOriginX(), sprite->getOriginY(), sprite->getWidth(), sprite->getHeight()));
				}
			}
		}
	}

	return ret;
}

wyRect wyAFCSprite::getFrameRectRelativeToParent() {
	wyRect r = getFrameRect();
	wyAffineTransform t = getTransformMatrix();
	r = wyaTransformRect(t, r);
	return r;
}

wyRect wyAFCSprite::getFrameRectRelativeToWorld() {
	wyRect r = getFrameRect();
	wyAffineTransform t = getNodeToWorldTransform();
	r = wyaTransformRect(t, r);
	return r;
}

void wyAFCSprite::addClipMapping(wyAFCClipMapping* mapping) {
	if(mapping) {
		wyArrayPush(m_mappingList, mapping);
		mapping->retain();
	}
}

void wyAFCSprite::removeClipMappingByTag(int tag) {
	for(int i = 0; i < m_mappingList->num; i++) {
		wyAFCClipMapping* mapping = (wyAFCClipMapping*)wyArrayGet(m_mappingList, i);
		if(mapping->getTag() == tag) {
			wyArrayDeleteIndex(m_mappingList, i);
			mapping->release();
			break;
		}
	}
}

wyAFCClipMapping* wyAFCSprite::getClipMappingByTag(int tag) {
	for(int i = 0; i < m_mappingList->num; i++) {
		wyAFCClipMapping* mapping = (wyAFCClipMapping*)wyArrayGet(m_mappingList, i);
		if(mapping->getTag() == tag) {
			return mapping;
		}
	}
	return NULL;
}
