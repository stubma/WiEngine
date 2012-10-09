/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "wyChipmunk.h"
#include "wyMemory.h"
#include "wyLog.h"

#if ANDROID

#include "wyJNI.h"
#define CLASS_SPACE "com/wiyun/engine/chipmunk/Space"
#define CLASS_BODY "com/wiyun/engine/chipmunk/Body"
#define CLASS_SHAPE "com/wiyun/engine/chipmunk/Shape"
#define CLASS_CONSTRAINT "com/wiyun/engine/chipmunk/Constraint"
#define CLASS_ARBITER "com/wiyun/engine/chipmunk/Arbiter"
#define CLASS_ITORQUEUPDATER "com/wiyun/engine/chipmunk/DampedRotarySpring$ITorqueUpdater"
#define CLASS_IFORCEUPDATER "com/wiyun/engine/chipmunk/DampedSpring$IForceUpdater"
#define CLASS_IVELOCITYUPDATER "com/wiyun/engine/chipmunk/Body$IVelocityUpdater"
#define CLASS_IPOSITIONUPDATER "com/wiyun/engine/chipmunk/Body$IPositionUpdater"
#define CLASS_IBODYVISITOR "com/wiyun/engine/chipmunk/Space$IBodyVisitor"
#define CLASS_IPOSTSTEPCALLBACK "com/wiyun/engine/chipmunk/Space$IPostStepCallback"
#define CLASS_IPOINTQUERYCALLBACK "com/wiyun/engine/chipmunk/Space$IPointQueryCallback"
#define CLASS_ISEGMENTQUERYCALLBACK "com/wiyun/engine/chipmunk/Space$ISegmentQueryCallback"
#define CLASS_SEGMENTQUERYINFO "com/wiyun/engine/chipmunk/Space$SegmentQueryInfo"
#define CLASS_ICOLLISIONHANDLER "com/wiyun/engine/chipmunk/ICollisionHandler"
#define CLASS_SHAPEANIMATION_CALLBACK "com/wiyun/engine/chipmunk/ShapeAnimation$Callback"

// required java ids
jfieldID g_fid_Space_mPointer;
jfieldID g_fid_Body_mPointer;
jfieldID g_fid_Shape_mPointer;
jfieldID g_fid_Constraint_mPointer;
jfieldID g_fid_Arbiter_mPointer;

jfieldID g_fid_SegmentQueryInfo_shapePointer;
jfieldID g_fid_SegmentQueryInfo_distance;
jfieldID g_fid_SegmentQueryInfo_normalX;
jfieldID g_fid_SegmentQueryInfo_normalY;

jmethodID g_mid_ITorqueUpdater_updateTorque;
jmethodID g_mid_IForceUpdater_updateForce;
jmethodID g_mid_IVelocityUpdater_updateVelocity;
jmethodID g_mid_IPositionUpdater_updatePosition;
jmethodID g_mid_IBodyVisitor_visit;
jmethodID g_mid_ICollisionHandler_begin;
jmethodID g_mid_ICollisionHandler_preSolve;
jmethodID g_mid_ICollisionHandler_postSolve;
jmethodID g_mid_ICollisionHandler_separate;
jmethodID g_mid_IPostStepCallback_postStep;
jmethodID g_mid_IPointQueryCallback_onMatch;
jmethodID g_mid_ISegmentQueryCallback_onMatch;
jmethodID g_mid_ShapeAnimationCallback_onAnimationEnd;
jmethodID g_mid_ShapeAnimationCallback_onAnimationAborted;

static bool sFirstChipmunk = true;

#endif // #if ANDROID

wyChipmunk::~wyChipmunk() {
	cpSpaceFreeChildren(m_space);
	cpSpaceFree(m_space);
}

void wyChipmunk::draw() {
	// if no draw flag is set, call wyNode::draw and it
	// will decide forward drawing to java layer or not
	if(m_noDraw) {
		wyNode::draw();
		return;
	}

	drawSpace(m_space, &m_options);
}

wyChipmunk* wyChipmunk::make() {
	wyChipmunk* c = WYNEW wyChipmunk();
	return (wyChipmunk*)c->autoRelease();
}

