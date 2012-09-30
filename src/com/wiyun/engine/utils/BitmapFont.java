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
package com.wiyun.engine.utils;

import com.wiyun.engine.BaseObject;

public class BitmapFont extends BaseObject {
	/// HGE bitmap font editor导出的格式
	public static final int BFF_HGE = 0;

	/// AngelCode的文本格式, 可以通过Glyph Designer导出
	public static final int BFF_ANGELCODE_TXT = 1;

	/// AngelCode的XML格式, 可以通过Glyph Designer导出
	public static final int BFF_ANGELCODE_XML = 2;
	
	/**
	 * 构造函数
	 */
	public BitmapFont() {}
	
	private native void nativeInit(int resId, int format);
	private native void nativeInit(String path, boolean isFile, int format, float inDensity);
	
	/**
	 * 构造函数
	 *
	 * @param resId 保存font信息的文件资源ID
	 * @param format 字体描述文件的格式, 缺省是HGE格式, HGE格式不是最强的格式, 不过这是WiEngine第一个支持的图片字体格式.
	 * 		可以认为是出于历史原因和纪念意义吧
	 */
	protected BitmapFont(int resId, int format) {
		nativeInit(resId, format);
	}

	/**
	 * 构造函数，根据系统路径加载字体
	 *
	 * @param path 字体描述文件的路径名
	 * @param isFile 默认为false，true表示path为系统路径，否则为资源路径
	 * @param format 字体描述文件的格式, 缺省是HGE格式, HGE格式不是最强的格式, 不过这是WiEngine第一个支持的图片字体格式.
	 * 		可以认为是出于历史原因和纪念意义吧
	 * @param inDensity 字体的密度
	 */
	protected BitmapFont(String path, boolean isFile, int format, float inDensity) {
		nativeInit(path, isFile, format, inDensity);
	}
	
	/**
	 * \if English
	 * load a bitmap font description file from resource id. returns existed one if it is already loaded
	 *
	 * @param resId resource id of bitmap font description file
	 * \else
	 * 载入一个图片字体的描述文件, 如还没有创建，创建一个新font，否则返回之前创建的
	 *
	 * @param resId 图片字体描述文件的资源ID
	 * \endif
	 */
	public static BitmapFont loadFont(int resId) {
		return new BitmapFont(resId, BFF_HGE);
	}
	
	/**
	 * \if English
	 * load a bitmap font description file from resource id. returns existed one if it is already loaded
	 *
	 * @param resId resource id of bitmap font description file
	 * @param format format of description file, default is BFF_HGE
	 * \else
	 * 载入一个图片字体的描述文件, 如还没有创建，创建一个新font，否则返回之前创建的
	 *
	 * @param resId 图片字体描述文件的资源ID
	 * @param format 字体描述文件的格式, 缺省是HGE格式, HGE格式不是最强的格式, 不过这是WiEngine第一个支持的图片字体格式.
	 * 		可以认为是出于历史原因和纪念意义吧
	 * \endif
	 */
	public static BitmapFont loadFont(int resId, int format) {
		return new BitmapFont(resId, format);
	}
	
	/**
	 * \if English
	 * load a bitmap font description file from assets folder or file system. returns existed one if it is already loaded
	 *
	 * @param path path of bitmap font description file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path is a relative path
	 * 		in assets folder. default is false
	 * \else
	 * 载入一个图片字体的描述文件, 如还没有创建，创建一个新font，否则返回之前创建的
	 *
	 * @param path 字体描述文件的路径名
	 * @param isFile 默认为false，true表示\c path是一个文件系统下的绝对路径，false表示\c path是一个
	 * 		assets下的相对路径
	 * \endif
	 */
	public static BitmapFont loadFont(String path, boolean isFile) {
		return new BitmapFont(path, isFile, BFF_HGE, 1);
	}
	
	/**
	 * \if English
	 * load a bitmap font description file from assets folder or file system. returns existed one if it is already loaded
	 *
	 * @param path path of bitmap font description file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path is a relative path
	 * 		in assets folder. default is false
	 * @param format format of description file, default is BFF_HGE
	 * \else
	 * 载入一个图片字体的描述文件, 如还没有创建，创建一个新font，否则返回之前创建的
	 *
	 * @param path 字体描述文件的路径名
	 * @param isFile 默认为false，true表示\c path是一个文件系统下的绝对路径，false表示\c path是一个
	 * 		assets下的相对路径
	 * @param format 字体描述文件的格式, 缺省是HGE格式, HGE格式不是最强的格式, 不过这是WiEngine第一个支持的图片字体格式.
	 * 		可以认为是出于历史原因和纪念意义吧
	 * \endif
	 */
	public static BitmapFont loadFont(String path, boolean isFile, int format) {
		return new BitmapFont(path, isFile, format, 1);
	}
	
	/**
	 * \if English
	 * load a bitmap font description file from assets folder or file system. returns existed one if it is already loaded
	 *
	 * @param path path of bitmap font description file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path is a relative path
	 * 		in assets folder. default is false
	 * @param format format of description file, default is BFF_HGE
	 * @param inDensity density of font, default is 1 and it means by default the font is thought as designed for mdpi
	 * \else
	 * 载入一个图片字体的描述文件, 如还没有创建，创建一个新font，否则返回之前创建的
	 *
	 * @param path 字体描述文件的路径名
	 * @param isFile 默认为false，true表示\c path是一个文件系统下的绝对路径，false表示\c path是一个
	 * 		assets下的相对路径
	 * @param format 字体描述文件的格式, 缺省是HGE格式, HGE格式不是最强的格式, 不过这是WiEngine第一个支持的图片字体格式.
	 * 		可以认为是出于历史原因和纪念意义吧
	 * @param inDensity 字体文件的密度, 这关系到WiEngine自动缩放的比例, 缺省是1, 即默认为字体是对mdpi设计的
	 * \endif
	 */
	public static BitmapFont loadFont(String path, boolean isFile, int format, float inDensity) {
		return new BitmapFont(path, isFile, format, inDensity);
	}

	/**
	 * 静态函数，通知底层卸载字体
	 */
	public static native void unloadFont(BitmapFont font);
}