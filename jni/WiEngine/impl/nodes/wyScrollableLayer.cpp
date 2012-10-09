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
#include "wyScrollableLayer.h"
#include "wyEventDispatcher.h"
#include "wyNinePatchSprite.h"
#include "wyFadeOut.h"
#include "wyFadeIn.h"
#include "wyLog.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include <math.h>
#include "wyScheduler.h"

#if ANDROID
#include "wyUtils_android.h"

extern jmethodID g_mid_IScrollableLayerCallback_onScrollOffsetChanged;
extern jmethodID g_mid_IScrollableLayerCallback_onStartFling;
extern jmethodID g_mid_IScrollableLayerCallback_onEndFling;
extern jmethodID g_mid_IScrollableLayerCallback_onScrollableChildNotVisible;
#endif

class wyScrollContainer : public wyLayer {
public:
	static wyScrollContainer* make() {
		wyScrollContainer* c = WYNEW wyScrollContainer();
		return (wyScrollContainer*)c->autoRelease();
	}

	wyScrollContainer() {
		setContentSize(0, 0);
	}

	virtual ~wyScrollContainer() {
	}

	virtual void visit() {
		// TODO gles2
//		/*
//		 * Here we do optimization in drawing scrollable children,
//		 * child whose rect is outside of wyScrollableLayer is skipped
//		 * to improve frame rate
//		 */
//
//		// if not visible
//		if(!m_visible)
//			return;
//
//		// should push matrix to avoid disturb current matrix
//		glPushMatrix();
//
//		// if grid is set, prepare grid
//		if(m_grid != NULL && m_grid->isActive()) {
//			m_grid->beforeDraw();
//			transformAncestors();
//		}
//
//		// transform for myself
//		transform();
//
//		// check clip
//		if(m_hasClip)
//			doClip();
//
//		// parent is scrollable layer
//		wyScrollableLayer* sl = (wyScrollableLayer*)m_parent;
//
//		// parent size
//		float pW = m_parent->getWidth();
//		float pH = m_parent->getHeight();
//
//		// draw children whose z order is less than zero
//		for(int i = 0; i < m_children->num; i++) {
//			wyNode* n = (wyNode*)wyArrayGet(m_children, i);
//			if(n->getZOrder() < 0) {
//				// get child bound relative to scrollable layer
//				float w = n->getWidth();
//				float h = n->getHeight();
//				float x = n->isRelativeAnchorPoint() ? (n->getPositionX() - w * n->getAnchorX()) : n->getPositionX();
//				float y = n->isRelativeAnchorPoint() ? (n->getPositionY() - h * n->getAnchorY()) : n->getPositionY();
//				x += m_positionX;
//				y += m_positionY;
//
//				// check bound, if intersected, visit this child
//				if(x + w > 0 && pW > x && y + h > 0 && pH > y) {
//					// set flag so it will be notified when it is invisible
//					wyUserData& ud = n->getUserData();
//					ud.b = false;
//
//					// visit it
//					n->visit();
//				} else {
//					wyUserData& ud = n->getUserData();
//					if(!ud.b) {
//						sl->invokeOnScrollableChildNotVisible(n);
//						ud.b = true;
//					}
//				}
//			} else
//				break;
//		}
//
//		// draw self
//		draw();
//
//		// draw children whose z order is larger than zero
//		for(int i = 0; i < m_children->num; i++) {
//			wyNode* n = (wyNode*)wyArrayGet(m_children, i);
//			if(n->getZOrder() >= 0) {
//				// get child bound relative to scrollable layer
//				float w = n->getWidth();
//				float h = n->getHeight();
//				float x = n->isRelativeAnchorPoint() ? (n->getPositionX() - w * n->getAnchorX()) : n->getPositionX();
//				float y = n->isRelativeAnchorPoint() ? (n->getPositionY() - h * n->getAnchorY()) : n->getPositionY();
//				x += m_positionX;
//				y += m_positionY;
//
//				// check bound, if intersected, visit this child
//				if(x + w > 0 && pW > x && y + h > 0 && pH > y) {
//					// set flag so it will be notified when it is invisible
//					wyUserData& ud = n->getUserData();
//					ud.b = false;
//
//					// visit it
//					n->visit();
//				} else {
//					wyUserData& ud = n->getUserData();
//					if(!ud.b) {
//						sl->invokeOnScrollableChildNotVisible(n);
//						ud.b = true;
//					}
//				}
//			}
//		}
//
//		// restore
//		if(m_hasClip)
//			glDisable(GL_SCISSOR_TEST);
//
//		// if grid is set, end grid
//		if(m_grid != NULL && m_grid->isActive()) {
//			m_grid->afterDraw(this);
//		}
//
//		// pop matrix
//		glPopMatrix();
	}
};

