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
#ifndef __wyZwoptexManager_h__
#define __wyZwoptexManager_h__

#include "wyObject.h"
#include "wyZwoptex.h"
#include "wySprite.h"
#include "wySpriteEx.h"
#include "wyButton.h"

// for code simplify
#define WY_ZWOPTEX_MAP map<const char*, wyZwoptex*, wyStrPredicate>
#define WY_ZWOPTEX_ITER WY_ZWOPTEX_MAP::iterator

/**
 * @class wyZwoptexManager
 *
 * \if English
 * Atlas manager, it maintains a cache for every atlas image. So when you don't want some atlas, you
 * must remove it from this manager
 * \else
 * 图片集管理类, 它维护一个图片集的缓冲. 所以当你不再需要某个图片集时, 需要把图片集从这里删除以便系统能释放它.
 * \endif
 */
class WIENGINE_API wyZwoptexManager : public wyObject {
private:
	WY_ZWOPTEX_MAP* m_cache;

private:
	wyZwoptexManager();

	/// find sprite frame by frame name, it searches all zwoptex
	wySpriteFrame* findSpriteFrame(const char* frameName);

	/// find zwoptex frame by frame name, it searches all zwoptex
	/// also it can returned matched zwoptex
	wyZwoptexFrame* findFrame(const char* frameName, wyZwoptex** outZwoptex = NULL, char** outName = NULL);

public:
	static wyZwoptexManager* getInstance();
	virtual ~wyZwoptexManager();

	/**
	 * \if English
	 * Add a zwoptex to cache, its name is the key
	 *
	 * @param name name of zwoptex
	 * @param resId resource id of zwoptex plist file
	 * @param tex related texture of zwoptex atlas image. It can be NULL but you must
	 * 		set it before use it
	 * \else
	 * 通过某个名称缓存一个Zwoptex
	 *
	 * @param name Zwoptex名称
	 * @param resId Zwoptex的plist文件资源id
	 * @param tex zwoptex相关联的\link wyTexture2D wyTexture2D\endlink 对象，可选参数，缺省为NULL，
	 * 		如果为NULL，应该在之后通过其它api设置
	 * \endif
	 */
	void addZwoptex(const char* name, int resId, wyTexture2D* tex = NULL);

	/**
	 * \if English
	 * Add a zwoptex by name
	 *
	 * @param name name of zwoptex
	 * @param path path of zwoptex plist file
	 * @param isFile true means \c path is an absolute path in file system, false
	 * 		means \c path is a relative path under assets
	 * @param tex related texture of zwoptex atlas image, it can be NULL but must be
	 * 		set before using
	 * @param inDensity input density of zwoptex, default is zero and it means use current
	 * 		defaultInDensity
	 * \else
	 * 通过某个名称缓存一个Zwoptex
	 *
	 * @param name Zwoptex名称
	 * @param path Zwoptex的plist文件路径
	 * @param isFile true表示path是一个文件系统路径，false表示是一个assets下的相对路径
	 * @param tex zwoptex相关联的\link wyTexture2D wyTexture2D\endlink 对象，可选参数，缺省为NULL，
	 * 		如果为NULL，应该在之后通过其它api设置
	 * @param inDensity 密度, 缺省为0, 表示使用当前设置的defaultInDensity
	 * \endif
	 */
	void addZwoptex(const char* name, const char* path, bool isFile = false, wyTexture2D* tex = NULL, float inDensity = 0);

	/**
	 * \if English
	 * Get a cached zwoptex object by name
	 *
	 * @param name name of zwoptex
	 * @return cache
	 * \else
	 * 得到一个缓存的\link wyZwoptex wyZwoptex\endlink 对象
	 *
	 * @param name zwoptex名称
	 * @return \link wyZwoptex wyZwoptex\endlink
	 * \endif
	 */
	wyZwoptex* getZwoptex(const char* name);

	/**
	 * \if English
	 * Remove a cached zwoptex object by name. But for the texture object, you must
	 * use \link wyTextureManager wyTextureManager\endlink to delete it.
	 *
	 * @param name name of zwoptex
	 * \else
	 * 删除一个Zwoptex对象. 但是对于Zwoptex的贴图对象, 只能通过\link wyTextureManager wyTextureManager\endlink
	 * 来删除才是真正的删除
	 *
	 * @param name zwoptex名称
	 * \endif
	 */
	void removeZwoptex(const char* name);

