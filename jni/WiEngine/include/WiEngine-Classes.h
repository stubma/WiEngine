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
#ifndef __WiEngine_Classes_h__
#define __WiEngine_Classes_h__

/*
 * Pre-declaration of all classes of WiEngine
 */

// actions
class wyAction;
class wyAnimate;
class wyBezier;
class wyBlink;
class wyCallFunc;
class wyCameraAction;
class wyClipIn;
class wyClipOut;
class wyCoverFlowAction;
class wyDelayTime;
class wyFadeIn;
class wyFadeOut;
class wyFadeTo;
class wyFiniteTimeAction;
class wyFollow;
class wyHide;
class wyHypotrochoid;
class wyInstantAction;
class wyIntervalAction;
class wyJumpBy;
class wyJumpTo;
class wyLagrange;
class wyMoveBy;
class wyMoveByAngle;
class wyMoveByPath;
class wyMoveTo;
class wyOrbitCamera;
class wyPlace;
class wyProgressBy;
class wyProgressTo;
class wyRepeat;
class wyRepeatForever;
class wyReverseTime;
class wyRotateBy;
class wyRotateTo;
class wyScaleBy;
class wyScaleTo;
class wySequence;
class wyShake;
class wyShow;
class wySkewBy;
class wySkewTo;
class wySpawn;
class wySpeed;
class wyTintBy;
class wyTintTo;
class wyToggleVisibility;

// afc animations
class wyAFCAnimation;
class wyAFCClip;
class wyAFCClipMapping;
class wyAFCFileData;
class wyAFCFrame;
class wyAFCSprite;
class wyArcticFileData;
class wyArcticLoader;
class wyArcticManager;
class wyArcticSprite;
class wyAuroraFileData;
class wyAuroraLoader;
class wyAuroraManager;
class wyAuroraSprite;
class wyMWFileData;
class wyMWLoader;
class wyMWManager;
class wyMWSprite;
class wySPX3Action;
class wySPX3FileData;
class wySPX3Frame;
class wySPX3Loader;
class wySPX3Manager;
class wySPX3Sprite;
class wySPXAction;
class wySPXFileData;
class wySPXFrame;
class wySPXLoader;
class wySPXManager;
class wySPXSprite;

// astar
class wyAStar;
class wyAStarMap;
class wyAStarStep;
class wyAStarTile;
class wyHexagonAStarMap;
class wyRectAStarMap;

// bitmap font
class wyAngelCodeTXTFontLoader;
class wyAngelCodeXMLFontLoader;
class wyBitmapFont;
class wyBitmapFontLabel;
class wyHGEFontLoader;

// common
struct wyArray;
class wyAutoReleasePool;
struct wyHashSet;
class wyObject;
class wyThread;

// dialog
class wyDialog;
class wyDialogPopupTransition;
class wyDialogTransition;

// ease actions
class wyEaseAction;
class wyEaseBackIn;
class wyEaseBackInOut;
class wyEaseBackOut;
class wyEaseBounce;
class wyEaseBounceIn;
class wyEaseBounceInOut;
class wyEaseBounceOut;
class wyEaseElastic;
class wyEaseElasticIn;
class wyEaseElasticInOut;
class wyEaseElasticOut;
class wyEaseExponentialIn;
class wyEaseExponentialInOut;
class wyEaseExponentialOut;
class wyEaseIn;
class wyEaseInOut;
class wyEaseOut;
class wyEaseRateAction;
class wyEaseSineIn;
class wyEaseSineInOut;
class wyEaseSineOut;

// events
class wyEventDispatcher;
struct wyKeyEvent;
struct wyMotionEvent;
struct wyEvent;

// filters
class wyAreaColorFilter;
class wyBlurColorFilter;
class wyColorFilter;
class wyColorMatrix;
class wyColorMatrixColorFilter;
class wyCombineColorFilter;
class wyCustomColorFilter;
class wyDropShadowColorFilter;
class wyEmbossColorFilter;
class wyGlowColorFilter;
class wyLightingColorFilter;
class wyMappingColorFilter;

// grid
class wyGridController;

// grid actions
class wyBottomLineShrinkOut;
class wyBottomTilesShrinkOut;
class wyGrid3DAction;
class wyGridAction;
class wyGridFlipX;
class wyGridFlipY;
class wyJumpTiles3D;
class wyLeftBottomTilesShrinkOut;
class wyLeftLineShrinkOut;
class wyLens3D;
class wyLiquid;
class wyPageTurn3D;
class wyReuseGrid;
class wyRightLineShrinkOut;
class wyRightTopTilesShrinkOut;
class wyRipple3D;
class wyShaky3D;
class wyShakyTiles3D;
class wyShatteredTiles3D;
class wyShuffleTiles;
class wySplitCols;
class wySplitRows;
class wyStopGrid;
class wySuck;
class wyTiledGrid3DAction;
class wyTopLineShrinkOut;
class wyTopTilesShrinkOut;
class wyTurnOffTiles;
class wyTwirl;
class wyWaves;
class wyWaves3D;
class wyWavesTiles3D;

// material
class wyMaterial;
class wyMaterialParameter;
class wyMaterialTextureParameter;
class wyRenderState;
class wyTechnique;

