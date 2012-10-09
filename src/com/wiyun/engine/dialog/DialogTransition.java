package com.wiyun.engine.dialog;

import com.wiyun.engine.BaseWYObject;

/**
 * \if English
 * Effect when open or close dialog
 * \else
 * 封装对话框出现, 消失的效果
 * \endif
 */
public class DialogTransition extends BaseWYObject {
	public static DialogTransition from(int pointer) {
		return new DialogTransition(pointer);
	}
	
	protected DialogTransition() {
	}
	
	protected DialogTransition(int pointer) {
		super(pointer);
	}
}
