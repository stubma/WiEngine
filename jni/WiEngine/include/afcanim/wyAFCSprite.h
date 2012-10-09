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
#ifndef __wyAFCSprite_h__
#define __wyAFCSprite_h__

#include "wyNode.h"
#include "wySpriteBatchNode.h"
#include "wyAFCAnimation.h"
#include "wyAFCFileData.h"
#include "wyAFCClipMapping.h"
#include "wyArray.h"
#if ANDROID
	#include <jni.h>
#endif

class wyAFCSprite;

/**
 * @struct wyAFCSpriteCallback
 *
 * \if English
 * Callback interface of \link wyAFCSprite wyAFCSprite\endlink
 * \else
 * \link wyAFCSprite wyAFCSprite\endlink 的回调定义
 * \endif
 */
typedef struct WIENGINE_API wyAFCSpriteCallback {
	/**
	 * \if English
	 * Invoked when frame changed
	 *
	 * @param sprite \link wyAFCSprite wyAFCSprite\endlink
	 * @param data extra data pointer
	 * \else
	 * 动画帧已经改变
	 *
	 * @param sprite \link wyAFCSprite wyAFCSprite\endlink
	 * @param data 附加数据指针
	 * \endif
	 */
	void (*onAFCAnimationFrameChanged)(wyAFCSprite* sprite, void* data);

	/**
	 * \if English
	 * Invoked when animation ended
	 *
	 * @param sprite \link wyAFCSprite wyAFCSprite\endlink
	 * @param data extra data pointer
	 * \else
	 * 动画已经结束
	 *
	 * @param sprite \link wyAFCSprite wyAFCSprite\endlink
	 * @param data 附加数据指针
	 * \endif
	 */
	void (*onAFCAnimationEnded)(wyAFCSprite* sprite, void* data);
} wyAFCSpriteCallback;

/**
 * @class wyAFCSprite
 *
 * \if English
 * \par
 * AFC means Animation, Frame, Clip and it is an architecture of frame animation. That is
 * to say, animation consists of frame and frame consists of fragment. This architecture
 * is common and many animation editors support it. Purpose of \link wyAFCSprite wyAFCSprite\endlink
 * is encapsulating the common logic for all AFC editors.
 *
 * \par
 * For other editors, terms may differ but meaning is similar. For example:
 * \li Motion Welder: it calls AFC
 * \li SpriteX: it calls AFT: Action, Frame, Tile
 * \li Arctic & AuroraGT: it calls AFM: Animation, Frame, Module
 * Motion Welder is first animation editor supported by WiEngine, so we use AFC as a souvenir.
 *
 * \par
 * Some complex transformation is not supported, such as clip rotation and animation rotation.
 * Those features are not important.
 *
 * \par
 * Duration time of frame has two measurement: by time or by tick. Some editor, likes Motion Welder, Arctic,
 * etc. uses an integer as frame duration. The integer is a tick count, not time, so animation will be faster
 * if device has higher frame rate. In \link wyAFCSprite wyAFCSprite\endlink, there is an unit interval can be
 * set and if it is not zero, the final duration time will be the result of multiply tick and unit interval.
 * By default it is zero and it means using tick directly.
 *
 * \par
 * \link wyAFCSprite wyAFCSprite\endlink subclass has a zero size so you can't perform collision detection
 * based on node size. \link wyAFCSprite wyAFCSprite\endlink provides \c getFrameRect methods to return a
 * minimum rectangle containing all clips of current frame
 * \else
 * \par
 * AFC的含义是Animation, Frame, Clip, 它代表了一种常见的动画架构, 即动画由帧组成, 而帧由分片组成
 * 的动画数据结构. 这种动画数据结构在逐帧动画中应用的比较普遍, 相关的编辑器也很多. 而\link wyAFCSprite wyAFCSprite\endlink的
 * 目的就是封装此类动画逻辑, 做到用一套代码适应不同编辑器的目的.
 *
 * \par
 * 对于不同的编辑器, 其相关术语可能叫法不同, 但是含义基本类似. 这里的Animation, Frame和Clip是动画编辑
 * 器Motion Welder的叫法, 对于其它的编辑器, 如:
 * \li SpriteX: 按照AFC的排列顺序, 它的叫法是Action, Frame, Tile
 * \li Arctic & AuroraGT: 按照AFC的排列顺序, 它的叫法是Animation, Frame, Module
 * 之所以采用Motion Welder的叫法, 是因为Motion Welder是WiEngine支持的第一款动画编辑器, 作为纪念所以命名此类动画为AFC动画
 *
 * \par
 * 对于某些复杂的功能(比如分片图片本身是旋转的或者动画本身有旋转属性), 目前并不支持. 这些旋转功能并非必要的特性, 由于AFC是一个
 * 通用架构, 且需要遵守节点本身的架构, 为避免过于复杂的转换, 目前并不支持这些特性.
 *
 * \par
 * 一个动画帧的持续时间在AFC架构中有两种表示方式, 即按照时间或按照帧表示. 有些编辑器, 比如Motion Welder, Arctic等, 并不存放
 * 一个动画帧的实际显示时间, 而是使用一个无单位的整数, 用来表示这个动画帧应该在几帧内保持可见. 因此, 如果机器渲染速度越快, 则
 * 动画帧可见的时间就越短. \link wyAFCSprite wyAFCSprite\endlink提供了第三种选择, 可以设置一个单位时间间隔, 从而可以调整
 * 按帧显示动画的播放速度, 从而将按帧显示变成按时间显示. 缺省情况下单位时间间隔是0, 表示忽略该设置, 使用按帧显示.
 *
 * \par
 * \link wyAFCSprite wyAFCSprite\endlink及其子类都是没有大小的, 即它们的尺寸都是0, 因此不能通过节点大小来判断碰撞.
 * \link wyAFCSprite wyAFCSprite\endlink提供了getFrameRect等方法可以返回当前帧相对于节点位置的矩形, 但是要注意, 这些
 * 方法只是计算包含所有分片的最小矩形.
 * \endif
 */
