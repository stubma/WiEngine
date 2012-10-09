#include "com_wiyun_engine_box2d_controllers_BuoyancyController.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_setNormal
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->normal.x = x;
	c->normal.y = y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_nativeGetNormal
  (JNIEnv * env, jobject thiz, jobject n) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(n, g_fid_WYPoint_x, c->normal.x);
	env->SetFloatField(n, g_fid_WYPoint_y, c->normal.y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_getOffset
  (JNIEnv * env, jobject thiz) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->offset;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_setOffset
  (JNIEnv * env, jobject thiz, jfloat offset) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->offset = offset;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_getDensity
  (JNIEnv * env, jobject thiz) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->density;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_setDensity
  (JNIEnv * env, jobject thiz, jfloat density) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->density = density;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_setVelocity
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->velocity.x = x;
	c->velocity.y = y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_nativeGetVelocity
  (JNIEnv * env, jobject thiz, jobject v) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(v, g_fid_WYPoint_x, c->velocity.x);
	env->SetFloatField(v, g_fid_WYPoint_y, c->velocity.y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_getLinearDrag
  (JNIEnv * env, jobject thiz) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->linearDrag;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_setLinearDrag
  (JNIEnv * env, jobject thiz, jfloat linearDrag) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->linearDrag = linearDrag;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_getAngularDrag
  (JNIEnv * env, jobject thiz) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->angularDrag;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_setAngularDrag
  (JNIEnv * env, jobject thiz, jfloat angularDrag) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->angularDrag = angularDrag;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_isUseDensity
  (JNIEnv * env, jobject thiz) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->useDensity;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_setUseDensity
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->useDensity = flag;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_isUseWorldGravity
  (JNIEnv * env, jobject thiz) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->useWorldGravity;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_setUseWorldGravity
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->useWorldGravity = flag;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_setGravity
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->gravity.x = x;
	c->gravity.y = y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyController_nativeGetGravity
  (JNIEnv * env, jobject thiz, jobject g) {
	b2BuoyancyController* c = (b2BuoyancyController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(g, g_fid_WYPoint_x, c->gravity.x);
	env->SetFloatField(g, g_fid_WYPoint_y, c->gravity.y);
}
