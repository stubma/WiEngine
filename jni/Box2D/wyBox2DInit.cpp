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
#if ANDROID

#include "wyJNI.h"

// classes
#define CLASS_BOX2D "com/wiyun/engine/box2d/Box2D"
#define CLASS_CDRESULT "com/wiyun/engine/box2d/CDResult"
#define CLASS_IQUERYCALLBACK "com/wiyun/engine/box2d/dynamics/World$IQueryCallback"
#define CLASS_ICONTACTLISTENER "com/wiyun/engine/box2d/dynamics/World$IContactListener"
#define CLASS_IRAYCASTCALLBACK "com/wiyun/engine/box2d/dynamics/World$IRayCastCallback"
#define CLASS_IDESTRUCTIONLISTENER "com/wiyun/engine/box2d/dynamics/World$IDestructionListener"
#define CLASS_TRANSFORM "com/wiyun/engine/box2d/common/Transform"
#define CLASS_ROTATION "com/wiyun/engine/box2d/common/Rotation"
#define CLASS_MATRIX22 "com/wiyun/engine/box2d/common/Matrix22"
#define CLASS_MASSDATA "com/wiyun/engine/box2d/collision/MassData"
#define CLASS_RAYCASTINPUT "com/wiyun/engine/box2d/collision/RayCastInput"
#define CLASS_RAYCASTOUTPUT "com/wiyun/engine/box2d/collision/RayCastOutput"
#define CLASS_MANIFOLDPOINT "com/wiyun/engine/box2d/collision/ManifoldPoint"
#define CLASS_AABB "com/wiyun/engine/box2d/collision/AABB"
#define CLASS_FILTER "com/wiyun/engine/box2d/dynamics/Filter"
#define CLASS_FIXTUREANIMATION_CALLBACK "com/wiyun/engine/box2d/FixtureAnimation$Callback"

// method id in various interface
jmethodID g_mid_IQueryCallback_reportFixture;

// IContactListener
jmethodID g_mid_IContactListener_beginContact;
jmethodID g_mid_IContactListener_endContact;
jmethodID g_mid_IContactListener_preSolve;
jmethodID g_mid_IContactListener_postSolve;

// IRayCastListener
jmethodID g_mid_IRayCastListener_reportFixture;

// IDestructionListener
jmethodID g_mid_IDestructionListener_jointSayGoodbye;
jmethodID g_mid_IDestructionListener_fixtureSayGoodbye;

// transform
jfieldID g_fid_Transform_q;
jfieldID g_fid_Transform_p;

// Rotation
jfieldID g_fid_Rotation_s;
jfieldID g_fid_Rotation_c;

// matrix22
jfieldID g_fid_Matrix22_col1X;
jfieldID g_fid_Matrix22_col1Y;
jfieldID g_fid_Matrix22_col2X;
jfieldID g_fid_Matrix22_col2Y;

// massdata
jfieldID g_fid_MassData_mass;
jfieldID g_fid_MassData_center;
jfieldID g_fid_MassData_I;

// filter
jfieldID g_fid_Filter_categoryBits;
jfieldID g_fid_Filter_maskBits;
jfieldID g_fid_Filter_groupIndex;

// raycast input
jfieldID g_fid_RayCastInput_p1;
jfieldID g_fid_RayCastInput_p2;
jfieldID g_fid_RayCastInput_maxFraction;

// raycast output
jfieldID g_fid_RayCastOutput_normal;
jfieldID g_fid_RayCastOutput_fraction;

// manifold point
jfieldID g_fid_ManifoldPoint_localPoint;
jfieldID g_fid_ManifoldPoint_normalImpulse;
jfieldID g_fid_ManifoldPoint_tangentImpulse;
jfieldID g_fid_ManifoldPoint_indexA;
jfieldID g_fid_ManifoldPoint_indexB;
jfieldID g_fid_ManifoldPoint_typeA;
jfieldID g_fid_ManifoldPoint_typeB;

// aabb
jfieldID g_fid_AABB_lowerBound;
jfieldID g_fid_AABB_upperBound;

// fixture animation
jmethodID g_mid_FixtureAnimationCallback_onAnimationEnd;
jmethodID g_mid_FixtureAnimationCallback_onAnimationAborted;

// CDResult
jfieldID g_fid_CDResult_pointCount;
jfieldID g_fid_CDResult_points;
jfieldID g_fid_CDResult_normal;

// flag indicating this is the frist Box2D instance
static bool sFirstBox2D = true;

#endif // #if ANDROID

