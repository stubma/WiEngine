#include "com_wiyun_engine_box2d_dynamics_Fixture.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_Filter_categoryBits;
extern jfieldID g_fid_Filter_maskBits;
extern jfieldID g_fid_Filter_groupIndex;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;
extern jfieldID g_fid_RayCastInput_p1;
extern jfieldID g_fid_RayCastInput_p2;
extern jfieldID g_fid_RayCastInput_maxFraction;
extern jfieldID g_fid_RayCastOutput_normal;
extern jfieldID g_fid_RayCastOutput_fraction;
extern jfieldID g_fid_MassData_mass;
extern jfieldID g_fid_MassData_center;
extern jfieldID g_fid_MassData_I;
extern jfieldID g_fid_AABB_lowerBound;
extern jfieldID g_fid_AABB_upperBound;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_nativeGetBody
  (JNIEnv * env, jobject thiz) {
	b2Fixture* f = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)f->GetBody();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_testPoint
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2Fixture* f = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->TestPoint(b2Vec2(x, y));
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_getShape
  (JNIEnv * env, jobject thiz) {
	b2Fixture* f = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)f->GetShape();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_setSensor
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2Fixture* f = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->SetSensor(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_isSensor
  (JNIEnv * env, jobject thiz) {
	b2Fixture* f = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->IsSensor();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_setFilterData
  (JNIEnv * env, jobject thiz, jobject f) {
	b2Fixture* fix = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Filter filter;
	filter.categoryBits = env->GetIntField(f, g_fid_Filter_categoryBits);
	filter.maskBits = env->GetIntField(f, g_fid_Filter_maskBits);
	filter.groupIndex = env->GetIntField(f, g_fid_Filter_groupIndex);
	fix->SetFilterData(filter);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_nativeGetFilterData
  (JNIEnv * env, jobject thiz, jobject f) {
	b2Fixture* fix = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Filter filter = fix->GetFilterData();
	env->SetIntField(f, g_fid_Filter_categoryBits, filter.categoryBits);
	env->SetIntField(f, g_fid_Filter_maskBits, filter.maskBits);
	env->SetIntField(f, g_fid_Filter_groupIndex, filter.groupIndex);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_nativeGetNext
  (JNIEnv * env, jobject thiz) {
	b2Fixture* f = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)f->GetNext();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_nativeRayCast
  (JNIEnv * env, jobject thiz, jobject output, jobject input, jint childIndex) {
	b2Fixture* f = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2RayCastOutput o;
	b2RayCastInput i;

	// set b2RayCastInput and perform ray cast
	jobject p1 = env->GetObjectField(input, g_fid_RayCastInput_p1);
	jobject p2 = env->GetObjectField(input, g_fid_RayCastInput_p2);
	i.p1.x = env->GetFloatField(p1, g_fid_WYPoint_x);
	i.p1.y = env->GetFloatField(p1, g_fid_WYPoint_y);
	i.p2.x = env->GetFloatField(p2, g_fid_WYPoint_x);
	i.p2.y = env->GetFloatField(p2, g_fid_WYPoint_y);
	i.maxFraction = env->GetFloatField(input, g_fid_RayCastInput_maxFraction);
	f->RayCast(&o, i, childIndex);
	env->DeleteLocalRef(p1);
	env->DeleteLocalRef(p2);

	// write back to output
	jobject normal = env->GetObjectField(output, g_fid_RayCastOutput_normal);
	env->SetFloatField(normal, g_fid_WYPoint_x, o.normal.x);
	env->SetFloatField(normal, g_fid_WYPoint_y, o.normal.y);
	env->SetFloatField(normal, g_fid_RayCastOutput_fraction, o.fraction);
	env->DeleteLocalRef(normal);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_nativeGetMassData
  (JNIEnv * env, jobject thiz, jobject d) {
	b2MassData data;
	b2Fixture* f = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->GetMassData(&data);

	jobject p = env->GetObjectField(d, g_fid_MassData_center);
	env->SetFloatField(d, g_fid_MassData_mass, data.mass);
	env->SetFloatField(p, g_fid_WYPoint_x, data.center.x);
	env->SetFloatField(p, g_fid_WYPoint_y, data.center.y);
	env->SetFloatField(d, g_fid_MassData_I, data.I);
	env->DeleteLocalRef(p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_setDensity
  (JNIEnv * env, jobject thiz, jfloat density) {
	b2Fixture* f = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->SetDensity(density);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_getDensity
  (JNIEnv * env, jobject thiz) {
	b2Fixture* f = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->GetDensity();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_getFriction
  (JNIEnv * env, jobject thiz) {
	b2Fixture* f = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->GetFriction();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_setFriction
  (JNIEnv * env, jobject thiz, jfloat friction) {
	b2Fixture* f = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->SetFriction(friction);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_getRestitution
  (JNIEnv * env, jobject thiz) {
	b2Fixture* f = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->GetRestitution();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_setRestitution
  (JNIEnv * env, jobject thiz, jfloat res) {
	b2Fixture* f = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->SetRestitution(res);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_nativeGetAABB
  (JNIEnv * env, jobject thiz, jobject aabb, jint childIndex) {
	b2Fixture* f = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2AABB ab = f->GetAABB(childIndex);

	jobject lb = env->GetObjectField(aabb, g_fid_AABB_lowerBound);
	jobject ub = env->GetObjectField(aabb, g_fid_AABB_upperBound);
	env->SetFloatField(lb, g_fid_WYPoint_x, ab.lowerBound.x);
	env->SetFloatField(lb, g_fid_WYPoint_y, ab.lowerBound.y);
	env->SetFloatField(ub, g_fid_WYPoint_x, ab.upperBound.x);
	env->SetFloatField(ub, g_fid_WYPoint_y, ab.upperBound.y);
	env->DeleteLocalRef(lb);
	env->DeleteLocalRef(ub);
}

JNIEXPORT jobject JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_getUserData
  (JNIEnv * env, jobject thiz) {
	b2Fixture* f = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->GetJavaUserData();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_setUserData
  (JNIEnv * env, jobject thiz, jobject data) {
	b2Fixture* f = (b2Fixture*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->SetJavaUserData(data);
}
