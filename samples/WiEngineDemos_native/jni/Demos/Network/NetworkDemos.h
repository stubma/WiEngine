#ifndef __NetworkDemos_h__
#define __NetworkDemos_h__

#if ANDROID
	#include <jni.h>
#endif
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

DEMO_ENTRY(network, DownloadImageTest);
DEMO_ENTRY(network, HttpPostTest);
DEMO_ENTRY(network, IPQueryTest);

#ifdef __cplusplus
}
#endif

#endif // __NetworkDemos_h__
