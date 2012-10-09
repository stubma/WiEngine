#include "com_wiyun_engine_nodes_ActionManager.h"
#include "wyActionManager.h"

extern wyActionManager* gActionManager;
extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_ActionManager_nativeGetInstance
  (JNIEnv * env, jclass clazz) {
	return (jint)gActionManager;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ActionManager_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyActionManager* am = wyActionManager::getInstance();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)am);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ActionManager_addAction
  (JNIEnv * env, jobject thiz, jobject action, jobject target, jboolean paused) {
	wyAction* actionNode = (wyAction*)env->GetIntField(action, g_fid_BaseObject_mPointer);
	wyNode* targetNode = (wyNode*)env->GetIntField(target, g_fid_BaseObject_mPointer);
	gActionManager->addActionLocked(actionNode, targetNode);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_ActionManager_getRunningActionCount
  (JNIEnv * env, jobject thiz, jobject target) {
	wyNode* targetNode = (wyNode*)env->GetIntField(target, g_fid_BaseObject_mPointer);
	return gActionManager->getRunningActionCount(targetNode);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ActionManager_removeAction__Lcom_wiyun_engine_nodes_Node_2I
  (JNIEnv * env, jobject thiz, jobject target, jint tag) {
	wyNode* targetNode = (wyNode*)env->GetIntField(target, g_fid_BaseObject_mPointer);
	jint pointer = (jint)gActionManager->getAction(targetNode, tag);
	gActionManager->removeActionByTagLocked(targetNode, tag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ActionManager_removeAction__Lcom_wiyun_engine_actions_Action_2
  (JNIEnv * env, jobject thiz, jobject action) {
	wyAction* actionNode = (wyAction*)env->GetIntField(action, g_fid_BaseObject_mPointer);
	gActionManager->removeActionLocked(actionNode);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ActionManager_removeAllActions__Lcom_wiyun_engine_nodes_Node_2
  (JNIEnv * env, jobject thiz, jobject target) {
	wyNode* targetNode = (wyNode*)env->GetIntField(target, g_fid_BaseObject_mPointer);
	gActionManager->removeActionsLocked(targetNode, false);
}
JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ActionManager_removeAllActions__Lcom_wiyun_engine_nodes_Node_2Z
  (JNIEnv * env, jobject thiz, jobject target, jboolean includeChildren) {
	wyNode* targetNode = (wyNode*)env->GetIntField(target, g_fid_BaseObject_mPointer);
	gActionManager->removeActionsLocked(targetNode, includeChildren);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ActionManager_removeAllActions__
  (JNIEnv * env, jobject thiz) {
	gActionManager->removeAllActionsLocked();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ActionManager_resumeAllActions
  (JNIEnv * env, jobject thiz, jobject target, jboolean includeChildren) {
	wyNode* targetNode = (wyNode*)env->GetIntField(target, g_fid_BaseObject_mPointer);
	gActionManager->resumeActions(targetNode, includeChildren);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ActionManager_pauseAllActions
  (JNIEnv * env, jobject thiz, jobject target, jboolean includeChildren) {
	wyNode* targetNode = (wyNode*)env->GetIntField(target, g_fid_BaseObject_mPointer);
	gActionManager->pauseActions(targetNode, includeChildren);
}
