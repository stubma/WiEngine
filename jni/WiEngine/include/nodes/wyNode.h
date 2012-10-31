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
#ifndef __wyNode_h__
#define __wyNode_h__

#include "WiEngine-Classes.h"
#include <stdbool.h>
#include "wyAction.h"
#include "wyTypes.h"
#include "wyEvents.h"
#include "wyArray.h"
#include "wyTargetSelector.h"
#include "wyRenderQueue.h"
#include "wyRenderState.h"

#define INVALID_TAG -1

/**
 * @struct wyNodePositionListener
 *
 * 用来监听节点位置变化的回调接口, 当setPosition方法被调用时, 这个
 * 回掉会被触发
 */
typedef struct wyNodePositionListener {
	/**
	 * 当位置变化时, 该方法被调用
	 *
	 * @param node \link wyNode wyNode\endlink
	 * @param data 附加数据指针
	 */
	void (*onPositionChanged)(wyNode* node, void* data);
} wyNodePositionListener;

/**
 * An interface used to match render pair
 */
class WIENGINE_API wyRenderPairSelector {
public:
	/**
	 * Compare render pair
	 *
	 * @param mat material
	 * @param mesh mesh
	 * @param data extra data passed in by caller
	 * @return true means this render pair matched
	 */
	virtual bool selectRenderPair(wyMaterial* mat, wyMesh* mesh, void* data) = 0;
};

/**
 * @class wyNode
 *
 * 节点对象的封装,是所有节点的基类
 */
class WIENGINE_API wyNode : public wyObject {
	friend class wyEventDispatcher;

private:
	/// touch state of a node
	struct wyTouchState {
		/// pointer id list, max capacity is five
		int pid[5];

		/// touch pointer count
		int count;
	};

public:
	/// render pair info
	struct RenderPair {
		/// material
		wyMaterial* material;

		/// mesh
		wyMesh* mesh;

		/// level of detail
		int lod;
	};

private:
    /// 触摸事件状态
	wyTouchState m_state;

protected:
	/// render bucket
	wyRenderQueue::Bucket m_queueBucket;

	/// 转换矩阵，用来转换到父节点矩阵值
	wyAffineTransform m_transformMatrix;

	/// 转换矩阵，用来从父节点矩阵值转换到自身矩阵
	wyAffineTransform m_inverseMatrix;

	/// 矩阵转换脏标记，标识矩阵值需要重新计算
	bool m_transformDirty;

	/// 翻转脏标记，标识需要重新计算
	bool m_inverseDirty;

	/// 标识当前对象是否可用状态,true可用状态
	bool m_enabled;

	/// 标识当前对象是否选中状态,true选中状态
	bool m_selected;

	/// 标识当前对象是否可见,true可见
	bool m_visible;

	/// 表示当前节点是否获得焦点, true获得状态
	bool m_focused;

	/// 标识当前对象是否需要画,true为不绘画
	bool m_noDraw;

	/// 是否position和anchor position分离,true表示不分离，false表示分离
	bool m_relativeAnchorPoint;

	/// 标识当前对象是否是激活状态,一般在onEnter之后设置,true为激活状态
	bool m_running;

	/// 标识当前对象是否监听触摸事件,true为监听
	bool m_touchEnabled;

	/// 标识当前对象是否监听键盘事件,true为监听
	bool m_keyEnabled;

	/// 标识当前对象是否监听加速事件,true为监听
	bool m_accelerometerEnabled;

	/// 标识当前对象是否监听手势事件,true为监听
	bool m_gestureEnabled;

	/// 标识当前对象是否监听双击事件,true为监听
	bool m_doubleTabEnabled;

	/**
	 * true表示在多点触摸的情况下, 节点也可以触发点击事件. 每个节点都可以设置按下的
	 * selector, 松开的selector, 移除的selector等, 缺省情况下, 这些selector只在
	 * 第一个触点在节点范围内时才会触发. 但是如果第一个触点没有点中节点, 第二个触点
	 * 点中了, 这种情况下如果也希望selector被触发, 则可以设置该标志为true.
	 *
	 * \par
	 * 如果第一个触点和第二个触点都点中了节点会怎么样呢? down selector和up selector
	 * 都只会触发一次
	 *
	 * \par
	 * 而对于move out selector, 只要有一个触点在节点范围内, 就不会被触发
	 */
	bool m_multiTouchClickable;

	/**
	 * true表示当这个节点处理了触摸事件时, 返回true, 则后面的节点将无法收到事件.
	 * 如果为false, 则当前节点返回false, 后面的节点还有机会处理事件. 缺省是
	 * true
	 */
	bool m_interceptTouch;

	/**
	 * true表示正在添加或删除子节点, 这个标志用来防止嵌套性的访问子节点列表
	 */
	bool m_childrenChanging;

	/// priority of touch event, default is 0
	int m_touchPriority;

	/// priority of key event, default is 0
	int m_keyPriority;

	/// priority of gesture event, default is 0
	int m_gesturePriority;

	/// priority of double click event, default is 0
	int m_doubleTapPriority;

	/// priority of accelerometer event, default is 0
	int m_accelerometerPriority;

	/// z order of node in parent, it is an internal z order, not OpenGL z order
	int m_zOrder;

	/// tag of node, just an integer identifier of node
	int m_tag;

	/// anchor x position in pixels, relative to node left-bottom corner
	float m_anchorPointX;

	/// anchor y position in pixels, relative to node left-bottom corner
	float m_anchorPointY;

	/**
	 * Relative anchor x position, if (0.5, 0.5) and node size is 100x200, then node point position is (50, 100)
	 */ 
	float m_anchorX;

	/**
	 * Relative anchor y position, if (0.5, 0.5) and node size is 100x200, then node point position is (50, 100)
	 */ 
	float m_anchorY;

	/**
	 * node x position, if \c m_relativeAnchorPoint is true, it is the position of anchor point relative to parent node
	 * if \c m_relativeAnchorPoint is false, it is position of node left-bottom corner relative to parent node
	 */
	float m_positionX;

	/**
	 * node y position, if \c m_relativeAnchorPoint is true, it is the position of anchor point relative to parent node
	 * if \c m_relativeAnchorPoint is false, it is position of node left-bottom corner relative to parent node
	 */
	float m_positionY;

	/// node width in pixels
	float m_width;

	/// node height in pixels
	float m_height;

	/// node rotation in degree, Positive value rotates in clockwise, or negative value to counter-clockwise
	float m_rotation;

	/// scale ratio in x axis, default is 1
	float m_scaleX;

	/// scale ratio in y axis, default is 1
	float m_scaleY;

	/// degree of x axis skewing, position value is clockwise
	float m_skewX;

	/// degree of y axis skewing, position value is clockwise
	float m_skewY;

	/// z order in OpenGL
	float m_vertexZ;

	/// x velocity of node, in pixels/second
	float m_velocityX;

	/// y velocity of node, in pixels/second
	float m_velocityY;

	/// x acceleration in x axis, in pixels/second
	float m_accelerationX;

	/// y aceleration in y axis, in pixels/second
	float m_accelerationY;

	/// render pair list
	vector<RenderPair>* m_renderPairs;

	/// node color, meaningless for non-geometry node
	wyColor4B m_color;

	/// true means material should be updated
	bool m_materialNeedUpdate;

	/// true means mesh need to be updated
	bool m_meshNeedUpdate;

	/// true means mesh color need to be updated
	bool m_meshColorNeedUpdate;

	/// true indicating clip rect is set
	bool m_hasClip;

	/// clip矩形, 节点只在这个矩形范围内的部分被渲染. 如果矩形的宽或高为0表示没有clip
	wyRect m_clipRect;

	/**
	 * true表示\c m_clipRect 代表的是一个相对于节点自身坐标的矩形, false表示
	 * \c m_clipRect 代表的是一个全局坐标矩形. 缺省情况下是false.
	 */
	bool m_clipRelativeToSelf;

	/// 父节点\link wyNode wyNode对象指针\endlink
	wyNode* m_parent;

	/// 所有子节点\link wyArray wyArray对象指针\endlink
	wyArray* m_children;

	/// 网格对象\link wyGridController wyGridController对象指针\endlink
	wyGridController* m_grid;

	/// 相机对象\link wyCamera wyCamera对象指针\endlink
	wyCamera* m_camera;

	// 节点定时器集合\link wyArray wyArray对象指针\endlink
	wyArray* m_timers;

	/// 按下节点的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	wyTargetSelector* m_downSelector;

	/// 松开节点的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	wyTargetSelector* m_upSelector;

	/// 移出节点的回调\link wyTargetSelector wyTargetSelector对象指针\endlink
	wyTargetSelector* m_moveOutSelector;

	/// 节点的附加数据对象
	wyUserData m_data;

	/// 节点的位置更改事件回调接口指针
	wyNodePositionListener* m_positionListener;

	/// 位置更改事件的附加数据指针
	void* m_plData;
	
	/// touch event should in such node content rect
	/// it won't be retained by current node
	wyNode* m_touchCoffin;

#if ANDROID

	/// java层位置更改事件接口实现类
	jobject m_jPositionListener;
	
	/// java层的触摸事件监听器
	jobject m_jTouchHandler;
	
	/// java层的按键事件监听器
	jobject m_jKeyHandler;
	
	/// java层的加速事件监听器
	jobject m_jAccelHandler;
	
	/// java层的双击事件监听器
	jobject m_jDoubleTapHandler;
	
	/// java层的手势事件监听器
	jobject m_jGestureHandler;
	
	/// java层虚方法实现
	jobject m_jVirtualMethods;
	
	/// true表示\c m_data中存放的是jobject
	bool m_dataIsJavaObject;

#endif // #if ANDROID

private:
	static bool activateTimer(wyArray* arr, void* ptr, int index, void* data);
	static bool deactivateTimer(wyArray* arr, void* ptr, int index, void* data);
	static bool releaseTimer(wyArray* arr, void* ptr, int index, void* data);
	static bool zOrderLocator(void* elementPtr, void* ptr, void* data);
	static bool tagLocator(void* elementPtr, void* ptr, void* data);
	static bool sOnEnter(wyArray* arr, void* ptr, int index, void* data);
	static bool sOnExit(wyArray* arr, void* ptr, int index, void* data);
	static bool sOnEnterTransitionDidFinish(wyArray* arr, void* ptr, int index, void* data);
	static bool sCleanup(wyArray* arr, void* ptr, int index, void* data);

	/**
	 * 目前节点内是否有至少一个正在跟踪的触摸点
	 *
	 * @return true表示有至少一个正在跟踪的触摸点
	 */
	bool hasTouch() { return m_state.count > 0; }

	/**
	 * 清空目前增在跟踪的触摸点
	 */
	void clearTouch() { m_state.count = 0; }

	/**
	 * 保存触摸点id到状态中
	 *
	 * @param pid 触摸点id
	 */
	void trackTouch(int pid) { m_state.pid[m_state.count++] = pid; }

	/**
	 * 是否存在某个pid
	 *
	 * @param pid 触摸点id
	 * @return true表示存在
	 */
	bool hasPid(int pid);

	/**
	 * 清除一个pid
	 *
	 * @param pid 触摸点id
	 */
	void clearPid(int pid);

	/**
	 * 设置触摸事件状态, 主要由WiEngine内部调用, 应用不应该调用该方法
	 *
	 * @param state 状态常量, 定义在枚举wyTouchState中
	 */
	void setTouchState(wyTouchState state) { m_state = state; }

	/**
	 * 获得触摸事件状态
	 *
	 * @return 触摸事件状态
	 */
	wyTouchState getTouchState() { return m_state; }

protected:
	/// constructor
	wyNode();

	/**
	 * 添加一个子节点
	 *
	 * @param n 被添加的子节点\link wyNode wyNode对象指针\endlink
	 * @param z z轴的顺序, 根据z轴顺序决定画节点的顺序
	 * @return 子节点被插入后在子节点列表中的索引, 或者-1表示插入到了最后
	 */
	int insertChild(wyNode* n, int z);

	/**
	 * 激活定时器
	 */
	void activateTimers();

	/**
	 * 禁用定时器
	 */
	void deactivateTimers();

	/**
	 * 得到基础适配模式下的clip rect
	 *
	 * @param r 相对于基础大小的矩形
	 * @return 相对于真实屏幕大小的矩形
	 */
	wyRect getBaseSizeClipRect(wyRect r);

public:
	/// static creator
	static wyNode* make();

