#include "com_wiyun_engine_nodes_ProgressTimer.h"
#include "wyProgressTimer.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ProgressTimer_nativeInit__Lcom_wiyun_engine_opengl_Texture2D_2
  (JNIEnv * env, jobject thiz, jobject texture) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	wyProgressTimer* timer = wyProgressTimer::make(tex);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)timer);
	timer->retain();
	timer->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ProgressTimer_nativeInit__Lcom_wiyun_engine_nodes_Sprite_2
  (JNIEnv * env, jobject thiz, jobject sprite) {
	wySprite* s = (wySprite*)env->GetIntField(sprite, g_fid_BaseObject_mPointer);
	wyProgressTimer* timer = wyProgressTimer::make(s);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)timer);
	timer->retain();
	timer->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ProgressTimer_setPercentage
  (JNIEnv * env, jobject thiz, jfloat percentage) {
	wyProgressTimer* timer = (wyProgressTimer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	timer->setPercentage(percentage);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_ProgressTimer_getPercentage
  (JNIEnv * env, jobject thiz) {
	wyProgressTimer* timer = (wyProgressTimer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return timer->getPercentage();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ProgressTimer_setSprite
  (JNIEnv * env, jobject thiz, jobject sprite) {
	wyProgressTimer* timer = (wyProgressTimer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wySprite* s = (wySprite*)env->GetIntField(sprite, g_fid_BaseObject_mPointer);
	timer->setSprite(s);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ProgressTimer_setStyle
  (JNIEnv * env, jobject thiz, jint style) {
	wyProgressTimer* timer = (wyProgressTimer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	timer->setStyle((wyProgress::Style)style);
}
