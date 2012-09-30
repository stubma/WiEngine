#include "com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint_nativeGetLocalAnchorA
  (JNIEnv * env, jobject thiz, jobject p) {
	b2RevoluteJoint* j = (b2RevoluteJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, j->GetLocalAnchorA().x);
	env->SetFloatField(p, g_fid_WYPoint_y, j->GetLocalAnchorA().y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint_nativeGetLocalAnchorB
  (JNIEnv * env, jobject thiz, jobject p) {
	b2RevoluteJoint* j = (b2RevoluteJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, j->GetLocalAnchorB().x);
	env->SetFloatField(p, g_fid_WYPoint_y, j->GetLocalAnchorB().y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint_getReferenceAngle
  (JNIEnv * env, jobject thiz) {
	b2RevoluteJoint* j = (b2RevoluteJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetReferenceAngle();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint_getMaxMotorTorque
  (JNIEnv * env, jobject thiz) {
	b2RevoluteJoint* j = (b2RevoluteJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetMaxMotorTorque();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint_isMotorEnabled
  (JNIEnv * env, jobject thiz) {
	b2RevoluteJoint* j = (b2RevoluteJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->IsMotorEnabled();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint_enableMotor
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2RevoluteJoint* j = (b2RevoluteJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->EnableMotor(flag);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint_getJointAngle
  (JNIEnv * env, jobject thiz) {
	b2RevoluteJoint* j = (b2RevoluteJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetJointAngle();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint_getJointSpeed
  (JNIEnv * env, jobject thiz) {
	b2RevoluteJoint* j = (b2RevoluteJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetJointSpeed();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint_isLimitEnabled
  (JNIEnv * env, jobject thiz) {
	b2RevoluteJoint* j = (b2RevoluteJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->IsLimitEnabled();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint_enableLimit
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2RevoluteJoint* j = (b2RevoluteJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->EnableLimit(flag);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint_getLowerLimit
  (JNIEnv * env, jobject thiz) {
	b2RevoluteJoint* j = (b2RevoluteJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetLowerLimit();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint_getUpperLimit
  (JNIEnv * env, jobject thiz) {
	b2RevoluteJoint* j = (b2RevoluteJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetUpperLimit();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint_setLimits
  (JNIEnv * env, jobject thiz, jfloat lower, jfloat upper) {
	b2RevoluteJoint* j = (b2RevoluteJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetLimits(lower, upper);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint_setMotorSpeed
  (JNIEnv * env, jobject thiz, jfloat speed) {
	b2RevoluteJoint* j = (b2RevoluteJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetMotorSpeed(speed);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint_getMotorSpeed
  (JNIEnv * env, jobject thiz) {
	b2RevoluteJoint* j = (b2RevoluteJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetMotorSpeed();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint_setMaxMotorTorque
  (JNIEnv * env, jobject thiz, jfloat torque) {
	b2RevoluteJoint* j = (b2RevoluteJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetMaxMotorTorque(torque);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJoint_getMotorTorque
  (JNIEnv * env, jobject thiz, jfloat inv_dt) {
	b2RevoluteJoint* j = (b2RevoluteJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetMotorTorque(inv_dt);
}
