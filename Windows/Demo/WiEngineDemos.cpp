// WiEngineDemos.cpp : 定义 DLL 应用程序的导出函数。
//
#include <Windows.h>
#include "WiEngineDemos.h"
#include "WiEngine.h"
#include "WiEngineApp.h"
#include "common.h"
#include "Actions/ActionDemos.h"
#include "Box2D/Box2DDemos.h"
#include "Ease/EaseActionDemos.h"
#include "Events/EventDemos.h"
#include "GridActions/GridActionDemos.h"
#include "Network/NetworkDemos.h"
#include "Nodes/NodeDemos.h"
#include "Lua/LuaDemos.h"
#include "Others/OtherDemos.h"
#include "Particles/ParticleDemos.h"
#include "Performance/PerformanceDemos.h"
#include "Persistence/PersistenceDemos.h"
#include "Shader/ShaderDemos.h"
#include "Sound/SoundDemos.h"
#include "Transition/TransitionDemos.h"

/// demo entry for not implemented feature
static void demo_notImplemented() {
	wyScene* scene = wyScene::make();
    
	wyLabel* label = wyLabel::make("This demo is not available on Windows", SP(12), BOLD, WY_DEFAULT_FONT);
	label->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
	scene->addChildLocked(label);
	
	wyDirector::getInstance()->runWithScene(scene);
}

/// not implemented macro
#define NOT_IMPL(entry) demo_notImplemented

