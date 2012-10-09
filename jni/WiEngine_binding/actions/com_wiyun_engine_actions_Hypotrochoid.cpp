#include "com_wiyun_engine_actions_Hypotrochoid.h"
#include "wyHypotrochoid.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Hypotrochoid_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject config) {
	wyHypotrochoidConfig hc = wyUtils_android::to_wyHypotrochoidConfig(config);
	wyHypotrochoid* hypotrochoid = wyHypotrochoid::make(duration, hc);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)hypotrochoid);
	hypotrochoid->retain();
	hypotrochoid->lazyRelease();
}


JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Hypotrochoid_setAutoRotate
  (JNIEnv * env, jobject thiz, jboolean flag, jfloat angleDelta) {
	wyHypotrochoid* h = (wyHypotrochoid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	h->setAutoRotate(flag, angleDelta);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Hypotrochoid_setPinPoint
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	wyHypotrochoid* m = (wyHypotrochoid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setPinPoint(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Hypotrochoid_nativeGetPinPoint
  (JNIEnv * env, jobject thiz, jobject p) {
	wyHypotrochoid* m = (wyHypotrochoid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint pos = m->getPinPoint();
	env->SetFloatField(p, g_fid_WYPoint_x, pos.x);
	env->SetFloatField(p, g_fid_WYPoint_y, pos.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Hypotrochoid_clearPinPoint
  (JNIEnv * env, jobject thiz) {
	wyHypotrochoid* m = (wyHypotrochoid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->clearPinPoint();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Hypotrochoid_setPinAngleDelta
  (JNIEnv * env, jobject thiz, jfloat delta) {
	wyHypotrochoid* m = (wyHypotrochoid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setPinAngleDelta(delta);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_actions_Hypotrochoid_getPinAngleDelta
  (JNIEnv * env, jobject thiz) {
	wyHypotrochoid* m = (wyHypotrochoid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return m->getPinAngleDelta();
}