// mesh
class wyProgress;
class wyBaseGrid;
class wyGrid3D;
class wyMesh;
class wyMeshRef;
class wyQuadList;
class wyRectangle;
class wyShape;
class wyTiledGrid3D;

// nodes
class wyActionManager;
class wyAnimation;
class wyArrayTileMapAtlas;
class wyAtlasLabel;
class wyAtlasNode;
class wyBladeRibbon;
class wyButton;
class wyColorLayer;
class wyCompoundNode;
class wyCover;
class wyCoverFlow;
class wyDirector;
class wyDotPageIndicator;
class wyFrame;
class wyGradientColorLayer;
class wyLabel;
class wyLayer;
class wyLineRibbon;
class wyMenu;
class wyMenuItemAtlasLabel;
class wyMenuItemLabel;
class wyMenuItemSprite;
class wyMenuItemToggle;
class wyMotionStreak;
class wyMultiplexLayer;
class wyNinePatchSprite;
class wyNode;
class wyPageControl;
class wyPageIndicator;
class wyParallaxNode;
class wyParallaxObject;
class wyProgressTimer;
class wyRenderTexture;
class wyRibbon;
class wyScene;
class wyScheduler;
class wyScrollableLayer;
class wyScrollableLayerListener;
class wySlider;
class wySpotRibbon;
class wySprite;
class wySpriteBatchNode;
class wySpriteEx;
class wySpriteFrame;
class wyStripRibbon;
class wyTextBox;
class wyTextureNode;
class wyTGATileMapAtlas;
class wyTiledSprite;
class wyTileMapAtlas;
class wyTimer;
class wyToast;
class wyVirtualJoystick;

// opengl
class wyCamera;
class wyGLTexture2D;
class wyTexture2D;
class wyTextureManager;

// particle
class wyHGEParticleLoader;
struct wyParticle;
class wyParticleLoader;
class wyParticleSystem;
class wyQuadParticleSystem;

// persistence
class wyDatabase;
class wyPrefs;
class wyResultSet;
class wyStatement;

// render
class wyFrameBuffer;
class wyRenderer;
class wyRenderManager;
class wyRenderQueue;
class wyViewport;

// shader
class wyAttribute;
class wyBuffer;
class wyShader;
class wyShaderLoader;
class wyShaderManager;
class wyShaderProgram;
class wyShaderVariable;
class wyUniform;

// tmx
struct wyLayerInfo;
struct wyMapInfo;
struct wyTileSetInfo;
class wyTMXLayer;
class wyTMXLoader;
class wyTMXObject;
class wyTMXObjectGroup;
class wyTMXTileMap;

// transitions
class wyBottomPushInTransition;
class wyBottomSlideInTransition;
class wyBottomTilesShrinkOutTransition;
class wyClipInTransition;
class wyClipOutTransition;
class wyColorFadeTransition;
class wyCrossFadeTransition;
class wyFlipAngularTransition;
class wyFlipXTransition;
class wyFlipYTransition;
class wyJumpZoomTransition;
class wyLeftBottomTilesShrinkOutTransition;
class wyLeftPushInTransition;
class wyLeftSlideInTransition;
class wyPageTurn3DTransition;
class wyRadialCCWTransition;
class wyRadialCWTransition;
class wyRightPushInTransition;
class wyRightSlideInTransition;
class wyRightTopTilesShrinkOutTransition;
class wyRotateZoomTransition;
class wyShrinkGrowTransition;
class wySplitColsTransition;
class wySplitRowsTransition;
class wySuckTransition;
class wyTopPushInTransition;
class wyTopSlideInTransition;
class wyTopTilesShrinkOutTransition;
class wyTransitionScene;
class wyTurnOffTilesTransition;
class wyZoomFlipAngularTransition;
class wyZoomFlipXTransition;
class wyZoomFlipYTransition;

// types
struct wyAffineTransform;
struct wyBezierConfig;
struct wyBlendFunc;
struct wyColor3B;
struct wyColor4B;
struct wyColor4F;
struct wyColorHSV;
struct wyDimension;
struct wyHypotrochoidConfig;
struct wyLagrangeConfig;
struct wyPoint;
class wyPointList;
struct wyPVR;
struct wyQuad2D;
struct wyQuad3D;
struct wyRect;
struct wySize;
struct wyVertex3D;

// utils
class wyAssetInputStream;
class wyAssetOutputStream;
class wyCharProvider;
class wyImagePicker;
class wyMath;
class wyMD5;
class wyMemoryInputStream;
class wyMemoryOutputStream;
class wyResourceDecoder;
class wyRunnable;
class wyScroller;
class wyTargetSelector;
class wyTGALoader;
class wyUtils;
class wyVerletPoint;
class wyVerletStick;
class wyZwoptex;
class wyZwoptexManager;

// platform
#ifdef IOS
	@class WYEAGLView;
	@class WYUIEvent;
	@class WYUITouch;
#elif defined(MACOSX)
	@class WYOpenGLView;
#elif defined(WINDOWS)
	class wyGestureRecognizerListener;
	class wyWinGLView;
#endif

#endif // __WiEngine_Classes_h__
