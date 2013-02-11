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
#ifndef __wySkeletalSprite_h__
#define __wySkeletalSprite_h__

#include "wyNode.h"
#include "wySkeleton.h"
#include "wySkeletalAnimation.h"
#include "wySpriteEx.h"

/**
 * sprite can play skeletal animation
 *
 * \note
 * by default, its content size is zero
 */
class WIENGINE_API wySkeletalSprite : public wyNode {
private:
	/// skeleton
	wySkeleton* m_skeleton;
	
	/// current skeletal animation
	wySkeletalAnimation* m_animation;
	
	/// loop flag, -1 for infinite loop, 0 for no loop, > 0 for loop times
	int m_loop;
	
	/// root bone
	wyBone* m_rootBone;
	
protected:
	wySkeletalSprite();
	
	/// initialization before an animation is firsttime run
	void setupFirstFrameState();
	
	/**
	 * set animation time
	 *
	 * @param time animation time, in second. if the time exceeds the max time of animation,
	 *		then depend on the \c m_loop flag
	 */
	void setFrame(float time);
	
	/// create sprite by a name, the sprite location depends on skeleton location
	wySpriteEx* createRelatedSprite(const char* name);
	
	/// create bone nodes
	void createBoneNodes(wyBone* bone);
	
	/// create slot sprites
	void createSlotSprites();
	
	/// save original bone info
	void saveOriginalBoneInfo(wyBone* bone);
	
	/// restore to original bone state
	void restoreOriginalBoneInfo(wyBone* bone);
	
	/// sync bone state to bone node
	void syncBoneStates(wyBone* bone);
	
	/// sync skin attachment state to slot sprite
	void syncSkinAttachmentStates();
	
public:
	virtual ~wySkeletalSprite();
	
	/**
	 * create a skeletal sprite
	 * 
	 * @param s skeleton model
	 * @return \link wySkeletalSprite wySkeletalSprite\endlinnk
	 */
	static wySkeletalSprite* make(wySkeleton* s);
	
	/// @see wyNode::visit
	virtual void visit();
	
	/// stop any animation which is ongoing
	void stopAnimation();
	
	/// set skeleton, this will stop current animation if any
	void setSkeleton(wySkeleton* s);
	
	/// get skeleton
	wySkeleton* getSkeleton() { return m_skeleton; }
	
	/// play an animation, that will stop current animation if any
	void playAnimation(wySkeletalAnimation* anim);
	
	/**
	 * play an animation, that will stop current animation if any
	 *
	 * @param animName animation key in skeletal animation cache, the animation must be added	
	 *		before calling this method. otherwise nothing will happen
	 */
	void playAnimation(const char* animName);
	
	/// get animation
	wySkeletalAnimation* getAnimation() { return m_animation; }
	
	/// set loop style, -1 means infinite loop, 0 means no loop, larger than 0 means loop times
	void setLoopCount(int loop) { m_loop = loop; }
	
	/// get loop flag, -1 means infinite loop, 0 means no loop, larger than 0 means loop times
	int getLoopCount() { return m_loop; }
};

#endif // __wySkeletalSprite_h__