wyScrollableLayer::wyScrollableLayer(wyColor4B color) :
		wyColorLayer(color),
		m_vertical(false),
		m_horizontal(false),
		m_scrolling(false),
		m_flinging(false),
		m_childTouchCancelled(false),
		m_lastX(0),
		m_lastY(0),
		m_firstX(0),
		m_firstY(0),
		m_leftMargin(0),
		m_rightMargin(0),
		m_topMargin(0),
		m_bottomMargin(0),
		m_leftBorder(0),
		m_rightBorder(0),
		m_topBorder(0),
		m_bottomBorder(0),
		m_xExtent(0),
		m_yExtent(0),
		m_horizontalThumb(NULL),
		m_verticalThumb(NULL),
		m_fadeOutTime(0),
		m_noScrollTime(0),
		m_fadeingOut(false),
		m_callback(NULL),
#if ANDROID
		m_jCallback(NULL),
#endif
		m_scroller(WYNEW wyScroller()) {
	// enable event
	setTouchEnabled(true);
	setGestureEnabled(true);

	// create container
	m_container = wyScrollContainer::make();
	addChildLocked(m_container);

	// schedule fling timer
	wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyScrollableLayer::updateFling));
	wyTimer* timer = wyTimer::make(ts);
	scheduleLocked(timer);
}

wyScrollableLayer::~wyScrollableLayer() {
#if ANDROID
	if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->DeleteGlobalRef(m_jCallback);
		m_jCallback = NULL;
	}
#endif

	m_scroller->release();
}

wyScrollableLayer* wyScrollableLayer::make(wyColor4B color) {
	wyScrollableLayer* l = WYNEW wyScrollableLayer(color);
	return (wyScrollableLayer*)l->autoRelease();
}

void wyScrollableLayer::updateFling(wyTargetSelector* ts) {
	if(m_scroller->computeScrollOffset()) {
		m_container->setPosition(m_horizontal ? m_scroller->getCurrX() : 0,
				m_vertical ? m_scroller->getCurrY() : (m_height - m_topBorder));
		updateOffset();
	} else {
		if(m_flinging) {
			m_flinging = false;
			invokeOnEndFling();
		}
	}

	if(!m_fadeingOut && !m_flinging && !m_scrolling && m_fadeOutTime > 0) {
		// increase no scroll time
		m_noScrollTime += ts->getDelta();

		// > fade out time
		if(m_noScrollTime >= m_fadeOutTime) {
			if(m_horizontalThumb || m_verticalThumb) {
				if(m_horizontalThumb) {
					m_horizontalThumb->stopAllActions();
					m_horizontalThumb->runAction(wyFadeOut::make(0.6f));
				}
				if(m_verticalThumb) {
					m_verticalThumb->stopAllActions();
					m_verticalThumb->runAction(wyFadeOut::make(0.6f));
				}
			}

			m_fadeingOut = true;
		}
	}
}

void wyScrollableLayer::setContentSize(float w, float h) {
	wyColorLayer::setContentSize(w, h);
	setClipRect(wyr(0, 0, w, h), true);
	updateExtent();
	updateThumbSize();
	updateOffset();
}

