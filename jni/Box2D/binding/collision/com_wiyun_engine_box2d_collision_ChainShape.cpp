#include "com_wiyun_engine_box2d_collision_ChainShape.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_ChainShape_nativeNew
  (JNIEnv * env, jobject thiz) {
	b2ChainShape* s = new b2ChainShape();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)s);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_ChainShape_createLoop
  (JNIEnv * env, jobject thiz, jobjectArray vertices) {
	b2ChainShape* s = (b2ChainShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jsize len = env->GetArrayLength(vertices);
	b2Vec2 v[len];
	for(int i = 0; i < len; i++) {
		jobject p = env->GetObjectArrayElement(vertices, i);
		v[i].x = env->GetFloatField(p, g_fid_WYPoint_x);
		v[i].y = env->GetFloatField(p, g_fid_WYPoint_y);
		env->DeleteLocalRef(p);
	}
	s->CreateLoop(v, len);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_ChainShape_createChain
  (JNIEnv * env, jobject thiz, jobjectArray vertices) {
	b2ChainShape* s = (b2ChainShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jsize len = env->GetArrayLength(vertices);
	b2Vec2 v[len];
	for(int i = 0; i < len; i++) {
		jobject p = env->GetObjectArrayElement(vertices, i);
		v[i].x = env->GetFloatField(p, g_fid_WYPoint_x);
		v[i].y = env->GetFloatField(p, g_fid_WYPoint_y);
		env->DeleteLocalRef(p);
	}
	s->CreateChain(v, len);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_ChainShape_SetPrevVertex
  (JNIEnv * env, jobject thiz, jobject p) {
	b2ChainShape* s = (b2ChainShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float x = env->GetFloatField(p, g_fid_WYPoint_x);
	float y = env->GetFloatField(p, g_fid_WYPoint_y);
	s->SetPrevVertex(b2Vec2(x, y));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_ChainShape_SetNextVertex
  (JNIEnv * env, jobject thiz, jobject p) {
	b2ChainShape* s = (b2ChainShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float x = env->GetFloatField(p, g_fid_WYPoint_x);
	float y = env->GetFloatField(p, g_fid_WYPoint_y);
	s->SetNextVertex(b2Vec2(x, y));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_ChainShape_nativeGetPrevVertex
  (JNIEnv * env, jobject thiz, jobject p) {
	b2ChainShape* s = (b2ChainShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, s->m_prevVertex.x);
	env->SetFloatField(p, g_fid_WYPoint_y, s->m_prevVertex.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_ChainShape_nativeGetNextVertex
  (JNIEnv * env, jobject thiz, jobject p) {
	b2ChainShape* s = (b2ChainShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, s->m_nextVertex.x);
	env->SetFloatField(p, g_fid_WYPoint_y, s->m_nextVertex.y);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_collision_ChainShape_hasPrevVertex
  (JNIEnv * env, jobject thiz) {
	b2ChainShape* s = (b2ChainShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return s->m_hasPrevVertex;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_collision_ChainShape_hasNextVertex
  (JNIEnv * env, jobject thiz) {
	b2ChainShape* s = (b2ChainShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return s->m_hasNextVertex;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_collision_ChainShape_nativeGetChildEdge
  (JNIEnv * env, jobject thiz, jint index) {
	b2ChainShape* s = (b2ChainShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2EdgeShape* es = new b2EdgeShape();
	s->GetChildEdge(es, index);
	return (jint)es;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_collision_ChainShape_getCount
  (JNIEnv * env, jobject thiz) {
	b2ChainShape* s = (b2ChainShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return s->m_count;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_ChainShape_nativeGetVertex
  (JNIEnv * env, jobject thiz, jobject p, jint index) {
	b2ChainShape* s = (b2ChainShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 v = s->m_vertices[index];
	env->SetFloatField(p, g_fid_WYPoint_x, v.x);
	env->SetFloatField(p, g_fid_WYPoint_y, v.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_ChainShape_nativeGetVertices
  (JNIEnv * env, jobject thiz, jobjectArray vertices) {
	b2ChainShape* s = (b2ChainShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const b2Vec2* v = s->m_vertices;
	int count = s->m_count;
	for(int i = 0; i < count; i++) {
		jobject p = env->GetObjectArrayElement(vertices, i);
		env->SetFloatField(p, g_fid_WYPoint_x, v[i].x);
		env->SetFloatField(p, g_fid_WYPoint_y, v[i].y);
		env->DeleteLocalRef(p);
	}
}
