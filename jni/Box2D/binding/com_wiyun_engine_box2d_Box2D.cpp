#include <jni.h>
#include "com_wiyun_engine_box2d_Box2D.h"
#include "wyBox2D.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_Box2D_nativeInit
  (JNIEnv* env, jobject thiz) {
	wyBox2D* box2d = wyBox2D::make();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)box2d);
	box2d->retain();
	box2d->lazyRelease();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_Box2D_nativeGetWorld
  (JNIEnv * env, jobject thiz) {
	wyBox2D* box2d = (wyBox2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)box2d->getWorld();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_Box2D_isDebugDraw
  (JNIEnv * env, jobject thiz) {
	wyBox2D* box2d = (wyBox2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return box2d->isDebugDraw();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_Box2D_setDebugDraw
  (JNIEnv * env, jobject thiz, jboolean debugDraw) {
	wyBox2D* box2d = (wyBox2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	box2d->setDebugDraw(debugDraw);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_Box2D_pixel2Meter
  (JNIEnv * env, jobject thiz, jfloat pixel) {
	wyBox2D* box2d = (wyBox2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return box2d->pixel2Meter(pixel);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_Box2D_meter2Pixel
  (JNIEnv * env, jobject thiz, jfloat meter) {
	wyBox2D* box2d = (wyBox2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return box2d->meter2Pixel(meter);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_Box2D_getMeterPixels
  (JNIEnv * env, jobject thiz) {
	wyBox2D* box2d = (wyBox2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return box2d->getMeterPixels();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_Box2D_setMeterPixels
  (JNIEnv * env, jobject thiz, jfloat mp) {
	wyBox2D* box2d = (wyBox2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	box2d->setMeterPixels(mp);
}