bool wyScrollableLayer::touchesBegan(wyMotionEvent& e) {
	// stop fling
	if(m_flinging) {
		m_scroller->forceFinished(true);
		m_flinging = false;
		invokeOnEndFling();
	}

	// save touch info
	m_lastX = e.x[0];
	m_lastY = e.y[0];
	m_firstX = m_lastX;
	m_firstY = m_lastY;

	// set flags
	m_scrolling = true;
	m_childTouchCancelled = false;

	// stop fading out
	m_fadeingOut = false;
	if(m_horizontalThumb) {
		m_horizontalThumb->stopAllActions();
		if(m_horizontalThumb->getAlpha() == 0) {
			m_horizontalThumb->runAction(wyFadeIn::make(0.3f));
		} else {
			m_horizontalThumb->setAlpha(255);
		}
	}
	if(m_verticalThumb) {
		m_verticalThumb->stopAllActions();
		if(m_verticalThumb->getAlpha() == 0) {
			m_verticalThumb->runAction(wyFadeIn::make(0.3f));
		} else {
			m_verticalThumb->setAlpha(255);
		}
	}

	return true;
}

bool wyScrollableLayer::touchesMoved(wyMotionEvent& e) {
	if(m_scrolling) {
		// calculate new offset
		float dx = e.x[0] - m_lastX;
		float dy = e.y[0] - m_lastY;
		float posX = m_container->getPositionX();
		float posY = m_container->getPositionY();
		if(m_vertical)
			posY += dy;
		if(m_horizontal)
			posX += dx;
		m_container->setPosition(posX, posY);

		// save last x/y
		m_lastX = e.x[0];
		m_lastY = e.y[0];

		// update
		updateOffset();

		// if exceeds thresholder, cancel child touch
		if(!m_childTouchCancelled) {
			dx = fabs(e.x[0] - m_firstX);
			dy = fabs(e.y[0] - m_firstY);

			if(dx >= DP(10) || dy >= DP(10)) {
				wyEventDispatcher::getInstance()->cancelTouch(e, m_container);
				m_childTouchCancelled = true;
			}
		}

		return true;
	}

	return false;
}

bool wyScrollableLayer::touchesEnded(wyMotionEvent& e) {
	if(m_scrolling) {
		m_scrolling = false;
		m_noScrollTime = 0;
		return true;
	}

	return false;
}

bool wyScrollableLayer::touchesCancelled(wyMotionEvent& e) {
	if(m_scrolling) {
		m_scrolling = false;
		m_noScrollTime = 0;
		return true;
	}

	return false;
}

bool wyScrollableLayer::onFling(wyMotionEvent& e1, wyMotionEvent& e2, float velocityX, float velocityY) {
	m_flinging = true;
	m_scroller->fling(m_container->getPositionX(),
			m_container->getPositionY(),
			m_horizontal ? velocityX : 0.0f,
			m_vertical ? velocityY : 0.0f,
			m_width - m_rightBorder,
			-m_leftBorder,
			m_height - m_topBorder,
			-m_bottomBorder);
	invokeOnStartFling();
	return true;
}

void wyScrollableLayer::addScrollableChildLocked(wyNode* child) {
	addScrollableChildLocked(child, child->getZOrder(), child->getTag());
}

void wyScrollableLayer::addScrollableChildLocked(wyNode* child, int z) {
	addScrollableChildLocked(child, z, child->getTag());
}

void wyScrollableLayer::addScrollableChildLocked(wyNode* child, int z, int tag) {
	// don't intercept touch because scrollable layer need it
	child->setInterceptTouch(false);

	// add child
	m_container->addChildLocked(child, z, tag);

	// confine the touch event
	child->setTouchCoffin(this);

	// update
	updateExtent();
	if(!m_running)
		m_container->setPosition(-m_leftBorder, m_height - m_topBorder);
	updateThumbSize();
	updateOffset();
}

