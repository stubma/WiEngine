#include "com_wiyun_engine_particle_QuadParticleSystem.h"
#include "wyQuadParticleSystem.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_QuadParticleSystem_nativeInit
  (JNIEnv * env, jobject thiz, jint numberOfParticles) {
	wyQuadParticleSystem* ps = WYNEW wyQuadParticleSystem(numberOfParticles);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ps);
	wyObjectLazyRelease(ps);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_QuadParticleSystem_setTexture
  (JNIEnv * env, jobject thiz, jobject texture, jobject rect) {
	wyQuadParticleSystem* ps = (wyQuadParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	wyRect r = wyUtils_android::to_wyRect( rect);
	ps->setTexture(tex, r);
}
