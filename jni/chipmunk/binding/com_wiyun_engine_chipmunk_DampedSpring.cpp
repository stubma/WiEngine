#include <jni.h>
#include "com_wiyun_engine_chipmunk_DampedSpring.h"
#include "chipmunk.h"
#include <stdlib.h>
#include "wyJNI.h"

extern jfieldID g_fid_Body_mPointer;
extern jfieldID g_fid_Constraint_mPointer;
extern jmethodID g_mid_IForceUpdater_updateForce;

static cpFloat forceFunc(struct cpConstraint* spring, cpFloat dist) {
    JNIEnv* env = getEnv();
    if(env == NULL)
    	return 0;

	return env->CallFloatMethod(spring->j_callback, g_mid_IForceUpdater_updateForce, spring, dist);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_DampedSpring_init
  (JNIEnv * env, jobject thiz, jobject b1, jobject b2, jfloat anchor1X, jfloat anchor1Y, jfloat anchor2X, jfloat anchor2Y, jfloat restLength, jfloat stiffness, jfloat damping) {
	cpBody* body1 = (cpBody*)env->GetIntField(b1, g_fid_Body_mPointer);
	cpBody* body2 = (cpBody*)env->GetIntField(b2, g_fid_Body_mPointer);
	cpConstraint* constraint = cpDampedSpringNew(body1, body2, cpv(anchor1X, anchor1Y), cpv(anchor2X, anchor2Y), restLength, stiffness, damping);
	env->SetIntField(thiz, g_fid_Constraint_mPointer, (jint)constraint);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_DampedSpring_setForceUpdater
  (JNIEnv * env, jobject thiz, jobject updater) {
	cpDampedSpring* s = (cpDampedSpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	cpConstraint* c = (cpConstraint*)s;

	if(c->j_callback != NULL) {
		env->DeleteGlobalRef(c->j_callback);
		c->j_callback = NULL;
	}

	if(updater == NULL) {
		s->springForceFunc = cpDampedSpringUpdateForceDefault;
	} else {
		s->springForceFunc = forceFunc;
		c->j_callback = env->NewGlobalRef(updater);
	}
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_DampedSpring_getRestLength
   (JNIEnv * env, jobject thiz) {
	cpDampedSpring* spring = (cpDampedSpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return spring->restLength;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_DampedSpring_getStiffness
  (JNIEnv * env, jobject thiz) {
	cpDampedSpring* spring = (cpDampedSpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return spring->stiffness;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_DampedSpring_getDamping
  (JNIEnv * env, jobject thiz) {
	cpDampedSpring* spring = (cpDampedSpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return spring->damping;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_DampedSpring_setRestLength
  (JNIEnv * env, jobject thiz, jfloat len) {
	cpDampedSpring* s = (cpDampedSpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	s->restLength = len;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_DampedSpring_setStiffness
  (JNIEnv * env, jobject thiz, jfloat stiffness) {
	cpDampedSpring* s = (cpDampedSpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	s->stiffness = stiffness;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_DampedSpring_setDamping
  (JNIEnv * env, jobject thiz, jfloat damping) {
	cpDampedSpring* s = (cpDampedSpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	s->damping = damping;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_DampedSpring_getAnchor1X
  (JNIEnv * env, jobject thiz) {
	cpDampedSpring* s = (cpDampedSpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return s->anchr1.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_DampedSpring_getAnchor1Y
  (JNIEnv * env, jobject thiz) {
	cpDampedSpring* s = (cpDampedSpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return s->anchr1.y;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_DampedSpring_getAnchor2X
  (JNIEnv * env, jobject thiz) {
	cpDampedSpring* s = (cpDampedSpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return s->anchr2.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_DampedSpring_getAnchor2Y
  (JNIEnv * env, jobject thiz) {
	cpDampedSpring* s = (cpDampedSpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return s->anchr2.y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_DampedSpring_setAnchor1
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	cpDampedSpring* s = (cpDampedSpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	s->anchr1 = cpv(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_DampedSpring_setAnchor2
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	cpDampedSpring* s = (cpDampedSpring*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	s->anchr2 = cpv(x, y);
}
