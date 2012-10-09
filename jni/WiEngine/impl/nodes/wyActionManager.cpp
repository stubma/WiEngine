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
#include "wyActionManager.h"
#include <stdlib.h>
#include <pthread.h>
#include "wyScheduler.h"
#include "wyLog.h"

wyActionManager* gActionManager;

extern pthread_mutex_t gMutex;

typedef struct wyActionHash {
	// node target
	wyNode* target;

	// action list
	wyArray* actions;

	// pending remove queue, action will NOT be retained when add into it
	wyArray* pendingRemoveList;

	// pending add queue, action will be retained when add into it
	wyArray* pendingAddList;
	
	// true indicating this hash need to be destroyed
	bool pendingDestroy;

	// locked flag, if has action is in each, it is true
	bool locked;
} wyActionHash;

static bool releaseAction(wyArray* arr, void* ptr, int index, void* data) {
	wyAction* action = (wyAction*)ptr;
	action->stop();
	wyObjectRelease((wyObject*)ptr);
	return true;
}

wyActionHash* wyActionHashNew(wyNode* target) {
	wyActionHash* hash = (wyActionHash*)wyCalloc(1, sizeof(wyActionHash));
	hash->target = target;
	hash->actions = wyArrayNew(2);
	hash->pendingRemoveList = wyArrayNew(2);
	hash->pendingAddList = wyArrayNew(2);
	return hash;
}

void wyActionHashDestroy(wyActionHash* hash) {
	/**
	 * need lock hash in case removeActionsLocked is called when releaseAction is called
	 * releaseAction -> action stop -> call onStop -> if user call stopAllActions in onStop -> removeActionsLocked ->
	 * destroy hash again if not locked -> crash!!!
	 */
	pthread_mutex_lock(&gMutex);
	hash->locked = true;
	pthread_mutex_unlock(&gMutex);

	// release actions
	wyArrayEach(hash->actions, releaseAction, NULL);
	wyArrayDestroy(hash->actions);

	// release pending remove array
	wyArrayDestroy(hash->pendingRemoveList);

	// release pending add array
	wyArrayEach(hash->pendingAddList, releaseAction, NULL);
	wyArrayDestroy(hash->pendingAddList);

	// unlock hash
	pthread_mutex_lock(&gMutex);
	hash->locked = false;
	pthread_mutex_unlock(&gMutex);

	// free hash
	wyFree(hash);
}

int wyActionManager::actionHashEquals(void* ptr, void* elt) {
	return ((wyActionHash*)elt)->target == ptr;
}

void* wyActionManager::buildActionHash(void* ptr, void* data) {
	return ptr;
}

bool wyActionManager::execAction(wyArray* arr, void* ptr, int index, void* data) {
    // The 'actions' may change while inside this loop.
	wyAction* action = (wyAction*)ptr;

	if(!action->m_paused) {
		float delta = *(float*)data;
		action->step(delta);
		
		if (action->isDone()) {
			action->stop();
			wyActionManager::getInstance()->removeActionLocked(action);
		}	
	}

    return true;
}

bool wyActionManager::removeActions(wyArray* arr, void* ptr, int index, void* data) {
	gActionManager->removeActionsLocked((wyNode*)ptr, *(bool*)data);
	return true;
}

bool wyActionManager::sResumeActions(wyArray* arr, void* ptr, int index, void* data) {
	gActionManager->resumeActions((wyNode*)ptr, *(bool*)data);
	return true;
}

bool wyActionManager::sPauseActions(wyArray* arr, void* ptr, int index, void* data) {
	gActionManager->pauseActions((wyNode*)ptr, *(bool*)data);
	return true;
}

bool wyActionManager::sUpdateNodePhysics(wyArray* arr, void* ptr, int index, void* data) {
	wyNode* node = (wyNode*)ptr;
	float delta = *(float*)data;
	float vx = node->getVelocityX();
	float vy = node->getVelocityY();
	float ax = node->getAccelerationX();
	float ay = node->getAccelerationY();
	float px = node->getPositionX();
	float py = node->getPositionY();
	px += vx * delta;
	py += vy * delta;
	vx += ax * delta;
	vy += ay * delta;
	node->setVelocity(vx, vy);
	node->setPosition(px, py);
	return true;
}

