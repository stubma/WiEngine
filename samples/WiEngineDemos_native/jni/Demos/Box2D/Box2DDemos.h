#ifndef __Box2DDemos_h__
#define __Box2DDemos_h__

#if ANDROID
	#include <jni.h>
#endif
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

DEMO_ENTRY(box2d, ApplyForceTest);
DEMO_ENTRY(box2d, BodyTypesTest);
DEMO_ENTRY(box2d, BounceTest);
DEMO_ENTRY(box2d, BreakableTest);
DEMO_ENTRY(box2d, BridgeTest);
DEMO_ENTRY(box2d, BulletTest);
DEMO_ENTRY(box2d, BuoyancyTest);
DEMO_ENTRY(box2d, CantileverTest);
DEMO_ENTRY(box2d, CarTest);
DEMO_ENTRY(box2d, ChainTest);
DEMO_ENTRY(box2d, ChainShapeTest);
DEMO_ENTRY(box2d, CollisionDetectionTest);
DEMO_ENTRY(box2d, CollisionFilteringTest);
DEMO_ENTRY(box2d, CompoundShapesTest);
DEMO_ENTRY(box2d, ConfinedTest);
DEMO_ENTRY(box2d, DominosTest);
DEMO_ENTRY(box2d, EdgeShapesTest);
DEMO_ENTRY(box2d, FixtureAnimationTest);
DEMO_ENTRY(box2d, GearsTest);
DEMO_ENTRY(box2d, OneWayTest);
DEMO_ENTRY(box2d, PulleysTest);
DEMO_ENTRY(box2d, PyramidTest);
DEMO_ENTRY(box2d, RopeTest);
DEMO_ENTRY(box2d, SensorTest);
DEMO_ENTRY(box2d, ShapeEditingTest);
DEMO_ENTRY(box2d, SliderCrankTest);
DEMO_ENTRY(box2d, SphereStackTest);
DEMO_ENTRY(box2d, TensorDampingTest);
DEMO_ENTRY(box2d, TexturedBounceTest);
DEMO_ENTRY(box2d, TexturedEdgeShapesTest);
DEMO_ENTRY(box2d, TexturedChainShapeTest);
DEMO_ENTRY(box2d, TexturedOneWayTest);
DEMO_ENTRY(box2d, VaryingFrictionTest);
DEMO_ENTRY(box2d, VaryingRestitutionTest);
DEMO_ENTRY(box2d, WebTest);
DEMO_ENTRY(box2d, SimpleTest);
DEMO_ENTRY(box2d, PhysicsEditorTest);

#ifdef __cplusplus
}
#endif

#endif
