#include "com_wiyun_engine_afcanim_SPX3Sprite.h"
#include "wySPX3Sprite.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_SPX3Sprite_nativeInit__II_3Lcom_wiyun_engine_opengl_Texture2D_2
(JNIEnv * env, jobject thiz, jint spxResId, jint animIndex, jobjectArray tex) {
	jsize len = env->GetArrayLength(tex);
	wyTexture2D* textures[len];
	for(int i = 0; i < len; i++) {
		jobject jt = (jobject)env->GetObjectArrayElement(tex, i);
		wyTexture2D* t = jt == NULL ? NULL : (wyTexture2D*)env->GetIntField(jt, g_fid_BaseObject_mPointer);
		textures[i] = t;
	}
	wySPX3Sprite* sprite = wySPX3Sprite::make(spxResId, animIndex, textures, len);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)sprite);
	sprite->retain();
	sprite->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_SPX3Sprite_nativeInit__Ljava_lang_String_2ZI_3Lcom_wiyun_engine_opengl_Texture2D_2
(JNIEnv * env, jobject thiz, jstring spxPath, jboolean isFile, jint animIndex, jobjectArray tex) {
	jsize len = env->GetArrayLength(tex);
	wyTexture2D* textures[len];
	for(int i = 0; i < len; i++) {
		jobject jt = (jobject)env->GetObjectArrayElement(tex, i);
		wyTexture2D* t = jt == NULL ? NULL : (wyTexture2D*)env->GetIntField(jt, g_fid_BaseObject_mPointer);
		textures[i] = t;
	}
	const char* p = (const char*)env->GetStringUTFChars(spxPath, NULL);
	wySPX3Sprite* sprite = wySPX3Sprite::make(p, isFile, animIndex, textures, len);
	env->ReleaseStringUTFChars(spxPath, p);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)sprite);
	sprite->retain();
	sprite->lazyRelease();
}
