#include "com_wiyun_engine_opengl_Camera.h"
#include "wyCamera.h"
#include "wyTypes.h"
#include "wyGlobal.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Camera_nativeNew
  (JNIEnv * env, jobject thiz) {
	wyCamera* camera = wyCamera::make();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)camera);
	camera->retain();
	camera->lazyRelease();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_opengl_Camera_isDirty
  (JNIEnv * env, jobject thiz) {
	wyCamera* camera = (wyCamera*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return camera->isDirty();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Camera_setDirty
  (JNIEnv * env, jobject thiz, jboolean value) {
	wyCamera* camera = (wyCamera*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	camera->setDirty(value);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Camera_restore
  (JNIEnv * env, jobject thiz) {
	wyCamera* camera = (wyCamera*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	camera->restore();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Camera_locate
  (JNIEnv * env, jobject thiz) {
	wyCamera* camera = (wyCamera*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	camera->locate();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_opengl_Camera_getZEye
  (JNIEnv * env, jclass clazz) {
	return wyCamera::getZEye();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Camera_setEye
  (JNIEnv * env, jobject thiz, jfloat eyeX, jfloat eyeY, jfloat eyeZ) {
	wyCamera* camera = (wyCamera*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	camera->setEye(eyeX, eyeY, eyeZ);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Camera_setCenter
  (JNIEnv * env, jobject thiz, jfloat centerX, jfloat centerY, jfloat centerZ) {
	wyCamera* camera = (wyCamera*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	camera->setCenter(centerX, centerY, centerZ);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Camera_setUp
  (JNIEnv * env, jobject thiz, jfloat upX, jfloat upY, jfloat upZ) {
	wyCamera* camera = (wyCamera*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	camera->setUp(upX, upY, upZ);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Camera_getEye
  (JNIEnv * env, jobject thiz, jfloatArray v) {
	wyCamera* camera = (wyCamera*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float f[3];
	camera->getEye(f);
	env->SetFloatArrayRegion(v, 0, 3, f);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Camera_getCenter
  (JNIEnv * env, jobject thiz, jfloatArray v) {
	wyCamera* camera = (wyCamera*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float f[3];
	camera->getCenter(f);
	env->SetFloatArrayRegion(v, 0, 3, f);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Camera_getUp
  (JNIEnv * env, jobject thiz, jfloatArray v) {
	wyCamera* camera = (wyCamera*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float f[3];
	camera->getUp(f);
	env->SetFloatArrayRegion(v, 0, 3, f);
}
