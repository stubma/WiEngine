#include "com_wiyun_engine_box2d_dynamics_Body.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;
extern jfieldID g_fid_Transform_q;
extern jfieldID g_fid_Transform_p;
extern jfieldID g_fid_Rotation_s;
extern jfieldID g_fid_Rotation_c;
extern jfieldID g_fid_MassData_mass;
extern jfieldID g_fid_MassData_center;
extern jfieldID g_fid_MassData_I;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeCreateFixture__Lcom_wiyun_engine_box2d_dynamics_FixtureDef_2
  (JNIEnv * env, jobject thiz, jobject fd) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2FixtureDef* def = (b2FixtureDef*)env->GetIntField(fd, g_fid_BaseObject_mPointer);
	return (jint)body->CreateFixture(def);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeCreateFixture__Lcom_wiyun_engine_box2d_collision_Shape_2F
  (JNIEnv * env, jobject thiz, jobject shape, jfloat density) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Shape* s = (b2Shape*)env->GetIntField(shape, g_fid_BaseObject_mPointer);
	return (jint)body->CreateFixture(s, density);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_getMass
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return body->GetMass();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_setAwake
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	body->SetAwake(flag);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_getType
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)body->GetType();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_setType
  (JNIEnv * env, jobject thiz, jint type) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	body->SetType((b2BodyType)type);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_getInertia
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return body->GetInertia();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_applyTorque
  (JNIEnv * env, jobject thiz, jfloat torque) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	body->ApplyTorque(torque);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_applyForce
  (JNIEnv * env, jobject thiz, jobject force, jobject point) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float x1 = env->GetFloatField(force, g_fid_WYPoint_x);
	float y1 = env->GetFloatField(force, g_fid_WYPoint_y);
	float x2 = env->GetFloatField(point, g_fid_WYPoint_x);
	float y2 = env->GetFloatField(point, g_fid_WYPoint_y);
	body->ApplyForce(b2Vec2(x1, y1), b2Vec2(x2, y2));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_applyForceToCenter
  (JNIEnv * env, jobject thiz, jobject force) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float x1 = env->GetFloatField(force, g_fid_WYPoint_x);
	float y1 = env->GetFloatField(force, g_fid_WYPoint_y);
	body->ApplyForceToCenter(b2Vec2(x1, y1));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_applyLinearImpulse
  (JNIEnv * env, jobject thiz, jobject impulse, jobject point) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float x1 = env->GetFloatField(impulse, g_fid_WYPoint_x);
	float y1 = env->GetFloatField(impulse, g_fid_WYPoint_y);
	float x2 = env->GetFloatField(point, g_fid_WYPoint_x);
	float y2 = env->GetFloatField(point, g_fid_WYPoint_y);
	body->ApplyLinearImpulse(b2Vec2(x1, y1), b2Vec2(x2, y2));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_applyAngularImpulse
  (JNIEnv * env, jobject thiz, jfloat impulse) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	body->ApplyAngularImpulse(impulse);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeGetWorldVector
  (JNIEnv * env, jobject thiz, jobject ret, jfloat x, jfloat y) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 v = body->GetWorldVector(b2Vec2(x, y));
	env->SetFloatField(ret, g_fid_WYPoint_x, v.x);
	env->SetFloatField(ret, g_fid_WYPoint_y, v.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeGetWorldPoint
  (JNIEnv * env, jobject thiz, jobject ret, jfloat x, jfloat y) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 v = body->GetWorldPoint(b2Vec2(x, y));
	env->SetFloatField(ret, g_fid_WYPoint_x, v.x);
	env->SetFloatField(ret, g_fid_WYPoint_y, v.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_setLinearVelocity
  (JNIEnv * env, jobject thiz, jobject v) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float x = env->GetFloatField(v, g_fid_WYPoint_x);
	float y = env->GetFloatField(v, g_fid_WYPoint_y);
	body->SetLinearVelocity(b2Vec2(x, y));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeGetLinearVelocity
  (JNIEnv * env, jobject thiz, jobject v) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 bv = body->GetLinearVelocity();
	env->SetFloatField(v, g_fid_WYPoint_x, bv.x);
	env->SetFloatField(v, g_fid_WYPoint_y, bv.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeGetTransform
  (JNIEnv * env, jobject thiz, jobject t) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Transform trans = body->GetTransform();
	jobject q = env->GetObjectField(t, g_fid_Transform_q);
	jobject p = env->GetObjectField(t, g_fid_Transform_p);
	env->SetFloatField(q, g_fid_Rotation_s, trans.q.s);
	env->SetFloatField(q, g_fid_Rotation_c, trans.q.c);
	env->SetFloatField(p, g_fid_WYPoint_x, trans.p.x);
	env->SetFloatField(p, g_fid_WYPoint_y, trans.p.y);
	env->DeleteLocalRef(q);
	env->DeleteLocalRef(p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_setAngularVelocity
  (JNIEnv * env, jobject thiz, jfloat v) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	body->SetAngularVelocity(v);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_getAngularVelocity
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return body->GetAngularVelocity();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeGetWorldCenter
  (JNIEnv * env, jobject thiz, jobject c) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 bv = body->GetWorldCenter();
	env->SetFloatField(c, g_fid_WYPoint_x, bv.x);
	env->SetFloatField(c, g_fid_WYPoint_y, bv.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeGetLocalCenter
  (JNIEnv * env, jobject thiz, jobject c) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 bv = body->GetLocalCenter();
	env->SetFloatField(c, g_fid_WYPoint_x, bv.x);
	env->SetFloatField(c, g_fid_WYPoint_y, bv.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_destroyFixture
  (JNIEnv * env, jobject thiz, jobject f) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Fixture* fix = (b2Fixture*)env->GetIntField(f, g_fid_BaseObject_mPointer);
	body->DestroyFixture(fix);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeGetPosition
  (JNIEnv * env, jobject thiz, jobject p) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 bv = body->GetPosition();
	env->SetFloatField(p, g_fid_WYPoint_x, bv.x);
	env->SetFloatField(p, g_fid_WYPoint_y, bv.y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_getAngle
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return body->GetAngle();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_setTransform
  (JNIEnv * env, jobject thiz, jfloat px, jfloat py, jfloat angle) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	body->SetTransform(b2Vec2(px, py), angle);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_isAwake
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return body->IsAwake();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeGetNext
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)body->GetNext();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeGetLocalPoint
  (JNIEnv * env, jobject thiz, jobject p, jfloat x, jfloat y) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 local = body->GetLocalPoint(b2Vec2(x, y));
	env->SetFloatField(p, g_fid_WYPoint_x, local.x);
	env->SetFloatField(p, g_fid_WYPoint_y, local.y);
}

JNIEXPORT jobject JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_getUserData
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return body->GetJavaUserData();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_setUserData
  (JNIEnv * env, jobject thiz, jobject data) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	body->SetJavaUserData(data);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeGetMassData
  (JNIEnv * env, jobject thiz, jobject d) {
	b2MassData data;
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	body->GetMassData(&data);

	jobject p = env->GetObjectField(d, g_fid_MassData_center);
	env->SetFloatField(d, g_fid_MassData_mass, data.mass);
	env->SetFloatField(p, g_fid_WYPoint_x, data.center.x);
	env->SetFloatField(p, g_fid_WYPoint_y, data.center.y);
	env->SetFloatField(d, g_fid_MassData_I, data.I);
	env->DeleteLocalRef(p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_setMassData
  (JNIEnv * env, jobject thiz, jobject d) {
	b2MassData data;
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);

	jobject p = env->GetObjectField(d, g_fid_MassData_center);
	data.mass = env->GetFloatField(d, g_fid_MassData_mass);
	data.I = env->GetFloatField(d, g_fid_MassData_I);
	data.center.x = env->GetFloatField(p, g_fid_WYPoint_x);
	data.center.y = env->GetFloatField(p, g_fid_WYPoint_y);
	env->DeleteLocalRef(p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_resetMassData
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	body->ResetMassData();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeGetLocalVector
  (JNIEnv * env, jobject thiz, jobject p, jfloat x, jfloat y) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 v = body->GetLocalVector(b2Vec2(x, y));
	env->SetFloatField(p, g_fid_WYPoint_x, v.x);
	env->SetFloatField(p, g_fid_WYPoint_y, v.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeGetLinearVelocityFromWorldPoint
  (JNIEnv * env, jobject thiz, jobject p, jfloat x, jfloat y) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 v = body->GetLinearVelocityFromWorldPoint(b2Vec2(x, y));
	env->SetFloatField(p, g_fid_WYPoint_x, v.x);
	env->SetFloatField(p, g_fid_WYPoint_y, v.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeGetLinearVelocityFromLocalPoint
  (JNIEnv * env, jobject thiz, jobject p, jfloat x, jfloat y) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 v = body->GetLinearVelocityFromLocalPoint(b2Vec2(x, y));
	env->SetFloatField(p, g_fid_WYPoint_x, v.x);
	env->SetFloatField(p, g_fid_WYPoint_y, v.y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_getLinearDamping
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return body->GetLinearDamping();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_setLinearDamping
  (JNIEnv * env, jobject thiz, jfloat damping) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	body->SetLinearDamping(damping);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_getAngularDamping
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	body->GetAngularDamping();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_setAngularDamping
  (JNIEnv * env, jobject thiz, jfloat damping) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	body->SetLinearDamping(damping);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_setBullet
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	body->SetBullet(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_isBullet
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return body->IsBullet();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_setSleepingAllowed
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	body->SetSleepingAllowed(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_isSleepingAllowed
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return body->IsSleepingAllowed();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_setActive
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	body->SetActive(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_isActive
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return body->IsActive();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_setFixedRotation
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	body->SetFixedRotation(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_isFixedRotation
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return body->IsFixedRotation();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeGetFirstFixture
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)body->GetFixtureList();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeGetFirstJointEdge
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)body->GetJointList();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeGetContactEdge
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)body->GetContactList();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_Body_nativeGetWorld
  (JNIEnv * env, jobject thiz) {
	b2Body* body = (b2Body*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)body->GetWorld();
}
