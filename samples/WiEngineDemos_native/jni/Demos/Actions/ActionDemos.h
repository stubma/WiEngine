#ifndef __ActionDemos_h__
#define __ActionDemos_h__

#if ANDROID
	#include <jni.h>
#endif
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

DEMO_ENTRY(action, AnimationTest);
DEMO_ENTRY(action, AtlasAnimationTest);
DEMO_ENTRY(action, BezierTest);
DEMO_ENTRY(action, BlinkTest);
DEMO_ENTRY(action, CallFuncTest);
DEMO_ENTRY(action, ClipInOutTest);
DEMO_ENTRY(action, DelayShowHideTest);
DEMO_ENTRY(action, FadeInOutTest);
DEMO_ENTRY(action, FadeToTest);
DEMO_ENTRY(action, FollowTest);
DEMO_ENTRY(action, HypotrochoidTest);
DEMO_ENTRY(action, JumpByTest);
DEMO_ENTRY(action, JumpToTest);
DEMO_ENTRY(action, LagrangeTest);
DEMO_ENTRY(action, MoveByTest);
DEMO_ENTRY(action, MoveByAngleTest);
DEMO_ENTRY(action, MoveByPathTest);
DEMO_ENTRY(action, MoveToTest);
DEMO_ENTRY(action, OrbitCameraFlipXTest);
DEMO_ENTRY(action, PauseResumeActionTest);
DEMO_ENTRY(action, ProgressByTest);
DEMO_ENTRY(action, ProgressToTest);
DEMO_ENTRY(action, RotateByTest);
DEMO_ENTRY(action, RotateToTest);
DEMO_ENTRY(action, ScaleByTest);
DEMO_ENTRY(action, ScaleToTest);
DEMO_ENTRY(action, ShakeTest);
DEMO_ENTRY(action, SkewByTest);
DEMO_ENTRY(action, SkewToTest);
DEMO_ENTRY(action, TintByTest);
DEMO_ENTRY(action, TintToTest);

#ifdef __cplusplus
}
#endif

#endif
