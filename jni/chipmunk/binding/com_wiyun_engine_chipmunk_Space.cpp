#include "com_wiyun_engine_chipmunk_Space.h"
#include "wyJNI.h"
#include "chipmunk.h"

#include "wyLog.h"

extern jfieldID g_fid_Space_mPointer;
extern jfieldID g_fid_Body_mPointer;
extern jfieldID g_fid_Shape_mPointer;
extern jfieldID g_fid_Constraint_mPointer;
extern jfieldID g_fid_SegmentQueryInfo_shapePointer;
extern jfieldID g_fid_SegmentQueryInfo_distance;
extern jfieldID g_fid_SegmentQueryInfo_normalX;
extern jfieldID g_fid_SegmentQueryInfo_normalY;
extern jmethodID g_mid_IBodyVisitor_visit;
extern jmethodID g_mid_ICollisionHandler_begin;
extern jmethodID g_mid_ICollisionHandler_preSolve;
extern jmethodID g_mid_ICollisionHandler_postSolve;
extern jmethodID g_mid_ICollisionHandler_separate;
extern jmethodID g_mid_IPostStepCallback_postStep;
extern jmethodID g_mid_IPointQueryCallback_onMatch;
extern jmethodID g_mid_ISegmentQueryCallback_onMatch;

// cache for body shapes
static cpArray* _sShapes = NULL;

static void segmentQueryFunc(cpShape *shape, cpFloat t, cpVect n, void* data) {
    JNIEnv* env = getEnv();
    if(env == NULL)
    	return;

    wyHandlerWrap* wrap = (wyHandlerWrap*)data;
	env->CallObjectMethod(wrap->handler, g_mid_ISegmentQueryCallback_onMatch, (jint)shape, t, n.x, n.y, wrap->data);
}

static void pointQueryFunc(cpShape *shape, void* data) {
    JNIEnv* env = getEnv();
    if(env == NULL)
    	return;

    wyHandlerWrap* wrap = (wyHandlerWrap*)data;
	env->CallVoidMethod(wrap->handler, g_mid_IPointQueryCallback_onMatch, (jint)shape, wrap->data);
}

void jni_postStep(cpSpace *space, void* obj, void* data) {
    JNIEnv* env = getEnv();
    if(env == NULL)
    	return;

    wyHandlerWrap* wrap = (wyHandlerWrap*)data;
	env->CallVoidMethod(wrap->handler, g_mid_IPostStepCallback_postStep, obj, wrap->data);
	env->DeleteGlobalRef(wrap->handler);
	env->DeleteGlobalRef(wrap->data);
	if(obj)
		env->DeleteGlobalRef((jobject)obj);
}

static void visitBody(cpBody *body, void* data) {
    JNIEnv* env = getEnv();
    if(env == NULL)
    	return;

    // get visitor and data
	wyHandlerWrap* v = (wyHandlerWrap*)data;
	env->CallVoidMethod(v->handler, g_mid_IBodyVisitor_visit, (jint)body, v->data);
}

// wrapper for collision handler
int jni_begin(cpArbiter *arb, cpSpace *space, void* data) {
    JNIEnv* env = getEnv();
    if(env == NULL)
    	return 1;

	wyHandlerWrap* wrap = (wyHandlerWrap*)data;
	return env->CallIntMethod(wrap->handler, g_mid_ICollisionHandler_begin, (jint)arb, (jint)space, wrap->data);
}

static int jni_preSolve(cpArbiter *arb, cpSpace *space, void* data) {
    JNIEnv* env = getEnv();
    if(env == NULL)
    	return 1;

    wyHandlerWrap* wrap = (wyHandlerWrap*)data;
	return env->CallIntMethod(wrap->handler, g_mid_ICollisionHandler_preSolve, (jint)arb, (jint)space, wrap->data);
}

static void jni_postSolve(cpArbiter *arb, cpSpace *space, void* data) {
    JNIEnv* env = getEnv();
    if(env == NULL)
    	return;

    wyHandlerWrap* wrap = (wyHandlerWrap*)data;
	env->CallVoidMethod(wrap->handler, g_mid_ICollisionHandler_postSolve, (jint)arb, (jint)space, wrap->data);
}

