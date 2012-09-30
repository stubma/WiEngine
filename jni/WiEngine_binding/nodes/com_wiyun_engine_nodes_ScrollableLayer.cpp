#include "com_wiyun_engine_nodes_ScrollableLayer.h"
#include "wyScrollableLayer.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_nativeInit
  (JNIEnv * env, jobject thiz, jobject color) {
	wyColor4B c = wyUtils_android::to_wyColor4B( color);
	wyScrollableLayer* layer = WYNEW wyScrollableLayer(c);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)layer);
	layer->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_setVertical
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setVertical(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_isVertical
  (JNIEnv * env, jobject thiz) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isVertical();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_setHorizontal
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setHorizontal(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_isHorizontal
  (JNIEnv * env, jobject thiz) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isHorizontal();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_addScrollableChild
  (JNIEnv * env, jobject thiz, jobject child, jint z, jint tag) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* c = (wyNode*)env->GetIntField(child, g_fid_BaseObject_mPointer);
	node->addScrollableChildLocked(c, z, tag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_removeScrollableChild
  (JNIEnv * env, jobject thiz, jobject child, jboolean cleanup) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* c = (wyNode*)env->GetIntField(child, g_fid_BaseObject_mPointer);
	node->removeScrollableChildLocked(c, cleanup);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_removeScrollableChildByTag
  (JNIEnv * env, jobject thiz, jint tag, jboolean cleanup) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->removeScrollableChildByTagLocked(tag, cleanup);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_removeAllScrollableChildrenLocked
  (JNIEnv * env, jobject thiz, jboolean cleanup) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->removeAllScrollableChildrenLocked(cleanup);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_nativeGetScrollExtent
  (JNIEnv * env, jobject thiz, jobject size) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wySize s = node->getScrollExtent();
	wyUtils_android::to_WYSize(s, size);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_setHorizontalThumb
  (JNIEnv * env, jobject thiz, jobject thumb) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* t = thumb == NULL ? NULL : (wyNode*)env->GetIntField(thumb, g_fid_BaseObject_mPointer);
	node->setHorizontalThumb(t);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_setVerticalThumb
  (JNIEnv * env, jobject thiz, jobject thumb) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* t = thumb == NULL ? NULL : (wyNode*)env->GetIntField(thumb, g_fid_BaseObject_mPointer);
	node->setVerticalThumb(t);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_setThumbFadeOutTime
  (JNIEnv * env, jobject thiz, jfloat time) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setThumbFadeOutTime(time);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_getThumbFadeOutTime
  (JNIEnv * env, jobject thiz) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getThumbFadeOutTime();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_setLeftMargin
  (JNIEnv * env, jobject thiz, jfloat m) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setLeftMargin(m);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_getLeftMargin
  (JNIEnv * env, jobject thiz) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getLeftMargin();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_setRightMargin
  (JNIEnv * env, jobject thiz, jfloat m) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setRightMargin(m);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_getRightMargin
  (JNIEnv * env, jobject thiz) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getRightMargin();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_setTopMargin
  (JNIEnv * env, jobject thiz, jfloat m) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setTopMargin(m);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_getTopMargin
  (JNIEnv * env, jobject thiz) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getTopMargin();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_setBottomMargin
  (JNIEnv * env, jobject thiz, jfloat m) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setBottomMargin(m);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_getBottomMargin
  (JNIEnv * env, jobject thiz) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getBottomMargin();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_getOffsetX
  (JNIEnv * env, jobject thiz) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getOffsetX();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_getOffsetY
  (JNIEnv * env, jobject thiz) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getOffsetY();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_setOffsetX
  (JNIEnv * env, jobject thiz, jfloat x) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setOffsetX(x);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_setOffsetY
  (JNIEnv * env, jobject thiz, jfloat y) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setOffsetY(y);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_isAtXEnd
  (JNIEnv * env, jobject thiz) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isAtXEnd();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_isAtYEnd
  (JNIEnv * env, jobject thiz) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isAtYEnd();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_setCallback
  (JNIEnv * env, jobject thiz, jobject callback) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setCallback(callback);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_ScrollableLayer_getScrollableChildByTag
  (JNIEnv * env, jobject thiz, jint tag) {
	wyScrollableLayer* node = (wyScrollableLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)node->getScrollableChildByTag(tag);
}
