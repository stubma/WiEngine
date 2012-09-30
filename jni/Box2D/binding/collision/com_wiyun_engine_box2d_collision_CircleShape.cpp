#include "com_wiyun_engine_box2d_collision_CircleShape.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_CircleShape_nativeNew
  (JNIEnv * env, jobject thiz) {
	b2CircleShape* cs = new b2CircleShape();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)cs);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_CircleShape_setPosition
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2CircleShape* cs = (b2CircleShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	cs->m_p = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_CircleShape_nativeGetPosition
  (JNIEnv * env, jobject thiz, jobject p) {
	b2CircleShape* cs = (b2CircleShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, cs->m_p.x);
	env->SetFloatField(p, g_fid_WYPoint_y, cs->m_p.y);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_collision_CircleShape_getSupport
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2CircleShape* cs = (b2CircleShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return cs->GetSupport(b2Vec2(x, y));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_CircleShape_nativeGetSupportVertex
  (JNIEnv * env, jobject thiz, jobject p, jfloat x, jfloat y) {
	b2CircleShape* cs = (b2CircleShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 v = cs->GetSupportVertex(b2Vec2(x, y));
	env->SetFloatField(p, g_fid_WYPoint_x, v.x);
	env->SetFloatField(p, g_fid_WYPoint_y, v.y);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_collision_CircleShape_getVertexCount
  (JNIEnv * env, jobject thiz) {
	b2CircleShape* cs = (b2CircleShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return cs->GetVertexCount();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_CircleShape_nativeGetVertex
  (JNIEnv * env, jobject thiz, jobject p, jint index) {
	b2CircleShape* cs = (b2CircleShape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 v = cs->GetVertex(index);
	env->SetFloatField(p, g_fid_WYPoint_x, v.x);
	env->SetFloatField(p, g_fid_WYPoint_y, v.y);
}
