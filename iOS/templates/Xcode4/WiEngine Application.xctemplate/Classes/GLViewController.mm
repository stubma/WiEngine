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

@implementation GLViewController

- (void)viewDidLoad {
	((WYEAGLView*)self.view).delegate = self;
	
	/*
	 * You should uncomment following code if you want to
	 * use base size adaption mode. To know what is base size
	 * adaption mode, view WiYun blog: http://blog.wiyun.com/?p=949
 	 */
//	wyDirector* director = wyDirector::getInstance();
//  director->setScaleMode(SCALE_MODE_BASE_SIZE_FIT_XY);
//  director->setBaseSize(480, 800);
}

- (void)dealloc {
	((WYEAGLView*)self.view).delegate = nil;
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

- (void)eaglView:(WYEAGLView*)v frameBufferCreatedWithWidth:(int)width height:(int)height {
	wyDirector* director = wyDirector::getInstance();
	if(director->getRunningScene() == NULL) {
		director->setShowFPS(true);
		
		// run with it
		wyScene* scene = new FirstScene();
		director->runWithScene(scene);
		scene->release();	
	}
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
