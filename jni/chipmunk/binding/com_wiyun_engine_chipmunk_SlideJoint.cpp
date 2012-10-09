#include <jni.h>
#include "com_wiyun_engine_chipmunk_SlideJoint.h"
#include "chipmunk.h"

extern jfieldID g_fid_Body_mPointer;
extern jfieldID g_fid_Constraint_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_init
  (JNIEnv * env, jobject thiz, jobject b1, jobject b2, jfloat anchor1X, jfloat anchor1Y, jfloat anchor2X, jfloat anchor2Y, jfloat min, jfloat max) {
	cpBody* body1 = (cpBody*)env->GetIntField(b1, g_fid_Body_mPointer);
	cpBody* body2 = (cpBody*)env->GetIntField(b2, g_fid_Body_mPointer);
	cpConstraint* constraint = cpSlideJointNew(body1, body2, cpv(anchor1X, anchor1Y), cpv(anchor2X, anchor2Y), min, max);
	env->SetIntField(thiz, g_fid_Constraint_mPointer, (jint)constraint);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_getMin
  (JNIEnv * env, jobject thiz) {
	cpSlideJoint* j = (cpSlideJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return j->min;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_setMin
  (JNIEnv * env, jobject thiz, jfloat min) {
	cpSlideJoint* j = (cpSlideJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	j->min = min;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_getMax
  (JNIEnv * env, jobject thiz) {
	cpSlideJoint* j = (cpSlideJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return j->max;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_setMax
  (JNIEnv * env, jobject thiz, jfloat max) {
	cpSlideJoint* j = (cpSlideJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	j->max = max;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_getAnchor1X
  (JNIEnv * env, jobject thiz) {
	cpSlideJoint* j = (cpSlideJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return j->anchr1.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_getAnchor1Y
  (JNIEnv * env, jobject thiz) {
	cpSlideJoint* j = (cpSlideJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return j->anchr1.y;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_getAnchor2X
  (JNIEnv * env, jobject thiz) {
	cpSlideJoint* j = (cpSlideJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return j->anchr2.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_getAnchor2Y
  (JNIEnv * env, jobject thiz) {
	cpSlideJoint* j = (cpSlideJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return j->anchr2.y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_setAnchor1
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	cpSlideJoint* j = (cpSlideJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	j->anchr1 = cpv(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_SlideJoint_setAnchor2
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	cpSlideJoint* j = (cpSlideJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	j->anchr2 = cpv(x, y);
}
