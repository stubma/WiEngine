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

import com.wiyun.engine.nodes.Button;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.nodes.SpriteEx;
import com.wiyun.engine.nodes.SpriteFrame;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;

/**
 * \if English
 * Atlas manager, it maintains a cache for every atlas image. So when you don't want some atlas, you
 * must remove it from this manager
 * \else
 * 图片集管理类, 它维护一个图片集的缓冲. 所以当你不再需要某个图片集时, 需要把图片集从这里删除以便系统能释放它.
 * \endif
 */
public class ZwoptexManager {
	/**
	 * \if English
	 * Add a zwoptex to cache, its name is the key
	 *
	 * @param name name of zwoptex
	 * @param resId resource id of zwoptex plist file
	 * \else
	 * 通过某个名称缓存一个Zwoptex
	 *
	 * @param name Zwoptex名称
	 * @param resId Zwoptex的plist文件资源id
	 * \endif
	 */
	public static void addZwoptex(String name, int resId) {
		addZwoptex(name, resId, null);
	}
	
	/**
	 * \if English
	 * Add a zwoptex to cache, its name is the key
	 *
	 * @param name name of zwoptex
	 * @param resId resource id of zwoptex plist file
	 * @param tex related texture of zwoptex atlas image
	 * \else
	 * 通过某个名称缓存一个Zwoptex
	 *
	 * @param name Zwoptex名称
	 * @param resId Zwoptex的plist文件资源id
	 * @param tex zwoptex相关联的\link Texture2D Texture2D\endlink 对象
	 * \endif
	 */
	public static native void addZwoptex(String name, int resId, Texture2D tex);
	
	/**
	 * \if English
	 * Check if a zwoptex object with given name exists
	 *
	 * @param name name of zwoptex
	 * @return true means this zwoptex is already loaded
	 * \else
	 * 检查某个名称的Zwoptex是否存在
	 *
	 * @param name Zwoptex名称
	 * @return true表示这个Zwoptex已经载入了
	 * \endif
	 */
	public static native boolean hasZwoptex(String name);
	
	/**
	 * \if English
	 * Get names of all frames in zwoptex
	 *
	 * @param name name of zwoptex
	 * @param count how many frames in this zwoptex
	 * @return name list of all frames, or null if no zwoptex found by given \c name
	 * \else
	 * 得到某个Zwoptex里面的所有frame名称
	 *
	 * @param name Zwoptex名称
	 * @param count 返回frame的个数
	 * @return frame名称的数组, 如果name代表的Zwoptex不存在, 则返回null
	 * \endif
	 */
	public static native String[] getFrameNames(String name);
	
	/**
	 * \if English
	 * Add a zwoptex by name
	 *
	 * @param name name of zwoptex
	 * @param path relative path of zwoptex plist file in assets
	 * \else
	 * 通过某个名称缓存一个Zwoptex
	 *
	 * @param name Zwoptex名称
	 * @param path Zwoptex的plist文件在assets中的相对路径
	 * \endif
	 */
	public static void addZwoptex(String name, String path) {
		addZwoptex(name, path, false);
	}
	
	/**
	 * \if English
	 * Add a zwoptex by name
	 *
	 * @param name name of zwoptex
	 * @param path path of zwoptex plist file
	 * @param isFile true means \c path is an absolute path in file system, false
	 * 		means \c path is a relative path under assets
	 * \else
	 * 通过某个名称缓存一个Zwoptex
	 *
	 * @param name Zwoptex名称
	 * @param path Zwoptex的plist文件路径
	 * @param isFile true表示path是一个文件系统路径，false表示是一个assets下的相对路径
	 * \endif
	 */
	public static void addZwoptex(String name, String path, boolean isFile) {
		addZwoptex(name, path, isFile, null);
	}
	
