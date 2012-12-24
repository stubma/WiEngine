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

@synthesize window = _window;
@synthesize viewController = _viewController;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    if([self.window respondsToSelector:@selector(setRootViewController:)])
        self.window.rootViewController = self.viewController;
    else
        [self.window addSubview:self.viewController.view];
	[self.window makeKeyAndVisible];
    return NO;
}

- (void)applicationWillResignActive:(UIApplication *)application {
	wyDirector* director = wyDirector::getInstanceNoCreate();
	if(director)
		director->pause();
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
	wyDirector* director = wyDirector::getInstanceNoCreate();
	if(director)
		director->resume();
}

- (void)dealloc
{
    [_window release];
    [_viewController release];
    [super dealloc];
}

@end
