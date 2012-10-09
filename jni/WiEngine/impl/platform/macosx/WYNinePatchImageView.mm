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

#import "WYNinePatchImageView.h"

@implementation WYNinePatchImageView

- (WYNinePatchImageView*)initWithImage:(NSImage*)image {
	self = [super initWithFrame:NSZeroRect];
	if(self) {
		float patchWidth = 2;
		float patchHeight = 2;
		float cutX = (image.size.width - patchWidth) / 2;
		float cutY = (image.size.height - patchHeight) / 2;
		
		m_topLeft = [[NSImage alloc] initWithSize:NSMakeSize(cutX, cutY)];
		[m_topLeft lockFocus];
		[image drawInRect:NSMakeRect(0, 0, cutX, cutY) 
				 fromRect:NSMakeRect(0, cutY + patchHeight, cutX, cutY) 
				operation:NSCompositeCopy 
				 fraction:1.0];
		[m_topLeft unlockFocus];
		
		m_top = [[NSImage alloc] initWithSize:NSMakeSize(patchWidth, cutY)];
		[m_top lockFocus];
		[image drawInRect:NSMakeRect(0, 0, patchWidth, cutY) 
				 fromRect:NSMakeRect(cutX, cutY + patchHeight, patchWidth, cutY)
				operation:NSCompositeCopy 
				 fraction:1.0];
		[m_top unlockFocus];
		
		m_topRight = [[NSImage alloc] initWithSize:NSMakeSize(cutX, cutY)];
		[m_topRight lockFocus];
		[image drawInRect:NSMakeRect(0, 0, cutX, cutY) 
				 fromRect:NSMakeRect(cutX + patchWidth, cutY + patchHeight, cutX, cutY)
				operation:NSCompositeCopy 
				 fraction:1.0];
		[m_topRight unlockFocus];
		
		// setup center section, left, right
		m_left = [[NSImage alloc] initWithSize:NSMakeSize(cutX, patchHeight)];
		[m_left lockFocus];
		[image drawInRect:NSMakeRect(0, 0, cutX, patchHeight)
				 fromRect:NSMakeRect(0, cutY, cutX, patchHeight) 
				operation:NSCompositeCopy 
				 fraction:1.0];
		[m_left unlockFocus];
		
		m_center = [[NSImage alloc] initWithSize:NSMakeSize(patchWidth, patchHeight)];
		[m_center lockFocus];
		[image drawInRect:NSMakeRect(0, 0, patchWidth, patchHeight)
				 fromRect:NSMakeRect(cutX, cutY, patchWidth, patchHeight)
				operation:NSCompositeCopy 
				 fraction:1.0];
		[m_center unlockFocus];
		
		m_right = [[NSImage alloc] initWithSize:NSMakeSize(cutX, patchHeight)];
		[m_right lockFocus];
		[image drawInRect:NSMakeRect(0, 0, cutX, patchHeight)
				 fromRect:NSMakeRect(cutX + patchWidth, cutY, cutX, patchHeight)
				operation:NSCompositeCopy 
				 fraction:1.0];
		[m_right unlockFocus];
		
		m_bottomLeft = [[NSImage alloc] initWithSize:NSMakeSize(cutX, cutY)];
		[m_bottomLeft lockFocus];
		[image drawInRect:NSMakeRect(0, 0, cutX, cutY)
				 fromRect:NSMakeRect(0, 0, cutX, cutY)
				operation:NSCompositeCopy 
				 fraction:1.0];
		[m_bottomLeft unlockFocus];	
		
		m_bottom = [[NSImage alloc] initWithSize:NSMakeSize(patchWidth, cutY)];
		[m_bottom lockFocus];
		[image drawInRect:NSMakeRect(0, 0, patchWidth, cutY)
				 fromRect:NSMakeRect(cutX, 0, patchWidth, cutY)
				operation:NSCompositeCopy 
				 fraction:1.0];
		[m_bottom unlockFocus];		
		
		m_bottomRight = [[NSImage alloc] initWithSize:NSMakeSize(cutX, cutY)];
		[m_bottomRight lockFocus];
		[image drawInRect:NSMakeRect(0, 0, cutX, cutY)
				 fromRect:NSMakeRect(cutX + patchWidth, 0, cutX, cutY)
				operation:NSCompositeCopy 
				 fraction:1.0];
		[m_bottomRight unlockFocus];
	}
    return self;
}

- (void)dealloc {
    [m_topLeft release];
	[m_top release];
	[m_topRight release];
	[m_center release];
	[m_left release];
	[m_right release];
	[m_bottom release];
	[m_bottomLeft release];
	[m_bottomRight release];
    [super dealloc];
}

- (void)drawRect:(NSRect)dirtyRect {
	[[NSColor clearColor] set];
    NSRectFill(dirtyRect);
	
	float cutX = m_topLeft.size.width;
	float cutY = m_topLeft.size.height;
	float width = self.frame.size.width;
	float height = self.frame.size.height;

	[m_topLeft drawInRect:NSMakeRect(0, height - cutY, cutX, cutY)
				 fromRect:NSMakeRect(0, 0, m_topLeft.size.width, m_topLeft.size.height) 
				operation:NSCompositeSourceOver
				 fraction:1.0];
	
	[m_top drawInRect:NSMakeRect(cutX, height - cutY, width - cutX * 2, cutY) 
			 fromRect:NSMakeRect(0, 0, m_top.size.width, m_top.size.height) 
			operation:NSCompositeSourceOver
			 fraction:1.0];
	
	[m_topRight drawInRect:NSMakeRect(width - cutX, height - cutY, cutX, cutY)
				  fromRect:NSMakeRect(0, 0, m_topRight.size.width, m_topRight.size.height) 
				 operation:NSCompositeSourceOver
				  fraction:1.0];
	
	[m_left drawInRect:NSMakeRect(0, cutY, cutX, height - cutY * 2)
			  fromRect:NSMakeRect(0, 0, m_left.size.width, m_left.size.height) 
			 operation:NSCompositeSourceOver
			  fraction:1.0];
	
	[m_center drawInRect:NSMakeRect(cutX, cutY, width - cutX * 2, height - cutY * 2)
				fromRect:NSMakeRect(0, 0, m_center.size.width, m_center.size.height) 
			   operation:NSCompositeSourceOver
				fraction:1.0];
	
	[m_right drawInRect:NSMakeRect(width - cutX, cutY, cutX, height - cutY * 2)
			   fromRect:NSMakeRect(0, 0, m_right.size.width, m_right.size.height) 
			  operation:NSCompositeSourceOver
			   fraction:1.0];
	
	[m_bottomLeft drawInRect:NSMakeRect(0, 0, cutX, cutY)
					fromRect:NSMakeRect(0, 0, m_bottomLeft.size.width, m_bottomLeft.size.height) 
				   operation:NSCompositeSourceOver
					fraction:1.0];
	
	[m_bottom drawInRect:NSMakeRect(cutX, 0, width - cutX * 2, cutY) 
				fromRect:NSMakeRect(0, 0, m_bottom.size.width, m_bottom.size.height) 
			   operation:NSCompositeSourceOver
				fraction:1.0];
	
	[m_bottomRight drawInRect:NSMakeRect(width - cutX, 0, cutX, cutY)
					 fromRect:NSMakeRect(0, 0, m_bottomRight.size.width, m_bottomRight.size.height) 
					operation:NSCompositeSourceOver
					 fraction:1.0];
}

@end

#endif // #if MACOSX
