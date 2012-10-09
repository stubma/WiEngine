#include "com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_nativeGetLocalAnchorA
  (JNIEnv * env, jobject thiz, jobject p) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, j->GetLocalAnchorA().x);
	env->SetFloatField(p, g_fid_WYPoint_y, j->GetLocalAnchorA().y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_nativeGetLocalAnchorB
  (JNIEnv * env, jobject thiz, jobject p) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, j->GetLocalAnchorB().x);
	env->SetFloatField(p, g_fid_WYPoint_y, j->GetLocalAnchorB().y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_nativeGetLocalAxisA
  (JNIEnv * env, jobject thiz, jobject p) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, j->GetLocalAxisA().x);
	env->SetFloatField(p, g_fid_WYPoint_y, j->GetLocalAxisA().y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_getReferenceAngle
  (JNIEnv * env, jobject thiz) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetReferenceAngle();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_getMaxMotorForce
  (JNIEnv * env, jobject thiz) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetMaxMotorForce();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_isMotorEnabled
  (JNIEnv * env, jobject thiz) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->IsMotorEnabled();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_enableMotor
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->EnableMotor(flag);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_getJointTranslation
  (JNIEnv * env, jobject thiz) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetJointTranslation();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_getJointSpeed
  (JNIEnv * env, jobject thiz) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetJointSpeed();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_isLimitEnabled
  (JNIEnv * env, jobject thiz) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->IsLimitEnabled();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_enableLimit
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->EnableLimit(flag);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_getLowerLimit
  (JNIEnv * env, jobject thiz) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetLowerLimit();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_getUpperLimit
  (JNIEnv * env, jobject thiz) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetUpperLimit();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_setLimits
  (JNIEnv * env, jobject thiz, jfloat lower, jfloat upper) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetLimits(lower, upper);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_setMotorSpeed
  (JNIEnv * env, jobject thiz, jfloat speed) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetMotorSpeed(speed);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_getMotorSpeed
  (JNIEnv * env, jobject thiz) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetMotorSpeed();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_setMaxMotorForce
  (JNIEnv * env, jobject thiz, jfloat force) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetMaxMotorForce(force);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJoint_getMotorForce
  (JNIEnv * env, jobject thiz, jfloat inv_dt) {
	b2PrismaticJoint* j = (b2PrismaticJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetMotorForce(inv_dt);
}
