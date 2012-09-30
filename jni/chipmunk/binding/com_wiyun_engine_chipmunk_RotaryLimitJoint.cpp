#include <jni.h>
#include "com_wiyun_engine_chipmunk_RotaryLimitJoint.h"
#include "chipmunk.h"

extern jfieldID g_fid_Body_mPointer;
extern jfieldID g_fid_Constraint_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_RotaryLimitJoint_init
  (JNIEnv * env, jobject thiz, jobject b1, jobject b2, jfloat min, jfloat max) {
	cpBody* body1 = (cpBody*)env->GetIntField(b1, g_fid_Body_mPointer);
	cpBody* body2 = (cpBody*)env->GetIntField(b2, g_fid_Body_mPointer);
	cpConstraint* constraint = cpRotaryLimitJointNew(body1, body2, min, max);
	env->SetIntField(thiz, g_fid_Constraint_mPointer, (jint)constraint);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_RotaryLimitJoint_getMin
  (JNIEnv * env, jobject thiz) {
	cpRotaryLimitJoint* j = (cpRotaryLimitJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return j->min;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_RotaryLimitJoint_setMin
  (JNIEnv * env, jobject thiz, jfloat min) {
	cpRotaryLimitJoint* j = (cpRotaryLimitJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	j->min = min;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_RotaryLimitJoint_getMax
  (JNIEnv * env, jobject thiz) {
	cpRotaryLimitJoint* j = (cpRotaryLimitJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return j->max;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_RotaryLimitJoint_setMax
  (JNIEnv * env, jobject thiz, jfloat max) {
	cpRotaryLimitJoint* j = (cpRotaryLimitJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	j->max = max;
}
