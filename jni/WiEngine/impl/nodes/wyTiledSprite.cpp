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
#include "wyTiledSprite.h"
#include "wyGlobal.h"
#include "wyScheduler.h"
#include "wyParallaxObject.h"
#include "wyLog.h"
#include "wyTexture2D.h"
#include "wyMaterial.h"
#include "wyQuadList.h"

/**
 * @class wyTiledSpriteParallaxObject
 *
 * wyTiledSprite的实现方式和普通的节点有区别, 因此需要自定义视差对象
 */
class wyTiledSpriteParallaxObject : public wyParallaxObject {
private:
	float m_minX;
	float m_maxX;

protected:
	wyTiledSpriteParallaxObject() :
			wyParallaxObject(),
			m_minX(0),
			m_maxX(0) {
	}

	virtual ~wyTiledSpriteParallaxObject() {
	}

public:
	static wyTiledSpriteParallaxObject* make() {
		wyTiledSpriteParallaxObject* po = WYNEW wyTiledSpriteParallaxObject();
		return (wyTiledSpriteParallaxObject*)po->autoRelease();
	}

	virtual void translate(float dx, float dy) {
		wyTiledSprite* ts = (wyTiledSprite*)getNode();

		// current pos
		float posX = ts->getPositionX();
		float posY = ts->getPositionY();

		// calculate new position x
		if(dx > 0) {
			float possiblePosOffsetX = MAX(0, m_maxX - posX);
			float possibleInternalOffsetX = ts->m_offsetX < 0 ? -ts->m_offsetX : 0;
			if(possibleInternalOffsetX >= dx) {
				ts->offsetBy(dx, dy);
			} else if(possiblePosOffsetX <= 0) {
				ts->offsetBy(dx, dy);
			} else {
				ts->offsetBy(possibleInternalOffsetX, dy);
				dx -= possibleInternalOffsetX;
				if(possiblePosOffsetX >= dx) {
					ts->setPosition(posX + dx, posY);
				} else {
					ts->setPosition(posX + possiblePosOffsetX, posY);
					ts->offsetBy(dx - possiblePosOffsetX, 0);
				}
			}
		} else {
			float possiblePosOffsetX = MAX(0, posX - m_minX);
			float possibleInternalOffsetX = ts->m_offsetX > 0 ? ts->m_offsetX : 0;
			if(possibleInternalOffsetX >= -dx) {
				ts->offsetBy(dx, dy);
			} else if(possiblePosOffsetX <= 0) {
				ts->offsetBy(dx, dy);
			} else {
				ts->offsetBy(-possibleInternalOffsetX, dy);
				dx += possibleInternalOffsetX;
				if(possiblePosOffsetX >= -dx) {
					ts->setPosition(posX + dx, posY);
				} else {
					ts->setPosition(posX - possiblePosOffsetX, posY);
					ts->offsetBy(dx + possiblePosOffsetX, 0);
				}
			}
		}
	}

	void setOriginalPositionX(float x) {
		m_maxX = MAX(0, x);
		m_minX = MIN(0, x);
	}
};

wyTiledSprite::wyTiledSprite(wyTexture2D* tex) :
		m_tileVertical(true),
		m_tileHorizontal(true),
		m_stretch(false),
		m_flinging(false),
		m_scroller(WYNEW wyScroller()),
		m_minOffsetX(-MAX_FLOAT),
		m_maxOffsetX(MAX_FLOAT),
		m_minOffsetY(-MAX_FLOAT),
		m_maxOffsetY(MAX_FLOAT),
		m_rect(wyrZero),
		m_offsetX(0),
		m_offsetY(0),
		m_spacingX(0),
		m_spacingY(0) {
	// create empty material and mesh
	addRenderPair(wyMaterial::make(), wyQuadList::make());

	// set blend mode
	setBlendMode(wyRenderState::ALPHA);

	// set texture, size and position
	setTexture(tex);
	setContentSize(wyDevice::winWidth, wyDevice::winHeight);
	setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);

	// schedule fling timer
	wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyTiledSprite::updateFling));
	wyTimer* timer = wyTimer::make(ts);
	scheduleLocked(timer);
}

wyTiledSprite::~wyTiledSprite() {
	m_scroller->release();
}

