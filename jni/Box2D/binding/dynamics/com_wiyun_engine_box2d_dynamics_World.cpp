#include "com_wiyun_engine_box2d_dynamics_World.h"
#include "wyBox2D.h"
#include "wyJNI.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;
extern jmethodID g_mid_IQueryCallback_reportFixture;
extern jmethodID g_mid_IContactListener_beginContact;
extern jmethodID g_mid_IContactListener_endContact;
extern jmethodID g_mid_IContactListener_preSolve;
extern jmethodID g_mid_IContactListener_postSolve;
extern jmethodID g_mid_IRayCastListener_reportFixture;
extern jmethodID g_mid_IDestructionListener_jointSayGoodbye;
extern jmethodID g_mid_IDestructionListener_fixtureSayGoodbye;

class QueryCallback: public b2QueryCallback {
private:
	jobject m_jcallback;

public:
	QueryCallback(jobject jcb) {
		m_jcallback = jcb;
	}

	virtual ~QueryCallback() {
	}

	virtual bool ReportFixture(b2Fixture* fixture) {
		JNIEnv* env = getEnv();
		if(env == NULL) {
			return false;
		} else {
			return env->CallBooleanMethod(m_jcallback, g_mid_IQueryCallback_reportFixture, (jint)fixture);
		}
	}
};

class RayCastCallback : public b2RayCastCallback
{
public:
	jobject m_jcallback;

public:
	RayCastCallback(jobject jcb) {
		m_jcallback = jcb;
	}

	virtual ~RayCastCallback() {
	}

	float32 ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction) {
		JNIEnv* env = getEnv();
		if(env == NULL) {
			return 0;
		} else {
			return env->CallFloatMethod(m_jcallback, g_mid_IRayCastListener_reportFixture, (jint)fixture,
					point.x, point.y, normal.x, normal.y, fraction);
		}
	}
};

class DestructionListener : public b2DestructionListener {
private:
	jobject m_jdl;

public:
	DestructionListener(jobject jdl) {
		JNIEnv* env = getEnv();
		m_jdl = env->NewGlobalRef(jdl);
	}

	virtual ~DestructionListener() {
		JNIEnv* env = getEnv();
		if(env != NULL) {
			env->DeleteGlobalRef(m_jdl);
			m_jdl = NULL;
		}
	}

	virtual void SayGoodbye(b2Joint* joint) {
		JNIEnv* env = getEnv();
		if(env != NULL)
			env->CallVoidMethod(m_jdl, g_mid_IDestructionListener_jointSayGoodbye, (jint)joint);
	}

	virtual void SayGoodbye(b2Fixture* fixture) {
		JNIEnv* env = getEnv();
		if(env != NULL)
			env->CallVoidMethod(m_jdl, g_mid_IDestructionListener_fixtureSayGoodbye, (jint)fixture);
	}
};

class ContactListener : public b2ContactListener {
private:
	jobject m_jcl;

public:
	ContactListener(jobject jcl) {
		JNIEnv* env = getEnv();
		m_jcl = env->NewGlobalRef(jcl);
	}

	virtual ~ContactListener() {
		JNIEnv* env = getEnv();
		if(env != NULL) {
			env->DeleteGlobalRef(m_jcl);
			m_jcl = NULL;
		}
	}

	virtual void BeginContact(b2Contact* contact) {
		JNIEnv* env = getEnv();
		if(env != NULL)
			env->CallVoidMethod(m_jcl, g_mid_IContactListener_beginContact, (jint)contact);
	}

