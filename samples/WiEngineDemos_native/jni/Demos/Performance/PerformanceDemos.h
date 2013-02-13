#ifndef __PerformanceDemos_h__
#define __PerformanceDemos_h__

#if ANDROID
	#include <jni.h>
#endif
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

DEMO_ENTRY(performance, BatchRenderSpriteTest);
DEMO_ENTRY(performance, BigTMXTest);
DEMO_ENTRY(performance, RenderSpriteTest);
DEMO_ENTRY(performance, RunActionTest);
DEMO_ENTRY(performance, RunSkeletalAnimationTest);

#ifdef __cplusplus
}
#endif

#endif // __PerformanceDemos_h__