	/// deconstructor
	virtual ~wyNode();

    /**
     * \if English
     * Invoked when node will become active. Active means related scene is running.
     * This method is called from internal and generally you should not call it from
     * program
     * \else
     * 当节点要变成活动态时，该方法被调用。活动态即节点所属的场景正在运行。
     * 该方法由WiEngine内部调用，不需要手动调用
     * \endif
     */
	virtual void onEnter();

    /**
     * \if English
     * Invoked when this node is removed from parent or related scene is gone.
     * This method is called internal and generally you should not call it from
     * program
     * \else
     * 当节点所属场景退出时该方法被调用，或者当该节点被删除时被调用
     * 该方法由WiEngine内部调用，不需要手动调用
     * \endif
     */
	virtual void onExit();

    /**
     * \if English
     * Invoked when a transition is done. It is called from internal and
     * you should not call it from program
     * \else
     * 当节点所属场景切换完成时该方法被调用
     * 该方法由WiEngine内部调用，不需要手动调用
     * \endif
     */
	virtual void onEnterTransitionDidFinish();

    /**
     * \if English
     * Invoked when this node is added to a parent node, it occurs
     * before \c onEnter
     *
     * @param parent parent node
     * \else
     * 当节点被添加到某个父节点后，该方法被调用. 这个方法会发生在onEnter之前.
     *
     * @param parent 父节点
     * \endif
     */
	virtual void onAttachToParent(wyNode* parent);

    /**
     * \if English
     * Invoked when this node is removed from parent, it occurs before
     * \c onExit
     *
     * @param parent parent node
     * \else
     * 当节点从某个父节点删除之前，该方法被调用，这个方法会发生在onExit之前
     *
     * @param parent 父节点
     * \endif
     */
	virtual void onDetachFromParent(wyNode* parent);

	/**
	 * \if English
	 * Clear timers on this node
	 * \else
	 * 重置节点状态，包括子节点的状态
	 * \endif
	 */
	virtual void cleanup();

	/**
	 * \if English
	 * Set anchor relative position
	 *
	 * @param x relative x position
	 * @param y relative y position
	 * \else
	 * 设置锚点的相对位置
	 *
	 * @param x 相对x位置
	 * @param y 相对y位置
	 * \endif
	 */
	virtual void setAnchor(float x, float y);

	/**
	 * \if English
	 * Set anchor relative x position
	 *
	 * @param x relative x position
	 * \else
	 * 设置锚点的x位置
	 *
	 * @param x 相对x位置
	 * \endif
	 */
	virtual void setAnchorX(float x);

	/**
	 * \if English
	 * Set anchor relative y position
	 *
	 * @param y relative y position
	 * \else
	 * 设置锚点的y位置
	 *
	 * @param y 相对y位置
	 * \endif
	 */
	virtual void setAnchorY(float y);

	/**
	 * \if English
	 * Reset anchor relative position but doesn't change node bound rect relative to
	 * parent
	 *
	 * @param x new anchor x relative position
	 * @param y new anchor y relative position
	 * \else
	 * 重新设置节点的锚点位置, 但是保持节点相对于父节点的位置不变, 这在有时候只想移动锚点时但不想
	 * 改变节点位置的时候是个方便的方法
	 *
	 * @param x 新的锚点y位置
	 * @param y 新的锚点y位置
	 * \endif
	 */
	virtual void moveAnchorTo(float x, float y);

	/**
	 * \if English
	 * Set size of node
	 *
	 * @param w width of node in pixel
	 * @param h height of node in pixel
	 * \else
	 * 设置节点的大小
	 *
	 * @param w 节点象素宽度
	 * @param h 节点象素高度
	 * \endif
	 */
	virtual void setContentSize(float w, float h);

	/**
	 * \if English
	 * Set node position, the method behavior is affected by \c m_relativeAnchorPoint flag.
	 * If \c m_relativeAnchorPoint is true, this method set anchor to that position. If \c m_relativeAnchorPoint
	 * is false, this method set bottom-left corner to that position
	 *
	 * @param x x position
	 * @param y y position
	 * \else
	 * 设置节点位置, 这个方法的行为和\c m_relativeAnchorPoint标志相关. 如果\c m_relativeAnchorPoint是true,
	 * 这个方法设置的其实是锚点的位置. 如果\c m_relativeAnchorPoint的值是false, 这个方法设置的是左下角的位置.
	 *
	 * @param x x位置
	 * @param y y位置
	 * \endif
	 */
	virtual void setPosition(float x, float y);

	/**
	 * \if English
	 * Set node position by delta. It is same as \c setPosition(getPositionX() + x, getPositionY() + y).
	 *
	 * @param x delta x
	 * @param y delta y
	 * \else
	 * 平移节点
	 *
	 * @param x 平移的x值
	 * @param y 平移的y值
	 * \endif
	 */
	virtual void translate(float x, float y);

	/**
	 * \if English
	 * Translate all direct children node
	 *
	 * @param x delta x
	 * @param y delta y
	 * \else
	 * 平移所有子节点, 只平移一级, 不会平移子节点的子节点
	 *
	 * @param x 平移的x值
	 * @param y 平移的y值
	 * \endif
	 */
	virtual void translateChildren(float x, float y);

	/**
	 * \if English
	 * Set rotation angle in degree. Positive value rotates in clockwise, or negative value
	 * to counter-clockwise
	 *
	 * @param rot rotation in degree
	 * \else
	 * 设置旋转角度, 正值表示顺时针，负值表示逆时针
	 *
	 * @param rot 角度
	 * \endif
	 */
	virtual void setRotation(float rot);

	/**
	 * \if English
	 * Set scale rate of node
	 *
	 * @param scale scale rate
	 * \else
	 * 设置缩放比例
	 *
	 * @param scale 缩放比例, 将把x和y都设置成同样比例
	 * \endif
	 */
	virtual void setScale(float scale);

	/**
	 * \if English
	 * Set scale rate along x axis
	 *
	 * @param scaleX scale in x axis
	 * \else
	 * 设置x方向缩放比例
	 *
	 * @param scaleX x方向缩放比例
	 * \endif
	 */
	virtual void setScaleX(float scaleX);

	/**
	 * \if English
	 * Set scale rate along y axis
	 *
	 * @param scaleY scale in y axis
	 * \else
	 * 设置y方向缩放比例
	 *
	 * @param scaleY y方向缩放比例
	 * \endif
	 */
	virtual void setScaleY(float scaleY);

	/**
	 * \if English
	 * The X skew angle of the node in degrees. This angle describes the shear distortion in the X direction.
	 * Thus, it is the angle between the Y axis and the left edge of the shape. The default skewX angle is 0.
	 * Positive values distort the node in a CCW direction.
	 * \else
	 * 设置x轴扭曲角度. 这个扭曲角度表示的是在x方向上的倾斜程度, 它是y轴和节点左边界的角度值. 正值为逆时针方向.
	 * \endif
	 */
	virtual void setSkewX(float degree);

	/**
	 * \if English
	 * The Y skew angle of the node in degrees. This angle describes the shear distortion in the Y direction.
	 * Thus, it is the angle between the X axis and the bottom edge of the shape. The default skewY angle is 0.
	 * Positive values distort the node in a CCW direction.
	 * \else
	 * 设置y轴扭曲角度. 这个扭曲角度表示的是在y方向上的倾斜程度, 它是x轴和节点底边的角度值. 正值为逆时针方向.
	 * \endif
	 */
	virtual void setSkewY(float degree);

	/**
	 * \if English
	 * Set selected flag of node
	 *
	 * @param selected selected state or not
	 * \else
	 * 设置节点的选择状态
	 *
	 * @param selected 选择状态
	 * \endif
	 */
	virtual void setSelected(bool selected) { m_selected = selected; }

	/**
	 * \if English
	 * Set z order value in OpenGL
	 *
	 * @param vertexZ z order value in OpenGL
	 * \else
	 * 设置节点在OpenGL中的z order值
	 *
	 * @param vertexZ 在OpenGL中的z order值
	 * \endif
	 */
	virtual void setVertexZ(float vertexZ) { m_vertexZ = vertexZ; }

	/**
	 * \if English
	 * Set visibility of node. If false, then all children's isVisibleFromRoot returns false.
	 * An invisible node can't receive event and children node also can't.
	 *
	 * @param visible true means visible
	 * \else
	 * 设置节点是否可见. 这个状态如果为false，那么所有子节点的
	 * isVisibleFromRoot()也将返回false。一个visible状态为false的
	 * 节点无法接收到系统事件, 并且其子节点也无法接收到系统事件。
	 *
	 * @param visible true表示可见
	 * \endif
	 */
	virtual void setVisible(bool visible) { m_visible = visible; }

	/**
	 * \if English
	 * Set focus state of node. This flag doesn't affect event handling. It is only
	 * a flag and only useful for full-keyboard mobile phone.
	 *
	 * @param focused true means node is in focused state
	 * \else
	 * 设置节点是否获得焦点. 这个状态并不影响节点是否能收到事件, 它仅仅是一个状态标志. 而这个标志一般只对
	 * 拥有全键盘的手机有意义.
	 *
	 * @param focused true获得焦点
	 * \endif
	 */
	virtual void setFocused(bool focused);

	/**
	 * \if English
	 * Set enable state of node. If false, all children's isEnabledFromRoot() will returns false.
	 * A disabled node can't process event and children also can't. But disabled node is still visible.
	 *
	 * @param enabled true means node is enabled
	 * \else
	 * 设置节点的是否启用状态. 这个状态如果为false，那么所有子节点的
	 * isEnabledFromRoot()也将返回false。一个enable状态为false的
	 * 节点无法接收到系统事件, 并且其子节点也无法接收到系统事件。
	 *
	 * @param enabled 节点状态
	 * \endif
	 */
	virtual void setEnabled(bool enabled) { m_enabled = enabled; }

	/**
	 * \if English
	 * Accelerometer event handler. Accelerometer has three values: x, y, z. And their value
	 * is following iOS rule. Android and iOS behave different in accelerometer values:
	 * 1. Their sign is opposite
	 * 2. Values in iOS changes between -1 and 1, but Android it is -9.81 to 9.81. So WiEngine
	 * maps Android value to iOS value.
	 *
	 * \note
	 * WiEngine uses iOS value rule because it coincide with OpenGL coordinates
	 *
	 * @param accelX x value
	 * @param accelY y value
	 * @param accelZ z value
	 * \else
	 * 加速事件的回调. 这里的加速器值分成x, y, z三个维度, 它们的取值采用iOS的规则. Android和iOS
	 * 平台对加速器事件的参数主要有两个差异:
	 * 1. 它们的符号是完全相反的
	 * 2. iOS以1表示一个重力加速度, 而Android以9.81代表一个重力加速度
	 * 因此在Android平台上得到的值需要除以9.81并翻转符号.
	 *
	 * \note
	 * 之所以使用iOS规则表示加速器事件, 是因为其取值与OpenGL坐标系相符合.
	 *
	 * @param accelX x轴加速值
	 * @param accelY y轴加速值
	 * @param accelZ z轴加速值
	 * \endif
	 */
	virtual void accelerometerChanged(float accelX, float accelY, float accelZ);

	/**
	 * \if English
	 * Key down event handler
	 *
	 * @param e \link wyKeyEvent wyKeyEvent\endlink
	 * \else
	 * Key Down事件的回调
	 *
	 * @param e key事件
	 * \endif
	 */
	virtual bool keyDown(wyKeyEvent& e);

	/**
	 * \if English
	 * Key up event handler
	 *
	 * @param e \link wyKeyEvent wyKeyEvent\endlink
	 * \else
	 * Key Up事件的回调
	 *
	 * @param e key事件
	 * \endif
	 */
	virtual bool keyUp(wyKeyEvent& e);

	/**
	 * \if English
	 * Key multiple event handler
	 *
	 * @param e \link wyKeyEvent wyKeyEvent\endlink
	 * \else
	 * Key Multiple事件的回调
	 *
	 * @param e key事件
	 * \endif
	 */
	virtual bool keyMultiple(wyKeyEvent& e);
	
	/**
	 * \if English
	 * Touch began event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 * \else
	 * Touches Began事件的回调
	 *
	 * @param e 屏幕触摸事件
	 * \endif
	 */
	virtual bool touchesBegan(wyMotionEvent& e);

