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
#ifndef __wySlotTransform_h__
#define __wySlotTransform_h__

#include "wyTransform.h"

class wyTexture2D;

/**
 * transform of slot, it records key frames of one slot
 */
class WIENGINE_API wySlotTransform : public wyTransform {
public:
	/// key frame of slot skin attachment
	struct SkinKeyFrame : public KeyFrame {
		/// skin attachment name
		const char* skinName;
	};
	
	/// key frame of slot color
	struct ColorKeyFrame : public KeyFrame {
		/// color in argb format
		int color;
	};
	
private:
	/// slot name
	const char* m_slotName;
	
	/// current slot image
	SkinKeyFrame m_currentSkin;
	
	/// current slot color
	ColorKeyFrame m_currentColor;
	
	/// key frame of slot skin
	typedef vector<SkinKeyFrame> SkinKeyFrameList;
	SkinKeyFrameList m_skfList;
	
	/// key frame of slot color
	typedef vector<ColorKeyFrame> ColorKeyFrameList;
	ColorKeyFrameList m_ckfList;
	
private:
	/// create related texture
	wyTexture2D* createRelatedTexture(wySkeleton* s, const char* name);
	
protected:
	wySlotTransform();
	
public:
	virtual ~wySlotTransform();
	static wySlotTransform* make();
	
	/// @see wyTransform::populateFrame
	virtual void populateFrame(float time);
	
	/// @see wyTransform::applyTo
	virtual bool applyTo(wySkeleton* s);
	
	/// @see wyTransform::dump
	virtual void dump();
	
	/// set slot name
	void setSlotName(const char* name);
	
	/// get slot name, caller should NOT release it
	const char* getSlotName() { return m_slotName; }
	
	/// add slot skin key frame, the skin name will not be copied, so caller
	/// should NOT release the original one after returns
	void addSkinKeyFrame(SkinKeyFrame kf);
	
	/// add slot color key frame
	void addColorKeyFrame(ColorKeyFrame kf);
	
	/// get slot skin frame
	SkinKeyFrame& getSkinFrame() { return m_currentSkin; }
	
	/// get slot color frame
	ColorKeyFrame& getColorFrame() { return m_currentColor; }
};

#endif // __wySlotTransform_h__
