#ifndef __ParticleDemos_h__
#define __ParticleDemos_h__

#ifdef __cplusplus
extern "C" {
#endif

#if ANDROID
	#include <jni.h>
#endif
#include "common.h"

DEMO_ENTRY(particle, BigFlowerTest);
DEMO_ENTRY(particle, ExplosionTest);
DEMO_ENTRY(particle, FireTest);
DEMO_ENTRY(particle, FireworkTest);
DEMO_ENTRY(particle, FlowerTest);
DEMO_ENTRY(particle, GalaxyTest);
DEMO_ENTRY(particle, HGETest);
DEMO_ENTRY(particle, MeteorTest);
DEMO_ENTRY(particle, ModernArtTest);
DEMO_ENTRY(particle, ParticleDesignerTest);
DEMO_ENTRY(particle, RainTest);
DEMO_ENTRY(particle, RingTest);
DEMO_ENTRY(particle, RotateFlowerTest);
DEMO_ENTRY(particle, SmokeTest);
DEMO_ENTRY(particle, SnowTest);
DEMO_ENTRY(particle, SpiralTest);
DEMO_ENTRY(particle, SunTest);

#ifdef __cplusplus
}
#endif

#endif