// demo map
static demoEntryFunc sDemoMap[16][50] = {
	{
		DEMO_ENTRY_NAME(action, AnimationTest),
		DEMO_ENTRY_NAME(action, AtlasAnimationTest),
		DEMO_ENTRY_NAME(action, BezierTest),
		DEMO_ENTRY_NAME(action, BlinkTest),
		DEMO_ENTRY_NAME(action, CallFuncTest),
		DEMO_ENTRY_NAME(action, ClipInOutTest),
		DEMO_ENTRY_NAME(action, DelayShowHideTest),
		DEMO_ENTRY_NAME(action, FadeInOutTest),
		DEMO_ENTRY_NAME(action, FadeToTest),
        DEMO_ENTRY_NAME(action, FollowTest),
        DEMO_ENTRY_NAME(action, HypotrochoidTest),
		DEMO_ENTRY_NAME(action, JumpByTest),
		DEMO_ENTRY_NAME(action, JumpToTest),
		DEMO_ENTRY_NAME(action, LagrangeTest),
		DEMO_ENTRY_NAME(action, MoveByTest),
		DEMO_ENTRY_NAME(action, MoveByAngleTest),
		DEMO_ENTRY_NAME(action, MoveByPathTest),
		DEMO_ENTRY_NAME(action, MoveToTest),
		DEMO_ENTRY_NAME(action, OrbitCameraFlipXTest),
		DEMO_ENTRY_NAME(action, PauseResumeActionTest),
		DEMO_ENTRY_NAME(action, ProgressByTest),
		DEMO_ENTRY_NAME(action, ProgressToTest),
		DEMO_ENTRY_NAME(action, RotateByTest),
		DEMO_ENTRY_NAME(action, RotateToTest),
		DEMO_ENTRY_NAME(action, ScaleByTest),
		DEMO_ENTRY_NAME(action, ScaleToTest),
		DEMO_ENTRY_NAME(action, ShakeTest),
		DEMO_ENTRY_NAME(action, SkewByTest),
		DEMO_ENTRY_NAME(action, SkewToTest),
		DEMO_ENTRY_NAME(action, TintByTest),
		DEMO_ENTRY_NAME(action, TintToTest),
	},
	{
		DEMO_ENTRY_NAME(box2d, ApplyForceTest),
		DEMO_ENTRY_NAME(box2d, BodyTypesTest),
		DEMO_ENTRY_NAME(box2d, BounceTest),
		DEMO_ENTRY_NAME(box2d, BreakableTest),
		DEMO_ENTRY_NAME(box2d, BridgeTest),
		DEMO_ENTRY_NAME(box2d, BulletTest),
        DEMO_ENTRY_NAME(box2d, BuoyancyTest),
		DEMO_ENTRY_NAME(box2d, CantileverTest),
        DEMO_ENTRY_NAME(box2d, CarTest),
		DEMO_ENTRY_NAME(box2d, ChainTest),
		DEMO_ENTRY_NAME(box2d, ChainShapeTest),
		DEMO_ENTRY_NAME(box2d, CollisionDetectionTest),
		DEMO_ENTRY_NAME(box2d, CollisionFilteringTest),
		DEMO_ENTRY_NAME(box2d, CompoundShapesTest),
		DEMO_ENTRY_NAME(box2d, ConfinedTest),
		DEMO_ENTRY_NAME(box2d, DominosTest),
		DEMO_ENTRY_NAME(box2d, EdgeShapesTest),
		DEMO_ENTRY_NAME(box2d, GearsTest),
		DEMO_ENTRY_NAME(box2d, OneWayTest),
        DEMO_ENTRY_NAME(box2d, PhysicsEditorTest),
		DEMO_ENTRY_NAME(box2d, PulleysTest),
		DEMO_ENTRY_NAME(box2d, PyramidTest),
		DEMO_ENTRY_NAME(box2d, RopeTest),
		DEMO_ENTRY_NAME(box2d, SensorTest),
		DEMO_ENTRY_NAME(box2d, ShapeEditingTest),
		DEMO_ENTRY_NAME(box2d, SimpleTest),
		DEMO_ENTRY_NAME(box2d, SliderCrankTest),
		DEMO_ENTRY_NAME(box2d, SphereStackTest),
		DEMO_ENTRY_NAME(box2d, TensorDampingTest),
		DEMO_ENTRY_NAME(box2d, TexturedBounceTest),
		DEMO_ENTRY_NAME(box2d, TexturedChainShapeTest),
		DEMO_ENTRY_NAME(box2d, TexturedEdgeShapesTest),
		DEMO_ENTRY_NAME(box2d, TexturedOneWayTest),
		DEMO_ENTRY_NAME(box2d, VaryingFrictionTest),
		DEMO_ENTRY_NAME(box2d, VaryingRestitutionTest),
		DEMO_ENTRY_NAME(box2d, WebTest),
	},
	{
		DEMO_ENTRY_NAME(ease, EaseBackInOutTest),
		DEMO_ENTRY_NAME(ease, EaseBackInTest),
		DEMO_ENTRY_NAME(ease, EaseBackOutTest),
		DEMO_ENTRY_NAME(ease, EaseBounceInOutTest),
		DEMO_ENTRY_NAME(ease, EaseBounceInTest),
		DEMO_ENTRY_NAME(ease, EaseBounceOutTest),
		DEMO_ENTRY_NAME(ease, EaseElasticInOutTest),
		DEMO_ENTRY_NAME(ease, EaseElasticInTest),
		DEMO_ENTRY_NAME(ease, EaseElasticOutTest),
		DEMO_ENTRY_NAME(ease, EaseExponentialInOutTest),
		DEMO_ENTRY_NAME(ease, EaseExponentialInTest),
		DEMO_ENTRY_NAME(ease, EaseExponentialOutTest),
		DEMO_ENTRY_NAME(ease, EaseInOutTest),
		DEMO_ENTRY_NAME(ease, EaseInTest),
		DEMO_ENTRY_NAME(ease, EaseOutTest),
		DEMO_ENTRY_NAME(ease, EaseSineInOutTest),
		DEMO_ENTRY_NAME(ease, EaseSineInTest),
		DEMO_ENTRY_NAME(ease, EaseSineOutTest),
	},
	{
		NOT_IMPL(DEMO_ENTRY_NAME(event, AccelerometerTest)),
		DEMO_ENTRY_NAME(event, CharacterMoveTest),
		DEMO_ENTRY_NAME(event, ClickAndMoveTest),
		DEMO_ENTRY_NAME(event, DoubleTapTest),
		DEMO_ENTRY_NAME(event, GestureTest),
		DEMO_ENTRY_NAME(event, KeyTest),
		NOT_IMPL(DEMO_ENTRY_NAME(event, MultiTouchTest)),
		DEMO_ENTRY_NAME(event, CustomBackTest),
	},
	{
		DEMO_ENTRY_NAME(gridaction, GridFlipXTest),
		DEMO_ENTRY_NAME(gridaction, GridFlipYTest),
		DEMO_ENTRY_NAME(gridaction, JumpTiles3DTest),
		DEMO_ENTRY_NAME(gridaction, Lens3DTest),
		DEMO_ENTRY_NAME(gridaction, LineShrinkOutTest),
		DEMO_ENTRY_NAME(gridaction, LiquidTest),
		DEMO_ENTRY_NAME(gridaction, PageTurn3DTest),
		DEMO_ENTRY_NAME(gridaction, Ripple3DTest),
		DEMO_ENTRY_NAME(gridaction, Shaky3DTest),
		DEMO_ENTRY_NAME(gridaction, ShakyTiles3DTest),
		DEMO_ENTRY_NAME(gridaction, ShatterTiles3DTest),
		DEMO_ENTRY_NAME(gridaction, ShuffleTilesTest),
		DEMO_ENTRY_NAME(gridaction, SplitRowsColsTest),
		DEMO_ENTRY_NAME(gridaction, SuckTest),
		DEMO_ENTRY_NAME(gridaction, TilesShrinkOutTest),
		DEMO_ENTRY_NAME(gridaction, TurnOffTilesTest),
		DEMO_ENTRY_NAME(gridaction, TwirlTest),
		DEMO_ENTRY_NAME(gridaction, Waves3DTest),
		DEMO_ENTRY_NAME(gridaction, WavesTest),
		DEMO_ENTRY_NAME(gridaction, WavesTiles3DTest),
	},
    {
        NOT_IMPL(DEMO_ENTRY_NAME(iap, IAPTest)),
    },
	{
		DEMO_ENTRY_NAME(lua, CreateAnimationTest),
		DEMO_ENTRY_NAME(lua, CreateButtonTest),
		DEMO_ENTRY_NAME(lua, CreateLabelTest),
		DEMO_ENTRY_NAME(lua, SplitWordsTest),
	},
	{
		DEMO_ENTRY_NAME(network, DownloadImageTest),
		DEMO_ENTRY_NAME(network, HttpPostTest),
        DEMO_ENTRY_NAME(network, IPQueryTest),
	},
	{
		DEMO_ENTRY_NAME(node, ArcticTest),
		DEMO_ENTRY_NAME(node, ArrayTileMapAtlasTest),
		DEMO_ENTRY_NAME(node, AtlasButtonTest),
		DEMO_ENTRY_NAME(node, AtlasLabelTest),
		DEMO_ENTRY_NAME(node, AtlasSpriteTest),
		DEMO_ENTRY_NAME(node, AuroraGTTest),
		DEMO_ENTRY_NAME(node, BitmapFontAngelCodeTest),
		DEMO_ENTRY_NAME(node, BitmapFontHGETest),
		DEMO_ENTRY_NAME(node, ButtonTest),
		DEMO_ENTRY_NAME(node, ClipMappingAuroraGTTest),
		DEMO_ENTRY_NAME(node, CoverFlowTest),
		DEMO_ENTRY_NAME(node, DialogTest),
		DEMO_ENTRY_NAME(node, GradientColorLayerTest),
		DEMO_ENTRY_NAME(node, ImageSpriteTest),
		DEMO_ENTRY_NAME(node, LabelTest),
		DEMO_ENTRY_NAME(node, MenuTest),
		DEMO_ENTRY_NAME(node, MotionStreakTest),
		DEMO_ENTRY_NAME(node, MotionWelderTest),
		DEMO_ENTRY_NAME(node, MultiplexLayerTest),
		DEMO_ENTRY_NAME(node, NinePatchButtonTest),
		DEMO_ENTRY_NAME(node, PageControlTest),
		DEMO_ENTRY_NAME(node, ParallaxTest),
		DEMO_ENTRY_NAME(node, ProgressTimerTest),
		DEMO_ENTRY_NAME(node, PVRSpriteTest),
		DEMO_ENTRY_NAME(node, RenderTextureTest),
		DEMO_ENTRY_NAME(node, SceneTest),
		DEMO_ENTRY_NAME(node, ScrollableLayerTest),
		DEMO_ENTRY_NAME(node, SliderTest),
		DEMO_ENTRY_NAME(node, SpriteExBatchNodeTest),
		DEMO_ENTRY_NAME(node, SpriteExSelfRenderTest),
		DEMO_ENTRY_NAME(node, SpriteX2011Test),
		DEMO_ENTRY_NAME(node, SpriteXTest),
		DEMO_ENTRY_NAME(node, TextBoxTest),
		DEMO_ENTRY_NAME(node, TGATileMapAtlasTest),
		DEMO_ENTRY_NAME(node, TiledSpriteTest),
		DEMO_ENTRY_NAME(node, TMXHexagonalTest),
		DEMO_ENTRY_NAME(node, TMXIsometricTest),
		DEMO_ENTRY_NAME(node, TMXOrthogonalTest),
		DEMO_ENTRY_NAME(node, ToastTest),
		DEMO_ENTRY_NAME(node, VirtualJoystickTest),
	},
	{
		DEMO_ENTRY_NAME(other, AStarTest),
		DEMO_ENTRY_NAME(other, ColorFilterTest),
		DEMO_ENTRY_NAME(other, DrawPrimitivesTest),
		DEMO_ENTRY_NAME(other, JsonParseTest),
		DEMO_ENTRY_NAME(other, MemoryFileSystemTest),
		DEMO_ENTRY_NAME(other, NodePhysicsTest),
		DEMO_ENTRY_NAME(other, PauseResumeGameTest),
		NOT_IMPL(DEMO_ENTRY_NAME(other, PickFromAlbumTest)),
		NOT_IMPL(DEMO_ENTRY_NAME(other, PickFromCameraTest)),
		DEMO_ENTRY_NAME(other, PixelOperationTest),
		DEMO_ENTRY_NAME(other, ResourceDecoderTest),
		DEMO_ENTRY_NAME(other, SchedulerTest),
		DEMO_ENTRY_NAME(other, ScreenshotTest),
		DEMO_ENTRY_NAME(other, TextureLoadUnloadTest),
		NOT_IMPL(DEMO_ENTRY_NAME(other, TransparentDrawPrimitivesTest)),
		DEMO_ENTRY_NAME(other, VerletRopeTest),
		NOT_IMPL(DEMO_ENTRY_NAME(other, VideoPlayingTest)),
		DEMO_ENTRY_NAME(other, ZwoptexTest),
	},
	{
		DEMO_ENTRY_NAME(particle, BigFlowerTest),
		DEMO_ENTRY_NAME(particle, ExplosionTest),
		DEMO_ENTRY_NAME(particle, FireTest),
		DEMO_ENTRY_NAME(particle, FireworkTest),
		DEMO_ENTRY_NAME(particle, FlowerTest),
		DEMO_ENTRY_NAME(particle, GalaxyTest),
		DEMO_ENTRY_NAME(particle, HGETest),
		DEMO_ENTRY_NAME(particle, MeteorTest),
		DEMO_ENTRY_NAME(particle, ModernArtTest),
		DEMO_ENTRY_NAME(particle, ParticleDesignerTest),
		DEMO_ENTRY_NAME(particle, RainTest),
		DEMO_ENTRY_NAME(particle, RingTest),
		DEMO_ENTRY_NAME(particle, RotateFlowerTest),
		DEMO_ENTRY_NAME(particle, SmokeTest),
		DEMO_ENTRY_NAME(particle, SnowTest),
		DEMO_ENTRY_NAME(particle, SpiralTest),
		DEMO_ENTRY_NAME(particle, SunTest),
	},
	{
		DEMO_ENTRY_NAME(performance, BatchRenderSpriteTest),
		DEMO_ENTRY_NAME(performance, BigTMXTest),
		DEMO_ENTRY_NAME(performance, RenderSpriteTest),
		DEMO_ENTRY_NAME(performance, RunActionTest),
	},
	{
		DEMO_ENTRY_NAME(persistence, CreateDatabaseTest),
		DEMO_ENTRY_NAME(persistence, PreferenceTest),
		DEMO_ENTRY_NAME(persistence, SQLFileTest),
		DEMO_ENTRY_NAME(persistence, TransactionTest),
	},
	{
		DEMO_ENTRY_NAME(shader, AlphaTestTest),
	},
	{
		DEMO_ENTRY_NAME(sound, MP3Test),
		DEMO_ENTRY_NAME(sound, OGGTest),
		DEMO_ENTRY_NAME(sound, WAVTest),
	},
	{
		DEMO_ENTRY_NAME(transition, ClipInOutTest),
		DEMO_ENTRY_NAME(transition, ColorFadeTest),
		DEMO_ENTRY_NAME(transition, CrossFadeTest),
		DEMO_ENTRY_NAME(transition, FlipAngularTest),
		DEMO_ENTRY_NAME(transition, FlipXTest),
		DEMO_ENTRY_NAME(transition, FlipYTest),
		DEMO_ENTRY_NAME(transition, JumpZoomTest),
		DEMO_ENTRY_NAME(transition, LeftRightPushTest),
		DEMO_ENTRY_NAME(transition, LeftRightSlideTest),
		DEMO_ENTRY_NAME(transition, PageTurn3DTest),
		DEMO_ENTRY_NAME(transition, RadialCWCCWTest),
		DEMO_ENTRY_NAME(transition, RotateZoomTest),
		DEMO_ENTRY_NAME(transition, ShrinkGrowTest),
		DEMO_ENTRY_NAME(transition, ShrinkOutTilesTest),
		DEMO_ENTRY_NAME(transition, SplitRowsColsTest),
		DEMO_ENTRY_NAME(transition, SuckTest),
		DEMO_ENTRY_NAME(transition, TopBottomPushTest),
		DEMO_ENTRY_NAME(transition, TopBottomSlideTest),
		DEMO_ENTRY_NAME(transition, TopBottomSlideBounceTest),
		DEMO_ENTRY_NAME(transition, TurnOffTilesTest),
		DEMO_ENTRY_NAME(transition, ZoomFlipAngularTest),
		DEMO_ENTRY_NAME(transition, ZoomFlipXTest),
		DEMO_ENTRY_NAME(transition, ZoomFlipYTest),
	}
};

void startDemo(int clazz, int id) {
	wyUtils::addAndroidStrings(".\\values\\strings-en.xml", "en");
	wyUtils::addAndroidStrings(".\\values\\strings-zh.xml", "zh");

	WiEngineApp* app = new WiEngineApp();
	app->setTitle("WiEngine Demo");
	app->runWithEntry(sDemoMap[clazz][id]);
	delete app;
}