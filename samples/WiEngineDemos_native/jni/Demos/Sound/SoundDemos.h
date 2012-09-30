#ifndef __SoundDemos_h__
#define __SoundDemos_h__

#if ANDROID
	#include <jni.h>
#endif
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

DEMO_ENTRY(sound, MP3Test);
DEMO_ENTRY(sound, OGGTest);
DEMO_ENTRY(sound, WAVTest);

#ifdef __cplusplus
}
#endif

#endif
