#include "com_wiyun_engine_particle_ParticleLoader.h"
#include "wyParticleLoader.h"

JNIEXPORT jint JNICALL Java_com_wiyun_engine_particle_ParticleLoader_nativeLoad__I
  (JNIEnv * env, jclass clazz, jint resId) {
	return (jint)wyParticleLoader::load(resId);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_particle_ParticleLoader_nativeLoad__Ljava_lang_String_2ZF
  (JNIEnv * env, jclass clazz, jstring path, jboolean isFile, jfloat inDensity) {
	const char* p = (const char*)env->GetStringUTFChars(path, NULL);
	jint ret = (jint)wyParticleLoader::load(p, (bool)isFile, inDensity);
	env->ReleaseStringUTFChars(path, p);
	return ret;
}
