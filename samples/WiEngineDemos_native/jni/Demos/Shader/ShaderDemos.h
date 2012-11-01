#ifndef __IAPDemos_h__
#define __IAPDemos_h__

#if ANDROID
	#include <jni.h>
#endif
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

DEMO_ENTRY(shader, AlphaTestTest);

#ifdef __cplusplus
}
#endif

#endif // __IAPDemos_h__
