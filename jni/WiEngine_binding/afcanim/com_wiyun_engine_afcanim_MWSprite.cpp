#include "com_wiyun_engine_afcanim_MWSprite.h"
#include "wyMWSprite.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_MWSprite_nativeInit__II_3Lcom_wiyun_engine_opengl_Texture2D_2
  (JNIEnv * env, jobject thiz, jint mwResId, jint animIndex, jobjectArray tex) {
	jsize len = env->GetArrayLength(tex);
	wyTexture2D* textures[len];
	for(int i = 0; i < len; i++) {
		jobject jt = (jobject)env->GetObjectArrayElement(tex, i);
		wyTexture2D* t = jt == NULL ? NULL : (wyTexture2D*)env->GetIntField(jt, g_fid_BaseObject_mPointer);
		textures[i] = t;
	}
	wyMWSprite* sprite = wyMWSprite::make(mwResId, animIndex, textures, len);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)sprite);
	sprite->retain();
	sprite->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_MWSprite_nativeInit__Ljava_lang_String_2ZI_3Lcom_wiyun_engine_opengl_Texture2D_2
  (JNIEnv * env, jobject thiz, jstring path, jboolean isFile, jint animIndex, jobjectArray tex) {
	jsize len = env->GetArrayLength(tex);
	wyTexture2D* textures[len];
	for(int i = 0; i < len; i++) {
		jobject jt = (jobject)env->GetObjectArrayElement(tex, i);
		wyTexture2D* t = jt == NULL ? NULL : (wyTexture2D*)env->GetIntField(jt, g_fid_BaseObject_mPointer);
		textures[i] = t;
	}
	const char* p = (const char*)env->GetStringUTFChars(path, NULL);
	wyMWSprite* sprite = wyMWSprite::make(p, isFile, animIndex, textures, len);
	env->ReleaseStringUTFChars(path, p);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)sprite);
	sprite->retain();
	sprite->lazyRelease();
}
