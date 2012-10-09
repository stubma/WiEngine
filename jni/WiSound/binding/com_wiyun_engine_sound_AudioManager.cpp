#if ANDROID

#include "com_wiyun_engine_sound_AudioManager.h"
#include "wyAudioManager.h"

#if BACKEND_OPENAL

#ifdef __cplusplus
extern "C" {
#endif

extern void onWiSoundPeriodicNotification();

#ifdef __cplusplus
}
#endif

#endif // #if BACKEND_OPENAL

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_onPeriodicNotification
  (JNIEnv * env, jclass clazz) {
#if BACKEND_OPENAL
	onWiSoundPeriodicNotification();
#endif // #if BACKEND_OPENAL
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_preloadBackgroundMusic__I
  (JNIEnv * env, jclass clazz, jint resId) {
	wyAudioManager::getInstance()->preloadBackgroundMusic(resId, FORMAT_MP3);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_preloadBackgroundMusic__II
  (JNIEnv * env, jclass clazz, jint resId, jint type) {
	wyAudioManager::getInstance()->preloadBackgroundMusic(resId, type);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_preloadBackgroundMusic__Ljava_lang_String_2Z
  (JNIEnv * env, jclass clazz, jstring path, jboolean isFile) {
	const char* str = env->GetStringUTFChars(path, NULL);
	wyAudioManager::getInstance()->preloadBackgroundMusic(str, isFile);
	env->ReleaseStringUTFChars(path, str);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_playBackgroundMusic__I
  (JNIEnv* env, jclass clazz, jint resId) {
	wyAudioManager::getInstance()->playBackgroundMusic(resId, FORMAT_MP3, -1);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_playBackgroundMusic__III
  (JNIEnv* env, jclass clazz, jint resId, jint format, jint repeatCount) {
	wyAudioManager::getInstance()->playBackgroundMusic(resId, format, repeatCount);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_playBackgroundMusic__Ljava_lang_String_2ZI
  (JNIEnv* env, jclass clazz, jstring path, jboolean isFile, jint repeatCount) {
	const char* str = env->GetStringUTFChars(path, NULL);
	wyAudioManager::getInstance()->playBackgroundMusic(str, isFile, repeatCount);
	env->ReleaseStringUTFChars(path, str);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_stopBackgroundMusic
  (JNIEnv* env, jclass clazz) {
	wyAudioManager::getInstance()->stopBackgroundMusic();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_sound_AudioManager_isBackgroundMusicPaused
  (JNIEnv* env, jclass clazz) {
	return wyAudioManager::getInstance()->isBackgroundMusicPaused();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_pauseBackgroundMusic
  (JNIEnv* env, jclass clazz) {
	wyAudioManager::getInstance()->pauseBackgroundMusic();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_resumeBackgroundMusic
  (JNIEnv* env, jclass clazz) {
	wyAudioManager::getInstance()->resumeBackgroundMusic();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_sound_AudioManager_isBackgroundPlaying
  (JNIEnv* env, jclass clazz) {
	return wyAudioManager::getInstance()->isBackgroundPlaying();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_removeAllEffects
  (JNIEnv* env, jclass clazz) {
	wyAudioManager::getInstance()->removeAllEffects();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_removeEffect__I
  (JNIEnv * env, jclass clazz, jint resId) {
	wyAudioManager::getInstance()->removeEffect(resId);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_removeEffect__Ljava_lang_String_2
  (JNIEnv * env, jclass clazz, jstring path) {
	const char* p = env->GetStringUTFChars(path, NULL);
	wyAudioManager::getInstance()->removeEffect(p);
	env->ReleaseStringUTFChars(path, p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_playEffect__I
  (JNIEnv* env, jclass clazz, jint resId) {
	wyAudioManager::getInstance()->playEffect(resId);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_playEffect__II
  (JNIEnv* env, jclass clazz, jint resId, jint type) {
	wyAudioManager::getInstance()->playEffect(resId, type);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_playEffect__Ljava_lang_String_2Z
  (JNIEnv* env, jclass clazz, jstring path, jboolean isFile) {
	const char* str = env->GetStringUTFChars(path, NULL);
	wyAudioManager::getInstance()->playEffect(str, isFile);
	env->ReleaseStringUTFChars(path, str);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_stopEffect__I
  (JNIEnv* env, jclass clazz, jint resId) {
	wyAudioManager::getInstance()->stopEffect(resId);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_stopEffect__Ljava_lang_String_2Z
  (JNIEnv* env, jclass clazz, jstring path, jboolean isFile) {
	const char* str = env->GetStringUTFChars(path, NULL);
	wyAudioManager::getInstance()->stopEffect(str, isFile);
	env->ReleaseStringUTFChars(path, str);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_preloadEffect__I
  (JNIEnv* env, jclass clazz, jint resId) {
	wyAudioManager::getInstance()->preloadEffect(resId);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_preloadEffect__II
  (JNIEnv* env, jclass clazz, jint resId, jint type) {
	wyAudioManager::getInstance()->preloadEffect(resId, type);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_preloadEffect__Ljava_lang_String_2Z
  (JNIEnv* env, jclass clazz, jstring path, jboolean isFile) {
	const char* str = env->GetStringUTFChars(path, NULL);
	wyAudioManager::getInstance()->preloadEffect(str, isFile);
	env->ReleaseStringUTFChars(path, str);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_setEffectVolume
  (JNIEnv* env, jclass clazz, jfloat volume) {
	wyAudioManager::getInstance()->setEffectVolume(volume);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_setBackgroundVolume
  (JNIEnv* env, jclass clazz, jfloat volume) {
	wyAudioManager::getInstance()->setBackgroundVolume(volume);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_sound_AudioManager_setMute
  (JNIEnv * env, jclass clazz, jboolean mute) {
	wyAudioManager* am = wyAudioManager::getInstanceNoCreate();
	if(am)
		am->setMute(mute);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_sound_AudioManager_isMuted
  (JNIEnv * env, jclass clazz) {
	wyAudioManager* am = wyAudioManager::getInstanceNoCreate();
	return am == NULL ? true : am->isMuted();
}

#endif // #if ANDROID
