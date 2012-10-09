#include <jni.h>
#include "com_wiyun_engine_chipmunk_Circle.h"
#include "chipmunk.h"


extern jfieldID g_fid_Body_mPointer;
extern jfieldID g_fid_Shape_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Circle_init(JNIEnv * env, jobject thiz, jobject body, jfloat radius, jfloat centerX, jfloat centerY) {
	cpBody* bodyStruct = (cpBody*)env->GetIntField(body, g_fid_Body_mPointer);
	cpShape* shape = cpCircleShapeNew(bodyStruct, radius, cpv(centerX, centerY));
	env->SetIntField(thiz, g_fid_Shape_mPointer, (int)shape);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Circle_setRadius
  (JNIEnv * env, jobject thiz, jfloat r) {
	cpCircleShape* circle = (cpCircleShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	circle->r = r;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Circle_getRadius
  (JNIEnv * env, jobject thiz) {
	cpCircleShape* circle = (cpCircleShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return circle->r;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Circle_setOffset
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	cpCircleShape* circle = (cpCircleShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	circle->c = cpv(x, y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Circle_getOffsetX
  (JNIEnv * env, jobject thiz) {
	cpCircleShape* circle = (cpCircleShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return circle->c.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Circle_getOffsetY
  (JNIEnv * env, jobject thiz) {
	cpCircleShape* circle = (cpCircleShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return circle->c.y;
}
