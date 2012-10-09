#include "com_wiyun_engine_actions_Bezier.h"
#include "wyBezier.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Bezier_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject config) {
	wyBezierConfig bc = wyUtils_android::to_wyBezierConfig(config);
	wyBezier* bezier = wyBezier::make(duration, bc);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)bezier);
	bezier->retain();
	bezier->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Bezier_setAutoRotate
  (JNIEnv * env, jobject thiz, jboolean flag, jfloat angleDelta) {
	wyBezier* b = (wyBezier*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b->setAutoRotate(flag, angleDelta);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Bezier_setPinPoint
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	wyBezier* m = (wyBezier*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setPinPoint(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Bezier_nativeGetPinPoint
  (JNIEnv * env, jobject thiz, jobject p) {
	wyBezier* m = (wyBezier*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint pos = m->getPinPoint();
	env->SetFloatField(p, g_fid_WYPoint_x, pos.x);
	env->SetFloatField(p, g_fid_WYPoint_y, pos.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Bezier_clearPinPoint
  (JNIEnv * env, jobject thiz) {
	wyBezier* m = (wyBezier*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->clearPinPoint();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Bezier_setPinAngleDelta
  (JNIEnv * env, jobject thiz, jfloat delta) {
	wyBezier* m = (wyBezier*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setPinAngleDelta(delta);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_actions_Bezier_getPinAngleDelta
  (JNIEnv * env, jobject thiz) {
	wyBezier* m = (wyBezier*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return m->getPinAngleDelta();
}
