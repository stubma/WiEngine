#include "com_wiyun_engine_box2d_controllers_ConstantAccelControllerDef.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_ConstantAccelControllerDef_nativeInit
  (JNIEnv * env, jobject thiz) {
	b2ConstantAccelControllerDef* cd = new b2ConstantAccelControllerDef();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)cd);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_ConstantAccelControllerDef_destroy
  (JNIEnv * env, jobject thiz) {
	b2ConstantAccelControllerDef* c = (b2ConstantAccelControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	delete c;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_ConstantAccelControllerDef_setAcceleration
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2ConstantAccelControllerDef* c = (b2ConstantAccelControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->A.x = x;
	c->A.y = y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_ConstantAccelControllerDef_nativeGetAcceleration
  (JNIEnv * env, jobject thiz, jobject f) {
	b2ConstantAccelControllerDef* c = (b2ConstantAccelControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(f, g_fid_WYPoint_x, c->A.x);
	env->SetFloatField(f, g_fid_WYPoint_y, c->A.y);
}

