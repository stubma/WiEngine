#include "com_wiyun_engine_afcanim_AFCAnimation.h"
#include "wyAFCAnimation.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCAnimation_getFrameCount
  (JNIEnv * env, jobject thiz) {
	wyAFCAnimation* anim = (wyAFCAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return anim->getFrameCount();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCAnimation_nativeGetFrameAt
  (JNIEnv * env, jobject thiz, jint index) {
	wyAFCAnimation* anim = (wyAFCAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)anim->getFrameAt(index);
}
