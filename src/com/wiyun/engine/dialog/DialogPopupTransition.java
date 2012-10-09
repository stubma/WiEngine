package com.wiyun.engine.dialog;

/**
 * \if English
 * Popup dialog, first dialog will be scaled up and then shrink to normal size
 * \else
 * 对话框弹出效果, 会先有一个放大效果, 然后缩小到正常大小
 * \endif
 */
public class DialogPopupTransition extends DialogTransition {
	public static DialogPopupTransition make() {
		return new DialogPopupTransition();
	}
	
	public static DialogPopupTransition from(int pointer) {
		return new DialogPopupTransition(pointer);
	}
	
	protected DialogPopupTransition() {
		nativeInit();
	}
	
	private native void nativeInit();

	protected DialogPopupTransition(int pointer) {
		super(pointer);
	}
}
