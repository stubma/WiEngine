#include "com_wiyun_engine_box2d_dynamics_joints_FrictionJointDef.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_FrictionJointDef_nativeNew
  (JNIEnv * env, jobject thiz) {
	b2FrictionJointDef* jd = new b2FrictionJointDef();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)jd);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_FrictionJointDef_setLocalAnchorA
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2FrictionJointDef* d = (b2FrictionJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	d->localAnchorA = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_FrictionJointDef_setLocalAnchorB
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2FrictionJointDef* d = (b2FrictionJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	d->localAnchorB = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_FrictionJointDef_setMaxForce
  (JNIEnv * env, jobject thiz, jfloat maxForce) {
	b2FrictionJointDef* d = (b2FrictionJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	d->maxForce = maxForce;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_FrictionJointDef_getMaxForce
  (JNIEnv * env, jobject thiz) {
	b2FrictionJointDef* d = (b2FrictionJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return d->maxForce;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_FrictionJointDef_setMaxTorque
  (JNIEnv * env, jobject thiz, jfloat maxTorque) {
	b2FrictionJointDef* d = (b2FrictionJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	d->maxTorque = maxTorque;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_FrictionJointDef_getMaxTorque
  (JNIEnv * env, jobject thiz) {
	b2FrictionJointDef* d = (b2FrictionJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return d->maxTorque;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_FrictionJointDef_nativeGetLocalAnchorA
  (JNIEnv * env, jobject thiz, jobject a) {
	b2FrictionJointDef* jd = (b2FrictionJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAnchorA.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAnchorA.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_FrictionJointDef_nativeGetLocalAnchorB
  (JNIEnv * env, jobject thiz, jobject a) {
	b2FrictionJointDef* jd = (b2FrictionJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAnchorB.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAnchorB.y);
}