	/**
	 * \if English
	 * Touch moved event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 * \else
	 * Touches Moved事件的回调
	 *
	 * @param e 屏幕触摸事件
	 * \endif
	 */
	virtual bool touchesMoved(wyMotionEvent& e);

	/**
	 * \if English
	 * Touch ended event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 * \else
	 * Touches Ended事件的回调
	 *
	 * @param e 屏幕触摸事件
	 * \endif
	 */
	virtual bool touchesEnded(wyMotionEvent& e);

	/**
	 * \if English
	 * Touch cancelled event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 * \else
	 * Touches Cancelled事件的回调
	 *
	 * @param e 屏幕触摸事件
	 * \endif
	 */
	virtual bool touchesCancelled(wyMotionEvent& e);

	/**
	 * \if English
	 * Touch pointer began event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 * \else
	 * Touches Pointer Began事件的回调
	 *
	 * @param e 屏幕触摸事件
	 * \endif
	 */
	virtual bool touchesPointerBegan(wyMotionEvent& e);

	/**
	 * \if English
	 * Touch pointer ended event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 * \else
	 * Touches Pointer Ended事件的回调
	 *
	 * @param e 屏幕触摸事件
	 * \endif
	 */
	virtual bool touchesPointerEnded(wyMotionEvent& e);

	/**
	 * \if English
	 * double tap event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 * \else
	 * Double Tap事件的回调
	 *
	 * @param e 屏幕触摸事件
	 * \endif
	 */
	virtual bool onDoubleTap(wyMotionEvent& e);

	/**
	 * \if English
	 * double tap event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 * \else
	 * Double Tap Event事件的回调
	 *
	 * @param e 屏幕触摸事件
	 * \endif
	 */
	virtual bool onDoubleTapEvent(wyMotionEvent& e);

	/**
	 * \if English
	 * single tap event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 * \else
	 * Single Tap Confirmed事件的回调
	 *
	 * @param e 屏幕触摸事件
	 * \endif
	 */
	virtual bool onSingleTapConfirmed(wyMotionEvent& e);

	/**
	 * \if English
	 * Down event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 * \else
	 * Down事件的回调
	 *
	 * @param e 屏幕触摸事件
	 * \endif
	 */
	virtual bool onDown(wyMotionEvent& e);

	/**
	 * \if English
	 * Fling event handler
	 *
	 * @param e1 \link wyMotionEvent wyMotionEvent\endlink
	 * @param e2 \link wyMotionEvent wyMotionEvent\endlink
	 * @param velocityX fling velocity in x axis
	 * @param velocityY fling velocity in y axis
	 * \else
	 * Fling事件的回调
	 *
	 * @param e1 事件对象
	 * @param e2 事件对象
	 * @param velocityX Fling事件x轴速度
	 * @param velocityY Fling事件y轴速度
	 * \endif
	 */
	virtual bool onFling(wyMotionEvent& e1, wyMotionEvent& e2, float velocityX, float velocityY);

	/**
	 * \if English
	 * Long press event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 * \else
	 * Long Press事件的回调
	 *
	 * @param event 屏幕触摸事件
	 * \endif
	 */
	virtual void onLongPress(wyMotionEvent& event);

	/**
	 * \if English
	 * Scroll event handler
	 *
	 * @param e1 \link wyMotionEvent wyMotionEvent\endlink
	 * @param e2 \link wyMotionEvent wyMotionEvent\endlink
	 * @param distanceX scrolling distance in x axis from last event
	 * @param distanceY scrolling distance in y axis from last event
	 * \else
	 * Scroll事件的回调
	 *
	 * @param e1 事件对象
	 * @param e2 事件对象
	 * @param distanceX Scroll事件x轴距离
	 * @param distanceY Scroll事件y轴距离
	 * \endif
	 */
	virtual bool onScroll(wyMotionEvent& e1, wyMotionEvent& e2, float distanceX, float distanceY);

	/**
	 * \if English
	 * Show press event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 * \else
	 * Show Press事件的回调
	 *
	 * @param e 屏幕触摸事件
	 * \endif
	 */
	virtual void onShowPress(wyMotionEvent& e);

	/**
	 * \if English
	 * Single tap up event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 * \else
	 * Single Tap Up事件的回调
	 *
	 * @param e 屏幕触摸事件
	 * \endif
	 */
	virtual bool onSingleTapUp(wyMotionEvent& e);

	/**
	 * \if English
	 * Hit test to check a point is inside node or not. The location must be in global coordinates.
	 * This method will consider node's scale, rotation, etc. And if node is rotation, actually the
	 * bounding rectangle is checked.
	 *
	 * @param x x position
	 * @param y y position
	 * @return true means the point is inside node rectangle
	 * \else
	 * 判断某个坐标是否落在了节点的矩形范围内，坐标必须是全局坐标. 这个方法判断的时候
	 * 会考虑节点当前的缩放, 旋转等参数. 如果节点是旋转了的, 那么实际判断的矩形范围
	 * 是节点的外接矩形.
	 *
	 * @param x x坐标
	 * @param y y坐标
	 * @return true表示坐标在节点矩形范围内，false表示不在
	 * \endif
	 */
	virtual bool hitTest(float x, float y);

	/**
	 * \if English
	 * Set flag indicating \c setPosition behavior. If true, \c setPosition sets anchor position or false means
	 * \c setPosition set bottom-left position
	 *
	 * @param flag true means \c setPosition sets anchor position or false means
	 * 		\c setPosition set bottom-left position
	 * \else
	 * 设置是否position和anchor position分离. true表示\c setPosition设置的是锚点位置, false表示\c setPosition设置的是
	 * 做左下角的位置
	 *
	 * @param flag true表示不分离，false表示分离
	 * \endif
	 */
	virtual void setRelativeAnchorPoint(bool flag);

	/**
	 * \if English
	 * Update transform matrix from node to parent
	 * \else
	 * 更新节点相对父节点的转换矩阵
	 * \endif
	 */
	void updateNodeToParentTransform();

	/**
	 * \if English
	 * Update transform matrix from parent to node
	 * \else
	 * 更新父节点相对节点的转换矩阵
	 * \endif
	 */
	void updateParentToNodeTransform();

	/**
	 * \if English
	 * Get transform matrix from node to global
	 *
	 * @return \link wyAffineTransform wyAffineTransform\endlink
	 * \else
	 * 返回节点相对屏幕坐标轴的转换矩阵
	 *
	 * @return \link wyAffineTransform wyAffineTransform\endlink
	 * \endif
	 */
	wyAffineTransform getNodeToWorldTransform();

	/**
	 * \if English
	 * Get transform matrix from node to parent
	 *
	 * @retun \link wyAffineTransform wyAffineTransform\endlink
	 * \else
	 * 返回当前节点相对父节点的转换矩阵
	 *
	 * @return \link wyAffineTransform wyAffineTransform\endlink
	 * \endif
	 */	
	wyAffineTransform getTransformMatrix();

	/**
	 * \if English
	 * Get transform matrix from global to node
	 *
	 * @retun \link wyAffineTransform wyAffineTransform\endlink
	 * \else
	 * 返回屏幕坐标轴相对节点的转换矩阵
	 *
	 * @return \link wyAffineTransform wyAffineTransform\endlink
	 * \endif
	 */
	wyAffineTransform getWorldToNodeTransform();

	/**
	 * \if English
	 * Set dirty flag of transform matrix. Then node will update transform matrix next time.
	 * \else
	 * 设置变换矩阵状态为脏，这样Node会强制底层更新变换矩阵
	 * \endif
	 */
	void setTransformDirty();

	/**
	 * \if English
	 * Get current scale rate
	 *
	 * @return scale rate
	 * \else
	 * 得到当前的缩放比例
	 *
	 * @return 缩放比例
	 * \endif
	 */
	float getScale();

	/**
	 * \if English
	 * Get current x scale rate
	 *
	 * @return x scale rate
	 * \else
	 * 得到x轴缩放比例
	 *
	 * @return 缩放比例
	 * \endif
	 */
	float getScaleX() { return m_scaleX; }

	/**
	 * \if English
	 * Get current y scale rate
	 *
	 * @return y scale rate
	 * \else
	 * 得到y轴缩放比例
	 *
	 * @return 缩放比例
	 * \endif
	 */
	float getScaleY() { return m_scaleY; }

	/**
	 * \if English
	 * Get X axis shear distortion degree. Positive value is counter-clockwise
	 * \else
	 * 得到x方向的倾斜角度, 正值表示逆时针
	 * \endif
	 */
	float getSkewX() { return m_skewX; }

	/**
	 * \if English
	 * Get Y axis shear distortion degree. Positive value is counter-clockwise
	 * \else
	 * 得到y方向的倾斜角度, 正值表示逆时针
	 * \endif
	 */
	float getSkewY() { return m_skewY; }

	/**
	 * \if English
	 * Set grid object for this node
	 *
	 * @param grid \link wyGridController wyGridController\endlink subclass
	 * \else
	 * 设置节点的网格对象
	 *
	 * @param grid 网格对象\link wyGridController wyGridController对象指针\endlink
	 * \endif
	 */
	void setGrid(wyGridController* grid);

	/**
	 * \if English
	 * Add a child node in a thread safe way
	 *
	 * @param child \link Node Node\endlink to be added
	 * @param z z order in child list
	 * @param tag tag value of child node, default is an invalid value
	 * \else
	 * 添加子节点,方法是线程安全的
	 *
	 * @param child 子节点\link wyNode wyNode对象指针\endlink
	 * @param z z轴顺序, 缺省是0
	 * @param tag 子节点的标识, 缺省是一个无效值
	 * \endif
	 */
	void addChildLocked(wyNode* child, int z = 0, int tag = INVALID_TAG);

	/**
	 * \if English
	 * Add child node
	 *
	 * @param child child node object
	 * @param z z order in child list, the smaller will be drawn first
	 * @param tag tag to identify child node
	 * \else
	 * 添加子节点
	 *
	 * @param child 子节点\link wyNode wyNode对象指针\endlink
	 * @param z z轴顺序
	 * @param tag 子节点的标识
	 * \endif
	 */
	virtual void addChild(wyNode* child, int z, int tag);

	/**
	 * \if English
	 * Change z-order of a child, not thread safe. That will affect render sequence of this child. Don't
	 * call setZOrder because it doesn't resort children
	 *
	 * @param child child node
	 * @param z new z order value
	 * \else
	 * 更新子节点的z轴顺序
	 *
	 * @param child 子节点\link wyNode wyNode对象指针\endlink
	 * @param z z轴顺序
	 * \endif
	 */
	virtual int reorderChild(wyNode* child, int z);

	/**
	 * \if English
	 * Remove all children in thread safe way
	 *
	 * @param cleanup true means reset state of removed child.
	 * \else
	 * 删除所有子节点,方法是线程安全的
	 *
	 * @param cleanup true表示重置被删除的节点的状态。一个节点被clean之后将失去一些状态，比如附加在节点
	 * 		上的action，timer等，但是这个节点仍然可以用addChild加回来继续使用。
	 * \endif
	 */
	void removeAllChildrenLocked(bool cleanup);

	/**
	 * \if English
	 * Remove all children, not thread safe
	 *
	 * @param cleanup true means reset state of removed child
	 * \else
	 * 删除所有子节点
	 *
	 * @param cleanup true表示重置被删除的节点的状态。一个节点被clean之后将失去一些状态，比如附加在节点
	 * 		上的action，timer等，但是这个节点仍然可以用addChild加回来继续使用。
	 * \endif
	 */
	virtual void removeAllChildren(bool cleanup);

	/**
	 * \if English
	 * Remove one child node in thread safe way
	 *
	 * @param child child node to be removed
	 * @param cleanup true means reset state of removed child
	 * \else
	 * 删除某个子节点,方法是线程安全的
	 *
	 * @param child 要删除的节点
	 * @param cleanup true表示重置被删除的节点的状态。一个节点被clean之后将失去一些状态，比如附加在节点
	 * 		上的action，timer等，但是这个节点仍然可以用addChild加回来继续使用。
	 * \endif
	 */
	void removeChildLocked(wyNode* child, bool cleanup);

