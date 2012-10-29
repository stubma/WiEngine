package com.wiyun.engine.afcanim;

import com.wiyun.engine.nodes.Node;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYBlendFunc;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;

/**
 * \if English
 * \par
 * AFC means Animation, Frame, Clip and it is an architecture of frame animation. That is
 * to say, animation consists of frame and frame consists of fragment. This architecture
 * is common and many animation editors support it. Purpose of \link AFCSprite AFCSprite\endlink
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
 * Duration time of frame has two measurement: by time or by tick. Some editor, likes Motion Welder, Arctic,
 * etc. uses an integer as frame duration. The integer is a tick count, not time, so animation will be faster
 * if device has higher frame rate. In \link AFCSprite AFCSprite\endlink, there is an unit interval can be
 * set and if it is not zero, the final duration time will be the result of multiply tick and unit interval.
 * By default it is zero and it means using tick directly.
 * \else
 * \par
 * AFC的含义是Animation, Frame, Clip, 它代表了一种常见的动画架构, 即动画由帧组成, 而帧由分片组成
 * 的动画数据结构. 这种动画数据结构在逐帧动画中应用的比较普遍, 相关的编辑器也很多. 而\link AFCSprite AFCSprite\endlink的
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
 * 一个动画帧的持续时间在AFC架构中有两种表示方式, 即按照时间或按照帧表示. 有些编辑器, 比如Motion Welder, Arctic等, 并不存放
 * 一个动画帧的实际显示时间, 而是使用一个无单位的整数, 用来表示这个动画帧应该在几帧内保持可见. 因此, 如果机器渲染速度越快, 则
 * 动画帧可见的时间就越短. \link AFCSprite AFCSprite\endlink提供了第三种选择, 可以设置一个单位时间间隔, 从而可以调整
 * 按帧显示动画的播放速度, 从而将按帧显示变成按时间显示. 缺省情况下单位时间间隔是0, 表示忽略该设置, 使用按帧显示.
 * \endif
 */
public class AFCSprite extends Node {
	/**
	 * \if English
	 * Callback interface of \link AFCSprite AFCSprite\endlink
	 * \else
	 * \link AFCSprite AFCSprite\endlink 的回调定义
	 * \endif
	 */
	public static interface IAFCSpriteCallback {
		/**
		 * \if English
		 * Invoked when frame changed
		 *
		 * @param pointer native pointer of \link AFCSprite AFCSprite\endlink
		 * \else
		 * 动画帧已经改变
		 *
		 * @param pointer \link AFCSprite AFCSprite\endlink的底层指针
		 * \endif
		 */
		public void onAFCAnimationFrameChanged(int pointer);
		
		/**
		 * \if English
		 * Invoked when animation ended
		 *
		 * @param pointer native pointer of \link AFCSprite AFCSprite\endlink
		 * \else
		 * 动画已经结束
		 *
		 * @param pointer \link AFCSprite AFCSprite\endlink的底层指针
		 * \endif
		 */
		public void onAFCAnimationEnded(int pointer);
	}
	
	protected AFCSprite() {
	}
	
	@Override
	protected void doNativeInit() {
	}
	
	protected AFCSprite(int pointer) {
		super(pointer);
	}
	
	/**
	 * \if English
	 * Get animation at specified index
	 *
	 * @param index animation index
	 * \else
	 * 得到指定索引位置的动画数据
	 *
	 * @param index 动画索引
	 * \endif
	 */
	public AFCAnimation getAnimationAt(int index) {
		return AFCAnimation.from(nativeGetAnimationAt(index));
	}
	
	private native int nativeGetAnimationAt(int index);

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
	public native int getAnimationCount();

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
	public native int getImageCount();

	/**
	 * \if English
	 * Play an animation, it will immediately end current animation (if has)
	 *
	 * @param index index of animation
	 * \else
	 * 开始播放动画
	 *
	 * @param index 动画索引
	 * \endif
	 */
	public native void playAnimation(int index);
	
	/**
	 * \if English
	 * Play an animation, it will immediately end current animation (if has)
	 *
	 * \note
	 * Currently, clip mapping doesn't support SpriteX 2011 and Motion Welder
	 * 
	 * @param index index of animation
	 * @param mapping clip mapping, can be null. A clip mapping must be added
	 * 		to \link AFCSprite AFCSprite\endlink before use it in \c playAnimation 
	 * \else
	 * 开始播放动画
	 *
	 * \note
	 * 分片映射不支持SpriteX 2011和Motion Welder
	 * 
	 * @param index 动画索引
	 * @param mapping 分片映射规则对象, 可以为null. 一个分片映射被正式用来播放之前, 必须添加
	 * 		到\link AFCSprite AFCSprite\endlink中
	 * \endif
	 */
	public native void playAnimation(int index, AFCClipMapping mapping);

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
	public native void playAnimation(int index, int mappingTag);

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
	public native void setFrameIndex(int index);

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
	public native void tick(float delta);

