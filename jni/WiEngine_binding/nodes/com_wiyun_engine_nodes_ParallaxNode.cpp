#include "com_wiyun_engine_nodes_ParallaxNode.h"
#include "wyParallaxNode.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyParallaxNode* pn = WYNEW wyParallaxNode();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)pn);
	wyObjectLazyRelease(pn);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_addChild__Lcom_wiyun_engine_nodes_Node_2II
  (JNIEnv * env, jobject thiz, jobject child, jint z, jint tag) {
	wyParallaxNode* pn = (wyParallaxNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* childNode = (wyNode*)env->GetIntField(child, g_fid_BaseObject_mPointer);
	pn->addChildLocked(childNode, z, tag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_addChild__Lcom_wiyun_engine_nodes_Node_2IFF
  (JNIEnv * env, jobject thiz, jobject child, jint z, jfloat ratioX, jfloat ratioY) {
	wyParallaxNode* pn = (wyParallaxNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* childNode = (wyNode*)env->GetIntField(child, g_fid_BaseObject_mPointer);
	pn->addChild(childNode, z, ratioX, ratioY);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_removeChild
  (JNIEnv * env, jobject thiz, jobject child, jboolean cleanup) {
	wyParallaxNode* pn = (wyParallaxNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* childNode = (wyNode*)env->GetIntField(child, g_fid_BaseObject_mPointer);
	pn->removeChildLocked(childNode, cleanup);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_removeAllChildren
  (JNIEnv * env, jobject thiz, jboolean cleanup) {
	wyParallaxNode* pn = (wyParallaxNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pn->removeAllChildrenLocked(cleanup);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_offsetBy
  (JNIEnv * env, jobject thiz, jfloat dx, jfloat dy) {
	wyParallaxNode* pn = (wyParallaxNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pn->offsetBy(dx, dy);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_fling
  (JNIEnv * env, jobject thiz, jfloat vx, jfloat vy) {
	wyParallaxNode* pn = (wyParallaxNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pn->fling(vx, vy);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_stopFling
  (JNIEnv * env, jobject thiz) {
	wyParallaxNode* pn = (wyParallaxNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pn->stopFling();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_getOffsetX
  (JNIEnv * env, jobject thiz) {
	wyParallaxNode* pn = (wyParallaxNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return pn->getOffsetX();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_getOffsetY
  (JNIEnv * env, jobject thiz) {
	wyParallaxNode* pn = (wyParallaxNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return pn->getOffsetY();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_setMinX
  (JNIEnv * env, jobject thiz, jfloat x) {
	wyParallaxNode* pn = (wyParallaxNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pn->setMinX(x);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_setMinY
  (JNIEnv * env, jobject thiz, jfloat y) {
	wyParallaxNode* pn = (wyParallaxNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pn->setMinY(y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_getMinX
  (JNIEnv * env, jobject thiz) {
	wyParallaxNode* pn = (wyParallaxNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return pn->getMinX();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_getMinY
  (JNIEnv * env, jobject thiz) {
	wyParallaxNode* pn = (wyParallaxNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return pn->getMinY();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_setMaxX
  (JNIEnv * env, jobject thiz, jfloat x) {
	wyParallaxNode* pn = (wyParallaxNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pn->setMaxX(x);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_setMaxY
  (JNIEnv * env, jobject thiz, jfloat y) {
	wyParallaxNode* pn = (wyParallaxNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pn->setMaxY(y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_getMaxX
  (JNIEnv * env, jobject thiz) {
	wyParallaxNode* pn = (wyParallaxNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return pn->getMaxX();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_ParallaxNode_getMaxY
  (JNIEnv * env, jobject thiz) {
	wyParallaxNode* pn = (wyParallaxNode*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return pn->getMaxY();
}