class WIENGINE_API wyAFCSprite : public wyNode {
protected:
	/**
	 * \if English
	 * \link wySpriteEx wySpriteEx\endlink list for every clip
	 * \else
	 * 给分片使用的\link wySpriteEx wySpriteEx\endlink列表
	 * \endif
	 */
	wyArray* m_spriteList;

	/**
	 * \if English
	 * List of \link wySpriteBatchNode wySpriteBatchNode\endlink
	 * \else
	 * 关联的\link wySpriteBatchNode wySpriteBatchNode\endlink 对象列表
	 * \endif
	 */
	wyArray* m_sheetList;

	/**
	 * \if English
	 * List of \link wyAFCClipMapping wyAFCClipMapping\endlink
	 * \else
	 * 关联的\link wyAFCClipMapping wyAFCClipMapping\endlink对象类别
	 * \endif
	 */
	wyArray* m_mappingList;

	/**
	 * \if English
	 * data of current AFC animation
	 * \else
	 * 当前正在播放的动画数据
	 * \endif
	 */
	wyAFCAnimation* m_animationData;

	/**
	 * \if English
	 * Index of current animation
	 * \else
	 * 当前正在播放的动画的索引
	 * \endif
	 */
	int m_curAnimationIndex;

	/**
	 * \if English
	 * Index of current frame
	 * \else
	 * 当前的帧索引
	 * \endif
	 */
	int m_curFrame;

	/**
	 * \if English
	 * frame count of current animation
	 * \else
	 * 当前动画的总帧数
	 * \endif
	 */
	int m_numOfFrame;

	/**
	 * \if English
	 * duration time of current frame
	 * \else
	 * 当前帧的持续时间
	 * \endif
	 */
	float m_frameDuration;

	/**
	 * \if English
	 * true means \c m_frameDuration is a tick value, not time
	 * \else
	 * true表示\c m_frameDuration不是一个时间, 而是一个帧数
	 * \endif
	 */
	bool m_isTickDelay;

	/**
	 * \if English
	 * true means use frame mode to play animation forever, default is false
	 * \else
	 * true表示强行使用帧模式播放动画, 即使动画编辑器只支持时间模式, 缺省是false
	 * \endif
	 */
	bool m_forceTickMode;

	/**
	 * \if English
	 * accumulated offset till to current frame
	 * \else
	 * 累积的帧偏移
	 * \endif
	 */
	wyPoint m_frameOffset;

	/**
	 * \if English
	 * true indicating ignore frame offset, default is false
	 * \else
	 * true表示忽略帧偏移，所有的帧都在同样的位置播放, 缺省是false
	 * \endif
	 */
	bool m_ignoreFrameOffset;

