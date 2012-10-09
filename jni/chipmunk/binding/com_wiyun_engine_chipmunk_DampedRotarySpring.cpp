#include <jni.h>
#include "com_wiyun_engine_chipmunk_DampedRotarySpring.h"
#include "chipmunk.h"
#include <stdlib.h>
#include "wyJNI.h"

extern jfieldID g_fid_Body_mPointer;
extern jfieldID g_fid_Constraint_mPointer;
extern jmethodID g_mid_ITorqueUpdater_updateTorque;

static cpFloat torqueFunc(struct cpConstraint *spring, cpFloat relativeAngle) {
    JNIEnv* env = getEnv();
    if(env == NULL)
    	return 0;

	// call it
	return env->CallFloatMethod(spring->j_callback, g_mid_ITorqueUpdater_updateTorque, (jint)spring, relativeAngle);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_DampedRotarySpring_init
  (JNIEnv * env, jobject thiz, jobject b1, jobject b2, jfloat restAngle, jfloat stiffness, jfloat damping) {
	cpBody* body1 = (cpBody*)env->GetIntField(b1, g_fid_Body_mPointer);
	cpBody* body2 = (cpBody*)env->GetIntField(b2, g_fid_Body_mPointer);
	cpConstraint* constraint = cpDampedRotarySpringNew(body1, body2, restAngle, stiffness, damping);
	env->SetIntField(thiz, g_fid_Constraint_mPointer, (jint)constraint);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_DampedRotarySpring_setTorqueUpdater
  (JNIEnv * env, jobject thiz, jobject updater) {
	cpDampedRotarySpring* s = (cpDampedRotarySpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	cpConstraint* c = (cpConstraint*)s;

	if(c->j_callback != NULL) {
		env->DeleteGlobalRef(c->j_callback);
		c->j_callback = NULL;
	}

	if(updater == NULL) {
		s->springTorqueFunc = cpDampedRotarySpringUpdateTorqueDefault;
	} else {
		s->springTorqueFunc = torqueFunc;
		c->j_callback = env->NewGlobalRef(updater);
	}
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_DampedRotarySpring_getRestAngle
  (JNIEnv* env, jobject thiz) {
	cpDampedRotarySpring* s = (cpDampedRotarySpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return s->restAngle;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_DampedRotarySpring_setRestAngle
  (JNIEnv* env, jobject thiz, jfloat a) {
	cpDampedRotarySpring* s = (cpDampedRotarySpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	s->restAngle = a;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_DampedRotarySpring_getStiffness
  (JNIEnv* env, jobject thiz) {
	cpDampedRotarySpring* s = (cpDampedRotarySpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return s->stiffness;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_DampedRotarySpring_setStiffness
  (JNIEnv* env, jobject thiz, jfloat stiffness) {
	cpDampedRotarySpring* s = (cpDampedRotarySpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	s->stiffness = stiffness;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_DampedRotarySpring_getDamping
  (JNIEnv* env, jobject thiz) {
	cpDampedRotarySpring* s = (cpDampedRotarySpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return s->damping;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_DampedRotarySpring_setDamping
  (JNIEnv* env, jobject thiz, jfloat damping) {
	cpDampedRotarySpring* s = (cpDampedRotarySpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	s->damping = damping;
}