wyTiledSprite* wyTiledSprite::make(wyTexture2D* tex) {
	wyTiledSprite* n = WYNEW wyTiledSprite(tex);
	return (wyTiledSprite*)n->autoRelease();
}

void wyTiledSprite::setOffsetX(float offset) {
	if(offset >= m_minOffsetX && offset <= m_maxOffsetX) {
		m_offsetX = offset;
		setNeedUpdateMesh(true);
	}
}

void wyTiledSprite::setOffsetY(float offset) {
	if(offset >= m_minOffsetY && offset <= m_maxOffsetY) {
		m_offsetY = offset;
		setNeedUpdateMesh(true);
	}
}

void wyTiledSprite::offsetBy(float dx, float dy) {
	if(dx != 0 && m_tileHorizontal) {
		float offset = m_offsetX + dx;
		offset = MAX(m_minOffsetX, MIN(m_maxOffsetX, offset));
		if(offset != m_offsetX) {
			m_offsetX = offset;
			setNeedUpdateMesh(true);
		}
	}
	if(dy != 0 && m_tileVertical) {
		float offset = m_offsetY + dy;
		offset = MAX(m_minOffsetY, MIN(m_maxOffsetY, offset));
		if(offset != m_offsetY) {
			m_offsetY = offset;
			setNeedUpdateMesh(true);
		}
	}
}

void wyTiledSprite::setTextureRect(wyRect r) {
	m_rect = r;
	setNeedUpdateMesh(true);
}

void wyTiledSprite::setTileDirection(bool horizontal, bool vertical) {
	m_tileHorizontal = horizontal;
	m_tileVertical = vertical;
	setNeedUpdateMesh(true);
}

void wyTiledSprite::updateMeshColor() {
	wyQuadList* quadList = (wyQuadList*)getMesh();
	quadList->updateColor(m_color);
}

