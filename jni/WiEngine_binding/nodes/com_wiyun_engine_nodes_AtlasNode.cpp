#include "com_wiyun_engine_nodes_AtlasNode.h"
#include "wyAtlasNode.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_AtlasNode_getBlendFuncSrc
  (JNIEnv * env, jobject thiz) {
	wyAtlasNode* sprite = (wyAtlasNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return sprite->getBlendFunc().src;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_AtlasNode_getBlendFuncDst
  (JNIEnv * env, jobject thiz) {
	wyAtlasNode* sprite = (wyAtlasNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return sprite->getBlendFunc().dst;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_AtlasNode_setBlendFunc
  (JNIEnv * env, jobject thiz, jint src, jint dst) {
	wyAtlasNode* sprite = (wyAtlasNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyBlendFunc func = { src, dst };
	sprite->setBlendFunc(func);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_AtlasNode_getAlpha
  (JNIEnv * env, jobject thiz) {
	wyAtlasNode* sprite = (wyAtlasNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return sprite->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_AtlasNode_setAlpha
  (JNIEnv * env, jobject thiz, jint alpha) {
	wyAtlasNode* sprite = (wyAtlasNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	sprite->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_AtlasNode_nativeGetColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyAtlasNode* sprite = (wyAtlasNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = sprite->getColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_AtlasNode_nativeSetColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyAtlasNode* sprite = (wyAtlasNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = { r, g, b };
	sprite->setColor(c);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_AtlasNode_nativeGetTexture
  (JNIEnv * env, jobject thiz) {
	wyAtlasNode* node = (wyAtlasNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)node->getTexture();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_AtlasNode_setTexture
  (JNIEnv * env, jobject thiz, jobject tex) {
	wyAtlasNode* node = (wyAtlasNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setTexture((wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer));
}
