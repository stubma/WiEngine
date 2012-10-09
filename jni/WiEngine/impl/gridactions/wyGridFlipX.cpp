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
#include "wyGridFlipX.h"
#include "wyNode.h"

wyAction* wyGridFlipX::copy() {
	return wyGridFlipX::make(m_duration);
}

void wyGridFlipX::update(float t) {
	float radian = M_PI * t; // 180 degrees

	wyVertex3D v0, v1, v;
	wyVertex3D diff = wyvZero;

	v0 = getOriginalVertex(wyd(m_gridX, m_gridY));
	v1 = getOriginalVertex(wyd(0, 0));

	float x0 = v0.x;
	float x1 = v1.x;
	float deltaX;
	wyDimension a, b, c, d;

	if(x0 > x1) {
		// Normal Grid
		a = wyd(0, 0);
		b = wyd(0, m_gridY);
		c = wyd(m_gridX, 0);
		d = wyd(m_gridX, m_gridY);
	} else {
		// Reversed Grid
		c = wyd(0, 0);
		d = wyd(0, m_gridY);
		a = wyd(m_gridX, 0);
		b = wyd(m_gridX, m_gridY);
	}
	deltaX = fabs(x0 - x1) / 2;

	diff.x = (deltaX - deltaX * wyMath::cos(radian));
	diff.z = fabs(deltaX * wyMath::sin(radian));

	// bottom-left
	v = getOriginalVertex(a);
	v.x += diff.x;
	v.z += diff.z;
	setVertex(a, v);

	// upper-left
	v = getOriginalVertex(b);
	v.x += diff.x;
	v.z += diff.z;
	setVertex(b, v);

	// bottom-right
	v = getOriginalVertex(c);
	v.x -= diff.x;
	v.z -= diff.z;
	setVertex(c, v);

	// upper-right
	v = getOriginalVertex(d);
	v.x -= diff.x;
	v.z -= diff.z;
	setVertex(d, v);

	// super only call callback
	wyGrid3DAction::update(t);
}

wyGridFlipX::~wyGridFlipX() {
}

wyGridFlipX::wyGridFlipX(float duration) : wyGrid3DAction(duration, 1, 1) {
}

wyGridFlipX* wyGridFlipX::make(float duration) {
	wyGridFlipX* a = WYNEW wyGridFlipX(duration);
	return (wyGridFlipX*)a->autoRelease();
}