	/**
	 * \if English
	 * Set ignore frame offset when rendering or not
	 *
	 * @param flag true means ignore frame offset
	 * \else
	 * 设置是否忽略帧偏移，帧偏移可以造成动画前进的效果，如果忽略掉就会变成原地动画.
	 * 这个标志只影响渲染时是否考虑帧偏移, 对于帧偏移的计算仍然进行, 因此不影响获得帧偏移
	 *
	 * @param flag true表示忽略帧偏移
	 * \endif
	 */
	public native void setIgnoreFrameOffset(boolean flag);

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
	public native boolean isIgnoreFrameOffset();

	/**
	 * \if English
	 * Get current frame offset
	 *
	 * @param current frame offset
	 * \else
	 * 得到当前帧偏移，这个偏移值是当前帧和第一帧的总偏移. 即使设置了在动画播放时忽略
	 * 帧偏移, 仍然可以获得当前帧偏移数据
	 *
	 * @return \link Point Point\endlink
	 * \endif
	 */
	public WYPoint getFrameOffset() {
		WYPoint p = WYPoint.makeZero();
		nativeGetFrameOffset(p);
		return p;
	}
	
	private native void nativeGetFrameOffset(WYPoint p);

	/**
	 * \if English
	 * Set animation event callback
	 *
	 * @param callback \link IAFCSpriteCallback IAFCSpriteCallback\endlink, if NULL, means clear callback
	 * \else
	 * 设置动画事件的回调
	 *
	 * @param callback \link IAFCSpriteCallback IAFCSpriteCallback\endlink 结构，如果为NULL, 表示清除之前设置的callback
	 * \endif
	 */
	public native void setAFCSpriteCallback(IAFCSpriteCallback callback);

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
	public native int getCurrentAnimationIndex();

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
	public native int getCurrentFrame();

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
	public native int getFrameCount();

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
	public native boolean isReverse();

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
	public native void setReverse(boolean flag);

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
	public native int getLoopCount();

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
	public native void setLoopCount(int loop);

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
	public native boolean isAnimationEnded();

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
	public native boolean isFlipX();

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
	public native void setFlipX(boolean flipX);

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
	public native boolean isFlipY();

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
	public native void setFlipY(boolean flipY);

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
	public native void setPaused(boolean flag);

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
	public native boolean isPaused();

	/**
	 * \if English
	 * Get data of current animation
	 *
	 * \node
	 * Returned info is auto scaled by WiEngine on the basis of density
	 *
	 * @return \link AFCAnimation AFCAnimation\endlink
	 * \else
	 * 得到当前正在播放的动画数据结构, 即\link AFCAnimation AFCAnimation\endlink结构,
	 * 从这个结构可以得到一个动画的所有信息
	 *
	 * \note
	 * 返回的结构中的信息都是经过了WiEngine自动缩放的, 即考虑了anu文件的密度和屏幕密度进行了
	 * 自动的转换
	 *
	 * @return \link AFCAnimation AFCAnimation\endlink
	 * \endif
	 */
	public AFCAnimation getCurrentAnimationData() {
		return AFCAnimation.from(nativeGetCurrentAnimationData());
	}
	
	private native int nativeGetCurrentAnimationData();

	public native int getAlpha();

	public native void setAlpha(int alpha);

	public WYColor3B getColor() {
		WYColor3B color = new WYColor3B();
		nativeGetColor(color);
		return color;
	}

	private native void nativeGetColor(WYColor3B color);

	public void setColor(WYColor3B color) {
		nativeSetColor(color.r, color.g, color.b);
	}

	private native void nativeSetColor(int r, int g, int b);
	
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
	public native float getUnitInterval();

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
	public native void setUnitInterval(float interval);
	
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
	public native boolean isForceTickMode();

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
	public native void setForceTickMode(boolean flag);
	
	/**
	 * \if English
	 * Get total number of collision rectangle in current frame
	 * \else
	 * 得到当前帧中的碰撞矩形个数
	 * \endif
	 */
	public native int getCollisionRectCount();
	
	/**
	 * \if English
	 * Get collision rect of current frame, in node coordinates
	 *
	 * @param index index of collision rect
	 * @return \link WYRect WYRect\endlink, if no collision rect in current frame or
	 * 		\c index is invalid, return a zero rect
	 * \else
	 * 得到当前帧的碰撞矩形, 返回的矩形坐标是相对于节点本身的
	 *
	 * @return index 碰撞矩形的索引, 0表示第一个, 1表示第二个
	 * @return \link WYRect WYRect\endlink, 如果当前帧没有碰撞矩形或者\c index值无效, 返回一个零大小的矩形
	 * \endif
	 */
	public WYRect getCollisionRect(int index) {
		WYRect r = WYRect.makeZero();
		nativeGetCollisionRect(index, r);
		return r;
	}
	
