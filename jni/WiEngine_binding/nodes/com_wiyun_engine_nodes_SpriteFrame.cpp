#include "com_wiyun_engine_nodes_SpriteFrame.h"
#include "wySpriteFrame.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject tex, jobject rect, jobject offset, jobject originalSize, jboolean rotated) {
	wyRect r = wyUtils_android::to_wyRect( rect);
	wyPoint p = wyUtils_android::to_wyPoint( offset);
	wySize s = wyUtils_android::to_wySize( originalSize);
	wyTexture2D* t = NULL;
	if(tex != NULL)
		t = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	wySpriteFrame* f = wySpriteFrame::make(duration, t, r, p, s, rotated);
	f->retain();
	f->lazyRelease();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)f);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_nativeGetTexture
  (JNIEnv * env, jobject thiz) {
	wySpriteFrame* f = (wySpriteFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)f->getTexture();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_nativeGetRect
  (JNIEnv * env, jobject thiz, jobject rect) {
	wySpriteFrame* f = (wySpriteFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyUtils_android::to_WYRect( f->getRect(), rect);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_nativeGetSourceColorRect
  (JNIEnv * env, jobject thiz, jobject rect) {
	wySpriteFrame* f = (wySpriteFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyUtils_android::to_WYRect( f->getSourceColorRect(), rect);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_nativeGetOffset
  (JNIEnv * env, jobject thiz, jobject offset) {
	wySpriteFrame* f = (wySpriteFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyUtils_android::to_WYPoint(f->getOffset(), offset);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_nativeGetOriginalSize
  (JNIEnv * env, jobject thiz, jobject originalSize) {
	wySpriteFrame* f = (wySpriteFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyUtils_android::to_WYSize(f->getOriginalSize(), originalSize);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_setRotated
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wySpriteFrame* f = (wySpriteFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->setRotated(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_isRotated
  (JNIEnv * env, jobject thiz) {
	wySpriteFrame* f = (wySpriteFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->isRotated();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteFrame_setTexture
  (JNIEnv * env, jobject thiz, jobject tex) {
	wySpriteFrame* f = (wySpriteFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTexture2D* t = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	f->setTexture(t);
}
