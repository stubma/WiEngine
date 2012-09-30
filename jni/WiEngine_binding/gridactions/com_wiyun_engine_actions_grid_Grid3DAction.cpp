#include "com_wiyun_engine_actions_grid_Grid3DAction.h"
#include "wyGrid3DAction.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYVertex3D_x;
extern jfieldID g_fid_WYVertex3D_y;
extern jfieldID g_fid_WYVertex3D_z;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_Grid3DAction_getVertex
  (JNIEnv * env, jobject thiz, jint x, jint y, jobject vertex) {
	wyGrid3DAction* grid = (wyGrid3DAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyVertex3D v = grid->getVertex(wyd(x, y));
	env->SetFloatField(vertex, g_fid_WYVertex3D_x, v.x);
	env->SetFloatField(vertex, g_fid_WYVertex3D_y, v.y);
	env->SetFloatField(vertex, g_fid_WYVertex3D_z, v.z);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_Grid3DAction_getOriginalVertex
  (JNIEnv * env, jobject thiz, jint x, jint y, jobject vertex) {
	wyGrid3DAction* grid = (wyGrid3DAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyVertex3D v = grid->getOriginalVertex(wyd(x, y));
	env->SetFloatField(vertex, g_fid_WYVertex3D_x, v.x);
	env->SetFloatField(vertex, g_fid_WYVertex3D_y, v.y);
	env->SetFloatField(vertex, g_fid_WYVertex3D_z, v.z);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_Grid3DAction_setVertex
  (JNIEnv * env, jobject thiz, jint x, jint y, jfloat vx, jfloat vy, jfloat vz) {
	wyGrid3DAction* grid = (wyGrid3DAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	grid->setVertex(wyd(x, y), wyv(vx, vy, vz));
}
