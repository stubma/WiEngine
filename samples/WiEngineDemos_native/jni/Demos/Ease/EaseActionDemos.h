#ifndef __EaseActionDemos_h__
#define __EaseActionDemos_h__

#if ANDROID
	#include <jni.h>
#endif
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

DEMO_ENTRY(ease, EaseBackInOutTest);
DEMO_ENTRY(ease, EaseBackInTest);
DEMO_ENTRY(ease, EaseBackOutTest);
DEMO_ENTRY(ease, EaseBounceInOutTest);
DEMO_ENTRY(ease, EaseBounceInTest);
DEMO_ENTRY(ease, EaseBounceOutTest);
DEMO_ENTRY(ease, EaseElasticInOutTest);
DEMO_ENTRY(ease, EaseElasticInTest);
DEMO_ENTRY(ease, EaseElasticOutTest);
DEMO_ENTRY(ease, EaseExponentialInOutTest);
DEMO_ENTRY(ease, EaseExponentialInTest);
DEMO_ENTRY(ease, EaseExponentialOutTest);
DEMO_ENTRY(ease, EaseInOutTest);
DEMO_ENTRY(ease, EaseInTest);
DEMO_ENTRY(ease, EaseOutTest);
DEMO_ENTRY(ease, EaseSineInOutTest);
DEMO_ENTRY(ease, EaseSineInTest);
DEMO_ENTRY(ease, EaseSineOutTest);

#ifdef __cplusplus
}
#endif

#endif
