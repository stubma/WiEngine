#ifndef __ChipmunkDemos_h__
#define __ChipmunkDemos_h__

#if ANDROID
	#include <jni.h>
#endif
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

DEMO_ENTRY(chipmunk, BodyDraggingTest);
DEMO_ENTRY(chipmunk, BounceTest);
DEMO_ENTRY(chipmunk, JointsTest);
DEMO_ENTRY(chipmunk, LogoSmashTest);
DEMO_ENTRY(chipmunk, MagnetsElectricTest);
DEMO_ENTRY(chipmunk, OneWayTest);
DEMO_ENTRY(chipmunk, PlanetTest);
DEMO_ENTRY(chipmunk, PlayerTest);
DEMO_ENTRY(chipmunk, PlinkTest);
DEMO_ENTRY(chipmunk, PumpTest);
DEMO_ENTRY(chipmunk, PyramidStackTest);
DEMO_ENTRY(chipmunk, PyramidToppleTest);
DEMO_ENTRY(chipmunk, QueryTest);
DEMO_ENTRY(chipmunk, SensorTest);
DEMO_ENTRY(chipmunk, ShapeAnimationTest);
DEMO_ENTRY(chipmunk, SimpleTest);
DEMO_ENTRY(chipmunk, SpringTest);
DEMO_ENTRY(chipmunk, TankTest);
DEMO_ENTRY(chipmunk, TexturedBounceTest);
DEMO_ENTRY(chipmunk, TexturedOneWayTest);
DEMO_ENTRY(chipmunk, TheoJansenTest);
DEMO_ENTRY(chipmunk, TumbleTest);
DEMO_ENTRY(chipmunk, UnsafeOpsTest);
DEMO_ENTRY(chipmunk, PhysicsEditorTest);

#ifdef __cplusplus
}
#endif

#endif
