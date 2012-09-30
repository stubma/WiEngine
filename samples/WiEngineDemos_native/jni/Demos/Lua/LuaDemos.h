#ifndef __LuaDemos_h__
#define __LuaDemos_h__

#if ANDROID
	#include <jni.h>
#endif
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

DEMO_ENTRY(lua, CreateAnimationTest);
DEMO_ENTRY(lua, CreateButtonTest);
DEMO_ENTRY(lua, CreateLabelTest);
DEMO_ENTRY(lua, SplitWordsTest);

#ifdef __cplusplus
}
#endif

#endif // __LuaDemos_h__