bool wyActionManager::sTick(void* elt, void* data) {
	wyActionHash* hash = (wyActionHash*)elt;
    if (hash->target->isRunning()) {
    	// mark the locked flag
    	pthread_mutex_lock(&gMutex);
    	hash->locked = true;
    	pthread_mutex_unlock(&gMutex);

    	// use concurrent each
    	wyArrayEach(hash->actions, execAction, data);

		// if hash need to be destroyed
		if(hash->pendingDestroy) {
			wyActionHashDestroy(hash);
		} else {
			// check pending remove list
			if(hash->pendingRemoveList->num > 0) {
				for(int i = 0; i < hash->pendingRemoveList->num; i++) {
					wyAction* action = (wyAction*)wyArrayGet(hash->pendingRemoveList, i);

					// must check deleted pointer, if NULL, then it may be deleted in preExecAction
					if(wyArrayDeleteObj(hash->actions, action, NULL, NULL) != NULL) {
						if(action->isRunning())
							action->stop();
						wyObjectRelease(action);
					}
				}
				wyArrayClear(hash->pendingRemoveList);
			}

			// check pending add list
			if(hash->pendingAddList->num > 0) {
				for(int i = 0; i < hash->pendingAddList->num; i++) {
					// don't retain, it is retained in addActionLocked
					wyAction* action = (wyAction*)wyArrayGet(hash->pendingAddList, i);
					wyArrayPush(hash->actions, action);
					action->m_paused = false;
					action->start(hash->target);
				}
				wyArrayClear(hash->pendingAddList);
			}

			// unlock
			pthread_mutex_lock(&gMutex);
			hash->locked = false;
			pthread_mutex_unlock(&gMutex);
		}
    }

    return true;
}

bool wyActionManager::deleteEmtpyTarget(void* elt, void* data) {
	wyActionHash* hash = (wyActionHash*)elt;
	bool ret = hash->actions->num > 0;
	if(!ret)
		wyActionHashDestroy(hash);
	return ret;
}

bool wyActionManager::findActionByTag(void* elementPtr, void* ptr2, void* data) {
	wyAction* action = (wyAction*)elementPtr;
	int tag = *(int*)ptr2;
	return action->getTag() == tag;
}

bool wyActionManager::releaseHash(void* elt, void* data) {
	// release actions
	wyActionHashDestroy((wyActionHash*)elt);
	return false;
}

wyActionManager::~wyActionManager() {
	wyHashSetFilter(m_targets, releaseHash, NULL);
	wyHashSetDestroy(m_targets);
	wyArrayDestroy(m_physicsNodes);
    wyArrayDestroy(m_physicsNodesPendingAdd);
    wyArrayDestroy(m_physicsNodesPendingRemove);
	gActionManager = NULL;
}

wyActionManager::wyActionManager() :
		m_targets(wyHashSetNew(100, actionHashEquals, buildActionHash)),
		m_physicsNodes(wyArrayNew(10)),
		m_physicsNodesPendingAdd(wyArrayNew(10)),
		m_physicsNodesPendingRemove(wyArrayNew(10)),
		m_removingAll(false) {
}

wyActionManager* wyActionManager::getInstance() {
	if(gActionManager == NULL) {
		gActionManager = WYNEW wyActionManager();
	}
	return gActionManager;
}

void wyActionManager::addPhysicsNode(wyNode* node) {
	if(wyArrayIndexOf(m_physicsNodes, node, NULL, NULL) != -1)
        return;

    if(m_physicsNodes->locked) {
	    wyArrayPush(m_physicsNodesPendingAdd, node);
    } else {
        wyArrayPush(m_physicsNodes, node);
    }
}

void wyActionManager::removePhysicsNode(wyNode* node) {
    if(m_physicsNodes->locked) {
	    wyArrayPush(m_physicsNodesPendingRemove, node);
    } else {
        wyArrayDeleteObj(m_physicsNodes, node, NULL, NULL);
    }
}

