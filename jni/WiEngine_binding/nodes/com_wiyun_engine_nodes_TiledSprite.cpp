#include "com_wiyun_engine_nodes_TiledSprite.h"
#include "wyTiledSprite.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_nativeInit
  (JNIEnv * env, jobject thiz, jobject texture) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	wyTiledSprite* ts = WYNEW wyTiledSprite(tex);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ts);
	wyObjectLazyRelease(ts);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_TiledSprite_nativeGetTexture
  (JNIEnv * env, jobject thiz) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)node->getTexture();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_setTexture
  (JNIEnv * env, jobject thiz, jobject texture) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	node->setTexture(tex);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_TiledSprite_getBlendFuncSrc
  (JNIEnv * env, jobject thiz) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getBlendFunc().src;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_TiledSprite_getBlendFuncDst
  (JNIEnv * env, jobject thiz) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getBlendFunc().dst;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_setBlendFunc
  (JNIEnv * env, jobject thiz, jint src, jint dst) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyBlendFunc func = { src, dst };
	node->setBlendFunc(func);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_TiledSprite_getAlpha
  (JNIEnv * env, jobject thiz) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_setAlpha
  (JNIEnv * env, jobject thiz, jint alpha) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_nativeGetColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = node->getColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_nativeSetColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = { r, g, b };
	node->setColor(c);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_TiledSprite_isTileVertical
  (JNIEnv * env, jobject thiz) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isTileVertical();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_TiledSprite_isTileHorizontal
  (JNIEnv * env, jobject thiz) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isTileHorizontal();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_setTileDirection
  (JNIEnv * env, jobject thiz, jboolean horizontal, jboolean vertical) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setTileDirection(horizontal, vertical);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_setTextureRect
  (JNIEnv * env, jobject thiz, jobject r) {
	wyRect rect = wyUtils_android::to_wyRect( r);
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setTextureRect(rect);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_TiledSprite_isFlinging
  (JNIEnv * env, jobject thiz) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isFlinging();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_setMaxOffsetX
  (JNIEnv* env, jobject thiz, jfloat max) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setMaxOffsetX(max);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_TiledSprite_getMaxOffsetX
  (JNIEnv* env, jobject thiz) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getMaxOffsetX();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_setMinOffsetX
  (JNIEnv* env, jobject thiz, jfloat min) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setMinOffsetX(min);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_TiledSprite_getMinOffsetX
  (JNIEnv* env, jobject thiz) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getMinOffsetX();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_setMaxOffsetY
  (JNIEnv* env, jobject thiz, jfloat max) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setMaxOffsetY(max);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_TiledSprite_getMaxOffsetY
  (JNIEnv* env, jobject thiz) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getMaxOffsetY();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_setMinOffsetY
  (JNIEnv* env, jobject thiz, jfloat min) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setMinOffsetY(min);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_TiledSprite_getMinOffsetY
  (JNIEnv* env, jobject thiz) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getMinOffsetY();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_setOffsetX
  (JNIEnv* env, jobject thiz, jfloat offset) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setOffsetX(offset);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_setOffsetY
  (JNIEnv* env, jobject thiz, jfloat offset) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setOffsetY(offset);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_offsetBy
  (JNIEnv* env, jobject thiz, jfloat dx, jfloat dy) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->offsetBy(dx, dy);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_stopFling
  (JNIEnv * env, jobject thiz) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->stopFling();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_fling
  (JNIEnv * env, jobject thiz, jfloat velocityX, jfloat velocityY) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->fling(velocityX, velocityY);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_setStretch
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setStretch(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_TiledSprite_isStretch
  (JNIEnv * env, jobject thiz) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isStretch();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_setSpacing
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setSpacing(x, y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_TiledSprite_getSpacingX
  (JNIEnv * env, jobject thiz) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getSpacingX();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_TiledSprite_getSpacingY
  (JNIEnv * env, jobject thiz) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getSpacingY();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_TiledSprite_isDither
  (JNIEnv * env, jobject thiz) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isDither();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TiledSprite_setDither
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyTiledSprite* node = (wyTiledSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setDither(flag);
}
