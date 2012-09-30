#include "com_wiyun_engine_box2d_controllers_GravityControllerDef.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_GravityControllerDef_nativeInit
  (JNIEnv * env, jobject thiz) {
	b2GravityControllerDef* cd = new b2GravityControllerDef();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)cd);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_GravityControllerDef_destroy
  (JNIEnv * env, jobject thiz) {
	b2GravityControllerDef* c = (b2GravityControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	delete c;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_GravityControllerDef_setGravitationalConstant
  (JNIEnv * env, jobject thiz, jfloat gc) {
	b2GravityControllerDef* c = (b2GravityControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->G = gc;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_controllers_GravityControllerDef_getGravitationalConstant
  (JNIEnv * env, jobject thiz) {
	b2GravityControllerDef* c = (b2GravityControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->G;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_GravityControllerDef_setProportionalToInvRadius
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2GravityControllerDef* c = (b2GravityControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->invSqr = flag;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_controllers_GravityControllerDef_isProportionalToInvRadius
  (JNIEnv * env, jobject thiz) {
	b2GravityControllerDef* c = (b2GravityControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->invSqr;
}
