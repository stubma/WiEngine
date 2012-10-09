#include "com_wiyun_engine_actions_MoveTo.h"
#include "wyMoveTo.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveTo_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jfloat startX, jfloat startY, jfloat endX, jfloat endY) {
	wyMoveTo* mb = wyMoveTo::make(duration, startX, startY, endX, endY);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)mb);
	mb->retain();
	mb->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveTo_setPinPoint
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	wyMoveTo* m = (wyMoveTo*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setPinPoint(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveTo_nativeGetPinPoint
  (JNIEnv * env, jobject thiz, jobject p) {
	wyMoveTo* m = (wyMoveTo*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint pos = m->getPinPoint();
	env->SetFloatField(p, g_fid_WYPoint_x, pos.x);
	env->SetFloatField(p, g_fid_WYPoint_y, pos.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveTo_clearPinPoint
  (JNIEnv * env, jobject thiz) {
	wyMoveTo* m = (wyMoveTo*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->clearPinPoint();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveTo_setPinAngleDelta
  (JNIEnv * env, jobject thiz, jfloat delta) {
	wyMoveTo* m = (wyMoveTo*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setPinAngleDelta(delta);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_actions_MoveTo_getPinAngleDelta
  (JNIEnv * env, jobject thiz) {
	wyMoveTo* m = (wyMoveTo*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return m->getPinAngleDelta();
}
