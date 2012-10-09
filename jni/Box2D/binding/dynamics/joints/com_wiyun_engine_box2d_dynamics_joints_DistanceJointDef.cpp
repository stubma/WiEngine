#include "com_wiyun_engine_box2d_dynamics_joints_DistanceJointDef.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJointDef_nativeNew
  (JNIEnv * env, jobject thiz) {
	b2DistanceJointDef* jd = new b2DistanceJointDef();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)jd);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJointDef_initialize
  (JNIEnv * env, jobject thiz, jobject bodyA, jobject bodyB, jfloat aX, jfloat aY, jfloat bX, jfloat bY) {
	b2DistanceJointDef* jd = (b2DistanceJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Body* ba = (b2Body*)env->GetIntField(bodyA, g_fid_BaseObject_mPointer);
	b2Body* bb = (b2Body*)env->GetIntField(bodyB, g_fid_BaseObject_mPointer);
	jd->Initialize(ba, bb, b2Vec2(aX, aY), b2Vec2(bX, bY));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJointDef_setLocalAnchorA
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2DistanceJointDef* jd = (b2DistanceJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->localAnchorA = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJointDef_setLocalAnchorB
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2DistanceJointDef* jd = (b2DistanceJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->localAnchorB = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJointDef_setLength
  (JNIEnv * env, jobject thiz, jfloat len) {
	b2DistanceJointDef* jd = (b2DistanceJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->length = len;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJointDef_getLength
  (JNIEnv * env, jobject thiz) {
	b2DistanceJointDef* jd = (b2DistanceJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->length;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJointDef_setFrequencyHz
  (JNIEnv * env, jobject thiz, jfloat f) {
	b2DistanceJointDef* jd = (b2DistanceJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->frequencyHz = f;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJointDef_getFrequencyHz
  (JNIEnv * env, jobject thiz) {
	b2DistanceJointDef* jd = (b2DistanceJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->frequencyHz;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJointDef_setDampingRatio
  (JNIEnv * env, jobject thiz, jfloat damping) {
	b2DistanceJointDef* jd = (b2DistanceJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->dampingRatio = damping;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJointDef_getDampingRatio
  (JNIEnv * env, jobject thiz) {
	b2DistanceJointDef* jd = (b2DistanceJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->dampingRatio;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJointDef_nativeGetLocalAnchorA
  (JNIEnv* env, jobject thiz, jobject a) {
	b2DistanceJointDef* jd = (b2DistanceJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAnchorA.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAnchorA.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJointDef_nativeGetLocalAnchorB
  (JNIEnv* env, jobject thiz, jobject a) {
	b2DistanceJointDef* jd = (b2DistanceJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAnchorB.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAnchorB.y);
}
