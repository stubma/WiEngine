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
#include "wyCameraAction.h"
#include "wyReverseTime.h"
#include "wyNode.h"
#include "wyLog.h"
#include "wyCamera.h"

wyAction* wyCameraAction::reverse() {
	return wyReverseTime::make((wyFiniteTimeAction*)copy());
}

void wyCameraAction::start(wyNode* target) {
    wyIntervalAction::start(target);

    wyCamera* camera = target->getCamera();
    float c[3];
    camera->getCenter(c);
    m_centerX = c[0];
    m_centerY = c[1];
    m_centerZ = c[2];

    camera->getEye(c);
    m_eyeX = c[0];
    m_eyeY = c[1];
    m_eyeZ = c[2];

    camera->getUp(c);
    m_upX = c[0];
    m_upY = c[1];
    m_upZ = c[2];
}

wyCameraAction::~wyCameraAction() {
}

wyCameraAction::wyCameraAction(float duration) :
		wyIntervalAction(duration),
		m_centerX(0),
		m_centerY(0),
		m_centerZ(0),
		m_eyeX(0),
		m_eyeY(0),
		m_eyeZ(0),
		m_upX(0),
		m_upY(0),
		m_upZ(0) {
}
