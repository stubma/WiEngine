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
#include "wyDialogTransition.h"
#include "wyDialog.h"

// tag for in & out action
#define TAG_IN_ACTION 0x10000
#define TAG_OUT_ACTION 0x10001

wyDialogTransition::wyDialogTransition() {
}

wyDialogTransition::~wyDialogTransition() {
}

void wyDialogTransition::onActionStop(wyAction* action) {
	// the action target is background, whose parent is dialog
	wyNode* target = action->getTarget();
	wyDialog* dialog = (wyDialog*)target->getParent();

	switch(action->getTag()) {
		case TAG_IN_ACTION:
			dialog->getParent()->setEnabled(true);
			break;
		case TAG_OUT_ACTION:
			dialog->getParent()->setEnabled(true);
			dialog->dismiss(false);
			break;
	}
}

wyIntervalAction* wyDialogTransition::getInAction() {
	return NULL;
}

wyIntervalAction* wyDialogTransition::getOutAction() {
	return NULL;
}

void wyDialogTransition::applyIn(wyDialog* dialog) {
	wyIntervalAction* a = getInAction();
	if(a) {
		a->setTag(TAG_IN_ACTION);
		a->setCallback(this);
		dialog->getParent()->setEnabled(false);
		dialog->getBackground()->runAction(a);
	}
}

void wyDialogTransition::applyOut(wyDialog* dialog) {
	wyIntervalAction* a = getOutAction();
	if(a) {
		a->setTag(TAG_OUT_ACTION);
		a->setCallback(this);
		dialog->getParent()->setEnabled(false);
		dialog->getBackground()->runAction(a);
	} else {
		dialog->dismiss(false);
	}
}
