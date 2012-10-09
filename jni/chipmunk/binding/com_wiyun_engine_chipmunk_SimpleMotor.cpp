#include <jni.h>
#include "com_wiyun_engine_chipmunk_SimpleMotor.h"
#include "chipmunk.h"

extern jfieldID g_fid_Body_mPointer;
extern jfieldID g_fid_Constraint_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_SimpleMotor_init
  (JNIEnv * env, jobject thiz, jobject b1, jobject b2, jfloat rate) {
	cpBody* body1 = (cpBody*)env->GetIntField(b1, g_fid_Body_mPointer);
	cpBody* body2 = (cpBody*)env->GetIntField(b2, g_fid_Body_mPointer);
	cpConstraint* constraint = cpSimpleMotorNew(body1, body2, rate);
	env->SetIntField(thiz, g_fid_Constraint_mPointer, (jint)constraint);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_SimpleMotor_setRate
  (JNIEnv * env, jobject thiz, jfloat rate) {
	cpSimpleMotor* motor = (cpSimpleMotor*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	motor->rate = rate;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_SimpleMotor_getRate
  (JNIEnv * env, jobject thiz) {
	cpSimpleMotor* motor = (cpSimpleMotor*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return motor->rate;
}