	/**
	 * \if English
	 * Time elapsed of current frame, should switch to next frame if it is larger than \c m_frameDuration
	 * \else
	 * 当前帧已经过去的时间, 当这个时间大于m_frameDuration时, 就该切换到下一帧了
	 * \endif
	 */
	float m_elapsed;

	/**
	 * \if English
	 * Unit interval of animation frame. Default unit interval is 0 so it means don't use unit
	 * interval.
	 * \else
	 * 帧的单位时间. 缺省这个值是0, 表示不要使用单位时间, 而是使用编辑器本身的方式
	 * \endif
	 */
	float m_unitInterval;

	/**
	 * \if English
	 * reverse playing flag
	 * \else
	 * true表示倒放动画
	 * \endif
	 */
	bool m_isReverse;

	/**
	 * -1 means loop forever
	 * 0 means don't loop
	 * > 0 means loop count
	 */
	int m_loop;

	/// a helper variable of looping
	int m_tmpLoop;

	/**
	 * \if English
	 * true means animation is over
	 * \else
	 * true表示动画已经结束
	 * \endif
	 */
	bool m_isAnimationEnded;

	/**
	 * \if English
	 * true means animation is paused
	 * \else
	 * true表示动画暂停
	 * \endif
	 */
	bool m_paused;

	/**
	 * \if English
	 * If set to true, frame rect will be drawn, for debug purpose
	 * \else
	 * 如果为true, 则会渲染出当前帧的矩形, 用于调试目的
	 * \endif
	 */
	bool m_debugDrawFrameRect;

	/**
	 * \if English
	 * If set to true, collision rect will be drawn, for debug purpose
	 * \else
	 * 如果为true, 则会渲染出当前帧的碰撞矩形, 用于调试目的
	 * \endif
	 */
	bool m_debugDrawCollisionRect;

	/**
	 * \if English
	 * true means x axis should be flipped
	 * \else
	 * true表示翻转x轴
	 * \endif
	 */
	bool m_flipX;

	/**
	 * \if English
	 * true means y axis should be flipped
	 * \else
	 * true表示翻转y轴
	 * \endif
	 */
	bool m_flipY;

	/**
	 * \if English
	 * color when renderring
	 * \else
	 * 颜色\link wyColor4B wyColor4B结构\endlink
	 * \endif
	 */
	wyColor4B m_color;

	/// blend function
    wyBlendFunc m_blendFunc;

	/**
	 * \if English
	 * callback
	 * \else
	 * 回调
	 * \endif
	 */
	wyAFCSpriteCallback* m_callback;

#if ANDROID
	/**
	 * \if English
	 * callback of java side
	 * \else
	 * java层设置的回调
	 * \endif
	 */
	jobject m_jCallback;
#endif

	/**
	 * \if English
	 * extra data pointer of native callback
	 * \else
	 * native回调的附加数据指针
	 * \endif
	 */
	void* m_data;

private:
	static bool releaseObject(wyArray* arr, void* ptr, int index, void* data);

	void invokeOnAFCAnimationFrameChanged();
	void invokeOnAFCAnimationEnded();

protected:
	wyAFCSprite();

	/**
	 * \if English
	 * Set animation data
	 *
	 * @param data \link wyAFCAnimation wyAFCAnimation\endlink
	 * \else
	 * 设置动画数据
	 *
	 * @param data \link wyAFCAnimation wyAFCAnimation\endlink
	 * \endif
	 */
	void setAnimationData(wyAFCAnimation* data);

	/**
	 * \if English
	 * Create sprite pool for current animation
	 * \else
	 * 根据当前动画数据创建必要的\link wySpriteEx wySpriteEx\endlink 对象
	 * \endif
	 */
	void initSpriteFromAnimationData();

	/**
	 * \if English
	 * Initialize frame offset at start of animation
	 * \else
	 * 初始化帧偏移
	 * \endif
	 */
	void initFrameOffset();

	/**
	 * \if English
	 * Adjust frame offset for a frame
	 *
	 * @param frameData \link wyAFCFrame wyAFCFrame\endlink
	 * \else
	 * 调整帧偏移
	 *
	 * @param frameData \link wyAFCFrame wyAFCFrame\endlink
	 * \endif
	 */
	void adjustFrameOffset(wyAFCFrame* frameData);

	/**
	 * \if English
	 * update color of sprites
	 * \else
	 * 批量更新颜色
	 * \endif
	 */
	void updateColor();

public:
	virtual ~wyAFCSprite();

