#include "com_wiyun_engine_box2d_collision_PolygonShape.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_PolygonShape_nativeNew
  (JNIEnv * env, jobject thiz) {
	b2PolygonShape* ps = new b2PolygonShape();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ps);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_PolygonShape_setVertices
  (JNIEnv * env, jobject thiz, jobjectArray vertices) {
	b2PolygonShape* ps = (b2PolygonShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jsize len = env->GetArrayLength(vertices);
	b2Vec2 v[len];
	for(int i = 0; i < len; i++) {
		jobject vert = env->GetObjectArrayElement(vertices, i);
		float x = env->GetFloatField(vert, g_fid_WYPoint_x);
		float y = env->GetFloatField(vert, g_fid_WYPoint_y);
		v[i] = b2Vec2(x, y);
		env->DeleteLocalRef(vert);
	}
	ps->Set(v, len);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_PolygonShape_setAsBox__FF
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2PolygonShape* ps = (b2PolygonShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->SetAsBox(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_PolygonShape_setAsBox__FFFFF
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y, jfloat centerX, jfloat centerY, jfloat angle) {
	b2PolygonShape* ps = (b2PolygonShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ps->SetAsBox(x, y, b2Vec2(centerX, centerY), angle);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_collision_PolygonShape_getVertexCount
  (JNIEnv * env, jobject thiz) {
	b2PolygonShape* ps = (b2PolygonShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ps->GetVertexCount();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_PolygonShape_nativeGetVertex
  (JNIEnv * env, jobject thiz, jobject p, jint index) {
	b2PolygonShape* ps = (b2PolygonShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 v = ps->GetVertex(index);
	env->SetFloatField(p, g_fid_WYPoint_x, v.x);
	env->SetFloatField(p, g_fid_WYPoint_y, v.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_PolygonShape_nativeGetCentroid
  (JNIEnv * env, jobject thiz, jobject p) {
	b2PolygonShape* ps = (b2PolygonShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, ps->m_centroid.x);
	env->SetFloatField(p, g_fid_WYPoint_y, ps->m_centroid.y);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_collision_PolygonShape_validate
  (JNIEnv * env, jobject thiz) {
	b2PolygonShape* ps = (b2PolygonShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ps->Validate();
}
