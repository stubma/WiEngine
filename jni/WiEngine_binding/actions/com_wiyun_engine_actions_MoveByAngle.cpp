#include "com_wiyun_engine_actions_MoveByAngle.h"
#include "wyMoveByAngle.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveByAngle_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint degree, jint velocity) {
	wyMoveByAngle* mb = wyMoveByAngle::make(duration, degree, velocity);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)mb);
	mb->retain();
	mb->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveByAngle_setPinPoint
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	wyMoveByAngle* m = (wyMoveByAngle*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setPinPoint(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveByAngle_nativeGetPinPoint
  (JNIEnv * env, jobject thiz, jobject p) {
	wyMoveByAngle* m = (wyMoveByAngle*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint pos = m->getPinPoint();
	env->SetFloatField(p, g_fid_WYPoint_x, pos.x);
	env->SetFloatField(p, g_fid_WYPoint_y, pos.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveByAngle_clearPinPoint
  (JNIEnv * env, jobject thiz) {
	wyMoveByAngle* m = (wyMoveByAngle*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->clearPinPoint();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveByAngle_setPinAngleDelta
  (JNIEnv * env, jobject thiz, jfloat delta) {
	wyMoveByAngle* m = (wyMoveByAngle*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setPinAngleDelta(delta);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_actions_MoveByAngle_getPinAngleDelta
  (JNIEnv * env, jobject thiz) {
	wyMoveByAngle* m = (wyMoveByAngle*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return m->getPinAngleDelta();
}
