#ifndef __OtherDemos_h__
#define __OtherDemos_h__

#if ANDROID
	#include <jni.h>
#endif
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

DEMO_ENTRY(other, AlphaTestTest);
DEMO_ENTRY(other, AStarTest);
DEMO_ENTRY(other, ColorFilterTest);
DEMO_ENTRY(other, DrawPrimitivesTest);
DEMO_ENTRY(other, JsonParseTest);
DEMO_ENTRY(other, MemoryFileSystemTest);
DEMO_ENTRY(other, NodePhysicsTest);
DEMO_ENTRY(other, PauseResumeGameTest);
DEMO_ENTRY(other, PickFromAlbumTest);
DEMO_ENTRY(other, PickFromCameraTest);
DEMO_ENTRY(other, PixelOperationTest);
DEMO_ENTRY(other, ResourceDecoderTest);
DEMO_ENTRY(other, TextureAtlasTest);
DEMO_ENTRY(other, TextureLoadUnloadTest);
#if ANDROID
	DEMO_ENTRY(other, TransparentDrawPrimitivesTest);
#endif
DEMO_ENTRY(other, SchedulerTest);
DEMO_ENTRY(other, ScreenshotTest);
DEMO_ENTRY(other, VerletRopeTest);
DEMO_ENTRY(other, VideoPlayingTest);
DEMO_ENTRY(other, ZwoptexTest);

#ifdef __cplusplus
}
#endif

#endif
