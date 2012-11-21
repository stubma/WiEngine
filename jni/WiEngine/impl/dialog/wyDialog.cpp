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
#include "wyDialog.h"
#include "wyTextureNode.h"
#include "wyDirector.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLog.h"
#include "wyDialog_resources.h"
#include "wyNinePatchSprite.h"

extern wyDirector* gDirector;

// spacing components
#define COMPONENT_SPACING DP(10)

wyDialog::wyDialog() :
		wyColorLayer(wyc4b(0, 0, 0, 127)),
		m_created(false),
		m_bg(NULL),
		m_leftPadding(0),
		m_rightPadding(0),
		m_topPadding(0),
		m_bottomPadding(0),
		m_transition(NULL),
		m_backKeyButtonIndex(-1),
		m_title(NULL),
		m_content(NULL) {
	// make dialog top priority
	setTouchEnabled(true);
	setKeyEnabled(true);
	setTouchPriority(MAX_INT);
	setKeyPriority(MAX_INT);

	// init members
	m_buttons = WYNEW vector<Button>();
	m_buttons->reserve(3);
	m_defaultSelector = wyTargetSelector::make(this, SEL(wyDialog::onCloseDialog));
	m_defaultSelector->retain();

	// set default background
	wyNinePatchSprite* bg = wyNinePatchSprite::make(wyTexture2D::makeMemory("default_dialog_bg.png"), wyr(DP(130), DP(20), DP(1), DP(1)));
	setBackground(bg);
	setBackgroundPadding(DP(20), DP(20), DP(20), DP(15));
}

wyDialog::~wyDialog() {
	m_defaultSelector->release();
	wyObjectRelease(m_transition);
	WYDELETE(m_buttons);
}

wyDialog* wyDialog::make() {
	wyDialog* d = WYNEW wyDialog();
	return (wyDialog*)d->autoRelease();
}

void wyDialog::onCloseDialog(wyTargetSelector* ts) {
	dismiss();
}

wyDialog* wyDialog::setBackground(wyNode* bg) {
	if(!bg) {
		LOGW("wyDialog::setBackground: can't set a null background");
		return this;
	}

	// remove old bg
	if(m_bg) {
		removeChildLocked(m_bg, true);
		m_bg = NULL;
	}

	// set new one
	m_bg = bg;
	addChildLocked(m_bg);
	m_created = false;
	return this;
}

wyDialog* wyDialog::setBackgroundPadding(float left, float top, float right, float bottom) {
	m_leftPadding = left;
	m_topPadding = top;
	m_rightPadding = right;
	m_bottomPadding = bottom;
	m_created = false;
	return this;
}

wyDialog* wyDialog::setTitle(wyNode* title) {
	// remove old
	if(m_title) {
		m_bg->removeChildLocked(m_title, true);
		m_title = NULL;
	}

	// add new
	m_title = title;
	if(m_title)
		m_bg->addChildLocked(m_title);

	// reset flag
	m_created = false;

	// return self
	return this;
}

wyDialog* wyDialog::setContent(wyNode* content) {
	// remove old
	if(m_content) {
		m_bg->removeChildLocked(m_content, true);
		m_content = NULL;
	}

	// add new
	m_content = content;
	if(m_content)
		m_bg->addChildLocked(m_content);

	// reset flag
	m_created = false;

	// return self
	return this;
}

wyDialog* wyDialog::addTwoColumnsButton(wyNode* button1, wyNode* label1, wyTargetSelector* sel1, wyNode* button2, wyNode* label2, wyTargetSelector* sel2) {
	// check button node
	if(!button1 || !button2) {
		LOGW("wyDialog::addTwoColumnsButton: can't add null button node");
		return this;
	}

	// button structure
	Button b1 = {
		button1,
		label1,
		sel1,
		true
	};
	Button b2 = {
		button2,
		label2,
		sel2,
		true
	};

	// add button
	m_bg->addChildLocked(button1);
	m_bg->addChildLocked(button2);

	// add label
	if(label1)
		m_bg->addChildLocked(label1);
	if(label2)
		m_bg->addChildLocked(label2);

	// install selector
	button1->setTouchEnabled(true);
	button1->setTouchPriority(MAX_INT);
	if(sel1) {
		button1->setUpSelector(sel1);
	} else{
		button1->setUpSelector(m_defaultSelector);
	}
	button2->setTouchEnabled(true);
	button2->setTouchPriority(MAX_INT);
	if(sel2) {
		button2->setUpSelector(sel2);
	} else{
		button2->setUpSelector(m_defaultSelector);
	}

	// add button
	m_buttons->push_back(b1);
	m_buttons->push_back(b2);

	return this;
}

