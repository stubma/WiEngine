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
package com.wiyun.engine.nodes;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.text.Editable;
import android.text.TextUtils;
import android.text.TextWatcher;
import android.text.method.PasswordTransformationMethod;
import android.view.View;
import android.view.WindowManager;
import android.widget.EditText;

/**
 * 提供一个单行文本编辑框组件，wyTextBox是一个组合式节点，它是由4个状态节点和一个标签节点组合
 * 而成的。四个状态和\link wyButton wyButton\endlink一样，是普通，焦点，按下，禁止四态，
 * 只有普通态是必须提供的，其它的都可以为NULL。标签节点是用来显示用户输入的问题的，只要是
 * WiEngine支持的标签节点都可以，或者通泛一点说，只要是实现了\link wyNode wyNode\endlink
 * 中set/getText方法的子类都可以。标签节点显示的范围不会超过文本框状态图片的范围。<br/>
 *
 * 文本框节点的大小在创建后会自动根据状态图片的大小决定，当然您也可以手动设置大小，但是不建议这么
 * 做，因为自动计算出的大小是最佳大小。<br/>
 *
 * 文本框编辑的是采用弹框式，因为在手机上可能存在软键盘，当软键盘出现时，有可能会遮挡文本框
 * 节点，因此采用弹框式的设计更容易让用户输入。可以设置弹出框的标题和提示。<br/>
 *
 * 文本框缺省是打开了触摸事件处理的.
 */
public class TextBox extends Node {
	/**
	 * \if English
	 * Definition of edit text event callback
	 * \else
	 * \link TextBox TextBox\endlink 的回调接口定义
	 * \endif
	 */
	public static interface ITextBoxCallback {
		/**
		 * 文本内容发生变化时被调用, 如果之后用户点击了取消按钮，则这些文本变化都会被取消
		 *
		 * @param pointer TextBox的底层指针
		 */
		public void onTextChanged(int pointer);

		/**
		 * 开始编辑时调用, 即输入框弹出时被调用
		 *
		 * @param pointer TextBox的底层指针
		 */
		public void onBeginEditing(int pointer);

		/**
		 * 结束编辑时调用，不管是点击了确定还是取消按钮，就是调用这个方法
		 *
		 * @param pointer TextBox的底层指针
		 */
		public void onEndEditing(int pointer);
	}
	
	public static TextBox make(Node normalSprite, Node selectedSprite, Node disabledSprite, Node focusedSprite, Node label) {
		return new TextBox(normalSprite, selectedSprite, disabledSprite, focusedSprite, label);
	}
	
	public static TextBox make(int pointer) {
		return new TextBox(pointer);
	}
	
	public static TextBox from(int pointer) {
		return pointer == 0 ? null : new TextBox(pointer);
	}
	
	protected TextBox(Node normalSprite, Node selectedSprite, Node disabledSprite, Node focusedSprite, Node label) {
		nativeInit(normalSprite, selectedSprite, disabledSprite, focusedSprite, label);
	}
	
	private native void nativeInit(Node normalSprite, Node selectedSprite, Node disabledSprite, Node focusedSprite, Node label);
	
	protected TextBox(int pointer) {
		super(pointer);
	}
	
	@Override
	protected void doNativeInit() {
	}
	
	public native void setText(String string);
	
	public native String getText();
	
	public native void setCallback(ITextBoxCallback callback);
	
	/**
	 * 设置弹出框的标题
	 *
	 * @param title 标题字符串, 这个字符串会被复制，因此方法返回后可以立刻释放
	 */
	public native void setTitle(String title);

	/**
	 * 获得弹出框的标题
	 *
	 * @return 弹出框的标题字符串, 调用者不需要负责释放
	 */
	public native String getTitle();

	/**
	 * 设置弹出框的提示
	 *
	 * @param msg 提示字符串, 这个字符串会被复制，因此方法返回后可以立刻释放
	 */
	public native void setMessage(String msg);

	/**
	 * 获得弹出框的提示
	 *
	 * @return 弹出框的提示字符串, 调用者不需要负责释放
	 */
	public native String getMessage();

	/**
	 * 设置弹出框的确定按钮文字
	 *
	 * @param btn 确定按钮文字字符串, 这个字符串会被复制，因此方法返回后可以立刻释放
	 */
	public native void setPositiveButton(String btn);

