#include "com_wiyun_engine_opengl_TextureManager.h"
#include "wyTextureManager.h"
#include <stdint.h>

extern jfieldID g_fid_BaseObject_mPointer;
extern wyTextureManager* gTextureManager;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_TextureManager_nativeGetInstance
  (JNIEnv * env, jclass clazz) {
	return (jint)gTextureManager;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureManager_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyTextureManager* tm = wyTextureManager::getInstance();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)tm);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_TextureManager_getTextureCount
  (JNIEnv * env, jobject thiz) {
	wyTextureManager* tm = wyTextureManager::getInstance();
	return tm->getTextureCount();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureManager_removeAllTextures
  (JNIEnv * env, jobject thiz) {
	wyTextureManager* tm = (wyTextureManager*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	tm->removeAllTextures();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureManager_removeTexture__I
  (JNIEnv * env, jobject thiz, jint resId) {
	wyTextureManager* tm = (wyTextureManager*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	tm->removeTexture(resId);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureManager_removeTexture__Ljava_lang_String_2
  (JNIEnv * env, jobject thiz, jstring name) {
	wyTextureManager* tm = (wyTextureManager*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* n = (const char*)env->GetStringUTFChars(name, NULL);
	tm->removeTexture(n);
	env->ReleaseStringUTFChars(name, n);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureManager_removeTexture__Lcom_wiyun_engine_opengl_Texture2D_2Z
  (JNIEnv * env, jobject thiz, jobject tex, jboolean permanentDelete) {
	wyTextureManager* tm = (wyTextureManager*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTexture2D* t = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	tm->removeTexture(t, permanentDelete);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureManager_setTexturePixelFormat
  (JNIEnv * env, jobject thiz, jint format) {
	wyTextureManager* tm = (wyTextureManager*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	tm->setTexturePixelFormat((wyTexturePixelFormat)format);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_TextureManager_getTexturePixelFormat
  (JNIEnv * env, jobject thiz) {
	wyTextureManager* tm = (wyTextureManager*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)tm->getTexturePixelFormat();
}
