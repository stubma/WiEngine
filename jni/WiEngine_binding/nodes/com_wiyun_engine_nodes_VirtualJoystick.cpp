#include "com_wiyun_engine_nodes_VirtualJoystick.h"
#include "wyVirtualJoystick.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_VirtualJoystick_nativeInit
  (JNIEnv * env, jobject thiz, jobject bg, jobject rocker) {
	wyNode* bgNode = bg == NULL ? NULL: (wyNode*)env->GetIntField(bg, g_fid_BaseObject_mPointer);
	wyNode* rockerNode = rocker == NULL ? NULL : (wyNode*)env->GetIntField(rocker, g_fid_BaseObject_mPointer);
	wyVirtualJoystick* vj = wyVirtualJoystick::make(bgNode, rockerNode);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)vj);
	vj->retain();
	vj->lazyRelease();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_VirtualJoystick_getEventStyle
  (JNIEnv * env, jobject thiz) {
	wyVirtualJoystick* vj = (wyVirtualJoystick*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (wyVirtualJoystickEventStyle)vj->getEventStyle();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_VirtualJoystick_setEventStyle
  (JNIEnv * env, jobject thiz, jint style) {
	wyVirtualJoystick* vj = (wyVirtualJoystick*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	vj->setEventStyle((wyVirtualJoystickEventStyle)style);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_VirtualJoystick_setAutoReset
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyVirtualJoystick* vj = (wyVirtualJoystick*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	vj->setAutoReset(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_VirtualJoystick_isAutoReset
  (JNIEnv * env, jobject thiz) {
	wyVirtualJoystick* vj = (wyVirtualJoystick*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return vj->isAutoReset();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_VirtualJoystick_setCallback
  (JNIEnv * env, jobject thiz, jobject callback) {
	wyVirtualJoystick* vj = (wyVirtualJoystick*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	vj->setCallback(callback);
}

