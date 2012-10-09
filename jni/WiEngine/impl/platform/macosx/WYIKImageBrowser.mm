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
#if MACOSX

#import "WYIKImageBrowser.h"
#include "wyGlobal.h"
#include "wyUtils_macosx.h"
#include "wyDirector_macosx.h"

extern wyDirector_macosx* gDirector;

// layout
#define MARGIN_BOTTOM 10
#define MARGIN_RIGHT 10
#define MARGIN_LEFT 10
#define BUTTON_WIDTH 80
#define BUTTON_HEIGHT 24
#define SLIDER_WIDTH 167
#define SLIDER_HEIGHT 24

// root dir
#define ROOT "/Library/Desktop Pictures"

@interface WYImageObject : NSObject {
    NSString* path; 
}

@end

@implementation WYImageObject

- (void)dealloc {
    [path release];
    [super dealloc];
}

- (void)setPath:(NSString*)aPath {
    if(path != aPath){
        [path release];
        path = [aPath retain];
    }
}

- (NSString*)imageRepresentationType {
	return IKImageBrowserPathRepresentationType;
}

- (id)imageRepresentation {
	return path;
}

- (NSString*)imageUID {
    return path;
}

- (id)imageTitle {
	return [path lastPathComponent];
}

@end

@interface WYIKImageBrowser (Private)
- (void)sheetDidEnd:(NSWindow*)sheet returnCode:(NSInteger)returnCode contextInfo:(void*)contextInfo;
- (void)onOKButton:(id)sender;
- (void)onCancelButton:(id)sender;
- (void)onSliderValueChanged:(id)sender;
- (void)addImagesFromDirectory:(NSString*)path;
- (void)addImageWithPath:(NSString*)path;
@end

@implementation WYIKImageBrowser

