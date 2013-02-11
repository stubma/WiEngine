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
#ifndef __wySkeletalAnimationCache_h__
#define __wySkeletalAnimationCache_h__

#include "wyObject.h"
#include "wySkeletalAnimation.h"

/**
 * cache of skeletal animation, singleton pattern
 */
class WIENGINE_API wySkeletalAnimationCache : public wyObject {
private:
	/// animation map
	typedef map<const char*, wySkeletalAnimation*, wyStrPredicate> AnimationMap;
	AnimationMap m_animMap;
	
protected:
	wySkeletalAnimationCache();
	
public:
	virtual ~wySkeletalAnimationCache();
	
	/// get singleton instance, or create a new one if not existent
	static wySkeletalAnimationCache* getInstance();
	
	/// get singleton instance, may return NULL if not existent
	static wySkeletalAnimationCache* peekInstance();
	
	/// add an animation, the animation must have a name set
	void addAnimation(wySkeletalAnimation* anim);
	
	/// add an animation, and the name of animation will be set
	void addAnimation(const char* name, wySkeletalAnimation* anim);
	
	/// get an animation by name
	wySkeletalAnimation* getAnimation(const char* name);

	/// remove all cached animations
	void purgeCache();
};

#endif // __wySkeletalAnimationCache_h__
