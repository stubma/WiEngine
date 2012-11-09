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
#ifndef __wyAnimation_h__
#define __wyAnimation_h__

#include "wyArray.h"
#include "wyFrame.h"
#include "wyTexture2D.h"

class wyAnimate;
class wyAnimation;

/**
 * callback which will be called as animation runs.
 * Notice, \link wyAnimation wyAnimation\endlink is not an action, instead, you should use
 * \link wyAnimate wyAnimate\endlink to execute an animation. This callback is called from
 * \link wyAnimate wyAnimate\endlink.
 */
class WIENGINE_API wyAnimationCallback {
public:
	/**
	 * called when the displaying frame changes
	 *
	 * @param anim \link wyAnimation wyAnimation\endlink object
	 * @param index the index of the displaying frame
	 */
	virtual void onAnimationFrameChanged(wyAnimation* anim, int index) = 0;

	/**
	 * called when the animation ends.
	 * If \link wyAnimate wyAnimate\endlink runs inside a \link wyRepeat wyRepeat\endlink action,
	 * this method will be called every time wyAnimate is repeated.
	 * @param anim \link wyAnimation wyAnimation\endlink object
	 */
	virtual void onAnimationEnded(wyAnimation* anim) = 0;
};

/**
 * The animation consists of frames with each frame has a duration.
 */
class WIENGINE_API wyAnimation : public wyObject {
	friend class wyAnimate;

private:
	// identifier of the animation
	int m_id;

	/// \link wyArray wyArray\endlink object, used to store frames
	wyArray* m_frames;

	/// duration of the whole animation
	float m_duration;

	/// \link wyAniamtionCallback wyAnimationCallback\endlink
	wyAnimationCallback* m_callback;

private:
	/**
	 * to release a frame
	 *
	 * @param arr the pointer to frame \link wyArray array\endlink
	 * @param ptr the current frame
	 * @param index index of the frame to be released
	 * @param data user data
	 */
	static bool releaseFrame(wyArray* arr, void* ptr, int index, void* data);

protected:
	/**
	 * called when the frame changes
	 *
	 * @param index the index of the current frame
	 */
	void notifyAnimationFrameChanged(int index);

	/**
	 * called when the animation ends. if the animation is executed in
	 * a repeat loop, then it will be called every loop
	 */
	void notifyAnimationEnded();

protected:
	/**
	 * constructor
	 *
	 * @param id identifier
	 */
	wyAnimation(int id);

public:
	/**
	 * factory function, used to created a new instance with autoRelease enabled
	 *
	 * @param id identifier
	 */
	static wyAnimation* make(int id);

	virtual ~wyAnimation();

	/**
	 * getter, get the total duration of the whole animation
	 */
	float getDuration() { return m_duration; }

	/**
	 * getter, get the frame array
	 */
	wyArray* getFrames() { return m_frames; }

	/**
	 * getter, get the identifier of the animation
	 */
	int getId() { return m_id; }

	/**
	 * to add a frame to the animation
	 *
	 * @param frameDuration duration of the frame to be added
	 * @param tex \link wyTexture2D wyTexture2D object\endlink
	 */
	void addFrame(float frameDuration, wyTexture2D* tex);

	/**
	 * to add a frame to the animation
	 *
	 * @param frameDuration duration of the frame to be added
	 * @param rect the rectangle of the frame in the atlas picture
	 */
	void addFrame(float frameDuration, wyRect rect);

	/**
	 * to add a frame
	 *
	 * @param f \link wyFrame wyFrame\endlink
	 */
	void addFrame(wyFrame* f);

	/**
	 * to set the callback
	 *
	 * @param callback \link wyAnimationCallback wyAnimationCallback\endlink
	 */
	void setCallback(wyAnimationCallback* callback) { m_callback = callback; }
};

#endif //__wyAnimation_h__
