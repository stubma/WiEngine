#include "com_wiyun_engine_actions_Action.h"
#include "wyAction.h"

#include "wyNode.h"
#include "wyJNI.h"
#include "wyLog.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Action_setCallback
  (JNIEnv * env, jobject thiz, jobject callback) {
	wyAction* action = (wyAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	action->setCallback(callback);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_actions_Action_getTag
  (JNIEnv * env, jobject thiz) {
	wyAction* action = (wyAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return action->getTag();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Action_setTag
  (JNIEnv * env, jobject thiz, jint tag) {
	wyAction* action = (wyAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	action->setTag(tag);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_actions_Action_nativeGetTarget
  (JNIEnv * env, jobject thiz) {
	wyAction* action = (wyAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)action->getTarget();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_actions_Action_nativeCopy
  (JNIEnv * env, jobject thiz) {
	wyAction* action = (wyAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyAction* copy = action->copy();
	copy->retain();
	return (jint)copy->lazyRelease();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_actions_Action_nativeReverse
  (JNIEnv * env, jobject thiz) {
	wyAction* action = (wyAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyAction* reverse = action->reverse();
	reverse->retain();
	return (jint)reverse->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Action_start
  (JNIEnv * env, jobject thiz, jobject target) {
	wyAction* action = (wyAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* targetNode = (wyNode*)env->GetIntField(target, g_fid_BaseObject_mPointer);
	action->start(targetNode);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Action_stop
  (JNIEnv * env, jobject thiz) {
	wyAction* action = (wyAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	action->stop();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_actions_Action_isDone
  (JNIEnv * env, jobject thiz) {
	wyAction* action = (wyAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return action->isDone();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Action_step
  (JNIEnv * env, jobject thiz, jfloat delta) {
	wyAction* action = (wyAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	action->step(delta);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Action_update
  (JNIEnv * env, jobject thiz, jfloat delta) {
	wyAction* action = (wyAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	action->update(delta);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_actions_Action_isPaused
  (JNIEnv * env, jobject thiz) {
	wyAction* action = (wyAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return action->isPaused();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_actions_Action_isRunning
  (JNIEnv * env, jobject thiz) {
	wyAction* action = (wyAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return action->isRunning();
}
