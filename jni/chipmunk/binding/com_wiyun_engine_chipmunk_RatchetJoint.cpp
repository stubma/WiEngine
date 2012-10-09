#include <jni.h>
#include "com_wiyun_engine_chipmunk_RatchetJoint.h"
#include "chipmunk.h"

extern jfieldID g_fid_Body_mPointer;
extern jfieldID g_fid_Constraint_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_RatchetJoint_init
  (JNIEnv * env, jobject thiz, jobject b1, jobject b2, jfloat phase, jfloat ratchet) {
	cpBody* body1 = (cpBody*)env->GetIntField(b1, g_fid_Body_mPointer);
	cpBody* body2 = (cpBody*)env->GetIntField(b2, g_fid_Body_mPointer);
	cpConstraint* constraint = cpRatchetJointNew(body1, body2, phase, ratchet);
	env->SetIntField(thiz, g_fid_Constraint_mPointer, (jint)constraint);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_RatchetJoint_getAngle
  (JNIEnv * env, jobject thiz) {
	cpRatchetJoint* j = (cpRatchetJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return j->angle;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_RatchetJoint_setAngle
  (JNIEnv * env, jobject thiz, jfloat a) {
	cpRatchetJoint* j = (cpRatchetJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	j->angle = a;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_RatchetJoint_getPhase
  (JNIEnv * env, jobject thiz) {
	cpRatchetJoint* j = (cpRatchetJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return j->phase;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_RatchetJoint_setPhase
  (JNIEnv * env, jobject thiz, jfloat phase) {
	cpRatchetJoint* j = (cpRatchetJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	j->phase = phase;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_RatchetJoint_getRatchet
  (JNIEnv * env, jobject thiz) {
	cpRatchetJoint* j = (cpRatchetJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return j->ratchet;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_RatchetJoint_setRatchet
  (JNIEnv * env, jobject thiz, jfloat ratchet) {
	cpRatchetJoint* j = (cpRatchetJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	j->ratchet = ratchet;
}
