#include "com_wiyun_engine_box2d_dynamics_joints_Joint.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_Joint_nativeGetBodyA
  (JNIEnv * env, jobject thiz) {
	b2Joint* j = (b2Joint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)j->GetBodyA();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_Joint_nativeGetBodyB
  (JNIEnv * env, jobject thiz) {
	b2Joint* j = (b2Joint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)j->GetBodyB();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_Joint_nativeGetAnchorA
  (JNIEnv * env, jobject thiz, jobject p) {
	b2Joint* j = (b2Joint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 v = j->GetAnchorA();
	env->SetFloatField(p, g_fid_WYPoint_x, v.x);
	env->SetFloatField(p, g_fid_WYPoint_y, v.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_Joint_nativeGetAnchorB
  (JNIEnv * env, jobject thiz, jobject p) {
	b2Joint* j = (b2Joint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 v = j->GetAnchorB();
	env->SetFloatField(p, g_fid_WYPoint_x, v.x);
	env->SetFloatField(p, g_fid_WYPoint_y, v.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_Joint_nativeGetReactionForce
  (JNIEnv * env, jobject thiz, jobject p, jfloat inv_dt) {
	b2Joint* j = (b2Joint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 v = j->GetReactionForce(inv_dt);
	env->SetFloatField(p, g_fid_WYPoint_x, v.x);
	env->SetFloatField(p, g_fid_WYPoint_y, v.y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_Joint_getReactionTorque
  (JNIEnv * env, jobject thiz, jfloat inv_dt) {
	b2Joint* j = (b2Joint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetReactionTorque(inv_dt);
}

JNIEXPORT jobject JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_Joint_getUserData
  (JNIEnv * env, jobject thiz) {
	b2Joint* j = (b2Joint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetJavaUserData();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_Joint_setUserData
  (JNIEnv * env, jobject thiz, jobject data) {
	b2Joint* j = (b2Joint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetJavaUserData(data);
}
