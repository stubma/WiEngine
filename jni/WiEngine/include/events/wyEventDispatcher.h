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
#ifndef __wyEventDispatcher_h__
#define __wyEventDispatcher_h__

#include <stdbool.h>
#include "wyArray.h"
#include "wyNode.h"
#include <pthread.h>
#include "wyEvents.h"
#if ANDROID
	#include <jni.h>
#endif

class wyGLTexture2D;
class wyAutoReleasePool;

/**
 * @class wyEventDispatcher
 *
 * 事件处理的封装类，包括加速，键盘，触摸，双击，手势事件设置和回调
 */
class WIENGINE_API wyEventDispatcher : public wyObject {
	friend class wyGLTexture2D;
	friend class wyAutoReleasePool;

private:
	/// handler of event
	struct wyPriorityHandler {
		// priority
		int priority;
	
		// node
		wyNode* node;
	};

protected:
	/// 标识是否启用事件机制
	bool m_dispatchEvents;

	/// pending accelerator handlers
	wyArray* m_pendingAccelHandlers;

	/// pending touch handlers
	wyArray* m_pendingTouchHandlers;

	/// pending key handlers
	wyArray* m_pendingKeyHandlers;

	/// pending double tap handlers
	wyArray* m_pendingDoubleTapHandlers;

	/// pending gesture handlers
	wyArray* m_pendingGestureHandlers;

	/// 加速事件\link wyArray wyArray对象\endlink
	wyArray* m_accelHandlers;

	/// 键盘事件\link wyArray wyArray对象\endlink
	wyArray* m_keyHandlers;

	/// 屏幕触摸事件\link wyArray wyArray对象\endlink
	wyArray* m_touchHandlers;

	/// 屏幕双击事件\link wyArray wyArray对象\endlink
	wyArray* m_doubleTapHandlers;

	/// 手势事件\link wyArray wyArray对象\endlink
	wyArray* m_gestureHandlers;

	/// 事件队列\link wyArray wyArray对象\endlink，事件放入队列等待处理
	wyArray* m_eventQueue;

	/// 事件池\link wyArray wyArray对象\endlink，用来保存执行过的事件，为下次使用避免分配内存问题
	wyArray* m_eventPool;

	/// 需要加入到事件队列里的事件
	wyArray* m_pendingAddList;

	/// 需要执行的\link wyRunnable wyRunnable\endlink 对象
	wyArray* m_runnables;

protected:
	/**
	 * 构造函数
	 */
	wyEventDispatcher();

	/**
	 * \if English
	 * Check if any accelerometer handler installed, and enable accelerometer event
	 * dispatching based on the result
	 * \else
	 * 检查当前是否有加速器事件监听器, 根据结果来打开或关闭加速器事件派发
	 * \endif
	 */
	virtual void checkAccelHandlers() {}

	/**
	 * \if English
	 * Check if any double tap handler installed, and enable double tap event dispatching
	 * based on the result
	 * \else
	 * 检查当前是否有双击事件监听器, 根据结果来打开或关闭双击事件派发
	 * \endif
	 */
	virtual void checkDoubleTapHandlers() {}

	/**
	 * \if English
	 * Check if any gesture handler installed, and enable gesture event dispatching
	 * based on the result
	 * \else
	 * 检查当前是否有手势事件监听器, 根据结果来打开或关闭手势事件派发
	 * \endif
	 */
	virtual void checkGestureHandlers() {}

	/**
	 * \if English
	 * Convert platform key event to general wyEvent structure
	 * \else
	 * 把平台按键事件对象转换为通用wyEvent结构
	 * \endif
	 */
	virtual wyEvent* buildKeyEvent(wyEventType type, wyPlatformKeyEvent pe) = 0;

	/**
	 * \if English
	 * Queue motion event
	 * \else
	 * 将平台触摸事件放入队列
	 * \endif
	 */
	virtual void queueMotionEvent(wyEventType type, wyPlatformMotionEvent pe) = 0;

	/**
	 * \if English
	 * Queue multi touch motion event
	 * \else
	 * 将平台多点触摸事件放入队列
	 * \endif
	 */
	virtual void queueMotionEvent(wyEventType type, wyPlatformMotionEvent pe1, wyPlatformMotionEvent pe2, float vx, float vy) = 0;

	/**
	 * \if English
	 * Process event which is not common for all platform
	 * \else
	 * 处理并非所有平台都支持的事件
	 * \endif
	 */
	virtual void processUncommonEvent(wyEvent* e) {}