void wyActionManager::addActionLocked(wyAction* action, wyNode* target) {
	if(action == NULL) {
		LOGW("Argument action must be non-null");
		return;
	}
	if(target == NULL) {
		LOGW("Argument target must be non-null");
		return;
	}

    pthread_mutex_lock(&gMutex);

	// check hashset, if not found, create a new entry
	wyActionHash* hash = (wyActionHash*)wyHashSetFind(m_targets, (size_t)target, target);
	if(hash == NULL) {
		hash = wyActionHashNew(target);
		wyHashSetInsert(m_targets, (size_t)target, hash, NULL);
	}

	// if already contained, do nothing
	// if not, add it and start it
	if(wyArrayIndexOf(hash->actions, action, NULL, NULL) >= 0) {
    	LOGW("runAction: action already running");
	} else {
		if(hash->locked) {
			wyArrayPush(hash->pendingAddList, action);
		} else {
			wyArrayPush(hash->actions, action);
			action->m_paused = false;
			action->start(target);
			
			/*
			 * 确保pending add list里面没有这个action, 如果有, 需要释放一次, 因为它在加入到
			 * pending add list中时被retain了一次
			 */
			if(wyArrayDeleteObj(hash->pendingAddList, action, NULL, NULL) != NULL)
				action->autoRelease();
		}
		wyObjectRetain(action);
	}

	pthread_mutex_unlock(&gMutex);
}

void wyActionManager::removeActionLocked(wyAction* action) {
	pthread_mutex_lock(&gMutex);
	wyActionHash* hash = (wyActionHash*)wyHashSetFind(m_targets, (size_t)action->getTarget(), action->getTarget());
	if(hash != NULL) {
		// find it in list
		int index = wyArrayIndexOf(hash->actions, action, NULL, NULL);

		if(index != -1) {
			if(hash->locked) {
				wyArrayPush(hash->pendingRemoveList, action);
			} else {
				/*
				 * 必须要记住需要在pendingRemoveList中删除这个动作, 万一在这个时候这个动作也在
				 * pendingRemoveList里面(在某种情况下是可能出现的), 那么它就会被多release一次, 
				 * 导致出错(因为在加入到pending remove list中时是没有retain的)
				 */
				wyArrayDeleteObj(hash->actions, action, NULL, NULL);
				wyArrayDeleteObj(hash->pendingRemoveList, action, NULL, NULL);
				action->stop();
				wyObjectRelease(action);
			}
		}
	}
	pthread_mutex_unlock(&gMutex);
}

void wyActionManager::removeActionByTagLocked(wyNode* target, int tag) {
	// check tag
	if(tag == WY_ACTION_INVALID_TAG)
		return;

	pthread_mutex_lock(&gMutex);

	wyActionHash* hash = (wyActionHash*)wyHashSetFind(m_targets, (size_t)target, target);
	if(hash != NULL) {
		// find it in action list
		int index = wyArrayIndexOf(hash->actions, &tag, findActionByTag, NULL);
		wyAction* action = (wyAction*)wyArrayGet(hash->actions, index);

		// if not NULL, remove it, or pending it if locked
		if(action != NULL) {
			if(hash->locked) {
				wyArrayPush(hash->pendingRemoveList, action);
			} else {
				wyArrayDeleteIndex(hash->actions, index);
				wyArrayDeleteObj(hash->pendingRemoveList, action, NULL, NULL);
				action->stop();
				wyObjectRelease(action);
			}
		}
	}

	pthread_mutex_unlock(&gMutex);
}

void wyActionManager::removeActionsLocked(wyNode* target, bool includeChildren) {
	// if removing all, return
	if(m_removingAll)
		return;

	pthread_mutex_lock(&gMutex);

	// if found, release action array
	// no need to destroy hash because it is recycled
	wyActionHash* hash = (wyActionHash*)wyHashSetRemove(m_targets, (size_t)target, target);
	if(hash != NULL) {
		// clear pending remove list because hash will be destroyed and actions in pending remove list are not retained
		wyArrayClear(hash->pendingRemoveList);
		if(hash->locked) {
			hash->pendingDestroy = true;
		} else {
			wyActionHashDestroy(hash);
		}
	}

	if(includeChildren) {
		wyArrayEach(target->getChildren(), removeActions, &includeChildren);
	}

	pthread_mutex_unlock(&gMutex);
}

void wyActionManager::removeAllActionsLocked() {
	pthread_mutex_lock(&gMutex);
	if(!m_removingAll) {
		m_removingAll = true;
		wyHashSetFilter(m_targets, releaseHash, NULL);
		m_removingAll = false;
	}
	pthread_mutex_unlock(&gMutex);
}

