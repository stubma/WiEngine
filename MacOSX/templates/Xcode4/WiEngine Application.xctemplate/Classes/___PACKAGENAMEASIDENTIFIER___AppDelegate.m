//
//  ___PROJECTNAMEASIDENTIFIER___AppDelegate.m
//  ___PROJECTNAME___
//
//  Created by ___FULLUSERNAME___ on ___DATE___.
//  Copyright ___YEAR___ ___ORGANIZATIONNAME___. All rights reserved.
//

#import "___PACKAGENAMEASIDENTIFIER___AppDelegate.h"
#import "GLViewController.h"
#import "wyDirector.h"

@implementation ___PACKAGENAMEASIDENTIFIER___AppDelegate

@synthesize window = m_window;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
	// create GLViewController, it will create opengl view so we attach it to window
	m_glvc = [[GLViewController alloc] init];
	[self.window.contentView addSubview:m_glvc.view];	
}

- (void)applicationDidResignActive:(NSNotification *)aNotification {
	wyDirector* director = wyDirector::getInstanceNoCreate();
	if(director)
		director->pause();
}

- (void)applicationDidBecomeActive:(NSNotification *)aNotification {
	wyDirector* director = wyDirector::getInstanceNoCreate();
	if(director)
		director->resume();
}

- (void)dealloc {
	[m_glvc release];
    [super dealloc];
}

@end