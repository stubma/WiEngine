#include "com_wiyun_engine_box2d_FixtureAnimation.h"
#include "wyFixtureAnimation.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_FixtureAnimation_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyFixtureAnimation* anim = WYNEW wyFixtureAnimation();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)anim);
	anim->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_FixtureAnimation_nativeAddFrame
  (JNIEnv * env, jobject thiz, jfloat duration, jobject texture) {
	wyFixtureAnimation* anim = (wyFixtureAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	anim->addFrame(duration, tex);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_FixtureAnimation_start
  (JNIEnv * env, jobject thiz, jobject fixture) {
	wyFixtureAnimation* anim = (wyFixtureAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Fixture* f = (b2Fixture*)env->GetIntField(fixture, g_fid_BaseObject_mPointer);
	anim->start(f);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_FixtureAnimation_stop
  (JNIEnv * env, jobject thiz) {
	wyFixtureAnimation* anim = (wyFixtureAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	anim->stop();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_FixtureAnimation_isLoop
  (JNIEnv * env, jobject thiz) {
	wyFixtureAnimation* anim = (wyFixtureAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return anim->isLoop();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_FixtureAnimation_setLoop
  (JNIEnv * env, jobject thiz, jboolean loop) {
	wyFixtureAnimation* anim = (wyFixtureAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	anim->setLoop(loop);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_FixtureAnimation_getDuration
  (JNIEnv * env, jobject thiz) {
	wyFixtureAnimation* anim = (wyFixtureAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return anim->getDuration();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_FixtureAnimation_setDuration
  (JNIEnv * env, jobject thiz, jfloat duration) {
	wyFixtureAnimation* anim = (wyFixtureAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	anim->setDuration(duration);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_FixtureAnimation_setCallback
  (JNIEnv * env, jobject thiz, jobject callback) {
	wyFixtureAnimation* anim = (wyFixtureAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	anim->setJavaCallback(callback);
}