	/**
	 * \if English
	 * Remove a child node by tag, in thread safe way. If more than one child
	 * has same tag, it will only remove first one matched
	 *
	 * @param tag child node tag
	 * @param cleanup true means reset state of removed child
	 * \else
	 * 根据tag删除某个子节点,方法是线程安全的. 这个方法只删除第一个tag匹配的节点, 因此不适用于
	 * 有多个节点tag相同的情况.
	 *
	 * @param tag 子节点的tag
	 * @param cleanup true表示重置被删除的节点的状态。一个节点被clean之后将失去一些状态，比如附加在节点
	 * 		上的action，timer等，但是这个节点仍然可以用addChild加回来继续使用。
	 * \endif
	 */
	void removeChildByTagLocked(int tag, bool cleanup);

	/**
	 * \if English
	 * Remove a child node by tag, in thread safe way. If more than one child
	 * has same tag, it will remove them all.
	 *
	 * @param tag child node tag
	 * @param cleanup true means reset state of removed child
	 * \else
	 * 根据tag删除某个子节点,方法是线程安全的. 这个方法删除所有具有同样tag的节点
	 *
	 * @param tag 子节点的tag
	 * @param cleanup true表示重置被删除的节点的状态。一个节点被clean之后将失去一些状态，比如附加在节点
	 * 		上的action，timer等，但是这个节点仍然可以用addChild加回来继续使用。
	 * \endif
	 */
	void removeChildrenByTagLocked(int tag, bool cleanup);

	/**
	 * \if English
	 * Remove one child node, not in thread safe way
	 *
	 * @param child child node to be removed
	 * @param cleanup true means reset state of removed child
	 * \else
	 * 删除某个子节点
	 *
	 * @param child 要删除的节点
	 * @param cleanup true表示重置被删除的节点的状态。一个节点被clean之后将失去一些状态，比如附加在节点
	 * 		上的action，timer等，但是这个节点仍然可以用addChild加回来继续使用。
	 * \endif
	 */
	virtual void removeChild(wyNode* child, bool cleanup);

	/**
	 * \if English
	 * Reorder child z order, in a thread safe way
	 *
	 * @param child child node to be reset z order
	 * @param z new z order
	 * \else
	 * 更新子节点的z轴顺序,方法是线程安全的
	 *
	 * @param child 子节点\link wyNode wyNode对象指针\endlink
	 * @param z z轴顺序
	 * \endif
	 */
	int reorderChildLocked(wyNode* child, int z);

	/**
	 * \if English
	 * Bring a child node to bottom of children list, that means the child will be above on
	 * other sibling nodes. Actually it calls \c reorderChild to set z order
	 *
	 * @param child child node to be moved
	 * \else
	 * 把一个子节点挪动到最前面, 因此它会是最后渲染的子节点, 可能盖住其它的子节点
	 *
	 * @param child 子节点, 如果该节点不是当前节点的子节点, 则不做任何事
	 * \endif
	 */
	virtual void bringToFront(wyNode* child);

	/**
	 * \if English
	 * Bring a child node to bottom of children list in a thread safe way, that means the child will be above on
	 * other sibling nodes. Actually it calls \c reorderChild to set z order
	 *
	 * @param child child node to be moved
	 * \else
	 * 把一个子节点挪动到最前面, 因此它会是最后渲染的子节点, 可能盖住其它的子节点. 该方法
	 * 是线程安全的
	 *
	 * @param child 子节点, 如果该节点不是当前节点的子节点, 则不做任何事
	 * \endif
	 */
	void bringToFrontLocked(wyNode* child);

	/**
	 * \if English
	 * Bring a child node to top of children list so it will below to other sibling nodes.
	 * Actually it calls \c reorderChild to set z order of child node
	 *
	 * @param child child node to be moved
	 * \else
	 * 把一个子节点挪到最后面, 因此它会是最先渲染的子节点, 后面的子节点可能覆盖它.
	 *
	 * @param child 子节点, 如果该节点不是当前节点的子节点, 则不做任何事
	 * \endif
	 */
	virtual void bringToBack(wyNode* child);

	/**
	 * \if English
	 * Bring a child node to top of children list in a thread safe way. It will below to other sibling nodes.
	 * Actually it calls \c reorderChild to set z order of child node
	 *
	 * @param child child node to be moved
	 * \else
	 * 把一个子节点挪到最后面, 因此它会是最先渲染的子节点, 后面的子节点可能覆盖它.
	 * 该方法是线程安全的
	 *
	 * @param child 子节点, 如果该节点不是当前节点的子节点, 则不做任何事
	 * \endif
	 */
	void bringToBackLocked(wyNode* child);

	/**
	 * \if English
	 * Get child by tag, in thread safe way. If more than one child matched, first
	 * one is returned
	 *
	 * @param tag tag of node
	 * @return found node, or NULL if not found
	 * \else
	 * 通过tag得到某个子节点,方法是线程安全的. 如果有多个子节点具有同样的tag, 第一个匹配的将会返回
	 *
	 * @param tag 子节点的tag
	 * @return 节点\link wyNode wyNode对象指针\endlink，如果没找到返回NULL
	 * \endif
	 */
	wyNode* getChildByTagLocked(int tag);

	/**
	 * \if English
	 * Get children by tag, in thread safe way
	 *
	 * @param tag tag of node
	 * @param count count of node returned
	 * @return all nodes which has the tag, caller should release the pointer
	 * \else
	 * 通过tag得到所有具有该tag的子节点, 方法是线程安全的
	 *
	 * @param tag 子节点的tag
	 * @param count 保存有返回的节点个数
	 * @return \link wyNode wyNode\endlink指针数组, 如果没找到返回NULL, 调用者要负责释放
	 * \endif
	 */
	wyNode** getChildrenByTagLocked(int tag, size_t* count);

	/**
	 * \if English
	 * Get child node by tag. If more than one child matched, first one is returned
	 *
	 * @param tag node tag
	 * @param node object or NULL if not found
	 * \else
	 * 通过tag得到某个子节点, 如果有多个子节点具有同样的tag, 则返回的是第一个匹配的子节点
	 *
	 * @param tag 子节点的tag
	 * @return 节点\link wyNode wyNode对象指针\endlink，如果没找到返回NULL
	 * \endif
	 */
	virtual wyNode* getChildByTag(int tag);

	/**
	 * \if English
	 * Get children by tag
	 *
	 * @param tag tag of node
	 * @param count count of node returned
	 * @return all nodes which has the tag, caller should release the pointer
	 * \else
	 * 通过tag得到所有具有该tag的子节点
	 *
	 * @param tag 子节点的tag
	 * @param count 保存有返回的节点个数
	 * @return \link wyNode wyNode\endlink指针数组, 如果没找到返回NULL, 调用者要负责释放
	 * \endif
	 */
	virtual wyNode** getChildrenByTag(int tag, size_t* count);

	/**
	 * \if English
	 * Get first node in children list, the first child has smallest z order value
	 *
	 * @return node object or NULL if children list is empty
	 * \else
	 * 获得子节点队列中的第一个
	 *
	 * @return 节点\link wyNode wyNode对象指针\endlink，如果没有子节点返回NULL
	 * \endif
	 */
	virtual wyNode* getFirstChild();

	/**
	 * \if English
	 * Set velocity of node. It is a simply way to move a node without running an action or
	 * maintaining physics engine
	 *
	 * @param vx x velocity
	 * @param vy y velocity
	 * \else
	 * 设置节点的速度. 方便于设置简单的物理功能, 对于只需要速度加速度的情况, 可以省掉
	 * 自己维护或者使用物理引擎的麻烦.
	 *
	 * @param vx x方向速度
	 * @param vy y方向速度
	 * \endif
	 */
	virtual void setVelocity(float vx, float vy);

	/**
	 * \if English
	 * Set acceleration of node. It is a simply way to move node without running an action or
	 * maintaining physics engine
	 *
	 * @param ax x acceleration
	 * @param ay y acceleration
	 * \else
	 * 设置节点的加速度. 方便于设置简单的物理功能, 对于只需要速度加速度的情况, 可以省掉
	 * 自己维护或者使用物理引擎的麻烦.
	 *
	 * @param ax x方向加速度
	 * @param ay y方向加速度
	 * \endif
	 */
	virtual void setAcceleration(float ax, float ay);

	/**
	 * \if English
	 * Set clip rect
	 *
	 * @param clip clip rectangle
	 * @param relativeToSelf true means \c clip is a rectangle relative to self coordinates. Or false
	 * 		means \c clip is a global rectangle
	 * \else
	 * 设置clip矩形, 这可以用来使节点的内容只在指定矩形范围内可见.
	 *
	 * @param clip clip矩形
	 * @param relativeToSelf true表示参数\c clip 代表的是一个相对于节点自身坐标的矩形, false表示
	 * 		参数\c clip 代表的是一个全局坐标矩形. 这是可选参数, 缺省情况下是false.
	 * \endif
	 */
	virtual void setClipRect(wyRect clip, bool relativeToSelf = false);

	/**
	 * \if English
	 * Clear clip rect
	 * \else
	 * 标记当前节点没有裁剪矩形
	 * \endif
	 */
	void clearClipRect() { m_hasClip = false; }

	/**
	 * \if English
	 * Has clip rect set
	 * \else
	 * 节点是否有裁剪矩形
	 * \endif
	 */
	bool hasClipRect() { return m_hasClip; }

	/**
	 * \if English
	 * Get clip rect
	 *
	 * @return clip rectangle
	 * \else
	 * 得到clip矩形
	 *
	 * @return clip矩形
	 * \endif
	 */
	wyRect getClipRect() { return m_clipRect; }

	/**
	 * \if English
	 * Set node acceleration in x axis. It is a simply way to attach physics property to node without
	 * running an action or maintaining physics engine
	 *
	 * @param ax x acceleration
	 * \else
	 * 设置节点的加速度. 方便于设置简单的物理功能, 对于只需要速度加速度的情况, 可以省掉
	 * 自己维护或者使用物理引擎的麻烦.
	 *
	 * @param ax x方向加速度
	 * \endif
	 */
	void setAccelerationX(float ax);

	/**
	 * \if English
	 * Set node acceleration in y axis. It is a simply way to attach physics property to node without
	 * running an action or maintaining physics engine
	 *
	 * @param ay y acceleration
	 * \else
	 * 设置节点的加速度. 方便于设置简单的物理功能, 对于只需要速度加速度的情况, 可以省掉
	 * 自己维护或者使用物理引擎的麻烦.
	 *
	 * @param ay y方向加速度
	 * \endif
	 */
	void setAccelerationY(float ay);

	/**
	 * \if English
	 * Set node velocity in x axis. It is a simply way to attach physics property to node without
	 * running an action or maintaining physics engine
	 *
	 * @param vx x velocity
	 * \else
	 * 设置节点的x方向速度. 方便于设置简单的物理功能, 对于只需要速度加速度的情况, 可以省掉
	 * 自己维护或者使用物理引擎的麻烦.
	 *
	 * @param vx x方向速度
	 * \endif
	 */
	void setVelocityX(float vx);

	/**
	 * \if English
	 * Set node velocity in y axis. It is a simply way to attach physics property to node without
	 * running an action or maintaining physics engine
	 *
	 * @param vy y velocity
	 * \else
	 * 设置节点的y方向速度. 方便于设置简单的物理功能, 对于只需要速度加速度的情况, 可以省掉
	 * 自己维护或者使用物理引擎的麻烦.
	 *
	 * @param vy y方向速度
	 * \endif
	 */
	void setVelocityY(float vy);

	/**
	 * \if English
	 * Get global position of node
	 *
	 * @return if \c m_relativeAnchorPoint is true, returned position is global anchor position, or false
	 * 		means it is global bottom-left position
	 * \else
	 * 得到节点的全局坐标位置。返回的坐标根据relativeAnchorPoint标志的结果，如果是true则
	 * 表示是锚点，如果是false则表示是左下角
	 *
	 * @return 全局坐标位置
	 * \endif
	 */
	wyPoint getAbsolutePosition();

	/**
	 * \if English
	 * Run an action on this node
	 *
	 * @param action subclass of \link wyAction wyAction\endlink
	 * \else
	 * 在这个节点上运行一个动作
	 *
	 * @param action 动作\link wyAction wyAction对象指针\endlink
	 * \endif
	 */
	void runAction(wyAction* action);

	/**
	 * \if English
	 * Stop an action by action tag
	 *
	 * @param tag action tag
	 * \else
	 * 根据动作tag在这个节点上停止一个动作
	 *
	 * @param tag 动作tag
	 * \endif
	 */
	void stopAction(int tag);

