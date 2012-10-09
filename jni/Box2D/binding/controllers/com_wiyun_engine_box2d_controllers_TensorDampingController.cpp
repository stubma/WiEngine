#include "com_wiyun_engine_box2d_controllers_TensorDampingController.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_Matrix22_col1X;
extern jfieldID g_fid_Matrix22_col1Y;
extern jfieldID g_fid_Matrix22_col2X;
extern jfieldID g_fid_Matrix22_col2Y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_TensorDampingController_setMatrix
  (JNIEnv * env, jobject thiz, jobject t) {
	b2TensorDampingController* c = (b2TensorDampingController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->T.ex.x = env->GetFloatField(t, g_fid_Matrix22_col1X);
	c->T.ex.y = env->GetFloatField(t, g_fid_Matrix22_col1Y);
	c->T.ey.x = env->GetFloatField(t, g_fid_Matrix22_col2X);
	c->T.ey.y = env->GetFloatField(t, g_fid_Matrix22_col2Y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_TensorDampingController_nativeGetMatrix
  (JNIEnv * env, jobject thiz, jobject t) {
	b2TensorDampingController* c = (b2TensorDampingController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(t, g_fid_Matrix22_col1X, c->T.ex.x);
	env->SetFloatField(t, g_fid_Matrix22_col1Y, c->T.ex.y);
	env->SetFloatField(t, g_fid_Matrix22_col2X, c->T.ey.x);
	env->SetFloatField(t, g_fid_Matrix22_col2Y, c->T.ey.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_TensorDampingController_setMaxTimeStep
  (JNIEnv * env, jobject thiz, jfloat maxTimeStep) {
	b2TensorDampingController* c = (b2TensorDampingController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->maxTimestep = maxTimeStep;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_controllers_TensorDampingController_getMaxTimeStep
  (JNIEnv * env, jobject thiz) {
	b2TensorDampingController* c = (b2TensorDampingController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->maxTimestep;
}
