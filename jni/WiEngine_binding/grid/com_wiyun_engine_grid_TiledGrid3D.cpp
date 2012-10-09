#include "com_wiyun_engine_grid_TiledGrid3D.h"
#include "wyTiledGrid3D.h"


static jfieldID g_fid_BaseObject_mPointer;

extern jfieldID g_fid_WYQuad3D_bl_x;
extern jfieldID g_fid_WYQuad3D_bl_y;
extern jfieldID g_fid_WYQuad3D_bl_z;
extern jfieldID g_fid_WYQuad3D_br_x;
extern jfieldID g_fid_WYQuad3D_br_y;
extern jfieldID g_fid_WYQuad3D_br_z;
extern jfieldID g_fid_WYQuad3D_tl_x;
extern jfieldID g_fid_WYQuad3D_tl_y;
extern jfieldID g_fid_WYQuad3D_tl_z;
extern jfieldID g_fid_WYQuad3D_tr_x;
extern jfieldID g_fid_WYQuad3D_tr_y;
extern jfieldID g_fid_WYQuad3D_tr_z;

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_TiledGrid3D_nativeInit
  (JNIEnv * env, jobject thiz, jfloat w, jfloat h, jint c, jint r) {
	wyTiledGrid3D* grid = wyTiledGrid3D::make(w, h, c, r);
	grid->retain();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)grid);
	grid->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_TiledGrid3D_setTile
  (JNIEnv * env, jobject thiz, jint x, jint y, jfloat bl_x, jfloat bl_y, jfloat bl_z, jfloat br_x, jfloat br_y, jfloat br_z,
		  jfloat tl_x, jfloat tl_y, jfloat tl_z, jfloat tr_x, jfloat tr_y, jfloat tr_z) {
	wyTiledGrid3D* grid = (wyTiledGrid3D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	grid->setTile(wyd(x, y), wyq3(bl_x, bl_y, bl_z, br_x, br_y, br_z, tl_x, tl_y, tl_z, tr_x, tr_y, tr_z));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_TiledGrid3D_getOriginalTile
  (JNIEnv * env, jobject thiz, jint x, jint y, jobject tile) {
	wyTiledGrid3D* grid = (wyTiledGrid3D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyQuad3D t = grid->getOriginalTile(wyd(x, y));
	env->SetFloatField(tile, g_fid_WYQuad3D_bl_x, t.bl_x);
	env->SetFloatField(tile, g_fid_WYQuad3D_bl_y, t.bl_y);
	env->SetFloatField(tile, g_fid_WYQuad3D_bl_z, t.bl_z);
	env->SetFloatField(tile, g_fid_WYQuad3D_br_x, t.br_x);
	env->SetFloatField(tile, g_fid_WYQuad3D_br_y, t.br_y);
	env->SetFloatField(tile, g_fid_WYQuad3D_br_z, t.br_z);
	env->SetFloatField(tile, g_fid_WYQuad3D_tl_x, t.tl_x);
	env->SetFloatField(tile, g_fid_WYQuad3D_tl_y, t.tl_y);
	env->SetFloatField(tile, g_fid_WYQuad3D_tl_z, t.tl_z);
	env->SetFloatField(tile, g_fid_WYQuad3D_tr_x, t.tr_x);
	env->SetFloatField(tile, g_fid_WYQuad3D_tr_y, t.tr_y);
	env->SetFloatField(tile, g_fid_WYQuad3D_tr_z, t.tr_z);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_TiledGrid3D_getTile
  (JNIEnv * env, jobject thiz, jint x, jint y, jobject tile) {
	wyTiledGrid3D* grid = (wyTiledGrid3D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyQuad3D t = grid->getTile(wyd(x, y));
	env->SetFloatField(tile, g_fid_WYQuad3D_bl_x, t.bl_x);
	env->SetFloatField(tile, g_fid_WYQuad3D_bl_y, t.bl_y);
	env->SetFloatField(tile, g_fid_WYQuad3D_bl_z, t.bl_z);
	env->SetFloatField(tile, g_fid_WYQuad3D_br_x, t.br_x);
	env->SetFloatField(tile, g_fid_WYQuad3D_br_y, t.br_y);
	env->SetFloatField(tile, g_fid_WYQuad3D_br_z, t.br_z);
	env->SetFloatField(tile, g_fid_WYQuad3D_tl_x, t.tl_x);
	env->SetFloatField(tile, g_fid_WYQuad3D_tl_y, t.tl_y);
	env->SetFloatField(tile, g_fid_WYQuad3D_tl_z, t.tl_z);
	env->SetFloatField(tile, g_fid_WYQuad3D_tr_x, t.tr_x);
	env->SetFloatField(tile, g_fid_WYQuad3D_tr_y, t.tr_y);
	env->SetFloatField(tile, g_fid_WYQuad3D_tr_z, t.tr_z);
}
