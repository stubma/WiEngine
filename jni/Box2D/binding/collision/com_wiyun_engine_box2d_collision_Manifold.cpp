#include "com_wiyun_engine_box2d_collision_Manifold.h"
#include "Box2D.h"
#include "wyMemory.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;
extern jfieldID g_fid_ManifoldPoint_localPoint;
extern jfieldID g_fid_ManifoldPoint_normalImpulse;
extern jfieldID g_fid_ManifoldPoint_tangentImpulse;
extern jfieldID g_fid_ManifoldPoint_indexA;
extern jfieldID g_fid_ManifoldPoint_indexB;
extern jfieldID g_fid_ManifoldPoint_typeA;
extern jfieldID g_fid_ManifoldPoint_typeB;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_collision_Manifold_getPointCount
  (JNIEnv * env, jobject thiz) {
	b2Manifold* m = (b2Manifold*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return m->pointCount;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_Manifold_destroy
  (JNIEnv * env, jobject thiz) {
	b2Manifold* m = (b2Manifold*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyFree(m);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_collision_Manifold_getType
  (JNIEnv * env, jobject thiz) {
	b2Manifold* m = (b2Manifold*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)m->type;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_Manifold_nativeGetLocalPoint
  (JNIEnv * env, jobject thiz, jobject p) {
	b2Manifold* m = (b2Manifold*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, m->localPoint.x);
	env->SetFloatField(p, g_fid_WYPoint_y, m->localPoint.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_Manifold_nativeGetLocalNormal
  (JNIEnv * env, jobject thiz, jobject p) {
	b2Manifold* m = (b2Manifold*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, m->localNormal.x);
	env->SetFloatField(p, g_fid_WYPoint_y, m->localNormal.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_Manifold_nativeGetManifoldPoint
  (JNIEnv * env, jobject thiz, jint index, jobject mp) {
	b2Manifold* m = (b2Manifold*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2ManifoldPoint b2mp = m->points[index];
	jobject p = env->GetObjectField(mp, g_fid_ManifoldPoint_localPoint);
	env->SetFloatField(p, g_fid_WYPoint_x, b2mp.localPoint.x);
	env->SetFloatField(p, g_fid_WYPoint_y, b2mp.localPoint.y);
	env->SetFloatField(mp, g_fid_ManifoldPoint_normalImpulse, b2mp.normalImpulse);
	env->SetFloatField(mp, g_fid_ManifoldPoint_tangentImpulse, b2mp.tangentImpulse);
	env->SetIntField(mp, g_fid_ManifoldPoint_indexA, b2mp.id.cf.indexA);
	env->SetIntField(mp, g_fid_ManifoldPoint_indexB, b2mp.id.cf.indexB);
	env->SetIntField(mp, g_fid_ManifoldPoint_typeA, b2mp.id.cf.typeA);
	env->SetIntField(mp, g_fid_ManifoldPoint_typeB, b2mp.id.cf.typeB);
	env->DeleteLocalRef(p);
}
