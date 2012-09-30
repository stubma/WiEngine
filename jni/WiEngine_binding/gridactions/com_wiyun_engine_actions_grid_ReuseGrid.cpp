#include "com_wiyun_engine_actions_grid_ReuseGrid.h"
#include "wyReuseGrid.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_ReuseGrid_nativeInit
  (JNIEnv * env, jobject thiz, jint times) {
	wyReuseGrid* r = WYNEW wyReuseGrid(times);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)r);
	r->lazyRelease();
}
