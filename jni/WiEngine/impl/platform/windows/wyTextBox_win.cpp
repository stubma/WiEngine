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
#if WINDOWS

#include "wyTextBox_win.h"
#include "resource.h"
#include "wyDirector.h"
#include "wyWinGLView.h"
#include "wyLog.h"

extern HMODULE gModule;

// current instance
static wyTextBox_win* s_current = NULL;

wyTextBox* wyTextBox::make(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyNode* label) {
	wyTextBox* n = WYNEW wyTextBox_win(normal, selected, disabled, focused, label);
	return (wyTextBox*)n->autoRelease();
}

wyTextBox_win::wyTextBox_win(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyNode* label) :
		wyTextBox(normal, selected, disabled, focused, label) {
	s_current = this;
}

wyTextBox_win::~wyTextBox_win() {
}

void wyTextBox_win::showInputDialog() {
	HWND hWnd = wyDirector::getInstance()->getGLView()->getWindowHandle();
	DialogBox(gModule, MAKEINTRESOURCE(IDD_INPUT), hWnd, About);
}

INT_PTR CALLBACK wyTextBox_win::About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
		case WM_INITDIALOG:
		{
			// set message
			SetDlgItemText(hDlg, IDC_MESSAGE, s_current->m_message == NULL ? "" : s_current->m_message);

			// set button
			SetDlgItemText(hDlg, IDOK, s_current->m_positiveButton == NULL ? "OK" : s_current->m_positiveButton);
			SetDlgItemText(hDlg, IDCANCEL, s_current->m_negativeButton == NULL ? "Cancel" : s_current->m_negativeButton);

			// set prefilled text
			SetDlgItemText(hDlg, IDC_TEXTBOX, s_current->getText() == NULL ? "" : s_current->getText());

			// set password style
			if(s_current->isPassword()) {
				HWND hTextBox = GetDlgItem(hDlg, IDC_TEXTBOX);
				SendMessage(hTextBox, EM_SETPASSWORDCHAR, (WPARAM)'*', NULL);
			}

			return (INT_PTR)TRUE;
		}
		case WM_COMMAND:
			switch(LOWORD(wParam)) {
				case IDOK:
				{
					char buf[32767];
					GetDlgItemText(hDlg, IDC_TEXTBOX, buf, 32767);
					s_current->onPositiveButtonClicked(buf);
					EndDialog(hDlg, LOWORD(wParam));
					return (INT_PTR)TRUE;
				}
				case IDCANCEL:
					s_current->onNegativeButtonClicked();
					EndDialog(hDlg, LOWORD(wParam));
					return (INT_PTR)TRUE;
				case IDC_TEXTBOX:
					switch(HIWORD(wParam)) {
						case EN_CHANGE:
						{
							char buf[32767];
							GetDlgItemText(hDlg, IDC_TEXTBOX, buf, 32767);
							s_current->onTextChanged(buf);
							break;
						}
					}
					break;
			}
			break;
	}
	return (INT_PTR)FALSE;
}

#endif // #if WINDOWS
