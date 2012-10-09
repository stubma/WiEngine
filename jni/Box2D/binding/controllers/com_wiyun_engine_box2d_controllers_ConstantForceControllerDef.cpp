#include "com_wiyun_engine_box2d_controllers_ConstantForceControllerDef.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_ConstantForceControllerDef_nativeInit
  (JNIEnv * env, jobject thiz) {
	b2ConstantForceControllerDef* cd = new b2ConstantForceControllerDef();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)cd);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_ConstantForceControllerDef_destroy
  (JNIEnv * env, jobject thiz) {
	b2ConstantForceControllerDef* c = (b2ConstantForceControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	delete c;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_ConstantForceControllerDef_setForce
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2ConstantForceControllerDef* c = (b2ConstantForceControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->F.x = x;
	c->F.y = y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_ConstantForceControllerDef_nativeGetForce
  (JNIEnv * env, jobject thiz, jobject f) {
	b2ConstantForceControllerDef* c = (b2ConstantForceControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(f, g_fid_WYPoint_x, c->F.x);
	env->SetFloatField(f, g_fid_WYPoint_y, c->F.y);
}