	/**
	 * \if English
	 * Add a zwoptex by name
	 *
	 * @param name name of zwoptex
	 * @param path path of zwoptex plist file
	 * @param isFile true means \c path is an absolute path in file system, false
	 * 		means \c path is a relative path under assets
	 * @param tex related texture of zwoptex atlas image
	 * \else
	 * 通过某个名称缓存一个Zwoptex
	 *
	 * @param name Zwoptex名称
	 * @param path Zwoptex的plist文件路径
	 * @param isFile true表示path是一个文件系统路径，false表示是一个assets下的相对路径
	 * @param tex zwoptex相关联的\link Texture2D Texture2D\endlink 对象
	 * \endif
	 */
	public static native void addZwoptex(String name, String path, boolean isFile, Texture2D tex);
	
	/**
	 * \if English
	 * Add a zwoptex by name
	 *
	 * @param name name of zwoptex
	 * @param path path of zwoptex plist file
	 * @param isFile true means \c path is an absolute path in file system, false
	 * 		means \c path is a relative path under assets
	 * @param tex related texture of zwoptex atlas image
	 * @param inDensity input density of zwoptex
	 * \else
	 * 通过某个名称缓存一个Zwoptex
	 *
	 * @param name Zwoptex名称
	 * @param path Zwoptex的plist文件路径
	 * @param isFile true表示path是一个文件系统路径，false表示是一个assets下的相对路径
	 * @param tex zwoptex相关联的\link Texture2D Texture2D\endlink 对象
	 * @param inDensity 密度
	 * \endif
	 */
	public static native void addZwoptex(String name, String path, boolean isFile, Texture2D tex, float inDensity);
	
	/**
	 * \if English
	 * Get a frame rect by name. The frame rect returned is effective area of frame image and
	 * it should be smaller than original size if image has transparent border
	 *
	 * @param zwoptexName name of zwoptex
	 * @param frameName name of frame
	 * @return \link WYRect WYRect\endlink, or zero rectangle if not found
	 * \else
	 * 通过名称得到一个矩形, 这个矩形是帧的有效区域矩形, 如果某个图片本身具有透明区域, 那么
	 * 在生成Zwoptex时一般都是可以选择是否裁剪透明区域的, 如果被裁剪了, 得到的这个矩形和图片
	 * 的原始大小是不相符的.
	 *
	 * @param zwoptexName zwoptex的名称
	 * @param frameName 帧名称
	 * @return \link WYRect WYRect\endlink, 如果没找到, 返回0大小矩形
	 * \endif
	 */
	public static WYRect getFrameRect(String zwoptexName, String frameName) {
		WYRect rect = WYRect.makeZero();
		nativeGetFrameRect(zwoptexName, frameName, rect);
		return rect;
	}
	
	private static native void nativeGetFrameRect(String zwoptexName, String frameName, WYRect rect);
	
	/**
	 * \if English
	 * Get a frame rect by frame name. This method doesn't require zwoptex name so
	 * it will search all zwoptexes. You can use this method if you already know there
	 * is no frame has same name
	 *
	 * @param frameName name of frame
	 * @return \link WYRect WYRect\endlink, or zero rectangle if not found
	 * \else
	 * 通过名称得到一个矩形, 该方法不需要指定zwoptex名称，因此将搜索所有的zwoptex,
	 * 如果找到则返回，找不到则返回零大小矩形。如果预先知道没有重名帧，则可以用这个
	 * 方法进行查找，代码上会更好维护。
	 *
	 * @param frameName 帧名称
	 * @return \link WYRect WYRect\endlink, 如果没找到, 返回零大小矩形
	 * \endif
	 */
	public static WYRect getFrameRect(String frameName) {
		WYRect rect = WYRect.makeZero();
		nativeGetFrameRect(frameName, rect);
		return rect;
	}
	
	private static native void nativeGetFrameRect(String frameName, WYRect rect);
	
	/**
	 * \if English
	 * Get frame count in a zwoptex
	 *
	 * @param zwoptexName zwoptex name
	 * @return frame count in this zwoptex, or zero if zwoptex not found
	 * \else
	 * 得到某个zwoptex里的帧数量
	 *
	 * @param zwoptexName zwoptex名称
	 * @return zwoptex中的帧数量, 如果没找到对应的zwoptex, 返回0
	 * \endif
	 */
	public static native int getFrameCount(String zwoptexName);
	