	/// @see wyNode::getAlpha
	virtual int getAlpha() { return m_color.a; }

	/// @see wyNode::setAlpha
	virtual void setAlpha(int alpha);

	/// @see wyNode::getColor
	virtual wyColor3B getColor();

	/// @see wyNode::setColor
	virtual void setColor(wyColor3B color);

	/// @see wyNode::setColor
	virtual void setColor(wyColor4B color);

	/// @see wyNode::getBlendFunc
	virtual wyBlendFunc getBlendFunc() { return m_blendFunc; }

	/// @see wyNode::setBlendFunc
	virtual void setBlendFunc(wyBlendFunc func);

	/// @see wyNode::visit()
	virtual void visit();

	/// @see wyNode::draw()
	virtual void draw();

	/// @see wyNode::addChild(wyNode*, int, int)
	virtual void addChild(wyNode* child, int z, int tag);

	/**
	 * \if English
	 * Get file data object
	 *
	 * @return \link wyAFCFileData wyAFCFileData\endlink object
	 * \else
	 * 得到文件数据对象, 文件数据对象是比动画数据对象更高一级的数据对象, 因为一个文件
	 * 中可能包含多个动画
	 *
	 * \note
	 * 返回的结构中的数据都是没有经过自动缩放的, 即原始的描述文件中的数据
	 *
	 * @return \link wyAFCFileData wyAFCFileData\endlink
	 * \endif
	 */
	virtual wyAFCFileData* getFileData() = 0;

	/**
	 * \if English
	 * Get animation at specified index
	 *
	 * @param index animation index
	 * @param mapping clip mapping, default is NULL
	 * \else
	 * 得到指定索引位置的动画数据
	 *
	 * @param index 动画索引
	 * @param mapping 分片映射规则对象, 缺省为NULL表示没有
	 * \endif
	 */
	virtual wyAFCAnimation* getAnimationAt(int index, wyAFCClipMapping* mapping = NULL) = 0;

	/**
	 * \if English
	 * Get animation count
	 *
	 * @return animation count
	 * \else
	 * 得到动画总数
	 *
	 * @return 动画总数
	 * \endif
	 */
	virtual int getAnimationCount() = 0;

	/**
	 * \if English
	 * Get image count
	 *
	 * @return image count
	 * \else
	 * 得到图片集的个数
	 *
	 * @return 图片集个数
	 * \endif
	 */
	virtual int getImageCount() = 0;

	/**
	 * \if English
	 * Play an animation, it will immediately end current animation (if has)
	 *
	 * \note
	 * Currently, clip mapping doesn't support SpriteX 2011 and Motion Welder
	 *
	 * @param index index of animation
	 * @param mapping clip mapping, default is NULL. A clip mapping must be added
	 * 		to \link wyAFCSprite wyAFCSprite\endlink before use it in \c playAnimation
	 * \else
	 * 开始播放动画
	 *
	 * \note
	 * 分片映射不支持SpriteX 2011和Motion Welder
	 *
	 * @param index 动画索引
	 * @param mapping 分片映射规则对象, 缺省为NULL表示没有. 一个分片映射被正式用来播放之前, 必须添加
	 * 		到\link wyAFCSprite wyAFCSprite\endlink中
	 * \endif
	 */
	void playAnimation(int index, wyAFCClipMapping* mapping = NULL);

	/**
	 * \if English
	 * Play an animation and apply a clip mapping to it
	 *
	 * @param index index of animation
	 * @param mappingTag tag of clip mapping
	 * \else
	 * 播放动画, 同时对这套动画应用一套分片映射规则
	 *
	 * @param index 动画索引
	 * @param mappingTag 分片映射规则的标签
	 * \endif
	 */
	void playAnimation(int index, int mappingTag);

	/**
	 * \if English
	 * Set current frame index
	 *
	 * @param index frame index
	 * \else
	 * 设置当前帧
	 *
	 * @param index 帧索引
	 * \endif
	 */
	void setFrameIndex(int index);

	/**
	 * \if English
	 * Update animation by a delta time. Must be called continuously and usually you
	 * can schedule a timer to invoke it.
	 *
	 * @param delta time from last update
	 * \else
	 * 更新一次动画，这个方法应该要被连续调用，可以调度一个定时器用来
	 * 不停的调用tick方法，这样就可以形成动画效果了。
	 *
	 * @param delta 上一次调用到本次调用的时间
	 * \endif
	 */
	void tick(float delta);

