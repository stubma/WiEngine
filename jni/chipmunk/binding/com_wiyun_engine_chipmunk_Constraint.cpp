#include <jni.h>
#include "com_wiyun_engine_chipmunk_Constraint.h"
#include "chipmunk.h"


extern jfieldID g_fid_Constraint_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Constraint_destroy
  (JNIEnv * env, jobject thiz) {
	cpConstraint* constraint = (cpConstraint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	cpConstraintFree(constraint);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Constraint_setMaxForce
  (JNIEnv * env, jobject thiz, jfloat maxForce) {
	cpConstraint* constraint = (cpConstraint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	constraint->maxForce = maxForce;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Constraint_getMaxForce
  (JNIEnv * env, jobject thiz) {
	cpConstraint* constraint = (cpConstraint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return constraint->maxForce;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Constraint_setBias
  (JNIEnv * env, jobject thiz, jfloat bias) {
	cpConstraint* constraint = (cpConstraint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	constraint->biasCoef = bias;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Constraint_getBias
  (JNIEnv * env, jobject thiz) {
	cpConstraint* constraint = (cpConstraint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return constraint->biasCoef;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Constraint_setMaxBias
  (JNIEnv * env, jobject thiz, jfloat max) {
	cpConstraint* constraint = (cpConstraint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	constraint->maxBias = max;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Constraint_getMaxBias
  (JNIEnv * env, jobject thiz) {
	cpConstraint* constraint = (cpConstraint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return constraint->maxBias;
}
