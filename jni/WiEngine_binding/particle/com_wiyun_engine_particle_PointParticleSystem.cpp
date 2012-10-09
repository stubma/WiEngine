#include "com_wiyun_engine_particle_PointParticleSystem.h"
#include "wyPointParticleSystem.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_PointParticleSystem_nativeInit
  (JNIEnv * env, jobject thiz, jint numberOfParticles) {
	wyPointParticleSystem* ps = WYNEW wyPointParticleSystem(numberOfParticles);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ps);
	wyObjectLazyRelease(ps);
}