	/**
	 * \if English
	 * Set ignore frame offset when rendering or not
	 *
	 * \note
	 * Not all editor support it. Generally speaking, if editor support frame
	 * offset, then clip position must be relative to frame, not animation. For now,
	 * Motion Welder and Arctic support it.
	 *
	 * @param flag true means ignore frame offset
	 * \else
	 * 设置是否忽略帧偏移，帧偏移可以造成动画前进的效果，如果忽略掉就会变成原地动画.
	 * 这个标志只影响渲染时是否考虑帧偏移, 对于帧偏移的计算仍然进行, 因此不影响获得帧偏移
	 *
	 * \note
	 * 并不是所有的编辑器都支持这个设置, 一般来说, 如果编辑器支持这个设置. 那么分片的位置应该是
	 * 相对于帧, 而不是相对于动画的. 在目前WiEngine支持的编辑器中, Motion Welder和Arctic是这样
	 * 的.
	 *
	 * @param flag true表示忽略帧偏移
	 * \endif
	 */
	void setIgnoreFrameOffset(bool flag) { m_ignoreFrameOffset = flag; }

	/**
	 * \if English
	 * is frame offset ignored?
	 *
	 * @return true means frame offset is ignored
	 * \else
	 * 是否忽略帧偏移. 这个标志只影响渲染时是否考虑帧偏移, 对于帧偏移的计算仍然
	 * 进行, 因此不影响获得帧偏移
	 *
	 * @return true表示忽略帧偏移
	 * \endif
	 */
	bool isIgnoreFrameOffset() { return m_ignoreFrameOffset; }

	/**
	 * \if English
	 * Get current frame offset
	 *
	 * @param current frame offset
	 * \else
	 * 得到当前帧偏移，这个偏移值是当前帧和第一帧的总偏移. 即使设置了在动画播放时忽略
	 * 帧偏移, 仍然可以获得当前帧偏移数据
	 *
	 * @return \link wyPoint wyPoint\endlink
	 * \endif
	 */
	wyPoint getFrameOffset() { return m_frameOffset; }

	/**
	 * \if English
	 * Set animation event callback
	 *
	 * @param callback \link wyAFCSpriteCallback wyAFCSpriteCallback\endlink, if NULL, means clear callback
	 * @param data extra data pointer
	 * \else
	 * 设置动画事件的回调
	 *
	 * @param callback \link wyAFCSpriteCallback wyAFCSpriteCallback\endlink 结构，如果为NULL, 表示清除之前设置的callback
	 * @param data 附加数据指针，可选参数，缺省为NULL
	 * \endif
	 */
	void setAFCSpriteCallback(wyAFCSpriteCallback* callback, void* data = NULL);

#if ANDROID
	/**
	 * \if English
	 * Set java side callback, if null, means clear callback
	 *
	 * @param callback java side callback object
	 * \else
	 * 设置一个java端的回调，如果为null，表示清除之前的回调
	 *
	 * @param callback java端的回调对象
	 * \endif
	 */
	void setAFCSpriteCallback(jobject callback);
#endif

	/**
	 * \if English
	 * Get current animation index
	 *
	 * @return current animation index
	 * \else
	 * 得到当前的动画索引
	 *
	 * @return 当前的动画索引, 假如anu文件里有3个动画, 当然正在播放第2个, 那么索引是1
	 * \endif
	 */
	int getCurrentAnimationIndex() { return m_curAnimationIndex; }

	/**
	 * \if English
	 * Get current frame index
	 *
	 * @return current frame index
	 * \else
	 * 得到正在播放的帧在当前动画中的索引
	 *
	 * @return 正在播放的帧在当前动画中的索引, 比如动画包含5帧, 正在播放第3帧, 则应该返回2
	 * \endif
	 */
	int getCurrentFrame() { return m_curFrame; }

	/**
	 * \if English
	 * Get frame count of current animation
	 *
	 * @return frame count of current animation
	 * \else
	 * 得到当前动画的帧数
	 *
	 * @return 当前动画的帧数
	 * \endif
	 */
	int getFrameCount() { return m_numOfFrame; }

	/**
	 * \if English
	 * is reverse playing?
	 *
	 * @return true means reverse playing
	 * \else
	 * 是否倒序播放
	 *
	 * @return true表示倒序播放动画
	 * \endif
	 */
	bool isReverse() { return m_isReverse; }

