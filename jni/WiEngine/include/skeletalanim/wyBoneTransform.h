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
#ifndef __wyBoneTransform_h__
#define __wyBoneTransform_h__

#include "wyObject.h"

/**
 * transform of bone, it records key frames of one bone
 */
class WIENGINE_API wyBoneTransform : public wyObject {
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
	};
	
	/// key frame of rotation
	struct RotationKeyFrame : public KeyFrame {
		/// angle in degree, positive value is counter-clockwise
		float angle;
	};
	
	/// key frame of translation
	struct TranslationKeyFrame : public KeyFrame {
		/// x offset
		float x;
		
		/// y offset
		float y;
	};
	
	/// key frame of scale
	struct ScaleKeyFrame : public KeyFrame {
		/// x scale
		float scaleX;
		
		/// y scale
		float scaleY;
	};
	
	/// key frame of slot skin attachment
	struct SlotSkinKeyFrame : public KeyFrame {
		/// skin attachment name
		const char* skinName;
	};
	
	/// key frame of slot color
	struct SlotColorKeyFrame : public KeyFrame {
		/// color in argb format
		int color;
	};
	
private:
	/// current time
	float m_currentTime;
	
	/// boen name
	const char* m_boneName;
	
	/// current rotation
	RotationKeyFrame m_currentRotation;
	
	/// current translation
	TranslationKeyFrame m_currentTranslation;
	
	/// current scale
	ScaleKeyFrame m_currentScale;
	
	/// current slot image
	SlotSkinKeyFrame m_currentSlotSkin;
	
	/// current slot color
	SlotColorKeyFrame m_currentSlotColor;
	
	/// key frame list of rotation
	typedef vector<RotationKeyFrame> RotationKeyFrameList;
	RotationKeyFrameList m_rkfList;
	
	/// key frame list of translation
	typedef vector<TranslationKeyFrame> TranslationKeyFrameList;
	TranslationKeyFrameList m_tkfList;
	
	/// key frame list of scale
	typedef vector<ScaleKeyFrame> ScaleKeyFrameList;
	ScaleKeyFrameList m_skfList;
	
	/// key frame of slot skin
	typedef vector<SlotSkinKeyFrame> SlotSkinKeyFrameList;
	SlotSkinKeyFrameList m_sskfList;
	
	/// key frame of slot color
	typedef vector<SlotColorKeyFrame> SlotColorKeyFrameList;
	SlotColorKeyFrameList m_sckfList;
	
protected:
	wyBoneTransform();
	
public:
	virtual ~wyBoneTransform();
	static wyBoneTransform* make();
	
	/// set bone name
	void setBoneName(const char* name);

	/// get bone name, caller should NOT release it
	const char* getBoneName() { return m_boneName; }

	/// add rotation key frame
	void addRotationKeyFrame(RotationKeyFrame kf);

	/// add translation key frame
	void addTranslationKeyFrame(TranslationKeyFrame kf);

	/// add scale key frame
	void addScaleKeyFrame(ScaleKeyFrame kf);

	/// add slot skin key frame, the skin name will be copied, so caller can release the original one after returns
	void addSlotSkinKeyFrame(SlotSkinKeyFrame kf);

	/// add slot color key frame
	void addSlotColorKeyFrame(SlotColorKeyFrame kf);
	
	/// dump info for debug purpose
	void dump();
};

#endif // __wyBoneTransform_h__