wyChipmunk::wyChipmunk() :
	m_space(cpSpaceNew()) {
	// set option
	// non-zero means use debug drawing logic
	m_options.debugDraw = 0;
	m_options.drawHash = 0;
	m_options.drawBBs = 0;
	m_options.drawShapes = 1;
	m_options.collisionPointSize = 0.f;
	m_options.bodyPointSize = 0.f;
	m_options.lineThickness = 1.0f;

	// init chipmunk
	cpInitChipmunk();

#if ANDROID

	// if first, we need init chipmunk and find field
	if(sFirstChipmunk) {
		// set flag
		sFirstChipmunk = false;

		// get env
		JNIEnv* env = getEnv();

		// no jar flag
		bool noJava = false;

		// find field ids
		jclass clazz = env->FindClass(CLASS_SPACE);
		if(env->ExceptionOccurred() != NULL) {
			env->ExceptionClear();
			noJava = true;
		} else {
			g_fid_Space_mPointer = env->GetFieldID(clazz, "mPointer", "I");
			env->DeleteLocalRef(clazz);
		}

		if(!noJava) {
			clazz = env->FindClass(CLASS_BODY);
			g_fid_Body_mPointer = env->GetFieldID(clazz, "mPointer", "I");(clazz, "mPointer");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_SHAPE);
			g_fid_Shape_mPointer = env->GetFieldID(clazz, "mPointer", "I");(clazz, "mPointer");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_CONSTRAINT);
			g_fid_Constraint_mPointer = env->GetFieldID(clazz, "mPointer", "I");(clazz, "mPointer");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_ARBITER);
			g_fid_Arbiter_mPointer = env->GetFieldID(clazz, "mPointer", "I");(clazz, "mPointer");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_ITORQUEUPDATER);
			g_mid_ITorqueUpdater_updateTorque = env->GetMethodID(clazz, "updateTorque", "(IF)F");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_IFORCEUPDATER);
			g_mid_IForceUpdater_updateForce = env->GetMethodID(clazz, "updateForce", "(IF)F");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_IVELOCITYUPDATER);
			g_mid_IVelocityUpdater_updateVelocity = env->GetMethodID(clazz, "updateVelocity", "(IFFFF)V");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_IPOSITIONUPDATER);
			g_mid_IPositionUpdater_updatePosition = env->GetMethodID(clazz, "updatePosition", "(IF)V");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_IBODYVISITOR);
			g_mid_IBodyVisitor_visit = env->GetMethodID(clazz, "visit", "(ILjava/lang/Object;)V");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_IPOSTSTEPCALLBACK);
			g_mid_IPostStepCallback_postStep = env->GetMethodID(clazz, "postStep", "(Ljava/lang/Object;Ljava/lang/Object;)V");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_IPOINTQUERYCALLBACK);
			g_mid_IPointQueryCallback_onMatch = env->GetMethodID(clazz, "onMatch", "(ILjava/lang/Object;)V");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_ISEGMENTQUERYCALLBACK);
			g_mid_ISegmentQueryCallback_onMatch = env->GetMethodID(clazz, "onMatch", "(IFFFLjava/lang/Object;)V");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_SEGMENTQUERYINFO);
			g_fid_SegmentQueryInfo_shapePointer = env->GetFieldID(clazz, "shapePointer", "I");
			g_fid_SegmentQueryInfo_distance = env->GetFieldID(clazz, "distance", "F");
			g_fid_SegmentQueryInfo_normalX = env->GetFieldID(clazz, "normalX", "F");
			g_fid_SegmentQueryInfo_normalY = env->GetFieldID(clazz, "normalY", "F");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_ICOLLISIONHANDLER);
			g_mid_ICollisionHandler_begin = env->GetMethodID(clazz, "begin", "(IILjava/lang/Object;)I");
			g_mid_ICollisionHandler_preSolve = env->GetMethodID(clazz, "preSolve", "(IILjava/lang/Object;)I");
			g_mid_ICollisionHandler_postSolve = env->GetMethodID(clazz, "postSolve", "(IILjava/lang/Object;)V");
			g_mid_ICollisionHandler_separate = env->GetMethodID(clazz, "separate", "(IILjava/lang/Object;)V");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_SHAPEANIMATION_CALLBACK);
			g_mid_ShapeAnimationCallback_onAnimationEnd = env->GetMethodID(clazz, "onAnimationEnd", "(I)V");
			g_mid_ShapeAnimationCallback_onAnimationAborted = env->GetMethodID(clazz, "onAnimationAborted", "(I)V");
			env->DeleteLocalRef(clazz);
		}
	}

#endif // #if ANDROID
}

void wyChipmunk::applyDampedSpring(cpBody* a, cpBody* b, wyPoint anchor1, wyPoint anchor2, float rlen, float k, float dmp, float dt) {
	cpApplyDampedSpring(a, b, cpv(anchor1.x, anchor1.y), cpv(anchor2.x, anchor2.y), rlen, k, dmp, dt);
}