	/**
	 * \if English
	 * Set reverse playing or not
	 *
	 * @param flag true means reverse playing
	 * \else
	 * 设置是否倒序播放
	 *
	 * @param flag true表示倒序播放动画
	 * \endif
	 */
	void setReverse(bool flag) { m_isReverse = flag; }

	/**
	 * \if English
	 * Get loop count
	 *
	 * @return -1 means loop forever, 0 means no loop, larger than 0 means loop times
	 * \else
	 * 得到循环次数
	 *
	 * @return -1表示无限循环, 0表示不循环, 大于0表示循环次数
	 * \endif
	 */
	int getLoopCount() { return m_loop; }

	/**
	 * \if English
	 * Set loop count
	 *
	 * @param loop loop count, -1 means loop forever, 0 means no loop, larger than 0 means loop times
	 * \else
	 * 设置循环次数
	 *
	 * @param loop 循环次数, -1表示无限循环, 0表示不循环, 大于0表示循环次数
	 * \endif
	 */
	void setLoopCount(int loop);

	/**
	 * \if English
	 * is animation ended
	 *
	 * @return true means animation is ended
	 * \else
	 * 当前动画是否已经结束, 如果设置了循环播放, 则该标志永不为true
	 *
	 * @return 当前动画是否已经结束
	 * \endif
	 */
	bool isAnimationEnded() { return m_isAnimationEnded; }

	/**
	 * \if English
	 * is animation flipped in x axis?
	 *
	 * @return true means animation is flipped in x axis
	 * \else
	 * 动画播放时是否翻转x轴
	 *
	 * @return true表示动画播放时翻转x轴
	 * \endif
	 */
	bool isFlipX() { return m_flipX; }

	/**
	 * \if English
	 * Make animation flipped in x axis or not
	 *
	 * @param flipX true means animation should be flipped in x axis
	 * \else
	 * 设置动画播放时是否翻转x轴
	 *
	 * @param flipX true表示动画播放时翻转x轴
	 * \endif
	 */
	void setFlipX(bool flipX);

	/**
	 * \if English
	 * is animation flipped in y axis?
	 *
	 * @return true means animation is flipped in y axis
	 * \else
	 * 动画播放时是否翻转y轴
	 *
	 * @return true表示动画播放时翻转y轴
	 * \endif
	 */
	bool isFlipY() { return m_flipY; }

	/**
	 * \if English
	 * Make animation flipped in y axis or not
	 *
	 * @param flipY true means animation should be flipped in y axis
	 * \else
	 * 设置动画播放时是否翻转y轴
	 *
	 * @param flipY true表示动画播放时翻转y轴
	 * \endif
	 */
	void setFlipY(bool flipY);

	/**
	 * \if English
	 * Pause animation or not
	 *
	 * @param flag true means pause animation
	 * \else
	 * 设置是否暂停动画播放
	 *
	 * @param flag true表示暂停
	 * \endif
	 */
	void setPaused(bool flag) { m_paused = flag; }

	/**
	 * \if English
	 * is animation paused
	 *
	 * @return true means paused
	 * \else
	 * 动画是否已经暂停
	 *
	 * @return true表示动画已暂停
	 * \endif
	 */
	bool isPaused() { return m_paused; }

	/**
	 * \if English
	 * Get data of current animation
	 *
	 * \node
	 * Returned info is auto scaled by WiEngine on the basis of density
	 *
	 * @return \link wyAFCAnimation wyAFCAnimation\endlink
	 * \else
	 * 得到当前正在播放的动画数据结构, 即\link wyAFCAnimation wyAFCAnimation\endlink结构,
	 * 从这个结构可以得到一个动画的所有信息
	 *
	 * \note
	 * 返回的结构中的信息都是经过了WiEngine自动缩放的, 即考虑了anu文件的密度和屏幕密度进行了
	 * 自动的转换
	 *
	 * @return \link wyAFCAnimation wyAFCAnimation\endlink
	 * \endif
	 */
	wyAFCAnimation* getCurrentAnimationData() { return m_animationData; }

	/**
	 * \if English
	 * Get unit interval time
	 *
	 * @return unit interval time
	 * \else
	 * 得到帧间间隔单位时间
	 *
	 * @return 帧间间隔单位时间
	 * \endif
	 */
	float getUnitInterval() { return m_unitInterval; }

