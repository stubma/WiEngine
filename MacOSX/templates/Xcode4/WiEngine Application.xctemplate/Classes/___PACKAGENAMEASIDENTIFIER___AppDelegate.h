//
//  ___PROJECTNAMEASIDENTIFIER___AppDelegate.h
//  ___PROJECTNAME___
//
//  Created by ___FULLUSERNAME___ on ___DATE___.
//  Copyright ___YEAR___ ___ORGANIZATIONNAME___. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class GLViewController;

@interface ___PACKAGENAMEASIDENTIFIER___AppDelegate : NSObject {
@private
	NSWindow* m_window;
	GLViewController* m_glvc;
}

@property (nonatomic, assign) IBOutlet NSWindow* window;

@end