void globalJNIInit() {
#if ANDROID
	if(sFirstBox2D) {
		sFirstBox2D = false;

		// get env
		JNIEnv* env = getEnv();

		// no jar flag
		bool noJava = false;

		// find field ids
		jclass clazz = env->FindClass(CLASS_BOX2D);
		if(env->ExceptionOccurred() != NULL) {
			env->ExceptionClear();
			noJava = true;
		} else {
			env->DeleteLocalRef(clazz);
		}

		if(!noJava) {
			clazz = env->FindClass(CLASS_IQUERYCALLBACK);
			g_mid_IQueryCallback_reportFixture = env->GetMethodID(clazz, "reportFixture", "(I)Z");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_TRANSFORM);
			g_fid_Transform_q = env->GetFieldID(clazz, "q", "Lcom/wiyun/engine/box2d/common/Rotation;");
			g_fid_Transform_p = env->GetFieldID(clazz, "p", "Lcom/wiyun/engine/types/WYPoint;");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_ROTATION);
			g_fid_Rotation_s = env->GetFieldID(clazz, "s", "F");
			g_fid_Rotation_c = env->GetFieldID(clazz, "c", "F");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_MATRIX22);
			g_fid_Matrix22_col1X = env->GetFieldID(clazz, "col1X", "F");
			g_fid_Matrix22_col1Y = env->GetFieldID(clazz, "col1Y", "F");
			g_fid_Matrix22_col2X = env->GetFieldID(clazz, "col2X", "F");
			g_fid_Matrix22_col2Y = env->GetFieldID(clazz, "col2Y", "F");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_ICONTACTLISTENER);
			g_mid_IContactListener_beginContact = env->GetMethodID(clazz, "beginContact", "(I)V");
			g_mid_IContactListener_endContact = env->GetMethodID(clazz, "endContact", "(I)V");
			g_mid_IContactListener_preSolve = env->GetMethodID(clazz, "preSolve", "(II)V");
			g_mid_IContactListener_postSolve = env->GetMethodID(clazz, "postSolve", "(II)V");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_IRAYCASTCALLBACK);
			g_mid_IRayCastListener_reportFixture = env->GetMethodID(clazz, "reportFixture", "(IFFFFF)F");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_IDESTRUCTIONLISTENER);
			g_mid_IDestructionListener_jointSayGoodbye = env->GetMethodID(clazz, "jointSayGoodbye", "(I)V");
			g_mid_IDestructionListener_fixtureSayGoodbye = env->GetMethodID(clazz, "fixtureSayGoodbye", "(I)V");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_MASSDATA);
			g_fid_MassData_mass = env->GetFieldID(clazz, "mass", "F");
			g_fid_MassData_center = env->GetFieldID(clazz, "center", "Lcom/wiyun/engine/types/WYPoint;");
			g_fid_MassData_I = env->GetFieldID(clazz, "I", "F");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_FILTER);
			g_fid_Filter_categoryBits = env->GetFieldID(clazz, "categoryBits", "I");
			g_fid_Filter_maskBits = env->GetFieldID(clazz, "maskBits", "I");
			g_fid_Filter_groupIndex = env->GetFieldID(clazz, "groupIndex", "I");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_RAYCASTINPUT);
			g_fid_RayCastInput_p1 = env->GetFieldID(clazz, "p1", "Lcom/wiyun/engine/types/WYPoint;");
			g_fid_RayCastInput_p2 = env->GetFieldID(clazz, "p2", "Lcom/wiyun/engine/types/WYPoint;");
			g_fid_RayCastInput_maxFraction = env->GetFieldID(clazz, "maxFraction", "F");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_RAYCASTOUTPUT);
			g_fid_RayCastOutput_normal = env->GetFieldID(clazz, "normal", "Lcom/wiyun/engine/types/WYPoint;");
			g_fid_RayCastOutput_fraction = env->GetFieldID(clazz, "fraction", "F");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_MANIFOLDPOINT);
			g_fid_ManifoldPoint_localPoint = env->GetFieldID(clazz, "localPoint", "Lcom/wiyun/engine/types/WYPoint;");
			g_fid_ManifoldPoint_normalImpulse = env->GetFieldID(clazz, "normalImpulse", "F");
			g_fid_ManifoldPoint_tangentImpulse = env->GetFieldID(clazz, "tangentImpulse", "F");
			g_fid_ManifoldPoint_indexA = env->GetFieldID(clazz, "indexA", "I");
			g_fid_ManifoldPoint_indexB = env->GetFieldID(clazz, "indexB", "I");
			g_fid_ManifoldPoint_typeA = env->GetFieldID(clazz, "typeA", "I");
			g_fid_ManifoldPoint_typeB = env->GetFieldID(clazz, "typeB", "I");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_AABB);
			g_fid_AABB_lowerBound = env->GetFieldID(clazz, "lowerBound", "Lcom/wiyun/engine/types/WYPoint;");
			g_fid_AABB_upperBound = env->GetFieldID(clazz, "upperBound", "Lcom/wiyun/engine/types/WYPoint;");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_FIXTUREANIMATION_CALLBACK);
			g_mid_FixtureAnimationCallback_onAnimationEnd = env->GetMethodID(clazz, "onAnimationEnd", "(I)V");
			g_mid_FixtureAnimationCallback_onAnimationAborted = env->GetMethodID(clazz, "onAnimationAborted", "(I)V");
			env->DeleteLocalRef(clazz);

			clazz = env->FindClass(CLASS_CDRESULT);
			g_fid_CDResult_pointCount = env->GetFieldID(clazz, "pointCount", "I");
			g_fid_CDResult_points = env->GetFieldID(clazz, "points", "[Lcom/wiyun/engine/types/WYPoint;");
			g_fid_CDResult_normal = env->GetFieldID(clazz, "normal", "Lcom/wiyun/engine/types/WYPoint;");
			env->DeleteLocalRef(clazz);
		}
	}

#endif // #if ANDROID
}