	/**
	 * \if English
	 * Set unit interval time. If value is not zero and animation editor uses tick value, then
	 * final duration time is result of multiply unit interval and tick value
	 *
	 * @param interval unit interval time
	 * \else
	 * 设置帧间间隔单位时间. 如果这个值不是0, 且编辑器使用帧来表示帧持续时间, 则最终的持续时间将是单位间隔
	 * 时间和帧的乘积.
	 *
	 * @param interval 帧间间隔单位时间
	 * \endif
	 */
	void setUnitInterval(float interval);

	/**
	 * \if English
	 * Is animation played in tick mode? That means frame duration is measured by drawing frame and
	 * its speed can be controlled by unit interval
	 *
	 * @return true means animation is played in tick mode
	 * \else
	 * 是否动画按照帧模式进行播放, 帧模式表示动画帧的持续时间由渲染帧率决定, 意味着其播放速度可
	 * 通过单位间隔时间控制速度
	 *
	 * @return true表示动画播放采用帧模式
	 * \endif
	 */
	bool isForceTickMode() { return m_forceTickMode; }

	/**
	 * \if English
	 * Set use tick mode or time mode to play animation
	 *
	 * @param flag true means use tick mode
	 * \else
	 * 设置使用帧模式还是时间模式来播放动画
	 *
	 * @param flag true表示使用帧模式
	 * \endif
	 */
	void setForceTickMode(bool flag) { m_forceTickMode = flag; }

	/**
	 * \if English
	 * Get total number of collision rectangle in current frame
	 * \else
	 * 得到当前帧中的碰撞矩形个数
	 * \endif
	 */
	int getCollisionRectCount();

	/**
	 * \if English
	 * Get collision rect of current frame, in node coordinates
	 *
	 * @param index index of collision rect
	 * @return \link wyRect wyRect\endlink, if no collision rect in current frame or
	 * 		\c index is invalid, return a zero rect
	 * \else
	 * 得到当前帧的碰撞矩形, 返回的矩形坐标是相对于节点本身的
	 *
	 * @return index 碰撞矩形的索引, 0表示第一个, 1表示第二个
	 * @return \link wyRect wyRect\endlink, 如果当前帧没有碰撞矩形或者\c index值无效, 返回一个零大小的矩形
	 * \endif
	 */
	wyRect getCollisionRect(int index);

	/**
	 * \if English
	 * Get collision rect of current frame, in parent node coordinates. If node has rotation, then
	 * returned rectangle may be a circumscribed rectangle
	 *
	 * @param index index of collision rect
	 * @return \link wyRect wyRect\endlink, if no collision rect in current frame or
	 * 		\c index is invalid, return a zero rect
	 * \else
	 * 得到当前帧的碰撞矩形, 返回的矩形坐标是相对于父节点坐标系的. 如果节点自身有旋转, 则返回的可能是一个
	 * 外接矩形
	 *
	 * @return index 碰撞矩形的索引, 0表示第一个, 1表示第二个
	 * @return \link wyRect wyRect\endlink, 如果当前帧没有碰撞矩形或者\c index值无效, 返回一个零大小的矩形
	 * \endif
	 */
	wyRect getCollisionRectRelativeToParent(int index);

	/**
	 * \if English
	 * Get collision rect of current frame, in global coordinates. If node has rotation, then
	 * returned rectangle may be a circumscribed rectangle
	 *
	 * @param index index of collision rect
	 * @return \link wyRect wyRect\endlink, if no collision rect in current frame or
	 * 		\c index is invalid, return a zero rect
	 * \else
	 * 得到当前帧的碰撞矩形, 返回的矩形坐标是相对于全局坐标系的. 如果节点自身有旋转, 则返回的可能是一个
	 * 外接矩形
	 *
	 * @return index 碰撞矩形的索引, 0表示第一个, 1表示第二个
	 * @return \link wyRect wyRect\endlink, 如果当前帧没有碰撞矩形或者\c index值无效, 返回一个零大小的矩形
	 * \endif
	 */
	wyRect getCollisionRectRelativeToWorld(int index);

	/**
	 * \if English
	 * Get current frame bound relative to sprite node. It returns a minimum rectangle which
	 * contains all clips
	 *
	 * @return minimum rectangle which contains all clips, relative to node coordinates
	 * \else
	 * 得到当前帧的矩形范围
	 *
	 * @return 包含当前帧分片的最小矩形, 其坐标是相对于节点本身坐标系的
	 * \endif
	 */
	wyRect getFrameRect();