	/**
	 * \if English
	 * Stop all actions on this node
	 *
	 * @param includeChildren true means also stop actions in children node recursively. Default is false
	 * \else
	 * 停止所有动作
	 *
	 * @param includeChildren true表示也停止子节点上的所有动作
	 * \endif
	 */
	void stopAllActions(bool includeChildren = false);

	/**
	 * \if English
	 * Pause all action on this node. You can resume it by \c resumeAllActions
	 *
	 * @param includeChildren true means also pause actions in children node recursively. Default is false
	 * \else
	 * 暂停该节点上的所有动作, 之后可以通过resumeAllActions恢复
	 *
	 * @param includeChildren true表示也暂停子节点上的所有动作
	 * \endif
	 */
	void pauseAllActions(bool includeChildren = false);

	/**
	 * \if English
	 * Resume all actions on thisnode
	 *
	 * @param includeChildren true means also resume actions in children node recursively. Default is false
	 * \else
	 * 恢复该节点上的所有动作
	 *
	 * @param includeChildren true表示也恢复子节点上的所有动作
	 * \endif
	 */
	void resumeAllActions(bool includeChildren = false);

	/**
	 * \if English
	 * Pause all timers scheduled on this node. You can resume it by \c resumeAllTimers
	 *
	 * @param includeChildren true means also pause timers in children node recursively. Default is false
	 * \else
	 * 暂停该节点上的所有定时器, 之后可以通过resumeAllTimers恢复
	 *
	 * @param includeChildren true表示也暂停子节点上的所有定时器
	 * \endif
	 */
	void pauseAllTimers(bool includeChildren = false);

	/**
	 * \if English
	 * resume all timers scheduled on this node. You can pause it by \c pauseAllTimers
	 *
	 * @param includeChildren true means also resume timers in children node recursively. Default is false
	 * \else
	 * 恢复该节点上的所有定时器, 之后可以通过\c pauseAllTimers暂停
	 *
	 * @param includeChildren true表示也恢复子节点上的所有定时器
	 * \endif
	 */
	void resumeAllTimers(bool includeChildren = false);

	/**
	 * \if English
	 * Pause one action on this node, by action tag. If no action with given tag is found, do nothing
	 *
	 * \note
	 * If an action is included by a combination action, then pause it is no effect
	 *
	 * @param tag action tag
	 * \else
	 * 暂停一个动作, 要暂停的动作通过tag指定. 如果不存在这个tag的动作, 则不做任何事.
	 * 动作暂停后可以用resumeAction或resumeAllActions恢复运行.
	 *
	 * \note
	 * 如果一个动作被其它的组合类动作所包含, 则暂停这样的动作是无效的
	 *
	 * @param tag 动作的tag
	 * \endif
	 */
	void pauseAction(int tag);

	/**
	 * \if English
	 * Resume one action on this node, by action tag. If no action with given tag is found, do nothing
	 *
	 * @param tag action tag
	 * \else
	 * 恢复一个动作, 要恢复的动作通过tag指定. 如果不存在这个tag的动作, 则不做任何事.
	 *
	 * @param tag 动作的tag
	 * \endif
	 */
	void resumeAction(int tag);

	/**
	 * \if English
	 * Get an action by tag
	 *
	 * @param tag action tag
	 * @return action object, or NULL if no matched action
	 * \else
	 * 通过一个tag得到在这个节点上正在运行的\link wyAction wyAction\endlink 实例
	 *
	 * @param tag 动作的tag
	 * @return \link wyAction wyAction\endlink, 如果没有找到返回NULL
	 * \endif
	 */
	wyAction* getAction(int tag);

	/**
	 * \if English
	 * Check whether there is at least one action running on this node
	 *
	 * @return true means at least one action is running on this node
	 * \else
	 * 检查是否这个节点上有一些动作正在运行
	 *
	 * @return true表示当前有至少一个动作在这个节点上运行
	 * \endif
	 */
	bool hasRunningAction();

	/**
	 * \if English
	 * Convert world point to node space
	 *
	 * @param p point to be converted
	 * @return converted point
	 * \else
	 * 把一个全局坐标的点转换到节点内坐标
	 *
	 * @param p 需要转换的点
	 * @return 转换后的点
	 * \endif
	 */
	wyPoint worldToNodeSpace(wyPoint p);

	/**
	 * \if English
	 * Convert world point to node space. Converted point is relative
	 * to node anchor position
	 *
	 * @param p point to be converted
	 * @return converted point whose position is relative to node anchor
	 * \else
	 * 把一个全局坐标的点转换到节点内坐标, 转换后的点坐标是相对于节点的锚点的
	 *
	 * @param p 需要转换的点
	 * @return 转换后的点
	 * \endif
	 */
	wyPoint worldToNodeSpaceAR(wyPoint p);

	/**
	 * \if English
	 * Convert node point to global coordinates
	 *
	 * @param p point to be converted
	 * @return converted point
	 * \else
	 * 把一个节点坐标的点转换到全局坐标
	 *
	 * @param p 需要转换的点
	 * @return 转换后的点
	 * \endif
	 */
	wyPoint nodeToWorldSpace(wyPoint p);

	/**
	 * \if English
	 * Convert node point to global coordinates. Source point
	 * is relative to node anchor
	 *
	 * @param p point to be converted, its position is relative to node anchor
	 * @return converted point
	 * \else
	 * 把一个节点坐标的点转换到全局坐标, 要转换的点的坐标是相对于节点锚点的
	 *
	 * @param p 需要转换的点, 其坐标是相对于节点锚点的
	 * @return 转换后的点
	 * \endif
	 */
	wyPoint nodeToWorldSpaceAR(wyPoint p);

	/**
	 * \if English
	 * Convert a point in parent node coordinates to node coordinates
	 *
	 * @param p point to be converted
	 * @return converted point
	 * \else
	 * 把一个父节点坐标系的点转换到节点坐标系
	 *
	 * @param p 需要转换的点
	 * @return 转换后的点
	 * \endif
	 */
	wyPoint parentToNodeSpace(wyPoint p);

	/**
	 * \if English
	 * Convert a point in parent node coordinates to node coordinates.
	 * Converted point is relative to node anchor position
	 *
	 * @param p point to be converted
	 * @return converted point whose position is relative to node anchor
	 * \else
	 * 把一个父节点坐标系的点转换到节点坐标系, 转换后的点坐标是相对于节点的锚点的
	 *
	 * @param p 需要转换的点
	 * @return 转换后的点, 其坐标是相对于节点的锚点的
	 * \endif
	 */
	wyPoint parentToNodeSpaceAR(wyPoint p);

	/**
	 * \if English
	 * Convert node point to parent coordinates
	 *
	 * @param p point to be converted
	 * @return converted point
	 * \else
	 * 把一个节点坐标的点转换到父节点坐标
	 *
	 * @param p 需要转换的点
	 * @return 转换后的点
	 * \endif
	 */
	wyPoint nodeToParentSpace(wyPoint p);

	/**
	 * \if English
	 * Convert node point to parent coordinates. Source point
	 * is relative to node anchor
	 *
	 * @param p point to be converted, its position is relative to node anchor
	 * @return converted point
	 * \else
	 * 把一个节点坐标的点转换到父节点坐标, 要转换的点的坐标是相对于节点锚点的
	 *
	 * @param p 需要转换的点, 其坐标是相对于节点锚点的
	 * @return 转换后的点
	 * \endif
	 */
	wyPoint nodeToParentSpaceAR(wyPoint p);

	/**
	 * \if English
	 * Get bounding rectangle of node which doesn't consider scale and rotation
	 *
	 * @return bounding rectangle in self coordinates
	 * \else
	 * 返回节点自身坐标的矩形，(0，0)坐标到(width，height). 返回的矩形不会进行
	 * 变换, 不管节点是设置了缩放还是旋转, 返回的矩形始终是(0, 0)-(width, height).
	 * 返回矩形的origin代表左下角坐标
	 *
	 * @return \link wyRect wyRect结构\endlink
	 * \endif
	 */
	wyRect getBoundingBox();

	/**
	 * \if English
	 * Get bounding rectangle relative to parent space. It consider node scale
	 * and rotation.
	 *
	 * @return bounding rectangle in parent space
	 * \else
	 * 返回节点自身针对父节点坐标的矩形, 这个矩形经过了变换, 比如如果节点的原始
	 * 大小是(100, 100), 但是节点设置了放大2倍, 则得到的矩形大小是(200, 200).
	 * 但是如果节点还设置了旋转, 则返回的矩形是外接矩形, 其大小不一定反映节点的
	 * 真实宽高. 返回矩形的origin代表左下角坐标
	 *
	 * @return \link wyRect wyRect结构\endlink
	 * \endif
	 */
	wyRect getBoundingBoxRelativeToParent();

	/**
	 * \if English
	 * Get bounding rectangle relative to global space. It consider node scale
	 * and rotation
	 *
	 * @return bounding rectangle in global space
	 * \else
	 * 返回节点自身针对整个坐标轴坐标的矩形, 这个矩形经过了变换, 比如如果节点的原始
	 * 大小是(100, 100), 但是节点设置了放大2倍, 则得到的矩形大小是(200, 200).
	 * 但是如果节点还设置了旋转, 则返回的矩形是外接矩形, 其大小不一定反映节点的
	 * 真实宽高. 返回矩形的origin代表左下角坐标
	 *
	 * @return \link wyRect wyRect结构\endlink
	 * \endif
	 */
	wyRect getBoundingBoxRelativeToWorld();

	/**
	 * \if English
	 * Whether or not receive accelerometer event
	 *
	 * @param enabled true means receive accelerometer event
	 * \else
	 * 设置是否启用接收加速器事件
	 *
	 * @param enabled true表示启用接收
	 * \endif
	 */
	void setAccelerometerEnabled(bool enabled);

	/**
	 * \if English
	 * Whether or not receive key event
	 *
	 * @param enabled true means receive key event
	 * \else
	 * 设置是否接收键盘事件
	 *
	 * @param enabled true表示启用接收
	 * \endif
	 */
	void setKeyEnabled(bool enabled);

	/**
	 * \if English
	 * Whether or not receive touch event
	 *
	 * @param enabled true means receive touch event
	 * \else
	 * 设置是否接收触摸事件
	 *
	 * @param enabled true表示启用接收
	 * \endif
	 */
	void setTouchEnabled(bool enabled);

	/**
	 * \if English
	 * Whether or not receive double tap event
	 *
	 * @param enabled true means receive double tap event
	 * \else
	 * 设置是否接收双击事件
	 *
	 * @param enabled true表示启用接收
	 * \endif
	 */
	void setDoubleTapEnabled(bool enabled);

	/**
	 * \if English
	 * Set receive gesture event or not
	 *
	 * @param enabled true means receive gesture event
	 * \else
	 * 设置是否接收手势事件
	 *
	 * @param enabled true表示启用接收
	 * \endif
	 */
	void setGestureEnabled(bool enabled);

	/**
	 * \if English
	 * Whether or not touch event is enabled for this node
	 *
	 * @return true means touch event is enabled for this node
	 * \else
	 * 获得当前是否接收触摸事件
	 *
	 * @return true表示启用接收
	 * \endif
	 */
	bool isTouchEnabled() { return m_touchEnabled; }

	/**
	 * \if English
	 * Whether or not key event is enabled for this node
	 *
	 * @return true means key event is enabled for this node
	 * \else
	 * 获得当前是否接收键盘事件
	 *
	 * @return true表示启用接收
	 * \endif
	 */
	bool isKeyEnabled() { return m_keyEnabled; }

	/**
	 * \if English
	 * Whether or not accelerometer event is enabled for this node
	 *
	 * @return true means accelerometer event is enabled for this node
	 * \else
	 * 获得当前是否接收加速事件
	 *
	 * @return true表示启用接收
	 * \endif
	 */
	bool isAccelerometerEnabled() { return m_accelerometerEnabled; }

	/**
	 * \if English
	 * Whether or not gesture event is enabled for this node
	 *
	 * @return true means gesture event is enabled for this node
	 * \else
	 * 获得当前是否接收手势事件
	 *
	 * @return true表示启用接收
	 * \endif
	 */
	bool isGestureEnabled() { return m_gestureEnabled; }

