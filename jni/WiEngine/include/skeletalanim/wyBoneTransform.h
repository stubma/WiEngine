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

#include "wyTransform.h"

/**
 * transform of bone, it records key frames of one bone
 */
class WIENGINE_API wyBoneTransform : public wyTransform {
public:			
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
	
private:
	/// boen name
	const char* m_boneName;
	
	/// current rotation
	RotationKeyFrame m_currentRotation;
	
	/// current translation
	TranslationKeyFrame m_currentTranslation;
	
	/// current scale
	ScaleKeyFrame m_currentScale;
	
	/// key frame list of rotation
	typedef vector<RotationKeyFrame> RotationKeyFrameList;
	RotationKeyFrameList m_rkfList;
	
	/// key frame list of translation
	typedef vector<TranslationKeyFrame> TranslationKeyFrameList;
	TranslationKeyFrameList m_tkfList;
	
	/// key frame list of scale
	typedef vector<ScaleKeyFrame> ScaleKeyFrameList;
	ScaleKeyFrameList m_skfList;
	
protected:
	wyBoneTransform();
	
public:
	virtual ~wyBoneTransform();
	static wyBoneTransform* make();
	
	/// @see wyTransform::populateFrame
	virtual void populateFrame(float time);
	
	/// @see wyTransform::applyTo
	virtual bool applyTo(wySkeletalSprite* owner);
	
	/// @see wyTransform::dump
	virtual void dump();
	
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
	
	/// get current rotation frame
	RotationKeyFrame& getRotationFrame() { return m_currentRotation; }
	
	/// get current translation frame
	TranslationKeyFrame& getTranslationFrame() { return m_currentTranslation; }
	
	/// get current scale frame
	ScaleKeyFrame& getScaleFrame() { return m_currentScale; }
};

#endif // __wyBoneTransform_h__