	/**
	 * \if English
	 * Get all frame rects in a zwoptex
	 *
	 * @param zwoptexName name of zwoptex
	 * @return rect array
	 * \else
	 * 得到某个zwoptex里面的所有帧矩形
	 *
	 * @param zwoptexName zwoptex名称
	 * @return 包含所有矩形的数组
	 * \endif
	 */
	public static WYRect[] getFrameRects(String zwoptexName) {
		WYRect[] ret = new WYRect[getFrameCount(zwoptexName)];
		nativeGetFrameRects(zwoptexName, ret);
		return ret;
	}
	
	private static native void nativeGetFrameRects(String zwoptexName, WYRect[] ret);

	/**
	 * \if English
	 * Get a sprite frame by name
	 *
	 * @param zwoptexName name of zwoptex
	 * @param frameName name of frame
	 * @return \link SpriteFrame SpriteFrame\endlink, or NULL if not found
	 * \else
	 * 通过名称得到一个\link SpriteFrame SpriteFrame\endlink对象, 该方法不需要
	 * 指定zwoptex名称, 因此将搜索所有的zwoptex
	 *
	 * @param zwoptexName zwoptex的名称
	 * @param frameName 帧名称
	 * @return \link SpriteFrame SpriteFrame\endlink
	 * \endif
	 */
	public static SpriteFrame getSpriteFrame(String zwoptexName, String frameName) {
		return SpriteFrame.from(nativeGetSpriteFrame(zwoptexName, frameName));
	}
	
	/**
	 * \if English
	 * Get a sprite frame by name
	 *
	 * @param frameName name of frame
	 * @return \link SpriteFrame SpriteFrame\endlink, or NULL if not found
	 * \else
	 * 根据名称查找一个\link SpriteFrame SpriteFrame\endlink 对象
	 *
	 * @param frameName 帧名称
	 * @return \link SpriteFrame SpriteFrame\endlink, 如果没有找到, 返回NULL
	 * \endif
	 */
	public static SpriteFrame getSpriteFrame(String frameName) {
		return SpriteFrame.from(nativeGetSpriteFrame(frameName));
	}
	
	private native static int nativeGetSpriteFrame(String zwoptexName, String frameName);
	private native static int nativeGetSpriteFrame(String frameName);

	/**
	 * \if English
	 * Get a zwoptex frame by name
	 *
	 * @param frameName name of frame
	 * @return \link ZwoptexFrame ZwoptexFrame\endlink, or NULL if not found
	 * \else
	 * 根据名称查找一个zwoptex帧
	 *
	 * @param frameName 帧名称
	 * @return \link ZwoptexFrame ZwoptexFrame\endlink, 如果没有找到, 返回NULL
	 * \endif
	 */
	public static ZwoptexFrame getZwoptexFrame(String frameName) {
		return ZwoptexFrame.from(nativeGetZwoptexFrame(frameName));
	}
	
	private native static int nativeGetZwoptexFrame(String zwoptexName, String frameName);
	private native static int nativeGetZwoptexFrame(String frameName);
	
	/**
	 * \if English
	 * Create a \link Sprite Sprite\endlink from a frame
	 *
	 * @param zwoptexName name of zwoptex
	 * @param frameName name of frame
	 * @return tex \link Texture2D Texture2D\endlink. It can be NULL and NULL means using
	 * 		zwoptex texture
	 * @return \link Sprite Sprite\endlink, or NULL if frame is not found
	 * \else
	 * 通过Zwoptex创建一个\link Sprite Sprite\endlink 对象
	 *
	 * @param zwoptexName zwoptex的名称
	 * @param frameName 帧名称
	 * @param tex \link Texture2D Texture2D\endlink, 可以为NULL，如果为NULL，表示将使用zwoptex本身绑定的贴图,
	 * 		但是如果zwoptex本身没有绑定贴图，则会返回NULL
	 * @return \link Sprite Sprite\endlink 对象，如果没有找到相应名称的zwoptex帧，或者没有贴图对象，则返回NULL
	 * \endif
	 */
	public static Sprite makeSprite(String zwoptexName, String frameName, Texture2D tex) {
		return Sprite.from(nativeMakeSprite(zwoptexName, frameName, tex));
	}
	
