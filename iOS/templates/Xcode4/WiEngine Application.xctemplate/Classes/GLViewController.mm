//
//  GLViewController.m
//  ___PROJECTNAME___
//
//  Created by ___FULLUSERNAME___ on ___DATE___.
//  Copyright ___YEAR___ ___ORGANIZATIONNAME___. All rights reserved.
//

#import "GLViewController.h"
#import "WiEngine.h"
#import "FirstScene.h"

// you should change it to 1 if you use landscape orientation
#define LANDSCAPE 0

// is already started?
static bool s_started = false;

static void onSurfaceChanged(int w, int h, void* data) {
	// ensure it is not started multiple times
	if(!s_started) {
		s_started = true;

		// run with first scene
		wyDirector* director = wyDirector::getInstance();
		wyScene* scene = new FirstScene();
		director->runWithScene(scene);
		scene->release();
	}
}

// life cycle listener
static wyDirectorLifecycleListener s_surfaceLifeCycleListener = {
	NULL,
	onSurfaceChanged,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

@implementation GLViewController

- (void)viewDidLoad {	
	wyDirector* director = wyDirector::getInstance();
	director->setShowFPS(true);
	
	// add life cycle listener
    director->addLifecycleListener(&s_surfaceLifeCycleListener, NULL);

	/*
	 * You should uncomment following code if you want to
	 * use base size adaption mode. To know what is base size
	 * adaption mode, view WiYun blog: http://blog.wiyun.com/?p=949
 	 */
//  director->setScaleMode(SCALE_MODE_BASE_SIZE_FIT_XY);
//  director->setBaseSize(480, 800);
}

- (void)dealloc {
    [super dealloc];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation {
#if LANDSCAPE
	return UIInterfaceOrientationIsLandscape(toInterfaceOrientation);
#else
	return UIInterfaceOrientationIsPortrait(toInterfaceOrientation);
#endif
}

- (NSUInteger)supportedInterfaceOrientations {
#if LANDSCAPE
    return UIInterfaceOrientationMaskLandscape;
#else
    return UIInterfaceOrientationMaskPortrait;
#endif
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
	
	wyDirector* director = wyDirector::getInstance();
	director->resume();
}

- (void)viewWillDisappear:(BOOL)animated {
	[super viewWillDisappear:animated];
	
	wyDirector* director = wyDirector::getInstance();
	director->pause();
}

@end
