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
#ifndef __wyAction_h__
#define __wyAction_h__

#include <stdbool.h>
#include "wyObject.h"
#if ANDROID
	#include <jni.h>
#endif

#define WY_ACTION_INVALID_TAG -1

class wyActionManager;
class wyAction;

/**
 * @struct wyActionCallback
 *
 * \if English
 * \link wyAction wyAction\endlink callback definition.
 * \else
 * \link wyAction wyAction\endlink 的回调函数结构定义. 通过设置回调, 可以在
 * \link wyAction wyAction\endlink 的执行过程中通过回调了解动作的执行进度, 以及
 * 何时开始, 何时停止.
 * \endif
 */
typedef struct wyActionCallback {
	/**
	 * \if English
	 * Invoked when action is started
	 *
	 * @param action \link wyAction wyAction \endlink pointer
	 * @param data user data pointer
	 * \else
	 * 当动作开始执行时被调用
	 *
	 * @param action \link wyAction wyAction \endlink对象指针
	 * @param data 附加数据指针
	 * \endif
	 */
	void (*onStart)(wyAction* action, void* data);

	/**
	 * \if English
	 * Invoked when action is stopped, should call \c isDone to
	 * check whether action is terminated normally
	 *
	 * @param action \link wyAction wyAction \endlink pointer
	 * @param data user data pointer
	 * \else
	 * 当动作结束时被调用, 可以通过isDone来判断是否是正常结束
	 *
	 * @param action \link wyAction wyAction \endlink对象指针
	 * @param data 附加数据指针
	 * \endif
	 */
	void (*onStop)(wyAction* action, void* data);

	/**
	 * \if English
	 * Invoked every time when \c update method is called
	 *
	 * @param action \link wyAction wyAction \endlink pointer
	 * @param t current time, from 0 to 1. If action's duration is 2 seconds, then 0.5 means 1 second
	 * @param data user data pointer
	 * \else
	 * 在动作执行了update时被调用
	 *
	 * @param action \link wyAction wyAction \endlink对象指针
	 * @param t 当前时间点，从0到1
	 * @param data 附加数据指针
	 * \endif
	 */
	void (*onUpdate)(wyAction* action, float t, void* data);
} wyActionCallback;

class wyNode;

/**
 * @class wyAction
 *
 * \if English
 * Base class for other actions
 * \else
 * 动作的封装, 是所有动作的基类
 * \endif
 */
class WIENGINE_API wyAction : public wyObject {
	friend class wyActionManager;

protected:
	/**
	 * \if English
	 * true indicating action is running
	 * \else
	 * true表示动作正在运行
	 * \endif
	 */
	bool m_running;

	/**
	 * \if English
	 * true indicating action is paused
	 * \else
	 * true表示动作已被暂停
	 * \endif
	 */
	bool m_paused;

	/**
	 * \if English
	 * the \link wyNode wyNode\endlink object on which this action is running
	 * \else
	 * 执行动作\link wyNode wyNode \endlink对象指针
	 * \endif
	 */
	wyNode* m_target;

	/**
	 * 当前动作的父动作, 父动作一般都是一个组合类动作. 所谓组合类动作就是指自身没有逻辑, 而必须
	 * 包含另外一个动作的动作, 比如\link wyRepeat wyRepeat\endlink等.
	 */
	wyAction* m_parent;

	/**
	 * \if English
	 * tag of action, can be used to query an action from node
	 * \else
	 * 动作的标签
	 * \endif
	 */
	int m_tag;

	/**
	 * \if English
	 * action callback
	 * \else
	 * 动作执行的回调函数指针
	 * \endif
	 */
	wyActionCallback m_callback;

	/**
	 * \if English
	 * extra data pointer of action callback
	 * \else
	 * callback的附加数据指针
	 * \endif
	 */
	void* m_data;

#if ANDROID
	/**
	 * \if English
	 * action callback, but it is defined in java layer so it is a java object
	 * \else
	 * 动作执行的java回调函数对象,调用java层的setCallback设置
	 * \endif
	 */
	jobject j_callback;
#endif

protected:
	wyAction();

	/**
	 * \if English
	 * Invoke start callback
	 * \else
	 * 当动作开始执行时的回调函数
	 * \endif
	 */
	virtual void invokeOnStart();

	/**
	 * \if English
	 * Invoke stop callback
	 * \else
	 * 当动作结束执行时的回调函数
	 * \endif
	 */
	virtual void invokeOnStop();

	/**
	 * \if English
	 * Invoke update callback
	 *
	 * @param t current time, from 0 to 1. If action's duration is 2 seconds, then 0.5 means 1 second
	 * \else
	 * 当动作执行过程中时的回调函数
	 *
	 * @param t 动作执行的相对时间，取值从0到1
	 * \endif
	 */
	virtual void invokeOnUpdate(float t);

public:
	virtual ~wyAction();

	/**
	 * \if English
	 * Make a copy of current action object, returned object is already
	 * auto released.
	 *
	 * @return \link wyAction wyAction\endlink pointer
	 * \else
	 * 获得当前动作的复制, 返回的动作已经调用过了autoRelease()
	 *
	 * @return \link wyAction wyAction\endlink对象指针
	 * \endif
	 */
	virtual wyAction* copy();

	/**
	 * \if English
	 * Make a reverse copy of this action object, returned object is already
	 * auto released.
	 *
	 * @return \link wyAction wyAction\endlink pointer
	 * \else
	 * 获得动作反转后的指针, 返回的动作已经调用过了autoRelease()
	 *
	 * @return \link wyAction wyAction\endlink对象指针
	 * \endif
	 */
	virtual wyAction* reverse();

