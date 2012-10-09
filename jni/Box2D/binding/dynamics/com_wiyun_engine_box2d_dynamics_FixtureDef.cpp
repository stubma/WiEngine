#include "com_wiyun_engine_box2d_dynamics_FixtureDef.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_Filter_categoryBits;
extern jfieldID g_fid_Filter_maskBits;
extern jfieldID g_fid_Filter_groupIndex;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_nativeNew
  (JNIEnv * env, jobject thiz) {
	b2FixtureDef* fixDef = new b2FixtureDef();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)fixDef);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_setShape
  (JNIEnv * env, jobject thiz, jobject s) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Shape* shape = (b2Shape*)env->GetIntField(s, g_fid_BaseObject_mPointer);
	fd->shape = shape;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_getShape
  (JNIEnv * env, jobject thiz) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)fd->shape;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_setFriction
  (JNIEnv * env, jobject thiz, jfloat f) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	fd->friction = f;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_getFriction
  (JNIEnv * env, jobject thiz) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return fd->friction;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_setRestitution
  (JNIEnv * env, jobject thiz, jfloat r) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	fd->restitution = r;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_getRestitution
  (JNIEnv * env, jobject thiz) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return fd->restitution;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_setDensity
  (JNIEnv * env, jobject thiz, jfloat d) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	fd->density = d;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_getDensity
  (JNIEnv * env, jobject thiz) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return fd->density;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_setSensor
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	fd->isSensor = flag;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_isSensor
  (JNIEnv * env, jobject thiz) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return fd->isSensor;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_destroy
  (JNIEnv * env, jobject thiz) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	delete fd;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_setFilter
  (JNIEnv * env, jobject thiz, jint categoryBits, jint maskBits, jint groupIndex) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	fd->filter.categoryBits = categoryBits;
	fd->filter.maskBits = maskBits;
	fd->filter.groupIndex = groupIndex;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_setFilterCategory
  (JNIEnv * env, jobject thiz, jint categoryBits) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	fd->filter.categoryBits = categoryBits;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_setFilterMask
  (JNIEnv * env, jobject thiz, jint maskBits) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	fd->filter.maskBits = maskBits;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_setFilterGroupIndex
  (JNIEnv * env, jobject thiz, jint groupIndex) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	fd->filter.groupIndex = groupIndex;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_nativeGetFilter
  (JNIEnv * env, jobject thiz, jobject f) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetIntField(f, g_fid_Filter_categoryBits, fd->filter.categoryBits);
	env->SetIntField(f, g_fid_Filter_maskBits, fd->filter.maskBits);
	env->SetIntField(f, g_fid_Filter_groupIndex, fd->filter.groupIndex);
}

JNIEXPORT jobject JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_getUserData
  (JNIEnv * env, jobject thiz) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return fd->j_userData;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_FixtureDef_setUserData
  (JNIEnv * env, jobject thiz, jobject data) {
	b2FixtureDef* fd = (b2FixtureDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	if(fd->j_userData != NULL) {
		env->DeleteGlobalRef(fd->j_userData);
		fd->j_userData = NULL;
	}
	if(data != NULL) {
		fd->j_userData = env->NewGlobalRef(data);
	}
}
