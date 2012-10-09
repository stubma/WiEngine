#include "com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_nativeNew
  (JNIEnv * env, jobject thiz) {
	b2RevoluteJointDef* jd = new b2RevoluteJointDef();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)jd);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_initialize
  (JNIEnv * env, jobject thiz, jobject bodyA, jobject bodyB, jfloat anchorX, jfloat anchorY) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Body* ba = (b2Body*)env->GetIntField(bodyA, g_fid_BaseObject_mPointer);
	b2Body* bb = (b2Body*)env->GetIntField(bodyB, g_fid_BaseObject_mPointer);
	jd->Initialize(ba, bb, b2Vec2(anchorX, anchorY));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_setLocalAnchorA__FF
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->localAnchorA = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_setLocalAnchorA__Lcom_wiyun_engine_types_WYPoint_2
  (JNIEnv * env, jobject thiz, jobject a) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float x = env->GetFloatField(a, g_fid_WYPoint_x);
	float y = env->GetFloatField(a, g_fid_WYPoint_y);
	jd->localAnchorA = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_setLocalAnchorB__FF
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->localAnchorB = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_setLocalAnchorB__Lcom_wiyun_engine_types_WYPoint_2
  (JNIEnv * env, jobject thiz, jobject a) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float x = env->GetFloatField(a, g_fid_WYPoint_x);
	float y = env->GetFloatField(a, g_fid_WYPoint_y);
	jd->localAnchorB = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_nativeGetLocalAnchorA
  (JNIEnv * env, jobject thiz, jobject a) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAnchorA.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAnchorA.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_nativeGetLocalAnchorB
  (JNIEnv * env, jobject thiz, jobject a) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAnchorB.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAnchorB.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_setReferenceAngle
  (JNIEnv * env, jobject thiz, jfloat angle) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->referenceAngle = angle;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_getReferenceAngle
  (JNIEnv * env, jobject thiz) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->referenceAngle;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_setEnableLimit
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->enableLimit = flag;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_isEnableLimit
  (JNIEnv * env, jobject thiz) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->enableLimit;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_setLowerAngle
  (JNIEnv * env, jobject thiz, jfloat angle) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->lowerAngle = angle;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_getLowerAngle
  (JNIEnv * env, jobject thiz) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->lowerAngle;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_setUpperAngle
  (JNIEnv * env, jobject thiz, jfloat angle) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->upperAngle = angle;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_getUpperAngle
  (JNIEnv * env, jobject thiz) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->upperAngle;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_setEnableMotor
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->enableMotor = flag;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_isEnableMotor
  (JNIEnv * env, jobject thiz) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->enableMotor;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_setMotorSpeed
  (JNIEnv * env, jobject thiz, jfloat speed) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->motorSpeed = speed;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_getMotorSpeed
  (JNIEnv * env, jobject thiz) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->motorSpeed;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_setMaxMotorTorque
  (JNIEnv * env, jobject thiz, jfloat torque) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->maxMotorTorque = torque;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RevoluteJointDef_getMaxMotorTorque
  (JNIEnv * env, jobject thiz) {
	b2RevoluteJointDef* jd = (b2RevoluteJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->maxMotorTorque;
}