	/**
	 * \if English
	 * Start action. If callback is set, notify callback
	 *
	 * @param target the \link wyNode wyNode \endlink object on which this action is running
	 * \else
	 * 开始执行动作，如果动作有回调，会触发onStart回调函数
	 *
	 * @param target \link wyNode wyNode\endlink对象指针
	 * \endif
	 */
	virtual void start(wyNode* target);

	/**
	 * \if English
	 * Stop action. If callback is set, notify callback
	 * \else
	 * 停止动作，如果动作有回调，会触发onStop回调函数
	 * \endif
	 */
	virtual void stop();

	/**
	 * \if English
	 * Update action with a single step
	 *
	 * @param t time from last step
	 * \else
	 * 步进动作
	 *
	 * @param t 上一次调用step到现在过去的时间
	 * \endif
	 */
	virtual void step(float t);

	/**
	 * \if English
	 * Update action. If callback is set, notify callback.
	 *
	 * @param t current time, from 0 to 1. If action's duration is 2 seconds, then 0.5 means 1 second
	 * \else
	 * 更新动作执行的百分比，如果动作有回调，会触发onUpdate回调函数
	 *
	 * @param t 动作执行的相对时间，取值从0到1
	 * \endif
	 */
	virtual void update(float t);

	/**
	 * \if English
	 * Check action state
	 *
	 * @return true indicating action is done
	 * \else
	 * 判断动作是否结束
	 *
	 * @return 动作是否结束
	 * \endif
	 */
	virtual bool isDone();

	/**
	 * \if English
	 * Set callback
	 *
	 * @param callback \link wyActionCallback wyActionCallback \endlink structure. NULL means clear current callback.
	 * @param data User data pointer, who allocate it should be responsible for release it
	 * \else
	 * 设置动作执行的回调函数native引用
	 *
	 * @param callback 回调函数\link wyActionCallback wyActionCallback \endlink结构, 如果
	 * 		为NULL, 则表示清除现有的callback
	 * @param data 附加数据指针，wyAction不会负责释放该指针
	 * \endif
	 */
	void setCallback(wyActionCallback* callback, void* data);

#if ANDROID
	
	/**
	 * \if English
	 * Set java layer callback
	 *
	 * @param jcallback java side callback object, NULL means clear current callback
	 * \else
	 * 设置动作执行的java回调函数引用
	 *
	 * @param jcallback java回调函数对象, 如果为NULL，表示清除现有的callback
	 * \endif
	 */
	void setCallback(jobject jcallback);
	
	/**
	 * \if English
	 * Get java side callback object
	 *
	 * @return java side callback object
	 * \else
	 * 获得动作java回调函数对象
	 *
	 * @return java回调函数对象
	 * \endif
	 */
	jobject getCallback();
	
#endif // #if ANDROID

	/**
	 * \if English
	 * Set tag for action. A tag can be used as an unique id of action and later
	 * you can retrieve it by wyNode::getAction method
	 *
	 * @param tag integer for action
	 * \else
	 * 设置动作标签
	 *
	 * @param tag 动作标签
	 * \endif
	 */
	void setTag(int tag);

	/**
	 * \if English
	 * Get action tag
	 *
	 * @return action tag
	 * \else
	 * 获得动作标签
	 *
	 * @return 动作标签
	 * \endif
	 */
	int getTag();

	/**
	 * \if English
	 * Get action target.
	 *
	 * @return \link wyNode wyNode\endlink object on which this action is running
	 * \else
	 * 获得执行动作节点\link wyNode wyNode\endlink对象指针
	 *
	 * @return 执行动作的\link wyNode wyNode\endlink对象指针
	 * \endif
	 */
	wyNode* getTarget();
    
    /**
     * \if English
     * is action running or not
     *
     * @return true means it is running
     * \else
     * 检查动作是否正在执行
     *
     * @return true表示正在执行
     * \endif
     */
    bool isRunning() { return m_running; }

	/**
	 * \if English
	 * Get parent action, if an action is packed in composite action, such as
	 * \link wyRepeat wyRepeat\endlink, then its parent action will be set as
	 * \link wyRepeat wyRepeat\endlink. Usually developer doesn't need care about
	 * this.
	 *
	 * @return parent action, or NULL if not set
	 * \else
	 * 得到父动作
	 *
	 * @return 父动作, 如果没有则返回NULL
	 * \endif
	 */
	wyAction* getParent() { return m_parent; }

	/**
	 * \if English
	 * Set parent action, it doesn't increase retain count of parent action. This method
	 * is usually called internal and developer should not care about this.
	 *
	 * @param parent parent action
	 * \else
	 * 设置父动作, 该方法不会增加父动作的引用计数
	 *
	 * @param parent 父动作
	 * \endif
	 */
	void setParent(wyAction* parent) { m_parent = parent; }

	/**
	 * \if English
	 * is action paused? There is not method called setPaused because you can't pause action
	 * directly. \link wyNode wyNode\endlink has pauseAction method and you can use that
	 *
	 * @return true means action is paused
	 * \else
	 * 动作是否已停止. 没有setPaused方法可以让你直接暂停动作, 比如通过\link wyNode wyNode\endlink的方法
	 * pauseAction暂停动作.
	 *
	 * @return true表示动作已经暂停
	 * \endif
	 */
	bool isPaused() { return m_paused; }
};

#endif // __wyAction_h__
