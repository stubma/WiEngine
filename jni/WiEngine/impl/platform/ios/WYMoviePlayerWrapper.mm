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
#if IOS

#import "WYMoviePlayerWrapper.h"
#import "WYEAGLView.h"

/// notification of movie player overlay touch event
NSString* WYOverlayViewTouchNotification = @"WYOverlayViewTouchNotification";

#pragma -
#pragma WYMoviePlayerOverlay implementation

@implementation WYMoviePlayerOverlay

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
	[[NSNotificationCenter defaultCenter] postNotificationName:WYOverlayViewTouchNotification object:nil];
}

@end

#pragma -
#pragma WYMoviePlayerWrapper implementation

@implementation WYMoviePlayerWrapper

- (void)dealloc {
	[[NSNotificationCenter defaultCenter] removeObserver:self
													name:MPMoviePlayerPlaybackDidFinishNotification
												  object:nil];
	[[NSNotificationCenter defaultCenter] removeObserver:self
													name:WYOverlayViewTouchNotification
												  object:nil];
	[m_player release];
	[super dealloc];
}

- (void)playVideo:(NSURL*)url {
	// create player
	m_player = [[MPMoviePlayerController alloc] initWithContentURL:url];
	m_player.controlStyle = MPMovieControlStyleNone;
	
	// listen notification
	[[NSNotificationCenter defaultCenter] addObserver:self
											 selector:@selector(onPlaybackDidFinished:)
												 name:MPMoviePlayerPlaybackDidFinishNotification
											   object:nil];
	[[NSNotificationCenter defaultCenter] addObserver:self
											 selector:@selector(onPlayerTouched:)
												 name:WYOverlayViewTouchNotification
											   object:nil];
	
	// add player view to window
	wyGLSurfaceView view = wyDirector::getInstance()->getGLView();
	[m_player.view setFrame:view.window.bounds];
	[view.window addSubview:m_player.view];
	
	// add overlay view
	m_overlay = [[WYMoviePlayerOverlay alloc] init];
	m_overlay.frame = view.window.bounds;
	[view.window addSubview:m_overlay];
	[m_overlay release];
	
	// play
	[m_player play];
}

- (void)onPlaybackDidFinished:(NSNotification*)notifiation {
	if(m_player.view.superview != nil) {
		[m_player.view removeFromSuperview];
		[self release];
	}
	
	if(m_overlay.superview != nil) {
		[m_overlay removeFromSuperview];
	}
}

- (void)onPlayerTouched:(NSNotification*)notifiation {
	if(m_player.view.superview != nil) {
		[m_player.view removeFromSuperview];
		[self release];
	}
	
	if(m_overlay.superview != nil) {
		[m_overlay removeFromSuperview];
	}
}

@end

#endif // #if IOS