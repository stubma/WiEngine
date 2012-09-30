#include <jni.h>
#include <stdlib.h>
#include "com_wiyun_engine_chipmunk_Poly.h"
#include "chipmunk.h"
#include "chipmunk/chipmunk_unsafe.h"

extern jfieldID g_fid_Body_mPointer;
extern jfieldID g_fid_Shape_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Poly_init
  (JNIEnv * env, jobject thiz, jobject body, jobjectArray verts, jobject offset) {
	cpBody* bodyStruct = (cpBody*)env->GetIntField(body, g_fid_Body_mPointer);

	int numVerts = env->GetArrayLength(verts);

	cpVect *tVerts = (cpVect *)cpcalloc(numVerts, sizeof(cpVect));
	for(int i = 0; i < numVerts; i++) {
		jobject wypoint = env->GetObjectArrayElement(verts, i);
		tVerts[i].x = env->GetFloatField(wypoint, g_fid_WYPoint_x);
		tVerts[i].y = env->GetFloatField(wypoint, g_fid_WYPoint_y);
		env->DeleteLocalRef(wypoint);
	}

	cpVect tOffset = cpv(env->GetFloatField(offset, g_fid_WYPoint_x),
			env->GetFloatField(offset, g_fid_WYPoint_y));

	cpShape* shape = cpPolyShapeNew(bodyStruct, numVerts, tVerts, tOffset);
	free(tVerts);

	env->SetIntField(thiz, g_fid_Shape_mPointer, (jint)shape);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Poly_setVertices
  (JNIEnv * env, jobject thiz, jobjectArray verts, jobject offset) {
	cpShape* shape = (cpShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);

	jsize numVerts = env->GetArrayLength(verts);
	cpVect *tVerts = (cpVect *)cpcalloc(numVerts, sizeof(cpVect));
	for(int i = 0; i < numVerts; i++) {
		jobject v = env->GetObjectArrayElement(verts, i);
		tVerts[i].x = env->GetFloatField(v, g_fid_WYPoint_x);
		tVerts[i].y = env->GetFloatField(v, g_fid_WYPoint_y);
		env->DeleteLocalRef(v);
	}
	cpVect o = cpv(env->GetFloatField(offset, g_fid_WYPoint_x),
			env->GetFloatField(offset, g_fid_WYPoint_y));

	cpPolyShapeSetVerts(shape, numVerts, tVerts, o);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Poly_getVertexCount
  (JNIEnv * env, jobject thiz) {
	cpPolyShape* p = (cpPolyShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return p->numVerts;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Poly_getVertices
  (JNIEnv * env, jobject thiz, jobjectArray vertices) {
	cpPolyShape* p = (cpPolyShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);

	for(int i = 0; i < p->numVerts; i++) {
		jobject v = env->GetObjectArrayElement(vertices, i);
		env->SetFloatField(v, g_fid_WYPoint_x, p->verts[i].x);
		env->SetFloatField(v, g_fid_WYPoint_x, p->verts[i].y);
		env->DeleteLocalRef(v);
	}
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Poly_getOffsetX
  (JNIEnv * env, jobject thiz) {
	cpPolyShape* p = (cpPolyShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return p->offset.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Poly_getOffsetY
  (JNIEnv * env, jobject thiz) {
	cpPolyShape* p = (cpPolyShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return p->offset.y;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Poly_getOriginWidth
(JNIEnv * env, jobject thiz) {
	cpPolyShape* p = (cpPolyShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return p->origin_w;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Poly_getOriginHeight
  (JNIEnv * env, jobject thiz) {
	cpPolyShape* p = (cpPolyShape*)env->GetIntField(thiz, g_fid_Shape_mPointer);
	return p->origin_h;
}
