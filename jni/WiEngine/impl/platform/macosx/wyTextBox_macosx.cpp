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

#include "wyTextBox_macosx.h"
#include "wyUtils_macosx.h"
#include "wyDirector_macosx.h"
#import "WYTextBoxDelegate.h"

extern wyDirector_macosx* gDirector;

wyTextBox* wyTextBox::make(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyNode* label) {
	wyTextBox* n = WYNEW wyTextBox_macosx(normal, selected, disabled, focused, label);
	return (wyTextBox*)n->autoRelease();
}

wyTextBox_macosx::wyTextBox_macosx(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyNode* label) :
		wyTextBox(normal, selected, disabled, focused, label) {
}

wyTextBox_macosx::~wyTextBox_macosx() {
}

void wyTextBox_macosx::showInputDialog() {
	// precondition checking
	if(gDirector == NULL || gDirector->getGLView() == NULL)
		return;
	
	// get button title
	NSString* title = m_title == NULL ? @"Input" : wyUtils_macosx::to_NSString(m_title);
	NSString* message = m_message == NULL ? @"" : wyUtils_macosx::to_NSString(m_message);
	NSString* positive = m_positiveButton == NULL ? nil : wyUtils_macosx::to_NSString(m_positiveButton);
	NSString* negative = m_negativeButton == NULL ? nil : wyUtils_macosx::to_NSString(m_negativeButton);
	const char* lan = wyDevice::getLanguage();
	if(negative == nil) {
		if(!strcmp("zh", lan))
			negative = @WY_CANCEL_ZH;
		else
			negative = @WY_CANCEL_EN;
	}
	if(positive == nil) {
		if(!strcmp("zh", lan))
			positive = @WY_OK_ZH;
		else
			positive = @WY_OK_EN;
	}
	
	// create alert
	NSAlert* alert = [NSAlert alertWithMessageText:title
									 defaultButton:positive
								   alternateButton:negative
									   otherButton:nil
						 informativeTextWithFormat:message];
	
	// create delegate of text field and alert
	WYTextBoxDelegate* delegate = [[WYTextBoxDelegate alloc] initWithTextBox:this];
	
	// set text field as accessory
	NSTextField* input = nil;
    if(m_password)
        input = [[NSSecureTextField alloc] initWithFrame:NSMakeRect(0, 0, 320, 24)];
    else
        input = [[NSTextField alloc] initWithFrame:NSMakeRect(0, 0, 320, 24)];
    NSString* t = wyUtils_macosx::to_NSString(getText());
	input.stringValue = t == nil ? @"" : t;
	[alert setAccessoryView:input];
	
	// show alert
	[alert beginSheetModalForWindow:[gDirector->getGLView() window]
					  modalDelegate:delegate
					 didEndSelector:@selector(alertDidEnd:returnCode:contextInfo:) 
						contextInfo:nil];
}

#endif // #if MACOSX
