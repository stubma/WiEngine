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
#ifndef __wyActionManager_h__
#define __wyActionManager_h__

#include "wyNode.h"
#include "wyAction.h"
#include "wyHashSet.h"
#include <stdbool.h>

/**
 * @class wyActionManager
 * Action manager, used to manage nodes which are running actions or nodes which
 * non-zero velocity or acceleration is applied on.
 */
class WIENGINE_API wyActionManager : public wyObject {
private:
	/**
	 * Used to store nodes which are running actions
	 */
	wyHashSet* m_targets;

	/**
	 * true means removeAllActions is being executed
	 */
	bool m_removingAll;

	/**
	 * nodes which non-zero velocity or acceleration is applied on.
	 */
	wyArray* m_physicsNodes;

	/**
	 * In situation that m_physicsNodes is being operated(or locked), to add a node to m_physicsNodes
	 * must be replaced by adding it to this array.
	 */
	wyArray* m_physicsNodesPendingAdd;

	/**
	 * In situation that m_physicsNodes is being operated(or locked), to remove a node from m_physicsNodes
	 * must be replaced by adding it to this array.
	 */
	wyArray* m_physicsNodesPendingRemove;

private:
	/**
	 * constructor
	 */
	wyActionManager();

	static int actionHashEquals(void* ptr, void* elt);
	static void* buildActionHash(void* ptr, void* data);
	static bool execAction(wyArray* arr, void* ptr, int index, void* data);
	static bool removeActions(wyArray* arr, void* ptr, int index, void* data);
	static bool sResumeActions(wyArray* arr, void* ptr, int index, void* data);
	static bool sPauseActions(wyArray* arr, void* ptr, int index, void* data);
	static bool sUpdateNodePhysics(wyArray* arr, void* ptr, int index, void* data);
	static bool sTick(void* elt, void* data);
	static bool deleteEmtpyTarget(void* elt, void* data);
	static bool findActionByTag(void* elementPtr, void* ptr2, void* data);
	static bool releaseHash(void* elt, void* data);

public:
	/**
	 * Single instance getter
	 *
	 * @return \link wyActionManager wyActionManager instance \endlink
	 */
	static wyActionManager* getInstance();

	/**
	 * destructor
	 */
	virtual ~wyActionManager();

	/**
	 * To add an action, thread safe.
	 * If the action has ever added before, then nothing will happen.
	 *
	 * @param action \link wyAction wyAction\endlink
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 */
	void addActionLocked(wyAction* action, wyNode* target);

	/**
	 * To delete an action, thread safe.
	 *
	 * @param action \link wyAction wyAction\endlink
	 */
	void removeActionLocked(wyAction* action);

	/**
	 * To delete one of one node's actions according to the tag, thread safe.
	 *
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 * @param tag action's tag
	 */
	void removeActionByTagLocked(wyNode* target, int tag);

	/**
	 * To delete all actions of one node, thread safe.
	 *
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 * @param includeChildren indicates whether actions of child nodes are also deleted.
	 */
	void removeActionsLocked(wyNode* target, bool includeChildren);

	/**
	 * To delete all actions of all nodes, thread safe.
	 */
	void removeAllActionsLocked();

	/**
	 * To pause one action of a node according to tag, thread safe.
	 *
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 * @param tag tag of the action
	 */
	void pauseActionLocked(wyNode* target, int tag);

	/**
	 * To resume a action which was paused before, thread safe
	 *
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 * @param tag tag of the action
	 */
	void resumeActionLocked(wyNode* target, int tag);

	/**
	 *
	 * To resume all actions of a node.
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 * @param includeChildren indicates whether actions of child nodes are also resumed
	 */
	void resumeActions(wyNode* target, bool includeChildren);

	/**
	 * To pause all actions of a node.
	 *
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 * @param includeChildren indicates whether actions of child nodes are also paused
	 */
	void pauseActions(wyNode* target, bool includeChildren);

	/**
	 * To get the count of running actions of a node
	 *
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 * @return count of running actions
	 */
	int getRunningActionCount(wyNode* target);

	/**
	 * To get one action of a node according to the tag.
	 *
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 * @param tag  tag of the action
	 * @return \link wyAction wyAction\endlink
	 */
	wyAction* getAction(wyNode* target, int tag);

	/**
	 * To update actions
	 *
	 * @param delta time, in seconds
	 */
	void tick(float delta);

	/**
	 * To add a node to the physics array, developers shouldn't call this function.
	 *
	 * @param node \link wyNode wyNode\endlink
	 */
	void addPhysicsNode(wyNode* node);

	/**
	 * To remove a node from the physics array, developers shouldn't call this function.
	 *
	 * @param node  \link wyNode wyNode\endlink
	 */
	void removePhysicsNode(wyNode* node);
};

#endif // __wyActionManager_h__
