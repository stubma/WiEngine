#include "com_wiyun_engine_utils_VerletRope.h"
#include "wyVerletRope.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_VerletRope_nativeInit
  (JNIEnv * env, jobject thiz, jobject a, jobject b, jobject tex, jint length) {
	wyTexture2D* t = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	wyPoint pa = wyUtils_android::to_wyPoint( a);
	wyPoint pb = wyUtils_android::to_wyPoint( b);
	wyVerletRope* r = WYNEW wyVerletRope(pa, pb, t, (size_t)length);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)r);
	r->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_VerletRope_reset
  (JNIEnv * env, jobject thiz, jobject a, jobject b) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint pa = wyUtils_android::to_wyPoint( a);
	wyPoint pb = wyUtils_android::to_wyPoint( b);
	r->reset(pa, pb);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_VerletRope_update
  (JNIEnv * env, jobject thiz, jobject a, jobject b, jfloat dt) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint pa = wyUtils_android::to_wyPoint( a);
	wyPoint pb = wyUtils_android::to_wyPoint( b);
	r->update(pa, pb, dt);
}

JNIEXPORT jintArray JNICALL Java_com_wiyun_engine_utils_VerletRope_getSticks
  (JNIEnv * env, jobject thiz) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jintArray ret = env->NewIntArray(r->getStickCount());
	wyArray* sticks = r->getSticks();
	for(int i = 0; i < sticks->num; i++) {
		void* stick = wyArrayGet(sticks, i);
		env->SetIntArrayRegion(ret, i, 1, (const jint*)stick);
	}
	return ret;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_VerletRope_nativeGetStickAt
  (JNIEnv * env, jobject thiz, jint index) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)r->getStickAt(index);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_VerletRope_getStickCount
  (JNIEnv * env, jobject thiz) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return r->getStickCount();
}

JNIEXPORT jintArray JNICALL Java_com_wiyun_engine_utils_VerletRope_getPoints
  (JNIEnv * env, jobject thiz) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jintArray ret = env->NewIntArray(r->getPointCount());
	wyArray* points = r->getPoints();
	for(int i = 0; i < points->num; i++) {
		void* point = wyArrayGet(points, i);
		env->SetIntArrayRegion(ret, i, 1, (const jint*)point);
	}
	return ret;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_VerletRope_nativeGetPointAt
  (JNIEnv * env, jobject thiz, jint index) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)r->getPointAt(index);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_VerletRope_getPointCount
  (JNIEnv * env, jobject thiz) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return r->getPointCount();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_utils_VerletRope_getCurrentLength
  (JNIEnv * env, jobject thiz) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return r->getCurrentLength();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_VerletRope_rayCast
  (JNIEnv * env, jobject thiz, jobject s, jobject e) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint ps = wyUtils_android::to_wyPoint( s);
	wyPoint pe = wyUtils_android::to_wyPoint( e);
	return (jint)r->rayCast(ps, pe);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_VerletRope_nativeGetColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = r->getColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_VerletRope_setColor__Lcom_wiyun_engine_types_WYColor3B_2
  (JNIEnv * env, jobject thiz, jobject color) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = wyUtils_android::to_wyColor3B( color);
	r->setColor(c);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_VerletRope_setColor__Lcom_wiyun_engine_types_WYColor4B_2
  (JNIEnv * env, jobject thiz, jobject color) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor4B c = wyUtils_android::to_wyColor4B( color);
	r->setColor(c);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_VerletRope_getAlpha
  (JNIEnv * env, jobject thiz) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return r->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_VerletRope_setAlpha
  (JNIEnv * env, jobject thiz, jint a) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	r->setAlpha(a);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_utils_VerletRope_getLength
  (JNIEnv * env, jobject thiz) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return r->getLength();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_VerletRope_nativeSubRope
  (JNIEnv * env, jobject thiz, jint startPoint, jint endPoint) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)r->subRope(startPoint, endPoint);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_utils_VerletRope_isStretched
  (JNIEnv * env, jobject thiz) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return r->isStretched();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_VerletRope_changeLength
  (JNIEnv * env, jobject thiz, jfloat delta) {
	wyVerletRope* r = (wyVerletRope*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	r->changeLength(delta);
}