	/**
	 * \if English
	 * Remove all zwoptex. But for texture, you must remove it by \link wyTextureManager wyTextureManager\endlink
	 * \else
	 * 删除所有的zwoptex, 但是对于贴图你需要用\link wyTextureManager wyTextureManager\endlink删除
	 * \endif
	 */
	void removeAllZwoptex();

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
	bool hasZwoptex(const char* name);

	/**
	 * \if English
	 * Get names of all frames in zwoptex
	 *
	 * @param name name of zwoptex
	 * @param count how many frames in this zwoptex
	 * @return name list of all frames
	 * \else
	 * 得到某个Zwoptex里面的所有frame名称
	 *
	 * @param name Zwoptex名称
	 * @param count 返回frame的个数
	 * @return frame名称的指针数组, 如果name代表的Zwoptex不存在, 则返回NULL. 调用者要负责释放返回的指针数组.
	 * \endif
	 */
	const char** getFrameNames(const char* name, size_t* count);

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
	int getFrameCount(const char* zwoptexName);

	/**
	 * \if English
	 * Get a frame rect by name. The frame rect returned is effective area of frame image and
	 * it should be smaller than original size if image has transparent border
	 *
	 * @param zwoptexName name of zwoptex
	 * @param frameName name of frame
	 * @return \link wyRect wyRect\endlink, or zero rectangle if not found
	 * \else
	 * 通过名称得到一个矩形, 这个矩形是帧的有效区域矩形, 如果某个图片本身具有透明区域, 那么
	 * 在生成Zwoptex时一般都是可以选择是否裁剪透明区域的, 如果被裁剪了, 得到的这个矩形和图片
	 * 的原始大小是不相符的.
	 *
	 * @param zwoptexName zwoptex的名称
	 * @param frameName 帧名称
	 * @return \link wyRect wyRect\endlink, 如果没找到, 返回0大小矩形
	 * \endif
	 */
	wyRect getFrameRect(const char* zwoptexName, const char* frameName);

	/**
	 * \if English
	 * Get a frame rect by frame name. This method doesn't require zwoptex name so
	 * it will search all zwoptexes. You can use this method if you already know there
	 * is no frame has same name
	 *
	 * @param frameName name of frame
	 * @return \link wyRect wyRect\endlink, or zero rectangle if not found
	 * \else
	 * 通过名称得到一个矩形, 该方法不需要指定zwoptex名称，因此将搜索所有的zwoptex,
	 * 如果找到则返回，找不到则返回零大小矩形。如果预先知道没有重名帧，则可以用这个
	 * 方法进行查找，代码上会更好维护。
	 *
	 * @param frameName 帧名称
	 * @return \link wyRect wyRect\endlink, 如果没找到, 返回零大小矩形
	 * \endif
	 */
	wyRect getFrameRect(const char* frameName);

	/**
	 * \if English
	 * Get all frame rects in a zwoptex
	 *
	 * @param zwoptexName name of zwoptex
	 * @param count it returns the count of rect
	 * @return rect list pointer, caller should release it
	 * \else
	 * 得到某个zwoptex里面的所有帧矩形
	 *
	 * @param zwoptexName zwoptex名称
	 * @param count 返回矩形个数
	 * @return 包含所有矩形的缓冲区指针, 调用者要负责释放
	 * \endif
	 */
	wyRect* getFrameRects(const char* zwoptexName, size_t* count);

	/**
	 * \if English
	 * Get a zwoptex frame by name
	 *
	 * @param frameName name of frame
	 * @return \link wyZwoptexFrame wyZwoptexFrame\endlink, or NULL if not found
	 * \else
	 * 根据名称查找一个zwoptex帧
	 *
	 * @param frameName 帧名称
	 * @return \link wyZwoptexFrame wyZwoptexFrame\endlink, 如果没有找到, 返回NULL
	 * \endif
	 */
	wyZwoptexFrame* getZwoptexFrame(const char* frameName);

