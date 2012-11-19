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
 * Used to monitor node position change event
 */
class WIENGINE_API wyNodePositionCallback {
public:
	/**
	 * Invoked when node's position is changed. That could be a result
	 * of \c setPosition or \c translate calling
	 *
	 * @param node \link wyNode wyNode\endlink
	 */
	virtual void onNodePositionChanged(wyNode* node) = 0;
};

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

	/// node position callback
	wyNodePositionCallback* m_positionCallback;
	
	/// touch event should in such node content rect
	/// it won't be retained by current node
	wyNode* m_touchCoffin;

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
     * Invoked when node will become active. Active means related scene is running.
     * This method is called from internal and generally you should not call it from
     * program
     */
	virtual void onEnter();

    /**
     * Invoked when this node is removed from parent or related scene is gone.
     * This method is called internal and generally you should not call it from
     * program
     */
	virtual void onExit();

    /**
     * Invoked when a transition is done. It is called from internal and
     * you should not call it from program
     */
	virtual void onEnterTransitionDidFinish();

    /**
     * Invoked when this node is added to a parent node, it occurs
     * before \c onEnter
     *
     * @param parent parent node
     */
	virtual void onAttachToParent(wyNode* parent);

    /**
     * Invoked when this node is removed from parent, it occurs before
     * \c onExit
     *
     * @param parent parent node
     */
	virtual void onDetachFromParent(wyNode* parent);

	/**
	 * Clear timers on this node
	 */
	virtual void cleanup();

	/**
	 * Set anchor relative position
	 *
	 * @param x relative x position
	 * @param y relative y position
	 */
	virtual void setAnchor(float x, float y);

	/**
	 * Set anchor relative x position
	 *
	 * @param x relative x position
	 */
	virtual void setAnchorX(float x);

	/**
	 * Set anchor relative y position
	 *
	 * @param y relative y position
	 */
	virtual void setAnchorY(float y);

	/**
	 * Reset anchor relative position but doesn't change node bound rect relative to
	 * parent
	 *
	 * @param x new anchor x relative position
	 * @param y new anchor y relative position
	 */
	virtual void moveAnchorTo(float x, float y);

	/**
	 * Set size of node
	 *
	 * @param w width of node in pixel
	 * @param h height of node in pixel
	 */
	virtual void setContentSize(float w, float h);

	/**
	 * Set node position, the method behavior is affected by \c m_relativeAnchorPoint flag.
	 * If \c m_relativeAnchorPoint is true, this method set anchor to that position. If \c m_relativeAnchorPoint
	 * is false, this method set bottom-left corner to that position
	 *
	 * @param x x position
	 * @param y y position
	 */
	virtual void setPosition(float x, float y);

	/**
	 * Set node position by delta. It is same as \c setPosition(getPositionX() + x, getPositionY() + y).
	 *
	 * @param x delta x
	 * @param y delta y
	 */
	virtual void translate(float x, float y);

	/**
	 * Translate all direct children node
	 *
	 * @param x delta x
	 * @param y delta y
	 */
	virtual void translateChildren(float x, float y);

	/**
	 * Set rotation angle in degree. Positive value rotates in clockwise, or negative value
	 * to counter-clockwise
	 *
	 * @param rot rotation in degree
	 */
	virtual void setRotation(float rot);

	/**
	 * Set scale rate of node
	 *
	 * @param scale scale rate
	 */
	virtual void setScale(float scale);

	/**
	 * Set scale rate along x axis
	 *
	 * @param scaleX scale in x axis
	 */
	virtual void setScaleX(float scaleX);

	/**
	 * Set scale rate along y axis
	 *
	 * @param scaleY scale in y axis
	 */
	virtual void setScaleY(float scaleY);

	/**
	 * The X skew angle of the node in degrees. This angle describes the shear distortion in the X direction.
	 * Thus, it is the angle between the Y axis and the left edge of the shape. The default skewX angle is 0.
	 * Positive values distort the node in a CCW direction.
	 */
	virtual void setSkewX(float degree);

	/**
	 * The Y skew angle of the node in degrees. This angle describes the shear distortion in the Y direction.
	 * Thus, it is the angle between the X axis and the bottom edge of the shape. The default skewY angle is 0.
	 * Positive values distort the node in a CCW direction.
	 */
	virtual void setSkewY(float degree);

	/**
	 * Set selected flag of node
	 *
	 * @param selected selected state or not
	 */
	virtual void setSelected(bool selected) { m_selected = selected; }

	/**
	 * Set z order value in OpenGL
	 *
	 * @param vertexZ z order value in OpenGL
	 */
	virtual void setVertexZ(float vertexZ) { m_vertexZ = vertexZ; }

	/**
	 * Set visibility of node. If false, then all children's isVisibleFromRoot returns false.
	 * An invisible node can't receive event and children node also can't.
	 *
	 * @param visible true means visible
	 */
	virtual void setVisible(bool visible) { m_visible = visible; }

	/**
	 * Set focus state of node. This flag doesn't affect event handling. It is only
	 * a flag and only useful for full-keyboard mobile phone.
	 *
	 * @param focused true means node is in focused state
	 */
	virtual void setFocused(bool focused);

	/**
	 * Set enable state of node. If false, all children's isEnabledFromRoot() will returns false.
	 * A disabled node can't process event and children also can't. But disabled node is still visible.
	 *
	 * @param enabled true means node is enabled
	 */
	virtual void setEnabled(bool enabled) { m_enabled = enabled; }

	/**
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
	 */
	virtual void accelerometerChanged(float accelX, float accelY, float accelZ);

	/**
	 * Key down event handler
	 *
	 * @param e \link wyKeyEvent wyKeyEvent\endlink
	 */
	virtual bool keyDown(wyKeyEvent& e);

	/**
	 * Key up event handler
	 *
	 * @param e \link wyKeyEvent wyKeyEvent\endlink
	 */
	virtual bool keyUp(wyKeyEvent& e);

	/**
	 * Key multiple event handler
	 *
	 * @param e \link wyKeyEvent wyKeyEvent\endlink
	 */
	virtual bool keyMultiple(wyKeyEvent& e);
	
	/**
	 * Touch began event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 */
	virtual bool touchesBegan(wyMotionEvent& e);

	/**
	 * Touch moved event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 */
	virtual bool touchesMoved(wyMotionEvent& e);

	/**
	 * Touch ended event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 */
	virtual bool touchesEnded(wyMotionEvent& e);

	/**
	 * Touch cancelled event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 */
	virtual bool touchesCancelled(wyMotionEvent& e);

	/**
	 * Touch pointer began event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 */
	virtual bool touchesPointerBegan(wyMotionEvent& e);

	/**
	 * Touch pointer ended event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 */
	virtual bool touchesPointerEnded(wyMotionEvent& e);

	/**
	 * double tap event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 */
	virtual bool onDoubleTap(wyMotionEvent& e);

	/**
	 * double tap event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 */
	virtual bool onDoubleTapEvent(wyMotionEvent& e);

	/**
	 * single tap event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 */
	virtual bool onSingleTapConfirmed(wyMotionEvent& e);

	/**
	 * Down event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 */
	virtual bool onDown(wyMotionEvent& e);

	/**
	 * Fling event handler
	 *
	 * @param e1 \link wyMotionEvent wyMotionEvent\endlink
	 * @param e2 \link wyMotionEvent wyMotionEvent\endlink
	 * @param velocityX fling velocity in x axis
	 * @param velocityY fling velocity in y axis
	 */
	virtual bool onFling(wyMotionEvent& e1, wyMotionEvent& e2, float velocityX, float velocityY);

	/**
	 * Long press event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 */
	virtual void onLongPress(wyMotionEvent& event);

	/**
	 * Scroll event handler
	 *
	 * @param e1 \link wyMotionEvent wyMotionEvent\endlink
	 * @param e2 \link wyMotionEvent wyMotionEvent\endlink
	 * @param distanceX scrolling distance in x axis from last event
	 * @param distanceY scrolling distance in y axis from last event
	 */
	virtual bool onScroll(wyMotionEvent& e1, wyMotionEvent& e2, float distanceX, float distanceY);

	/**
	 * Show press event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 */
	virtual void onShowPress(wyMotionEvent& e);

	/**
	 * Single tap up event handler
	 *
	 * @param e \link wyMotionEvent wyMotionEvent\endlink
	 */
	virtual bool onSingleTapUp(wyMotionEvent& e);

	/**
	 * Hit test to check a point is inside node or not. The location must be in global coordinates.
	 * This method will consider node's scale, rotation, etc. And if node is rotation, actually the
	 * bounding rectangle is checked.
	 *
	 * @param x x position
	 * @param y y position
	 * @return true means the point is inside node rectangle
	 */
	virtual bool hitTest(float x, float y);

	/**
	 * Set flag indicating \c setPosition behavior. If true, \c setPosition sets anchor position or false means
	 * \c setPosition set bottom-left position
	 *
	 * @param flag true means \c setPosition sets anchor position or false means
	 * 		\c setPosition set bottom-left position
	 */
	virtual void setRelativeAnchorPoint(bool flag);

	/**
	 * Update transform matrix from node to parent
	 */
	void updateNodeToParentTransform();

	/**
	 * Update transform matrix from parent to node
	 */
	void updateParentToNodeTransform();

	/**
	 * Get transform matrix from node to global
	 *
	 * @return \link wyAffineTransform wyAffineTransform\endlink
	 */
	wyAffineTransform getNodeToWorldTransform();

	/**
	 * Get transform matrix from node to parent
	 *
	 * @retun \link wyAffineTransform wyAffineTransform\endlink
	 */	
	wyAffineTransform getTransformMatrix();

	/**
	 * Get transform matrix from global to node
	 *
	 * @retun \link wyAffineTransform wyAffineTransform\endlink
	 */
	wyAffineTransform getWorldToNodeTransform();

	/**
	 * Set dirty flag of transform matrix. Then node will update transform matrix next time.
	 */
	void setTransformDirty();

	/**
	 * Get current scale rate
	 *
	 * @return scale rate
	 */
	float getScale();

	/**
	 * Get current x scale rate
	 *
	 * @return x scale rate
	 */
	float getScaleX() { return m_scaleX; }

	/**
	 * Get current y scale rate
	 *
	 * @return y scale rate
	 */
	float getScaleY() { return m_scaleY; }

	/**
	 * Get X axis shear distortion degree. Positive value is counter-clockwise
	 */
	float getSkewX() { return m_skewX; }

	/**
	 * Get Y axis shear distortion degree. Positive value is counter-clockwise
	 */
	float getSkewY() { return m_skewY; }

	/**
	 * Set grid object for this node
	 *
	 * @param grid \link wyGridController wyGridController\endlink subclass
	 */
	void setGrid(wyGridController* grid);

	/**
	 * Add a child node in a thread safe way
	 *
	 * @param child \link Node Node\endlink to be added
	 * @param z z order in child list
	 * @param tag tag value of child node, default is an invalid value
	 */
	void addChildLocked(wyNode* child, int z = 0, int tag = INVALID_TAG);

	/**
	 * Add child node
	 *
	 * @param child child node object
	 * @param z z order in child list, the smaller will be drawn first
	 * @param tag tag to identify child node
	 */
	virtual void addChild(wyNode* child, int z, int tag);

	/**
	 * Change z-order of a child, not thread safe. That will affect render sequence of this child. Don't
	 * call setZOrder because it doesn't resort children
	 *
	 * @param child child node
	 * @param z new z order value
	 */
	virtual int reorderChild(wyNode* child, int z);

	/**
	 * Remove all children in thread safe way
	 *
	 * @param cleanup true means reset state of removed child.
	 */
	void removeAllChildrenLocked(bool cleanup);

	/**
	 * Remove all children, not thread safe
	 *
	 * @param cleanup true means reset state of removed child
	 */
	virtual void removeAllChildren(bool cleanup);

	/**
	 * Remove one child node in thread safe way
	 *
	 * @param child child node to be removed
	 * @param cleanup true means reset state of removed child
	 */
	void removeChildLocked(wyNode* child, bool cleanup);

	/**
	 * Remove a child node by tag, in thread safe way. If more than one child
	 * has same tag, it will only remove first one matched
	 *
	 * @param tag child node tag
	 * @param cleanup true means reset state of removed child
	 */
	void removeChildByTagLocked(int tag, bool cleanup);

	/**
	 * Remove a child node by tag, in thread safe way. If more than one child
	 * has same tag, it will remove them all.
	 *
	 * @param tag child node tag
	 * @param cleanup true means reset state of removed child
	 */
	void removeChildrenByTagLocked(int tag, bool cleanup);

	/**
	 * Remove one child node, not in thread safe way
	 *
	 * @param child child node to be removed
	 * @param cleanup true means reset state of removed child
	 */
	virtual void removeChild(wyNode* child, bool cleanup);

	/**
	 * Reorder child z order, in a thread safe way
	 *
	 * @param child child node to be reset z order
	 * @param z new z order
	 */
	int reorderChildLocked(wyNode* child, int z);

	/**
	 * Bring a child node to bottom of children list, that means the child will be above on
	 * other sibling nodes. Actually it calls \c reorderChild to set z order
	 *
	 * @param child child node to be moved
	 */
	virtual void bringToFront(wyNode* child);

	/**
	 * Bring a child node to bottom of children list in a thread safe way, that means the child will be above on
	 * other sibling nodes. Actually it calls \c reorderChild to set z order
	 *
	 * @param child child node to be moved
	 */
	void bringToFrontLocked(wyNode* child);

	/**
	 * Bring a child node to top of children list so it will below to other sibling nodes.
	 * Actually it calls \c reorderChild to set z order of child node
	 *
	 * @param child child node to be moved
	 */
	virtual void bringToBack(wyNode* child);

	/**
	 * Bring a child node to top of children list in a thread safe way. It will below to other sibling nodes.
	 * Actually it calls \c reorderChild to set z order of child node
	 *
	 * @param child child node to be moved
	 */
	void bringToBackLocked(wyNode* child);

	/**
	 * Get child by tag, in thread safe way. If more than one child matched, first
	 * one is returned
	 *
	 * @param tag tag of node
	 * @return found node, or NULL if not found
	 */
	wyNode* getChildByTagLocked(int tag);

	/**
	 * Get children by tag, in thread safe way
	 *
	 * @param tag tag of node
	 * @param count count of node returned
	 * @return all nodes which has the tag, caller should release the pointer
	 */
	wyNode** getChildrenByTagLocked(int tag, size_t* count);

	/**
	 * Get child node by tag. If more than one child matched, first one is returned
	 *
	 * @param tag node tag
	 * @param node object or NULL if not found
	 */
	virtual wyNode* getChildByTag(int tag);

	/**
	 * Get children by tag
	 *
	 * @param tag tag of node
	 * @param count count of node returned
	 * @return all nodes which has the tag, caller should release the pointer
	 */
	virtual wyNode** getChildrenByTag(int tag, size_t* count);

	/**
	 * Get first node in children list, the first child has smallest z order value
	 *
	 * @return node object or NULL if children list is empty
	 */
	virtual wyNode* getFirstChild();

	/**
	 * Set velocity of node. It is a simply way to move a node without running an action or
	 * maintaining physics engine
	 *
	 * @param vx x velocity
	 * @param vy y velocity
	 */
	virtual void setVelocity(float vx, float vy);

	/**
	 * Set acceleration of node. It is a simply way to move node without running an action or
	 * maintaining physics engine
	 *
	 * @param ax x acceleration
	 * @param ay y acceleration
	 */
	virtual void setAcceleration(float ax, float ay);

	/**
	 * Set clip rect
	 *
	 * @param clip clip rectangle
	 * @param relativeToSelf true means \c clip is a rectangle relative to self coordinates. Or false
	 * 		means \c clip is a global rectangle
	 */
	virtual void setClipRect(wyRect clip, bool relativeToSelf = false);

	/**
	 * Clear clip rect
	 */
	void clearClipRect() { m_hasClip = false; }

	/**
	 * Has clip rect set
	 */
	bool hasClipRect() { return m_hasClip; }

	/**
	 * Get clip rect
	 *
	 * @return clip rectangle
	 */
	wyRect getClipRect() { return m_clipRect; }

	/**
	 * Set node acceleration in x axis. It is a simply way to attach physics property to node without
	 * running an action or maintaining physics engine
	 *
	 * @param ax x acceleration
	 */
	void setAccelerationX(float ax);

	/**
	 * Set node acceleration in y axis. It is a simply way to attach physics property to node without
	 * running an action or maintaining physics engine
	 *
	 * @param ay y acceleration
	 */
	void setAccelerationY(float ay);

	/**
	 * Set node velocity in x axis. It is a simply way to attach physics property to node without
	 * running an action or maintaining physics engine
	 *
	 * @param vx x velocity
	 */
	void setVelocityX(float vx);

	/**
	 * Set node velocity in y axis. It is a simply way to attach physics property to node without
	 * running an action or maintaining physics engine
	 *
	 * @param vy y velocity
	 */
	void setVelocityY(float vy);

	/**
	 * Get global position of node
	 *
	 * @return if \c m_relativeAnchorPoint is true, returned position is global anchor position, or false
	 * 		means it is global bottom-left position
	 */
	wyPoint getAbsolutePosition();

	/**
	 * Run an action on this node
	 *
	 * @param action subclass of \link wyAction wyAction\endlink
	 */
	void runAction(wyAction* action);

	/**
	 * Stop an action by action tag
	 *
	 * @param tag action tag
	 */
	void stopAction(int tag);

	/**
	 * Stop all actions on this node
	 *
	 * @param includeChildren true means also stop actions in children node recursively. Default is false
	 */
	void stopAllActions(bool includeChildren = false);

	/**
	 * Pause all action on this node. You can resume it by \c resumeAllActions
	 *
	 * @param includeChildren true means also pause actions in children node recursively. Default is false
	 */
	void pauseAllActions(bool includeChildren = false);

	/**
	 * Resume all actions on thisnode
	 *
	 * @param includeChildren true means also resume actions in children node recursively. Default is false
	 */
	void resumeAllActions(bool includeChildren = false);

	/**
	 * Pause all timers scheduled on this node. You can resume it by \c resumeAllTimers
	 *
	 * @param includeChildren true means also pause timers in children node recursively. Default is false
	 */
	void pauseAllTimers(bool includeChildren = false);

	/**
	 * resume all timers scheduled on this node. You can pause it by \c pauseAllTimers
	 *
	 * @param includeChildren true means also resume timers in children node recursively. Default is false
	 */
	void resumeAllTimers(bool includeChildren = false);

	/**
	 * Pause one action on this node, by action tag. If no action with given tag is found, do nothing
	 *
	 * \note
	 * If an action is included by a combination action, then pause it is no effect
	 *
	 * @param tag action tag
	 */
	void pauseAction(int tag);

	/**
	 * Resume one action on this node, by action tag. If no action with given tag is found, do nothing
	 *
	 * @param tag action tag
	 */
	void resumeAction(int tag);

	/**
	 * Get an action by tag
	 *
	 * @param tag action tag
	 * @return action object, or NULL if no matched action
	 */
	wyAction* getAction(int tag);

	/**
	 * Check whether there is at least one action running on this node
	 *
	 * @return true means at least one action is running on this node
	 */
	bool hasRunningAction();

	/**
	 * Convert world point to node space
	 *
	 * @param p point to be converted
	 * @return converted point
	 */
	wyPoint worldToNodeSpace(wyPoint p);

	/**
	 * Convert world point to node space. Converted point is relative
	 * to node anchor position
	 *
	 * @param p point to be converted
	 * @return converted point whose position is relative to node anchor
	 */
	wyPoint worldToNodeSpaceAR(wyPoint p);

	/**
	 * Convert node point to global coordinates
	 *
	 * @param p point to be converted
	 * @return converted point
	 */
	wyPoint nodeToWorldSpace(wyPoint p);

	/**
	 * Convert node point to global coordinates. Source point
	 * is relative to node anchor
	 *
	 * @param p point to be converted, its position is relative to node anchor
	 * @return converted point
	 */
	wyPoint nodeToWorldSpaceAR(wyPoint p);

	/**
	 * Convert a point in parent node coordinates to node coordinates
	 *
	 * @param p point to be converted
	 * @return converted point
	 */
	wyPoint parentToNodeSpace(wyPoint p);

	/**
	 * Convert a point in parent node coordinates to node coordinates.
	 * Converted point is relative to node anchor position
	 *
	 * @param p point to be converted
	 * @return converted point whose position is relative to node anchor
	 */
	wyPoint parentToNodeSpaceAR(wyPoint p);

	/**
	 * Convert node point to parent coordinates
	 *
	 * @param p point to be converted
	 * @return converted point
	 */
	wyPoint nodeToParentSpace(wyPoint p);

	/**
	 * Convert node point to parent coordinates. Source point
	 * is relative to node anchor
	 *
	 * @param p point to be converted, its position is relative to node anchor
	 * @return converted point
	 */
	wyPoint nodeToParentSpaceAR(wyPoint p);

	/**
	 * Get bounding rectangle of node which doesn't consider scale and rotation
	 *
	 * @return bounding rectangle in self coordinates
	 */
	wyRect getBoundingBox();

	/**
	 * Get bounding rectangle relative to parent space. It consider node scale
	 * and rotation.
	 *
	 * @return bounding rectangle in parent space
	 */
	wyRect getBoundingBoxRelativeToParent();

	/**
	 * Get bounding rectangle relative to global space. It consider node scale
	 * and rotation
	 *
	 * @return bounding rectangle in global space
	 */
	wyRect getBoundingBoxRelativeToWorld();

	/**
	 * Whether or not receive accelerometer event
	 *
	 * @param enabled true means receive accelerometer event
	 */
	void setAccelerometerEnabled(bool enabled);

	/**
	 * Whether or not receive key event
	 *
	 * @param enabled true means receive key event
	 */
	void setKeyEnabled(bool enabled);

	/**
	 * Whether or not receive touch event
	 *
	 * @param enabled true means receive touch event
	 */
	void setTouchEnabled(bool enabled);

	/**
	 * Whether or not receive double tap event
	 *
	 * @param enabled true means receive double tap event
	 */
	void setDoubleTapEnabled(bool enabled);

	/**
	 * Set receive gesture event or not
	 *
	 * @param enabled true means receive gesture event
	 */
	void setGestureEnabled(bool enabled);

	/**
	 * Whether or not touch event is enabled for this node
	 *
	 * @return true means touch event is enabled for this node
	 */
	bool isTouchEnabled() { return m_touchEnabled; }

	/**
	 * Whether or not key event is enabled for this node
	 *
	 * @return true means key event is enabled for this node
	 */
	bool isKeyEnabled() { return m_keyEnabled; }

	/**
	 * Whether or not accelerometer event is enabled for this node
	 *
	 * @return true means accelerometer event is enabled for this node
	 */
	bool isAccelerometerEnabled() { return m_accelerometerEnabled; }

	/**
	 * Whether or not gesture event is enabled for this node
	 *
	 * @return true means gesture event is enabled for this node
	 */
	bool isGestureEnabled() { return m_gestureEnabled; }

	/**
	 * Whether or not double tap event is enabled for this node
	 *
	 * @return true means double tap event is enabled for this node
	 */
	bool isDoubleTabEnabled() { return m_doubleTabEnabled; }

	/**
	 * Get anchor position relative to self coordinates
	 *
	 * @return x position
	 */
	float getAnchorPointX() { return m_anchorPointX; }

	/**
	 * Get anchor position relative to self coordinates
	 *
	 * @return y position
	 */
	float getAnchorPointY() { return m_anchorPointY; }

	/**
	 * Get anchor x relative position
	 *
	 * @return x relative position
	 */
	float getAnchorX() { return m_anchorX; }

	/**
	 * Get anchor relative y position
	 *
	 * @return y relative position
	 */
	float getAnchorY() { return m_anchorY; }

	/**
	 * Get camera object of this node
	 *
	 * @return \link wyCamera wyCamera\endlink
	 */
	wyCamera* getCamera();

	/**
	 * Check any camera object is created for this node. Every node has a camera object
	 * but it is lazy created
	 */
	bool hasCamera() { return m_camera != NULL; }

	/**
	 * Get attached grid object of node, must be a subclass of \link wyGridController wyGridController\endlink
	 */
	wyGridController* getGrid() { return m_grid; }

	/**
	 * Is grid active, if grid is NULL, returns false
	 *
	 * @return true means grid is active
	 */
	bool isGridActive();

	/**
	 * Is node visible
	 */
	bool isVisible() { return m_visible; }

	/**
	 * Is node focused
	 */
	bool isFocused() { return m_focused; }

	/**
	 * Is node really visible? A node is really visible when all ancestor nodes are visible
	 */
	bool isVisibleFromRoot();

	/**
	 * Get selected state of node
	 */
	bool isSelected() { return m_selected; }

	/**
	 * Get node enable state
	 */
	bool isEnabled() { return m_enabled; }

	/**
	 * Is a node really enabled? A node is really enabled when all ancestor nodes are enabled
	 */
	bool isEnabledFromRoot();

	/**
	 * Get node OpenGL z value
	 */
	float getVertexZ() { return m_vertexZ; }

	/**
	 * Get node rotation angle, in degree. Positive value is clockwise.
	 */
	float getRotation() { return m_rotation; }

	/**
	 * Get position x
	 */
	float getPositionX() { return m_positionX; }

	/**
	 * Get position y
	 */
	float getPositionY() { return m_positionY; }

	/**
	 * Get position of bottom left corner.
	 */
	float getOriginX();

	/**
	 * Get position of bottom left corner
	 */
	float getOriginY();

	/**
	 * Get flag about anchor and bottom left relationship. true means \c setPosition actually set
	 * anchor position, false means \c setPosition set bottom left position
	 */
	bool isRelativeAnchorPoint() { return m_relativeAnchorPoint; }

	/**
	 * Is current node is running. Node is running means the node is in the current scene
	 */
	bool isRunning() { return m_running; }

	/**
	 * Get width of node, in pixels
	 */
	float getWidth() { return m_width; }

	/**
	 * Get height of node, in pixels
	 */
	float getHeight() { return m_height; }

	/**
	 * Get velocity in x axis
	 */
	float getVelocityX() { return m_velocityX; }

	/**
	 * Get velocity in y axis
	 */
	float getVelocityY() { return m_velocityY; }

	/**
	 * Get velocity vector of this node
	 */
	wyPoint getVelocity() { return wyp(m_velocityX, m_velocityY); }

	/**
	 * Get acceleration in x axis
	 */
	float getAccelerationX() { return m_accelerationX; }

	/**
	 * Get acceleration in y axis
	 */
	float getAccelerationY() { return m_accelerationY; }

	/**
	 * Get acceleration vector of node
	 */
	wyPoint getAcceleration() { return wyp(m_accelerationX, m_accelerationY); }

	/**
	 * Get content size of node
	 */
	wySize getContentSize() { return wys(m_width, m_height); }

	/**
	 * Get children list
	 */
	wyArray* getChildren() { return m_children; }

	/**
	 * Get child node at specified index
	 *
	 * @param index index of child
	 * @return \link wyNode wyNode\endlink, or NULL if \c index is invalid
	 */
	wyNode* getChildAt(int index) { return (wyNode*)wyArrayGet(m_children, index); }

	/**
	 * Get children count
	 */
	int getChildCount() { return m_children->num; }

	/**
	 * Get parent node
	 */
	wyNode* getParent() { return m_parent; }

	/**
	 * Set parent node
	 */
	void setParent(wyNode* p) { m_parent = p; }

	/**
	 * Set node tag. Tag is an integer and -1 is default.
	 */
	void setTag(int tag) { m_tag = tag; }

	/**
	 * Get node tag
	 */
	int getTag() { return m_tag; }

	/**
	 * Get z order value in parent. It is not OpenGL z value.
	 */
	void setZOrder(int z) { m_zOrder = z; }

	/**
	 * Get z order in parent node
	 */
	int getZOrder() { return m_zOrder; }

	/**
	 * Schedule a timer, the timer is a local timer and will be auto stopped when node exit
	 *
	 * @param t timer object
	 */
	void scheduleLocked(wyTimer* t);

	/**
	 * Unschedule a timer, i.e., stop it
	 *
	 * @param t timer object
	 */
	void unscheduleLocked(wyTimer* t);

	/**
	 * should render this node? true means don't render it
	 */
	bool isNoDraw() { return m_noDraw; }

	/**
	 * Set render this node or not, true means don't render it
	 */
	void setNoDraw(bool flag) { m_noDraw = flag; }

	/**
	 * Set selector to be triggered when touch down
	 */
	void setDownSelector(wyTargetSelector* ts);

	/**
	 * Get selector to be triggered when touch down
	 */
	wyTargetSelector* getDownSelector() { return m_downSelector; }

	/**
	 * Set selector to be triggered when touch up
	 */
	void setUpSelector(wyTargetSelector* ts);

	/**
	 * Get selector to be triggered when touch up
	 */
	wyTargetSelector* getUpSelector() { return m_upSelector; }

	/**
	 * Set selector to be triggered when touch point move outside of node
	 */
	void setMoveOutSelector(wyTargetSelector* ts);

	/**
	 * Get selector to be triggered when touch point moves outside of node
	 */
	wyTargetSelector* getMoveOutSelector() { return m_moveOutSelector; }

	/* other optional interface, we don't use multiple inheritance */

	/* IFrames */
	/**
	 * Add an animation to this node, then it can be obtained by animation id
	 *
	 * @param animation \link wyAnimation wyAnimation\endlink
	 */
	virtual void addAnimation(wyAnimation* animation) {}

	/**
	 * Get animation by animation id
	 *
	 * @param id animation id
	 * @return \link wyAnimation wyAnimation\endlink
	 */
	virtual wyAnimation* getAnimationById(int id) { return NULL; }

	/**
	 * Get current frame, or NULL if no frame set
	 *
	 * @return current frame object
	 */
	virtual wyFrame* getDisplayFrame() { return NULL; }

	/**
	 * Check a frame is set or not
	 *
	 * @param frame frame object
	 * @return true means this frame is set
	 */
	virtual bool isFrameDisplayed(wyFrame* frame) { return false; }

	/**
	 * Set current frame
	 *
	 * @param newFrame frame object
	 */
	virtual void setDisplayFrame(wyFrame* newFrame) {}

	/**
	 * Set frame by animation id and frame index
	 *
	 * @param id animation id
	 * @param frameIndex frame index
	 */
	virtual void setDisplayFrameById(int id, int frameIndex) {}

	/* ILabel */

	/**
	 * Get text
	 *
	 * @return text in utf-8 encoding
	 */
	virtual const char* getText() { return NULL; }

	/**
	 * If a node supports setting text, it should implement this method
	 *
	 * @param text text in utf-8 encoding
	 */
	virtual void setText(const char* text) {}

	/* ITransparent */

	/**
	 * Get current alpha
	 */
	virtual int getAlpha() { return m_color.a; }

	/**
	 * Set node alpha
	 */
	virtual void setAlpha(int alpha);

	/* IRGB */

	/// Get node color in 3B format
	virtual wyColor3B getColor() { return wyc4b2c3b(m_color); }

	/// get colro in 4B format
	virtual wyColor4B getColor4B() { return m_color; }

	/**
	 * Get node color
	 */
	virtual void setColor(wyColor3B color);

	/**
	 * Set node color
	 */
	virtual void setColor(wyColor4B color);

	/* IDitherable */

	/**
	 * Is dither enabled or not
	 *
	 * @return true means dither is enabled
	 */
	virtual bool isDither();

	/**
	 * Enable dither or not
	 *
	 * @param flag true means enable dither
	 */
	virtual void setDither(bool flag);

	/* IBlendable */

	/**
	 * Get current blending mode
	 *
	 * @return blending mode
	 */
	virtual wyRenderState::BlendMode getBlendMode();

	/**
	 * Set current blending mode
	 *
	 * @param mode blending mode
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
	 * Create a parallax object for this node
	 *
	 * @return \link wyParallaxObject wyParallaxObject\endlink
	 */
	virtual wyParallaxObject* createParallaxObject();

	/**
	 * Is this node visitable. "Visitable" means its children should be visited when
	 * rendering this node
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
	 * Update material
	 */
	virtual void updateMaterial() {}

	/**
	 * Update mesh
	 */
	virtual void updateMesh() {}

	/**
	 * Update mesh color
	 */
	virtual void updateMeshColor() {}

	/**
	 * Adjust node size to contain all children. It won't consider child node scale or rotation
	 *
	 * \note
	 * If child node exceeds left or bottom edge of parent node, the exceeded part is not calculated
	 */
	void sizeToFit();

	/**
	 * Get best size which can contain all children node. It doesn't consider child node
	 * scale or rotation. However, if a child node exceeds left or bottom edge of parent node,
	 * it will be also included. So the result may be different with \c sizeToFit
	 *
	 * @return minimum size of all children node combination
	 */
	wySize getFitSize();

	/**
	 * Enlarge node size with given delta
	 *
	 * @param left delta size to expand in left
	 * @param top delta size to expand in top
	 * @param right delta size to expand in right
	 * @param bottom delta size to expand in bottom
	 */
	void enlargeNode(float left, float top, float right, float bottom);

	/**
	 * Release object. This method is only called from java layer. Don't call it manually.
	 */
	void javaRelease(bool includeChildren);

	/**
	 * Set priority of touch event handling
	 */
	void setTouchPriority(int p) { m_touchPriority = p; }

	/**
	 * Set priority of key event handling
	 */
	void setKeyPriority(int p) { m_keyPriority = p; }

	/**
	 * Set priority of gesture event handling
	 */
	void setGesturePriority(int p) { m_gesturePriority = p; }

	/**
	 * Set priority of double tap handling
	 */
	void setDoubleTapPriority(int p) { m_doubleTapPriority = p; }

	/**
	 * Set priority of accelerometer event handling
	 */
	void setAccelerometerPriority(int p) { m_accelerometerPriority = p; }

	/**
	 * Get priority of touch event handling
	 */
	int getTouchPriority() { return m_touchPriority; }

	/**
	 * Get priority of key event handling
	 */
	int getKeyPriority() { return m_keyPriority; }

	/**
	 * Get priority of gesture event handling
	 */
	int getGesturePriority() { return m_gesturePriority; }

	/**
	 * Get priority of double tap event handling
	 */
	int getDoubleTapPriority() { return m_doubleTapPriority; }

	/**
	 * Get priority of accelerometer event handling
	 */
	int getAccelerometerPriority() { return m_accelerometerPriority; }

	/**
	 * Set position callback
	 *
	 * @param cb \link wyNodePositionCallback wyNodePositionCallback\endlink
	 */
	virtual void setPositionCallback(wyNodePositionCallback* cb) { m_positionCallback = cb; }

	/**
	 * Set intercept event or not. If true, default event handler returns true, or false returns false.
	 * When a event handler returns true, handler after that won't receive event
	 */
	virtual void setInterceptTouch(bool flag) { m_interceptTouch = flag; }

	/**
	 * Checking a node is ancestor of current node
	 *
	 * @param node node to be checked
	 * @return true if \c node is ancestor of current node
	 */
	virtual bool isAncestor(wyNode* node);

	/**
	 * Set whether node should trigger click behavior for non-first touch point
	 */
	virtual void setMultiTouchClickable(bool flag) { m_multiTouchClickable = flag; }

	/**
	 * Whether node should trigger click behavior for non-first touch point
	 */
	virtual bool isMultiTouchClickable() { return m_multiTouchClickable; }

	/**
	 * Set flag indicating material need to be updated before rendering
	 *
	 * @param flag true means need update
	 */
	virtual void setNeedUpdateMaterial(bool flag) { m_materialNeedUpdate = flag; }

	/**
	 * Set flag indicating mesh need to be updated before rendering
	 *
	 * @param flag true means need update
	 */
	virtual void setNeedUpdateMesh(bool flag) { m_meshNeedUpdate = flag; }

	/**
	 * Set flag indicating mesh color need to be updated before rendering
	 *
	 * @param flag true means need update
	 */
	virtual void setNeedUpdateMeshColor(bool flag) { m_meshColorNeedUpdate = flag; }

	/**
	 * Is material need to be updated?
	 *
	 * @return true means need update
	 */
	virtual bool isNeedUpdateMaterial() { return m_materialNeedUpdate; }

	/**
	 * Is mesh need to be updated?
	 *
	 * @return true means need update
	 */
	virtual bool isNeedUpdateMesh() { return m_meshNeedUpdate; }

	/**
	 * Is mesh color need to be updated?
	 *
	 * @return true means need update
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
	 * Remove render pairs which are matched by selector
	 *
	 * @param sel custom selector used to select render pair
	 * @param data extra data will be passed to selector
	 */
	virtual void removeRenderPairs(wyRenderPairSelector* sel, void* data);

	/**
	 * Remove render pairs whose tag is same as given one
	 *
	 * @param tag tag
	 */
	virtual void removeRenderPairsByTag(int tag);

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
	 * Replace mesh of render pair at given index
	 *
	 * @param mesh new mesh
	 * @param index render pair index
	 */
	virtual void replaceMesh(wyMesh* mesh, int index = 0);

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
	 * Get clip rect which is transformed if relative self flag is true
	 *
	 * @return clip rect transformed
	 */
	virtual wyRect getResolvedClipRect();

	/**
	 * Get queue bucket id, default value is \c wyRenderQueue::INHERIT
	 *
	 * @return queue bucket id
	 */
	virtual wyRenderQueue::Bucket getQueueBucket();

	/**
	 * Set queue bucket id
	 *
	 * @param bucket queue bucket id
	 */
	virtual void setQueueBucket(wyRenderQueue::Bucket bucket) { m_queueBucket = bucket; }

	/**
	 * Set a touch coffin to this node. A touch coffin is a node which means
	 * current node touch event must occurs in coffin node content area. Otherwise
	 * the touch event will be ignored
	 *
	 * \note
	 * Node won't retain coffin node, so you must ensure the coffin node is clear when
	 * it is released
	 */
	void setTouchCoffin(wyNode* c) { m_touchCoffin = c; }

	/**
	 * Get touch coffin touch bound to this node
	 */
	wyNode* getTouchCoffin() { return m_touchCoffin; }

	/// apply node matrix to top matrix of world matrix stack
	void applyWorldMatrix();
};

#endif // __wyNode_h__
