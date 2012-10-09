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
#include "wyPageTurn3D.h"
#include "wyNode.h"

wyAction* wyPageTurn3D::copy() {
	return wyPageTurn3D::make(m_duration, m_gridX, m_gridY);
}

void wyPageTurn3D::update(float t) {
	float tt = MAX(0, t - 0.25f);
	float deltaAy = (tt * tt * 500);
	float ay = -100 - deltaAy;

	float deltaTheta = -M_PI / 2 * sqrt(t);
	float theta = M_PI / 2 + deltaTheta;

	float sinTheta = wyMath::sin(theta);
	float cosTheta = wyMath::cos(theta);

	wyDimension gridPos = wydZero;
	for(int i = 0; i <= m_gridX; i++) {
		for(int j = 0; j <= m_gridY; j++) {
			// Get original vertex
			gridPos.x = i;
			gridPos.y = j;
			wyVertex3D p = getOriginalVertex(gridPos);

			float R = sqrt((p.x * p.x) + ((p.y - ay) * (p.y - ay)));
			float r = R * sinTheta;
			float alpha = asin(p.x / R);
			float beta = alpha / sinTheta;
			float cosBeta = wyMath::cos(beta);

			// If beta > PI then we've wrapped around the cone
			// Reduce the radius to stop these points interfering with others
			if(beta <= M_PI) {
				p.x = r * wyMath::sin(beta);
				p.y = R + ay - r * (1 - cosBeta) * sinTheta;

				// We scale z here to avoid the animation being
				// too much bigger than the screen due to perspectve transform
				p.z = r * (1 - cosBeta) * cosTheta / 100;
			} else {
				// Force X = 0 to stop wrapped
				// points
				p.x = 0;
				p.y = R + ay - r * (1 - cosBeta) * sinTheta;
				p.z = 0.001f;
			}

			// Stop z coord from dropping beneath underlying page in a transition
			// issue #751
			if(p.z < 0.9f)
				p.z = 0.9f;

			// Set new coords
			setVertex(gridPos, p);
		}
	}

	// super only call callback
	wyGrid3DAction::update(t);
}

wyPageTurn3D::~wyPageTurn3D() {
}

wyPageTurn3D::wyPageTurn3D(float duration, int gridX, int gridY) : wyGrid3DAction(duration, gridX, gridY) {
}

wyPageTurn3D* wyPageTurn3D::make(float duration, int gridX, int gridY) {
	wyPageTurn3D* a = WYNEW wyPageTurn3D(duration, gridX, gridY);
	return (wyPageTurn3D*)a->autoRelease();
}
