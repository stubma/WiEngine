#include <jni.h>
#include "com_wiyun_engine_chipmunk_PinJoint.h"
#include "chipmunk.h"

extern jfieldID g_fid_Body_mPointer;
extern jfieldID g_fid_Constraint_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_PinJoint_init
	(JNIEnv * env, jobject thiz, jobject b1, jobject b2, jfloat anchor1X, jfloat anchor1Y, jfloat anchor2X, jfloat anchor2Y) {
	cpBody* body1 = (cpBody*)env->GetIntField(b1, g_fid_Body_mPointer);
	cpBody* body2 = (cpBody*)env->GetIntField(b2, g_fid_Body_mPointer);
	cpConstraint* constraint = cpPinJointNew(body1, body2, cpv(anchor1X, anchor1Y), cpv(anchor2X, anchor2Y));
	env->SetIntField(thiz, g_fid_Constraint_mPointer, (jint)constraint);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_PinJoint_setDistance
(JNIEnv * env, jobject thiz, jfloat distance) {
	cpPinJoint* pin = (cpPinJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	pin->dist = distance;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_PinJoint_getDistance
  (JNIEnv * env, jobject thiz) {
	cpPinJoint* pin = (cpPinJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return pin->dist;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_PinJoint_getAnchor1X
  (JNIEnv * env, jobject thiz) {
	cpPinJoint* pin = (cpPinJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return pin->anchr1.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_PinJoint_getAnchor1Y
  (JNIEnv * env, jobject thiz) {
	cpPinJoint* pin = (cpPinJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return pin->anchr1.y;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_PinJoint_getAnchor2X
  (JNIEnv * env, jobject thiz) {
	cpPinJoint* pin = (cpPinJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return pin->anchr2.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_PinJoint_getAnchor2Y
  (JNIEnv * env, jobject thiz) {
	cpPinJoint* pin = (cpPinJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return pin->anchr2.y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_PinJoint_setAnchor1
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	cpPinJoint* pin = (cpPinJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	pin->anchr1 = cpv(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_PinJoint_setAnchor2
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	cpPinJoint* pin = (cpPinJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	pin->anchr2 = cpv(x, y);
}
