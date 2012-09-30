#include "com_wiyun_engine_chipmunk_Body.h"
#include "chipmunk.h"
#include <stdlib.h>
#include "wyJNI.h"

extern jfieldID g_fid_Body_mPointer;
extern jmethodID g_mid_IVelocityUpdater_updateVelocity;
extern jmethodID g_mid_IPositionUpdater_updatePosition;

static void velocityFunc(cpBody *body, cpVect gravity, cpFloat damping, cpFloat dt) {
    JNIEnv* env = getEnv();
    if(env == NULL)
    	return;

	env->CallVoidMethod(body->velocityUpdater, g_mid_IVelocityUpdater_updateVelocity,
			(jint)body, gravity.x, gravity.y, damping, dt);
}

static void positionFunc(cpBody *body, cpFloat dt) {
    JNIEnv* env = getEnv();
    if(env == NULL)
    	return;

	env->CallVoidMethod(body->positionUpdater, g_mid_IPositionUpdater_updatePosition, (jint)body, dt);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_init(JNIEnv * env, jobject thiz, jfloat mass, jfloat momentOfInertia) {
    cpBody* body = NULL;
    if(mass == INFINITY && momentOfInertia == INFINITY)
        body = cpBodyNewStatic();
    else
        body = cpBodyNew(mass, momentOfInertia);
    
	env->SetIntField(thiz, g_fid_Body_mPointer, (jint)body);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_setPosition(JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	body->p = cpv(x, y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getPositionX
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->p.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getPositionY
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->p.y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_setVelocity(JNIEnv * env, jobject thiz, jfloat xVel, jfloat yVel) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	body->v = cpv(xVel, yVel);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getVelocityX
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->v.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getVelocityY
	(JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->v.y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_setAngle
  (JNIEnv * env, jobject thiz, jfloat angle) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	cpBodySetAngle(body, angle);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getAngle
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->a;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getAngleUnitVectorX
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->rot.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getAngllUnitVectorY
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->rot.y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_setAngularVelocity
  (JNIEnv * env, jobject thiz, jfloat v) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	body->w = v;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getAngularVelocity
  (JNIEnv * env , jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->w;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_setTorque
  (JNIEnv * env, jobject thiz, jfloat torque) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	body->t = torque;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getTorque
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->t;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_updateVelocity
  (JNIEnv * env, jobject thiz, jfloat gravityX, jfloat gravityY, jfloat damping, jfloat delta) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	cpBodyUpdateVelocity(body, cpv(gravityX, gravityY), damping, delta);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_updatePosition
	(JNIEnv * env, jobject thiz, jfloat delta) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	cpBodyUpdatePosition(body, delta);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_setVelocityUpdater
  (JNIEnv * env, jobject thiz, jobject updater) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);

	if(body->velocityUpdater != NULL) {
		env->DeleteGlobalRef(body->velocityUpdater);
		body->velocityUpdater = NULL;
	}

	if(updater == NULL) {
		body->velocity_func = cpBodyUpdateVelocityDefault;
	} else {
		body->velocity_func = velocityFunc;
		body->velocityUpdater = env->NewGlobalRef(updater);
	}
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_setPositionUpdater
  (JNIEnv * env, jobject thiz, jobject updater) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);

	if(body->positionUpdater != NULL) {
		env->DeleteGlobalRef(body->positionUpdater);
		body->positionUpdater = NULL;
	}

	if(updater == NULL) {
		body->position_func = cpBodyUpdatePositionDefault;
	} else {
		body->position_func = positionFunc;
		body->positionUpdater = env->NewGlobalRef(updater);
	}
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getMass
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->m;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_setMass
  (JNIEnv * env, jobject thiz, jfloat mass) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	body->m = mass;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getMassInverse
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->m_inv;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_setMomentOfInertia
  (JNIEnv * env, jobject thiz, jfloat moment) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	cpBodySetMoment(body, moment);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getMomentOfInertia
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->i;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getMomentOfInertiaInverse
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->i_inv;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_setForce
  (JNIEnv * env, jobject thiz, jfloat fx, jfloat fy) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	body->f = cpv(fx, fy);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getForceX
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->f.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getForceY
(JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->f.y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_destroy
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	cpBodyFree(body);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_setData
  (JNIEnv * env, jobject thiz, jobject data) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	if(body->j_data != NULL) {
		env->DeleteGlobalRef(body->j_data);
		body->j_data = NULL;
	}
	body->j_data = env->NewGlobalRef(data);
}

JNIEXPORT jobject JNICALL Java_com_wiyun_engine_chipmunk_Body_getData
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->j_data;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_nativeApplyForce
  (JNIEnv * env, jobject thiz, jfloat forceX, jfloat forceY, jfloat radiusX, jfloat radiusY) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	cpBodyApplyForce(body, cpv(forceX, forceY), cpv(radiusX, radiusY));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_resetForces
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	cpBodyResetForces(body);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_setVelocityBias
  (JNIEnv * env, jobject thiz, jfloat biasX, jfloat biasY) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	body->v_bias = cpv(biasX, biasY);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getVelocityBiasX
 (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->v_bias.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getVelocityBiasY
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->v_bias.y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_setAngularVelocityBias
  (JNIEnv * env, jobject thiz, jfloat bias) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	body->w_bias = bias;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getAngularVelocityBias
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->w_bias;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getMaxVelocity
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->v_limit;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_setMaxVelocity
  (JNIEnv * env, jobject thiz, jfloat max) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	body->v_limit = max;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Body_getMaxAngularVelocity
  (JNIEnv * env, jobject thiz) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	return body->w_limit;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_setMaxAngularVelocity
  (JNIEnv * env, jobject thiz, jfloat max) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	body->w_limit = max;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_slew
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y, jfloat delta) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	cpBodySlew(body, cpv(x, y), delta);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Body_applyImpulse
  (JNIEnv * env, jobject thiz, jfloat impulseX, jfloat impulseY, jfloat directionX, jfloat directionY) {
	cpBody* body = (cpBody*)env->GetIntField(thiz, g_fid_Body_mPointer);
	cpBodyApplyImpulse(body, cpv(impulseX, impulseY), cpv(directionX, directionY));
}
