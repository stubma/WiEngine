#include "com_wiyun_engine_box2d_controllers_BuoyancyControllerDef.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_nativeInit
  (JNIEnv * env, jobject thiz) {
	b2BuoyancyControllerDef* cd = new b2BuoyancyControllerDef();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)cd);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_destroy
  (JNIEnv * env, jobject thiz) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	delete c;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_setNormal
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->normal.x = x;
	c->normal.y = y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_nativeGetNormal
  (JNIEnv * env, jobject thiz, jobject n) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(n, g_fid_WYPoint_x, c->normal.x);
	env->SetFloatField(n, g_fid_WYPoint_y, c->normal.y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_getOffset
  (JNIEnv * env, jobject thiz) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->offset;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_setOffset
  (JNIEnv * env, jobject thiz, jfloat offset) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->offset = offset;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_getDensity
  (JNIEnv * env, jobject thiz) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->density;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_setDensity
  (JNIEnv * env, jobject thiz, jfloat density) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->density = density;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_setVelocity
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->velocity.x = x;
	c->velocity.y = y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_nativeGetVelocity
  (JNIEnv * env, jobject thiz, jobject v) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(v, g_fid_WYPoint_x, c->velocity.x);
	env->SetFloatField(v, g_fid_WYPoint_y, c->velocity.y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_getLinearDrag
  (JNIEnv * env, jobject thiz) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->linearDrag;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_setLinearDrag
  (JNIEnv * env, jobject thiz, jfloat linearDrag) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->linearDrag = linearDrag;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_getAngularDrag
  (JNIEnv * env, jobject thiz) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->angularDrag;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_setAngularDrag
  (JNIEnv * env, jobject thiz, jfloat angularDrag) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->angularDrag = angularDrag;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_isUseDensity
  (JNIEnv * env, jobject thiz) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->useDensity;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_setUseDensity
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->useDensity = flag;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_isUseWorldGravity
  (JNIEnv * env, jobject thiz) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->useWorldGravity;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_setUseWorldGravity
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->useWorldGravity = flag;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_setGravity
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->gravity.x = x;
	c->gravity.y = y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_BuoyancyControllerDef_nativeGetGravity
  (JNIEnv * env, jobject thiz, jobject g) {
	b2BuoyancyControllerDef* c = (b2BuoyancyControllerDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(g, g_fid_WYPoint_x, c->gravity.x);
	env->SetFloatField(g, g_fid_WYPoint_y, c->gravity.y);
}