void wyTiledSprite::updateMesh() {
	// if no texture, return
	wyTexture2D* tex = getTexture();
	if(tex == NULL)
		return;

	// first clear old quads
	wyQuadList* atlas = (wyQuadList*)getMesh();
	atlas->removeAllQuads();

	// get texture info
	float tW = m_rect.width;
	float tH = m_rect.height;
	float tPW = tex->getPixelWidth();
	float tPH = tex->getPixelHeight();

	// get original tex coords
	float orgLeft = (2 * m_rect.x + 1) / (2 * tPW);
	float orgRight = orgLeft + (2 * m_rect.width - 2) / (2 * tPW);
	float orgTop = (2 * m_rect.y + 1) / (2 * tPH);
	float orgBottom = orgTop + (2 * m_rect.height - 2) / (2 * tPH);
	float orgW = orgRight - orgLeft;
	float orgH = orgBottom - orgTop;

	// help variables
	wyQuad2D texCoords;
	wyQuad3D vertex;

	// build quads
	if(m_tileVertical && m_tileHorizontal) {
		// get start position of left-bottom
		float startX = 0;
		float startY = 0;
		if(m_offsetX > 0)
			startX = fmod(m_offsetX, tW + m_spacingX) - tW - m_spacingX;
		else
			startX = fmod(m_offsetX, tW + m_spacingX);
		if(m_offsetY > 0)
			startY = fmod(m_offsetY, tH + m_spacingY) - tH - m_spacingY;
		else
			startY = fmod(m_offsetY, tH + m_spacingY);

		// special checking for negative spacing x
		if(m_spacingX < 0) {
			if(startX > m_spacingX) {
				if(m_maxOffsetX >= tW + m_spacingX || m_maxOffsetX - m_offsetX >= tW + m_spacingX) {
					startX += -(tW + m_spacingX);
				}
			}
		}

		// special checking for negative spacing y
		if(m_spacingY < 0) {
			if(startY > m_spacingY) {
				if(m_maxOffsetY >= tH + m_spacingY || m_maxOffsetY - m_offsetY >= tH + m_spacingY) {
					startY += -(tH + m_spacingY);
				}
			}
		}

		// build vertex and tex coords buffer
		while(m_height > startY) {
			while(m_width > startX) {
				// build vertex
				vertex.bl_x = MAX(0, startX);
				vertex.bl_y = MAX(0, startY);
				vertex.bl_z = 0;
				vertex.br_x = MIN(m_width, startX + tW);
				vertex.br_y = MAX(0, startY);
				vertex.br_z = 0;
				vertex.tl_x = MAX(0, startX);
				vertex.tl_y = MIN(m_height, startY + tH);
				vertex.tl_z = 0;
				vertex.tr_x = MIN(m_width, startX + tW);
				vertex.tr_y = MIN(m_height, startY + tH);
				vertex.tr_z = 0;

				// build tex coords
				texCoords.bl_x = texCoords.tl_x = startX >= 0 ? orgLeft : (orgLeft + orgW * -startX / tW);
				texCoords.bl_y = texCoords.br_y = startY >= 0 ? orgBottom : (orgBottom - orgH * -startY / tH);
				texCoords.br_x = texCoords.tr_x = (startX + tW) <= m_width ? orgRight : (orgLeft + orgW * (m_width - startX) / tW);
				texCoords.tl_y = texCoords.tr_y = (startY + tH) <= m_height ? orgTop : (orgBottom - orgH * (m_height - startY) / tH);

				// append quad
				atlas->appendQuad(texCoords, vertex);

				// adjust startX
				startX += tW;
				startX += m_spacingX;
			}

			startY += tH;
			startY += m_spacingY;
			if(m_offsetX > 0)
				startX = fmod(m_offsetX, tW + m_spacingX) - tW - m_spacingX;
			else
				startX = fmod(m_offsetX, tW + m_spacingX);
		}
	} else if(m_tileVertical) {
		// get start position of left-top
		float startX = m_stretch ? 0 : (tW > m_width ? 0 : ((m_width - tW) / 2));
		if(m_stretch)
			tW = m_width;
		float startY = 0;
		if(m_offsetY > 0)
			startY = fmod(m_offsetY, tH + m_spacingY) - tH - m_spacingY;
		else
			startY = fmod(m_offsetY, tH + m_spacingY);

		// special checking for negative spacing y
		if(m_spacingY < 0) {
			if(startY > m_spacingY) {
				if(m_maxOffsetY >= tH + m_spacingY || m_maxOffsetY - m_offsetY >= tH + m_spacingY) {
					startY += -(tH + m_spacingY);
				}
			}
		}

		// build vertex and tex coords buffer
		while(m_height > startY) {
			// build vertex
			vertex.bl_x = startX;
			vertex.bl_y = MAX(0, startY);
			vertex.bl_z = 0;
			vertex.br_x = startX + tW;
			vertex.br_y = MAX(0, startY);
			vertex.br_z = 0;
			vertex.tl_x = startX;
			vertex.tl_y = MIN(m_height, startY + tH);
			vertex.tl_z = 0;
			vertex.tr_x = startX + tW;
			vertex.tr_y = MIN(m_height, startY + tH);
			vertex.tr_z = 0;

			// build tex coords
			texCoords.bl_x = texCoords.tl_x = orgLeft;
			texCoords.bl_y = texCoords.br_y = startY >= 0 ? orgBottom : (orgBottom - orgH * -startY / tH);
			texCoords.br_x = texCoords.tr_x = orgRight;
			texCoords.tl_y = texCoords.tr_y = (startY + tH) <= m_height ? orgTop : (orgBottom - orgH * (m_height - startY) / tH);

			// append quad
			atlas->appendQuad(texCoords, vertex);

			// adjust startY
			startY += tH;
			startY += m_spacingY;
		}
	} else if(m_tileHorizontal) {
		// get start position of left-bottom
		float startX = 0;
		float startY = m_stretch ? 0 : (tH > m_height ? 0 : ((m_height - tH) / 2));
		if(m_stretch)
			tH = m_height;
		if(m_offsetX > 0)
			startX = fmod(m_offsetX, tW + m_spacingX) - tW - m_spacingX;
		else
			startX = fmod(m_offsetX, tW + m_spacingX);

		// special checking for negative spacing x
		if(m_spacingX < 0) {
			if(startX > m_spacingX) {
				if(m_maxOffsetX >= tW + m_spacingX || m_maxOffsetX - m_offsetX >= tW + m_spacingX) {
					startX += -(tW + m_spacingX);
				}
			}
		}

		// build vertex and tex coords buffer
		while(m_width > startX) {
			// build vertex
			vertex.bl_x = MAX(0, startX);
			vertex.bl_y = startY;
			vertex.bl_z = 0;
			vertex.br_x = MIN(m_width, startX + tW);
			vertex.br_y = startY;
			vertex.br_z = 0;
			vertex.tl_x = MAX(0, startX);
			vertex.tl_y = startY + tH;
			vertex.tl_z = 0;
			vertex.tr_x = MIN(m_width, startX + tW);
			vertex.tr_y = startY + tH;
			vertex.tr_z = 0;

			// build tex coords
			texCoords.bl_x = texCoords.tl_x = startX >= 0 ? orgLeft : (orgLeft + orgW * -startX / tW);
			texCoords.bl_y = texCoords.br_y = orgBottom;
			texCoords.br_x = texCoords.tr_x = (startX + tW) <= m_width ? orgRight : (orgLeft + orgW * (m_width - startX) / tW);
			texCoords.tl_y = texCoords.tr_y = orgTop;

			// append quad
			atlas->appendQuad(texCoords, vertex);

			// adjust startX
			startX += tW;
			startX += m_spacingX;
		}
	} else {
		// get start position of left-bottom
		float startX = m_stretch ? 0 : (tW > m_width ? 0 : ((m_width - tW) / 2));
		float startY = m_stretch ? 0 : (tH > m_height ? 0 : ((m_height - tH) / 2));
		if(m_stretch) {
			tW = m_width;
			tH = m_height;
		}

		// build vertex
		vertex.bl_x = startX;
		vertex.bl_y = startY;
		vertex.bl_z = 0;
		vertex.br_x = startX + tW;
		vertex.br_y = startY;
		vertex.br_z = 0;
		vertex.tl_x = startX;
		vertex.tl_y = startY + tH;
		vertex.tl_z = 0;
		vertex.tr_x = startX + tW;
		vertex.tr_y = startY + tH;
		vertex.tr_z = 0;

		// build tex coords
		texCoords.bl_x = texCoords.tl_x = orgLeft;
		texCoords.bl_y = texCoords.br_y = orgBottom;
		texCoords.br_x = texCoords.tr_x = orgRight;
		texCoords.tl_y = texCoords.tr_y = orgTop;

		// append quad
		atlas->appendQuad(texCoords, vertex);
	}
}

