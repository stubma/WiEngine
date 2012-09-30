#ifndef __EventDemos_h__
#define __EventDemos_h__

#if ANDROID
	#include <jni.h>
#endif
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

DEMO_ENTRY(event, AccelerometerTest);
DEMO_ENTRY(event, CharacterMoveTest);
DEMO_ENTRY(event, ClickAndMoveTest);
DEMO_ENTRY(event, CustomBackTest);
DEMO_ENTRY(event, DoubleTapTest);
DEMO_ENTRY(event, GestureTest);
DEMO_ENTRY(event, KeyTest);
DEMO_ENTRY(event, MultiTouchTest);
	
#ifdef __cplusplus
}
#endif

#endif
