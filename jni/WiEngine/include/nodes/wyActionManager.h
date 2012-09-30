/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

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
 * \if English
 * Action manager, used to manage nodes which are running actions or nodes which
 * non-zero velocity or acceleration is applied on.
 * \else
 * 正在执行的动作管理类
 * \endif
 */
class WIENGINE_API wyActionManager : public wyObject {
private:
	/**
	 * \if English
	 * Used to store nodes which are running actions
	 * \else
	 * 保存正在执行动作的节点 \link wyHashSet wyHashSet对象 \endlink 的指针
	 * \endif
	 */
	wyHashSet* m_targets;

	/**
	 * \if English
	 * true means removeAllActions is being executed
	 * \else
	 * true表示removeAllActions正在被执行
	 * \endif
	 */
	bool m_removingAll;

	/**
	 * \if English
	 * nodes which non-zero velocity or acceleration is applied on.
	 * \else
	 * 具有速度或者加速度的节点
	 * \endif
	 */
	wyArray* m_physicsNodes;

	/**
	 * \if English
	 * In situation that m_physicsNodes is being operated(or locked), to add a node to m_physicsNodes
	 * must be replaced by adding it to this array.
	 * \else
	 * 当m_physicsNodes处于locked状态时，添加节点时操作该数组
	 * \endif
	 */
	wyArray* m_physicsNodesPendingAdd;

	/**
	 * \if English
	 * In situation that m_physicsNodes is being operated(or locked), to remove a node from m_physicsNodes
	 * must be replaced by adding it to this array.
	 * \else
	 * 当m_physicsNodes处于locked状态时，删除节点时操作该数组
	 * \endif
	 */
	wyArray* m_physicsNodesPendingRemove;

private:
	/**
	 * \if English
	 * constructor
	 * \else
	 * 构造函数
	 * \endif
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
	 * \if English
	 * Single instance getter
	 *
	 * @return \link wyActionManager wyActionManager instance \endlink
	 * \else
	 * 获得\link wyActionManager wyActionManager对象指针 \endlink
	 *
	 * @return \link wyActionManager wyActionManager对象指针 \endlink
	 * \endif
	 */
	static wyActionManager* getInstance();

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyActionManager();

	/**
	 * \if English
	 * To add an action, thread safe.
	 * If the action has ever added before, then nothing will happen.
	 *
	 * @param action \link wyAction wyAction\endlink
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 * \else
	 * 启动动作并缓存动作到队列中，此方法中判断了是否已经添加过该动作，方法是线程安全的
	 *
	 * @param action 动作的\link wyAction wyAction对象指针\endlink
	 * @param target 执行动作的节点\link wyNode wyNode对象指针\endlink
	 * \endif
	 */
	void addActionLocked(wyAction* action, wyNode* target);

	/**
	 * \if English
	 * To delete an action, thread safe.
	 *
	 * @param action \link wyAction wyAction\endlink
	 * \else
	 * 删除队列中的动作，方法是线程安全的
	 *
	 * @param action 动作的\link wyAction wyAction对象指针\endlink
	 * \endif
	 */
	void removeActionLocked(wyAction* action);

	/**
	 * \if English
	 * To delete one of one node's actions according to the tag, thread safe.
	 *
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 * @param tag action's tag
	 * \else
	 * 根据执行动作节点和动作tag,删除队列中的动作,方法是线程安全的
	 *
	 * @param target 执行动作的节点\link wyNode wyNode对象指针\endlink
	 * @param tag 动作的tag
	 * \endif
	 */
	void removeActionByTagLocked(wyNode* target, int tag);

	/**
	 * \if English
	 * To delete all actions of one node, thread safe.
	 *
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 * @param includeChildren indicates whether actions of child nodes are also deleted.
	 * \else
	 * 删除节点中所有动作,方法是线程安全的
	 *
	 * @param target 执行动作的节点\link wyNode wyNode对象指针\endlink
	 * @param includeChildren 是否包含节点下的子节点
	 * \endif
	 */
	void removeActionsLocked(wyNode* target, bool includeChildren);

