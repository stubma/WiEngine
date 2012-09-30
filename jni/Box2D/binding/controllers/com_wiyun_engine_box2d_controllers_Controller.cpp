#include "com_wiyun_engine_box2d_controllers_Controller.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_Controller_addBody
  (JNIEnv * env, jobject thiz, jobject body) {
	b2Controller* c = (b2Controller*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Body* b = (b2Body*)env->GetIntField(body, g_fid_BaseObject_mPointer);
	c->AddBody(b);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_Controller_removeBody
  (JNIEnv * env, jobject thiz, jobject body) {
	b2Controller* c = (b2Controller*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Body* b = (b2Body*)env->GetIntField(body, g_fid_BaseObject_mPointer);
	c->RemoveBody(b);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_controllers_Controller_clear
  (JNIEnv * env, jobject thiz) {
	b2Controller* c = (b2Controller*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	c->Clear();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_controllers_Controller_getNext
  (JNIEnv * env, jobject thiz) {
	b2Controller* c = (b2Controller*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)c->GetNext();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_controllers_Controller_getWorld
  (JNIEnv * env, jobject thiz) {
	b2Controller* c = (b2Controller*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)c->GetWorld();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_controllers_Controller_getBodyList
  (JNIEnv * env, jobject thiz) {
	b2Controller* c = (b2Controller*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)c->GetBodyList();
}
