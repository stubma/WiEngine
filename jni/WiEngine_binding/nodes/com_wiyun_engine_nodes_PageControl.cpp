#include "com_wiyun_engine_nodes_PageControl.h"
#include "wyPageControl.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_PageControl_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyPageControl* pc = WYNEW wyPageControl();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)pc);
	pc->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_PageControl_addPage
  (JNIEnv * env, jobject thiz, jobject page) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* p = (wyNode*)env->GetIntField(page, g_fid_BaseObject_mPointer);
	pc->addPage(p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_PageControl_addPageAt
  (JNIEnv * env, jobject thiz, jobject page, jint index) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* p = (wyNode*)env->GetIntField(page, g_fid_BaseObject_mPointer);
	pc->addPageAt(p, index);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_PageControl_removePage
  (JNIEnv * env, jobject thiz, jobject page) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* p = (wyNode*)env->GetIntField(page, g_fid_BaseObject_mPointer);
	pc->removePage(p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_PageControl_removePageAt
  (JNIEnv * env, jobject thiz, jint index) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pc->removePageAt(index);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_PageControl_setInitialPage
  (JNIEnv * env, jobject thiz, jint index) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pc->setInitialPage(index);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_PageControl_gotoPage__I
  (JNIEnv * env, jobject thiz, jint index) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pc->gotoPage(index);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_PageControl_gotoPage__IF
  (JNIEnv * env, jobject thiz, jint index, jfloat duration) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pc->gotoPage(index, true, duration);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_PageControl_setPageSpacing
  (JNIEnv * env, jobject thiz, jfloat spacing) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pc->setPageSpacing(spacing);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_PageControl_getPageSpacing
  (JNIEnv * env, jobject thiz) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return pc->getPageSpacing();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_PageControl_getCenterY
  (JNIEnv * env, jobject thiz) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return pc->getCenterY();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_PageControl_setCenterY
  (JNIEnv * env, jobject thiz, jfloat centerY) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pc->setCenterY(centerY);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_PageControl_getCenterX
  (JNIEnv * env, jobject thiz) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return pc->getCenterX();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_PageControl_setCenterX
  (JNIEnv * env, jobject thiz, jfloat x) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pc->setCenterX(x);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_PageControl_getPageCount
  (JNIEnv * env, jobject thiz) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return pc->getPageCount();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_PageControl_setCallback
  (JNIEnv * env, jobject thiz, jobject callback) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pc->setCallback(callback);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_PageControl_isVertical
  (JNIEnv * env, jobject thiz) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return pc->isVertical();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_PageControl_setVertical
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pc->setVertical(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_PageControl_removeAllPages
  (JNIEnv * env, jobject thiz) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	pc->removeAllPages();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_PageControl_setPageIndicator
  (JNIEnv * env, jobject thiz, jobject indicator) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPageIndicator* i = indicator == NULL ? NULL : (wyPageIndicator*)env->GetIntField(indicator, g_fid_BaseObject_mPointer);
	pc->setPageIndicator(i);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_PageControl_getPageIndicatorPointer
  (JNIEnv * env, jobject thiz) {
	wyPageControl* pc = (wyPageControl*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)pc->getPageIndicator();
}