wyDialog* wyDialog::addButton(wyNode* button, wyNode* label, wyTargetSelector* sel) {
	// check button node
	if(!button) {
		LOGW("wyDialog::addButton: can't add a null button node");
		return this;
	}

	// button structure
	Button b = {
		button,
		label,
		sel,
		false
	};

	// add button
	m_bg->addChildLocked(button);

	// add label
	if(label)
		m_bg->addChildLocked(label);

	// install selector
	button->setTouchEnabled(true);
	button->setTouchPriority(MAX_INT);
	if(sel) {
		button->setUpSelector(sel);
	} else{
		button->setUpSelector(m_defaultSelector);
	}

	// add button
	m_buttons->push_back(b);

	return this;
}

wyDialog* wyDialog::setTransition(wyDialogTransition* t) {
	wyObjectRetain(t);
	wyObjectRelease(m_transition);
	m_transition = t;
	return this;
}

wyDialog* wyDialog::setBackKeyEquivalentButtonIndex(int index) {
	m_backKeyButtonIndex = index;
	return this;
}

wyDialog* wyDialog::create() {
	if(m_created)
		return this;

	// set flag
	m_created = true;

	// content size
	float width = 0;
	float height = 0;

	// indicating a spacing need to be applied
	bool needSpacing = false;

	// check title node
	if(m_title) {
		width = MAX(width, m_title->getWidth());
		height += m_title->getHeight();
		needSpacing = true;
	}

	// check message node
	if(m_content) {
		if(needSpacing) {
			height += COMPONENT_SPACING;
			needSpacing = false;
		}

		width = MAX(width, m_content->getWidth());
		height += m_content->getHeight();
		needSpacing = true;
	}

	// check buttons
	if(m_buttons->size() > 0) {
		// frist column button
		bool firstColumn = true;
		float columnModeWidth = 0;
		float columnModeHeight = 0;

		for(vector<Button>::iterator iter = m_buttons->begin(); iter != m_buttons->end(); iter++) {
			if(needSpacing) {
				height += COMPONENT_SPACING;
				needSpacing = false;
			}

			if(iter->twoColumns) {
				if(firstColumn) {
					columnModeWidth = iter->button->getWidth();
					columnModeHeight = iter->button->getHeight();
					firstColumn = false;
				} else {
					columnModeWidth += iter->button->getWidth() + COMPONENT_SPACING;
					columnModeHeight = MAX(columnModeHeight, iter->button->getHeight());
					width = MAX(width, columnModeWidth);
					height += columnModeHeight;
					firstColumn = true;
					needSpacing = true;
				}
			} else {
				width = MAX(width, iter->button->getWidth());
				height += iter->button->getHeight();
				needSpacing = true;
			}
		}
	}

	// final background size
	float bgWidth = width + m_leftPadding + m_rightPadding;
	float bgHeight = height + m_topPadding + m_bottomPadding;
	bgWidth = MIN(wyDevice::winWidth, MAX(bgWidth, m_bg->getWidth()));
	bgHeight = MIN(wyDevice::winHeight, MAX(bgHeight, m_bg->getHeight()));

	// set background size
	if(m_bg) {
		m_bg->setAnchor(0.5f, 0.5f);
		m_bg->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
		m_bg->setContentSize(bgWidth, bgHeight);

		// if m_bg is a texture node, enable auto fit
		wyTextureNode* tn = dynamic_cast<wyTextureNode*>(m_bg);
		if(tn)
			tn->setAutoFit(true);
	}

	// layout title
	float y = bgHeight - m_topPadding;
	needSpacing = false;
	if(m_title) {
		m_title->setAnchor(0.5f, 1);
		m_title->setPosition(bgWidth / 2, y);
		y -= m_title->getHeight();
		needSpacing = true;
	}

	// layout message
	if(m_content) {
		if(needSpacing) {
			y -= COMPONENT_SPACING;
			needSpacing = false;
		}
		m_content->setAnchor(0.5f, 1);
		m_content->setPosition(bgWidth / 2, y);
		y -= m_content->getHeight();
		needSpacing = true;
	}

	// layer buttons
	if(m_buttons->size() > 0) {
		// frist column button
		bool firstColumn = true;
		float firstColumnButtonWidth = 0;
		float columnModeHeight = 0;

		// keep first column button
		Button* firstBtn;

		for(vector<Button>::iterator iter = m_buttons->begin(); iter != m_buttons->end(); iter++) {
			if(needSpacing) {
				y -= COMPONENT_SPACING;
				needSpacing = false;
			}

			Button& b = *iter;
			if(b.twoColumns) {
				if(firstColumn) {
					firstBtn = &b;
					firstColumn = false;
				} else {
					// height of this line
					float lineHeight = MAX(firstBtn->button->getHeight(), b.button->getHeight());

					// layout first
					firstBtn->button->setAnchor(0.5f, 0.5f);
					firstBtn->button->setPosition(bgWidth / 2 - COMPONENT_SPACING / 2 - firstBtn->button->getWidth() / 2,
							y - lineHeight / 2);

					// layout first label
					if(firstBtn->label) {
						firstBtn->label->setAnchor(0.5f, 0.5f);
						firstBtn->label->setPosition(firstBtn->button->getOriginX() + firstBtn->button->getWidth() / 2,
								firstBtn->button->getOriginY() + firstBtn->button->getHeight() / 2);
					}

					// layout second
					b.button->setAnchor(0.5f, 0.5f);
					b.button->setPosition(bgWidth / 2 + COMPONENT_SPACING / 2 + b.button->getWidth() / 2,
							y - lineHeight / 2);

					// layout second label
					if(b.label) {
						b.label->setAnchor(0.5f, 0.5f);
						b.label->setPosition(b.button->getOriginX() + b.button->getWidth() / 2,
								b.button->getOriginY() + b.button->getHeight() / 2);
					}

					// adjust y
					y -= lineHeight;

					// return to first column and reset spacing flag
					firstColumn = true;
					needSpacing = true;
				}
			} else {
				b.button->setAnchor(0.5f, 1);
				b.button->setPosition(bgWidth / 2, y);
				if(b.label) {
					b.label->setAnchor(0.5f, 1);
					b.label->setPosition(bgWidth / 2, y - (b.button->getHeight() - b.label->getHeight()) / 2);
				}
				y -= b.button->getHeight();
				needSpacing = true;
			}
		}
	}

	return this;
}

