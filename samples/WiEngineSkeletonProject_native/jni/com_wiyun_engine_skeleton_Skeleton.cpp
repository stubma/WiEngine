#include "com_wiyun_engine_skeleton_Skeleton.h"
#include "WiEngine.h"
#include "FirstScene.h"

extern jmethodID g_mid_Activity_getRequestedOrientation;
extern int g_enum_ActivityInfo_SCREEN_ORIENTATION_LANDSCAPE;

// is already started?
static bool s_started = false;

static void onSurfaceChanged(int w, int h, void* data) {
	/*
	 * 避免一些屏幕尺寸问题. 因为一开始WiEngine并不知道
	 * SurfaceView的尺寸, 所以是假设为全屏大小. 在之后的onSurfaceChanged事件中,
	 * 正确的大小会被设置. 但是往往在onSurfaceChanged之前, 场景就已经被创建了,
	 * 所以如果因为某种原因不是全屏大小, 那么之前创建的场景位置就有误了.
	 *
	 * 由于onSurfaceChanged有可能被调用多次, 用一个标志来防止多次运行. 而且这可能
	 * 还不够, 有些情况下onSurfaceChanged可能连续被调用两次, 第一次传入的尺寸不对,
	 * 而第二次是对的. 这种情况下, 还需要做更多的检查, 可以通过尺寸大小和屏幕朝向来检查.
	 * 比如游戏如果是横屏的, 则w必须要大于h才认为是可以的, 反之则必须要h大于w才可以.
	 */

	// is landscape
	wyDirector* director = wyDirector::getInstance();
	JNIEnv* env = wyUtils::getJNIEnv();
	wyGLContext act = director->getContext();
	bool landscape = env->CallIntMethod(act, g_mid_Activity_getRequestedOrientation) == g_enum_ActivityInfo_SCREEN_ORIENTATION_LANDSCAPE;

	// check
	if(!s_started && (landscape && w >= h || !landscape && h >= w)) {
		s_started = true;

		FirstScene* scene = new FirstScene();
		director->runWithScene(scene);
		scene->release();
	}
}

// life cycle listener
static const wyDirectorLifecycleListener s_surfaceLifeCycleListener = {
	NULL,
	onSurfaceChanged,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

JNIEXPORT void JNICALL Java_com_wiyun_engine_skeleton_Skeleton_nativeStart
  (JNIEnv * env, jobject thiz) {
	wyDirector* director = wyDirector::getInstance();
	director->setShowFPS(true);

	// clear flag
	s_started = false;

	/*
	 * You should uncomment following code if you want to
	 * use base size adaption mode. To know what is base size
	 * adaption mode, view WiYun blog: http://blog.wiyun.com/?p=949
 	 */
//  director->setScaleMode(SCALE_MODE_BASE_SIZE_FIT_XY);
//  director->setBaseSize(480, 800);

	// add life cycle listener
	director->addLifecycleListener(&s_surfaceLifeCycleListener, NULL);
}

