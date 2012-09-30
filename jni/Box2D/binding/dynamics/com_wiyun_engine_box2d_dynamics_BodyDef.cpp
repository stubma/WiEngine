#include "com_wiyun_engine_box2d_dynamics_BodyDef.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_nativeNew
  (JNIEnv * env, jobject thiz) {
	b2BodyDef* bd = new b2BodyDef();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)bd);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_setPosition__FF
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	bd->position.Set(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_setPosition__Lcom_wiyun_engine_types_WYPoint_2
  (JNIEnv * env, jobject thiz, jobject p) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float x = env->GetFloatField(p, g_fid_WYPoint_x);
	float y = env->GetFloatField(p, g_fid_WYPoint_y);
	bd->position.Set(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_destroy
  (JNIEnv * env, jobject thiz) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	delete bd;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_setType
  (JNIEnv * env, jobject thiz, jint type) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	bd->type = (b2BodyType)type;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_getType
  (JNIEnv * env, jobject thiz) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return bd->type;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_setAngularDamping
  (JNIEnv * env, jobject thiz, jfloat damping) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	bd->angularDamping = damping;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_getAngularDamping
  (JNIEnv * env, jobject thiz) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return bd->angularDamping;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_setLinearDamping
  (JNIEnv * env, jobject thiz, jfloat damping) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	bd->linearDamping = damping;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_getLinearDamping
  (JNIEnv * env, jobject thiz) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return bd->linearDamping;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_setLinearVelocity
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	bd->linearVelocity = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_setAngularVelocity
  (JNIEnv * env, jobject thiz, jfloat v) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	bd->angularVelocity = v;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_setAngle
  (JNIEnv * env, jobject thiz, jfloat angle) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	bd->angle = angle;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_getAngle
  (JNIEnv * env, jobject thiz) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return bd->angle;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_setAllowSleep
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	bd->allowSleep = flag;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_isAllowSleep
  (JNIEnv * env, jobject thiz) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return bd->allowSleep;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_setBullet
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	bd->bullet = flag;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_isBullet
  (JNIEnv * env, jobject thiz) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return bd->bullet;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_setGravityScale
  (JNIEnv * env, jobject thiz, jfloat gravityScale) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	bd->gravityScale = gravityScale;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_getGravityScale
  (JNIEnv * env, jobject thiz) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return bd->gravityScale;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_setFixedRotation
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	bd->fixedRotation = flag;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_isFixedRotation
  (JNIEnv * env, jobject thiz) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return bd->fixedRotation;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_nativeGetPosition
  (JNIEnv * env, jobject thiz, jobject p) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, bd->position.x);
	env->SetFloatField(p, g_fid_WYPoint_y, bd->position.y);
}

JNIEXPORT jobject JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_getUserData
  (JNIEnv * env, jobject thiz) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return bd->j_userData;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_BodyDef_setUserData
  (JNIEnv * env, jobject thiz, jobject data) {
	b2BodyDef* bd = (b2BodyDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	if(bd->j_userData != NULL) {
		env->DeleteGlobalRef(bd->j_userData);
		bd->j_userData = NULL;
	}
	if(data != NULL) {
		bd->j_userData = env->NewGlobalRef(data);
	}
}
