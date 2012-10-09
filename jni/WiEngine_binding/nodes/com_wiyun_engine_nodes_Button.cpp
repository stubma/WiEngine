#include "com_wiyun_engine_nodes_Button.h"
#include "wyButton.h"
#include "wyLog.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Button_nativeInit
  (JNIEnv * env, jobject thiz, jobject normal, jobject selected, jobject disabled, jobject focused, jobject downSelector, jobject upSelector) {
	wyNode* normalSprite = (wyNode*)env->GetIntField(normal, g_fid_BaseObject_mPointer);
	wyNode* selectedSprite = selected == NULL ? NULL : (wyNode*)env->GetIntField(selected, g_fid_BaseObject_mPointer);
	wyNode* disabledSprite = disabled == NULL ? NULL : (wyNode*)env->GetIntField(disabled, g_fid_BaseObject_mPointer);
	wyNode* focusedSprite = focused == NULL ? NULL : (wyNode*)env->GetIntField(focused, g_fid_BaseObject_mPointer);
	wyTargetSelector* down = NULL;
	if(downSelector != NULL) {
		down = wyTargetSelector::make(downSelector);
	}
	wyTargetSelector* up = NULL;
	if(upSelector != NULL) {
		up = wyTargetSelector::make(upSelector);
	}
	wyButton* b = WYNEW wyButton(normalSprite, selectedSprite, disabledSprite, focusedSprite, down, up);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)b);
	b->lazyRelease();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Button_getAlpha
  (JNIEnv * env, jobject thiz) {
	wyButton* node = (wyButton*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Button_setAlpha
  (JNIEnv * env, jobject thiz, jint alpha) {
	wyButton* node = (wyButton*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Button_nativeGetColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyButton* node = (wyButton*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = node->getColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Button_nativeSetColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyButton* node = (wyButton*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = { r, g, b };
	node->setColor(c);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Button_setTexture
  (JNIEnv * env, jobject thiz, jobject normal, jobject selected, jobject disabled, jobject focused) {
	wyButton* node = (wyButton*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTexture2D* n = normal == NULL ? NULL : (wyTexture2D*)env->GetIntField(normal, g_fid_BaseObject_mPointer);
	wyTexture2D* s = selected == NULL ? NULL : (wyTexture2D*)env->GetIntField(selected, g_fid_BaseObject_mPointer);
	wyTexture2D* d = disabled == NULL ? NULL : (wyTexture2D*)env->GetIntField(disabled, g_fid_BaseObject_mPointer);
	wyTexture2D* f = focused == NULL ? NULL : (wyTexture2D*)env->GetIntField(focused, g_fid_BaseObject_mPointer);
	node->setTexture(n, s, d, f);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Button_setTextureRect
  (JNIEnv * env, jobject thiz, jobject normalRect, jobject selectedRect, jobject disabledRect, jobject focusedRect) {
	wyButton* node = (wyButton*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyRect zero = wyr(0, 0, 0, 0);
	wyRect nr = normalRect == NULL ? zero : wyUtils_android::to_wyRect( normalRect);
	wyRect sr = selectedRect == NULL ? zero : wyUtils_android::to_wyRect( selectedRect);
	wyRect dr = disabledRect == NULL ? zero : wyUtils_android::to_wyRect( disabledRect);
	wyRect fr = focusedRect == NULL ? zero : wyUtils_android::to_wyRect( focusedRect);
	node->setTextureRect(wyrEquals(nr, zero) ? NULL : &nr,
			wyrEquals(sr, zero) ? NULL : &sr,
			wyrEquals(dr, zero) ? NULL : &dr,
			wyrEquals(fr, zero) ? NULL : &fr);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Button_setClickScale
  (JNIEnv * env, jobject thiz, jfloat scale) {
	wyButton* node = (wyButton*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setClickScale(scale);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Button_getClickScale
  (JNIEnv * env, jobject thiz) {
	wyButton* node = (wyButton*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getClickScale();
}
