#include "com_wiyun_engine_transitions_TransitionScene.h"
#include "wyTransitionScene.h"
#include "wyEaseAction.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_TransitionScene_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject inScene) {
	wyScene* scene = inScene == NULL ? NULL : (wyScene*)env->GetIntField(inScene, g_fid_BaseObject_mPointer);
	wyTransitionScene* s = wyTransitionScene::make(duration, scene);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)s);
	s->retain();
	s->lazyRelease();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_transitions_TransitionScene_getDuration
  (JNIEnv * env, jobject thiz) {
	wyTransitionScene* trans = (wyTransitionScene*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return trans->getDuration();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_transitions_TransitionScene_nativeGetInScene
  (JNIEnv * env, jobject thiz) {
	wyTransitionScene* trans = (wyTransitionScene*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)trans->getInScene();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_TransitionScene_setInScene
  (JNIEnv * env, jobject thiz, jobject scene) {
	if(scene) {
		wyTransitionScene* trans = (wyTransitionScene*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
		wyScene* in = (wyScene*)env->GetIntField(scene, g_fid_BaseObject_mPointer);
		trans->setInScene(in);
	}
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_transitions_TransitionScene_nativeGetOutScene
  (JNIEnv * env, jobject thiz) {
	wyTransitionScene* trans = (wyTransitionScene*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)trans->getOutScene();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_TransitionScene_setOutScene
  (JNIEnv * env, jobject thiz, jobject scene) {
	if(scene) {
		wyTransitionScene* trans = (wyTransitionScene*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
		wyScene* out = (wyScene*)env->GetIntField(scene, g_fid_BaseObject_mPointer);
		trans->setOutScene(out);
	}
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_TransitionScene_setInEaseAction
  (JNIEnv * env, jobject thiz, jobject inEase) {
	wyTransitionScene* trans = (wyTransitionScene*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyEaseAction* ease = (wyEaseAction*)env->GetIntField(inEase, g_fid_BaseObject_mPointer);
	trans->setInEaseAction(ease);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_TransitionScene_setOutEaseAction
  (JNIEnv * env, jobject thiz, jobject outEase) {
	wyTransitionScene* trans = (wyTransitionScene*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyEaseAction* ease = (wyEaseAction*)env->GetIntField(outEase, g_fid_BaseObject_mPointer);
	trans->setOutEaseAction(ease);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_TransitionScene_setFinishCallback
  (JNIEnv * env, jobject thiz, jobject ts) {
	wyTransitionScene* trans = (wyTransitionScene*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	trans->setFinishCallback(wyTargetSelector::make(ts));
}
