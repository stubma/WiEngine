#include "com_wiyun_engine_tmx_TMXTileMap.h"
#include "wyTMXTileMap.h"
#include "wyUtils_android.h"
#include "wyLog.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_nativeInit__I_3Lcom_wiyun_engine_opengl_Texture2D_2
  (JNIEnv * env, jobject thiz, jint resId, jobjectArray tex) {
	jsize len = env->GetArrayLength(tex);
	wyTexture2D* textures[len];
	for(int i = 0; i < len; i++) {
		jobject jt = (jobject)env->GetObjectArrayElement(tex, i);
		wyTexture2D* t = (wyTexture2D*)env->GetIntField(jt, g_fid_BaseObject_mPointer);
		textures[i] = t;
	}
	wyTMXTileMap* m = wyTMXTileMap::make(resId, textures, len);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)m);
	m->retain();
	m->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_nativeInit__Ljava_lang_String_2Z_3Lcom_wiyun_engine_opengl_Texture2D_2
  (JNIEnv * env, jobject thiz, jstring path, jboolean isFile, jobjectArray tex) {
	jsize len = env->GetArrayLength(tex);
	wyTexture2D* textures[len];
	for(int i = 0; i < len; i++) {
		jobject jt = (jobject)env->GetObjectArrayElement(tex, i);
		wyTexture2D* t = (wyTexture2D*)env->GetIntField(jt, g_fid_BaseObject_mPointer);
		textures[i] = t;
	}
	const char* p = (const char*)env->GetStringUTFChars(path, NULL);
	wyTMXTileMap* m = wyTMXTileMap::make(p, isFile, textures, len);
	env->ReleaseStringUTFChars(path, p);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)m);
	m->retain();
	m->lazyRelease();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_nativeGetTMXLayer
  (JNIEnv * env, jobject thiz, jstring name) {
	wyTMXTileMap* map = (wyTMXTileMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* n = env->GetStringUTFChars(name, NULL);
	wyTMXLayer* layer = map->getLayer(n);
	env->ReleaseStringUTFChars(name, n);
	return (jint)layer;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_nativeGetTMXLayerAt
  (JNIEnv * env, jobject thiz, jint index) {
	wyTMXTileMap* map = (wyTMXTileMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)map->getLayerAt(index);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_nativeGetObjectGroup
  (JNIEnv * env, jobject thiz, jstring name) {
	wyTMXTileMap* map = (wyTMXTileMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* n = env->GetStringUTFChars(name, NULL);
	wyTMXObjectGroup* group = map->getObjectGroup(n);
	env->ReleaseStringUTFChars(name, n);
	return (jint)group;
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_getProperty
  (JNIEnv * env, jobject thiz, jstring key) {
	wyTMXTileMap* map = (wyTMXTileMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* k = env->GetStringUTFChars(key, NULL);
	char* v = map->getProperty(k);
	jstring value = env->NewStringUTF(v);
	env->ReleaseStringUTFChars(key, k);
	return value;
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_getTileProperties
  (JNIEnv * env, jobject thiz, jint gid, jstring key) {
	wyTMXTileMap* map = (wyTMXTileMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* k = env->GetStringUTFChars(key, NULL);
	char* v = map->getTileProperty(gid, k);
	jstring value = env->NewStringUTF(v);
	env->ReleaseStringUTFChars(key, k);
	return value;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_getMapWidth
  (JNIEnv * env, jobject thiz) {
	wyTMXTileMap* map = (wyTMXTileMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return map->getMapWidth();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_getMapHeight
  (JNIEnv * env, jobject thiz) {
	wyTMXTileMap* map = (wyTMXTileMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return map->getMapHeight();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_getTileWidth
  (JNIEnv * env, jobject thiz) {
	wyTMXTileMap* map = (wyTMXTileMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return map->getTileWidth();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_getTileHeight
  (JNIEnv * env, jobject thiz) {
	wyTMXTileMap* map = (wyTMXTileMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return map->getTileHeight();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_getOrientation
  (JNIEnv * env, jobject thiz) {
	wyTMXTileMap* map = (wyTMXTileMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return map->getOrientation();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_setDebugDrawObjects
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyTMXTileMap* map = (wyTMXTileMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	map->setDebugDrawObjects(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_nativeNodeToTMXSpace
  (JNIEnv * env, jobject thiz, jobject p, jobject out) {
	wyTMXTileMap* map = (wyTMXTileMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint np = wyUtils_android::to_wyPoint(p);
	wyPoint nout = map->nodeToTMXSpace(np);
	wyUtils_android::to_WYPoint(nout, out);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_nativeTMXToNodeSpace
  (JNIEnv * env, jobject thiz, jobject p, jobject out) {
	wyTMXTileMap* map = (wyTMXTileMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint np = wyUtils_android::to_wyPoint(p);
	wyPoint nout = map->tmxToNodeSpace(np);
	wyUtils_android::to_WYPoint(nout, out);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_getAlpha
  (JNIEnv * env, jobject thiz) {
	wyTMXTileMap* map = (wyTMXTileMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return map->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_setAlpha
  (JNIEnv * env, jobject thiz, jint alpha) {
	wyTMXTileMap* map = (wyTMXTileMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	map->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_nativeGetColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyTMXTileMap* map = (wyTMXTileMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = map->getColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXTileMap_nativeSetColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyTMXTileMap* map = (wyTMXTileMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	map->setColor(wyc3b(r, g, b));
}