	/**
	 * \if English
	 * Get current frame bound relative to parent node. It returns a minimum rectangle
	 * which contains all clips
	 *
	 * @return minimum rectangle which contains all clips, relative to parent node
	 * 		coordinates
	 * \else
	 * 得到当前帧的矩形范围
	 *
	 * @return 包含当前帧分片的最小矩形, 其坐标是相对于父节点坐标系的
	 * \endif
	 */
	wyRect getFrameRectRelativeToParent();

	/**
	 * \if English
	 * Get current frame bound relative to world. It returns a minimum rectangle
	 * which contains all clips
	 *
	 * @return minimum rectangle which contains all clips, relative to global coordinates
	 * \else
	 * 得到当前帧的矩形范围
	 *
	 * @return 包含当前帧分片的最小矩形, 其坐标是相对于全局坐标系的
	 * \endif
	 */
	wyRect getFrameRectRelativeToWorld();

	/**
	 * \if English
	 * Set debug draw flag of drawing frame rect
	 *
	 * @param flag true means frame rect will be drawn, for debug purpose
	 * \else
	 * 设置是否渲染出当前帧的矩形, 用于调试目的
	 *
	 * @param flag true表示渲染出当前帧矩形
	 * \endif
	 */
	void setDebugDrawFrameRect(bool flag) { m_debugDrawFrameRect = flag; }

	/**
	 * \if English
	 * Set debug draw flag of drawing collision rect
	 *
	 * @param flag true means collision rect will be drawn, for debug purpose
	 * \else
	 * 设置是否渲染出当前帧的碰撞矩形, 用于调试目的
	 *
	 * @param flag true表示渲染出当前帧的碰撞矩形
	 * \endif
	 */
	void setDebugDrawCollisionRect(bool flag) { m_debugDrawCollisionRect = flag; }

	/**
	 * \if English
	 * Add a clip mapping to this sprite, which can be used later in \c playAnimation
	 *
	 * @param mapping \link wyAFCClipMapping wyAFCClipMapping\endlink
	 * \else
	 * 为当前精灵添加一组分片映射规则, 添加了之后可以通过\c playAnimation使用
	 *
	 * @param mapping \link wyAFCClipMapping wyAFCClipMapping\endlink
	 * \endif
	 */
	void addClipMapping(wyAFCClipMapping* mapping);

	/**
	 * \if English
	 * Remove a clip mapping by its tag
	 *
	 * @param tag tag of clip mapping
	 * \else
	 * 根据tag删除一套分片映射规则
	 *
	 * @param tag 分片映射规则的tag
	 * \endif
	 */
	void removeClipMappingByTag(int tag);

	/**
	 * \if English
	 * Get a clip mapping by tag
	 *
	 * @param tag tag of clip mapping
	 * @return clip mapping or NULL if not found
	 * \else
	 * 根据tag得到分片映射规则对象
	 *
	 * @param tag 分片映射规则tag
	 * @return 分片映射规则对象, 如果没找到返回NULL
	 * \endif
	 */
	wyAFCClipMapping* getClipMappingByTag(int tag);

	/**
	 * \if English
	 * Replace current textures with another set of textures. You must ensure
	 * the new set of textures has same size and quantity as old set.
	 *
	 * @param tex texture 1, other textures can follow it and NULL ends
	 * \else
	 * 整体替换掉所有贴图, 这个方法也可用于换装. 但是你必须保证新贴图与老贴图的大小数量都相同
	 *
	 * @param tex 贴图1, 其它的贴图跟在后面, 以NULL结尾
	 * \endif
	 */
	void replaceTextures(wyTexture2D* tex, ...);

	/**
	 * \if English
	 * Replace current textures with another set of textures. You must ensure
	 * the new set of textures has same size and quantity as old set.
	 *
	 * @param tex texture list
	 * @param count texture count in \tex
	 * \else
	 * 整体替换掉所有贴图, 这个方法也可用于换装. 但是你必须保证新贴图与老贴图的大小数量都相同
	 *
	 * @param tex 贴图列表
	 * @param count \c tex中的贴图个数
	 * \endif
	 */
	void replaceTextures(wyTexture2D** tex, int count);
};

#endif // __wyAFCSprite_h__