- (id)initWithCallback:(wyImagePickerCallback*)callback data:(void*)data width:(int)width height:(int)height keepRatio:(BOOL)keepRatio {
	if(self = [super init]) {
		memset(&m_callback, 0, sizeof(wyImagePickerCallback));
		memcpy(&m_callback, callback, sizeof(wyImagePickerCallback));
		m_data = data;
		m_width = width;
		m_height = height;
		m_keepRatio = keepRatio;
		m_images = [[NSMutableArray array] retain];
		m_topLevel = YES;
		
		// get button title
		NSString* cancelButtonTitle = nil;
		NSString* okButtonTitle = nil;
		const char* lan = wyDevice::getLanguage();
		if(cancelButtonTitle == nil) {
			if(!strcmp("zh", lan))
				cancelButtonTitle = @WY_CANCEL_ZH;
			else
				cancelButtonTitle = @WY_CANCEL_EN;
		}
		if(okButtonTitle == nil) {
			if(!strcmp("zh", lan))
				okButtonTitle = @WY_OK_ZH;
			else
				okButtonTitle = @WY_OK_EN;
		}
		
		// sheet window minimum width
		float minWidth = MARGIN_LEFT + MARGIN_RIGHT + MARGIN_RIGHT + BUTTON_WIDTH + BUTTON_WIDTH + SLIDER_WIDTH;
		
		// button bar height
		float buttonBarHeight = MARGIN_BOTTOM + MARGIN_BOTTOM + BUTTON_HEIGHT;
		
		// create sheet window
		m_sheetWindow = [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, MAX(minWidth, wyDevice::winWidth), wyDevice::winHeight)
													styleMask:NSBorderlessWindowMask 
													  backing:NSBackingStoreBuffered 
														defer:NO];
		
		// create ok button
		NSRect frame = NSMakeRect(wyDevice::winWidth - MARGIN_RIGHT - BUTTON_WIDTH, MARGIN_BOTTOM, BUTTON_WIDTH, BUTTON_HEIGHT);
		NSButton* okBtn = [[[NSButton alloc] initWithFrame:frame] autorelease];
		[okBtn setTitle:okButtonTitle];
		[okBtn setButtonType:NSMomentaryPushInButton];
		[okBtn setBezelStyle:NSRoundedBezelStyle];
		[okBtn setTarget:self];
		[okBtn setAction:@selector(onOKButton:)];
		[m_sheetWindow.contentView addSubview:okBtn];
		
		// create cancel button
		frame = NSMakeRect(wyDevice::winWidth - MARGIN_RIGHT * 2 - BUTTON_WIDTH * 2, MARGIN_BOTTOM, BUTTON_WIDTH, BUTTON_HEIGHT);
		NSButton* cancelBtn = [[[NSButton alloc] initWithFrame:frame] autorelease];
		[cancelBtn setTitle:cancelButtonTitle];
		[cancelBtn setButtonType:NSMomentaryPushInButton];
		[cancelBtn setBezelStyle:NSRoundedBezelStyle];
		[cancelBtn setTarget:self];
		[cancelBtn setAction:@selector(onCancelButton:)];
		[m_sheetWindow.contentView addSubview:cancelBtn];
		
		// create slider
		frame = NSMakeRect(MARGIN_LEFT, MARGIN_BOTTOM, SLIDER_WIDTH, SLIDER_HEIGHT);
		NSSlider* slider = [[[NSSlider alloc] initWithFrame:frame] autorelease];
		[slider setTickMarkPosition:NSTickMarkAbove];
		[[slider cell] setSliderType:NSLinearSlider];
		[slider setMinValue:0];
		[slider setMaxValue:1];
		[slider setNumberOfTickMarks:10];
		[[slider cell] setControlSize:NSMiniControlSize];
		[slider setTarget:self];
		[slider setAction:@selector(onSliderValueChanged:)];
		[m_sheetWindow.contentView addSubview:slider];
		
		// create scroller view
		frame = NSMakeRect(0, buttonBarHeight, MAX(minWidth, wyDevice::winWidth), wyDevice::winHeight - buttonBarHeight);
		NSScrollView* scrollView = [[[NSScrollView alloc] initWithFrame:frame] autorelease];
		[scrollView setScrollerStyle:NSScrollerStyleOverlay];
		[scrollView setHasHorizontalScroller:NO];
		[scrollView setHasVerticalScroller:YES];
		[scrollView setBorderType:NSBezelBorder];
		[m_sheetWindow.contentView addSubview:scrollView];
		
		// create image browser view
		m_imageBrowser = [[[IKImageBrowserView alloc] initWithFrame:frame] autorelease];
		[m_imageBrowser setDelegate:self];
		[m_imageBrowser setDataSource:self];
		[m_imageBrowser setAllowsMultipleSelection:NO];
		[m_imageBrowser setCellsStyleMask:IKCellsStyleOutlined | IKCellsStyleShadowed | IKCellsStyleTitled];
		[scrollView setDocumentView:m_imageBrowser];
		
		// set slider value
		[slider setFloatValue:[m_imageBrowser zoomValue]]; 
		
		// add desktop pictures
		m_curPath = [@ROOT retain];
		[self addImagesFromDirectory:m_curPath];
	}
	return self;
}

- (void)dealloc {
    [m_sheetWindow release];
	[m_images release];
	[m_curPath release];
    [super dealloc];
}

- (void)beginSheet {
	[NSApp beginSheet:m_sheetWindow
	   modalForWindow:[gDirector->getGLView() window]
		modalDelegate:self
	   didEndSelector:@selector(sheetDidEnd:returnCode:contextInfo:)
		  contextInfo:nil];
}

