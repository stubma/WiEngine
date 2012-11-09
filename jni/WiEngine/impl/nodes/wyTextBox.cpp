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
#include "wyTextBox.h"
#include "wyDirector.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyGlobal.h"
#include "wyLog.h"
#include "wyRunnable.h"

extern wyDirector* gDirector;

/**
 * 确定按钮点下时执行的方法
 */
class wyPositiveRunnable : public wyRunnable {
protected:
	/// 新字符串
	const char* m_text;

	/// text box对象
	wyTextBox* m_box;

public:
	wyPositiveRunnable(wyTextBox* box, const char* text) :
			m_box(box),
			m_text(NULL) {
		m_text = wyUtils::copy(text);
	}

	virtual ~wyPositiveRunnable() {
		wyFree((void*)m_text);
	}

	virtual void run() {
		m_box->setText(m_text);
		m_box->notifyOnEndEditing();
	}
};

/**
 * 取消按钮点下时执行的方法
 */
class wyNegativeRunnable : public wyRunnable {
protected:
	/// text box对象
	wyTextBox* m_box;

public:
	wyNegativeRunnable(wyTextBox* box) :
			m_box(box) {
	}

	virtual ~wyNegativeRunnable() {
	}

	virtual void run() {
		// restore old text
		m_box->setText(m_box->m_oldText);

		// notify
		m_box->notifyOnEndEditing();
	}
};

/**
 * 文本输入时执行的方法
 */
class wyTextChangedRunnable : public wyRunnable {
protected:
	/// text box对象
	wyTextBox* m_box;

	/// 新字符串
	const char* m_text;

public:
	wyTextChangedRunnable(wyTextBox* box, const char* text) :
			m_box(box),
			m_text(NULL) {
		m_text = wyUtils::copy(text);
	}

	virtual ~wyTextChangedRunnable() {
		wyFree((void*)m_text);
	}

	virtual void run() {
		m_box->setText(m_text);
		m_box->notifyOnTextChanged();
	}
};

wyTextBox::wyTextBox(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyNode* label) :
		m_normalState(NULL),
		m_selectedState(NULL),
		m_disabledState(NULL),
		m_focusedState(NULL),
		m_label(NULL),
		m_oldText(NULL),
		m_text(NULL),
		m_title(NULL),
		m_message(NULL),
		m_positiveButton(NULL),
		m_negativeButton(NULL),
		m_leftPadding(0),
		m_rightPadding(0),
		m_topPadding(0),
		m_bottomPadding(0),
		m_password(false),
		m_callback(NULL) {
	// add state and label as child
	if(normal) {
		m_normalState = normal;
		addChildLocked(normal);
	}
	if(selected) {
		m_selectedState = selected;
		addChildLocked(selected);
	}
	if(disabled) {
		m_disabledState = disabled;
		addChildLocked(disabled);
	}
	if(focused) {
		m_focusedState = focused;
		addChildLocked(focused);
	}
	if(label) {
		m_label = label;
		addChildLocked(label);
	}

	// set up selector
	wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyTextBox::onShowDialog));
	setUpSelector(ts);

	// decide text box size
	wySize s = wysZero;
	if(normal) {
		s.width = MAX(normal->getWidth(), s.width);
		s.height = MAX(normal->getHeight(), s.height);
	}
	if(selected) {
		s.width = MAX(selected->getWidth(), s.width);
		s.height = MAX(selected->getHeight(), s.height);
	}
	if(disabled) {
		s.width = MAX(disabled->getWidth(), s.width);
		s.height = MAX(disabled->getHeight(), s.height);
	}
	if(focused) {
		s.width = MAX(focused->getWidth(), s.width);
		s.height = MAX(focused->getHeight(), s.height);
	}
	setContentSize(s.width, s.height);

	// adjust state node position
	if(m_normalState) {
		m_normalState->setAnchor(0, 0);
		m_normalState->setPosition((m_width - m_normalState->getWidth()) / 2, (m_height - m_normalState->getHeight()) / 2);
	}
	if(m_selectedState) {
		m_selectedState->setAnchor(0, 0);
		m_selectedState->setPosition((m_width - m_selectedState->getWidth()) / 2, (m_height - m_selectedState->getHeight()) / 2);
	}
	if(m_disabledState) {
		m_disabledState->setAnchor(0, 0);
		m_disabledState->setPosition((m_width - m_disabledState->getWidth()) / 2, (m_height - m_disabledState->getHeight()) / 2);
	}
	if(m_focusedState) {
		m_focusedState->setAnchor(0, 0);
		m_focusedState->setPosition((m_width - m_focusedState->getWidth()) / 2, (m_height - m_focusedState->getHeight()) / 2);
	}

	// place label
	m_label->setAnchor(0, 0);
	updateLabelSizeAndPosition();

	// enable touch
	setTouchEnabled(true);
}

