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
#include "wyScheduler.h"
#include <stdlib.h>
#include <pthread.h>
#include "wyLog.h"

wyScheduler* gScheduler;

extern pthread_mutex_t gMutex;

wyTimer::~wyTimer() {
	wyObjectRelease(m_targetSelector);
}

wyTimer::wyTimer(wyTargetSelector* ts) :
		m_targetSelector(ts),
		m_interval(0),
		m_elapsed(0),
		m_frame(0),
		m_elapsedFrame(0),
		m_counter(0),
		m_maxInvocation(0),
		m_paused(false),
		m_pendingRemove(false),
		m_done(false) {
	wyObjectRetain(ts);
}

wyTimer::wyTimer(wyTargetSelector* ts, float interval) :
		m_targetSelector(ts),
		m_interval(interval),
		m_elapsed(0),
		m_frame(0),
		m_elapsedFrame(0),
		m_counter(0),
		m_maxInvocation(0),
		m_paused(false),
		m_pendingRemove(false),
		m_done(false) {
	wyObjectRetain(ts);
}

wyTimer::wyTimer(wyTargetSelector* ts, int frame) :
		m_targetSelector(ts),
		m_interval(0),
		m_elapsed(0),
		m_frame(frame),
		m_elapsedFrame(0),
		m_counter(0),
		m_maxInvocation(0),
		m_paused(false),
		m_pendingRemove(false),
		m_done(false) {
	wyObjectRetain(ts);
}

wyTimer* wyTimer::make(wyTargetSelector* ts) {
	wyTimer* t = WYNEW wyTimer(ts);
	return (wyTimer*)t->autoRelease();
}

wyTimer* wyTimer::make(wyTargetSelector* ts, float interval) {
	wyTimer* t = WYNEW wyTimer(ts, interval);
	return (wyTimer*)t->autoRelease();
}

wyTimer* wyTimer::make(wyTargetSelector* ts, int frame) {
	wyTimer* t = WYNEW wyTimer(ts, frame);
	return (wyTimer*)t->autoRelease();
}

void wyTimer::setOneShot(bool flag) {
	if(flag)
		m_maxInvocation = 1;
	else
		m_maxInvocation = 0;
}

void wyTimer::setInterval(float interval) {
	m_interval = interval;
	if(m_interval > 0.0f)
		m_frame = 0;
}

bool wyTimerEquals(void* ptr1, void* ptr2, void* data) {
	wyTimer* t1 = (wyTimer*)ptr1;
	wyTimer* t2 = (wyTimer*)ptr2;
	wyTargetSelector* ts1 = t1->getTargetSelector();
	wyTargetSelector* ts2 = t2->getTargetSelector();
	return ptr1 == ptr2 || (wyTargetSelectorEquals(ts1, ts2) && t1->getMaxInvocation() == t2->getMaxInvocation() && t1->isDone() == t2->isDone());
}

void wyTimer::fire(float delta) {
	m_elapsed += delta;
	if(m_frame > 0) {
		m_elapsedFrame++;
		if(m_elapsedFrame >= m_frame) {
            m_counter++;
			m_targetSelector->setDelta(m_elapsed);
			m_targetSelector->invoke();
			m_elapsedFrame = 0;
			m_elapsed = 0.0f;
		}
	} else {
		if(m_elapsed >= m_interval) {
            m_counter++;
			m_targetSelector->setDelta(m_elapsed);
			m_targetSelector->invoke();
			m_elapsed = 0.0f;
		}
	}
}

void wyTimer::reset() {
	m_elapsed = 0;
	m_elapsedFrame = 0;
	m_counter = 0;
	m_done = false;
}

wyScheduler::~wyScheduler() {
	wyArrayEach(m_timersToRemove, releaseTimer, NULL);
	wyArrayEach(m_timersToAdd, releaseTimer, NULL);
	wyArrayEach(m_scheduledTimers, releaseTimer, NULL);
	wyArrayDestroy(m_timersToRemove);
	wyArrayDestroy(m_timersToAdd);
	wyArrayDestroy(m_scheduledTimers);
	gScheduler = NULL;
}

wyScheduler::wyScheduler() :
		m_scheduledTimers(wyArrayNew(10)),
		m_timersToAdd(wyArrayNew(10)),
		m_timersToRemove(wyArrayNew(10)),
		m_timeScale(1.f) {
}

wyScheduler* wyScheduler::getInstance() {
	if(gScheduler == NULL) {
		gScheduler = WYNEW wyScheduler();
	}
	return gScheduler;
}

bool wyScheduler::removeTimers(wyArray* arr, void* ptr, int index, void* data) {
	wyTimer* t = (wyTimer*)ptr;
	wyTimer* timer = (wyTimer*)wyArrayDeleteObj(gScheduler->getScheduledTimers(), t, wyTimerEquals, NULL);
	wyObjectRelease(timer);
	return true;
}

bool wyScheduler::addTimers(wyArray* arr, void* ptr, int index, void* data) {
	wyTimer* t = (wyTimer*)ptr;
	wyArrayPush(gScheduler->getScheduledTimers(), t);
	wyObjectRetain(t);
	return true;
}

