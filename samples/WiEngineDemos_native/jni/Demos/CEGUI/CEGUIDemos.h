#ifndef __CEGUIDemos_h__
#define __CEGUIDemos_h__

#if ANDROID
	#include <jni.h>
#endif
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

DEMO_ENTRY(cegui, ControlSetTest);
DEMO_ENTRY(cegui, FontTest);
DEMO_ENTRY(cegui, ScrollablePaneTest);
DEMO_ENTRY(cegui, TabControlTest);
DEMO_ENTRY(cegui, TreeTest);
DEMO_ENTRY(cegui, WindowTest);

#ifdef __cplusplus
}
#endif

#endif // __CEGUIDemos_h__