	/**
	 * \if English
	 * Get a zwoptex frame by name
	 *
	 * @param zwoptexName name of zwoptex
	 * @param frameName name of frame
	 * @return \link wyZwoptexFrame wyZwoptexFrame\endlink, or NULL if not found
	 * \else
	 * 通过名称得到一个zwoptex帧
	 *
	 * @param zwoptexName zwoptex的名称
	 * @param frameName 帧名称
	 * @return \link wyZwoptexFrame wyZwoptexFrame\endlink, 如果没有找到, 返回NULL
	 * \endif
	 */
	wyZwoptexFrame* getZwoptexFrame(const char* zwoptexName, const char* frameName);

	/**
	 * \if English
	 * Get a sprite frame by name
	 *
	 * @param frameName name of frame
	 * @return \link wySpriteFrame wySpriteFrame\endlink, or NULL if not found
	 * \else
	 * 根据名称查找一个\link wySpriteFrame wySpriteFrame\endlink对象, 该方法不需
	 * 要指定zwoptex名称, 因此将搜索所有的zwoptex
	 *
	 * @param frameName 帧名称
	 * @return \link wySpriteFrame wySpriteFrame\endlink, 如果没有找到, 返回NULL
	 * \endif
	 */
	wySpriteFrame* getSpriteFrame(const char* frameName);

	/**
	 * \if English
	 * Get a sprite frame by name
	 *
	 * @param zwoptexName name of zwoptex
	 * @param frameName name of frame
	 * @return \link wySpriteFrame wySpriteFrame\endlink, or NULL if not found
	 * \else
	 * 通过名称得到一个\link wySpriteFrame wySpriteFrame\endlink 对象
	 *
	 * @param zwoptexName zwoptex的名称
	 * @param frameName 帧名称
	 * @return \link wySpriteFrame wySpriteFrame\endlink
	 * \endif
	 */
	wySpriteFrame* getSpriteFrame(const char* zwoptexName, const char* frameName);

	/**
	 * \if English
	 * Create a \link wySprite wySprite\endlink from a frame
	 *
	 * @param zwoptexName name of zwoptex
	 * @param frameName name of frame
	 * @return tex \link wyTexture2D wyTexture2D\endlink. It can be NULL and NULL means using
	 * 		zwoptex texture
	 * @return \link wySprite wySprite\endlink, or NULL if frame is not found
	 * \else
	 * 通过Zwoptex创建一个\link wySprite wySprite\endlink 对象
	 *
	 * @param zwoptexName zwoptex的名称
	 * @param frameName 帧名称
	 * @param tex \link wyTexture2D wyTexture2D\endlink, 可以为NULL，如果为NULL，表示将使用zwoptex本身绑定的贴图,
	 * 		但是如果zwoptex本身没有绑定贴图，则会返回NULL
	 * @return \link wySprite wySprite\endlink 对象，如果没有找到相应名称的zwoptex帧，或者没有贴图对象，则返回NULL
	 * \endif
	 */
	wySprite* makeSprite(const char* zwoptexName, const char* frameName, wyTexture2D* tex = NULL);

	/**
	 * \if English
	 * Create a \link wySprite wySprite\endlink. This method doesn't require zwoptex name so it
	 * will search all zwoptex. You can use it if you already know there is no duplicate frame
	 * name
	 *
	 * @param frameName name of frame
	 * @return \link wySprite wySprite\endlink, or NULL if frame is not found
	 * \else
	 * 通过Zwoptex创建一个\link wySprite wySprite\endlink 对象, 这个方法不指定zwoptex名称，因此会在
	 * 所有的zwoptex中搜索，直到找到一个匹配的为止。如果确定不存在重复名称的帧，可以用这个方法来生成sprite，
	 * 因为代码可以有更好的维护性。
	 *
	 * @param frameName 帧名称
	 * @return \link wySprite wySprite\endlink 对象，如果没有找到相应名称的zwoptex帧，或者没有贴图对象，则返回NULL
	 * \endif
	 */
	wySprite* makeSprite(const char* frameName);

