#include "com_wiyun_engine_box2d_dynamics_joints_WheelJoint.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJoint_nativeGetLocalAnchorA
  (JNIEnv * env, jobject thiz, jobject p) {
	b2WheelJoint* j = (b2WheelJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, j->GetLocalAnchorA().x);
	env->SetFloatField(p, g_fid_WYPoint_y, j->GetLocalAnchorA().y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJoint_nativeGetLocalAnchorB
  (JNIEnv * env, jobject thiz, jobject p) {
	b2WheelJoint* j = (b2WheelJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, j->GetLocalAnchorB().x);
	env->SetFloatField(p, g_fid_WYPoint_y, j->GetLocalAnchorB().y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJoint_nativeGetLocalAxisA
  (JNIEnv * env, jobject thiz, jobject p) {
	b2WheelJoint* j = (b2WheelJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, j->GetLocalAxisA().x);
	env->SetFloatField(p, g_fid_WYPoint_y, j->GetLocalAxisA().y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJoint_getJointTranslation
  (JNIEnv * env, jobject thiz) {
	b2WheelJoint* j = (b2WheelJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetJointTranslation();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJoint_getJointSpeed
  (JNIEnv * env, jobject thiz) {
	b2WheelJoint* j = (b2WheelJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetJointSpeed();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJoint_isMotorEnabled
  (JNIEnv * env, jobject thiz) {
	b2WheelJoint* j = (b2WheelJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->IsMotorEnabled();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJoint_enableMotor
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2WheelJoint* j = (b2WheelJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->EnableMotor(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJoint_setMotorSpeed
  (JNIEnv * env, jobject thiz, jfloat speed) {
	b2WheelJoint* j = (b2WheelJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetMotorSpeed(speed);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJoint_getMotorSpeed
  (JNIEnv * env, jobject thiz) {
	b2WheelJoint* j = (b2WheelJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetMotorSpeed();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJoint_setMaxMotorTorque
  (JNIEnv * env, jobject thiz, jfloat torque) {
	b2WheelJoint* j = (b2WheelJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->SetMaxMotorTorque(torque);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJoint_getMaxMotorTorque
  (JNIEnv * env, jobject thiz) {
	b2WheelJoint* j = (b2WheelJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetMaxMotorTorque();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJoint_getMotorTorque
  (JNIEnv * env, jobject thiz, jfloat inv_dt) {
	b2WheelJoint* j = (b2WheelJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetMotorTorque(inv_dt);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJoint_setSpringFrequencyHz
  (JNIEnv * env, jobject thiz, jfloat f) {
	b2WheelJoint* j = (b2WheelJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetSpringFrequencyHz(f);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJoint_getSpringFrequencyHz
  (JNIEnv * env, jobject thiz) {
	b2WheelJoint* j = (b2WheelJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetSpringFrequencyHz();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJoint_setSpringDampingRatio
  (JNIEnv * env, jobject thiz, jfloat dr) {
	b2WheelJoint* j = (b2WheelJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetSpringDampingRatio(dr);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJoint_getSpringDampingRatio
  (JNIEnv * env, jobject thiz) {
	b2WheelJoint* j = (b2WheelJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetSpringDampingRatio();
}