	/**
	 * \if English
	 * Whether or not double tap event is enabled for this node
	 *
	 * @return true means double tap event is enabled for this node
	 * \else
	 * 获得当前是否接收双击事件
	 *
	 * @return true表示启用接收
	 * \endif
	 */
	bool isDoubleTabEnabled() { return m_doubleTabEnabled; }

	/**
	 * \if English
	 * Get anchor position relative to self coordinates
	 *
	 * @return x position
	 * \else
	 * 得到锚点相对于节点自身坐标系的x坐标
	 *
	 * @return x位置
	 * \endif
	 */
	float getAnchorPointX() { return m_anchorPointX; }

	/**
	 * \if English
	 * Get anchor position relative to self coordinates
	 *
	 * @return y position
	 * \else
	 * 得到锚点相对于节点自身坐标系的y坐标
	 *
	 * @return y位置
	 * \endif
	 */
	float getAnchorPointY() { return m_anchorPointY; }

	/**
	 * \if English
	 * Get anchor x relative position
	 *
	 * @return x relative position
	 * \else
	 * 得到锚点的x方向比例
	 *
	 * @return 锚点x比例，从0到1
	 * \endif
	 */
	float getAnchorX() { return m_anchorX; }

	/**
	 * \if English
	 * Get anchor relative y position
	 *
	 * @return y relative position
	 * \else
	 * 得到锚点的y方向比例
	 *
	 * @return 锚点y比例，从0到1
	 * \endif
	 */
	float getAnchorY() { return m_anchorY; }

	/**
	 * \if English
	 * Get camera object of this node
	 *
	 * @return \link wyCamera wyCamera\endlink
	 * \else
	 * 得到节点上关联的相机对象
	 *
	 * @return 相机\link wyCamera wyCamera对象指针\endlink
	 * \endif
	 */
	wyCamera* getCamera();

	/**
	 * \if English
	 * Check any camera object is created for this node. Every node has a camera object
	 * but it is lazy created
	 * \else
	 * 检查节点上是否有相机. 相机是一个\link wyCamera wyCamera\endlink对象,
	 * 只在需要的时候才会创建, 因此有可能为NULL.
	 * \endif
	 */
	bool hasCamera() { return m_camera != NULL; }

	/**
	 * \if English
	 * Get attached grid object of node, must be a subclass of \link wyGridController wyGridController\endlink
	 * \else
	 * 得到节点上绑定的网格对象
	 * \endif
	 */
	wyGridController* getGrid() { return m_grid; }

	/**
	 * \if English
	 * Is grid active, if grid is NULL, returns false
	 *
	 * @return true means grid is active
	 * \else
	 * 是否网格是激活的, 如果没有网格, 返回false
	 *
	 * @return true表示网格目前是激活的
	 * \endif
	 */
	bool isGridActive();

	/**
	 * \if English
	 * Is node visible
	 * \else
	 * 得到节点是否可见
	 * \endif
	 */
	bool isVisible() { return m_visible; }

	/**
	 * \if English
	 * Is node focused
	 * \else
	 * 得到节点是否获得焦点
	 * \endif
	 */
	bool isFocused() { return m_focused; }

	/**
	 * \if English
	 * Is node really visible? A node is really visible when all ancestor nodes are visible
	 * \else
	 * 得到节点的真正可见状态，它会检查是否节点的某个祖先节点是不可见的
	 * \endif
	 */
	bool isVisibleFromRoot();

	/**
	 * \if English
	 * Get selected state of node
	 * \else
	 * 得到节点的选择状态
	 * \endif
	 */
	bool isSelected() { return m_selected; }

	/**
	 * \if English
	 * Get node enable state
	 * \else
	 * 得到节点的可用状态
	 * \endif
	 */
	bool isEnabled() { return m_enabled; }

	/**
	 * \if English
	 * Is a node really enabled? A node is really enabled when all ancestor nodes are enabled
	 * \else
	 * 得到节点的可用状态, 它会检查是否节点的某个祖先节点是不是可用的
	 * \endif
	 */
	bool isEnabledFromRoot();

	/**
	 * \if English
	 * Get node OpenGL z value
	 * \else
	 * 得到节点在整个OpenGL中的z order值
	 * \endif
	 */
	float getVertexZ() { return m_vertexZ; }

	/**
	 * \if English
	 * Get node rotation angle, in degree. Positive value is clockwise.
	 * \else
	 * 获取旋转角度，正值表示顺时针，负值表示逆时针
	 * \endif
	 */
	float getRotation() { return m_rotation; }

	/**
	 * \if English
	 * Get position x
	 * \else
	 * 得到当前位置的x值
	 * \endif
	 */
	float getPositionX() { return m_positionX; }

	/**
	 * \if English
	 * Get position y
	 * \else
	 * 得到当前位置的y值
	 * \endif
	 */
	float getPositionY() { return m_positionY; }

	/**
	 * \if English
	 * Get position of bottom left corner.
	 * \else
	 * 获得原点的x坐标, 原点即左下角的x坐标, 根据节点设置的不同, 左下角坐标
	 * 可能等于position也可能不等于
	 * \endif
	 */
	float getOriginX();

	/**
	 * \if English
	 * Get position of bottom left corner
	 * \else
	 * 获得原点的y坐标, 原点即左下角的x坐标, 根据节点设置的不同, 左下角坐标
	 * 可能等于position也可能不等于
	 * \endif
	 */
	float getOriginY();

	/**
	 * \if English
	 * Get flag about anchor and bottom left relationship. true means \c setPosition actually set
	 * anchor position, false means \c setPosition set bottom left position
	 * \else
	 * 得到是否position和anchor position是分离的. true表示\c setPosition设置的是锚点位置. false表示\c setPosition
	 * 		设置的是左下角位置
	 * \endif
	 */
	bool isRelativeAnchorPoint() { return m_relativeAnchorPoint; }

	/**
	 * \if English
	 * Is current node is running. Node is running means the node is in the current scene
	 * \else
	 * 得到节点当前是否在运行中. 节点在运行意味着节点正处于当前场景中
	 * \endif
	 */
	bool isRunning() { return m_running; }

	/**
	 * \if English
	 * Get width of node, in pixels
	 * \else
	 * 得到节点的宽度
	 * \endif
	 */
	float getWidth() { return m_width; }

	/**
	 * \if English
	 * Get height of node, in pixels
	 * \else
	 * 得到节点高度
	 * \endif
	 */
	float getHeight() { return m_height; }

	/**
	 * \if English
	 * Get velocity in x axis
	 * \else
	 * 得到节点在x方向上的速度
	 * \endif
	 */
	float getVelocityX() { return m_velocityX; }

	/**
	 * \if English
	 * Get velocity in y axis
	 * \else
	 * 得到节点在y方向上的速度
	 * \endif
	 */
	float getVelocityY() { return m_velocityY; }

	/**
	 * \if English
	 * Get velocity vector of this node
	 * \else
	 * 得到节点的速度, 单位是像素/秒
	 * \endif
	 */
	wyPoint getVelocity() { return wyp(m_velocityX, m_velocityY); }

	/**
	 * \if English
	 * Get acceleration in x axis
	 * \else
	 * 得到节点的x方向加速度
	 * \endif
	 */
	float getAccelerationX() { return m_accelerationX; }

	/**
	 * \if English
	 * Get acceleration in y axis
	 * \else
	 * 得到节点的y方向加速度
	 * \endif
	 */
	float getAccelerationY() { return m_accelerationY; }

	/**
	 * \if English
	 * Get acceleration vector of node
	 * \else
	 * 得到节点的加速度
	 * \endif
	 */
	wyPoint getAcceleration() { return wyp(m_accelerationX, m_accelerationY); }

	/**
	 * \if English
	 * Get content size of node
	 * \else
	 * 得到节点尺寸\link wySize wySize结构\endlink
	 * \endif
	 */
	wySize getContentSize() { return wys(m_width, m_height); }

	/**
	 * \if English
	 * Get children list
	 * \else
	 * 得到子节点\link wyArray wyArray对象指针\endlink
	 * \endif
	 */
	wyArray* getChildren() { return m_children; }

	/**
	 * \if English
	 * Get child node at specified index
	 *
	 * @param index index of child
	 * @return \link wyNode wyNode\endlink, or NULL if \c index is invalid
	 * \else
	 * 得到指定位置处的子节点
	 *
	 * @param index 子节点索引
	 * @return \link wyNode wyNode\endlink, 如果\c index不合法则返回NULL
	 * \endif
	 */
	wyNode* getChildAt(int index) { return (wyNode*)wyArrayGet(m_children, index); }

	/**
	 * \if English
	 * Get children count
	 * \else
	 * 得到子节点数量
	 * \endif
	 */
	int getChildCount() { return m_children->num; }

	/**
	 * \if English
	 * Get parent node
	 * \else
	 * 得到父节点\link wyNode wyNode对象指针\endlink
	 * \endif
	 */
	wyNode* getParent() { return m_parent; }

	/**
	 * \if English
	 * Set parent node
	 * \else
	 * 设置父节点\link wyNode wyNode对象指针\endlink
	 * \endif
	 */
	void setParent(wyNode* p) { m_parent = p; }

	/**
	 * \if English
	 * Set node tag. Tag is an integer and -1 is default.
	 * \else
	 * 设置节点标识
	 * \endif
	 */
	void setTag(int tag) { m_tag = tag; }

	/**
	 * \if English
	 * Get node tag
	 * \else
	 * 得到节点标识
	 * \endif
	 */
	int getTag() { return m_tag; }

	/**
	 * \if English
	 * Get z order value in parent. It is not OpenGL z value.
	 * \else
	 * 设置节点在父节点中的z轴顺序值
	 * \endif
	 */
	void setZOrder(int z) { m_zOrder = z; }

	/**
	 * \if English
	 * Get z order in parent node
	 * \else
	 * 得到节点在父节点中的z轴顺序值
	 * \endif
	 */
	int getZOrder() { return m_zOrder; }

	/**
	 * \if English
	 * Schedule a timer, the timer is a local timer and will be auto stopped when node exit
	 *
	 * @param t timer object
	 * \else
	 * 添加一个定时器\link wyTimer wyTimer对象指针\endlink. 这种方式添加的定时器是一个局部定时器, 会在
	 * 节点退出时自动停止
	 *
	 * @param t 定时器\link wyTimer wyTimer对象指针\endlink
	 * \endif
	 */
	void scheduleLocked(wyTimer* t);

	/**
	 * \if English
	 * Unschedule a timer, i.e., stop it
	 *
	 * @param t timer object
	 * \else
	 * 删除一个定时器\link wyTimer wyTimer对象指针\endlink
	 *
	 * @param t 定时器\link wyTimer wyTimer对象指针\endlink
	 * \endif
	 */
	void unscheduleLocked(wyTimer* t);

	/**
	 * \if English
	 * should render this node? true means don't render it
	 * \else
	 * 得到是否绘制节点的标志
	 * \endif
	 */
	bool isNoDraw() { return m_noDraw; }

	/**
	 * \if English
	 * Set render this node or not, true means don't render it
	 * \else
	 * 设置是否绘制节点的标志
	 * \endif
	 */
	void setNoDraw(bool flag) { m_noDraw = flag; }

	/**
	 * \if English
	 * Set user data in this node, if user data is a pointer, wyNode won't release
	 * it
	 *
	 * @param ud \link wyUserData wyUserData\endlink
	 * \else
	 * 给当前节点设置自定义的数据, 如果自定义数据是个指针, wyNode不会负责释放
	 *
	 * @param ud \link wyUserData wyUserData\endlink
	 * \endif
	 */
	void setUserData(wyUserData& ud);

	/**
	 * \if English
	 * Get user data reference
	 *
	 * @return reference of user data, you can change it
	 * \else
	 * 返回用户数据
	 *
	 * @return 用户数据的引用
	 * \endif
	 */
	wyUserData& getUserData() { return m_data; }

#if ANDROID
	
	/**
	 * \if English
	 * Set custom data which is a java object
	 * \else
	 * 设置一个自定义数据, 其是一个java对象
	 * \endif
	 */
	void setJavaData(jobject data);
	
	/**
	 * \if English
	 * Get custom data in java object format
	 * \else
	 * 得到java对象形式的自定义数据
	 * \endif
	 */
	jobject getJavaData() { return m_data.jo; }
	
