#ifndef __TransitionDemos_h__
#define __TransitionDemos_h__

#if ANDROID
	#include <jni.h>
#endif
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

DEMO_ENTRY(transition, ClipInOutTest);
DEMO_ENTRY(transition, ColorFadeTest);
DEMO_ENTRY(transition, CrossFadeTest);
DEMO_ENTRY(transition, FlipAngularTest);
DEMO_ENTRY(transition, FlipXTest);
DEMO_ENTRY(transition, FlipYTest);
DEMO_ENTRY(transition, JumpZoomTest);
DEMO_ENTRY(transition, LeftRightPushTest);
DEMO_ENTRY(transition, LeftRightSlideTest);
DEMO_ENTRY(transition, PageTurn3DTest);
DEMO_ENTRY(transition, RadialCWCCWTest);
DEMO_ENTRY(transition, RotateZoomTest);
DEMO_ENTRY(transition, ShrinkGrowTest);
DEMO_ENTRY(transition, ShrinkOutTilesTest);
DEMO_ENTRY(transition, SplitRowsColsTest);
DEMO_ENTRY(transition, SuckTest);
DEMO_ENTRY(transition, TopBottomPushTest);
DEMO_ENTRY(transition, TopBottomSlideTest);
DEMO_ENTRY(transition, TopBottomSlideBounceTest);
DEMO_ENTRY(transition, TurnOffTilesTest);
DEMO_ENTRY(transition, ZoomFlipAngularTest);
DEMO_ENTRY(transition, ZoomFlipXTest);
DEMO_ENTRY(transition, ZoomFlipYTest);

#ifdef __cplusplus
}
#endif

#endif