	/**
	 * 获得弹出框的确定按钮文字
	 *
	 * @return 弹出框的确定按钮文字, 调用者不需要负责释放
	 */
	public native String getPositiveButton();

	/**
	 * 设置弹出框的取消按钮文字
	 *
	 * @param btn 取消按钮文字字符串, 这个字符串会被复制，因此方法返回后可以立刻释放
	 */
	public native void setNegativeButton(String btn);

	/**
	 * 获得弹出框的取消按钮文字
	 *
	 * @return 弹出框的取消按钮文字, 调用者不需要负责释放
	 */
	public native String getNegativeButton();
	
	/**
	 * 设置文本框矩形和标签节点之间的空隙. 默认都是0.
	 *
	 * @param left 左边间隔
	 * @param top 上边间隔
	 * @param right 右边间隔
	 * @param bottom 下边间隔
	 */
	public native void setPadding(float left, float top, float right, float bottom);
	
	/**
	 * \if English
	 * Set text box as password style
	 * \else
	 * 设置文本框为密码输入框
	 * \endif
	 */
	public native void setPassword(boolean flag);

	/**
	 * \if English
	 * Is text box a password input?
	 * \else
	 * 文本框是否是密码输入框
	 * \endif
	 */
	public native boolean isPassword();
	
	private native void onOKButtonClicked(String text);
	
	private native void onCancelButtonClicked();
	
	private native void onTextChanged(String newText);
	
	static void showInputDialog(final int pointer) {
		// get context
		final Context context = Director.getInstance().getContext();
		if(context == null && !(context instanceof Activity))
			return;
		
		((Activity)context).runOnUiThread(new Runnable() {
			public void run() {
				// get text box object
				final TextBox box = TextBox.from(pointer);
				if(box == null)
					return;
				
				// create text view
				final EditText et = new EditText(context);
				et.setSingleLine(true);
				et.setTextAppearance(context, android.R.style.TextAppearance_Medium);
				et.setTextColor(0xff000000);
				et.setText(box.getText());
				et.selectAll();
				if(box.isPassword())
					et.setTransformationMethod(PasswordTransformationMethod.getInstance());
				et.addTextChangedListener(new TextWatcher() {
					@Override
					public void onTextChanged(CharSequence arg0, int arg1, int arg2, int arg3) {
						box.onTextChanged(et.getText().toString().trim());
					}
					
					@Override
					public void beforeTextChanged(CharSequence arg0, int arg1, int arg2,
							int arg3) {
					}
					
					@Override
					public void afterTextChanged(Editable arg0) {
					}
				});
				
				// build dialog and show
				AlertDialog.Builder builder = new AlertDialog.Builder(context);
				
				// view content
				builder.setView(et);
				
				// positive button
				String btn = box.getPositiveButton();
				if(btn == null)
					btn = "OK";
				builder.setPositiveButton(btn, new DialogInterface.OnClickListener() {
						@Override
						public void onClick(DialogInterface arg0, int arg1) {
							box.onOKButtonClicked(et.getText().toString().trim());
						}
					});
					
				// negative button
				btn = box.getNegativeButton();
				if(btn == null)
					btn = "Cancel";
				builder.setNegativeButton(btn, new DialogInterface.OnClickListener() {
					@Override
					public void onClick(DialogInterface arg0, int arg1) {
						box.onCancelButtonClicked();
					}
				});
				
				// set cancel listener
				builder.setOnCancelListener(new DialogInterface.OnCancelListener() {
					@Override
					public void onCancel(DialogInterface arg0) {
						box.onCancelButtonClicked();
					}
				});
				
				// title
				String title = box.getTitle();
				if(!TextUtils.isEmpty(title))
					builder.setTitle(title);
				
				// message
				String msg = box.getMessage();
				if(!TextUtils.isEmpty(msg))
					builder.setMessage(msg);
				
				// create and show
				// install a focus listener to make soft keyboard visible
				final Dialog d = builder.create();
				et.setOnFocusChangeListener(new View.OnFocusChangeListener() {
					@Override
					public void onFocusChange(View v, boolean hasFocus) {
						if(hasFocus)
							d.getWindow().setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_STATE_ALWAYS_VISIBLE);
					}
				});
				d.show();
			}
		});
	}
}