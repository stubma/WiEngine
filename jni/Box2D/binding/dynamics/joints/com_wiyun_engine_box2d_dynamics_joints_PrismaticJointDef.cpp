#include "com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_nativeNew
  (JNIEnv * env, jobject thiz) {
	b2PrismaticJointDef* jd = new b2PrismaticJointDef();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)jd);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_initialize
  (JNIEnv * env, jobject thiz, jobject bodyA, jobject bodyB, jfloat anchorX, jfloat anchorY, jfloat axisX, jfloat axisY) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Body* ba = (b2Body*)env->GetIntField(bodyA, g_fid_BaseObject_mPointer);
	b2Body* bb = (b2Body*)env->GetIntField(bodyB, g_fid_BaseObject_mPointer);
	jd->Initialize(ba, bb, b2Vec2(anchorX, anchorY), b2Vec2(axisX, axisY));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_setLocalAnchorA
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->localAnchorA = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_setLocalAnchorB
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->localAnchorB = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_setLocalAxisA
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->localAxisA = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_nativeGetLocalAnchorA
  (JNIEnv * env, jobject thiz, jobject a) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAnchorA.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAnchorA.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_nativeGetLocalAnchorB
  (JNIEnv * env, jobject thiz, jobject a) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAnchorB.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAnchorB.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_nativeGetLocalAxisA
  (JNIEnv * env, jobject thiz, jobject a) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAxisA.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAxisA.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_setReferenceAngle
  (JNIEnv * env, jobject thiz, jfloat angle) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->referenceAngle = angle;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_getReferenceAngle
  (JNIEnv * env, jobject thiz) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->referenceAngle;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_setEnableLimit
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->enableLimit = flag;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_isEnableLimit
  (JNIEnv * env, jobject thiz) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->enableLimit;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_setLowerTranslation
  (JNIEnv * env, jobject thiz, jfloat trans) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->lowerTranslation = trans;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_getLowerTranslation
  (JNIEnv * env, jobject thiz) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->lowerTranslation;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_setUpperTranslation
  (JNIEnv * env, jobject thiz, jfloat trans) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->upperTranslation = trans;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_getUpperTranslation
  (JNIEnv * env, jobject thiz) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->upperTranslation;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_setEnableMotor
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->enableMotor = flag;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_isEnableMotor
  (JNIEnv * env, jobject thiz) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->enableMotor;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_setMotorSpeed
  (JNIEnv * env, jobject thiz, jfloat speed) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->motorSpeed = speed;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_getMotorSpeed
  (JNIEnv * env, jobject thiz) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->motorSpeed;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_setMaxMotorForce
  (JNIEnv * env, jobject thiz, jfloat force) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->maxMotorForce = force;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PrismaticJointDef_getMaxMotorForce
  (JNIEnv * env, jobject thiz) {
	b2PrismaticJointDef* jd = (b2PrismaticJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->maxMotorForce;
}
