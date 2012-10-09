#include "com_wiyun_engine_actions_Follow.h"
#include "wyFollow.h"
#include "wyNode.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Follow_nativeInit
  (JNIEnv * env, jobject thiz, jobject node, jint x, jint y, jint width, jint height) {
	wyNode* fnode = (wyNode*)env->GetIntField(node, g_fid_BaseObject_mPointer);
	wyRect rect = wyr(x, y, width, height);
	wyFollow* a = wyFollow::make(fnode, rect);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)a);
	a->retain();
	a->lazyRelease();
}
