#include "com_wiyun_engine_afcanim_AFCSprite.h"
#include "wyAFCSprite.h"
#include "wyTypes.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_nativeGetAnimationAt
  (JNIEnv * env, jobject thiz, jint index) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)sprite->getAnimationAt(index);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_getAnimationCount
  (JNIEnv * env, jobject thiz) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return sprite->getAnimationCount();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_getImageCount
  (JNIEnv * env, jobject thiz) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return sprite->getImageCount();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_playAnimation__I
  (JNIEnv * env, jobject thiz, jint index) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	sprite->playAnimation(index);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_playAnimation__ILcom_wiyun_engine_afcanim_AFCClipMapping_2
  (JNIEnv * env, jobject thiz, jint index, jobject mapping) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyAFCClipMapping* m = mapping == NULL ? NULL : (wyAFCClipMapping*)env->GetIntField(mapping, g_fid_BaseObject_mPointer);
	sprite->playAnimation(index, m);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_playAnimation__II
  (JNIEnv * env, jobject thiz, jint index, jint mappingTag) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	sprite->playAnimation(index, mappingTag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_setFrameIndex
  (JNIEnv * env, jobject thiz, jint index) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	sprite->setFrameIndex(index);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_tick
  (JNIEnv * env, jobject thiz, jfloat delta) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	sprite->tick(delta);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_setIgnoreFrameOffset
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	sprite->setIgnoreFrameOffset(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_isIgnoreFrameOffset
  (JNIEnv * env, jobject thiz) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return sprite->isIgnoreFrameOffset();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_nativeGetFrameOffset
  (JNIEnv * env, jobject thiz, jobject p) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint o = sprite->getFrameOffset();
	wyUtils_android::to_WYPoint(o, p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_setAFCSpriteCallback
  (JNIEnv * env, jobject thiz, jobject callback) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	sprite->setAFCSpriteCallback(callback);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_getCurrentAnimationIndex
  (JNIEnv * env, jobject thiz) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return sprite->getCurrentAnimationIndex();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_getCurrentFrame
  (JNIEnv * env, jobject thiz) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return sprite->getCurrentFrame();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_getFrameCount
  (JNIEnv * env, jobject thiz) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return sprite->getFrameCount();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_isReverse
  (JNIEnv * env, jobject thiz) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return sprite->isReverse();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_setReverse
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	sprite->setReverse(flag);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_getLoopCount
  (JNIEnv * env, jobject thiz) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return sprite->getLoopCount();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_setLoopCount
  (JNIEnv * env, jobject thiz, jint loop) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	sprite->setLoopCount(loop);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_isAnimationEnded
  (JNIEnv * env, jobject thiz) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return sprite->isAnimationEnded();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_isFlipX
  (JNIEnv * env, jobject thiz) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return sprite->isFlipX();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_setFlipX
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	sprite->setFlipX(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_isFlipY
  (JNIEnv * env, jobject thiz) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return sprite->isFlipY();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_setFlipY
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	sprite->setFlipX(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_setPaused
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	sprite->setPaused(flag);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_isPaused
  (JNIEnv * env, jobject thiz) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return sprite->isPaused();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_nativeGetCurrentAnimationData
  (JNIEnv * env, jobject thiz) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)sprite->getCurrentAnimationData();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_getAlpha
  (JNIEnv * env, jobject thiz) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return sprite->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_setAlpha
  (JNIEnv * env, jobject thiz, jint alpha) {
	wyAFCSprite* sprite = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	sprite->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_nativeGetColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = node->getColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_nativeSetColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = { r, g, b };
	node->setColor(c);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_getUnitInterval
  (JNIEnv * env, jobject thiz) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getUnitInterval();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_setUnitInterval
  (JNIEnv * env, jobject thiz, jfloat interval) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setUnitInterval(interval);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_isForceTickMode
  (JNIEnv * env, jobject thiz) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isForceTickMode();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_setForceTickMode
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setForceTickMode(flag);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_getCollisionRectCount
  (JNIEnv * env, jobject thiz) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getCollisionRectCount();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_nativeGetCollisionRect
  (JNIEnv * env, jobject thiz, jint index, jobject r) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyRect rect = node->getCollisionRect(index);
	wyUtils_android::to_WYRect( rect, r);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_nativeGetCollisionRectRelativeToParent
  (JNIEnv * env, jobject thiz, jint index, jobject r) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyRect rect = node->getCollisionRectRelativeToParent(index);
	wyUtils_android::to_WYRect( rect, r);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_nativeGetCollisionRectRelativeToWorld
  (JNIEnv * env, jobject thiz, jint index, jobject r) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyRect rect = node->getCollisionRectRelativeToWorld(index);
	wyUtils_android::to_WYRect( rect, r);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_nativeGetFrameRect
  (JNIEnv * env, jobject thiz, jobject r) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyRect rect = node->getFrameRect();
	wyUtils_android::to_WYRect( rect, r);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_nativeGetFrameRectRelativeToParent
  (JNIEnv * env, jobject thiz, jobject r) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyRect rect = node->getFrameRectRelativeToParent();
	wyUtils_android::to_WYRect( rect, r);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_nativeGetFrameRectRelativeToWorld
  (JNIEnv * env, jobject thiz, jobject r) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyRect rect = node->getFrameRectRelativeToWorld();
	wyUtils_android::to_WYRect( rect, r);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_setDebugDrawFrameRect
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setDebugDrawFrameRect(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_setDebugDrawCollisionRect
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setDebugDrawCollisionRect(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_addClipMapping
  (JNIEnv * env, jobject thiz, jobject mapping) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyAFCClipMapping* m = (wyAFCClipMapping*)env->GetIntField(mapping, g_fid_BaseObject_mPointer);
	node->addClipMapping(m);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_removeClipMappingByTag
  (JNIEnv * env, jobject thiz, jint tag) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->removeClipMappingByTag(tag);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_nativeGetClipMappingByTag
  (JNIEnv * env, jobject thiz, jint tag) {
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)node->getClipMappingByTag(tag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCSprite_replaceTextures
  (JNIEnv * env, jobject thiz, jobjectArray tex) {
	jsize len = env->GetArrayLength(tex);
	wyTexture2D* textures[len];
	for(int i = 0; i < len; i++) {
		jobject jt = (jobject)env->GetObjectArrayElement(tex, i);
		wyTexture2D* t = jt == NULL ? NULL : (wyTexture2D*)env->GetIntField(jt, g_fid_BaseObject_mPointer);
		textures[i] = t;
	}
	wyAFCSprite* node = (wyAFCSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->replaceTextures(textures, len);
}