void wyTiledSprite::setTexture(wyTexture2D* tex, int index) {
	wyNode::setTexture(tex);

	// set rect
	if(tex != NULL)
		m_rect = wyr(0, 0, tex->getWidth(), tex->getHeight());
}

void wyTiledSprite::updateFling(wyTargetSelector* ts) {
	if(m_scroller->computeScrollOffset()) {
		if(m_tileHorizontal) {
			setOffsetX(m_scroller->getCurrX());
		}
		if(m_tileVertical) {
			setOffsetY(m_scroller->getCurrY());
		}
	} else {
		m_flinging = false;
	}
}

void wyTiledSprite::stopFling() {
	// stop fling
	if(m_flinging) {
		m_scroller->forceFinished(true);
		m_flinging = false;
	}
}

void wyTiledSprite::fling(float velocityX, float velocityY) {
	if(!m_flinging) {
		m_flinging = true;

		if(m_tileVertical && m_tileHorizontal)
			m_scroller->fling(m_offsetX, m_offsetY, velocityX, velocityY, m_minOffsetX, m_maxOffsetX, m_minOffsetY, m_maxOffsetY);
		else if(m_tileVertical)
			m_scroller->fling(0, m_offsetY, 0, velocityY, 0, 0, m_minOffsetY, m_maxOffsetY);
		else if(m_tileHorizontal)
			m_scroller->fling(m_offsetX, 0, velocityX, 0, m_minOffsetX, m_maxOffsetX, 0, 0);
	}
}

wyParallaxObject* wyTiledSprite::createParallaxObject() {
	wyTiledSpriteParallaxObject* o = wyTiledSpriteParallaxObject::make();
	o->setOriginalPositionX(m_positionX);
	return o;
}

void wyTiledSprite::setSpacing(float x, float y) {
	m_spacingX = x;
	m_spacingY = y;
	setNeedUpdateMesh(true);
}

void wyTiledSprite::setStretch(bool flag) {
	m_stretch = flag;
	setNeedUpdateMesh(true);
}
