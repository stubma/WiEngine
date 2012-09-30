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

#include "wyTextBox_ios.h"
#include "wyUtils_ios.h"
#import "WYTextBoxDelegate.h"

wyTextBox* wyTextBox::make(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyNode* label) {
	wyTextBox* n = WYNEW wyTextBox_ios(normal, selected, disabled, focused, label);
	return (wyTextBox*)n->autoRelease();
}

wyTextBox_ios::wyTextBox_ios(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyNode* label) :
		wyTextBox(normal, selected, disabled, focused, label) {
}

wyTextBox_ios::~wyTextBox_ios() {
}

void wyTextBox_ios::showInputDialog() {
	// create input alert view
	NSString* title = m_title == NULL ? @"Input" : wyUtils_ios::to_NSString(m_title);
	NSString* message = m_message == NULL ? @"" : wyUtils_ios::to_NSString(m_message);
	NSString* positive = m_positiveButton == NULL ? @"OK" : wyUtils_ios::to_NSString(m_positiveButton);
	NSString* negative = m_negativeButton == NULL ? @"Cancel" : wyUtils_ios::to_NSString(m_negativeButton);
	WYInputAlertView* alert = [[WYInputAlertView alloc] initWithTitle:title
															  message:message
															 delegate:[[[WYTextBoxDelegate alloc] initWithTexBox:this] autorelease]
													   positiveButton:positive
													   negativeButton:negative];

	// set initial value
	NSString* text = wyUtils_ios::to_NSString(getText());
	alert.textField.text = text;
    if(m_password)
        alert.textField.secureTextEntry = YES;

	/*
	 * we didn't call [alert show] because it will bring up a cancel touch event. That will
	 * cause a concurrent access to event queue and a warning printed. So we schedule it in
	 * next loop
	 */
	[alert performSelectorOnMainThread:@selector(show)
							withObject:nil
						 waitUntilDone:NO];
}

#endif // #if IOS