	/**
	 * \if English
	 * Create a \link wyButton wyButton\endlink from a frame
	 *
	 * @param zwoptexName name of zwoptex
	 * @param frameName name of frame
	 * @param ts target selector of this button
	 * @return tex \link wyTexture2D wyTexture2D\endlink. It can be NULL and NULL means using
	 * 		zwoptex texture
	 * @return \link wyButton wyButton\endlink, or NULL if frame is not found
	 * \else
	 * 通过Zwoptex创建一个\link wyButton wyButton\endlink 对象
	 *
	 * @param zwoptexName zwoptex的名称
	 * @param frameName 帧名称
	 * @param ts 按钮上的触摸事件选择子
	 * @param tex \link wyTexture2D wyTexture2D\endlink, 可以为NULL，如果为NULL，表示将使用zwoptex本身绑定的贴图,
	 * 		但是如果zwoptex本身没有绑定贴图，则会返回NULL
	 * @return \link wyButton wyButton\endlink 对象，如果没有找到相应名称的zwoptex帧，或者没有贴图对象，则返回NULL
	 * \endif
	 */
	wyButton* makeButton(const char* zwoptexName, const char* frameName, wyTargetSelector* ts, wyTexture2D* tex = NULL);

	/**
	 * \if English
	 * Create a \link wyButton wyButton\endlink. This method doesn't require zwoptex name so it
	 * will search all zwoptex. You can use it if you already know there is no duplicate frame
	 * name
	 *
	 * @param frameName name of frame
	 * @param ts target selector of this button
	 * @return \link wyButton wyButton\endlink, or NULL if frame is not found
	 * \else
	 * 通过Zwoptex创建一个\link wyButton wyButton\endlink 对象, 这个方法不指定zwoptex名称，因此会在
	 * 所有的zwoptex中搜索，直到找到一个匹配的为止。如果确定不存在重复名称的帧，可以用这个方法来生成sprite，
	 * 因为代码可以有更好的维护性。
	 *
	 * @param frameName 帧名称
	 * @param ts 按钮上的触摸事件选择子
	 * @return \link wyButton wyButton\endlink 对象，如果没有找到相应名称的zwoptex帧，或者没有贴图对象，则返回NULL
	 * \endif
	 */
	wyButton* makeButton(const char* frameName, wyTargetSelector* ts);

	/**
	 * \if English
	 * Create a \link wySpriteEx wySpriteEx\endlink object from a frame
	 *
	 * @param zwoptexName name of zwoptex
	 * @param frameName name of frame
	 * @param tex \link wyTexture2D wyTexture2D\endlink, it can be NULL and NULL means using
	 * 		zwoptex texture
	 * @return \link wySpriteEx wySpriteEx\endlink, or NULL if frame is not found
	 * \else
	 * 通过Zwoptex创建一个\link wySpriteEx wySpriteEx\endlink 对象
	 *
	 * @param zwoptexName zwoptex的名称
	 * @param frameName 帧名称
	 * @param tex \link wyTexture2D wyTexture2D\endlink, 可以为NULL，如果为NULL，表示将使用zwoptex本身绑定的贴图,
	 * 		但是如果zwoptex本身没有绑定贴图，则会返回NULL
	 * @return \link wySpriteEx wySpriteEx\endlink 对象，如果没有找到相应名称的zwoptex帧，或者没有贴图对象，则返回NULL
	 * \endif
	 */
	wySpriteEx* makeSpriteEx(const char* zwoptexName, const char* frameName, wyTexture2D* tex = NULL);

	/**
	 * \if English
	 * Create a \link wySpriteEx wySpriteEx\endlink. This method doesn't require zwoptex name so it
	 * will search all zwoptex. You can use it if you already know there is no duplicate frame
	 * name
	 *
	 * @param frameName name of frame
	 * @return \link wySpriteEx wySpriteEx\endlink, or NULL if frame is not found
	 * \else
	 * 通过Zwoptex创建一个\link wySpriteEx wySpriteEx\endlink 对象, 这个方法不指定zwoptex名称，因此会在
	 * 所有的zwoptex中搜索，直到找到一个匹配的为止。如果确定不存在重复名称的帧，可以用这个方法来生成sprite，
	 * 因为代码可以有更好的维护性。
	 *
	 * @param frameName 帧名称
	 * @return \link wySpriteEx wySpriteEx\endlink 对象，如果没有找到相应名称的zwoptex帧，或者没有贴图对象，则返回NULL
	 * \endif
	 */
	wySpriteEx* makeSpriteEx(const char* frameName);
};

#endif // __wyZwoptexManager_h__
