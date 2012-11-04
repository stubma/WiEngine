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
#ifndef __wyAction_h__
#define __wyAction_h__

#include <stdbool.h>
#include "wyObject.h"
#include "WiEngine-Classes.h"

#define WY_ACTION_INVALID_TAG -1

/**
 * \link wyAction wyAction\endlink callback definition.
 */
typedef struct wyActionCallback {
	/**
	 * Invoked when action is started
	 *
	 * @param action \link wyAction wyAction \endlink pointer
	 * @param data user data pointer
	 */
	void (*onStart)(wyAction* action, void* data);

	/**
	 * Invoked when action is stopped, should call \c isDone to
	 * check whether action is terminated normally
	 *
	 * @param action \link wyAction wyAction \endlink pointer
	 * @param data user data pointer
	 */
	void (*onStop)(wyAction* action, void* data);

	/**
	 * Invoked every time when \c update method is called
	 *
	 * @param action \link wyAction wyAction \endlink pointer
	 * @param t current time, from 0 to 1. If action's duration is 2 seconds, then 0.5 means 1 second
	 * @param data user data pointer
	 */
	void (*onUpdate)(wyAction* action, float t, void* data);
} wyActionCallback;

/**
 * Base class for all actions
 */
class WIENGINE_API wyAction : public wyObject {
	friend class wyActionManager;

protected:
	/// true indicating action is running
	bool m_running;

	/// true indicating action is paused
	bool m_paused;

	/// the \link wyNode wyNode\endlink object on which this action is running
	wyNode* m_target;

	/**
	 * Parent action. Parent action should be a compound action. If this action is not
	 * enclosed by a compound action, then it has no parent action
	 */
	wyAction* m_parent;

	/// tag of action, can be used to query an action from node
	int m_tag;

	/// action callback
	wyActionCallback m_callback;

	/// extra data pointer of action callback
	void* m_data;

#if ANDROID
	/// action callback, but it is defined in java layer so it is a java object
	jobject j_callback;
#endif

protected:
	wyAction();

	/// Invoke start callback
	virtual void invokeOnStart();

	/// Invoke stop callback
	virtual void invokeOnStop();

	/**
	 * Invoke update callback
	 *
	 * @param t current time, from 0 to 1. If action's duration is 2 seconds, then 0.5 means 1 second
	 */
	virtual void invokeOnUpdate(float t);

public:
	virtual ~wyAction();

	/**
	 * Make a copy of current action object, returned object is already
	 * auto released.
	 *
	 * @return \link wyAction wyAction\endlink pointer
	 */
	virtual wyAction* copy();

	/**
	 * Make a reverse copy of this action object, returned object is already
	 * auto released.
	 *
	 * @return \link wyAction wyAction\endlink pointer
	 */
	virtual wyAction* reverse();

	/**
	 * Start action. If callback is set, notify callback
	 *
	 * @param target the \link wyNode wyNode \endlink object on which this action is running
	 */
	virtual void start(wyNode* target);

	/**
	 * Stop action. If callback is set, notify callback
	 */
	virtual void stop();

	/**
	 * Update action with a single step
	 *
	 * @param t time from last step
	 */
	virtual void step(float t);

	/**
	 * Update action. If callback is set, notify callback.
	 *
	 * @param t current time, from 0 to 1. If action's duration is 2 seconds, then 0.5 means 1 second
	 */
	virtual void update(float t);

	/**
	 * Check action state
	 *
	 * @return true indicating action is done
	 */
	virtual bool isDone();

	/**
	 * Set callback
	 *
	 * @param callback \link wyActionCallback wyActionCallback \endlink structure. NULL means clear current callback.
	 * @param data User data pointer, who allocate it should be responsible for release it
	 */
	void setCallback(wyActionCallback* callback, void* data);

#if ANDROID
	
	/**
	 * Set java layer callback
	 *
	 * @param jcallback java side callback object, NULL means clear current callback
	 */
	void setCallback(jobject jcallback);
	
	/**
	 * Get java side callback object
	 *
	 * @return java side callback object
	 */
	jobject getCallback();
	
#endif // #if ANDROID

	/**
	 * Set tag for action. A tag can be used as an unique id of action and later
	 * you can retrieve it by wyNode::getAction method
	 *
	 * @param tag integer for action
	 */
	void setTag(int tag);

	/**
	 * Get action tag
	 *
	 * @return action tag
	 */
	int getTag();

	/**
	 * Get action target.
	 *
	 * @return \link wyNode wyNode\endlink object on which this action is running
	 */
	wyNode* getTarget();
    
    /**
     * is action running or not
     *
     * @return true means it is running
     */
    bool isRunning() { return m_running; }

	/**
	 * Get parent action, if an action is packed in compound action, such as
	 * \link wyRepeat wyRepeat\endlink, then its parent action will be set as
	 * \link wyRepeat wyRepeat\endlink. Usually developer doesn't need care about
	 * this.
	 *
	 * @return parent action, or NULL if not set
	 */
	wyAction* getParent() { return m_parent; }

	/**
	 * Set parent action, it doesn't increase retain count of parent action. This method
	 * is usually called internal and developer should not care about this.
	 *
	 * @param parent parent action
	 */
	void setParent(wyAction* parent) { m_parent = parent; }

	/**
	 * is action paused? There is not method called setPaused because you can't pause action
	 * directly. \link wyNode wyNode\endlink has pauseAction method and you can use that
	 *
	 * @return true means action is paused
	 */
	bool isPaused() { return m_paused; }
};

#endif // __wyAction_h__
