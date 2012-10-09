#include "com_wiyun_engine_box2d_dynamics_joints_WheelJointDef.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_nativeNew
  (JNIEnv * env, jobject thiz) {
	b2WheelJointDef* jd = new b2WheelJointDef();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)jd);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_initialize
  (JNIEnv * env, jobject thiz, jobject body1, jobject body2, jfloat anchorX, jfloat anchorY, jfloat axisX, jfloat axisY) {
	b2WheelJointDef* jd = (b2WheelJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Body* ba = (b2Body*)env->GetIntField(body1, g_fid_BaseObject_mPointer);
	b2Body* bb = (b2Body*)env->GetIntField(body2, g_fid_BaseObject_mPointer);
	jd->Initialize(ba, bb, b2Vec2(anchorX, anchorY), b2Vec2(axisX, axisY));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_setLocalAnchorA
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2WheelJointDef* jd = (b2WheelJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->localAnchorA = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_setLocalAnchorB
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2WheelJointDef* jd = (b2WheelJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->localAnchorB = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_setLocalAxisA
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2WheelJointDef* jd = (b2WheelJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->localAxisA = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_setEnableMotor
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2WheelJointDef* jd = (b2WheelJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->enableMotor = flag;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_isEnableMotor
  (JNIEnv * env, jobject thiz) {
	b2WheelJointDef* jd = (b2WheelJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->enableMotor;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_setMotorSpeed
  (JNIEnv * env, jobject thiz, jfloat speed) {
	b2WheelJointDef* jd = (b2WheelJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->motorSpeed = speed;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_getMotorSpeed
  (JNIEnv * env, jobject thiz) {
	b2WheelJointDef* jd = (b2WheelJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->motorSpeed;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_setMaxMotorTorque
  (JNIEnv * env, jobject thiz, jfloat torque) {
	b2WheelJointDef* jd = (b2WheelJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->maxMotorTorque = torque;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_getMaxMotorTorque
  (JNIEnv * env, jobject thiz) {
	b2WheelJointDef* jd = (b2WheelJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->maxMotorTorque;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_nativeGetLocalAnchorA
  (JNIEnv * env, jobject thiz, jobject a) {
	b2WheelJointDef* jd = (b2WheelJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAnchorA.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAnchorA.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_nativeGetLocalAnchorB
  (JNIEnv * env, jobject thiz, jobject a) {
	b2WheelJointDef* jd = (b2WheelJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAnchorB.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAnchorB.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_nativeGetLocalAxisA
  (JNIEnv * env, jobject thiz, jobject a) {
	b2WheelJointDef* jd = (b2WheelJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAxisA.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAxisA.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_setFrequency
  (JNIEnv * env, jobject thiz, jfloat f) {
	b2WheelJointDef* jd = (b2WheelJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->frequencyHz = f;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_getFrequency
  (JNIEnv * env, jobject thiz) {
	b2WheelJointDef* jd = (b2WheelJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->frequencyHz;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_setDampingRatio
  (JNIEnv * env, jobject thiz, jfloat dr) {
	b2WheelJointDef* jd = (b2WheelJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->dampingRatio = dr;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WheelJointDef_getDampingRatio
  (JNIEnv * env, jobject thiz) {
	b2WheelJointDef* jd = (b2WheelJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->dampingRatio;
}
