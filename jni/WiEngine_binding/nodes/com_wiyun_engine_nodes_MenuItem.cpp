#include "com_wiyun_engine_nodes_MenuItem.h"
#include "wyMenuItem.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_MenuItem_getClickScale
(JNIEnv * env, jobject thiz) {
	wyMenuItem* item = (wyMenuItem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return item->getClickScale();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItem_setClickScale
(JNIEnv * env, jobject thiz, jfloat clickScale) {
	wyMenuItem* item = (wyMenuItem*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	item->setClickScale(clickScale);
}
