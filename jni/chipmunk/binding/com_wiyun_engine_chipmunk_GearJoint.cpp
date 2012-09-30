#include <jni.h>
#include "com_wiyun_engine_chipmunk_GearJoint.h"
#include "chipmunk.h"

extern jfieldID g_fid_Body_mPointer;
extern jfieldID g_fid_Constraint_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_GearJoint_init
  (JNIEnv * env, jobject thiz, jobject b1, jobject b2, jfloat phase, jfloat ratio) {
	cpBody* body1 = (cpBody*)env->GetIntField(b1, g_fid_Body_mPointer);
	cpBody* body2 = (cpBody*)env->GetIntField(b2, g_fid_Body_mPointer);
	cpConstraint* constraint = cpGearJointNew(body1, body2, phase, ratio);
	env->SetIntField(thiz, g_fid_Constraint_mPointer, (jint)constraint);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_GearJoint_getRatio
  (JNIEnv * env, jobject thiz) {
	cpGearJoint* gj = (cpGearJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return gj->ratio;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_GearJoint_setRatio
  (JNIEnv * env, jobject thiz, jfloat ratio) {
	cpConstraint* gj = (cpConstraint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	cpGearJointSetRatio(gj, ratio);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_GearJoint_getPhase
  (JNIEnv * env, jobject thiz) {
	cpGearJoint* gj = (cpGearJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return gj->phase;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_GearJoint_setPhase
  (JNIEnv * env, jobject thiz, jfloat phase) {
	cpGearJoint* gj = (cpGearJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	gj->phase = phase;
}
