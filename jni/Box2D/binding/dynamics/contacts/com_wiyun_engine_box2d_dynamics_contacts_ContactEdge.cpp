#include "com_wiyun_engine_box2d_dynamics_contacts_ContactEdge.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_ContactEdge_nativeGetBody
  (JNIEnv * env, jobject thiz) {
	b2ContactEdge* e = (b2ContactEdge*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)e->other;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_ContactEdge_nativeGetContact
  (JNIEnv * env, jobject thiz) {
	b2ContactEdge* e = (b2ContactEdge*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)e->contact;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_ContactEdge_nativeGetNext
  (JNIEnv * env, jobject thiz) {
	b2ContactEdge* e = (b2ContactEdge*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)e->next;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_contacts_ContactEdge_nativeGetPrev
  (JNIEnv * env, jobject thiz) {
	b2ContactEdge* e = (b2ContactEdge*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)e->prev;
}