- (void)sheetDidEnd:(NSWindow*)sheet returnCode:(NSInteger)returnCode contextInfo:(void*)contextInfo {
	switch(returnCode) {
		case NSCancelButton:
			if(m_callback.onImagePickCancelled)
				m_callback.onImagePickCancelled(m_data);
			break;
		case NSOKButton:
			if(m_callback.onImagePicked) {
				// get selected image index
				NSIndexSet* indexSet = [m_imageBrowser selectionIndexes];
				if([indexSet count] < 1) {
					if(m_callback.onImagePickCancelled)
						m_callback.onImagePickCancelled(m_data);
				} else {
					WYImageObject* obj = [m_images objectAtIndex:[indexSet firstIndex]];
					NSImage* image = [[[NSImage alloc] initWithContentsOfFile:[obj imageUID]] autorelease];
					NSBitmapImageRep* rep = [[image representations] objectAtIndex:0];
					NSInteger width = [rep pixelsWide];
					NSInteger height = [rep pixelsHigh];
					
					// calculate scale
					float scaleX = (float)m_width / width;
					float scaleY = (float)m_height / height;
					
					// get data
					char* data = wyUtils_macosx::loadNSImage(image, NULL, NULL, false, scaleX, scaleY);	
					
					// callback
					m_callback.onImagePicked((const char*)data, m_width, m_height, m_data);
				}	
			}
			break;
	}
	
	[self release];
}

- (void)onOKButton:(id)sender {
	[NSApp endSheet:m_sheetWindow returnCode:NSOKButton];
	[m_sheetWindow orderOut:self];
}

- (void)onCancelButton:(id)sender {
	[NSApp endSheet:m_sheetWindow returnCode:NSCancelButton];
	[m_sheetWindow orderOut:self];
}

- (void)onSliderValueChanged:(id)sender {
	[m_imageBrowser setZoomValue:[sender floatValue]];
}

- (NSUInteger) numberOfItemsInImageBrowser:(IKImageBrowserView *)view {
    return [m_images count];
}

- (id)imageBrowser:(IKImageBrowserView *) view itemAtIndex:(NSUInteger)index {
    return [m_images objectAtIndex:index];
}

- (void)addImagesFromDirectory:(NSString*)path {
    BOOL dir;
    BOOL exist = [[NSFileManager defaultManager] fileExistsAtPath:path isDirectory:&dir];
	if(!exist)
		return;
	
    if(dir) {
        NSArray* content = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:path error:nil];
        NSUInteger n = [content count];
        
        for(NSUInteger i = 0; i < n; i++)
			[self addImageWithPath:[path stringByAppendingPathComponent:[content objectAtIndex:i]]];
    } else {
        [self addImageWithPath:path];
	}
	
	[m_imageBrowser reloadData];
}

- (void)addImageWithPath:(NSString*)path {   
    NSString* filename = [path lastPathComponent];
	if([filename length] > 0) {
		char *ch = (char*)[filename UTF8String];
		if(ch) {
			if(ch[0] == '.')
				return;
		}
	}
	
	WYImageObject* item = [[WYImageObject alloc] init];	
	[item setPath:path];
	[m_images addObject:item];
	[item release];
}

- (void) imageBrowser:(IKImageBrowserView *) aBrowser cellWasDoubleClickedAtIndex:(NSUInteger) index {
	// get clicked image object
	WYImageObject* obj = [m_images objectAtIndex:index];
	NSString* path = [obj imageUID];
	
	// is directory?
	BOOL dir;
	BOOL upLevel = NO;
	if(!m_topLevel && [@".." isEqualToString:path]) {
		dir = YES;
		upLevel = YES;
	} else {
		[[NSFileManager defaultManager] fileExistsAtPath:[obj imageUID] isDirectory:&dir];
	}
	
	// if file, select it, if dir, enter it
	if(dir) {
		// clear old image object
		[m_images removeAllObjects];
		NSString* newPath = nil;
		
		// decide new path
		if(upLevel) {
			newPath = [m_curPath stringByDeletingLastPathComponent];
			if([@ROOT isEqualToString:newPath])
				m_topLevel = YES;
		} else {
			newPath = path;
			m_topLevel = NO;
		}
		
		// if not top level, add ..
		if(!m_topLevel) {
			WYImageObject* upObj = [[[WYImageObject alloc] init] autorelease];
			[upObj setPath:@".."];
			[m_images addObject:upObj];
		}
		
		// add it
		m_curPath = [newPath retain];
		[self addImagesFromDirectory:m_curPath];
		
		// reload
		[m_imageBrowser reloadData];
	} else {
		[self onOKButton:nil];
	}
}

@end

#endif // #if MACOSX