wyTextBox::~wyTextBox() {
	if(m_title) {
		wyFree((void*)m_title);
	}
	if(m_message) {
		wyFree((void*)m_message);
	}
	if(m_text) {
		wyFree((void*)m_text);
	}
	if(m_oldText) {
		wyFree((void*)m_oldText);
	}
	if(m_positiveButton) {
		wyFree((void*)m_positiveButton);
	}
	if(m_negativeButton) {
		wyFree((void*)m_negativeButton);
	}
}

void wyTextBox::beforeRender() {
	if(m_normalState) {
		m_normalState->setNoDraw(true);
	}
	if(m_selectedState) {
		m_selectedState->setNoDraw(true);
	}
	if(m_disabledState) {
		m_disabledState->setNoDraw(true);
	}
	if(m_focusedState) {
		m_focusedState->setNoDraw(true);
	}

	wyNode* node = NULL;
	if(m_enabled) {
		if(m_selected) {
			if(m_selectedState != NULL)
				node = m_selectedState;
			else
				node = m_normalState;
		} else if(m_focused) {
			if(m_focusedState != NULL)
				node = m_focusedState;
			else
				node = m_normalState;
		} else
			node = m_normalState;
	} else {
		if(m_disabledState != NULL)
			node = m_disabledState;
		else
			node = m_normalState;
	}
	node->setNoDraw(false);
}

void wyTextBox::setPadding(float left, float top, float right, float bottom) {
	m_leftPadding = left;
	m_rightPadding = right;
	m_topPadding = top;
	m_bottomPadding = bottom;
	updateLabelSizeAndPosition();
}

void wyTextBox::updateLabelSizeAndPosition() {
	float w = m_width - m_leftPadding - m_rightPadding;
	float h = m_height - m_topPadding - m_bottomPadding;
	m_label->setContentSize(w, h);
	m_label->setClipRect(wyr(0, 0, w, h), true);
	m_label->setPosition(m_leftPadding, m_bottomPadding);
}

void wyTextBox::onShowDialog(wyTargetSelector* ts) {
	// save old text
	if(m_oldText) {
		wyFree((void*)m_oldText);
		m_oldText = NULL;
	}
	m_oldText = wyUtils::copy(getText());

	// begin editing
	notifyOnBeginEditing();

	// show input dialog in different platforms
	showInputDialog();
}

void wyTextBox::onPositiveButtonClicked(const char* text) {
	wyPositiveRunnable* r = WYNEW wyPositiveRunnable(this, text);
	wyUtils::runOnGLThread(r);
	r->release();
}

void wyTextBox::onNegativeButtonClicked() {
	wyNegativeRunnable* r = WYNEW wyNegativeRunnable(this);
	wyUtils::runOnGLThread(r);
	r->release();
}

void wyTextBox::onTextChanged(const char* newText) {
	wyTextChangedRunnable* r = WYNEW wyTextChangedRunnable(this, newText);
	wyUtils::runOnGLThread(r);
	r->release();
}

