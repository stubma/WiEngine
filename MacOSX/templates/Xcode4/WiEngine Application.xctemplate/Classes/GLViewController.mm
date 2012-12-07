//
//  GLViewController.m
//  ___PROJECTNAME___
//
//  Created by ___FULLUSERNAME___ on ___DATE___.
//  Copyright ___YEAR___ ___ORGANIZATIONNAME___. All rights reserved.
//

#import "GLViewController.h"
#include "wyDirector.h"
#include "FirstScene.h"
#include "WYOpenGLView.h"

// global screen config, only available for mac os x or windows
extern wyScreenConfig gScreenConfig;

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

- (id)init {
	self = [super init];
	if(self) {
		// if you want to test against different screen, set screen config here
//		wyScreenConfig c = { 1.5f, 1.0f, 1200, 600 };
//		wyDirector::setScreenConfig(c);
		
		// create opengl view
		WYOpenGLView* glView = [[[WYOpenGLView alloc] initWithFrame:NSMakeRect(0, 0, gScreenConfig.winWidth, gScreenConfig.winHeight)] autorelease];
		glView.autoresizingMask = NSViewNotSizable;
		self.view = glView;
		
		// set showing fps
		wyDirector* director = wyDirector::getInstance();
		director->setShowFPS(true);

		// add life cycle listener
	    director->addLifecycleListener(&s_surfaceLifeCycleListener, NULL);
		
		/*
		 * If you want to run demo in base size mode, uncomment
		 * following code. To understand what is base size mode, view
		 * WiYun blog: http://blog.wiyun.com/?p=949
		 */
//		director->setScaleMode(SCALE_MODE_BASE_SIZE_FIT_XY);
//		director->setBaseSize(320, 480);
	}
	return self;
}

- (void)dealloc {
	WYOpenGLView* glView = (WYOpenGLView*)self.view;
	[glView stopRender];
	[glView.window makeFirstResponder:nil];
	[self.view removeFromSuperview];
    [super dealloc];
}

@end