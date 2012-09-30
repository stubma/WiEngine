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

// global screen config, only available for mac os x or windows
extern wyScreenConfig gScreenConfig;

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
		glView.delegate = self;
		self.view = glView;
		
		/*
		 * If you want to run demo in base size mode, uncomment
		 * following code. To understand what is base size mode, view
		 * WiYun blog: http://blog.wiyun.com/?p=949
		 */
//		wyDirector* director = wyDirector::getInstance();
//		director->setScaleMode(SCALE_MODE_BASE_SIZE_FIT_XY);
//		director->setBaseSize(320, 480);
	}
	return self;
}

- (void)dealloc {
	WYOpenGLView* glView = (WYOpenGLView*)self.view;
	glView.delegate = nil;
	[glView stopRender];
	[glView.window makeFirstResponder:nil];
	[self.view removeFromSuperview];
    [super dealloc];
}

- (void)glView:(WYOpenGLView*)v frameBufferCreatedWithWidth:(int)width height:(int)height {
	wyDirector* director = wyDirector::getInstance();
	if(director->getRunningScene() == NULL) {
		director->setShowFPS(true);
		
		// run with it
		wyScene* scene = new FirstScene();
		director->runWithScene(scene);
		scene->release();	
	}
}

- (void)glViewFrameBufferDestroyed:(WYOpenGLView*)v {
}

@end