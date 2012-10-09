#include "com_wiyun_engine_particle_ParticleSystem.h"
#include "wyParticleSystem.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setDuration
  (JNIEnv * env, jobject thiz, jfloat duration) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setDuration(duration);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_particle_ParticleSystem_getDuration
  (JNIEnv * env, jobject thiz) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ps->getDuration();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_particle_ParticleSystem_getCenterOfGravityX
  (JNIEnv * env, jobject thiz) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ps->getCenterOfGravity().x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_particle_ParticleSystem_getCenterOfGravityY
  (JNIEnv * env, jobject thiz) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ps->getCenterOfGravity().y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setParticlePositionVariance
  (JNIEnv * env, jobject thiz, jfloat baseX, jfloat baseY, jfloat varianceX, jfloat varianceY) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setParticlePositionVariance(baseX, baseY, varianceX, varianceY);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setDirectionAngleVariance
  (JNIEnv * env, jobject thiz, jfloat base, jfloat variance) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setDirectionAngleVariance(base, variance);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setStartSizeVariance
  (JNIEnv * env, jobject thiz, jfloat base, jfloat variance) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setStartSizeVariance(base, variance);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setEndSizeVariance
  (JNIEnv * env, jobject thiz, jfloat base, jfloat variance) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setEndSizeVariance(base, variance);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setLifeVariance
  (JNIEnv * env, jobject thiz, jfloat base, jfloat variance) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setLifeVariance(base, variance);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setStartColorVariance
  (JNIEnv * env, jobject thiz, jfloat baseR, jfloat baseG, jfloat baseB, jfloat baseA, jfloat varR, jfloat varG, jfloat varB, jfloat varA) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setStartColorVariance(baseR, baseG, baseB, baseA, varR, varG, varB, varA);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setEndColorVariance
  (JNIEnv * env, jobject thiz, jfloat baseR, jfloat baseG, jfloat baseB, jfloat baseA, jfloat varR, jfloat varG, jfloat varB, jfloat varA) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setEndColorVariance(baseR, baseG, baseB, baseA, varR, varG, varB, varA);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setStartSpinVariance
  (JNIEnv * env, jobject thiz, jfloat base, jfloat variance) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setStartSpinVariance(base, variance);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setEndSpinVariance
  (JNIEnv * env, jobject thiz, jfloat base, jfloat variance) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setEndSpinVariance(base, variance);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setSpeedVariance
  (JNIEnv * env, jobject thiz, jfloat base, jfloat variance) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setSpeedVariance(base, variance);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setParticleGravity
  (JNIEnv * env, jobject thiz, jfloat gravityX, jfloat gravityY) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setParticleGravity(gravityX, gravityY);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setTangentialAccelerationVariance
  (JNIEnv * env, jobject thiz, jfloat base, jfloat variance) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setTangentialAccelerationVariance(base, variance);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setRadialAccelerationVariance
  (JNIEnv * env, jobject thiz, jfloat base, jfloat variance) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setRadialAccelerationVariance(base, variance);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setStartRadiusVariance
  (JNIEnv * env, jobject thiz, jfloat base, jfloat variance) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setStartRadiusVariance(base, variance);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setEndRadiusVariance
  (JNIEnv * env, jobject thiz, jfloat base, jfloat variance) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setEndRadiusVariance(base, variance);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setRotationVariance
  (JNIEnv * env, jobject thiz, jfloat base, jfloat variance) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setRotationVariance(base, variance);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_particle_ParticleSystem_getParticleCount
  (JNIEnv * env, jobject thiz) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ps->getParticleCount();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_particle_ParticleSystem_getMaxParticleCount
  (JNIEnv * env, jobject thiz) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ps->getMaxParticles();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_stopSystem
  (JNIEnv * env, jobject thiz) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->stopSystem();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_resetSystem
  (JNIEnv * env, jobject thiz) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->resetSystem();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_particle_ParticleSystem_nativeGetTexture
  (JNIEnv * env, jobject thiz) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)ps->getTexture();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setTexture
  (JNIEnv * env, jobject thiz, jobject texture) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	ps->setTexture(tex);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_particle_ParticleSystem_getBlendFuncSrc
  (JNIEnv * env, jobject thiz) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ps->getBlendFunc().src;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_particle_ParticleSystem_getBlendFuncDst
  (JNIEnv * env, jobject thiz) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ps->getBlendFunc().dst;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setBlendFunc
  (JNIEnv * env, jobject thiz, jint src, jint dst) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyBlendFunc func = { src, dst };
	ps->setBlendFunc(func);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setBlendAdditive
  (JNIEnv * env, jobject thiz, jboolean additive) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setBlendAdditive(additive);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_particle_ParticleSystem_isBlendAdditive
  (JNIEnv * env, jobject thiz) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ps->isBlendAdditive();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_particle_ParticleSystem_getPositionType
  (JNIEnv * env, jobject thiz) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ps->getPositionType();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setPositionType
  (JNIEnv * env, jobject thiz, jint t) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setPositionType((wyParticleSystemPositionType)t);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_particle_ParticleSystem_getEmitterMode
  (JNIEnv * env, jobject thiz) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ps->getEmitterMode();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setEmitterMode
  (JNIEnv * env, jobject thiz, jint m) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setEmitterMode((wyParticleSystemMode)m);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_particle_ParticleSystem_getEmissionRate
  (JNIEnv * env, jobject thiz) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ps->getEmissionRate();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setEmissionRate
  (JNIEnv * env, jobject thiz, jfloat r) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setEmissionRate(r);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_particle_ParticleSystem_isAutoRemoveOnFinish
  (JNIEnv * env, jobject thiz) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ps->isAutoRemoveOnFinish();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_particle_ParticleSystem_setAutoRemoveOnFinish
  (JNIEnv * env, jobject thiz, jboolean a) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->setAutoRemoveOnFinish(a);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_particle_ParticleSystem_getLife
  (JNIEnv * env, jobject thiz) {
	wyParticleSystem* ps = (wyParticleSystem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ps->getLife();
}