bool wyScheduler::releaseTimer(wyArray* arr, void* ptr, int index, void* data) {
	wyTimer* t = (wyTimer*)ptr;
	t->m_pendingRemove = false;
	wyObjectRelease(t);
	return true;
}

bool wyScheduler::fire(wyArray* arr, void* ptr, int index, void* data) {
	wyTimer* t = (wyTimer*)ptr;
	if (t->m_done || t->m_paused) {
		return true;
	}
	float delta = *(float*)data;

	/*
	 * 检查pending remove的标识，如果timer已经处于pending remove队列，则不进行调度。
	 * 这是因为有可能出现某个timer在被调度时，其已经被加入到pending remove队列。被
	 * 加入到pending remove队列倒不是一个很严重的事，但是这有可能表明timer的callback对象
	 * 已经被销毁，因此为了安全起见，对于这种timer不调度为好。
	 */
	if(!t->m_pendingRemove)
		t->fire(delta);

	if(t->getMaxInvocation() > 0 && t->getCurrentInvocationCount() >= t->getMaxInvocation()) {
		wyTimer* timer = (wyTimer*)wyArrayDeleteObj(gScheduler->getTimersToAdd(), t, wyTimerEquals, NULL);
		wyArrayPush(gScheduler->getTimersToRemove(), t);
		t->m_pendingRemove = true;
		t->m_done = true;
		wyObjectRetain(t);
		wyObjectRelease(timer);
	}

	return true;
}

void wyScheduler::scheduleLocked(wyTimer* t) {
	pthread_mutex_lock(&gMutex);

	/*
	 * 这里我们首先检查要添加的timer是否处于pending remove中, 如果存在的话, 要继续判断是否指针相同,
	 * 如果完全相同, 则从pending remove中删除, 如果指针不同, 还是要添加到pending add中.
	 *
	 * 这么做的原因是:
	 * 假设有一个节点A, 如果A创建了一个timer叫tA, 那么如果在运行时删掉A, 再创建一个新的A示例, 假设叫
	 * A', 那么它的timer叫tA', 代码一般不会认为tA和tA'相等, 从而tA得到删除, tA'得到调度, 这是正常结果.
	 * 但是, 在某些情况下, 由于A事先已被删除, 内存已被释放, 后面创建的A'的地址偶尔会和A相同, 这样的情况下,
	 * tA'和tA会被认为相同, 于是tA不会被删除, tA'也不会被调度, 但是由于A已经被释放, 导致tA在下次调度时崩溃.
	 *
	 * 为了解决这个问题, 多进行一次指针判断, 仅当指针完全相同时才从pending remove中删除.
	 */
	int index = wyArrayIndexOf(m_timersToRemove, t, wyTimerEquals, NULL);
	if(index >= 0) {
		wyTimer* timer = (wyTimer*)wyArrayGet(m_timersToRemove, index);
		bool exactlySame = t == timer;
		if(exactlySame) {
			wyTimer* timer = (wyTimer*)wyArrayDeleteIndex(m_timersToRemove, index);
			timer->m_pendingRemove = false;
			wyObjectRelease(timer);
		} else {
			wyArrayPush(m_timersToAdd, t);
			wyObjectRetain(t);
		}
	} else if(wyArrayIndexOf(m_scheduledTimers, t, wyTimerEquals, NULL) >= 0 ||
			wyArrayIndexOf(m_timersToAdd, t, wyTimerEquals, NULL) >= 0) {
		LOGW("Scheduler.schedulerTimer: timer already scheduled");
	} else {
		wyArrayPush(m_timersToAdd, t);
		wyObjectRetain(t);
	}

	pthread_mutex_unlock(&gMutex);
}

void wyScheduler::unscheduleLocked(wyTimer* t) {
	pthread_mutex_lock(&gMutex);

	// someone wants to remove it before it was added
	int index = wyArrayIndexOf(m_timersToAdd, t, wyTimerEquals, NULL);
	if(index >= 0) {
		wyTimer* timer = (wyTimer*)wyArrayDeleteIndex(m_timersToAdd, index);
		wyObjectRelease(timer);
	} else if(wyArrayIndexOf(m_scheduledTimers, t, wyTimerEquals, NULL) == -1) {
		if(!t->isOneShot())
			LOGW("Scheduler.unscheduleTimer: timer not scheduled");
	} else {
		wyArrayPush(m_timersToRemove, t);
		t->m_pendingRemove = true;
		wyObjectRetain(t);
	}

	pthread_mutex_unlock(&gMutex);
}

void wyScheduler::tickLocked(float delta) {
	if(delta > 0.0f) {
		if(m_timeScale != 1.0f)
			delta *= m_timeScale;

		pthread_mutex_lock(&gMutex);

		wyArrayEach(m_timersToRemove, removeTimers, NULL);
		wyArrayEach(m_timersToRemove, releaseTimer, NULL);
		wyArrayClear(m_timersToRemove);

		wyArrayEach(m_timersToAdd, addTimers, NULL);
		wyArrayEach(m_timersToAdd, releaseTimer, NULL);
		wyArrayClear(m_timersToAdd);

		wyArrayEach(m_scheduledTimers, fire, &delta);

		pthread_mutex_unlock(&gMutex);
	}
}
