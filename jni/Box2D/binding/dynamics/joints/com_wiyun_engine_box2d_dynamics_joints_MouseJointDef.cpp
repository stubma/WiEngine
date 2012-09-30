#include "com_wiyun_engine_box2d_dynamics_joints_MouseJointDef.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_MouseJointDef_nativeNew
  (JNIEnv * env, jobject thiz) {
	b2MouseJointDef* mjd = new b2MouseJointDef();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)mjd);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_MouseJointDef_setTarget
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2MouseJointDef* d = (b2MouseJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	d->target = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_MouseJointDef_nativeGetTarget
  (JNIEnv * env, jobject thiz, jobject a) {
	b2MouseJointDef* jd = (b2MouseJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->target.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->target.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_MouseJointDef_setMaxForce
  (JNIEnv * env, jobject thiz, jfloat maxForce) {
	b2MouseJointDef* d = (b2MouseJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	d->maxForce = maxForce;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_MouseJointDef_getMaxForce
  (JNIEnv * env, jobject thiz) {
	b2MouseJointDef* d = (b2MouseJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return d->maxForce;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_MouseJointDef_setFrequencyHz
  (JNIEnv * env, jobject thiz, jfloat f) {
	b2MouseJointDef* d = (b2MouseJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	d->frequencyHz = f;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_MouseJointDef_getFrequencyHz
  (JNIEnv * env, jobject thiz) {
	b2MouseJointDef* d = (b2MouseJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return d->frequencyHz;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_MouseJointDef_setDampingRatio
  (JNIEnv * env, jobject thiz, jfloat damping) {
	b2MouseJointDef* d = (b2MouseJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	d->dampingRatio = damping;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_MouseJointDef_getDampingRatio
  (JNIEnv * env, jobject thiz) {
	b2MouseJointDef* d = (b2MouseJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return d->dampingRatio;
}