void wyActionManager::resumeActions(wyNode* target, bool includeChildren) {
	wyActionHash* hash = (wyActionHash*)wyHashSetFind(m_targets, (size_t)target, target);
	if(hash != NULL) {
		for(int i = 0; i < hash->actions->num; i++) {
			wyAction* action = (wyAction*)wyArrayGet(hash->actions, i);
			action->m_paused = false;
		}
	}

	if(includeChildren) {
		wyArrayEach(target->getChildren(), sResumeActions, &includeChildren);
	}
}

void wyActionManager::pauseActions(wyNode* target, bool includeChildren) {
	wyActionHash* hash = (wyActionHash*)wyHashSetFind(m_targets, (size_t)target, target);
	if(hash != NULL) {
		for(int i = 0; i < hash->actions->num; i++) {
			wyAction* action = (wyAction*)wyArrayGet(hash->actions, i);
			action->m_paused = true;
		}
	}

	if(includeChildren) {
		wyArrayEach(target->getChildren(), sPauseActions, &includeChildren);
	}
}

void wyActionManager::pauseActionLocked(wyNode* target, int tag) {
	// check tag
	if(tag == WY_ACTION_INVALID_TAG)
		return;

	pthread_mutex_lock(&gMutex);

	wyActionHash* hash = (wyActionHash*)wyHashSetFind(m_targets, (size_t)target, target);
	if(hash != NULL) {
		// find it in action list
		int index = wyArrayIndexOf(hash->actions, &tag, findActionByTag, NULL);
		wyAction* action = (wyAction*)wyArrayGet(hash->actions, index);

		// if not NULL, set pause flag
		if(action != NULL) {
			action->m_paused = true;
		}
	}

	pthread_mutex_unlock(&gMutex);
}

void wyActionManager::resumeActionLocked(wyNode* target, int tag) {
	// check tag
	if(tag == WY_ACTION_INVALID_TAG)
		return;

	pthread_mutex_lock(&gMutex);

	wyActionHash* hash = (wyActionHash*)wyHashSetFind(m_targets, (size_t)target, target);
	if(hash != NULL) {
		// find it in action list
		int index = wyArrayIndexOf(hash->actions, &tag, findActionByTag, NULL);
		wyAction* action = (wyAction*)wyArrayGet(hash->actions, index);

		// if not NULL, set pause flag
		if(action != NULL) {
			action->m_paused = false;
		}
	}

	pthread_mutex_unlock(&gMutex);
}

int wyActionManager::getRunningActionCount(wyNode* target) {
	wyActionHash* hash = (wyActionHash*)wyHashSetFind(m_targets, (size_t)target, target);
	return hash == NULL ? 0 : hash->actions->num;
}

wyAction* wyActionManager::getAction(wyNode* target, int tag) {
	// check tag
	if(tag == WY_ACTION_INVALID_TAG)
		return NULL;

	// find hash and check null
	wyActionHash* hash = (wyActionHash*)wyHashSetFind(m_targets, (size_t)target, target);
	if(hash == NULL)
		return NULL;

	// find it in action list
	int index = wyArrayIndexOf(hash->actions, &tag, findActionByTag, NULL);
	if(index == -1)
		return NULL;
	else
		return (wyAction*)wyArrayGet(hash->actions, index);
}

void wyActionManager::tick(float delta) {
	wyHashSetEach(m_targets, sTick, &delta);
    
	wyArrayEach(m_physicsNodes, sUpdateNodePhysics, &delta);
	for(int i = 0; i < m_physicsNodesPendingRemove->num; i++) {
		wyNode* node = (wyNode*)wyArrayGet(m_physicsNodesPendingRemove, i);
		wyArrayDeleteObj(m_physicsNodes, node, NULL, NULL);
	}
	wyArrayClear(m_physicsNodesPendingRemove);
	for(int i = 0; i < m_physicsNodesPendingAdd->num; i++) {
		wyNode* node = (wyNode*)wyArrayGet(m_physicsNodesPendingAdd, i);
		wyArrayPush(m_physicsNodes, node);
	}
	wyArrayClear(m_physicsNodesPendingAdd);

	// clear targets which has no actions on it
	pthread_mutex_lock(&gMutex);
	wyHashSetFilter(m_targets, deleteEmtpyTarget, NULL);
	pthread_mutex_unlock(&gMutex);
}