int wyTextBox::getAlpha() {
    if(m_normalState)
	    return m_normalState->getAlpha();

	if(m_selectedState)
		return m_selectedState->getAlpha();

	if(m_disabledState)
		return m_disabledState->getAlpha();

	if(m_focusedState)
		return m_focusedState->getAlpha();

	if(m_label)
		return m_label->getAlpha();

    return -1;
}

void wyTextBox::setAlpha(int alpha) {
    if(m_normalState)
	    m_normalState->setAlpha(alpha);

	if(m_selectedState)
		m_selectedState->setAlpha(alpha);

	if(m_disabledState)
		m_disabledState->setAlpha(alpha);

	if(m_focusedState)
		m_focusedState->setAlpha(alpha);

	if(m_label)
		m_label->setAlpha(alpha);
}

wyColor3B wyTextBox::getColor() {
    if(m_normalState)
	    return m_normalState->getColor();

	if(m_selectedState)
		return m_selectedState->getColor();

	if(m_disabledState)
		return m_disabledState->getColor();

	if(m_focusedState)
		return m_focusedState->getColor();

	if(m_label)
		return m_label->getColor();

	return wyc3bWhite;
}

void wyTextBox::setColor(wyColor3B color) {
    if(m_normalState)
	    m_normalState->setColor(color);

	if(m_selectedState)
		m_selectedState->setColor(color);

	if(m_disabledState)
		m_disabledState->setColor(color);

	if(m_focusedState)
		m_focusedState->setColor(color);

	if(m_label)
		m_label->setColor(color);
}

void wyTextBox::setColor(wyColor4B color) {
    if(m_normalState)
	    m_normalState->setColor(color);

	if(m_selectedState)
		m_selectedState->setColor(color);

	if(m_disabledState)
		m_disabledState->setColor(color);

	if(m_focusedState)
		m_focusedState->setColor(color);

	if(m_label)
		m_label->setColor(color);
}

const char* wyTextBox::getText() {
	return m_text;
}

void wyTextBox::setText(const char* text) {
	// release old string
	if(m_text) {
		wyFree((void*)m_text);
		m_text = NULL;
	}

	// save new text
	m_text = wyUtils::copy(text);

	// should set asterisk if password mode
	if(m_password) {
		size_t len = strlen(text);
		char* buf = (char*)wyMalloc(sizeof(char) * (len + 1));
		for(int i = 0; i < len; i++)
			buf[i] = '*';
		buf[len] = 0;
		m_label->setText(buf);
		wyFree(buf);
	} else {
		m_label->setText(text);
	}

	// update label size
	updateLabelSizeAndPosition();
}

void wyTextBox::notifyOnTextChanged() {
	if(m_callback) {
		m_callback->onTextBoxTextChanged(this);
	}
}

void wyTextBox::notifyOnBeginEditing() {
	if(m_callback) {
		m_callback->onTextBoxBeginEditing(this);
	}
}

void wyTextBox::notifyOnEndEditing() {
	if(m_callback) {
		m_callback->onTextBoxEndEditing(this);
	}
}

void wyTextBox::setTitle(const char* title) {
	if(m_title) {
		wyFree((void*)m_title);
		m_title = NULL;
	}
	m_title = wyUtils::copy(title);
}

void wyTextBox::setMessage(const char* msg) {
	if(m_message) {
		wyFree((void*)m_message);
		m_message = NULL;
	}
	m_message = wyUtils::copy(msg);
}

void wyTextBox::setPositiveButton(const char* btn) {
	if(m_positiveButton) {
		wyFree((void*)m_positiveButton);
		m_positiveButton = NULL;
	}
	m_positiveButton = wyUtils::copy(btn);
}

void wyTextBox::setNegativeButton(const char* btn) {
	if(m_negativeButton) {
		wyFree((void*)m_negativeButton);
		m_negativeButton = NULL;
	}
	m_negativeButton = wyUtils::copy(btn);
}
