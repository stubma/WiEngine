#ifndef __wyLog_h__
#define __wyLog_h__

#if ANDROID
	#include <android/log.h>
#elif IOS || MACOSX
	#import <Foundation/Foundation.h>
#endif

#if ANDROID
	#undef LOG_TAG
	#undef LOGD
	#undef LOGW
	#undef LOGE
	#define LOG_TAG "libwiengine"
	#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
	#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
	#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#elif IOS || MACOSX
	#define LOGD(fmt, ...) NSLog(@fmt, ##__VA_ARGS__)
	#define LOGW(fmt, ...) NSLog(@fmt, ##__VA_ARGS__)
	#define LOGE(fmt, ...) NSLog(@fmt, ##__VA_ARGS__)
#elif WINDOWS
	extern "C" void __win_log_print(const char format[], ...);
	#define LOGD(fmt, ...) __win_log_print(fmt, __VA_ARGS__)
	#define LOGW(fmt, ...) __win_log_print(fmt, __VA_ARGS__)
	#define LOGE(fmt, ...) __win_log_print(fmt, __VA_ARGS__)
#endif

#endif // __wyLog_h__
