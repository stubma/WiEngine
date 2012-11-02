/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#import <QuartzCore/QuartzCore.h>
#import "WiEngineViewController.h"
#import "WiEngine.h"
#import "ManifestXML.h"
#import "GLViewController.h"
#import "common.h"
#import "ActionDemos.h"
#import "Box2DDemos.h"
#import "EaseActionDemos.h"
#import "EventDemos.h"
#import "GridActionDemos.h"
#import "IAPDemos.h"
#import "LuaDemos.h"
#import "NetworkDemos.h"
#import "NodeDemos.h"
#import "OtherDemos.h"
#import "ParticleDemos.h"
#import "PerformanceDemos.h"
#import "PersistenceDemos.h"
#import "ShaderDemos.h"
#import "SoundDemos.h"
#import "TransitionDemos.h"

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
        DEMO_ENTRY_NAME(box2d, BodyAnimationTest),
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
		DEMO_ENTRY_NAME(event, AccelerometerTest),
		DEMO_ENTRY_NAME(event, CharacterMoveTest),
		DEMO_ENTRY_NAME(event, ClickAndMoveTest),
		DEMO_ENTRY_NAME(event, DoubleTapTest),
		DEMO_ENTRY_NAME(event, GestureTest),
		DEMO_ENTRY_NAME(event, MultiTouchTest),
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
        DEMO_ENTRY_NAME(iap, IAPTest),
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
		DEMO_ENTRY_NAME(other, PickFromAlbumTest),
		DEMO_ENTRY_NAME(other, PickFromCameraTest),
		DEMO_ENTRY_NAME(other, PixelOperationTest),
		DEMO_ENTRY_NAME(other, ResourceDecoderTest),
		DEMO_ENTRY_NAME(other, SchedulerTest),
		DEMO_ENTRY_NAME(other, ScreenshotTest),
		DEMO_ENTRY_NAME(other, TextureLoadUnloadTest),
		DEMO_ENTRY_NAME(other, VerletRopeTest),
		DEMO_ENTRY_NAME(other, VideoPlayingTest),
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

@implementation WiEngineViewController

- (void)dealloc {
	[ManifestXML destroy];
	[m_tableView release];
	[m_versionLabel release];
	[m_layout release];
	[super dealloc];
}

- (void)viewDidLoad {
	// load strings
    wyUtils::addAndroidStrings("strings-en.xml", "en");
    wyUtils::addAndroidStrings("strings-zh.xml", "zh");
	
	// load activities
	[ManifestXML sharedInstance];

	// set version label
	m_versionLabel.text = [[NSBundle mainBundle] objectForInfoDictionaryKey:(NSString*)kCFBundleVersionKey];

	// create table view cell layout helper
	m_layout = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:nil];
	m_layout.detailTextLabel.numberOfLines = 0;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation {
    return YES;
}

- (IBAction)onBackButtonClicked:(id)sender {
	if(m_category != nil) {
		m_category = nil;
		[m_tableView reloadSections:[NSIndexSet indexSetWithIndex:0] withRowAnimation:UITableViewRowAnimationRight];
	}
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	if(m_category == nil)
		return [[ManifestXML sharedInstance].categories count];
	else
		return [[[ManifestXML sharedInstance].demos objectForKey:m_category] count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"master_detail"];
	if(cell == nil) {
		cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"master_detail"];
		cell.detailTextLabel.numberOfLines = 0;
		[cell autorelease];
	}
	
	if(m_category == nil) {
		NSString* category = [[ManifestXML sharedInstance].categories objectAtIndex:indexPath.row];
		cell.textLabel.text = category;

        NSString* key = [NSString stringWithFormat:@"R.string.%@_desc", [[category lowercaseString] stringByReplacingOccurrencesOfString:@" " withString:@"_"]];
        const char* cKey = wyUtils::getString(RES([key UTF8String]));
        cell.detailTextLabel.text = [NSString stringWithUTF8String:cKey];
        
	} else {
		Activity* act = [[[ManifestXML sharedInstance].demos objectForKey:m_category] objectAtIndex:indexPath.row];
		cell.textLabel.text = act.name;

        NSString* key = [NSString stringWithFormat:@"R.string.%@", act.descKey];
        const char* cKey = wyUtils::getString(RES([key UTF8String]));
        cell.detailTextLabel.text = [NSString stringWithUTF8String:cKey];
	}
	
	return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
	if(m_category == nil) {
		NSString* category = [[ManifestXML sharedInstance].categories objectAtIndex:indexPath.row];
		m_layout.textLabel.text = category;
        
        NSString* key = [NSString stringWithFormat:@"R.string.%@_desc", [[category lowercaseString] stringByReplacingOccurrencesOfString:@" " withString:@"_"]];
        const char* cKey = wyUtils::getString(RES([key UTF8String]));
        m_layout.detailTextLabel.text = [NSString stringWithUTF8String:cKey];
        wyFree((void*)cKey);
	} else {
		Activity* act = [[[ManifestXML sharedInstance].demos objectForKey:m_category] objectAtIndex:indexPath.row];
		m_layout.textLabel.text = act.name;

        NSString* key = [NSString stringWithFormat:@"R.string.%@", act.descKey];
        const char* cKey = wyUtils::getString(RES([key UTF8String]));
        m_layout.detailTextLabel.text = [NSString stringWithUTF8String:cKey];
        wyFree((void*)cKey);
	}
	[m_layout layoutSubviews];
	return m_layout.textLabel.frame.size.height + m_layout.detailTextLabel.frame.size.height + 4;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	if(m_category == nil) {
		m_category = [[ManifestXML sharedInstance].categories objectAtIndex:indexPath.row];
		[tableView reloadSections:[NSIndexSet indexSetWithIndex:0] withRowAnimation:UITableViewRowAnimationLeft];
	} else {
		int categoryIndex = [[ManifestXML sharedInstance].categories indexOfObject:m_category];
		GLViewController* vc = [[GLViewController alloc] initWithDemoEntry:sDemoMap[categoryIndex][indexPath.row]];
		[self.navigationController pushViewController:vc animated:YES];
		[vc release];
	}
} 

@end
