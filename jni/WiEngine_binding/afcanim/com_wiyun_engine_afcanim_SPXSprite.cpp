#include "com_wiyun_engine_afcanim_SPXSprite.h"
#include "wySPXSprite.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_SPXSprite_nativeInit__ILcom_wiyun_engine_opengl_Texture2D_2I
  (JNIEnv * env, jobject thiz, jint spxResId, jobject tex, jint actionIndex) {
	wyTexture2D* t = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	wySPXSprite* s = wySPXSprite::make(spxResId, t, actionIndex);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)s);
	s->retain();
	s->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_SPXSprite_nativeInit__Ljava_lang_String_2ZLcom_wiyun_engine_opengl_Texture2D_2I
  (JNIEnv * env, jobject thiz, jstring spxPath, jboolean isFile, jobject tex, jint actionIndex) {
	wyTexture2D* t = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	const char* path = (const char*)env->GetStringUTFChars(spxPath, NULL);
	wySPXSprite* s = wySPXSprite::make(path, isFile, t, actionIndex);
	env->ReleaseStringUTFChars(spxPath, path);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)s);
	s->retain();
	s->lazyRelease();
}
