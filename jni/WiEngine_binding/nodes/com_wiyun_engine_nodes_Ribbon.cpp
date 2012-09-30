#include "com_wiyun_engine_nodes_Ribbon.h"
#include "wyRibbon.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Ribbon_forceFirstPoint
  (JNIEnv * env, jobject thiz) {
	wyRibbon* ribbon = (wyRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ribbon->forceFirstPoint();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Ribbon_addPoint
  (JNIEnv * env, jobject thiz, jobject location) {
	wyRibbon* ribbon = (wyRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint loc = {
		env->GetIntField(location, g_fid_WYPoint_x),
		env->GetIntField(location, g_fid_WYPoint_y)
	};
	ribbon->addPoint(loc);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Ribbon_update
  (JNIEnv * env, jobject thiz, jfloat delta) {
	wyRibbon* ribbon = (wyRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ribbon->update(delta);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Ribbon_nativeGetTexture
  (JNIEnv * env, jobject thiz) {
	wyRibbon* ribbon = (wyRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)ribbon->getTexture();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Ribbon_setTexture
  (JNIEnv * env, jobject thiz, jobject texture) {
	wyRibbon* ribbon = (wyRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	ribbon->setTexture(tex);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Ribbon_getBlendFuncSrc
  (JNIEnv * env, jobject thiz) {
	wyRibbon* ribbon = (wyRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ribbon->getBlendFunc().src;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Ribbon_getBlendFuncDst
  (JNIEnv * env, jobject thiz) {
	wyRibbon* ribbon = (wyRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ribbon->getBlendFunc().dst;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Ribbon_setBlendFunc
  (JNIEnv * env, jobject thiz, jint src, jint dst) {
	wyRibbon* ribbon = (wyRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyBlendFunc func = { src, dst };
	ribbon->setBlendFunc(func);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Ribbon_reset
  (JNIEnv * env, jobject thiz) {
	wyRibbon* ribbon = (wyRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ribbon->reset();
}
