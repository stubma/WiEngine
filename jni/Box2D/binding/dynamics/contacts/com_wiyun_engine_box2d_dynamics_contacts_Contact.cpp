#include "com_wiyun_engine_box2d_dynamics_contacts_Contact.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;
extern jfieldID g_fid_Transform_q;
extern jfieldID g_fid_Transform_p;
extern jfieldID g_fid_Rotation_s;
extern jfieldID g_fid_Rotation_c;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_Contact_nativeGetManifold
  (JNIEnv * env, jobject thiz) {
	b2Contact* c = (b2Contact*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)c->GetManifold();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_Contact_nativeGetFixtureA
  (JNIEnv* env, jobject thiz) {
	b2Contact* c = (b2Contact*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)c->GetFixtureA();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_Contact_nativeGetFixtureB
  (JNIEnv* env, jobject thiz) {
	b2Contact* c = (b2Contact*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)c->GetFixtureB();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_Contact_setEnabled
  (JNIEnv* env, jobject thiz, jboolean flag) {
	b2Contact* c = (b2Contact*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->SetEnabled(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_Contact_isTouching
  (JNIEnv * env, jobject thiz) {
	b2Contact* c = (b2Contact*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->IsTouching();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_Contact_isEnabled
  (JNIEnv * env, jobject thiz) {
	b2Contact* c = (b2Contact*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->IsEnabled();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_Contact_nativeGetNext
  (JNIEnv * env, jobject thiz) {
	b2Contact* c = (b2Contact*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)c->GetNext();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_Contact_getChildIndexA
  (JNIEnv * env, jobject thiz) {
	b2Contact* c = (b2Contact*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->GetChildIndexA();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_Contact_getChildIndexB
  (JNIEnv * env, jobject thiz) {
	b2Contact* c = (b2Contact*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->GetChildIndexB();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_Contact_nativeEvaluate
  (JNIEnv * env, jobject thiz, jobject xfA, jobject xfB) {
	b2Contact* c = (b2Contact*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Manifold* manifold = new b2Manifold();

	b2Transform t1, t2;
	jobject q = env->GetObjectField(xfA, g_fid_Transform_q);
	jobject p = env->GetObjectField(xfA, g_fid_Transform_p);
	t1.q.s = env->GetFloatField(q, g_fid_Rotation_s);
	t1.q.c = env->GetFloatField(q, g_fid_Rotation_c);
	t1.p.x = env->GetFloatField(p, g_fid_WYPoint_x);
	t1.p.y = env->GetFloatField(p, g_fid_WYPoint_y);
	env->DeleteLocalRef(q);
	env->DeleteLocalRef(p);

	q = env->GetObjectField(xfB, g_fid_Transform_q);
	p = env->GetObjectField(xfB, g_fid_Transform_p);
	t2.q.s = env->GetFloatField(q, g_fid_Rotation_s);
	t2.q.c = env->GetFloatField(q, g_fid_Rotation_c);
	t2.p.x = env->GetFloatField(p, g_fid_WYPoint_x);
	t2.p.y = env->GetFloatField(p, g_fid_WYPoint_y);
	env->DeleteLocalRef(q);
	env->DeleteLocalRef(p);

	c->Evaluate(manifold, t1, t2);
	return (jint)manifold;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_Contact_setFriction
  (JNIEnv * env, jobject thiz, jfloat friction) {
	b2Contact* c = (b2Contact*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->SetFriction(friction);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_Contact_getFriction
  (JNIEnv * env, jobject thiz) {
	b2Contact* c = (b2Contact*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->GetFriction();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_Contact_resetFriction
  (JNIEnv * env, jobject thiz) {
	b2Contact* c = (b2Contact*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->ResetFriction();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_Contact_setRestitution
  (JNIEnv * env, jobject thiz, jfloat r) {
	b2Contact* c = (b2Contact*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->SetRestitution(r);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_Contact_getRestitution
  (JNIEnv * env, jobject thiz) {
	b2Contact* c = (b2Contact*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return c->GetRestitution();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_Contact_resetRestitution
  (JNIEnv * env, jobject thiz) {
	b2Contact* c = (b2Contact*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->ResetRestitution();
}
