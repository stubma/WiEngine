#include "com_wiyun_engine_box2d_controllers_ConstantForceController.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_ConstantForceController_setForce
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2ConstantForceController* c = (b2ConstantForceController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->F.x = x;
	c->F.y = y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_ConstantForceController_nativeGetForce
  (JNIEnv * env, jobject thiz, jobject f) {
	b2ConstantForceController* c = (b2ConstantForceController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(f, g_fid_WYPoint_x, c->F.x);
	env->SetFloatField(f, g_fid_WYPoint_y, c->F.y);
}
