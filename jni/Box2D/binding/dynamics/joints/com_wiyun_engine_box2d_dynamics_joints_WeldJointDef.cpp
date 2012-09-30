#include "com_wiyun_engine_box2d_dynamics_joints_WeldJointDef.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WeldJointDef_nativeNew
  (JNIEnv * env, jobject thiz) {
	b2WeldJointDef* jd = new b2WeldJointDef();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)jd);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WeldJointDef_initialize
  (JNIEnv * env, jobject thiz, jobject body1, jobject body2, jfloat anchorX, jfloat anchorY) {
	b2WeldJointDef* jd = (b2WeldJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Body* ba = (b2Body*)env->GetIntField(body1, g_fid_BaseObject_mPointer);
	b2Body* bb = (b2Body*)env->GetIntField(body2, g_fid_BaseObject_mPointer);
	jd->Initialize(ba, bb, b2Vec2(anchorX, anchorY));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WeldJointDef_setLocalAnchorA
  (JNIEnv* env, jobject thiz, jobject a) {
	b2WeldJointDef* jd = (b2WeldJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float x = env->GetFloatField(a, g_fid_WYPoint_x);
	float y = env->GetFloatField(a, g_fid_WYPoint_y);
	jd->localAnchorA = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WeldJointDef_setLocalAnchorB
  (JNIEnv* env, jobject thiz, jobject a) {
	b2WeldJointDef* jd = (b2WeldJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float x = env->GetFloatField(a, g_fid_WYPoint_x);
	float y = env->GetFloatField(a, g_fid_WYPoint_y);
	jd->localAnchorB = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WeldJointDef_nativeGetLocalAnchorA
  (JNIEnv * env, jobject thiz, jobject a) {
	b2WeldJointDef* jd = (b2WeldJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAnchorA.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAnchorA.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WeldJointDef_nativeGetLocalAnchorB
  (JNIEnv * env, jobject thiz, jobject a) {
	b2WeldJointDef* jd = (b2WeldJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAnchorB.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAnchorB.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WeldJointDef_setReferenceAngle
  (JNIEnv * env, jobject thiz, jfloat angle) {
	b2WeldJointDef* jd = (b2WeldJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->referenceAngle = angle;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WeldJointDef_getReferenceAngle
  (JNIEnv * env, jobject thiz) {
	b2WeldJointDef* jd = (b2WeldJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->referenceAngle;
}