	/*
	 * dispatch event
	 */

	virtual void dispatchAccelerometerChanged(wyNode* node, float accelX, float accelY, float accelZ);
	virtual bool dispatchKeyDown(wyNode* node, wyPlatformKeyEvent event, wyKeyEvent& ke);
	virtual bool dispatchKeyUp(wyNode* node, wyPlatformKeyEvent event, wyKeyEvent& ke);
	virtual bool dispatchKeyMultiple(wyNode* node, wyPlatformKeyEvent event, wyKeyEvent& ke);
	virtual bool dispatchTouchesBegan(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchTouchesMoved(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchTouchesEnded(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchTouchesCancelled(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchTouchesPointerBegan(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchTouchesPointerEnded(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchOnDoubleTap(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchOnDoubleTapEvent(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchOnSingleTapConfirmed(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchOnDown(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchOnFling(wyNode* node, wyPlatformMotionEvent e1, wyPlatformMotionEvent e2, wyMotionEvent& me1, wyMotionEvent& me2, float velocityX, float velocityY);
	virtual void dispatchOnLongPress(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchOnScroll(wyNode* node, wyPlatformMotionEvent e1, wyPlatformMotionEvent e2, wyMotionEvent& me1, wyMotionEvent& me2, float distanceX, float distanceY);
	virtual void dispatchOnShowPress(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);
	virtual bool dispatchOnSingleTapUp(wyNode* node, wyPlatformMotionEvent event, wyMotionEvent& me);

	/**
	 * \if English
	 * Recycle an event object, different platform may have different implementation
	 * \else
	 * 回收一个事件封装对象, 不同的平台需要不同的实现
	 * \endif
	 */
	static void recycleEvent(wyEvent* e);

	static bool releaseHandler(wyArray* arr, void* ptr, int index, void* data);
	static bool findHandler(void* elementPtr, void* ptr, void* data);
	static bool processEvent(wyArray* arr, void* ptr, int index, void* data);
	static bool releaseEvent(wyArray* arr, void* ptr, int index, void* data);
	static bool releaseRunnable(wyArray* arr, void* ptr, int index, void* data);
	
	/**
	 * 获得wyEvent指针，从事件池中，如果事件池没有中创建一个新的返回
	 *
	 * @return wyEvent指针
	 */
	wyEvent* popEvent();

	/**
	 * wyEvent指针保存到事件池
	 *
	 * @param e wyEvent指针
	 */
	void poolEvent(wyEvent* e);

	/**
	 * 保存载入贴图事件到事件队列中，此方法为线程安全的
	 *
	 * @param type 事件类型
	 * @param tex \link wyGLTexture2D wyGLTexture2D\endlink 需要载入的贴图
	 * @param cond pthread的条件变量
	 * @see ET_LOAD_TEXTURE
	 * @see ET_DELETE_TEXTURE
	 */
	void queueEventLocked(wyEventType type, wyGLTexture2D* tex, pthread_cond_t* cond);

	/**
	 * Queue a custom event for a object
	 */
	void queueEventLocked(wyEventType type, wyObject* obj);

	/// move pending handler to real queue
	void addAccelHandler(wyPriorityHandler* h);

	/// move pending handler to real queue
	void addKeyHandler(wyPriorityHandler* h);

	/// move pending handler to real queue
	void addTouchHandler(wyPriorityHandler* h);

	/// move pending handler to real queue
	void addDoubleTapHandler(wyPriorityHandler* h);

	/// move pending handler to real queue
	void addGestureHandler(wyPriorityHandler* h);

public:
	/**
	 * 获得\link wyEventDispatcher wyEventDispatcher对象 \endlink指针
	 *
	 * @return \link wyEventDispatcher wyEventDispatcher对象 \endlink指针
	 */
	static wyEventDispatcher* getInstance();

	/**
	 * \if English
	 * Get singleton event dispatcher. However, it doesn't create the singleton if it is not created yet
	 *
	 * @return Singleton instance, or NULL if that instance is not available yet
	 * \else
	 * 得到事件派发器的单一实例, 但是如果该单一实例尚未被创建, 则会返回NULL
	 *
	 * @return 单一实例, 如果没有, 返回NULL
	 * \endif
	 */
	static wyEventDispatcher* getInstanceNoCreate();

	/**
	 * 析构函数
	 */
	virtual ~wyEventDispatcher();

	/**
	 * 执行队列中的事件并清空队列，此方法是线程安全的
	 */
	void processEventsLocked();

	/**
	 * 判断是否含有加速事件的Handler
	 *
	 * @return true 存在加速事件的Handler
	 */
	bool hasAccelHandlers() { return !wyArrayIsEmpty(m_accelHandlers) || !wyArrayIsEmpty(m_pendingAccelHandlers); }

	/**
	 * 设置是否发送事件标记
	 *
	 * @param flag 是否发送事件标记，true为发送
	 */
	void setDispatchEvent(bool flag) { m_dispatchEvents = flag; }

	/**
	 * 获得当前是否发送事件标记
	 *
	 * @return 当前是否发送事件标记，true为发送
	 */
	bool getDispatchEvent() { return m_dispatchEvents; }

	/**
	 * 执行Key Down事件，并根据键盘事件Handler，派发到具体监听的节点
	 *
	 * @param event 平台相关的事件对象类型
	 */
	bool wyKeyDown(wyPlatformKeyEvent event);
	
	/**
	 * 执行Key Up事件，并根据键盘事件Handler，派发到具体监听的节点
	 *
	 * @param event 平台相关的事件对象类型
	 */
	bool wyKeyUp(wyPlatformKeyEvent event);
	
	/**
	 * 执行Key Multiple事件，并根据键盘事件Handler，派发到具体监听的节点
	 *
	 * @param event 平台相关的事件对象类型
	 */
	bool wyKeyMultiple(wyPlatformKeyEvent event);

	/**
	 * 执行Touches Began事件，并根据触摸事件Handler，派发到具体监听的节点
	 *
	 * @param event 平台相关的事件对象类型
	 */
	bool wyTouchesBegan(wyPlatformMotionEvent event);
	
	/**
	 * 执行Touches Moved事件，并根据触摸事件Handler，派发到具体监听的节点
	 *
	 * @param event 平台相关的事件对象类型
	 */
	bool wyTouchesMoved(wyPlatformMotionEvent event);
	
	/**
	 * 执行Touches Ended事件，并根据触摸事件Handler，派发到具体监听的节点
	 *
	 * @param event 平台相关的事件对象类型
	 */
	bool wyTouchesEnded(wyPlatformMotionEvent event);
	
	/**
	 * 执行Touches Cancelled事件，并根据触摸事件Handler，派发到具体监听的节点
	 *
	 * @param event 平台相关的事件对象类型
	 */
	bool wyTouchesCancelled(wyPlatformMotionEvent event);
	
	/**
	 * 执行Touches Pointer Began事件，并根据触摸事件Handler，派发到具体监听的节点
	 *
	 * @param event 平台相关的事件对象类型
	 */
	bool wyTouchesPointerBegan(wyPlatformMotionEvent event);
	
	/**
	 * 执行Touches Pointer Ended事件，并根据触摸事件Handler，派发到具体监听的节点
	 *
	 * @param event 平台相关的事件对象类型
	 */
	bool wyTouchesPointerEnded(wyPlatformMotionEvent event);
	
	/**
	 * 执行Double Tap事件，并根据双击事件Handler，派发到具体监听的节点
	 *
	 * @param event 平台相关的事件对象类型
	 */
	bool wyOnDoubleTap(wyPlatformMotionEvent event);
	
	/**
	 * 执行Double Tap Event事件，并根据双击事件Handler，派发到具体监听的节点
	 *
	 * @param event 平台相关的事件对象类型
	 */
	bool wyOnDoubleTapEvent(wyPlatformMotionEvent event);
	
	/**
	 * 执行Single Tap Confirmed事件，并根据双击事件Handler，派发到具体监听的节点
	 *
	 * @param event 平台相关的事件对象类型
	 */
	bool wyOnSingleTapConfirmed(wyPlatformMotionEvent event);
	
	/**
	 * 执行Down事件，并根据手势事件Handler，派发到具体监听的节点
	 *
	 * @param event 平台相关的事件对象类型
	 */
	bool wyOnDown(wyPlatformMotionEvent event);
	
	/**
	 * 执行Fling事件，并根据手势事件Handler，派发到具体监听的节点
	 *
	 * @param e1 平台相关的事件对象类型
	 * @param e2 平台相关的事件对象类型
	 * @param velocityX Fling事件x轴速度
	 * @param velocityY Fling事件y轴速度
	 */
	bool wyOnFling(wyPlatformMotionEvent e1, wyPlatformMotionEvent e2, float velocityX, float velocityY);
	
	/**
	 * 执行Long Press事件，并根据手势事件Handler，派发到具体监听的节点
	 *
	 * @param event 平台相关的事件对象类型
	 */
	void wyOnLongPress(wyPlatformMotionEvent event);
	
	/**
	 * 执行Scroll事件，并根据手势事件Handler，派发到具体监听的节点
	 *
	 * @param e1 平台相关的事件对象类型
	 * @param e2 平台相关的事件对象类型
	 * @param distanceX Scroll事件x轴距离
	 * @param distanceY Scroll事件y轴距离
	 */
	bool wyOnScroll(wyPlatformMotionEvent e1, wyPlatformMotionEvent e2, float distanceX, float distanceY);
	
	/**
	 * 执行Show Press事件，并根据手势事件Handler，派发到具体监听的节点
	 *
	 * @param event 平台相关的事件对象类型
	 */
	void wyOnShowPress(wyPlatformMotionEvent event);
	
	/**
	 * 执行Single Tap Up事件，并根据手势事件Handler，派发到具体监听的节点
	 *
	 * @param event 平台相关的事件对象类型
	 */
	bool wyOnSingleTapUp(wyPlatformMotionEvent event);

	/**
	 * 保存按键事件到队列中，此方法为线程安全的
	 *
	 * @param type wyEventType，事件类型，一般为键盘，触摸，双击事件
	 * @param pe 平台相关的事件对象
	 */
	void queueKeyEventLocked(wyEventType type, wyPlatformKeyEvent pe);

	/**
	 * 保存事件到事件队列中，此方法为线程安全的
	 *
	 * @param type wyEventType，事件类型，一般为键盘，触摸，双击事件
	 * @param pe 平台相关的事件对象
	 */
	void queueEventLocked(wyEventType type, wyPlatformMotionEvent pe);

	/**
	 * 保存事件到事件队列中，此方法为线程安全的
	 *
	 * @param type wyEventType，事件类型，一般为手势事件
	 * @param pe1 平台相关的事件对象
	 * @param pe2 平台相关的事件对象
	 * @param vx 手势事件中的x轴参数
	 * @param vy 手势事件中的y轴参数
	 */
	void queueEventLocked(wyEventType type, wyPlatformMotionEvent pe1, wyPlatformMotionEvent pe2, float vx, float vy);

	/**
	 * 保存加速事件到事件队列中，此方法为线程安全的
	 *
	 * @param accelX x轴的加速值得
	 * @param accelY y轴的加速值得
	 * @param accelZ z轴的加速值得
	 */
	void queueEventLocked(float accelX, float accelY, float accelZ);

	/**
	 * 把一个\link wyRunnable wyRunnable\endlink 对象放入队列中, 这通常用来调度执行一些
	 * 需要在OpenGL线程中执行的操作.
	 *
	 * @param runnable \link wyRunnable wyRunnable\endlink
	 */
	void queueRunnableLocked(wyRunnable* runnable);

	/**
	 * 添加键盘事件Handler，此方法为线程安全的
	 *
	 * @param node 监听事件的\link wyNode wyNode对象 \endlink指针
	 * @param priority 事件优先级
	 */
	void addKeyHandlerLocked(wyNode* node, int priority);

	/**
	 * 添加加速事件Handler，此方法为线程安全的
	 *
	 * @param node 监听事件的\link wyNode wyNode对象 \endlink指针
	 * @param priority 事件优先级
	 */
	void addAccelHandlerLocked(wyNode* node, int priority);

	/**
	 * 添加触摸事件Handler，此方法为线程安全的
	 *
	 * @param node 监听事件的\link wyNode wyNode对象 \endlink指针
	 * @param priority 事件优先级
	 */
	void addTouchHandlerLocked(wyNode* node, int priority);

	/**
	 * 添加双击事件Handler，此方法为线程安全的
	 *
	 * @param node 监听事件的\link wyNode wyNode对象 \endlink指针
	 * @param priority 事件优先级
	 */
	void addDoubleTapHandlerLocked(wyNode* node, int priority);

	/**
	 * 添加手势事件Handler，此方法为线程安全的
	 *
	 * @param node 监听事件的\link wyNode wyNode对象 \endlink指针
	 * @param priority 事件优先级
	 */
	void addGestureHandlerLocked(wyNode* node, int priority);

	/**
	 * 删除键盘事件Handler，此方法为线程安全的
	 *
	 * @param node 监听事件的\link wyNode wyNode对象 \endlink指针
	 */
	void removeKeyHandlerLocked(wyNode* node);
	
	/**
	 * 删除加速事件Handler，此方法为线程安全的
	 *
	 * @param node 监听事件的\link wyNode wyNode对象 \endlink指针
	 */
	void removeAccelHandlerLocked(wyNode* node);

	/**
	 * 删除触摸事件Handler，此方法为线程安全的
	 *
	 * @param node 监听事件的\link wyNode wyNode对象 \endlink指针
	 */
	void removeTouchHandlerLocked(wyNode* node);

	/**
	 * 删除双击事件Handler，此方法为线程安全的
	 *
	 * @param node 监听事件的\link wyNode wyNode对象 \endlink指针
	 */
	void removeDoubleTapHandlerLocked(wyNode* node);

	/**
	 * 删除手势事件Handler，此方法为线程安全的
	 *
	 * @param node 监听事件的\link wyNode wyNode对象 \endlink指针
	 */
	void removeGestureHandlerLocked(wyNode* node);

	/**
	 * 删除所有事件Handler，此方法为线程安全的
	 */
	void removeAllHandlersLocked();

	/**
	 * 设置键盘事件Handler优先级，此方法为线程安全的
	 *
	 * @param node 监听事件的\link wyNode wyNode对象 \endlink指针
	 * @param priority 事件优先级
	 */
	void setKeyHandlerPriorityLocked(wyNode* node, int priority);

	/**
	 * 设置加速事件Handler优先级，此方法为线程安全的
	 *
	 * @param node 监听事件的\link wyNode wyNode对象 \endlink指针
	 * @param priority 事件优先级
	 */
	void setAccelHandlerPriorityLocked(wyNode* node, int priority);

	/**
	 * 设置触摸事件Handler优先级，此方法为线程安全的
	 *
	 * @param node 监听事件的\link wyNode wyNode对象 \endlink指针
	 * @param priority 事件优先级
	 */
	void setTouchHandlerPriorityLocked(wyNode* node, int priority);

	/**
	 * 设置双击事件Handler优先级，此方法为线程安全的
	 *
	 * @param node 监听事件的\link wyNode wyNode对象 \endlink指针
	 * @param priority 事件优先级
	 */
	void setDoubleTapHandlerPriorityLocked(wyNode* node, int priority);

	/**
	 * 设置手势事件Handler优先级，此方法为线程安全的
	 *
	 * @param node 监听事件的\link wyNode wyNode对象 \endlink指针
	 * @param priority 事件优先级
	 */
	void setGestureHandlerPriorityLocked(wyNode* node, int priority);

	/**
	 * 执行加速事件，并根据加速事件Handler，派发到具体监听的节点.
	 * 这里的加速器值分成x, y, z三个维度, 它们的取值采用iOS的规则. Android和iOS
	 * 平台对加速器事件的参数主要有两个差异:
	 * 1. 它们的符号是完全相反的
	 * 2. iOS以1表示一个重力加速度, 而Android以9.81代表一个重力加速度
	 * 因此在Android平台上得到的值需要除以9.81并翻转符号.
	 *
	 * 之所以使用iOS规则表示加速器事件, 是因为其取值与OpenGL坐标系相符合.
	 *
	 * @param accelX x轴的加速值
	 * @param accelY y轴的加速值
	 * @param accelZ z轴的加速值
	 */
	void wyAccelerometerChanged(float accelX, float accelY, float accelZ);
	
	/**
	 * 请求取消某些节点的touch事件
	 *
	 * @param e cancel的触摸事件结构
	 * @param parent 需要检索的父节点, 这个父节点下的子节点将收到cancel事件
	 */
	void cancelTouch(wyMotionEvent& e, wyNode* parent);

	/**
	 * \if English
	 * Cancel touch event for all nodes exclude specified one
	 *
	 * @param e cancel event
	 * @param excludeNode node who won't receive cancel event
	 * \else
	 * 除了一个指定的节点, 其它所有节点目前在touch事件中的都收到touch取消事件
	 *
	 * @param e cancel的触摸事件结构
	 * @param excludeNode 唯一不接收touch取消事件的节点
	 * \endif
	 */
	void cancelTouchExcept(wyMotionEvent& e, wyNode* excludeNode);
};

#endif // __wyEventDispatcher_h__