	private static native int nativeMakeSprite(String zwoptexName, String frameName, Texture2D tex);
	
	/**
	 * \if English
	 * Create a \link Button Button\endlink from a frame
	 *
	 * @param zwoptexName name of zwoptex
	 * @param frameName name of frame
	 * @param ts target selector of this button
	 * @return tex \link Texture2D Texture2D\endlink. It can be NULL and NULL means using
	 * 		zwoptex texture
	 * @return \link Button Button\endlink, or NULL if frame is not found
	 * \else
	 * 通过Zwoptex创建一个\link Sprite Sprite\endlink 对象
	 *
	 * @param zwoptexName zwoptex的名称
	 * @param frameName 帧名称
	 * @param ts 按钮上的触摸事件选择子
	 * @param tex \link Texture2D Texture2D\endlink, 可以为NULL，如果为NULL，表示将使用zwoptex本身绑定的贴图,
	 * 		但是如果zwoptex本身没有绑定贴图，则会返回NULL
	 * @return \link Button Button\endlink 对象，如果没有找到相应名称的zwoptex帧，或者没有贴图对象，则返回NULL
	 * \endif
	 */
	public static Button makeButton(String zwoptexName, String frameName, TargetSelector ts, Texture2D tex) {
		return Button.from(nativeMakeButton(zwoptexName, frameName, ts, tex));
	}
	
	private static native int nativeMakeButton(String zwoptexName, String frameName, TargetSelector ts, Texture2D tex);
	
	/**
	 * \if English
	 * Create a \link SpriteEx SpriteEx\endlink object from a frame
	 *
	 * @param zwoptexName name of zwoptex
	 * @param frameName name of frame
	 * @param tex \link Texture2D Texture2D\endlink, it can be NULL and NULL means using
	 * 		zwoptex texture
	 * @return \link SpriteEx SpriteEx\endlink, or NULL if frame is not found
	 * \else
	 * 通过Zwoptex创建一个\link SpriteEx SpriteEx\endlink 对象
	 *
	 * @param zwoptexName zwoptex的名称
	 * @param frameName 帧名称
	 * @param tex \link Texture2D Texture2D\endlink, 可以为NULL，如果为NULL，表示将使用zwoptex本身绑定的贴图,
	 * 		但是如果zwoptex本身没有绑定贴图，则会返回NULL
	 * @return \link SpriteEx SpriteEx\endlink 对象，如果没有找到相应名称的zwoptex帧，或者没有贴图对象，则返回NULL
	 * \endif
	 */
	public static SpriteEx makeSpriteEx(String zwoptexName, String frameName, Texture2D tex) {
		return SpriteEx.from(nativeMakeSpriteEx(zwoptexName, frameName, tex));
	}
	
	private static native int nativeMakeSpriteEx(String zwoptexName, String frameName, Texture2D tex);
	
	/**
	 * \if English
	 * Set texture for a zwoptex
	 * 
	 * @param name name of zwoptex
	 * @param tex texture object
	 * \else
	 * 设置与zwoptex相关联的贴图对象
	 * 
	 * @param name zwoptex名称
	 * @param tex 贴图对象
	 * \endif
	 */
	public static native void setZwoptexTexture(String name, Texture2D tex);
	
	/**
	 * \if English
	 * Remove a cached zwoptex object by name. But for the texture object, you must
	 * use \link TextureManager TextureManager\endlink to delete it.
	 *
	 * @param name name of zwoptex
	 * \else
	 * 删除一个Zwoptex对象. 但是对于Zwoptex的贴图对象, 只能通过\link TextureManager TextureManager\endlink
	 * 来删除才是真正的删除
	 *
	 * @param name zwoptex名称
	 * \endif
	 */
	public static native void removeZwoptex(String name);
	
