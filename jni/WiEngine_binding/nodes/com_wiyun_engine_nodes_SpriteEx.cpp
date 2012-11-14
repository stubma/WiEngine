#include "com_wiyun_engine_nodes_SpriteEx.h"
#include "wySpriteEx.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteEx_nativeInit__Lcom_wiyun_engine_opengl_Texture2D_2
  (JNIEnv* env, jobject thiz, jobject tex) {
	wyTexture2D* texNode = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	wySpriteEx* sprite = WYNEW wySpriteEx(texNode);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)sprite);
	wyObjectLazyRelease(sprite);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteEx_nativeInit__Lcom_wiyun_engine_opengl_Texture2D_2Lcom_wiyun_engine_types_WYRect_2
  (JNIEnv* env, jobject thiz, jobject tex, jobject rect) {
	wyTexture2D* texNode = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
    wyRect rt = wyUtils_android::to_wyRect( rect);
	wySpriteEx* sprite = WYNEW wySpriteEx(texNode, rt);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)sprite);
	wyObjectLazyRelease(sprite);    
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteEx_nativeInit__Lcom_wiyun_engine_nodes_SpriteBatchNode_2Lcom_wiyun_engine_types_WYRect_2I
  (JNIEnv* env, jobject thiz, jobject batchNode, jobject rect, jint zOrder) {
	wySpriteBatchNode* bn = (wySpriteBatchNode*)env->GetIntField(batchNode, g_fid_BaseObject_mPointer);
    wyRect rt = wyUtils_android::to_wyRect( rect);
	wySpriteEx* sprite = wySpriteEx::make(bn, rt, zOrder);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)sprite);
	sprite->retain();
	sprite->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteEx_nativeInit__Lcom_wiyun_engine_nodes_SpriteBatchNode_2Lcom_wiyun_engine_utils_ZwoptexFrame_2
  (JNIEnv* env, jobject thiz, jobject batchNode, jobject zwoptexFrame) {
	wySpriteBatchNode* bn = (wySpriteBatchNode*)env->GetIntField(batchNode, g_fid_BaseObject_mPointer);
	wyZwoptexFrame* f = (wyZwoptexFrame*)env->GetIntField(zwoptexFrame, g_fid_BaseObject_mPointer);
	wySpriteEx* sprite = wySpriteEx::make(bn, f);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)sprite);
	sprite->retain();
	sprite->lazyRelease();
}
