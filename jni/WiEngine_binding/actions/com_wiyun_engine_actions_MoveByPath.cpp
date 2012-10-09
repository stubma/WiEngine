#include "com_wiyun_engine_actions_MoveByPath.h"
#include "wyMoveByPath.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveByPath_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyMoveByPath* m = wyMoveByPath::make();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)m);
	m->retain();
	m->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveByPath_addPoint
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y, jfloat duration) {
	wyMoveByPath* m = (wyMoveByPath*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->addPoint(x, y, duration);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_actions_MoveByPath_getPointCount
  (JNIEnv * env, jobject thiz) {
	wyMoveByPath* m = (wyMoveByPath*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return m->getPointCount();
}

JNIEXPORT jfloatArray JNICALL Java_com_wiyun_engine_actions_MoveByPath_getPoints
  (JNIEnv * env, jobject thiz) {
	wyMoveByPath* m = (wyMoveByPath*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	int count = m->getPointCount();
	jfloatArray array = env->NewFloatArray(count * 2);
	env->SetFloatArrayRegion(array, 0, count * 2, m->getPoints());
	return array;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveByPath_setAutoRotate
  (JNIEnv * env, jobject thiz, jboolean flag, jfloat angleDelta) {
	wyMoveByPath* b = (wyMoveByPath*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b->setAutoRotate(flag, angleDelta);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveByPath_setPinPoint
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	wyMoveByPath* m = (wyMoveByPath*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setPinPoint(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveByPath_nativeGetPinPoint
  (JNIEnv * env, jobject thiz, jobject p) {
	wyMoveByPath* m = (wyMoveByPath*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint pos = m->getPinPoint();
	env->SetFloatField(p, g_fid_WYPoint_x, pos.x);
	env->SetFloatField(p, g_fid_WYPoint_y, pos.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveByPath_clearPinPoint
  (JNIEnv * env, jobject thiz) {
	wyMoveByPath* m = (wyMoveByPath*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->clearPinPoint();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_MoveByPath_setPinAngleDelta
  (JNIEnv * env, jobject thiz, jfloat delta) {
	wyMoveByPath* m = (wyMoveByPath*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setPinAngleDelta(delta);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_actions_MoveByPath_getPinAngleDelta
  (JNIEnv * env, jobject thiz) {
	wyMoveByPath* m = (wyMoveByPath*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return m->getPinAngleDelta();
}