	/**
	 * \if English
	 * Remove all zwoptex. But for texture, you must remove it by \link wyTextureManager wyTextureManager\endlink
	 * \else
	 * 删除所有的zwoptex, 但是对于贴图你需要用\link wyTextureManager wyTextureManager\endlink删除
	 * \endif
	 */
	public static native void removeAllZwoptex();
	
	/**
	 * \if English
	 * Create a \link Sprite Sprite\endlink. This method doesn't require zwoptex name so it
	 * will search all zwoptex. You can use it if you already know there is no duplicate frame
	 * name
	 *
	 * @param frameName name of frame
	 * @return \link Sprite Sprite\endlink, or NULL if frame is not found
	 * \else
	 * 通过Zwoptex创建一个\link Sprite Sprite\endlink 对象, 这个方法不指定zwoptex名称，因此会在
	 * 所有的zwoptex中搜索，直到找到一个匹配的为止。如果确定不存在重复名称的帧，可以用这个方法来生成sprite，
	 * 因为代码可以有更好的维护性。
	 *
	 * @param frameName 帧名称
	 * @return \link Sprite Sprite\endlink 对象，如果没有找到相应名称的zwoptex帧，或者没有贴图对象，则返回NULL
	 * \endif
	 */
	public static Sprite makeSprite(String frameName) {
		return Sprite.from(nativeMakeSprite(frameName));
	}

	private native static int nativeMakeSprite(String frameName);
	
	/**
	 * \if English
	 * Create a \link Button Button\endlink. This method doesn't require zwoptex name so it
	 * will search all zwoptex. You can use it if you already know there is no duplicate frame
	 * name
	 *
	 * @param frameName name of frame
	 * @param ts target selector of this button
	 * @return \link Button Button\endlink, or NULL if frame is not found
	 * \else
	 * 通过Zwoptex创建一个\link Button Button\endlink 对象, 这个方法不指定zwoptex名称，因此会在
	 * 所有的zwoptex中搜索，直到找到一个匹配的为止。如果确定不存在重复名称的帧，可以用这个方法来生成sprite，
	 * 因为代码可以有更好的维护性。
	 *
	 * @param frameName 帧名称
	 * @param ts 按钮上的触摸事件选择子
	 * @return \link Button Button\endlink 对象，如果没有找到相应名称的zwoptex帧，或者没有贴图对象，则返回NULL
	 * \endif
	 */
	public static Button makeButton(String frameName, TargetSelector ts) {
		return Button.from(nativeMakeButton(frameName, ts));
	}
	
	private native static int nativeMakeButton(String frameName, TargetSelector ts);
	
	/**
	 * \if English
	 * Create a \link SpriteEx SpriteEx\endlink. This method doesn't require zwoptex name so it
	 * will search all zwoptex. You can use it if you already know there is no duplicate frame
	 * name
	 *
	 * @param frameName name of frame
	 * @return \link SpriteEx SpriteEx\endlink, or NULL if frame is not found
	 * \else
	 * 通过Zwoptex创建一个\link SpriteEx SpriteEx\endlink 对象, 这个方法不指定zwoptex名称，因此会在
	 * 所有的zwoptex中搜索，直到找到一个匹配的为止。如果确定不存在重复名称的帧，可以用这个方法来生成sprite，
	 * 因为代码可以有更好的维护性。
	 *
	 * @param frameName 帧名称
	 * @return \link SpriteEx SpriteEx\endlink 对象，如果没有找到相应名称的zwoptex帧，或者没有贴图对象，则返回NULL
	 * \endif
	 */
	public static SpriteEx makeSpriteEx(String frameName) {
		return SpriteEx.from(nativeMakeSpriteEx(frameName));
	}
	
	private native static int nativeMakeSpriteEx(String frameName);
}
