#include "com_wiyun_engine_nodes_TextureNode.h"
#include "wyTextureNode.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TextureNode_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyTextureNode* tn = WYNEW wyTextureNode();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)tn);
	wyObjectLazyRelease(tn);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TextureNode_setDisplayFrame__Lcom_wiyun_engine_nodes_Frame_2
  (JNIEnv * env, jobject thiz, jobject frame) {
	wyFrame* f = (wyFrame*)env->GetIntField(frame, g_fid_BaseObject_mPointer);
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setDisplayFrame(f);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TextureNode_setDisplayFrame__II
  (JNIEnv * env, jobject thiz, jint id, jint frameIndex) {
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setDisplayFrameById(id, frameIndex);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_TextureNode_nativeGetDisplayFrame
  (JNIEnv * env, jobject thiz) {
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)node->getDisplayFrame();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_TextureNode_isFrameDisplayed
  (JNIEnv * env, jobject thiz, jobject frame) {
	wyFrame* f = (wyFrame*)env->GetIntField(frame, g_fid_BaseObject_mPointer);
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isFrameDisplayed(f);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TextureNode_addAnimation
  (JNIEnv* env, jobject thiz, jobject animation) {
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyAnimation* anim = (wyAnimation*)env->GetIntField(animation, g_fid_BaseObject_mPointer);
    node->addAnimation(anim);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_TextureNode_nativeGetAnimationById
  (JNIEnv* env, jobject thiz, jint id) {
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyAnimation* anim = node->getAnimationById((int)id);
    return (jint) anim;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_TextureNode_isFlipX
  (JNIEnv * env, jobject thiz) {
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isFlipX();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TextureNode_setFlipX
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setFlipX(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_TextureNode_isFlipY
  (JNIEnv * env, jobject thiz) {
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isFlipY();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TextureNode_setFlipY
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setFlipY(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_TextureNode_isDither
  (JNIEnv * env, jobject thiz) {
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isDither();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TextureNode_setDither
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setDither(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TextureNode_setTextureRect
  (JNIEnv* env, jobject thiz, jobject rect) {
    wyRect texRect =  wyUtils_android::to_wyRect( rect);
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    node->setTextureRect(texRect);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TextureNode_nativeGetTextureRect
  (JNIEnv* env, jobject thiz, jobject rect) {
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    wyRect texRect = node->getTextureRect();
    wyUtils_android::to_WYRect( texRect,rect);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TextureNode_setRotatedZwoptex
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setRotatedZwoptex(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_TextureNode_isRotatedZwoptex
  (JNIEnv * env, jobject thiz) {
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isRotatedZwoptex();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TextureNode_setAutoFit
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setAutoFit(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_TextureNode_isAutoFit
  (JNIEnv * env, jobject thiz) {
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isAutoFit();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_TextureNode_nativeMakeFrame
  (JNIEnv * env, jobject thiz) {
	wyTextureNode* node = (wyTextureNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)node->makeFrame();
}
