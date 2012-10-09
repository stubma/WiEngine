#include <jni.h>
#include "com_wiyun_engine_chipmunk_Shape.h"
#include "chipmunk.h"
#include <stdlib.h>
#include "wyTexture2D.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_Shape_mPointer;
extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Shape_resetShapeIdCounter(JNIEnv * env, jclass clazz) {
	 cpResetShapeIdCounter();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Shape_clearAnimation
  (JNIEnv * env, jobject thiz) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	cpShapeClearAnimation(shape);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Shape_destroy
  (JNIEnv * env, jobject thiz) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	cpShapeFree(shape);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Shape_nativeGetBody
  (JNIEnv * env, jobject thiz) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return (jint)shape->body;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Shape_setRestitution(JNIEnv* env, jobject thiz, jfloat restitution) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	shape->e = restitution;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Shape_setFriction(JNIEnv* env, jobject thiz, jfloat friction) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	shape->u = friction;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Shape_setLayerMask(JNIEnv* env, jobject thiz, jint mask) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	shape->layers = mask;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Shape_getLayerMask
  (JNIEnv * env, jobject thiz) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return shape->layers;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Shape_setData
  (JNIEnv * env, jobject thiz, jobject data) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	if(shape->j_data != NULL) {
		env->DeleteGlobalRef(shape->j_data);
		shape->j_data = NULL;
	}
	shape->j_data = env->NewGlobalRef(data);
}

JNIEXPORT jobject JNICALL Java_com_wiyun_engine_chipmunk_Shape_getData(JNIEnv * env, jobject thiz) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return shape->j_data;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Shape_setCollisionType(JNIEnv * env, jobject thiz, jint type) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	shape->collision_type = type;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Shape_getCollisionType
  (JNIEnv * env, jobject thiz) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return shape->collision_type;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Shape_setSurfaceVelocity
  (JNIEnv * env, jobject thiz, jfloat xVel, jfloat yVel) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	shape->surface_v = cpv(xVel, yVel);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Shape_getSurfaceVelocityX
  (JNIEnv * env, jobject thiz) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return shape->surface_v.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Shape_getSurfaceVelocityY
  (JNIEnv * env, jobject thiz) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return shape->surface_v.y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Shape_setGroup
  (JNIEnv * env, jobject thiz, jint group) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	shape->group = group;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Shape_getGroup
  (JNIEnv * env, jobject thiz) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return shape->group;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Shape_updateBoundingBox
  (JNIEnv * env, jobject thiz) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	cpShapeCacheBB(shape);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_chipmunk_Shape_isSensor
  (JNIEnv * env, jobject thiz) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return shape->sensor == 1;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Shape_setIsSensor
  (JNIEnv * env, jobject thiz, jboolean sensor) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	shape->sensor = sensor ? 1 : 0;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Shape_nativeGetTexture
  (JNIEnv * env, jobject thiz) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return (jint)shape->tex;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Shape_setTexture__Lcom_wiyun_engine_opengl_Texture2D_2Z
  (JNIEnv * env, jobject thiz, jobject texture, jboolean autoSize) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	cpShapeSetTexture(shape, tex, autoSize);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Shape_setTexture__Lcom_wiyun_engine_opengl_Texture2D_2Lcom_wiyun_engine_types_WYRect_2Z
  (JNIEnv * env, jobject thiz, jobject texture, jobject rect, jboolean autoSize) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	wyRect r = wyUtils_android::to_wyRect( rect);
	cpShapeSetTexture2(shape, tex, r, autoSize);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Shape_getBoundingBox
  (JNIEnv * env, jobject thiz, jobject rect) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);

	wyRect r = {
		shape->bb.l,
		shape->bb.b,
		shape->bb.r - shape->bb.l,
		shape->bb.t - shape->bb.b
	};
	wyUtils_android::to_WYRect( r, rect);
}