void wyScrollableLayer::removeScrollableChildLocked(wyNode* child, bool cleanup) {
	// clear touch coffin
	child->setTouchCoffin(NULL);

	// remove
	m_container->removeChildLocked(child, cleanup);
}

void wyScrollableLayer::removeScrollableChildByTagLocked(int tag, bool cleanup) {
	// clear touch coffin
	wyNode* child = m_container->getChildByTag(tag);
	if(child)
		child->setTouchCoffin(NULL);

	// remove
	m_container->removeChildByTagLocked(tag, cleanup);
}

void wyScrollableLayer::removeAllScrollableChildrenLocked(bool cleanup) {
	// clear touch coffin
	wyArray* children = m_container->getChildren();
	for(int i = 0; i < children->num; i++) {
		wyNode* child = (wyNode*)wyArrayGet(children, i);
		child->setTouchCoffin(NULL);
	}

	// remove
	m_container->removeAllChildrenLocked(cleanup);
}

wyNode* wyScrollableLayer::getScrollableChildByTag(int tag) {
	return m_container->getChildByTag(tag);
}

void wyScrollableLayer::updateExtent() {
	if(!m_container)
		return;

	// get fit bound
	m_leftBorder = MAX_FLOAT;
	m_rightBorder = -MAX_FLOAT;
	m_topBorder = -MAX_FLOAT;
	m_bottomBorder = MAX_FLOAT;
	wyArray* children = m_container->getChildren();
	for(int i = 0; i < children->num; i++) {
		wyNode* child = (wyNode*)wyArrayGet(children, i);
		m_leftBorder = MIN(m_leftBorder, child->getOriginX());
		m_bottomBorder = MIN(m_bottomBorder, child->getOriginY());
		m_rightBorder = MAX(m_rightBorder, child->getOriginX() + child->getWidth());
		m_topBorder = MAX(m_topBorder, child->getOriginY() + child->getHeight());
	}

	// consider margin
	m_leftBorder -= m_leftMargin;
	m_rightBorder += m_rightMargin;
	m_topBorder += m_topMargin;
	m_bottomBorder -= m_bottomMargin;

	// calculate extent
	m_xExtent = m_rightBorder - m_leftBorder;
	m_yExtent = m_topBorder - m_bottomBorder;
}

void wyScrollableLayer::updateThumbSize() {
	if(m_horizontalThumb) {
		wyNinePatchSprite* nps = dynamic_cast<wyNinePatchSprite*>(m_horizontalThumb);
		if(nps != NULL) {
			float size = m_xExtent <= 0 ? m_width : (MIN(1, m_width / m_xExtent) * m_width);
			size = MAX(nps->getTexture()->getWidth(), size);
			nps->setContentSize(size, nps->getTexture()->getHeight());
		}
	}

	if(m_verticalThumb) {
		wyNinePatchSprite* nps = dynamic_cast<wyNinePatchSprite*>(m_verticalThumb);
		if(nps != NULL) {
			float size = m_yExtent <= 0 ? m_height : (MIN(1, m_height / m_yExtent) * m_height);
			size = MAX(nps->getTexture()->getHeight(), size);
			nps->setContentSize(nps->getTexture()->getWidth(), size);
		}
	}
}

void wyScrollableLayer::updateOffset() {
	// clamp container position
	float posX = m_container->getPositionX();
	float posY = m_container->getPositionY();
	posX = MIN(MAX(posX, m_width - m_rightBorder), -m_leftBorder);
	if(m_yExtent <= m_height)
		posY = m_height - m_topBorder;
	else
		posY = MIN(MAX(posY, m_height - m_topBorder), -m_bottomBorder);
	m_container->setPosition(posX, posY);

	// set horizontal thumb position
	if(m_horizontalThumb) {
		m_horizontalThumb->setPosition(getContainerPositionXPercent() * m_width, 0);
	}

	if(m_verticalThumb) {
		m_verticalThumb->setPosition(m_width, m_height - getContainerPositionYPercent() * m_height);
	}

	if(m_scrolling || m_flinging)
		invokeOnScrollOffsetChanged();
}

