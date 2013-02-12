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
#ifndef __wyTransform_h__
#define __wyTransform_h__

#include "wyObject.h"
#include "wyTypes.h"

class wySkeleton;

/**
 * transform base class
 */
class WIENGINE_API wyTransform : public wyObject {
public:
	/// interpolator type
	enum InterpolatorType {
		/// linear change
		LINEAR,
		
		/// change in a bezier style, controled by two control points
		BEZIER,
		
		/// instantly changed at the end
		STEP
	};
	
	/// interpolator
	struct Interpolator {
		/// type
		InterpolatorType type;
		
		/// control point 1, for bezier interpolator only
		/// they are relative value, between 0 and 1
		float cp1X, cp1Y;
		
		/// control point 2, for bezier interpolator only
		/// they are relative value, between 0 and 1
		float cp2X, cp2Y;
	};
	
	/// key frame base
	struct KeyFrame {
		/// time
		float time;
		
		/// interpolator
		Interpolator interpolator;
		
		/// true means this key frame is valid
		bool valid;
	};
	
protected:
	wyTransform();
	
	/// get interpolation time, from 0 to 1
	wyPoint getInterpolationTime(float startTime, float endTime, float curTime, Interpolator& interpolator);
	
public:
	virtual ~wyTransform();
	
	/// calculate current frame
	virtual void populateFrame(float time) = 0;
	
	/**
	 * apply current frame to a skeleton
	 *
	 * @param s skeleton
	 * @return true if frame is applied, or false if not applied
	 */
	virtual bool applyTo(wySkeleton* s) = 0;
	
	/// dump info, for debug purpose
	virtual void dump() {}
};

#endif // __wyTransform_h__
