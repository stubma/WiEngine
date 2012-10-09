#include "com_wiyun_engine_box2d_controllers_ConstantAccelController.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_ConstantAccelController_setAcceleration
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2ConstantAccelController* c = (b2ConstantAccelController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->A.x = x;
	c->A.y = y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_ConstantAccelController_nativeGetAcceleration
  (JNIEnv * env, jobject thiz, jobject f) {
	b2ConstantAccelController* c = (b2ConstantAccelController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(f, g_fid_WYPoint_x, c->A.x);
	env->SetFloatField(f, g_fid_WYPoint_y, c->A.y);
}