	/**
	 * \if English
	 * Set java layer touch event listener, only for java developer
	 * \else
	 * 设置java层触摸事件监听器, 这个方法是为了提供java端事件处理支持, 在
	 * native端不应该直接使用.
	 * \endif
	 */
	void setJavaTouchHandler(jobject h);

	/**
	 * \if English
	 * Get java layer touch event listener
	 * \else
	 * 得到java层的触摸事件监听器
	 * \endif
	 */
	jobject getJavaTouchHandler() { return m_jTouchHandler; }

	/**
	 * \if English
	 * Set java layer key event handler
	 * \else
	 * 设置java层按键事件监听器, 这个方法是为了提供java端事件处理支持, 在
	 * native端不应该直接使用.
	 * \endif
	 */
	void setJavaKeyHandler(jobject h);

	/**
	 * \if English
	 * Get java layer key event handler
	 * \else
	 * 得到java层的按键事件监听器
	 * \endif
	 */
	jobject getJavaKeyHandler() { return m_jKeyHandler; }

	/**
	 * \if English
	 * Set java layer accelerometer event handler
	 * \else
	 * 设置java层加速事件监听器, 这个方法是为了提供java端事件处理支持, 在
	 * native端不应该直接使用.
	 * \endif
	 */
	void setJavaAccelHandler(jobject h);

	/**
	 * \if English
	 * Get java layer accelerometer event handler
	 * \else
	 * 得到java层的加速事件监听器
	 * \endif
	 */
	jobject getJavaAccelHandler() { return m_jAccelHandler; }

	/**
	 * \if English
	 * Set java layer double tap event handler
	 * \else
	 * 设置java层双击事件监听器, 这个方法是为了提供java端事件处理支持, 在
	 * native端不应该直接使用.
	 * \endif
	 */
	void setJavaDoubleTapHandler(jobject h);

	/**
	 * \if English
	 * Get java layer double tap event handler
	 * \else
	 * 得到java层的双击事件监听器
	 * \endif
	 */
	jobject getJavaDoubleTapHandler() { return m_jDoubleTapHandler; }

	/**
	 * \if English
	 * Set java layer gesture event handler
	 * \else
	 * 设置java层手势事件监听器, 这个方法是为了提供java端事件处理支持, 在
	 * native端不应该直接使用.
	 * \endif
	 */
	void setJavaGestureHandler(jobject h);

	/**
	 * \if English
	 * Get java layer gesture event handler
	 * \else
	 * 得到java层的手势事件监听器
	 * \endif
	 */
	jobject getJavaGestureHandler() { return m_jGestureHandler; }

	/**
	 * \if English
	 * Set a java side virtual method implementor, so java layer can intercept native virtual method calling
	 * \else
	 * 设置java层方法回调对象, 通过这种方式允许java端覆盖native端的虚方法
	 * \endif
	 */
	void setJavaVirtualMethods(jobject h);

	/**
	 * \if English
	 * Get java side virtual method implementor
	 * \else
	 * 得到java层方法回调对象
	 * \endif
	 */
	jobject getJavaVirtualMethods() { return m_jVirtualMethods; }

	/**
	 * \if English
	 * Set java side position listener
	 * \else
	 * 设置java层的位置事件回调接口
	 * \endif
	 */
	void setPositionListener(jobject listener);
	
#endif // #if ANDROID
	
	/**
	 * \if English
	 * Set selector to be triggered when touch down
	 * \else
	 * 设置节点按下\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * \endif
	 */
	void setDownSelector(wyTargetSelector* ts);

	/**
	 * \if English
	 * Get selector to be triggered when touch down
	 * \else
	 * 得到节点按下\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * \endif
	 */
	wyTargetSelector* getDownSelector() { return m_downSelector; }

	/**
	 * \if English
	 * Set selector to be triggered when touch up
	 * \else
	 * 设置节点松开\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * \endif
	 */
	void setUpSelector(wyTargetSelector* ts);

	/**
	 * \if English
	 * Get selector to be triggered when touch up
	 * \else
	 * 得到节点松开\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * \endif
	 */
	wyTargetSelector* getUpSelector() { return m_upSelector; }

	/**
	 * \if English
	 * Set selector to be triggered when touch point move outside of node
	 * \else
	 * 设置节点按下后移出\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * \endif
	 */
	void setMoveOutSelector(wyTargetSelector* ts);

	/**
	 * \if English
	 * Get selector to be triggered when touch point moves outside of node
	 * \else
	 * 得到节点按下后移出\link wyTargetSelector wyTargetSelector对象指针\endlink
	 * \endif
	 */
	wyTargetSelector* getMoveOutSelector() { return m_moveOutSelector; }

	/* other optional interface, we don't use multiple inheritance */

	/* IFrames */
	/**
	 * \if English
	 * Add an animation to this node, then it can be obtained by animation id
	 *
	 * @param animation \link wyAnimation wyAnimation\endlink
	 * \else
	 * 添加一个动画
	 *
	 * @param animation \link wyAnimation wyAnimation对象指针\endlink
	 * \endif
	 */
	virtual void addAnimation(wyAnimation* animation) {}

	/**
	 * \if English
	 * Get animation by animation id
	 *
	 * @param id animation id
	 * @return \link wyAnimation wyAnimation\endlink
	 * \else
	 * 通过id获得动画对象
	 *
	 * @param id 动画id
	 * @return \link wyAnimation wyAnimation对象指针\endlink
	 * \endif
	 */
	virtual wyAnimation* getAnimationById(int id) { return NULL; }

	/**
	 * \if English
	 * Get current frame, or NULL if no frame set
	 *
	 * @return current frame object
	 * \else
	 * 获得当前帧
	 *
	 * @return \link wyFrame wyFrame对象指针\endlink, 如果当前没有帧被设置，则可以返回NULL
	 * \endif
	 */
	virtual wyFrame* getDisplayFrame() { return NULL; }

	/**
	 * \if English
	 * Check a frame is set or not
	 *
	 * @param frame frame object
	 * @return true means this frame is set
	 * \else
	 * 检查某帧是否现在正在显示
	 *
	 * @param frame \link wyFrame wyFrame对象指针\endlink
	 * @return true为是
	 * \endif
	 */
	virtual bool isFrameDisplayed(wyFrame* frame) { return false; }

	/**
	 * \if English
	 * Set current frame
	 *
	 * @param newFrame frame object
	 * \else
	 * 设置当前帧
	 *
	 * @param newFrame \link wyFrame wyFrame对象指针\endlink
	 * \endif
	 */
	virtual void setDisplayFrame(wyFrame* newFrame) {}

	/**
	 * \if English
	 * Set frame by animation id and frame index
	 *
	 * @param id animation id
	 * @param frameIndex frame index
	 * \else
	 * 通过动画id和帧索引设置当前帧
	 *
	 * @param id 动画id
	 * @param frameIndex 帧索引
	 * \endif
	 */
	virtual void setDisplayFrameById(int id, int frameIndex) {}

	/* ILabel */

	/**
	 * \if English
	 * Get text
	 *
	 * @return text in utf-8 encoding
	 * \else
	 * 获得文字内容, 字符串以NULL结尾
	 *
	 * @return 返回的字符串，编码为utf-8
	 * \endif
	 */
	virtual const char* getText() { return NULL; }

	/**
	 * \if English
	 * If a node supports setting text, it should implement this method
	 *
	 * @param text text in utf-8 encoding
	 * \else
	 * 设置文字内容. 如果一个节点支持设置文字内容，则应该实现这个方法
	 *
	 * @param text 要显示的字符串，NULL结尾，编码为utf-8, 可以通过wyUtils::getString获得字符串资源
	 * \endif
	 */
	virtual void setText(const char* text) {}

	/* ITransparent */

	/**
	 * \if English
	 * Get current alpha
	 * \else
	 * 得到当前alpha值
	 * \endif
	 */
	virtual int getAlpha() { return m_color.a; }

	/**
	 * \if English
	 * Set node alpha
	 * \else
	 * 设置alpha值
	 * \endif
	 */
	virtual void setAlpha(int alpha);

	/* IRGB */

	/// Get node color in 3B format
	virtual wyColor3B getColor() { return wyc4b2c3b(m_color); }

	/// get colro in 4B format
	virtual wyColor4B getColor4B() { return m_color; }

	/**
	 * \if English
	 * Get node color
	 * \else
	 * 设置颜色
	 * \endif
	 */
	virtual void setColor(wyColor3B color);

	/**
	 * \if English
	 * Set node color
	 * \else
	 * 设置颜色
	 * \endif
	 */
	virtual void setColor(wyColor4B color);

	/* IDitherable */

	/**
	 * \if English
	 * Is dither enabled or not
	 *
	 * @return true means dither is enabled
	 * \else
	 * 是否打开抖动
	 *
	 * @return true表示抖动已打开
	 * \endif
	 */
	virtual bool isDither();

	/**
	 * \if English
	 * Enable dither or not
	 *
	 * @param flag true means enable dither
	 * \else
	 * 设置是否打开抖动
	 *
	 * @param flag true表示打开抖动, false表示不打开抖动
	 * \endif
	 */
	virtual void setDither(bool flag);

	/* IBlendable */

	/**
	 * \if English
	 * Get current blending mode
	 *
	 * @return blending mode
	 * \else
	 * 得到当前渲染模式
	 *
	 * @return 渲染模式
	 * \endif
	 */
	virtual wyRenderState::BlendMode getBlendMode();

	/**
	 * \if English
	 * Set current blending mode
	 *
	 * @param mode blending mode
	 * \else
	 * 设置当前渲染模式
	 *
	 * @param mode 渲染模式
	 * \endif
	 */
	virtual void setBlendMode(wyRenderState::BlendMode mode);

	/**
	 * Get texture at given index. The index is used to locate render pair
	 *
	 * @param index default value is 0
	 */
	virtual wyTexture2D* getTexture(int index = 0);

	/**
	 * Set texture of node
	 *
	 * @param tex texture
	 * @param index render pair index
	 */
	virtual void setTexture(wyTexture2D* tex, int index = 0);

	/**
	 * \if English
	 * Create a parallax object for this node
	 *
	 * @return \link wyParallaxObject wyParallaxObject\endlink
	 * \else
	 * 为当前节点创建一个视差对象
	 *
	 * @return \link wyParallaxObject wyParallaxObject\endlink
	 * \endif
	 */
	virtual wyParallaxObject* createParallaxObject();

	/**
	 * \if English
	 * Is this node visitable. "Visitable" means its children should be visited when
	 * rendering this node
	 * \else
	 * 标识一个节点是否是可遍历的. "可遍历"指的是渲染该节点时必须递归的渲染每一个子节点
	 * \endif
	 */
	virtual bool isVisitable() { return true; }

	/**
	 * A method can be used to control child visitability. If returns false,
	 * render manager will render the child. By default, it always returns true.
	 *
	 * @param child child node need to be checked
	 * @return true means this child should be visited, false if you don't want to render this child
	 */
	virtual bool isChildVisitable(wyNode* child) { return true; }

	/**
	 * Invoked just before rendering this node
	 */
	virtual void beforeRender() {}

	/**
	 * Invoked just after rendering this node
	 */
	virtual void afterRender() {}

	/**
	 * \if English
	 * Update material
	 * \else
	 * 更新材质参数
	 * \endif
	 */
	virtual void updateMaterial() {}

	/**
	 * \if English
	 * Update mesh
	 * \else
	 * 更新网格
	 * \endif
	 */
	virtual void updateMesh() {}

	/**
	 * \if English
	 * Update mesh color
	 * \else
	 * 更新网格颜色信息
	 * \endif
	 */
	virtual void updateMeshColor() {}

	/**
	 * \if English
	 * Adjust node size to contain all children. It won't consider child node scale or rotation
	 *
	 * \note
	 * If child node exceeds left or bottom edge of parent node, the exceeded part is not calculated
	 * \else
	 * 把当前节点的大小调整为能完整包含所有子节点，如果当前节点有一个子节点，它
	 * 相对于当前节点的坐标是(10, 10), 大小是(100, 100), 那么实际上要把当前
	 * 节点的大小改成(110, 110). 如果子节点在该方法调用时还具有旋转或缩放的属性，
	 * 则实际计算的是子节点的外接矩形。该方法不会考虑子节点的缩放和旋转.
	 *
	 * \note
	 * 如果一个子节点超出了节点的下边界或者左边界, 则其超过的部分不会考虑在内
	 * \endif
	 */
	void sizeToFit();

