#include "com_wiyun_engine_nodes_SpriteBatchNode.h"
#include "wySpriteBatchNode.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteBatchNode_nativeInit
  (JNIEnv* env, jobject thiz, jobject tex) {
	wyTexture2D* texNode = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	wySpriteBatchNode* batchNode = WYNEW wySpriteBatchNode(texNode);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)batchNode);
	wyObjectLazyRelease(batchNode);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteBatchNode_nativesetTexture
  (JNIEnv* env, jobject thiz, jobject tex) {
	wyTexture2D* texNode = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	wySpriteBatchNode* batchNode = (wySpriteBatchNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer); 
    batchNode->setTexture(texNode);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_SpriteBatchNode_nativegetTexture
  (JNIEnv* env, jobject thiz) {
	wySpriteBatchNode* batchNode = (wySpriteBatchNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer); 
    wyTexture2D* texNode = batchNode->getTexture();
    return (jint)texNode;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_SpriteBatchNode_nativegetTexAtlas
  (JNIEnv* env, jobject thiz) {
	wySpriteBatchNode* batchNode = (wySpriteBatchNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer); 
    wyTextureAtlas* texAtlas = batchNode->getTexAtlas();
    return (jint)texAtlas;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_SpriteBatchNode_isDither
  (JNIEnv * env, jobject thiz) {
	wySpriteBatchNode* batchNode = (wySpriteBatchNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return batchNode->isDither();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteBatchNode_setDither
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wySpriteBatchNode* batchNode = (wySpriteBatchNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	batchNode->setDither(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_SpriteBatchNode_isBlend
  (JNIEnv * env, jobject thiz) {
	wySpriteBatchNode* batchNode = (wySpriteBatchNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return batchNode->isBlend();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteBatchNode_setBlend
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wySpriteBatchNode* batchNode = (wySpriteBatchNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	batchNode->setBlend(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteBatchNode_setAlphaFunc
  (JNIEnv * env, jobject thiz, jint func, jfloat ref) {
	wySpriteBatchNode* batchNode = (wySpriteBatchNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	batchNode->setAlphaFunc(func, ref);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_SpriteBatchNode_getBlendFuncSrc
(JNIEnv * env, jobject thiz) {
	wySpriteBatchNode* node = (wySpriteBatchNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getBlendFunc().src;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_SpriteBatchNode_getBlendFuncDst
(JNIEnv * env, jobject thiz) {
	wySpriteBatchNode* node = (wySpriteBatchNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getBlendFunc().dst;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteBatchNode_setBlendFunc
(JNIEnv * env, jobject thiz, jint src, jint dst) {
	wySpriteBatchNode* node = (wySpriteBatchNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyBlendFunc func = { src, dst };
	node->setBlendFunc(func);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_SpriteBatchNode_getAlpha
  (JNIEnv * env, jobject thiz) {
	wySpriteBatchNode* node = (wySpriteBatchNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteBatchNode_setAlpha
  (JNIEnv * env, jobject thiz, jint alpha) {
	wySpriteBatchNode* node = (wySpriteBatchNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteBatchNode_nativeGetColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wySpriteBatchNode* node = (wySpriteBatchNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = node->getColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteBatchNode_nativeSetColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wySpriteBatchNode* node = (wySpriteBatchNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setColor(wyc3b(r, g, b));
}
