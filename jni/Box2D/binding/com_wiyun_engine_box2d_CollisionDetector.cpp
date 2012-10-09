#include "com_wiyun_engine_box2d_CollisionDetector.h"
#include "wyBox2DCollisionDetector.h"
#include "wyLog.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_CDResult_pointCount;
extern jfieldID g_fid_CDResult_points;
extern jfieldID g_fid_CDResult_normal;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_CollisionDetector_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyBox2DCollisionDetector* cd = wyBox2DCollisionDetector::make();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)cd);
	cd->retain();
	cd->lazyRelease();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_CollisionDetector_isCollided__Lcom_wiyun_engine_nodes_Node_2Lcom_wiyun_engine_nodes_Node_2Lcom_wiyun_engine_box2d_CDResult_2
  (JNIEnv * env, jobject thiz, jobject node1, jobject node2, jobject result) {
	wyBox2DCollisionDetector* cd = (wyBox2DCollisionDetector*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* n1 = (wyNode*)env->GetIntField(node1, g_fid_BaseObject_mPointer);
	wyNode* n2 = (wyNode*)env->GetIntField(node2, g_fid_BaseObject_mPointer);
	wyBox2DCDResult r;
	if(cd->isCollided(n1, n2, &r)) {
		if(result) {
			env->SetIntField(result, g_fid_CDResult_pointCount, r.pointCount);

			jobjectArray points = (jobjectArray)env->GetObjectField(result, g_fid_CDResult_points);
			for(int i = 0; i < r.pointCount; i++) {
				jobject point = env->GetObjectArrayElement(points, i);
				wyUtils_android::to_WYPoint(r.points[i], point);
			}

			jobject normal = env->GetObjectField(result, g_fid_CDResult_normal);
			wyUtils_android::to_WYPoint(r.normal, normal);
		}

		return true;
	} else {
		return false;
	}
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_CollisionDetector_isCollided__Lcom_wiyun_engine_nodes_Node_2Lcom_wiyun_engine_types_WYRect_2Lcom_wiyun_engine_box2d_CDResult_2
  (JNIEnv * env, jobject thiz, jobject node, jobject rect, jobject result) {
	wyBox2DCollisionDetector* cd = (wyBox2DCollisionDetector*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* n = (wyNode*)env->GetIntField(node, g_fid_BaseObject_mPointer);
	wyBox2DCDResult r;
	wyRect rr = wyUtils_android::to_wyRect( rect);
	if(cd->isCollided(n, rr, &r)) {
		if(result) {
			env->SetIntField(result, g_fid_CDResult_pointCount, r.pointCount);

			jobjectArray points = (jobjectArray)env->GetObjectField(result, g_fid_CDResult_points);
			for(int i = 0; i < r.pointCount; i++) {
				jobject point = env->GetObjectArrayElement(points, i);
				wyUtils_android::to_WYPoint(r.points[i], point);
			}

			jobject normal = env->GetObjectField(result, g_fid_CDResult_normal);
			wyUtils_android::to_WYPoint(r.normal, normal);
		}

		return true;
	} else {
		return false;
	}
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_CollisionDetector_isCollided__Lcom_wiyun_engine_types_WYRect_2Lcom_wiyun_engine_types_WYRect_2Lcom_wiyun_engine_box2d_CDResult_2
  (JNIEnv * env, jobject thiz, jobject r1, jobject r2, jobject result) {
	wyBox2DCollisionDetector* cd = (wyBox2DCollisionDetector*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyBox2DCDResult r;
	wyRect rr1 = wyUtils_android::to_wyRect( r1);
	wyRect rr2 = wyUtils_android::to_wyRect( r2);
	if(cd->isCollided(rr1, rr2, &r)) {
		if(result) {
			env->SetIntField(result, g_fid_CDResult_pointCount, r.pointCount);

			jobjectArray points = (jobjectArray)env->GetObjectField(result, g_fid_CDResult_points);
			for(int i = 0; i < r.pointCount; i++) {
				jobject point = env->GetObjectArrayElement(points, i);
				wyUtils_android::to_WYPoint(r.points[i], point);
			}

			jobject normal = env->GetObjectField(result, g_fid_CDResult_normal);
			wyUtils_android::to_WYPoint(r.normal, normal);
		}

		return true;
	} else {
		return false;
	}
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_CollisionDetector_setNodeShape__Lcom_wiyun_engine_nodes_Node_2_3Lcom_wiyun_engine_types_WYPoint_2
  (JNIEnv * env, jobject thiz, jobject node, jobjectArray points) {
	wyBox2DCollisionDetector* cd = (wyBox2DCollisionDetector*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* n = (wyNode*)env->GetIntField(node, g_fid_BaseObject_mPointer);
	int size = env->GetArrayLength(points);
	wyPoint p[size];
	for(int i = 0; i < size; i++) {
		jobject point = env->GetObjectArrayElement(points, i);
		p[i] = wyUtils_android::to_wyPoint( point);
	}
	cd->setNodeShape(n, p, size);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_CollisionDetector_setNodeShape__Lcom_wiyun_engine_nodes_Node_2I
  (JNIEnv * env, jobject thiz, jobject node, jint radius) {
	wyBox2DCollisionDetector* cd = (wyBox2DCollisionDetector*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* n = (wyNode*)env->GetIntField(node, g_fid_BaseObject_mPointer);
	cd->setNodeShape(n, radius);
}