	virtual void EndContact(b2Contact* contact) {
		JNIEnv* env = getEnv();
		if(env != NULL)
			env->CallVoidMethod(m_jcl, g_mid_IContactListener_endContact, (jint)contact);
	}

	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) {
		JNIEnv* env = getEnv();
		if(env != NULL)
			env->CallVoidMethod(m_jcl, g_mid_IContactListener_preSolve, (jint)contact, (jint)oldManifold);
	}

	virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) {
		JNIEnv* env = getEnv();
		if(env != NULL)
			env->CallVoidMethod(m_jcl, g_mid_IContactListener_postSolve, (jint)contact, (jint)impulse);
	}
};

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_World_setContactListener
  (JNIEnv * env, jobject thiz, jobject listener) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	if(world->m_jclWrap != NULL) {
		delete world->m_jclWrap;
		world->m_jclWrap = NULL;
	}
	if(listener != NULL) {
		ContactListener* cl = new ContactListener(listener);
		world->m_jclWrap = cl;
		world->SetContactListener(cl);
	}
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_World_setDestructionListener
  (JNIEnv * env, jobject thiz, jobject listener) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	if(world->m_jdlWrap != NULL) {
		delete world->m_jdlWrap;
		world->m_jdlWrap = NULL;
	}
	if(listener != NULL) {
		DestructionListener* dl = new DestructionListener(listener);
		world->m_jdlWrap = dl;
		world->SetDestructionListener(dl);
	}
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_World_setGravity
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	world->SetGravity(b2Vec2(x, y));
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_World_nativeCreateBody
  (JNIEnv * env, jobject thiz, jobject bd) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2BodyDef* def = (b2BodyDef*)env->GetIntField(bd, g_fid_BaseObject_mPointer);
	return (jint)world->CreateBody(def);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_World_createJoint
  (JNIEnv * env, jobject thiz, jobject jd) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2JointDef* def = (b2JointDef*)env->GetIntField(jd, g_fid_BaseObject_mPointer);
	return (jint)world->CreateJoint(def);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_World_createController
  (JNIEnv * env, jobject thiz, jobject cd) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2ControllerDef* def = (b2ControllerDef*)env->GetIntField(cd, g_fid_BaseObject_mPointer);
	return (jint)world->CreateController(def);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_World_destroyController
  (JNIEnv * env, jobject thiz, jobject controller) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Controller* c = (b2Controller*)env->GetIntField(controller, g_fid_BaseObject_mPointer);
	world->DestroyController(c);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_World_step
  (JNIEnv * env, jobject thiz, jfloat timeStep, jint velocityIterations, jint positionIterations) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	world->Step(timeStep, velocityIterations, positionIterations);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_World_clearForces
  (JNIEnv * env, jobject thiz) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	world->ClearForces();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_World_queryAABB
  (JNIEnv * env, jobject thiz, jobject callback, jfloat lbX, jfloat lbY, jfloat upX, jfloat upY) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);

	// create callback
	QueryCallback* qc = new QueryCallback(callback);

	// create b2AABB
	b2AABB aabb;
	aabb.lowerBound = b2Vec2(lbX, lbY);
	aabb.upperBound = b2Vec2(upX, upY);

	// query
	world->QueryAABB(qc, aabb);

	// delete
	delete qc;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_World_destroyJoint
  (JNIEnv * env, jobject thiz, jobject joint) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Joint* j = (b2Joint*)env->GetIntField(joint, g_fid_BaseObject_mPointer);
	world->DestroyJoint(j);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_World_nativeGetFirstBody
  (JNIEnv * env, jobject thiz) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)world->GetBodyList();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_World_rayCast
  (JNIEnv * env, jobject thiz, jobject callback, jfloat startX, jfloat startY, jfloat endX, jfloat endY) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	RayCastCallback* cb = new RayCastCallback(callback);
	world->RayCast(cb, b2Vec2(startX, startY), b2Vec2(endX, endY));
	delete cb;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_World_destroyBody
  (JNIEnv * env, jobject thiz, jobject body) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Body* b = (b2Body*)env->GetIntField(body, g_fid_BaseObject_mPointer);
	world->DestroyBody(b);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_World_nativeGetFirstJoint
  (JNIEnv * env, jobject thiz) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)world->GetJointList();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_World_nativeGetFirstContact
  (JNIEnv * env, jobject thiz) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)world->GetContactList();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_World_setWarmStarting
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	world->SetWarmStarting(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_World_setContinuousPhysics
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	world->SetContinuousPhysics(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_World_setSubStepping
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	world->SetSubStepping(flag);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_World_getProxyCount
  (JNIEnv * env, jobject thiz) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return world->GetProxyCount();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_World_getBodyCount
  (JNIEnv * env, jobject thiz) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return world->GetBodyCount();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_World_getJointCount
  (JNIEnv * env, jobject thiz) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return world->GetJointCount();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_World_getContactCount
  (JNIEnv * env, jobject thiz) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return world->GetContactCount();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_World_nativeGetGravity
  (JNIEnv * env, jobject thiz, jobject g) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 v = world->GetGravity();
	env->SetFloatField(g, g_fid_WYPoint_x, v.x);
	env->SetFloatField(g, g_fid_WYPoint_y, v.y);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_World_isLocked
  (JNIEnv * env, jobject thiz) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return world->IsLocked();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_World_setAutoClearForces
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	world->SetAutoClearForces(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_World_getAutoClearForces
  (JNIEnv * env, jobject thiz) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return world->GetAutoClearForces();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_World_setNoSolidDraw
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	world->SetNoSolidDraw(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_World_setAllowSleeping
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	world->SetAllowSleeping(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_World_getAllowSleeping
  (JNIEnv * env, jobject thiz) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return world->GetAllowSleeping();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_World_getSubStepping
  (JNIEnv * env, jobject thiz) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return world->GetSubStepping();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_World_getWarmStarting
  (JNIEnv * env, jobject thiz) {
	b2World* world = (b2World*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return world->GetWarmStarting();
}
