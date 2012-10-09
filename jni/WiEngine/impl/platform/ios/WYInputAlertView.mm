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

#import "WYInputAlertView.h"

@interface WYInputAlertView (Private) 

- (void)onTextChanged:(NSNotification*)notification;

@end

@implementation WYInputAlertView

@synthesize textField = _textField;

- (id)initWithTitle:(NSString *)title message:(NSString*)message delegate:(id)delegate positiveButton:(NSString *)positiveButton negativeButton:(NSString*)negativeButton {
	if(self = [super initWithTitle:title 
						   message:[NSString stringWithFormat:@"%@\n\n", [message isEqualToString:@""] ? @"" : [NSString stringWithFormat:@"%@\n", message]]
						  delegate:delegate 
				 cancelButtonTitle:negativeButton
				 otherButtonTitles:positiveButton, nil]) {
		// create text field
		_textField = [[[UITextField alloc] initWithFrame:CGRectMake(15.0, 0.f, 255.0, 36.0)] autorelease];
		_textField.borderStyle = UITextBorderStyleRoundedRect;
		_textField.autocorrectionType = UITextAutocorrectionTypeNo;
		_textField.keyboardType = UIKeyboardTypeDefault;
		_textField.returnKeyType = UIReturnKeyDone;
		_textField.contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
		_textField.delegate = self;
		
		// set delegate to self
		self.delegate = self;
		
		// set real delegate
		_wyDelegate = delegate;
		[(id)_wyDelegate retain];
		
		// add text field
		[self addSubview:_textField];
		
		// add notification handler
		[[NSNotificationCenter defaultCenter] addObserver:self 
												 selector:@selector(onTextChanged:) 
													 name:UITextFieldTextDidChangeNotification 
												   object:nil];
	}
	return self;
}

- (void)dealloc {
	[[NSNotificationCenter defaultCenter] removeObserver:self 
													name:UITextFieldTextDidChangeNotification 
												  object:nil];
	[(id)_wyDelegate release];
    [super dealloc];
}

- (void)onTextChanged:(NSNotification*)notification {
	[_wyDelegate wyInputAlertViewTextChanged:_textField.text];
}

- (void)alertView:(UIAlertView *)alertView willDismissWithButtonIndex:(NSInteger)buttonIndex {
	if(buttonIndex == 0)
		[_wyDelegate wyInputAlertViewNegativeButtonClicked];
	else if(buttonIndex == 1)
		[_wyDelegate wyInputAlertViewPositiveButtonClicked:_textField.text];
}

- (void)layoutSubviews {
	[super layoutSubviews];
	
	// position text field, we need do it here because we don't know alert size in constructor
	CGRect frame = _textField.frame;
	frame.origin.y = self.frame.size.height - 123.f;
	_textField.frame = frame;
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
	[_textField resignFirstResponder];
	return YES;
}

- (void)show {
	[super show];
	[self release];
	[_textField becomeFirstResponder];
}

@end

#endif // #if IOS