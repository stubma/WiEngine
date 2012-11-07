#include "com_wiyun_engine_livewallpaper_WiEngineLiveWallpaperService_SnowEngine.h"
#include "FirstScene.h"
#include "WiEngine.h"

JNIEXPORT void JNICALL Java_com_wiyun_engine_livewallpaper_WiEngineLiveWallpaperService_00024SnowEngine_nativeStart
  (JNIEnv * env, jobject thiz) {
	wyDirector* d = wyDirector::getInstance();
	FirstScene* s = new FirstScene();
	d->runWithScene(s);
	s->release();
}
