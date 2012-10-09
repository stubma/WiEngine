#include "com_wiyun_engine_tmx_TMXLayer.h"
#include "wyTMXLayer.h"
#include "wyUtils_android.h"
#include <stdlib.h>

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXLayer_getLayerWidth
  (JNIEnv* env, jobject thiz) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return layer->getLayerWidth();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXLayer_getLayerHeight
  (JNIEnv* env, jobject thiz) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return layer->getLayerHeight();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXLayer_getTileWidth
  (JNIEnv* env, jobject thiz) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return layer->getTileWidth();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXLayer_getTileHeight
  (JNIEnv* env, jobject thiz) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return layer->getTileHeight();
}

JNIEXPORT jintArray JNICALL Java_com_wiyun_engine_tmx_TMXLayer_getGids
  (JNIEnv* env, jobject thiz) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jintArray ret = env->NewIntArray(layer->getLayerWidth() * layer->getLayerHeight());
	env->SetIntArrayRegion(ret, 0, layer->getLayerWidth() * layer->getLayerHeight(), layer->getGids());
	return ret;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXLayer_getGidAt
  (JNIEnv * env, jobject thiz, jint x, jint y) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return layer->getGidAt(x, y);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXLayer_nativeTileAt
  (JNIEnv * env, jobject thiz, jint x, jint y) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)layer->tileAt(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXLayer_removeTileAt
  (JNIEnv * env, jobject thiz, jint x, jint y) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	layer->removeTileAt(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXLayer_removeTile
  (JNIEnv * env, jobject thiz, jobject sprite) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wySpriteEx* s = (wySpriteEx*)env->GetIntField(sprite, g_fid_BaseObject_mPointer);
	layer->removeTile(s);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXLayer_setTileAt
  (JNIEnv * env, jobject thiz, jint gid, jint x, jint y) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	layer->setTileAt(gid, x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXLayer_updateTileAt
  (JNIEnv * env, jobject thiz, jint gid, jint x, jint y) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	layer->updateTileAt(gid, x, y);
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_tmx_TMXLayer_getProperty
  (JNIEnv * env, jobject thiz, jstring key) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* k = env->GetStringUTFChars(key, NULL);
	char* v = layer->getProperty(k);
	jstring value = env->NewStringUTF(v);
	env->ReleaseStringUTFChars(key, k);
	return value;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXLayer_nativeGetPositionAt
  (JNIEnv * env, jobject thiz, jint x, jint y, jobject p) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint pos = layer->getPositionAt(x, y);
	wyUtils_android::to_WYPoint(pos, p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXLayer_nativeGetTileCoordinateAt
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y, jobject d) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyDimension dim = layer->getTileCoordinateAt(x, y);
	wyUtils_android::to_WYDimension(dim, d);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXLayer_getAlpha
  (JNIEnv * env, jobject thiz) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return layer->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXLayer_setAlpha
  (JNIEnv * env, jobject thiz, jint alpha) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	layer->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXLayer_nativeGetColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = layer->getColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXLayer_nativeSetColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyTMXLayer* layer = (wyTMXLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	layer->setColor(wyc3b(r, g, b));
}
