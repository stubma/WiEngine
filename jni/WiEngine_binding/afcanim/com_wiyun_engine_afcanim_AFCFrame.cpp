#include "com_wiyun_engine_afcanim_AFCFrame.h"
#include "wyAFCFrame.h"
#include "wyTypes.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCFrame_getClipCount__
  (JNIEnv * env, jobject thiz) {
	wyAFCFrame* f = (wyAFCFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->getClipCount();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCFrame_getClipCount__I
  (JNIEnv * env, jobject thiz, jint type) {
	wyAFCFrame* f = (wyAFCFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->getClipCount((wyAFCClipType)type);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCFrame_nativeGetClipAt__I
  (JNIEnv * env, jobject thiz, jint index) {
	wyAFCFrame* f = (wyAFCFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)f->getClipAt(index);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_afcanim_AFCFrame_getDelay
  (JNIEnv * env, jobject thiz) {
	wyAFCFrame* f = (wyAFCFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->getDelay();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCFrame_nativeGetIncrementation
  (JNIEnv * env, jobject thiz, jobject p) {
	wyAFCFrame* f = (wyAFCFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint inc = f->getIncrementation();
	wyUtils_android::to_WYPoint(inc, p);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCFrame_nativeGetClipAt__II
  (JNIEnv * env, jobject thiz, jint type, jint index) {
	wyAFCFrame* f = (wyAFCFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)f->getClipAt((wyAFCClipType)type, index);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_afcanim_AFCFrame_isFlipX
  (JNIEnv * env, jobject thiz) {
	wyAFCFrame* f = (wyAFCFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->isFlipX();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_afcanim_AFCFrame_isFlipY
  (JNIEnv * env, jobject thiz) {
	wyAFCFrame* f = (wyAFCFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->isFlipY();
}
