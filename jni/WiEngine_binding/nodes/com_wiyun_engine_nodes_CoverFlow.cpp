#include "com_wiyun_engine_nodes_CoverFlow.h"
#include "wyCoverFlow.h"
#include "wyGlobal.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_nativeInit
  (JNIEnv* env, jobject thiz) {
    wyCoverFlow* cf = WYNEW wyCoverFlow();
    env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)cf);    
    cf->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_addCover
  (JNIEnv* env, jobject thiz, jobject cover) {
    wyCover* pCover = (wyCover*)env->GetIntField(cover, g_fid_BaseObject_mPointer);
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->addCover(pCover);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_removeCover
  (JNIEnv* env, jobject thiz, jobject cover) {
    wyCover* pCover = (wyCover*)env->GetIntField(cover, g_fid_BaseObject_mPointer);
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->removeCover(pCover);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_insertCoverBefore
  (JNIEnv* env, jobject thiz, jobject cover, jobject after) {
    wyCover* pCover = (wyCover*)env->GetIntField(cover, g_fid_BaseObject_mPointer);
    wyCover* pAfter = (wyCover*)env->GetIntField(after, g_fid_BaseObject_mPointer);
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->insertCoverBefore(pCover, pAfter);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_CoverFlow_getIndex
  (JNIEnv* env, jobject thiz, jobject cover) {
    wyCover* pCover = (wyCover*)env->GetIntField(cover, g_fid_BaseObject_mPointer);
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return cf->getIndex(pCover);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_CoverFlow_nativeGetCoverAt
  (JNIEnv* env, jobject thiz, jint index) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return (jint)cf->getCoverAt(index);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_CoverFlow_nativeGetCoverList
  (JNIEnv* env, jobject thiz) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return (jint)cf->getCoverList();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_CoverFlow_nativeGetFrontCover
  (JNIEnv* env, jobject thiz) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return (jint)cf->getFrontCover();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_setFrontCoverSize
  (JNIEnv* env, jobject thiz, jfloat width, jfloat height, jboolean updateOthers) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->setFrontCoverSize(width, height, updateOthers);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_setFrontCenterPosition
  (JNIEnv* env, jobject thiz, jint centerX, jint centerY) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->setFrontCenterPosition(centerX, centerY);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_setCountLeftVisible
  (JNIEnv* env, jobject thiz, jint count) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->setCountLeftVisible(count);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_CoverFlow_getCountLeftVisible
  (JNIEnv* env, jobject thiz) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return cf->getCountLeftVisible();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_setCountRightVisible
  (JNIEnv* env, jobject thiz, jint count) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->setCountRightVisible(count);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_CoverFlow_getCountRightVisible
  (JNIEnv* env, jobject thiz) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return cf->getCountRightVisible();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_CoverFlow_isMirrorEnabled
  (JNIEnv* env, jobject thiz) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return cf->isMirrorEnabled();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_setMirrorEnable
  (JNIEnv* env, jobject thiz, jboolean bEnable) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->setMirrorEnable(bEnable);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_setBlurredBorderWidth
  (JNIEnv* env, jobject thiz, jfloat percent) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->setBlurredBorderWidth(percent);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_setBlurredBorderWidthInPixels
  (JNIEnv* env, jobject thiz, jint width) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->setBlurredBorderWidthInPixels(width);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_setDepthZ
  (JNIEnv* env, jobject thiz, jfloat z) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->setDepthZ(z);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_CoverFlow_getDepthZ
  (JNIEnv* env, jobject thiz) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return cf->getDepthZ();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_setFirstLeftOffset
  (JNIEnv* env, jobject thiz, jfloat offset) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->setFirstLeftOffset(offset);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_CoverFlow_getFirstLeftOffset
  (JNIEnv* env, jobject thiz) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return cf->getFirstLeftOffset();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_setFirstRightOffset
  (JNIEnv* env, jobject thiz, jfloat offset) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->setFirstRightOffset(offset);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_CoverFlow_getFirstRightOffset
  (JNIEnv* env, jobject thiz) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return cf->getFirstRightOffset();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_setLeftCoverCenterDelta
  (JNIEnv* env, jobject thiz, jfloat delta) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->setLeftCoverCenterDelta(delta);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_CoverFlow_getLeftCoverCenterDelta
  (JNIEnv* env, jobject thiz) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return cf->getLeftCoverCenterDelta();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_setRightCoverCenterDelta
  (JNIEnv* env, jobject thiz, jfloat delta) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->setRightCoverCenterDelta(delta);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_CoverFlow_getRightCoverCenterDelta
  (JNIEnv* env, jobject thiz) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return cf->getRightCoverCenterDelta();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_setRotateDegreeLeft
  (JNIEnv* env, jobject thiz, jfloat degree) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->setRotateDegreeLeft(degree);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_CoverFlow_getRotateDegreeLeft
  (JNIEnv* env, jobject thiz) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return cf->getRotateDegreeLeft();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_setRotateDegreeRight
  (JNIEnv* env, jobject thiz, jfloat degree) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->setRotateDegreeRight(degree);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_CoverFlow_getRotateDegreeRight
  (JNIEnv* env, jobject thiz) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return cf->getRotateDegreeRight();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_showCover
  (JNIEnv* env, jobject thiz, jobject cover, jfloat duration) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    wyCover* pCover = (wyCover*)env->GetIntField(cover, g_fid_BaseObject_mPointer);
    cf->showCover(pCover, duration);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_moveLeft
  (JNIEnv* env, jobject thiz, jfloat duration) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->moveLeft(duration);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_moveRight
  (JNIEnv* env, jobject thiz, jfloat duration) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->moveRight(duration);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_CoverFlow_nativeGetTouchedCover
  (JNIEnv* env, jobject thiz, jfloat x, jfloat y) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    y = wyDevice::realHeight - y;

	// if not density scale mode, must convert coordinates relative to base size
	if(wyDevice::scaleMode != SCALE_MODE_BY_DENSITY) {
		x = x / wyDevice::baseScaleX;
		y = y / wyDevice::baseScaleY;
	}
    return (jint)cf->getTouchedCover(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_setHeightFromMirror
  (JNIEnv* env, jobject thiz, jfloat height) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->setHeightFromMirror(height);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_CoverFlow_getHeightFromMirror
  (JNIEnv* env, jobject thiz) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return (jfloat)cf->getHeightFromMirror();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CoverFlow_setBrightLevelOfMirror
  (JNIEnv* env, jobject thiz, jfloat level) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cf->setBrightLevelOfMirror(level);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_CoverFlow_getBrightLevelOfMirror
  (JNIEnv* env, jobject thiz) {
    wyCoverFlow* cf = (wyCoverFlow*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return (jfloat)cf->getBrightLevelOfMirror();
}
