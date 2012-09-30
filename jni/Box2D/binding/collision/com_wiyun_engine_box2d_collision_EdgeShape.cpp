#include "com_wiyun_engine_box2d_collision_EdgeShape.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_EdgeShape_nativeNew
  (JNIEnv * env, jobject thiz) {
	b2EdgeShape* es = new b2EdgeShape();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)es);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_EdgeShape_setEndpoints
  (JNIEnv * env, jobject thiz, jfloat x1, jfloat y1, jfloat x2, jfloat y2) {
	b2EdgeShape* es = (b2EdgeShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	es->Set(b2Vec2(x1, y1), b2Vec2(x2, y2));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_EdgeShape_nativeGetEndpoint1
  (JNIEnv * env, jobject thiz, jobject p) {
	b2EdgeShape* es = (b2EdgeShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, es->m_vertex1.x);
	env->SetFloatField(p, g_fid_WYPoint_y, es->m_vertex1.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_EdgeShape_nativeGetEndpoint2
  (JNIEnv * env, jobject thiz, jobject p) {
	b2EdgeShape* es = (b2EdgeShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, es->m_vertex2.x);
	env->SetFloatField(p, g_fid_WYPoint_y, es->m_vertex2.y);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_collision_EdgeShape_hasAdjacentVertex1
  (JNIEnv * env, jobject thiz) {
	b2EdgeShape* es = (b2EdgeShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return es->m_hasVertex0;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_collision_EdgeShape_hasAdjacentVertex2
  (JNIEnv * env, jobject thiz) {
	b2EdgeShape* es = (b2EdgeShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return es->m_hasVertex3;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_EdgeShape_nativeGetAdjacentVertex1
  (JNIEnv * env, jobject thiz, jobject p) {
	b2EdgeShape* es = (b2EdgeShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, es->m_vertex0.x);
	env->SetFloatField(p, g_fid_WYPoint_y, es->m_vertex0.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_EdgeShape_nativeGetAdjacentVertex2
  (JNIEnv * env, jobject thiz, jobject p) {
	b2EdgeShape* es = (b2EdgeShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, es->m_vertex3.x);
	env->SetFloatField(p, g_fid_WYPoint_y, es->m_vertex3.y);
}
