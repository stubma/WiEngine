#include "com_wiyun_engine_actions_Lagrange.h"
#include "wyLagrange.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Lagrange_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject config) {
	wyLagrangeConfig bc = wyUtils_android::to_wyLagrangeConfig(config);
	wyLagrange* a = wyLagrange::make(duration, bc);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)a);
	a->retain();
	a->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Lagrange_setAutoRotate
  (JNIEnv * env, jobject thiz, jboolean flag, jfloat angleDelta) {
	wyLagrange* b = (wyLagrange*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b->setAutoRotate(flag, angleDelta);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Lagrange_setPinPoint
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	wyLagrange* m = (wyLagrange*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setPinPoint(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Lagrange_nativeGetPinPoint
  (JNIEnv * env, jobject thiz, jobject p) {
	wyLagrange* m = (wyLagrange*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint pos = m->getPinPoint();
	env->SetFloatField(p, g_fid_WYPoint_x, pos.x);
	env->SetFloatField(p, g_fid_WYPoint_y, pos.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Lagrange_clearPinPoint
  (JNIEnv * env, jobject thiz) {
	wyLagrange* m = (wyLagrange*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->clearPinPoint();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Lagrange_setPinAngleDelta
  (JNIEnv * env, jobject thiz, jfloat delta) {
	wyLagrange* m = (wyLagrange*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setPinAngleDelta(delta);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_actions_Lagrange_getPinAngleDelta
  (JNIEnv * env, jobject thiz) {
	wyLagrange* m = (wyLagrange*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return m->getPinAngleDelta();
}