wyDialog* wyDialog::show(bool withAnimation) {
	// no director, return
	if(!gDirector)
		return this;

	// ensure created
	create();

	// add to current scene
	wyScene* scene = gDirector->getRunningScene();
	if(!scene)
		return this;
	scene->addChildLocked(this);

	// bring to top
	scene->bringToFront(this);

	// apply action
	if(m_transition && withAnimation) {
		m_transition->applyIn(this);
	}

	return this;
}

void wyDialog::dismiss(bool withAnimation) {
	wyNode* p = getParent();
	if(p) {
		if(m_transition && withAnimation) {
			m_transition->applyOut(this);
		} else {
			p->removeChildLocked(this, true);
		}
	}
}

bool wyDialog::keyDown(wyKeyEvent& event) {
	return true;
}

bool wyDialog::keyUp(wyKeyEvent& event) {
	switch(event.keyCode) {
		case KEYCODE_BACK:
			if(m_backKeyButtonIndex < 0 || m_backKeyButtonIndex >= m_buttons->size()) {
				dismiss();
			} else {
				Button& b = m_buttons->at(m_backKeyButtonIndex);
				if(b.sel) {
					b.sel->invoke();
				} else {
					dismiss();
				}
			}
			break;
	}

	return true;
}

bool wyDialog::keyMultiple(wyKeyEvent& event) {
	return true;
};

bool wyDialog::touchesBegan(wyMotionEvent& e) {
	return true;
}

bool wyDialog::touchesMoved(wyMotionEvent& e) {
	return true;
}

bool wyDialog::touchesEnded(wyMotionEvent& e) {
	return true;
}

bool wyDialog::touchesCancelled(wyMotionEvent& e) {
	return true;
}

bool wyDialog::touchesPointerBegan(wyMotionEvent& e) {
	return true;
}

bool wyDialog::touchesPointerEnded(wyMotionEvent& e) {
	return true;
}
