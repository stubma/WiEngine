#include "com_wiyun_engine_nodes_RenderTexture.h"
#include "wyRenderTexture.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_RenderTexture_nativeInit__
  (JNIEnv * env, jobject thiz) {
	wyRenderTexture* rt = wyRenderTexture::make();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)rt);
	rt->retain();
	rt->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_RenderTexture_nativeInit__II
  (JNIEnv * env, jobject thiz, jint width, jint height) {
	wyRenderTexture* rt = wyRenderTexture::make(width, height);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)rt);
	rt->retain();
	rt->lazyRelease();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_RenderTexture_nativeCreateTexture
(JNIEnv * env, jobject thiz) {
	wyRenderTexture* rt = (wyRenderTexture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)rt->createTexture();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_RenderTexture_beginRender__FFFF
  (JNIEnv * env, jobject thiz, jfloat r, jfloat g, jfloat b, jfloat a) {
	wyRenderTexture* rt = (wyRenderTexture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	rt->beginRender(r, g, b, a);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_RenderTexture_clear
  (JNIEnv * env, jobject thiz, jfloat r, jfloat g, jfloat b, jfloat a) {
	wyRenderTexture* rt = (wyRenderTexture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	rt->clear(r, g, b, a);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_RenderTexture_beginRender__
  (JNIEnv * env, jobject thiz) {
	wyRenderTexture* rt = (wyRenderTexture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	rt->beginRender();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_RenderTexture_endRender
  (JNIEnv * env, jobject thiz) {
	wyRenderTexture* rt = (wyRenderTexture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	rt->endRender();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_RenderTexture_getBlendFuncSrc
  (JNIEnv * env, jobject thiz) {
	wyRenderTexture* rt = (wyRenderTexture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return rt->getBlendFunc().src;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_RenderTexture_getBlendFuncDst
  (JNIEnv * env, jobject thiz) {
	wyRenderTexture* rt = (wyRenderTexture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return rt->getBlendFunc().dst;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_RenderTexture_nativeSetBlendFunc
  (JNIEnv * env, jobject thiz, jint src, jint dst) {
	wyRenderTexture* rt = (wyRenderTexture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyBlendFunc func = { src, dst };
	rt->setBlendFunc(func);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_RenderTexture_getAlpha
  (JNIEnv * env, jobject thiz) {
	wyRenderTexture* rt = (wyRenderTexture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return rt->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_RenderTexture_setAlpha
  (JNIEnv * env, jobject thiz, jint alpha) {
	wyRenderTexture* rt = (wyRenderTexture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	rt->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_RenderTexture_nativeGetColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyRenderTexture* rt = (wyRenderTexture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = rt->getColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_RenderTexture_nativeSetColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyRenderTexture* rt = (wyRenderTexture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = { r, g, b };
	rt->setColor(c);
}
