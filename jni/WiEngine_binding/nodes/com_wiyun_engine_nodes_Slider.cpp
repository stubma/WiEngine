#include "com_wiyun_engine_nodes_Slider.h"
#include "wySlider.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Slider_nativeInit
  (JNIEnv * env, jobject thiz, jobject bg, jobject bar, jobject thumb, jboolean vertical) {
	wySprite* nativeBg = bg == NULL ? NULL : (wySprite*)env->GetIntField(bg, g_fid_BaseObject_mPointer);
	wySprite* nativeBar = (wySprite*)env->GetIntField(bar, g_fid_BaseObject_mPointer);
	wySprite* nativeThumb = thumb == NULL ? NULL : (wySprite*)env->GetIntField(thumb, g_fid_BaseObject_mPointer);
	wySlider* s = WYNEW wySlider(nativeBg, nativeBar, nativeThumb, vertical);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)s);
	s->lazyRelease();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Slider_getMin
  (JNIEnv * env, jobject thiz) {
	wySlider* s = (wySlider*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return s->getMin();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Slider_setMin
  (JNIEnv * env, jobject thiz, jfloat min) {
	wySlider* s = (wySlider*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	s->setMin(min);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Slider_getMax
  (JNIEnv * env, jobject thiz) {
	wySlider* s = (wySlider*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return s->getMax();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Slider_setMax
  (JNIEnv * env, jobject thiz, jfloat max) {
	wySlider* s = (wySlider*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	s->setMax(max);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Slider_getValue
  (JNIEnv * env, jobject thiz) {
	wySlider* s = (wySlider*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return s->getValue();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Slider_setValue
  (JNIEnv * env, jobject thiz, jfloat value) {
	wySlider* s = (wySlider*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	s->setValue(value);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Slider_isShowFullBar
  (JNIEnv * env, jobject thiz) {
	wySlider* s = (wySlider*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return s->isShowFullBar();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Slider_setShowFullBar
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wySlider* s = (wySlider*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	s->setShowFullBar(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Slider_isVertical
  (JNIEnv * env, jobject thiz) {
	wySlider* s = (wySlider*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return s->isVertical();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Slider_setCallback
  (JNIEnv * env, jobject thiz, jobject callback) {
	wySlider* s = (wySlider*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	s->setCallback(callback);
}
