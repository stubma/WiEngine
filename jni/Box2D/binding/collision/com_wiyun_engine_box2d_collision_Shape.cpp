#include "com_wiyun_engine_box2d_collision_Shape.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;
extern jfieldID g_fid_Transform_q;
extern jfieldID g_fid_Transform_p;
extern jfieldID g_fid_Rotation_s;
extern jfieldID g_fid_Rotation_c;
extern jfieldID g_fid_RayCastInput_p1;
extern jfieldID g_fid_RayCastInput_p2;
extern jfieldID g_fid_RayCastInput_maxFraction;
extern jfieldID g_fid_RayCastOutput_normal;
extern jfieldID g_fid_RayCastOutput_fraction;
extern jfieldID g_fid_AABB_lowerBound;
extern jfieldID g_fid_AABB_upperBound;
extern jfieldID g_fid_MassData_mass;
extern jfieldID g_fid_MassData_center;
extern jfieldID g_fid_MassData_I;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_collision_Shape_copy
  (JNIEnv * env, jobject thiz, jobject world) {
	b2Shape* s = (b2Shape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2World* w = (b2World*)env->GetIntField(world, g_fid_BaseObject_mPointer);
	return (jint)s->Clone(w->getBlockAllocator());
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_collision_Shape_getType
  (JNIEnv * env, jobject thiz) {
	b2Shape* s = (b2Shape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)s->GetType();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_Shape_setType
  (JNIEnv * env, jobject thiz, jint type) {
	b2Shape* s = (b2Shape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	s->m_type = (b2Shape::Type)type;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_Shape_setRadius
  (JNIEnv * env, jobject thiz, jfloat r) {
	b2Shape* s = (b2Shape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	s->m_radius = r;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_collision_Shape_getRadius
  (JNIEnv * env, jobject thiz) {
	b2Shape* s = (b2Shape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return s->m_radius;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_collision_Shape_getChildCount
  (JNIEnv * env, jobject thiz) {
	b2Shape* s = (b2Shape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return s->GetChildCount();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_collision_Shape_testPoint
  (JNIEnv * env, jobject thiz, jobject trans, jobject point) {
	b2Shape* s = (b2Shape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);

	b2Transform t;
	jobject q = env->GetObjectField(trans, g_fid_Transform_q);
	jobject p = env->GetObjectField(trans, g_fid_Transform_p);
	t.q.s = env->GetFloatField(q, g_fid_Rotation_s);
	t.q.c = env->GetFloatField(q, g_fid_Rotation_c);
	t.p.x = env->GetFloatField(p, g_fid_WYPoint_x);
	t.p.y = env->GetFloatField(p, g_fid_WYPoint_y);
	env->DeleteLocalRef(q);
	env->DeleteLocalRef(p);

	b2Vec2 v;
	v.x = env->GetFloatField(point, g_fid_WYPoint_x);
	v.y = env->GetFloatField(point, g_fid_WYPoint_y);

	return s->TestPoint(t, v);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_Shape_nativeRayCast
  (JNIEnv * env, jobject thiz, jobject output, jobject input, jobject trans, jint childIndex) {
	b2Shape* s = (b2Shape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2RayCastOutput o;
	b2RayCastInput i;

	// get transform
	b2Transform t;
	jobject q = env->GetObjectField(trans, g_fid_Transform_q);
	jobject p = env->GetObjectField(trans, g_fid_Transform_p);
	t.q.s = env->GetFloatField(q, g_fid_Rotation_s);
	t.q.c = env->GetFloatField(q, g_fid_Rotation_c);
	t.p.x = env->GetFloatField(p, g_fid_WYPoint_x);
	t.p.y = env->GetFloatField(p, g_fid_WYPoint_y);
	env->DeleteLocalRef(q);
	env->DeleteLocalRef(p);

	// set b2RayCastInput and perform ray cast
	jobject p1 = env->GetObjectField(input, g_fid_RayCastInput_p1);
	jobject p2 = env->GetObjectField(input, g_fid_RayCastInput_p2);
	i.p1.x = env->GetFloatField(p1, g_fid_WYPoint_x);
	i.p1.y = env->GetFloatField(p1, g_fid_WYPoint_y);
	i.p2.x = env->GetFloatField(p2, g_fid_WYPoint_x);
	i.p2.y = env->GetFloatField(p2, g_fid_WYPoint_y);
	i.maxFraction = env->GetFloatField(input, g_fid_RayCastInput_maxFraction);
	s->RayCast(&o, i, t, childIndex);
	env->DeleteLocalRef(p1);
	env->DeleteLocalRef(p2);

	// write back to output
	jobject normal = env->GetObjectField(output, g_fid_RayCastOutput_normal);
	env->SetFloatField(normal, g_fid_WYPoint_x, o.normal.x);
	env->SetFloatField(normal, g_fid_WYPoint_y, o.normal.y);
	env->SetFloatField(normal, g_fid_RayCastOutput_fraction, o.fraction);
	env->DeleteLocalRef(normal);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_Shape_nativeComputeAABB
  (JNIEnv * env, jobject thiz, jobject aabb, jobject trans, jint childIndex) {
	b2Shape* s = (b2Shape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2AABB ab;

	// get transform
	b2Transform t;
	jobject q = env->GetObjectField(trans, g_fid_Transform_q);
	jobject p = env->GetObjectField(trans, g_fid_Transform_p);
	t.q.s = env->GetFloatField(q, g_fid_Rotation_s);
	t.q.c = env->GetFloatField(q, g_fid_Rotation_c);
	t.p.x = env->GetFloatField(p, g_fid_WYPoint_x);
	t.p.y = env->GetFloatField(p, g_fid_WYPoint_y);
	env->DeleteLocalRef(q);
	env->DeleteLocalRef(p);

	// compute aabb
	s->ComputeAABB(&ab, t, childIndex);

	// write back
	jobject lb = env->GetObjectField(aabb, g_fid_AABB_lowerBound);
	jobject ub = env->GetObjectField(aabb, g_fid_AABB_upperBound);
	env->SetFloatField(lb, g_fid_WYPoint_x, ab.lowerBound.x);
	env->SetFloatField(lb, g_fid_WYPoint_y, ab.lowerBound.y);
	env->SetFloatField(ub, g_fid_WYPoint_x, ab.upperBound.x);
	env->SetFloatField(ub, g_fid_WYPoint_y, ab.upperBound.y);
	env->DeleteLocalRef(lb);
	env->DeleteLocalRef(ub);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_collision_Shape_nativeComputeMass
  (JNIEnv * env, jobject thiz, jobject d, jfloat density) {
	b2Shape* s = (b2Shape*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2MassData data;

	s->ComputeMass(&data, density);

	jobject p = env->GetObjectField(d, g_fid_MassData_center);
	env->SetFloatField(d, g_fid_MassData_mass, data.mass);
	env->SetFloatField(p, g_fid_WYPoint_x, data.center.x);
	env->SetFloatField(p, g_fid_WYPoint_y, data.center.y);
	env->SetFloatField(d, g_fid_MassData_I, data.I);
	env->DeleteLocalRef(p);
}
