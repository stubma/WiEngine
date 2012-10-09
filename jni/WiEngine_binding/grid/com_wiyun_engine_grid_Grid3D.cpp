#include "com_wiyun_engine_grid_Grid3D.h"
#include "wyGrid3D.h"


extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYVertex3D_x;
extern jfieldID g_fid_WYVertex3D_y;
extern jfieldID g_fid_WYVertex3D_z;

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_Grid3D_nativeInit
  (JNIEnv * env, jobject thiz, jfloat w, jfloat h, jint c, jint r) {
	wyGrid3D* grid = wyGrid3D::make(w, h, c, r);
	grid->retain();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)grid);
	grid->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_Grid3D_setVertex
  (JNIEnv * env, jobject thiz, jint x, jint y, jfloat vx, jfloat vy, jfloat vz) {
	wyGrid3D* grid = (wyGrid3D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	grid->setVertex(wyd(x, y), wyv(vx, vy, vz));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_Grid3D_getVertex
  (JNIEnv * env, jobject thiz, jint x, jint y, jobject vertex) {
	wyGrid3D* grid = (wyGrid3D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyVertex3D v = grid->getVertex(wyd(x, y));
	env->SetFloatField(vertex, g_fid_WYVertex3D_x, v.x);
	env->SetFloatField(vertex, g_fid_WYVertex3D_y, v.y);
	env->SetFloatField(vertex, g_fid_WYVertex3D_z, v.z);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_Grid3D_getOriginalVertex
  (JNIEnv * env, jobject thiz, jint x, jint y, jobject vertex) {
	wyGrid3D* grid = (wyGrid3D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyVertex3D v = grid->getOriginalVertex(wyd(x, y));
	env->SetFloatField(vertex, g_fid_WYVertex3D_x, v.x);
	env->SetFloatField(vertex, g_fid_WYVertex3D_y, v.y);
	env->SetFloatField(vertex, g_fid_WYVertex3D_z, v.z);
}