	private native void nativeGetCollisionRect(int index, WYRect r);

	/**
	 * \if English
	 * Get collision rect of current frame, in parent node coordinates. If node has rotation, then
	 * returned rectangle may be a circumscribed rectangle
	 *
	 * @param index index of collision rect
	 * @return \link WYRect WYRect\endlink, if no collision rect in current frame or
	 * 		\c index is invalid, return a zero rect
	 * \else
	 * 得到当前帧的碰撞矩形, 返回的矩形坐标是相对于父节点坐标系的. 如果节点自身有旋转, 则返回的可能是一个
	 * 外接矩形
	 *
	 * @return index 碰撞矩形的索引, 0表示第一个, 1表示第二个
	 * @return \link WYRect WYRect\endlink, 如果当前帧没有碰撞矩形或者\c index值无效, 返回一个零大小的矩形
	 * \endif
	 */
	public WYRect getCollisionRectRelativeToParent(int index) {
		WYRect r = WYRect.makeZero();
		nativeGetCollisionRectRelativeToParent(index, r);
		return r;
	}
	
	private native void nativeGetCollisionRectRelativeToParent(int index, WYRect r);

	/**
	 * \if English
	 * Get collision rect of current frame, in global coordinates. If node has rotation, then
	 * returned rectangle may be a circumscribed rectangle
	 *
	 * @param index index of collision rect
	 * @return \link WYRect WYRect\endlink, if no collision rect in current frame or
	 * 		\c index is invalid, return a zero rect
	 * \else
	 * 得到当前帧的碰撞矩形, 返回的矩形坐标是相对于全局坐标系的. 如果节点自身有旋转, 则返回的可能是一个
	 * 外接矩形
	 *
	 * @return index 碰撞矩形的索引, 0表示第一个, 1表示第二个
	 * @return \link WYRect WYRect\endlink, 如果当前帧没有碰撞矩形或者\c index值无效, 返回一个零大小的矩形
	 * \endif
	 */
	public WYRect getCollisionRectRelativeToWorld(int index) {
		WYRect r = WYRect.makeZero();
		nativeGetCollisionRectRelativeToWorld(index, r);
		return r;
	}
	
	private native void nativeGetCollisionRectRelativeToWorld(int index, WYRect r);
	
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
	public WYRect getFrameRect() {
		WYRect r = WYRect.makeZero();
		nativeGetFrameRect(r);
		return r;
	}
	
	private native void nativeGetFrameRect(WYRect r);

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
	public WYRect getFrameRectRelativeToParent() {
		WYRect r = WYRect.makeZero();
		nativeGetFrameRectRelativeToParent(r);
		return r;
	}

	private native void nativeGetFrameRectRelativeToParent(WYRect r);

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
	public WYRect getFrameRectRelativeToWorld() {
		WYRect r = WYRect.makeZero();
		nativeGetFrameRectRelativeToWorld(r);
		return r;
	}

	private native void nativeGetFrameRectRelativeToWorld(WYRect r);
	
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
	public native void setDebugDrawFrameRect(boolean flag);
	
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
	public native void setDebugDrawCollisionRect(boolean flag);
	
	/**
	 * \if English
	 * Add a clip mapping to this sprite, which can be used later in \c playAnimation
	 *
	 * @param mapping \link AFCClipMapping AFCClipMapping\endlink
	 * \else
	 * 为当前精灵添加一组分片映射规则, 添加了之后可以通过\c playAnimation使用
	 *
	 * @param mapping \link AFCClipMapping AFCClipMapping\endlink
	 * \endif
	 */
	public native void addClipMapping(AFCClipMapping mapping);

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
	public native void removeClipMappingByTag(int tag);

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
	public AFCClipMapping getClipMappingByTag(int tag) {
		return AFCClipMapping.from(nativeGetClipMappingByTag(tag));
	}
	
	private native int nativeGetClipMappingByTag(int tag);
	
	/**
	 * \if English
	 * Replace current textures with another set of textures. You must ensure
	 * the new set of textures has same size and quantity as old set.
	 *
	 * @param tex texture list, other textures can follow it
	 * \else
	 * 整体替换掉所有贴图, 这个方法也可用于换装. 但是你必须保证新贴图与老贴图的大小数量都相同
	 *
	 * @param tex 贴图列表, 可变参数, 其它的贴图跟在后面
	 * \endif
	 */
	public native void replaceTextures(Texture2D... tex);
}
