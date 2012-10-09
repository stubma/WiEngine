#include "com_wiyun_engine_box2d_controllers_GravityController.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_GravityController_setGravitationalConstant
  (JNIEnv * env, jobject thiz, jfloat gc) {
	b2GravityController* c = (b2GravityController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->G = gc;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_controllers_GravityController_getGravitationalConstant
  (JNIEnv * env, jobject thiz) {
	b2GravityController* c = (b2GravityController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->G;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_GravityController_setProportionalToInvRadius
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2GravityController* c = (b2GravityController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->invSqr = flag;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_controllers_GravityController_isProportionalToInvRadius
  (JNIEnv * env, jobject thiz) {
	b2GravityController* c = (b2GravityController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->invSqr;
}
