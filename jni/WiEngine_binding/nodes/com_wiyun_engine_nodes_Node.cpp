#include "com_wiyun_engine_nodes_Node.h"
#include "wyNode.h"
#include "wyJNI.h"
#include "wyUtils_android.h"
#include "wyScheduler.h"
#include "wyActionManager.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;
extern jfieldID g_fid_BaseObject_mPointer;

extern wyActionManager* gActionManager;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyNode* node = wyNode::make();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)node);
	node->retain();
	node->lazyRelease();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Node_hitTest
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->hitTest(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_nativeAutoRelease
  (JNIEnv * env, jobject thiz, jboolean includeChildren) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->javaRelease(includeChildren);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setUserData
  (JNIEnv * env, jobject thiz, jobject data) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setJavaData(data);
}

JNIEXPORT jobject JNICALL Java_com_wiyun_engine_nodes_Node_getUserData
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getJavaData();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_draw
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->draw();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_nativeGetChildren
  (JNIEnv * env, jobject thiz, jintArray array) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	int* nodes = env->GetIntArrayElements(array, NULL);
	wyArray* children = node->getChildren();
	for(int i = 0; i < children->num; i++) {
		nodes[i] = (jint)wyArrayGet(children , i);
	}
	env->ReleaseIntArrayElements(array, nodes, 0);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Node_getChildCount
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getChildCount();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_visit
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->visit();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Node_nativeGetFirstChild
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)node->getFirstChild();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_runAction
  (JNIEnv * env, jobject thiz, jobject action) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyAction* actionNode = (wyAction*)env->GetIntField(action, g_fid_BaseObject_mPointer);
	gActionManager->addActionLocked(actionNode, node);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_stopAction__Lcom_wiyun_engine_actions_Action_2
  (JNIEnv * env, jobject thiz, jobject action) {
	wyAction* actionNode = (wyAction*)env->GetIntField(action, g_fid_BaseObject_mPointer);
	gActionManager->removeActionLocked(actionNode);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_stopAction__I
  (JNIEnv * env, jobject thiz, jint tag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	gActionManager->removeActionByTagLocked(node, tag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_stopAllActions__
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	gActionManager->removeActionsLocked(node, false);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_pauseAllActions__
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->pauseAllActions();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_pauseAllActions__Z
  (JNIEnv * env, jobject thiz, jboolean includeChildren) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->pauseAllActions(includeChildren);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_resumeAllActions__
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->resumeAllActions();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_resumeAllActions__Z
  (JNIEnv * env, jobject thiz, jboolean includeChildren) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->resumeAllActions(includeChildren);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_pauseAction
  (JNIEnv * env, jobject thiz, jint tag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->pauseAction(tag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_resumeAction
  (JNIEnv * env, jobject thiz, jint tag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->resumeAction(tag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_pauseAllTimers__
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->pauseAllTimers();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_pauseAllTimers__Z
  (JNIEnv * env, jobject thiz, jboolean includeChildren) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->pauseAllTimers(includeChildren);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_resumeAllTimers__
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->resumeAllTimers();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_resumeAllTimers__Z
  (JNIEnv * env, jobject thiz, jboolean includeChildren) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->resumeAllTimers(includeChildren);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Node_getActionPointer
  (JNIEnv * env, jobject thiz, jint tag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)node->getAction(tag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_stopAllActions__Z
  (JNIEnv * env, jobject thiz, jboolean includeChildren) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	gActionManager->removeActionsLocked(node, includeChildren);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_schedule
  (JNIEnv * env, jobject thiz, jobject targetSelector, jfloat interval) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTargetSelector* ts = wyTargetSelector::make(targetSelector);
	wyTimer* t = WYNEW wyTimer(ts, interval);
	node->scheduleLocked(t);
	wyObjectRelease(t);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_scheduleByFrame
  (JNIEnv * env, jobject thiz, jobject targetSelector, jint frame) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTargetSelector* ts = wyTargetSelector::make(targetSelector);
	wyTimer* t = WYNEW wyTimer(ts, frame);
	node->scheduleLocked(t);
	wyObjectRelease(t);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_scheduleOnce
  (JNIEnv * env, jobject thiz, jobject targetSelector, jfloat delay) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTargetSelector* ts = wyTargetSelector::make(targetSelector);
	wyTimer* t = WYNEW wyTimer(ts, delay);
	t->setOneShot(true);
	node->scheduleLocked(t);
	wyObjectRelease(t);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_scheduleOnceByFrame
  (JNIEnv * env, jobject thiz, jobject targetSelector, jint delayFrame) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTargetSelector* ts = wyTargetSelector::make(targetSelector);
	wyTimer* t = WYNEW wyTimer(ts, delayFrame);
	t->setOneShot(true);
	node->scheduleLocked(t);
	wyObjectRelease(t);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_unschedule
  (JNIEnv * env, jobject thiz, jobject targetSelector) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTargetSelector* ts = wyTargetSelector::make(targetSelector);
	wyTimer* t = WYNEW wyTimer(ts);
	node->unscheduleLocked(t);
	wyObjectRelease(t);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_removeAllChildren
  (JNIEnv * env, jobject thiz, jboolean cleanup) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->removeAllChildrenLocked(cleanup);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_removeChild__Lcom_wiyun_engine_nodes_Node_2Z
  (JNIEnv * env, jobject thiz, jobject child, jboolean cleanup) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* childNode = (wyNode*)env->GetIntField(child, g_fid_BaseObject_mPointer);
	node->removeChildLocked(childNode, cleanup);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_removeChild__IZ
  (JNIEnv * env, jobject thiz, jint tag, jboolean cleanup) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->removeChildByTagLocked(tag, cleanup);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_removeChildren
  (JNIEnv * env, jobject thiz, jint tag, jboolean cleanup) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->removeChildrenByTagLocked(tag, cleanup);
}

JNIEXPORT jintArray JNICALL Java_com_wiyun_engine_nodes_Node_getChildrenPointer
  (JNIEnv * env, jobject thiz, jint tag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);

	// get matched children
	size_t count;
	wyNode** children = node->getChildrenByTagLocked(tag, &count);

	// create returned array
	jintArray ret = env->NewIntArray(count);
	jint* nRet = env->GetIntArrayElements(ret, NULL);
	for(int i = 0; i < count; i++) {
		nRet[i] = (jint)children[i];
	}
	env->ReleaseIntArrayElements(ret, nRet, JNI_COMMIT);

	// release
	wyFree(children);

	// return
	return ret;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Node_getChildPointer
  (JNIEnv * env, jobject thiz, jint tag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)node->getChildByTagLocked(tag);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Node_getChildPointerAt
  (JNIEnv * env, jobject thiz, jint index) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)node->getChildAt(index);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_nativeConvertToWorldSpace
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y, jobject p) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint pos = { x, y };
	pos = node->nodeToWorldSpace(pos);
	env->SetFloatField(p, g_fid_WYPoint_x, pos.x);
	env->SetFloatField(p, g_fid_WYPoint_y, pos.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_nativeConvertToWorldSpaceAR
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y, jobject p) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint pos = { x, y };
	pos = node->nodeToWorldSpaceAR(pos);
	env->SetFloatField(p, g_fid_WYPoint_x, pos.x);
	env->SetFloatField(p, g_fid_WYPoint_y, pos.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_nativeConvertToNodeSpace
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y, jobject p) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint pos = { x, y };
	pos = node->worldToNodeSpace(pos);
	env->SetFloatField(p, g_fid_WYPoint_x, pos.x);
	env->SetFloatField(p, g_fid_WYPoint_y, pos.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_nativeConvertToNodeSpaceAR
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y, jobject p) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint pos = { x, y };
	pos = node->worldToNodeSpaceAR(pos);
	env->SetFloatField(p, g_fid_WYPoint_x, pos.x);
	env->SetFloatField(p, g_fid_WYPoint_y, pos.y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getHeight
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getHeight();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getWidth
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getWidth();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_nativeGetBoundingBox
  (JNIEnv * env, jobject thiz, jobject rect) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyRect r = node->getBoundingBox();
	wyUtils_android::to_WYRect( r, rect);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_nativeGetBoundingBoxRelativeToParent
  (JNIEnv * env, jobject thiz, jobject rect) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyRect r = node->getBoundingBoxRelativeToParent();
	wyUtils_android::to_WYRect( r, rect);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_nativeGetBoundingBoxRelativeToWorld
  (JNIEnv * env, jobject thiz, jobject rect) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyRect r = node->getBoundingBoxRelativeToWorld();
	wyUtils_android::to_WYRect( r, rect);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setParent
  (JNIEnv * env, jobject thiz, jobject parent) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	if(parent)
		node->setParent((wyNode*)env->GetIntField(parent, g_fid_BaseObject_mPointer));
	else
		node->setParent(NULL);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Node_nativeGetParent
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)node->getParent();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_addChild
  (JNIEnv * env, jobject thiz, jobject child, jint z, jint tag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* childNode = (wyNode*)env->GetIntField(child, g_fid_BaseObject_mPointer);
	node->addChildLocked(childNode, z, tag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_reorderChild
  (JNIEnv * env, jobject thiz, jobject child, jint z) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* childNode = (wyNode*)env->GetIntField(child, g_fid_BaseObject_mPointer);
	node->reorderChildLocked(childNode, z);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_bringToFront
  (JNIEnv * env, jobject thiz, jobject child) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* childNode = (wyNode*)env->GetIntField(child, g_fid_BaseObject_mPointer);
	node->bringToFrontLocked(childNode);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_bringToBack
  (JNIEnv * env, jobject thiz, jobject child) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* childNode = (wyNode*)env->GetIntField(child, g_fid_BaseObject_mPointer);
	node->bringToBackLocked(childNode);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_nativeGetAbsolutePosition
  (JNIEnv * env, jobject thiz, jobject p) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint pos = node->getAbsolutePosition();
	env->SetFloatField(p, g_fid_WYPoint_x, pos.x);
	env->SetFloatField(p, g_fid_WYPoint_y, pos.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_cleanup
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->cleanup();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_onEnter
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->onEnter();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_onExit
	(JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->onExit();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_onEnterTransitionDidFinish
	(JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->onEnterTransitionDidFinish();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setTransformDirty
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setTransformDirty();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Node_isRunning
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isRunning();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Node_getZOrder
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getZOrder();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setZOrder
  (JNIEnv * env, jobject thiz, jint zOrder) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setZOrder(zOrder);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Node_getTag
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getTag();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setTag
  (JNIEnv * env, jobject thiz, jint tag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setTag(tag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setEnabled
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setEnabled(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Node_isEnabled
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isEnabled();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Node_isSelected
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isSelected();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setSelected
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setSelected(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Node_isFocused
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isFocused();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setFocused
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setFocused(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setRelativeAnchorPoint
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setRelativeAnchorPoint(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Node_isRelativeToAnchor
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isRelativeAnchorPoint();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getPositionX
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getPositionX();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getPositionY
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getPositionY();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getOriginX
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getOriginX();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getOriginY
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getOriginY();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getRotation
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getRotation();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getScaleX
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getScaleX();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getScaleY
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getScaleY();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getScale
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getScale();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_scale
  (JNIEnv * env, jobject thiz, jfloat s) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setScale(s);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setRotation
  (JNIEnv * env, jobject thiz, jfloat rot) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setRotation(rot);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setScale
  (JNIEnv * env, jobject thiz, jfloat scale) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setScale(scale);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setScaleX
  (JNIEnv * env, jobject thiz, jfloat scaleX) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setScaleX(scaleX);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setScaleY
  (JNIEnv * env, jobject thiz, jfloat scaleY) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setScaleY(scaleY);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setSkewX
  (JNIEnv * env, jobject thiz, jfloat x) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setSkewX(x);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setSkewY
  (JNIEnv * env, jobject thiz, jfloat y) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setSkewY(y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getSkewX
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getSkewX();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getSkewY
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getSkewY();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setPosition
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setPosition(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_translate
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->translate(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_translateChildren
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->translateChildren(x, y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getVertexZ
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getVertexZ();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setVertexZ
  (JNIEnv * env, jobject thiz, jfloat z) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setVertexZ(z);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Node_isVisible
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isVisible();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setVisible
  (JNIEnv * env, jobject thiz, jboolean visible) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setVisible(visible);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setGrid
  (JNIEnv * env, jobject thiz, jobject grid) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setGrid((wyBaseGrid*)env->GetIntField(grid, g_fid_BaseObject_mPointer));
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Node_nativeGetGrid
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)node->getGrid();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Node_nativeGetCamera
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)node->getCamera();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getAnchorX
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getAnchorX();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getAnchorY
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getAnchorY();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setAnchor
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setAnchor(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setAnchorX
  (JNIEnv * env, jobject thiz, jfloat x) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setAnchorX(x);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setAnchorY
  (JNIEnv * env, jobject thiz, jfloat y) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setAnchorY(y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_moveAnchorTo
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->moveAnchorTo(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setContentSize
  (JNIEnv * env, jobject thiz, jfloat w, jfloat h) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setContentSize(w, h);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getAnchorPointX
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getAnchorPointX();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getAnchorPointY
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getAnchorPointY();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Node_isGestureEnabled
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isGestureEnabled();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setGestureEnabled
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setGestureEnabled(flag);
	node->setJavaGestureHandler(flag ? thiz : NULL);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Node_isDoubleTapEnabled
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isDoubleTabEnabled();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setDoubleTapEnabled
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setDoubleTapEnabled(flag);
	node->setJavaDoubleTapHandler(flag ? thiz : NULL);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Node_isTouchEnabled
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isTouchEnabled();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setTouchEnabled
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setTouchEnabled(flag);
	node->setJavaTouchHandler(flag ? thiz : NULL);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setKeyEnabled
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setKeyEnabled(flag);
	node->setJavaKeyHandler(flag ? thiz : NULL);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Node_isKeyEnabled
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isKeyEnabled();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Node_isAccelerometerEnabled
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isAccelerometerEnabled();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setAccelerometerEnabled
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setAccelerometerEnabled(flag);
	node->setJavaAccelHandler(flag ? thiz : NULL);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setJavaVirtualMethods
  (JNIEnv * env, jobject thiz, jobject h) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setJavaVirtualMethods(h);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Node_isNoDraw
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isNoDraw();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setNoDraw
  (JNIEnv * env, jobject thiz, jboolean noDraw) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setNoDraw(noDraw);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_transform
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->transform();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_transformAncestors
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->transformAncestors();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setTouchPriority
  (JNIEnv * env, jobject thiz, jint p) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setTouchPriority(p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setKeyPriority
  (JNIEnv * env, jobject thiz, jint p) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setKeyPriority(p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setGesturePriority
  (JNIEnv * env, jobject thiz, jint p) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setGesturePriority(p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setDoubleTapPriority
  (JNIEnv * env, jobject thiz, jint p) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setDoubleTapPriority(p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setAccelerometerPriority
  (JNIEnv * env, jobject thiz, jint p) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setAccelerometerPriority(p);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Node_getTouchPriority
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);

}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Node_getKeyPriority
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getKeyPriority();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Node_getGesturePriority
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getGesturePriority();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Node_getDoubleTapPriority
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getDoubleTapPriority();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Node_getAccelerometerPriority
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getAccelerometerPriority();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setVelocity
  (JNIEnv * env, jobject thiz, jfloat vx, jfloat vy) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setVelocity(vx, vy);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setAcceleration
  (JNIEnv * env, jobject thiz, jfloat ax, jfloat ay) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setAcceleration(ax, ay);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setAccelerationX
  (JNIEnv * env, jobject thiz, jfloat ax) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setAccelerationX(ax);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setAccelerationY
  (JNIEnv * env, jobject thiz, jfloat ay) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setAccelerationY(ay);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setVelocityX
  (JNIEnv * env, jobject thiz, jfloat vx) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setVelocityX(vx);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setVelocityY
  (JNIEnv * env, jobject thiz, jfloat vy) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setVelocityY(vy);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getVelocityX
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getVelocityX();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getVelocityY
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getVelocityY();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_nativeGetVelocity
  (JNIEnv * env, jobject thiz, jobject p) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint v = node->getVelocity();
	wyUtils_android::to_WYPoint(v, p);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getAccelerationX
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getAccelerationX();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Node_getAccelerationY
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getAccelerationY();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_nativeGetAcceleration
  (JNIEnv * env, jobject thiz, jobject p) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint a = node->getAcceleration();
	wyUtils_android::to_WYPoint(a, p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setPositionListener
  (JNIEnv * env, jobject thiz, jobject listener) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setPositionListener(listener);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setClipRect
  (JNIEnv * env, jobject thiz, jobject rect, jboolean relativeToSelf) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyRect r = wyUtils_android::to_wyRect( rect);
	node->setClipRect(r, relativeToSelf);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_clearClipRect
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->clearClipRect();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_nativeGetClipRect
  (JNIEnv * env, jobject thiz, jobject rect) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyRect r = node->getClipRect();
	wyUtils_android::to_WYRect( r, rect);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_sizeToFit
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->sizeToFit();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_enlargeNode
  (JNIEnv * env, jobject thiz, jfloat left, jfloat top, jfloat right, jfloat bottom) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->enlargeNode(left, top, right, bottom);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Node_isAncestor
  (JNIEnv * env, jobject thiz, jobject node) {
	wyNode* n1 = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* n2 = (wyNode*)env->GetIntField(node, g_fid_BaseObject_mPointer);
	return n1->isAncestor(n2);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setInterceptTouch
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setInterceptTouch(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Node_setMultiTouchClickable
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setMultiTouchClickable(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Node_isMultiTouchClickable
  (JNIEnv * env, jobject thiz) {
	wyNode* node = (wyNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isMultiTouchClickable();
}
