#include <jni.h>
#include "com_wiyun_engine_chipmunk_Segment.h"
#include "chipmunk.h"
#include "chipmunk_unsafe.h"

extern jfieldID g_fid_Body_mPointer;
extern jfieldID g_fid_Shape_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Segment_init(JNIEnv * env, jobject thiz, jobject body, jfloat startX, jfloat startY, jfloat endX, jfloat endY, jfloat thickness) {
	cpBody* bodyStruct = (cpBody*)env->GetIntField(body, g_fid_Body_mPointer);
	cpShape* shape = cpSegmentShapeNew(bodyStruct, cpv(startX, startY), cpv(endX, endY), thickness);
	env->SetIntField(thiz, g_fid_Shape_mPointer, (int)shape);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Segment_setEndpoints
  (JNIEnv * env, jobject thiz, jfloat aX, jfloat aY, jfloat bX, jfloat bY) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	cpSegmentShapeSetEndpoints(shape, cpv(aX, aY), cpv(bX, bY));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Segment_getEndpoints
  (JNIEnv * env, jobject thiz, jobjectArray endpoints) {
	cpSegmentShape* seg = (cpSegmentShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);

	jobject a = env->GetObjectArrayElement(endpoints, 0);
	jobject b = env->GetObjectArrayElement(endpoints, 1);
	env->SetFloatField(a, g_fid_WYPoint_x, seg->a.x);
	env->SetFloatField(a, g_fid_WYPoint_y, seg->a.y);
	env->SetFloatField(b, g_fid_WYPoint_x, seg->b.x);
	env->SetFloatField(b, g_fid_WYPoint_y, seg->b.y);
	env->DeleteLocalRef(a);
	env->DeleteLocalRef(b);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Segment_getNormal
  (JNIEnv * env, jobject thiz, jobject normal) {
	cpSegmentShape* seg = (cpSegmentShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	env->SetFloatField(normal, g_fid_WYPoint_x, seg->n.x);
	env->SetFloatField(normal, g_fid_WYPoint_y, seg->n.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Segment_getTransformedEndpoints
  (JNIEnv * env, jobject thiz, jobjectArray endpoints) {
	cpSegmentShape* seg = (cpSegmentShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);

	jobject a = env->GetObjectArrayElement(endpoints, 0);
	jobject b = env->GetObjectArrayElement(endpoints, 1);
	env->SetFloatField(a, g_fid_WYPoint_x, seg->ta.x);
	env->SetFloatField(a, g_fid_WYPoint_y, seg->ta.y);
	env->SetFloatField(b, g_fid_WYPoint_x, seg->tb.x);
	env->SetFloatField(b, g_fid_WYPoint_y, seg->tb.y);
	env->DeleteLocalRef(a);
	env->DeleteLocalRef(b);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Segment_getTransformedNormal
  (JNIEnv * env, jobject thiz, jobject normal) {
	cpSegmentShape* seg = (cpSegmentShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	env->SetFloatField(normal, g_fid_WYPoint_x, seg->tn.x);
	env->SetFloatField(normal, g_fid_WYPoint_y, seg->tn.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Segment_setThickness
  (JNIEnv * env, jobject thiz, jfloat thickness) {
	cpSegmentShape* seg = (cpSegmentShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	seg->r = thickness;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Segment_getThickness
  (JNIEnv * env, jobject thiz) {
	cpSegmentShape* seg = (cpSegmentShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return seg->r;
}