	/**
	 * \if English
	 * To delete all actions of all nodes, thread safe.
	 * \else
	 * 删除所有动作
	 * \endif
	 */
	void removeAllActionsLocked();

	/**
	 * \if English
	 * To pause one action of a node according to tag, thread safe.
	 *
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 * @param tag tag of the action
	 * \else
	 * 暂停一个动作
	 *
	 * @param target 执行动作的节点\link wyNode wyNode对象指针\endlink
	 * @param tag 动作的tag
	 * \endif
	 */
	void pauseActionLocked(wyNode* target, int tag);

	/**
	 * \if English
	 * To resume a action which was paused before, thread safe
	 *
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 * @param tag tag of the action
	 * \else
	 * 恢复一个动作
	 *
	 * @param target 执行动作的节点\link wyNode wyNode对象指针\endlink
	 * @param tag 动作的tag
	 * \endif
	 */
	void resumeActionLocked(wyNode* target, int tag);

	/**
	 * \if English
	 *
	 * To resume all actions of a node.
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 * @param includeChildren indicates whether actions of child nodes are also resumed
	 * \else
	 * 恢复执行节点中所有动作
	 *
	 * @param target 执行动作的节点\link wyNode wyNode对象指针\endlink
	 * @param includeChildren 是否包含节点下的子节点
	 * \endif
	 */
	void resumeActions(wyNode* target, bool includeChildren);

	/**
	 * \if English
	 * To pause all actions of a node.
	 *
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 * @param includeChildren indicates whether actions of child nodes are also paused
	 * \else
	 * 暂定执行节点中所有动作
	 *
	 * @param target 执行动作的节点\link wyNode wyNode对象指针\endlink
	 * @param includeChildren 是否包含节点下的子节点
	 * \endif
	 */
	void pauseActions(wyNode* target, bool includeChildren);

	/**
	 * \if English
	 * To get the count of running actions of a node
	 *
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 * @return count of running actions
	 * \else
	 * 获得节点中正在实行的动作数量
	 *
	 * @param target 执行动作的节点\link wyNode wyNode对象指针\endlink
	 * @return 节点中正在实行的动作数量
	 * \endif
	 */
	int getRunningActionCount(wyNode* target);

	/**
	 * \if English
	 * To get one action of a node according to the tag.
	 *
	 * @param target the node which action is running on. \link wyNode wyNode\endlink
	 * @param tag  tag of the action
	 * @return \link wyAction wyAction\endlink
	 * \else
	 * 根据执行动作节点和动作tag,返回动作\link wyAction wyAction对象指针\endlink
	 *
	 * @param target 执行动作的节点\link wyNode wyNode对象指针\endlink
	 * @param tag 动作的tag
	 * @return 动作\link wyAction wyAction对象指针\endlink
	 * \endif
	 */
	wyAction* getAction(wyNode* target, int tag);

	/**
	 * \if English
	 * To update actions
	 *
	 * @param delta time, in seconds
	 * \else
	 * 执行队列中的动作
	 *
	 * @param delta 距离上次动作执行的时间间隔
	 * \endif
	 */
	void tick(float delta);

	/**
	 * \if English
	 * To add a node to the physics array, developers shouldn't call this function.
	 *
	 * @param node \link wyNode wyNode\endlink
	 * \else
	 * 把有物理属性的节点添加到队列中进行统一维护, 这个方法不需要直接开发者直接调用
	 *
	 * @param node \link wyNode wyNode\endlink
	 * \endif
	 */
	void addPhysicsNode(wyNode* node);

	/**
	 * \if English
	 * To remove a node from the physics array, developers shouldn't call this function.
	 *
	 * @param node  \link wyNode wyNode\endlink
	 * \else
	 * 删除一个失去了物理属性的节点, 这个方法不需要直接开发者直接调用
	 *
	 * @param node \link wyNode wyNode\endlink
	 * \endif
	 */
	void removePhysicsNode(wyNode* node);
};

#endif // __wyActionManager_h__
