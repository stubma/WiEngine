#include "com_wiyun_engine_actions_grid_StopGrid.h"
#include "wyStopGrid.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_StopGrid_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyStopGrid* s = WYNEW wyStopGrid();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)s);
	s->lazyRelease();
}