float wyScrollableLayer::getOffsetX() {
	return -m_leftBorder - m_container->getPositionX();
}

float wyScrollableLayer::getOffsetY() {
	return m_container->getPositionY() - (m_height - m_topBorder);
}

void wyScrollableLayer::setOffsetX(float x) {
	float posX = -m_leftBorder - x;
	posX = MIN(MAX(posX, m_width - m_rightBorder), -m_leftBorder);
	m_container->setPosition(posX, m_container->getPositionY());
}

void wyScrollableLayer::setOffsetY(float y) {
	float posY = y + (m_height - m_topBorder);
	posY = MIN(MAX(posY, m_height - m_topBorder), -m_bottomBorder);
	m_container->setPosition(m_container->getPositionX(), posY);
}

bool wyScrollableLayer::isAtXEnd() {
	return m_container->getPositionX() == -m_leftBorder + MIN(0, m_width - m_xExtent);
}

bool wyScrollableLayer::isAtYEnd() {
	return m_container->getPositionY() == -m_bottomBorder;
}

float wyScrollableLayer::getContainerPositionXPercent() {
	return getOffsetX() / m_xExtent;
}

float wyScrollableLayer::getContainerPositionYPercent() {
	return getOffsetY() / m_yExtent;
}

void wyScrollableLayer::setHorizontalThumb(wyNode* thumb) {
	// remove old thumb
	if(m_horizontalThumb) {
		removeChildLocked(m_horizontalThumb, true);
		m_horizontalThumb = NULL;
	}

	// set new thumb
	if(thumb) {
		m_horizontalThumb = thumb;
		thumb->setAnchor(0, 0);
		addChildLocked(thumb);
		updateThumbSize();
		updateOffset();
	}
}

void wyScrollableLayer::setVerticalThumb(wyNode* thumb) {
	// remove old thumb
	if(m_verticalThumb) {
		removeChildLocked(m_verticalThumb, true);
		m_verticalThumb = NULL;
	}

	// set new thumb
	if(thumb) {
		m_verticalThumb = thumb;
		thumb->setAnchor(1, 1);
		addChildLocked(thumb);
		updateThumbSize();
		updateOffset();
	}
}

#if ANDROID
void wyScrollableLayer::setCallback(jobject callback) {
	JNIEnv* env = wyUtils::getJNIEnv();
	if(m_jCallback != NULL) {
		env->DeleteGlobalRef(m_jCallback);
		m_jCallback = NULL;
	}
	m_jCallback = env->NewGlobalRef(callback);
}
#endif

void wyScrollableLayer::invokeOnScrollOffsetChanged() {
	if(m_callback) {
		m_callback->onScrollOffsetChanged(this);
	}
#if ANDROID
	else if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->CallVoidMethod(m_jCallback, g_mid_IScrollableLayerCallback_onScrollOffsetChanged, (jint)this);
	}
#endif
}

void wyScrollableLayer::invokeOnStartFling() {
	if(m_callback) {
		m_callback->onStartFling(this);
	}
#if ANDROID
	else if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->CallVoidMethod(m_jCallback, g_mid_IScrollableLayerCallback_onStartFling, (jint)this);
	}
#endif
}

void wyScrollableLayer::invokeOnEndFling() {
	if(m_callback) {
		m_callback->onEndFling(this);
	}
#if ANDROID
	else if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->CallVoidMethod(m_jCallback, g_mid_IScrollableLayerCallback_onEndFling, (jint)this);
	}
#endif
}

void wyScrollableLayer::invokeOnScrollableChildNotVisible(wyNode* child) {
	if(m_callback) {
		m_callback->onScrollableChildNotVisible(this, child);
	}
#if ANDROID
	else if(m_jCallback != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->CallVoidMethod(m_jCallback, g_mid_IScrollableLayerCallback_onScrollableChildNotVisible, (jint)this, (jint)child);
	}
#endif
}
