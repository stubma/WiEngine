#ifndef __GridActionDemos_h__
#define __GridActionDemos_h__

#if ANDROID
	#include <jni.h>
#endif
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

DEMO_ENTRY(gridaction, SuckTest);
DEMO_ENTRY(gridaction, GridFlipXTest);
DEMO_ENTRY(gridaction, GridFlipYTest);
DEMO_ENTRY(gridaction, JumpTiles3DTest);
DEMO_ENTRY(gridaction, Lens3DTest);
DEMO_ENTRY(gridaction, LineShrinkOutTest);
DEMO_ENTRY(gridaction, LiquidTest);
DEMO_ENTRY(gridaction, PageTurn3DTest);
DEMO_ENTRY(gridaction, Ripple3DTest);
DEMO_ENTRY(gridaction, Shaky3DTest);
DEMO_ENTRY(gridaction, ShakyTiles3DTest);
DEMO_ENTRY(gridaction, ShatterTiles3DTest);
DEMO_ENTRY(gridaction, ShuffleTilesTest);
DEMO_ENTRY(gridaction, SplitRowsColsTest);
DEMO_ENTRY(gridaction, TilesShrinkOutTest);
DEMO_ENTRY(gridaction, TurnOffTilesTest);
DEMO_ENTRY(gridaction, TwirlTest);
DEMO_ENTRY(gridaction, Waves3DTest);
DEMO_ENTRY(gridaction, WavesTest);
DEMO_ENTRY(gridaction, WavesTiles3DTest);

#ifdef __cplusplus
}
#endif

#endif
