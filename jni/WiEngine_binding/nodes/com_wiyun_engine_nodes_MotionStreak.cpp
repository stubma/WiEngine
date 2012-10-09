#include "com_wiyun_engine_nodes_MotionStreak.h"
#include "wyMotionStreak.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYColor4B_r;
extern jfieldID g_fid_WYColor4B_g;
extern jfieldID g_fid_WYColor4B_b;
extern jfieldID g_fid_WYColor4B_a;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MotionStreak_nativeInit
  (JNIEnv * env, jobject thiz, jfloat fade, jobject texture, jobject color, jint style) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	wyColor4B c = {
		env->GetIntField(color, g_fid_WYColor4B_r),
		env->GetIntField(color, g_fid_WYColor4B_g),
		env->GetIntField(color, g_fid_WYColor4B_b),
		env->GetIntField(color, g_fid_WYColor4B_a)
	};
	wyMotionStreak* streak = WYNEW wyMotionStreak(fade, tex, c, (wyMotionStreakStyle)style);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)streak);
	wyObjectLazyRelease(streak);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_MotionStreak_getRibbon
  (JNIEnv * env, jobject thiz) {
	wyMotionStreak* streak = (wyMotionStreak*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)streak->getRibbon();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MotionStreak_nativeGetLastLocation
  (JNIEnv * env, jobject thiz, jobject p) {
	wyMotionStreak* streak = (wyMotionStreak*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint loc = streak->getLastLocation();
	wyUtils_android::to_WYPoint(loc, p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MotionStreak_nativeGetCurrentLocation
  (JNIEnv * env, jobject thiz, jobject p) {
	wyMotionStreak* streak = (wyMotionStreak*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint loc = streak->getCurrentLocation();
	wyUtils_android::to_WYPoint(loc, p);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_MotionStreak_nativeGetTexture
  (JNIEnv * env, jobject thiz) {
	wyMotionStreak* streak = (wyMotionStreak*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)streak->getTexture();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MotionStreak_setTexture
  (JNIEnv * env, jobject thiz, jobject texture) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	wyMotionStreak* streak = (wyMotionStreak*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	streak->setTexture(tex);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_MotionStreak_getBlendFuncSrc
  (JNIEnv * env, jobject thiz) {
	wyMotionStreak* streak = (wyMotionStreak*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return streak->getBlendFunc().src;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_MotionStreak_getBlendFuncDst
  (JNIEnv * env, jobject thiz) {
	wyMotionStreak* streak = (wyMotionStreak*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return streak->getBlendFunc().dst;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MotionStreak_setBlendFunc
  (JNIEnv * env, jobject thiz, jint src, jint dst) {
	wyMotionStreak* streak = (wyMotionStreak*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyBlendFunc func = { src, dst };
	streak->setBlendFunc(func);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MotionStreak_setPaused
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyMotionStreak* streak = (wyMotionStreak*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	streak->setPaused(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_MotionStreak_isPaused
  (JNIEnv * env, jobject thiz) {
	wyMotionStreak* streak = (wyMotionStreak*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return streak->isPaused();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MotionStreak_addPoint
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y, jboolean newSegment) {
	wyMotionStreak* streak = (wyMotionStreak*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	streak->addPoint(x,  y, newSegment);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MotionStreak_reset
  (JNIEnv * env, jobject thiz) {
	wyMotionStreak* streak = (wyMotionStreak*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	streak->reset();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_MotionStreak_getStyle
  (JNIEnv * env, jobject thiz) {
	wyMotionStreak* streak = (wyMotionStreak*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)streak->getStyle();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MotionStreak_setSegmentThreshold
  (JNIEnv * env, jobject thiz, jfloat seg) {
	wyMotionStreak* streak = (wyMotionStreak*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	streak->setSegmentThreshold(seg);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_MotionStreak_getSegmentThreshold
  (JNIEnv * env, jobject thiz) {
	wyMotionStreak* streak = (wyMotionStreak*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return streak->getSegmentThreshold();
}
