#include "com_wiyun_engine_particle_HGEParticleLoader.h"
#include "wyHGEParticleLoader.h"


extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_particle_HGEParticleLoader_nativeLoad__IILcom_wiyun_engine_opengl_Texture2D_2
  (JNIEnv* env, jclass thiz, jint resId, jint particleCount, jobject tex) {
    wyTexture2D* pTex = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
 	return (jint)wyHGEParticleLoader::load(resId, particleCount, pTex);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_particle_HGEParticleLoader_nativeLoad__Ljava_lang_String_2ILcom_wiyun_engine_opengl_Texture2D_2ZF
  (JNIEnv* env, jclass thiz, jstring path, jint particleCount, jobject tex, jboolean isFile, jfloat inDensity) {
    wyTexture2D* pTex = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	const char* filepath = (const char*)env->GetStringUTFChars(path, NULL);
	jint ret = (jint)wyHGEParticleLoader::load(filepath, particleCount, pTex, isFile, inDensity);
	env->ReleaseStringUTFChars(path, filepath);    
    return ret;
}

