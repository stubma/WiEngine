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
#include "wyDialogPopupTransition.h"
#include "wyScaleTo.h"
#include "wySequence.h"
#include "wyDialog.h"

wyDialogPopupTransition::wyDialogPopupTransition() :
		m_maxScale(1.1f),
		m_scaleUpDuration(0.2f) {
}

wyDialogPopupTransition::~wyDialogPopupTransition() {
}

wyDialogPopupTransition* wyDialogPopupTransition::make() {
	wyDialogPopupTransition* t = WYNEW wyDialogPopupTransition();
	return (wyDialogPopupTransition*)t->autoRelease();
}

wyIntervalAction* wyDialogPopupTransition::getInAction() {
	// scale up
	wyScaleTo* scaleUp = wyScaleTo::make(m_scaleUpDuration, 0, m_maxScale);

	// scale down
	wyScaleTo* scaleDown = wyScaleTo::make(0.1f, m_maxScale, 1);

	// sequence
	return wySequence::make(scaleUp, scaleDown, NULL);
}

wyIntervalAction* wyDialogPopupTransition::getOutAction() {
	// scale up
	wyScaleTo* scaleUp = wyScaleTo::make(m_scaleUpDuration, 1, m_maxScale);

	// scale down
	wyScaleTo* scaleDown = wyScaleTo::make(0.1f, m_maxScale, 0);

	// sequence
	return wySequence::make(scaleUp, scaleDown, NULL);
}

void wyDialogPopupTransition::applyIn(wyDialog* dialog) {
	wyNode* bg = dialog->getBackground();
	bg->setScale(0);
	wyDialogTransition::applyIn(dialog);
}
