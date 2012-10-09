#include "com_wiyun_engine_utils_VerletPoint.h"
#include "wyVerletPoint.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_VerletPoint_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyVerletPoint* vp = WYNEW wyVerletPoint();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)vp);
	vp->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_VerletPoint_setPosition
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	wyVerletPoint* vp = (wyVerletPoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	vp->setPosition(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_VerletPoint_update
  (JNIEnv * env, jobject thiz) {
	wyVerletPoint* vp = (wyVerletPoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	vp->update();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_VerletPoint_applyGravity
  (JNIEnv * env, jobject thiz, jfloat dt) {
	wyVerletPoint* vp = (wyVerletPoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	vp->applyGravity(dt);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_VerletPoint_setX
  (JNIEnv * env, jobject thiz, jfloat x) {
	wyVerletPoint* vp = (wyVerletPoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	vp->setX(x);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_VerletPoint_setY
  (JNIEnv * env, jobject thiz, jfloat y) {
	wyVerletPoint* vp = (wyVerletPoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	vp->setY(y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_utils_VerletPoint_getX
  (JNIEnv * env, jobject thiz) {
	wyVerletPoint* vp = (wyVerletPoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return vp->getX();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_utils_VerletPoint_getY
  (JNIEnv * env, jobject thiz) {
	wyVerletPoint* vp = (wyVerletPoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return vp->getY();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_VerletPoint_attenuate
  (JNIEnv * env, jobject thiz, jfloat percent) {
	wyVerletPoint* vp = (wyVerletPoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	vp->attenuate(percent);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_VerletPoint_nativeCopy
  (JNIEnv * env, jobject thiz) {
	wyVerletPoint* vp = (wyVerletPoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)vp->copy();
}