static void jni_separate(cpArbiter *arb, cpSpace *space, void* data) {
    JNIEnv* env = getEnv();
    if(env == NULL)
    	return;

    wyHandlerWrap* wrap = (wyHandlerWrap*)data;
	env->CallVoidMethod(wrap->handler, g_mid_ICollisionHandler_separate, (jint)arb, (jint)space, wrap->data);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_scheduleRemoveAndDestroyShapeAndBody
  (JNIEnv * env, jobject thiz, jobject shape) {
	// get space and shape
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpShape* shapeStruct = (cpShape*)env->GetIntField(shape, g_fid_Shape_mPointer);
	cpSpacePostStepRemoveAndFreeShapeAndBody(space, shapeStruct);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Space_nativeGetAnyShape
  (JNIEnv * env, jobject thiz, jobject body) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpBody* bodyStruct = (cpBody*)env->GetIntField(body, g_fid_Body_mPointer);
	return (jint)bodyStruct->shapesList;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_visitBody
  (JNIEnv * env, jobject thiz, jobject visitor, jobject data) {
	// get space
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	wyHandlerWrap v = { visitor, data };
	cpSpaceEachBody(space, &visitBody, (void*)&v);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_init(JNIEnv * env, jobject thiz) {
	cpSpace* space = cpSpaceNew();
	env->SetIntField(thiz, g_fid_Space_mPointer, (jint)space);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Space_getBodyCount
  (JNIEnv * env, jobject thiz) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	return space->bodies->num;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_resizeActiveHash(JNIEnv * env, jobject thiz, jfloat dim, jint count) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpSpaceResizeActiveHash(space, dim, count);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_resizeStaticHash
  (JNIEnv * env, jobject thiz, jfloat dim, jint count) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpSpaceResizeStaticHash(space, dim, count);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_nativeGetBodies
  (JNIEnv * env, jobject thiz, jintArray pointers) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	int* p = env->GetIntArrayElements(pointers, NULL);
	for(int i = 0; i < space->bodies->num; i++) {
		p[i] = (int)cpArrayGet(space->bodies, i);
	}
	env->ReleaseIntArrayElements(pointers, p, 0);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_addBody(JNIEnv * env, jobject thiz, jobject body) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpBody* bodyStruct = (cpBody*)env->GetIntField(body, g_fid_Body_mPointer);
	cpSpaceAddBody(space, bodyStruct);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_removeAndDestroyBody
  (JNIEnv * env, jobject thiz, jobject body) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpBody* bodyStruct = (cpBody*)env->GetIntField(body, g_fid_Body_mPointer);
	cpSpaceRemoveAndDestroyShapesOfBody(space, bodyStruct);
	cpSpaceRemoveBody(space, bodyStruct);
	cpBodyFree(bodyStruct);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_removeAndDestroyShapesOfBody
  (JNIEnv * env, jobject thiz, jobject body) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpBody* bodyStruct = (cpBody*)env->GetIntField(body, g_fid_Body_mPointer);
	cpSpaceRemoveAndDestroyShapesOfBody(space, bodyStruct);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_removeBody
  (JNIEnv * env, jobject thiz, jobject body) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpBody* bodyStruct = (cpBody*)env->GetIntField(body, g_fid_Body_mPointer);
	cpSpaceRemoveBody(space, bodyStruct);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_addShape(JNIEnv * env, jobject thiz, jobject shape) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpShape* shapeStruct = (cpShape*)env->GetIntField(shape, g_fid_Shape_mPointer);
	cpSpaceAddShape(space, shapeStruct);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_removeShape
  (JNIEnv * env, jobject thiz, jobject shape) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpShape* shapeStruct = (cpShape*)env->GetIntField(shape, g_fid_Shape_mPointer);
	cpSpaceRemoveShape(space, shapeStruct);
	cpSpaceRemoveStaticShape(space, shapeStruct);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_addStaticShape(JNIEnv * env, jobject thiz, jobject shape) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpShape* shapeStruct = (cpShape*)env->GetIntField(shape, g_fid_Shape_mPointer);
	cpSpaceAddStaticShape(space, shapeStruct);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_removeStaticShape
  (JNIEnv * env, jobject thiz, jobject shape) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpShape* shapeStruct = (cpShape*)env->GetIntField(shape, g_fid_Shape_mPointer);
	cpSpaceRemoveStaticShape(space, shapeStruct);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_setIterations(JNIEnv * env, jobject thiz, jint iterations) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	space->iterations = iterations;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_setElasticIterations
  (JNIEnv * env, jobject thiz, jint iterations) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	space->elasticIterations = iterations;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_step(JNIEnv * env, jobject thiz, jfloat delta) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpSpaceStep(space, delta);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_addConstraint(JNIEnv * env, jobject thiz, jobject constraint) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpConstraint* constraintStruct = (cpConstraint*)env->GetIntField(constraint, g_fid_Constraint_mPointer);
	cpSpaceAddConstraint(space, constraintStruct);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_removeConstraint
  (JNIEnv * env, jobject thiz, jobject constraint) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpConstraint* constraintStruct = (cpConstraint*)env->GetIntField(constraint, g_fid_Constraint_mPointer);
	cpSpaceRemoveConstraint(space, constraintStruct);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_addCollisionHandler
  (JNIEnv * env, jobject thiz, jint a, jint b, jobject handler, jobject data) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	wyHandlerWrap* wrap = (wyHandlerWrap*)calloc(1, sizeof(wyHandlerWrap));
	wrap->handler = env->NewGlobalRef(handler);
	wrap->data = env->NewGlobalRef(data);
	cpSpaceAddCollisionHandler_jni(space,
			a,
			b,
			jni_begin,
			jni_preSolve,
			jni_postSolve,
			jni_separate,
			(void*)wrap);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_removeCollisionHandler
  (JNIEnv * env, jobject thiz, jint collisionType1, jint collisionType2) {
	// get space
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpSpaceRemoveCollisionHandler_jni(space, collisionType1, collisionType2);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_setGravity
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	space->gravity.x = x;
	space->gravity.y = y;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Space_getGravityX
  (JNIEnv * env, jobject thiz) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	return space->gravity.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Space_getGravityY
  (JNIEnv * env, jobject thiz) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	return space->gravity.y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_destroy
  (JNIEnv * env, jobject thiz) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpSpaceFreeChildren(space);
	cpSpaceFree(space);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_querySegmentFirst
  (JNIEnv * env, jobject thiz, jfloat startX, jfloat startY, jfloat endX, jfloat endY, jint layer, jint group, jobject info) {
	// query
	cpSegmentQueryInfo qi = {};
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpSpaceSegmentQueryFirst(space, cpv(startX, startY), cpv(endX, endY), layer, group, &qi);

	env->SetIntField(info, g_fid_SegmentQueryInfo_shapePointer, (jint)qi.shape);
	env->SetFloatField(info, g_fid_SegmentQueryInfo_distance, qi.t);
	env->SetFloatField(info, g_fid_SegmentQueryInfo_normalX, qi.n.x);
	env->SetFloatField(info, g_fid_SegmentQueryInfo_normalY, qi.n.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_addPostStepCallback
  (JNIEnv * env, jobject thiz, jobject callback, jobject obj, jobject data) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	wyHandlerWrap* wrap = (wyHandlerWrap*)calloc(1, sizeof(wyHandlerWrap));
	wrap->handler = env->NewGlobalRef(callback);
	wrap->data = data == NULL ? NULL : env->NewGlobalRef(data);
	jobject g_obj = obj == NULL ? NULL : env->NewGlobalRef(obj);
	cpSpaceAddPostStepCallback(space, jni_postStep, g_obj, wrap);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_rehashStatic
  (JNIEnv * env, jobject thiz) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpSpaceRehashStatic(space);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Space_getStamp
  (JNIEnv * env, jobject thiz) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	return space->stamp;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_chipmunk_Space_isLocked
  (JNIEnv * env, jobject thiz) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	return space->locked == 1;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Space_getDamping
  (JNIEnv * env, jobject thiz) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	return space->damping;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_setDamping
  (JNIEnv * env, jobject thiz, jfloat damping) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	space->damping = damping;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Space_nativeQueryPointFirst
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y, jint layer, jint group) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	return (jint)cpSpacePointQueryFirst(space, cpv(x, y), layer, group);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_queryPoint
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y, jint layer, jint group, jobject callback, jobject data) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	wyHandlerWrap wrap = { callback, data };
	cpSpacePointQuery(space, cpv(x, y), layer, group, pointQueryFunc, (void*)&wrap);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_querySegment
  (JNIEnv * env, jobject thiz, jfloat startX, jfloat startY, jfloat endX, jfloat endY, jint layer, jint group, jobject callback, jobject data) {
	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	wyHandlerWrap wrap = { callback, data };
	cpSpaceSegmentQuery(space, cpv(startX, startY), cpv(endX, endY), layer, group, segmentQueryFunc, (void*)&wrap);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Space_prepareShapesOfBody
  (JNIEnv * env, jobject thiz, jobject body) {
	if(_sShapes != NULL) {
		cpArrayFree(_sShapes);
		_sShapes = NULL;
	}

	cpSpace* space = (cpSpace*)env->GetIntField(thiz, g_fid_Space_mPointer);
	cpBody* bodyStruct = (cpBody*)env->GetIntField(body, g_fid_Body_mPointer);
	_sShapes = cpSpaceGetShapesOfBody(space, bodyStruct);
	return _sShapes->num;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Space_cleanShapesOfBody
  (JNIEnv * env, jobject thiz, jobject body) {
	if(_sShapes != NULL) {
		cpArrayFree(_sShapes);
		_sShapes = NULL;
	}
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Space_getShapeOfBody
  (JNIEnv * env, jobject thiz, jint index) {
	return _sShapes == NULL ? 0 : (jint)cpArrayGet(_sShapes, index);
}