	/**
	 * \if English
	 * Get best size which can contain all children node. It doesn't consider child node
	 * scale or rotation. However, if a child node exceeds left or bottom edge of parent node,
	 * it will be also included. So the result may be different with \c sizeToFit
	 *
	 * @return minimum size of all children node combination
	 * \else
	 * 计算一个完全包含所有子节点的最小大小, 这个方法会考虑超出节点下边界或者左边界的情况, 因此
	 * 它得到的大小不一定是sizeToFit的结果. 该方法不会考虑子节点的缩放和旋转.
	 *
	 * @return 完全包含所有子节点的最小大小
	 * \endif
	 */
	wySize getFitSize();

	/**
	 * \if English
	 * Enlarge node size with given delta
	 *
	 * @param left delta size to expand in left
	 * @param top delta size to expand in top
	 * @param right delta size to expand in right
	 * @param bottom delta size to expand in bottom
	 * \else
	 * 将节点扩大, 扩大的尺寸通过四个方向的距离指定. 这个方法配合sizeToFit使用, 可以较方便的
	 * 控制父节点的大小.
	 *
	 * @param left 左边扩大的大小
	 * @param top 上边扩大的大小
	 * @param right 右边扩大的大小
	 * @param bottom 下边扩大的大小
	 * \endif
	 */
	void enlargeNode(float left, float top, float right, float bottom);

	/**
	 * \if English
	 * Release object. This method is only called from java layer. Don't call it manually.
	 * \else
	 * 在lazy release pool中查找某个对象, 如果找到了, 则从lazy release
	 * pool中删除并减少引用计数. 这个方法主要的目的是方便java层能够释放native层
	 * 对象, 开发者在任何时候都不应该调用此方法.
	 * \endif
	 */
	void javaRelease(bool includeChildren);

	/**
	 * \if English
	 * Set priority of touch event handling
	 * \else
	 * 设置触摸事件优先级
	 * \endif
	 */
	void setTouchPriority(int p) { m_touchPriority = p; }

	/**
	 * \if English
	 * Set priority of key event handling
	 * \else
	 * 设置按键事件优先级
	 * \endif
	 */
	void setKeyPriority(int p) { m_keyPriority = p; }

	/**
	 * \if English
	 * Set priority of gesture event handling
	 * \else
	 * 设置手势事件优先级
	 * \endif
	 */
	void setGesturePriority(int p) { m_gesturePriority = p; }

	/**
	 * \if English
	 * Set priority of double tap handling
	 * \else
	 * 设置双击事件优先级
	 * \endif
	 */
	void setDoubleTapPriority(int p) { m_doubleTapPriority = p; }

	/**
	 * \if English
	 * Set priority of accelerometer event handling
	 * \else
	 * 设置加速器事件优先级
	 * \endif
	 */
	void setAccelerometerPriority(int p) { m_accelerometerPriority = p; }

	/**
	 * \if English
	 * Get priority of touch event handling
	 * \else
	 * 获得触摸事件优先级
	 * \endif
	 */
	int getTouchPriority() { return m_touchPriority; }

	/**
	 * \if English
	 * Get priority of key event handling
	 * \else
	 * 获得按键事件优先级
	 * \endif
	 */
	int getKeyPriority() { return m_keyPriority; }

	/**
	 * \if English
	 * Get priority of gesture event handling
	 * \else
	 * 获得手势事件优先级
	 * \endif
	 */
	int getGesturePriority() { return m_gesturePriority; }

	/**
	 * \if English
	 * Get priority of double tap event handling
	 * \else
	 * 获得双击事件优先级
	 * \endif
	 */
	int getDoubleTapPriority() { return m_doubleTapPriority; }

	/**
	 * \if English
	 * Get priority of accelerometer event handling
	 * \else
	 * 获得加速器事件优先级
	 * \endif
	 */
	int getAccelerometerPriority() { return m_accelerometerPriority; }

	/**
	 * \if English
	 * Set position listener
	 *
	 * @param listener \link wyNodePositionListener wyNodePositionListener\endlink
	 * @param data custom data
	 * \else
	 * 设置位置事件回调接口
	 *
	 * @param listener \link wyNodePositionListener wyNodePositionListener\endlink
	 * @param data 附加数据指针
	 * \endif
	 */
	virtual void setPositionListener(wyNodePositionListener* listener, void* data);

	/**
	 * \if English
	 * Set intercept event or not. If true, default event handler returns true, or false returns false.
	 * When a event handler returns true, handler after that won't receive event
	 * \else
	 * 设置是否不让后续节点处理触摸事件. 该标志仅当setTouchEnabled(true)时有效.
	 * 缺省值是true, 即不让后续节点继续处理事件.
	 * \endif
	 */
	virtual void setInterceptTouch(bool flag) { m_interceptTouch = flag; }

	/**
	 * \if English
	 * Checking a node is ancestor of current node
	 *
	 * @param node node to be checked
	 * @return true if \c node is ancestor of current node
	 * \else
	 * 判断当前节点是否是某个节点的父节点或更高的节点
	 *
	 * @param node 要检查的节点, 如果该节点是当前节点的子孙, 则返回true
	 * @return 如果\c node 是当前节点的子孙, 则返回true
	 * \endif
	 */
	virtual bool isAncestor(wyNode* node);

	/**
	 * \if English
	 * Set whether node should trigger click behavior for non-first touch point
	 * \else
	 * 设置节点是否在非第一触点的情况下也触发点击事件
	 * \endif
	 */
	virtual void setMultiTouchClickable(bool flag) { m_multiTouchClickable = flag; }

	/**
	 * \if English
	 * Whether node should trigger click behavior for non-first touch point
	 * \else
	 * 节点是否在非第一触点的情况下也触发点击事件
	 * \endif
	 */
	virtual bool isMultiTouchClickable() { return m_multiTouchClickable; }

	/**
	 * \if English
	 * Set flag indicating material need to be updated before rendering
	 *
	 * @param flag true means need update
	 * \else
	 * 标记材质参数是否需要更新
	 *
	 * @param flag true表示材质参数需要更新
	 * \endif
	 */
	virtual void setNeedUpdateMaterial(bool flag) { m_materialNeedUpdate = flag; }

	/**
	 * \if English
	 * Set flag indicating mesh need to be updated before rendering
	 *
	 * @param flag true means need update
	 * \else
	 * 标记mesh需要被更新
	 *
	 * @param flag true表示mesh需要被更新
	 * \endif
	 */
	virtual void setNeedUpdateMesh(bool flag) { m_meshNeedUpdate = flag; }

	/**
	 * \if English
	 * Set flag indicating mesh color need to be updated before rendering
	 *
	 * @param flag true means need update
	 * \else
	 * 标记mesh的颜色信息需要被更新
	 *
	 * @param flag true表示mesh颜色需要被更新
	 * \endif
	 */
	virtual void setNeedUpdateMeshColor(bool flag) { m_meshColorNeedUpdate = flag; }

	/**
	 * \if English
	 * Is material need to be updated?
	 *
	 * @return true means need update
	 * \else
	 * 材质是否需要更新
	 *
	 * @return true表示需要更新
	 * \endif
	 */
	virtual bool isNeedUpdateMaterial() { return m_materialNeedUpdate; }

	/**
	 * \if English
	 * Is mesh need to be updated?
	 *
	 * @return true means need update
	 * \else
	 * mesh是否需要更新
	 *
	 * @return true表示需要更新
	 * \endif
	 */
	virtual bool isNeedUpdateMesh() { return m_meshNeedUpdate; }

	/**
	 * \if English
	 * Is mesh color need to be updated?
	 *
	 * @return true means need update
	 * \else
	 * mesh颜色是否需要更新
	 *
	 * @return true表示需要更新
	 * \endif
	 */
	virtual bool isNeedUpdateMeshColor() { return m_meshColorNeedUpdate; }

	/**
	 * Return count of bounded material and mesh
	 */
	virtual int getRenderPairCount() { return m_renderPairs->size(); }

	/**
	 * Add a render pair. A render pair consists of material and mesh
	 *
	 * @param material material
	 * @param mesh mesh
	 */
	virtual void addRenderPair(wyMaterial* material, wyMesh* mesh);

	/**
	 * Remove a render pair which is matched by selector
	 *
	 * @param sel custom selector used to select render pair
	 * @param data extra data will be passed to selector
	 */
	virtual void removeRenderPair(wyRenderPairSelector* sel, void* data);

	/**
	 * Find a mesh by tag, it only returns first mesh matched
	 *
	 * @param tag tag of mesh
	 * @return mesh object, or NULL if no match
	 */
	virtual wyMesh* getMeshByTag(int tag);

	/// remove all render pairs
	virtual void clearRenderPairs();

	/**
	 * Replace material of render pair at given index
	 *
	 * @param material new material
	 * @param index render pair index
	 */
	virtual void replaceMaterial(wyMaterial* material, int index = 0);

	/**
	 * Get mesh at specified index
	 *
	 * @param index index of mesh, for node which only has one render pair, this parameter
	 * 		is useless. So it is optional and default value is zero.
	 * @return \link wyMesh wyMesh\endlink
	 */
	virtual wyMesh* getMesh(int index = 0);

	/**
	 * Set material
	 *
	 * @param index index of material, for node which only has one render pair, this parameter
	 * 		is useless. So it is optional and default value is zero.
	 * @return \link wyMaterial wyMaterial\endlink
	 */
	virtual wyMaterial* getMaterial(int index = 0);

    /**
     * Returns the LOD level
     *
	 * @param index index of mesh, for node which only has one render pair, this parameter
	 * 		is useless. So it is optional and default value is zero.
     * @return the LOD level set
     */
    virtual int getLodLevel(int index = 0);

    /**
     * Set the LOD level
     *
     * @param level the LOD level
	 * @param index index of mesh, for node which only has one render pair, this parameter
	 * 		is useless. So it is optional and default value is zero.
     */
    virtual void setLodLevel(int level, int index = 0);

	/**
	 * \if English
	 * Get clip rect which is transformed if relative self flag is true
	 *
	 * @return clip rect transformed
	 * \else
	 * 得到最终的裁剪矩形, 如果裁剪矩形是相对于自身的, 则这个方法可以获得最终的裁剪矩形
	 *
	 * @return 最终的裁剪矩形
	 * \endif
	 */
	virtual wyRect getResolvedClipRect();

	/**
	 * \if English
	 * Get queue bucket id, default value is \c wyRenderQueue::INHERIT
	 *
	 * @return queue bucket id
	 * \else
	 * 得到渲染队列标识, 缺省是\c wyRenderQueue::INHERIT
	 *
	 * @return 本节点所属的渲染队列标识
	 * \endif
	 */
	virtual wyRenderQueue::Bucket getQueueBucket();

	/**
	 * \if English
	 * Set queue bucket id
	 *
	 * @param bucket queue bucket id
	 * \else
	 * 设置渲染队列标识
	 *
	 * @param bucket 本节点所属的渲染队列标识
	 * \endif
	 */
	virtual void setQueueBucket(wyRenderQueue::Bucket bucket) { m_queueBucket = bucket; }

	/**
	 * \if English
	 * Set a touch coffin to this node. A touch coffin is a node which means
	 * current node touch event must occurs in coffin node content area. Otherwise
	 * the touch event will be ignored
	 *
	 * \note
	 * Node won't retain coffin node, so you must ensure the coffin node is clear when
	 * it is released
	 * \else
	 * 给当前节点设置一个触摸范围. 这个触摸范围由另外一个节点来指定. 也就是当前节点的触摸事件必须也发生
	 * 在指定节点的范围内才有效(实际上就是对两个节点的大小取个交集).
	 *
	 * \note
	 * 该节点不会被retain, 因此要注意如果其被释放, 要清空存在的引用
	 * \endif
	 */
	void setTouchCoffin(wyNode* c) { m_touchCoffin = c; }

	/**
	 * \if English
	 * Get touch coffin touch bound to this node
	 * \else
	 * 得到当前节点绑定的触摸范围限制节点
	 * \endif
	 */
	wyNode* getTouchCoffin() { return m_touchCoffin; }

	/// apply node matrix to top matrix of world matrix stack
	void applyWorldMatrix();
};

#endif // __wyNode_h__
