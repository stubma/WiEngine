#include "com_wiyun_engine_actions_MoveBy.h"
#include "wyMoveBy.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveBy_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jfloat x, jfloat y) {
	wyMoveBy* mb = wyMoveBy::make(duration, x, y);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)mb);
	mb->retain();
	mb->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveBy_setPinPoint
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	wyMoveBy* m = (wyMoveBy*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setPinPoint(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveBy_nativeGetPinPoint
  (JNIEnv * env, jobject thiz, jobject p) {
	wyMoveBy* m = (wyMoveBy*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint pos = m->getPinPoint();
	env->SetFloatField(p, g_fid_WYPoint_x, pos.x);
	env->SetFloatField(p, g_fid_WYPoint_y, pos.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveBy_clearPinPoint
  (JNIEnv * env, jobject thiz) {
	wyMoveBy* m = (wyMoveBy*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->clearPinPoint();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveBy_setPinAngleDelta
  (JNIEnv * env, jobject thiz, jfloat delta) {
	wyMoveBy* m = (wyMoveBy*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setPinAngleDelta(delta);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_actions_MoveBy_getPinAngleDelta
  (JNIEnv * env, jobject thiz) {
	wyMoveBy* m = (wyMoveBy*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return m->getPinAngleDelta();
}
