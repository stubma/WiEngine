package com.wiyun.engine.nodes;

import java.util.ArrayList;

import android.view.GestureDetector.OnDoubleTapListener;
import android.view.GestureDetector.OnGestureListener;
import android.view.KeyEvent;
import android.view.MotionEvent;

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.events.IAccelerometerHandler;
import com.wiyun.engine.events.IKeyHandler;
import com.wiyun.engine.events.IMultiTouchHandler;
import com.wiyun.engine.grid.BaseGrid;
import com.wiyun.engine.opengl.Camera;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.utils.TargetSelector;

/**
 * WiEngine中节点的基类，可以在场景中放置的元素都必须集成自Node。Node封装了节点的通用逻辑
 * 和渲染过程。 
 */
public class Node extends BaseWYObject implements IKeyHandler, IMultiTouchHandler, IAccelerometerHandler, OnGestureListener, OnDoubleTapListener {
	/**
	 * \if English
	 * Blend mode
	 * \else
	 * 渲染模式
	 * \endif
	 */
	public enum BlendMode {
        /**
         * \if English
         * No blending mode is used.
         * \else
         * 不打开渲染模式
         * \endif
         */
        NO_BLEND,

        /**
         * \if English
         * Additive blending. For use with glows and particle emitters.
         *
         * \par
         * Result = Source Color + Destination Color -> (GL_ONE, GL_ONE)
         * \else
         * 追加式渲染
         *
         * \par
         * 结果 = 源色彩 + 目标色彩 = (GL_ONE, GL_ONE)
         * \endif
         */
        ADDITIVE,

        /**
         * \if English
         * Premultiplied alpha blending, for use with premultiplied alpha textures.
         *
         * \par
         * Result = Source Color + (Dest Color * (1 - Source Alpha) ) -> (GL_ONE, GL_ONE_MINUS_SRC_ALPHA)
         * \else
         * 预先计算alpha情况下的渲染
         *
         * \par
         * 结果 = 源色彩 + (目标色彩 * (1 - 源透明度)) = (GL_ONE, GL_ONE_MINUS_SRC_ALPHA)
         * \endif
         */
        PREMULTIPLIED_ALPHA,

        /**
         * \if English
         * Additive blending that is multiplied with source alpha.
         * For use with glows and particle emitters.
         *
         * \par
         * Result = (Source Alpha * Source Color) + Dest Color -> (GL_SRC_ALPHA, GL_ONE)
         * \else
         * 追加式渲染, 考虑源色彩透明度
         *
         * \par
         * 结果 = (源透明度 * 源色彩) + 目标色彩 = (GL_SRC_ALPHA, GL_ONE)
         * \endif
         */
        ALPHA_ADDITIVE,

        /**
         * \if English
         * Color blending, blends in color from dest color
         * using source color.
         *
         * \par
         * Result = Source Color + (1 - Source Color) * Dest Color -> (GL_ONE, GL_ONE_MINUS_SRC_COLOR)
         * \else
         * 颜色混合模式
         *
         * \par
         * 结果 = 源色彩 + (1 - 源色彩) * 目标色彩 = (GL_ONE, GL_ONE_MINUS_SRC_COLOR)
         * \endif
         */
        COLOR,

        /**
         * \if English
         * Alpha blending, interpolates to source color from dest color
         * using source alpha.
         *
         * \par
         * Result = Source Alpha * Source Color + (1 - Source Alpha) * Dest Color -> (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)
         * \else
         * alpha渲染, 最常见的一种形式
         *
         * \par
         * 结果 = 源透明度 * 源色彩 + (1 - 源透明度) * 目标色彩 = (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)
         * \endif
         */
        ALPHA,

        /**
         * \if English
         * Multiplies the source and dest colors.
         *
         * \par
         * Result = Source Color * Dest Color -> (GL_DST_COLOR, GL_ZERO)
         * \else
         * 调和模式
         *
         * \par
         * 结果 = 源色彩 * 目标色彩 = (GL_DST_COLOR, GL_ZERO)
         * \endif
         */
        MODULATE,

        /**
         * \if English
         * Multiplies the source and dest colors then doubles the result.
         *
         * \par
         * Result = 2 * Source Color * Dest Color -> (GL_DST_COLOR, GL_SRC_COLOR)
         * \else
         * 双倍调和模式
         *
         * \par
         * 结果 = 2 * 源色彩 * 目标色彩 = (GL_DST_COLOR, GL_SRC_COLOR)
         * \endif
         */
        MODULATE_X2
	}

	/**
	 * 用来监听节点位置变化的回调接口, 当setPosition方法被调用时, 这个
	 * 回掉会被触发
	 */
	public static interface IPositionListener {
		/**
		 * 当位置变化时, 该方法被调用
		 *
		 * @param nodePointer 底层的结点指针
		 */
		public void onPositionChanged(int nodePointer);
	}
	
	// for 2.0 back key compatibility
	private boolean mBackKeyTracking;
	
	/**
	 * 构造函数
	 */
	protected Node() {
		doNativeInit();
	}
	
	public static Node from(int pointer) {
		return pointer == 0 ? null : new Node(pointer);
	}
	
	protected Node(int pointer) {
		super(pointer);
	}
	
	protected void doNativeInit() {
		nativeInit();
	}
	
	private native void nativeInit();
	
	/**
	 * <p>和BaseWYObject.autoRelease的目的相同, 这个带一个参数可以指定递归释放所有的子
	 * 节点. 这是为了方便程序编写, 如果节点太多, 你可以只autoRelease一个顶层节点, 然后
	 * 把includeChildren设置为true. 不过要注意, 这个方法只会autoRelease子节点, 即Node
	 * 的子类, 不会autoRelease节点附加的Action等对象, 对于那些非Node子类的对象, 仍然需要去
	 * 调用autoRelease</p>
	 * 
	 * <p>这个方法反复调用是安全的, 不会造成底层引用计数混乱. 多余的调用会被
	 * 底层忽略. 假如某个子节点已经调用过了autoRelease, 那么那个子节点会被忽略, 因此也是
	 * 安全的.</p>
	 * 
	 * @param includeChildren true表示也同时释放所有子节点
	 */
	public Node autoRelease(boolean includeChildren) {
		nativeAutoRelease(includeChildren);
		return this;
	}
	
	private native void nativeAutoRelease(boolean includeChildren);
	
	/**
	 * 得到节点的全局坐标位置。返回的坐标根据<code>relativeAnchorPoint</code>标志的结果，如果是true则
	 * 表示是锚点，如果是false则表示是左下角
	 * 
	 * @return 全局坐标位置
	 */
	public WYPoint getAbsolutePosition() {
		WYPoint p = WYPoint.makeZero();
		nativeGetAbsolutePosition(p);
		return p;
	}
	
	private native void nativeGetAbsolutePosition(WYPoint p);

	/**
	 * 获得第一个子节点
	 * 
	 * @return {@link Node}
	 */
	public Node getFirstChild() {
		int pointer = nativeGetFirstChild();
		if(pointer > 0)
			return new Node(pointer);
		else
			return null;
	}
	
	private native int nativeGetFirstChild();
	
	/**
	 * 添加一个子节点
	 * 
	 * @param child {@link Node}
	 */
	public void addChild(Node child) {
		addChild(child, child.getZOrder(), child.getTag());
	}

	/**
	 * 添加一个子节点，指定一个z order值。Z order控制了子节点的远近关系，在渲染时，
	 * z order越小的子节点会越先渲染
	 * 
	 * @param child {@link Node}
	 * @param z z order值
	 */
	public void addChild(Node child, int z) {
		addChild(child, z, child.getTag());
	}

	/**
	 * 添加一个子节点，指定一个z order值和tag。Z order控制了子节点的远近关系，在渲染时，
	 * z order越小的子节点会越先渲染
	 * 
	 * @param child {@link Node}
	 * @param z z order值
	 * @param tag tag值
	 */
	public native void addChild(Node child, int z, int tag);
	
	/**
	 * 重置节点状态，包括子节点的状态
	 */
	public native void cleanup();
	
	/**
	 * 把一个全局坐标转换成节点内坐标
	 * 
	 * @param x 要转换的x值
	 * @param y 要转换的y值
	 * @return {@link WYPoint} 
	 */
	public WYPoint convertToNodeSpace(float x, float y) {
		WYPoint p = WYPoint.makeZero();
		nativeConvertToNodeSpace(x, y, p);
		return p;
	}
	
	private native void nativeConvertToWorldSpace(float x, float y, WYPoint out);
	private native void nativeConvertToWorldSpaceAR(float x, float y, WYPoint out);
	private native void nativeConvertToNodeSpace(float x, float y, WYPoint out);
	private native void nativeConvertToNodeSpaceAR(float x, float y, WYPoint out);

	/**
	 * 把一个全局坐标转换成节点内坐标，以节点的锚点为原点
	 * 
	 * @param x 要转换的x值
	 * @param y 要转换的y值
	 * @return {@link WYPoint} 
	 */
	public WYPoint convertToNodeSpaceAR(float x, float y) {
		WYPoint p = WYPoint.makeZero();
		nativeConvertToNodeSpaceAR(x, y, p);
		return p;
	}
	
	/**
	 * 把Android触摸事件中坐标转换成节点内坐标。 实际上这是一个两步的过程，先把android坐标
	 * 转换成OpenGL坐标，再把OpenGL全局坐标转换成节点内坐标
	 * 
	 * @param event {@link MotionEvent}
	 * @return {@link WYPoint}
	 */
	public WYPoint convertTouchToNodeSpace(MotionEvent event) {
		WYPoint p = WYPoint.makeZero();
		WYPoint loc = Director.getInstance().convertToGL(event.getX(), event.getY());
		nativeConvertToNodeSpace(loc.x, loc.y, p);
		return p;
	}

	/**
	 * 把Android触摸事件中坐标转换成节点内坐标。 以节点的锚点为原点
	 * 
	 * @param event {@link MotionEvent}
	 * @return {@link WYPoint}
	 */
	public WYPoint convertTouchToNodeSpaceAR(MotionEvent event) {
		WYPoint p = WYPoint.makeZero();
		WYPoint loc = Director.getInstance().convertToGL(event.getX(), event.getY());
		nativeConvertToNodeSpaceAR(loc.x, loc.y, p);
		return p;
	}

	/**
	 * 把节点内坐标转换为OpenGL全局坐标
	 * 
	 * @param x 要转换的x值
	 * @param y 要转换的y值
	 * @return {@link WYPoint} 
	 */
	public WYPoint convertToWorldSpace(float x, float y) {
		WYPoint p = WYPoint.makeZero();
		nativeConvertToWorldSpace(x, y, p);
		return p;
	}

	/**
	 * 把节点内坐标转换为OpenGL全局坐标。节点内坐标是以锚点为原点的。
	 * 
	 * @param x 要转换的x值
	 * @param y 要转换的y值
	 * @return {@link WYPoint} 
	 */
	public WYPoint convertToWorldSpaceAR(float x, float y) {
		WYPoint p = WYPoint.makeZero();
		nativeConvertToWorldSpaceAR(x, y, p);
		return p;
	}
	
	/**
	 * 设置java端的虚函数实现
	 * 
	 * @param j {@link INodeVirtualMethods}
	 */
	public native final void setJavaVirtualMethods(INodeVirtualMethods j);

	/**
     * 设置节点的enable状态。
     */
    public native void setEnabled(boolean enabled);

    /**
     * 得到节点当前的enable状态
     */
    public native boolean isEnabled();

    /**
     * 得到节点的选择状态
     */
    public native boolean isSelected();

    /**
     * 设置节点的当前选择状态
     */
    public native void setSelected(boolean flag);
    
    /**
     * 得到节点的获得焦点状态
     */
    public native boolean isFocused();
    
    /**
     * 设置节点的获得焦点状态
     */
    public native void setFocused(boolean flag);
    
	/**
	 * 得到锚点的x方向比例
	 * 
	 * @return 锚点x比例，从0到1
	 */
	public native float getAnchorX();

	/**
	 * 得到锚点的y方向比例
	 * 
	 * @return 锚点y比例，从0到1
	 */
	public native float getAnchorY();
	

	/**
	 * 得到是否绘制节点的标志
	 * 
	 * @return true表示不绘制节点，false表示绘制节点
	 */
	public native boolean isNoDraw();

	/**
	 * 设置是否绘制节点
	 * 
	 * @param noDraw true表示不绘制节点，false表示绘制节点
	 */
	public native void setNoDraw(boolean noDraw);
	
	/**
	 * 判断某个坐标是否落在了节点的矩形范围内，坐标必须是全局坐标. 这个方法判断的时候
	 * 会考虑节点当前的缩放, 旋转等参数. 如果节点是旋转了的, 那么实际判断的矩形范围
	 * 是节点的外接矩形.
	 * 
	 * @param x x坐标
	 * @param y y坐标
	 * @return true表示坐标在节点矩形范围内，false表示不在
	 */
	public native boolean hitTest(float x, float y);
	
	/**
	 * 返回节点自身坐标的矩形，(0，0)坐标到(width，height). 返回的矩形不会进行
	 * 变换, 不管节点是设置了缩放还是旋转, 返回的矩形始终是(0, 0)-(width, height).
	 * 返回矩形的origin代表左下角坐标
	 * 
	 * @return {@link WYRect}
	 */
	public WYRect getBoundingBox() {
		WYRect rect = WYRect.makeZero();
		nativeGetBoundingBox(rect);
		return rect;
	}
	
	private native void nativeGetBoundingBox(WYRect rect);
	private native void nativeGetBoundingBoxRelativeToParent(WYRect rect);
	private native void nativeGetBoundingBoxRelativeToWorld(WYRect rect);

	/**
	 * 返回节点自身针对父节点坐标的矩形, 这个矩形经过了变换, 比如如果节点的原始
	 * 大小是(100, 100), 但是节点设置了放大2倍, 则得到的矩形大小是(200, 200).
	 * 但是如果节点还设置了旋转, 则返回的矩形是外接矩形, 其大小不一定反映节点的
	 * 真实宽高. 返回矩形的origin代表左下角坐标
	 * 
	 * @return {@link WYRect}
	 */
	public WYRect getBoundingBoxRelativeToParent() {
		WYRect rect = WYRect.makeZero();
		nativeGetBoundingBoxRelativeToParent(rect);
		return rect;
	}
	
	/**
	 * 返回节点自身针对整个坐标轴坐标的矩形, 这个矩形经过了变换, 比如如果节点的原始
	 * 大小是(100, 100), 但是节点设置了放大2倍, 则得到的矩形大小是(200, 200).
	 * 但是如果节点还设置了旋转, 则返回的矩形是外接矩形, 其大小不一定反映节点的
	 * 真实宽高. 返回矩形的origin代表左下角坐标
	 * 
	 * @return {@link WYRect}
	 */
	public WYRect getBoundingBoxRelativeToWorld() {
		WYRect rect = WYRect.makeZero();
		nativeGetBoundingBoxRelativeToWorld(rect);
		return rect;
	}

	/**
	 * 得到节点上关联的相机对象
	 * 
	 * @return {@link Camera}
	 */
	public Camera getCamera() {
		return Camera.from(nativeGetCamera());
	}

	private native int nativeGetCamera();

	/**
	 * 通过tag得到某个子节点
	 * 
	 * @param tag 子节点的tag
	 * @return {@link Node}，如果没找到或者tag不合法，则返回null
	 */
	public Node getChild(int tag) {
		int pointer = getChildPointer(tag);
		return Node.from(pointer);
	}
	
	/**
	 * \if English
	 * Get children by tag, in thread safe way
	 *
	 * @param tag tag of node
	 * @return all matched children 
	 * \else
	 * 通过tag得到所有具有该tag的子节点, 方法是线程安全的
	 *
	 * @param tag 子节点的tag
	 * @return 所有匹配的子节点, 如果没找到返回NULL
	 * \endif
	 */
	public Node[] getChildren(int tag) {
		int[] p = getChildrenPointer(tag);
		if(p == null) {
			return null;
		} else {
			Node[] n = new Node[p.length];
			for(int i = 0; i < p.length; i++) {
				n[i] = Node.from(p[i]);
			}
			return n;
		}
	}
	
	/**
	 * \if English
	 * Get children by tag, in thread safe way
	 *
	 * @param tag tag of node
	 * @return all matched children pointer
	 * \else
	 * 通过tag得到所有具有该tag的子节点指针, 方法是线程安全的
	 *
	 * @param tag 子节点的tag
	 * @return 所有匹配的子节点指针, 如果没找到返回NULL
	 * \endif
	 */
	public native int[] getChildrenPointer(int tag);
	
	/**
	 * 通过tag得到某个子节点的底层指针
	 * 
	 * @param tag 子节点的tag
	 * @return 子节点指针, 您需要用具体类的from方法从指针获得java实例
	 */
	public native int getChildPointer(int tag);
	
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
	public native int getChildPointerAt(int index);

	/**
	 * 得到所有子节点列表
	 * 
	 * @return {@link Node}列表
	 */
	public ArrayList<Node> getChildren() {
		ArrayList<Node> children = new ArrayList<Node>();
		int[] pointers = new int[getChildCount()];
		nativeGetChildren(pointers);
		for(int pointer : pointers)
			children.add(new Node(pointer));
		return children;
	}

	public native int getChildCount();
	
	private native void nativeGetChildren(int[] children);

	/**
	 * 得到节点上绑定的网格对象
	 * 
	 * @return {@link BaseGrid}
	 */
	public BaseGrid getGrid() {
		return BaseGrid.from(nativeGetGrid());
	}
	
	private native int nativeGetGrid();

	/**
	 * 得到节点高度
	 * 
	 * @return 节点象素高度
	 */
	public native float getHeight();

	/**
	 * 得到节点的宽度
	 * 
	 * @return 节点象素宽度
	 */
	public native float getWidth();
	
	/**
	 * 得到父节点. 父节点是个一个Node类, 不能被直接类型转换成其他类. 因为WiEngine
	 * 的java端只是包装native层的指针, 在包装时并不能了解是什么类型. 如果需要将得到
	 * 的父节点转换成Scene类, 应该这样做: Scene.from(getParent().getPointer());
	 * 
	 * @return {@link Node}
	 */
	public Node getParent() {
		int pointer = nativeGetParent();
		return pointer > 0 ? new Node(nativeGetParent()) : null;
	}
	
	private native int nativeGetParent();

	/**
	 * 得到当前位置的x值
	 * 
	 * @return 返回的坐标根据<code>relativeAnchorPoint</code>标志的结果，如果是true则
	 * 		表示是锚点，如果是false则表示是左下角
	 */
	public native float getPositionX();

	/**
	 * 得到当前位置的y值
	 * 
	 * @return 返回的坐标根据<code>relativeAnchorPoint</code>标志的结果，如果是true则
	 * 		表示是锚点，如果是false则表示是左下角
	 */
	public native float getPositionY();
	
	/**
	 * 获得原点的x坐标, 原点即左下角的x坐标, 根据节点设置的不同, 左下角坐标
	 * 可能等于position也可能不等于
	 *
	 * @return 左下角的x坐标
	 */
	public native float getOriginX();

	/**
	 * 获得原点的y坐标, 原点即左下角的x坐标, 根据节点设置的不同, 左下角坐标
	 * 可能等于position也可能不等于
	 *
	 * @return 左下角的y坐标
	 */
	public native float getOriginY();

	/**
	 * 获取旋转角度，正值表示顺时针，负值表示逆时针
	 * 
	 * @return 旋转角度
	 */
	public native float getRotation();

	/**
	 * 得到x轴缩放比例
	 * 
	 * @return 缩放比例
	 */
	public native float getScaleX();

	/**
	 * 得到y轴缩放比例
	 * 
	 * @return 缩放比例
	 */
	public native float getScaleY();

	/**
	 * 得到节点的tag
	 * 
	 * @return tag
	 */
	public native int getTag();
	
	/**
	 * 设置节点的tag
	 * 
	 * @param tag tag的值
	 */
	public native void setTag(int tag);

	/**
	 * 得到锚点相对于节点自身坐标系的x坐标
	 * 
	 * @return x位置
	 */
	public native float getAnchorPointX();

	/**
	 * 得到锚点相对于节点自身坐标系的y坐标
	 * 
	 * @return y位置
	 */
	public native float getAnchorPointY();
	
	/**
	 * 得到节点上的附加数据对象
	 * 
	 * @return {@link Object}
	 */
	public native Object getUserData();

	/**
	 * 得到节点的z order值
	 * 
	 * @return 节点在父节点中的z order值
	 */
	public native int getZOrder();
	
	/**
	 * 设置节点在父节点中的z order值. 这个方法只能在构造时调用, 如果想动态
	 * 的修改z order, 使用reorderChild
	 * 
	 * @param z 在父节点中的z order值
	 */
	public native void setZOrder(int z);

	/**
	 * 得到节点当前是否在运行中
	 * 
	 * @return true表示节点当前在一个正在运行的场景中 
	 */
	public native boolean isRunning();

	/**
	 * 得到节点是否可见
	 * 
	 * @return true表示节点可见
	 */
	public native boolean isVisible();
	
	/**
	 * 设置节点是否可见
	 * 
	 * @param visible true表示可见
	 */
	public native void setVisible(boolean visible);

	/**
	 * 得到当前附加于该节点的动作数
	 * 
	 * @return 附加于该节点的动作数
	 */
	public int getRunningActionCount() {
		return ActionManager.getInstance().getRunningActionCount(this);
	}
	
	/**
	 * 检查是否这个节点上有一些动作正在运行
	 * 
	 * @return true表示当前有至少一个动作在这个节点上运行
	 */
	public boolean hasRunningAction() {
		return getRunningActionCount() > 0;
	}
	
	/**
	 * 当节点要变成活动态时，该方法被调用。活动态即节点所属的场景正在运行。
	 * 该方法由WiEngine内部调用，不需要手动调用
	 */
	public native final void onEnter();

	/**
	 * 当节点所属场景切换完成时该方法被调用
	 * 该方法由WiEngine内部调用，不需要手动调用
	 */
	public native final void onEnterTransitionDidFinish();

	/**
	 * 当节点所属场景退出时该方法被调用，或者当该节点被删除时被调用
	 * 该方法由WiEngine内部调用，不需要手动调用
	 */
	public native final void onExit();
	
	/**
	 * 删除所有子节点
	 * 
	 * @param cleanup true表示重置被删除的节点的状态。一个节点被clean之后将失去一些状态，比如附加在节点
	 * 		上的action，timer等，但是这个节点仍然可以用addChild加回来继续使用。
	 */
	public native void removeAllChildren(boolean cleanup);

	/**
	 * 删除某个子节点
	 * 
	 * @param child 要删除的节点
	 * @param cleanup true表示重置被删除的节点的状态。一个节点被clean之后将失去一些状态，比如附加在节点
	 * 		上的action，timer等，但是这个节点仍然可以用addChild加回来继续使用。
	 */
	public native void removeChild(Node child, boolean cleanup);

	/**
	 * 根据tag删除某个子节点
	 * 
	 * @param tag 子节点的tag
	 * @param cleanup true表示重置被删除的节点的状态。一个节点被clean之后将失去一些状态，比如附加在节点
	 * 		上的action，timer等，但是这个节点仍然可以用addChild加回来继续使用。
	 */
	public native void removeChild(int tag, boolean cleanup);
	
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
	public native void removeChildren(int tag, boolean cleanup);
	
	/**
	 * 修改节点的z order值
	 * 
	 * @param child 要修改的子节点
	 * @param z 新的z order值
	 */
	public native void reorderChild(Node child, int z);
	
	/**
	 * 把一个子节点挪动到最前面, 因此它会是最后渲染的子节点, 可能盖住其它的子节点
	 *
	 * @param child 子节点, 如果该节点不是当前节点的子节点, 则不做任何事
	 */
	public native void bringToFront(Node child);

	/**
	 * 把一个子节点挪到最后面, 因此它会是最先渲染的子节点, 后面的子节点可能覆盖它.
	 *
	 * @param child 子节点, 如果该节点不是当前节点的子节点, 则不做任何事
	 */
	public native void bringToBack(Node child);

	/**
	 * 在这个节点上运行一个动作
	 * 
	 * @param action {@link Action}
	 */
	public native void runAction(Action action);

	/**
	 * 得到当前的缩放比例
	 * 
	 * @return 缩放比例
	 */
	public native float getScale();

	/**
	 * 对节点进行指定比例的缩放
	 * 
	 * @param s 缩放比例
	 */
	public native void scale(float s);
	
	/**
	 * 开始调用一个方法
	 * 
	 * @param selector {@link TargetSelector}对象，回调的方法必须是public的且至少有一个float参数，该
	 * 		参数必须是第一个参数, 含义是上一次调用到现在的时间，单位秒. 其后可以跟其它参数.
	 */
	public void schedule(TargetSelector selector) {
		schedule(selector, 0f);
	}
	
	/**
	 * 按照帧间隔开始调用一个方法
	 * 
	 * @param selector {@link TargetSelector}对象，回调的方法必须是public的且至少有一个float参数，该
	 * 		参数必须是第一个参数, 含义是上一次调用到现在的时间，单位秒. 其后可以跟其它参数.
	 * @param frame 调用的帧间隔，如果为2，表示每2帧调用方法一次，小于等于0时都表示下一帧执行
	 */
	public native void scheduleByFrame(TargetSelector selector, int frame);
	
	/**
	 * 开始调用一个方法
	 * 
	 * @param selector {@link TargetSelector}对象，回调的方法必须是public的且至少有一个float参数，该
	 * 		参数必须是第一个参数, 含义是上一次调用到现在的时间，单位秒. 其后可以跟其它参数.
	 * @param interval 重复调用间隔，单位秒。为0表示每帧都会调用，小于0时当做0处理
	 */
	public native void schedule(TargetSelector selector, float interval);
	
	/**
	 * 开始调用一个方法，这个方法只会调用一次
	 * 
	 * @param selector {@link TargetSelector}对象，回调的方法必须是public的且至少有一个float参数，该
	 * 		参数必须是第一个参数, 含义是上一次调用到现在的时间，单位秒. 其后可以跟其它参数.
	 */
	public void scheduleOnce(TargetSelector selector) {
		scheduleOnce(selector, 0f);
	}

	/**
	 * 开始调用一个方法，这个方法只会调用一次
	 * 
	 * @param selector {@link TargetSelector}对象，回调的方法必须是public的且至少有一个float参数，该
	 * 		参数必须是第一个参数, 含义是上一次调用到现在的时间，单位秒. 其后可以跟其它参数.
	 * @param delay 调用延迟，单位秒。为0表示立刻调用，小于0时当做0处理
	 */
	public native void scheduleOnce(TargetSelector selector, float delay);
	
	/**
	 * 开始调用一个方法，这个方法只会调用一次
	 * 
	 * @param selector {@link TargetSelector}对象，回调的方法必须是public的且至少有一个float参数，该
	 * 		参数必须是第一个参数, 含义是上一次调用到现在的时间，单位秒. 其后可以跟其它参数.
	 * @param delayFrame 调用的延迟帧数，为0表示下一帧就调用，为1表示等一帧，等等。小于等于0时当做1处理
	 */
	public native void scheduleOnceByFrame(TargetSelector selector, int delayFrame);

	/**
	 * 取消对一个方法的重复调用
	 * 
	 * @param selector 需要解除调度的{@link TargetSelector}对象
	 */
	public native void unschedule(TargetSelector selector);
	
	/**
	 * 设置锚点的相对位置
	 * 
	 * @param x 相对x位置，从0到1
	 * @param y 相对y位置，从0到1
	 */
	public native void setAnchor(float x, float y);
	
	/**
	 * 设置锚点的x位置
	 * 
	 * @param x 相对x位置，从0到1
	 */
	public native void setAnchorX(float x);
	
	/**
	 * 设置锚点的y位置
	 * 
	 * @param y 相对y位置，从0到1
	 */
	public native void setAnchorY(float y);
	
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
	public native void moveAnchorTo(float x, float y);
	
	/**
	 * 设置节点的大小
	 * 
	 * @param w 节点象素宽度
	 * @param h 节点象素高度
	 */
	public native void setContentSize(float w, float h);
	
	/**
	 * 设置变换矩阵状态为脏，这样Node会强制底层更新变换矩阵
	 */
	public native void setTransformDirty();

	/**
	 * 设置节点的网格对象
	 * 
	 * @param grid {@link BaseGrid}
	 */
	public native void setGrid(BaseGrid grid);
	
	/**
	 * 设置节点的父节点
	 * 
	 * @param parent {@link Node}
	 */
	protected native void setParent(Node parent);
	
	/**
	 * 设置节点位置, 根据<code>relativeAnchorPoint</code>标志的结果，如果是true则
	 * 表示是锚点，如果是false则表示是左下角
	 * 
	 * @param p {@link WYPoint}
	 */
	public void setPosition(WYPoint p) {
		setPosition(p.x, p.y);
	}

	/**
	 * 设置节点位置, 根据<code>relativeAnchorPoint</code>标志的结果，如果是true则
	 * 表示是锚点，如果是false则表示是左下角
	 * 
	 * @param x x位置
	 * @param y y位置
	 */
	public native void setPosition(float x, float y);
	
	/**
	 * 平移节点
	 * 
	 * @param x 平移的x值
	 * @param y 平移的y值
	 */
	public native void translate(float x, float y);
	
	/**
	 * 平移所有子节点, 只平移一级, 不会平移子节点的子节点
	 *
	 * @param x 平移的x值
	 * @param y 平移的y值
	 */
	public native void translateChildren(float x, float y);

	/**
	 * 设置是否position和anchor position分离
	 * 
	 * @param newValue true表示不分离，false表示分离
	 */
	public native void setRelativeAnchorPoint(boolean newValue);
	
	/**
	 * 得到是否position和anchor position是分离的
	 * 
	 * @return true表示不分离，false表示分离
	 */
	public native boolean isRelativeToAnchor();

	/**
	 * 设置旋转角度, 正值表示顺时针，负值表示逆时针
	 * 
	 * @param rot 角度
	 */
	public native void setRotation(float rot);
	
	/**
	 * 设置缩放比例
	 * 
	 * @param sx x方向缩放比例
	 * @param sy y方向缩放比例
	 */
	public void setScale(float sx, float sy) {
		setScaleX(sx);
		setScaleY(sy);
	}

	/**
	 * 设置缩放比例
	 * 
	 * @param s 缩放比例, 将把x和y都设置成同样比例
	 */
	public native void setScale(float s);

	/**
	 * 设置x方向缩放比例
	 * 
	 * @param sx x方向缩放比例
	 */
	public native void setScaleX(float sx);

	/**
	 * 设置y方向缩放比例
	 * 
	 * @param sy y方向缩放比例
	 */
	public native void setScaleY(float sy);
	
	/**
	 * \if English
	 * The X skew angle of the node in degrees. This angle describes the shear distortion in the X direction.
	 * Thus, it is the angle between the Y axis and the left edge of the shape. The default skewX angle is 0.
	 * Positive values distort the node in a CCW direction.
	 * \else
	 * 设置x轴扭曲角度. 这个扭曲角度表示的是在x方向上的倾斜程度, 它是y轴和节点左边界的角度值. 正值为逆时针方向.
	 * \endif
	 */
	public native void setSkewX(float degree);

	/**
	 * \if English
	 * The Y skew angle of the node in degrees. This angle describes the shear distortion in the Y direction.
	 * Thus, it is the angle between the X axis and the bottom edge of the shape. The default skewY angle is 0.
	 * Positive values distort the node in a CCW direction.
	 * \else
	 * 设置y轴扭曲角度. 这个扭曲角度表示的是在y方向上的倾斜程度, 它是x轴和节点底边的角度值. 正值为逆时针方向.
	 * \endif
	 */
	public native void setSkewY(float degree);
	
	/**
	 * \if English
	 * Get X axis shear distortion degree. Positive value is counter-clockwise
	 * \else
	 * 得到x方向的倾斜角度, 正值表示逆时针
	 * \endif
	 */
	public native float getSkewX();

	/**
	 * \if English
	 * Get Y axis shear distortion degree. Positive value is counter-clockwise
	 * \else
	 * 得到y方向的倾斜角度, 正值表示逆时针
	 * \endif
	 */
	public native float getSkewY();

	/**
	 * 设置附加数据对象
	 * 
	 * @param data {@link Object}
	 */
	public native void setUserData(Object data);

	/**
	 * 得到节点的z值
	 * 
	 * @return 节点在整个OpenGL中的z order值
	 */
	public native float getVertexZ();
	
	/**
	 * 设置节点在OpenGL中的z order值
	 * 
	 * @param z 在OpenGL中的z order值
	 */
	public native void setVertexZ(float z);

	/**
	 * 停止某个动作
	 * 
	 * @param action {@link Action}
	 */
	public native final void stopAction(Action action);

	/**
	 * 根据tag停止某个动作
	 * 
	 * @param tag {@link Action}的tag
	 */
	public native final void stopAction(int tag);

	/**
	 * 停止所有动作
	 */
	public native final void stopAllActions();	
	
	/**
	 * 通过tag找到某个action的指针
	 * 
	 * @param tag action的tag
	 * @return action的底层指针, 你需要用对应类的from方法得到java对象
	 */
	public native int getActionPointer(int tag);
	
	/**
	 * 停止所有动作
	 * 
	 * @param includeChildren true表示也停止子节点上的所有动作
	 */
	public native void stopAllActions(boolean includeChildren);
	
	/**
	 * 暂停该节点上的所有动作, 之后可以通过resumeAllActions恢复
	 */
	public native void pauseAllActions();
	
	/**
	 * 暂停该节点上的所有动作, 之后可以通过resumeAllActions恢复
	 *
	 * @param includeChildren true表示也暂停子节点上的所有动作
	 */
	public native void pauseAllActions(boolean includeChildren);
	
	/**
	 * 暂停一个动作, 要暂停的动作通过tag指定. 如果不存在这个tag的动作, 则不做任何事.
	 * 动作暂停后可以用resumeAction或resumeAllActions恢复运行.
	 *
	 * \note
	 * 如果一个动作被其它的组合类动作所包含, 则暂停这样的动作是无效的
	 *
	 * @param tag 动作的tag
	 */
	public native void pauseAction(int tag);

	/**
	 * 恢复一个动作, 要恢复的动作通过tag指定. 如果不存在这个tag的动作, 则不做任何事.
	 *
	 * @param tag 动作的tag
	 */
	public native void resumeAction(int tag);
	
	/**
	 * 恢复该节点上的所有动作
	 */
	public native void resumeAllActions();

	/**
	 * 恢复该节点上的所有动作
	 *
	 * @param includeChildren true表示也恢复子节点上的所有动作
	 */
	public native void resumeAllActions(boolean includeChildren);
	
	/**
	 * \if English
	 * Pause all timers scheduled on this node. You can resume it by \c resumeAllTimers
	 * \else
	 * 暂停该节点上的所有定时器, 之后可以通过resumeAllTimers恢复
	 * \endif
	 */
	public native void pauseAllTimers();
	
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
	public native void pauseAllTimers(boolean includeChildren);

	/**
	 * \if English
	 * resume all timers scheduled on this node. You can pause it by \c pauseAllTimers
	 * \else
	 * 恢复该节点上的所有定时器, 之后可以通过\c pauseAllTimers暂停
	 * \endif
	 */
	public native void resumeAllTimers();
	
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
	public native void resumeAllTimers(boolean includeChildren);

	@Override
	public String toString() {
		return "<instance of " + this.getClass() + "| Tag = " + getTag() + ">";
	}
	
	/**
	 * 是否接收手势事件
	 * 
	 * @return true表示接收手势事件
	 */
	public native final boolean isGestureEnabled();

	/**
	 * 设置是否接收手势事件
	 * 
	 * @param enabled true表示接收手势事件
	 */
	public native final void setGestureEnabled(boolean enabled);
	
	/**
	 * 是否接收双击事件
	 * 
	 * @return true表示接收双击事件
	 */
	public native final boolean isDoubleTapEnabled();

	/**
	 * 设置是否接收双击事件
	 * 
	 * @param enabled true表示接收双击事件
	 */
	public native final void setDoubleTapEnabled(boolean enabled);
	
	/**
	 * 是否接收触摸事件
	 * 
	 * @return true表示接收触摸事件
	 */
	public native final boolean isTouchEnabled();

	/**
	 * 设置是否接收触摸事件. 注意, 如果在java层调用setTouchEnabled(true), 
	 * 就意味着你想来java端处理触摸事件, 底层将不负责事件处理. 这在某些情况
	 * 下可能带来问题. 比如说Menu, Menu缺省是在native层处理触摸事件的, 如果
	 * 你先调用setTouchEnabled(false), 再调用setTouchEnabled(true), 看
	 * 起来应该没问题, 但实际上这样一来Menu的事件处理被重定向到了java端, 导致
	 * Menu点击无反应. 所以, 如果只是想临时禁止节点不处理事件, 推荐使用
	 * setEnabled(false). 
	 * 
	 * @param enabled true表示接收触摸事件
	 */
	public native final void setTouchEnabled(boolean enabled);
	
	/**
	 * 设置是否接收按键事件
	 * 
	 * @param enabled true表示接收按键事件
	 */
	public native final void setKeyEnabled(boolean enabled);
	
	/**
	 * 是否接收按键事件
	 * 
	 * @return true表示接收按键事件
	 */
	public native final boolean isKeyEnabled();

	/**
	 * 是否接收加速器事件
	 * 
	 * @return true表示接收加速器事件
	 */
	public native final boolean isAccelerometerEnabled();

	/**
	 * 设置是否接收加速器事件
	 * 
	 * @param enabled true表示接收加速器事件
	 */
	public native final void setAccelerometerEnabled(boolean enabled);
	
	/**
	 * 设置触摸事件优先级
	 *
	 * @param p 优先级数值, 越大则越先收到事件
	 */
	public native void setTouchPriority(int p);

	/**
	 * 设置按键事件优先级
	 *
	 * @param p 优先级数值, 越大则越先收到事件
	 */
	public native void setKeyPriority(int p);

	/**
	 * 设置手势事件优先级
	 *
	 * @param p 优先级数值, 越大则越先收到事件
	 */
	public native void setGesturePriority(int p);

	/**
	 * 设置双击事件优先级
	 *
	 * @param p 优先级数值, 越大则越先收到事件
	 */
	public native void setDoubleTapPriority(int p);

	/**
	 * 设置加速器事件优先级
	 *
	 * @param p 优先级数值, 越大则越先收到事件
	 */
	public native void setAccelerometerPriority(int p);

	/**
	 * 获得触摸事件优先级
	 *
	 * @return p 优先级数值, 越大则越先收到事件
	 */
	public native int getTouchPriority();

	/**
	 * 获得按键事件优先级
	 *
	 * @return p 优先级数值, 越大则越先收到事件
	 */
	public native int getKeyPriority();

	/**
	 * 获得手势事件优先级
	 *
	 * @return p 优先级数值, 越大则越先收到事件
	 */
	public native int getGesturePriority();

	/**
	 * 获得双击事件优先级
	 *
	 * @return p 优先级数值, 越大则越先收到事件
	 */
	public native int getDoubleTapPriority();

	/**
	 * 获得加速器事件优先级
	 *
	 * @return p 优先级数值, 越大则越先收到事件
	 */
	public native int getAccelerometerPriority();
	
	/**
	 * 设置节点的速度. 方便于设置简单的物理功能, 对于只需要速度加速度的情况, 可以省掉
	 * 自己维护或者使用物理引擎的麻烦.
	 *
	 * @param vx x方向速度
	 * @param vy y方向速度
	 */
	public native void setVelocity(float vx, float vy);

	/**
	 * 设置节点的加速度. 方便于设置简单的物理功能, 对于只需要速度加速度的情况, 可以省掉
	 * 自己维护或者使用物理引擎的麻烦.
	 *
	 * @param ax x方向加速度
	 * @param ay y方向加速度
	 */
	public native void setAcceleration(float ax, float ay);
	
	/**
	 * 设置节点的加速度. 方便于设置简单的物理功能, 对于只需要速度加速度的情况, 可以省掉
	 * 自己维护或者使用物理引擎的麻烦.
	 *
	 * @param ax x方向加速度
	 */
	public native void setAccelerationX(float ax);

	/**
	 * 设置节点的加速度. 方便于设置简单的物理功能, 对于只需要速度加速度的情况, 可以省掉
	 * 自己维护或者使用物理引擎的麻烦.
	 *
	 * @param ay y方向加速度
	 */
	public native void setAccelerationY(float ay);

	/**
	 * 设置节点的x方向速度. 方便于设置简单的物理功能, 对于只需要速度加速度的情况, 可以省掉
	 * 自己维护或者使用物理引擎的麻烦.
	 *
	 * @param vx x方向速度
	 */
	public native void setVelocityX(float vx);

	/**
	 * 设置节点的y方向速度. 方便于设置简单的物理功能, 对于只需要速度加速度的情况, 可以省掉
	 * 自己维护或者使用物理引擎的麻烦.
	 *
	 * @param vy y方向速度
	 */
	public native void setVelocityY(float vy);
	
	/**
	 * 得到节点的x方向速度
	 *
	 * @return x方向速度, 单位是像素
	 */
	public native float getVelocityX();

	/**
	 * 得到节点的y方向速度
	 *
	 * @return y方向速度, 单位是像素
	 */
	public native float getVelocityY();

	/**
	 * 得到节点的速度
	 *
	 * @return 节点的速度, 单位是像素
	 */
	public WYPoint getVelocity() {
		WYPoint p = WYPoint.makeZero();
		nativeGetVelocity(p);
		return p;
	}
	
	private native void nativeGetVelocity(WYPoint p);

	/**
	 * 得到节点的x方向加速度
	 *
	 * @return x方向加速度, 单位是像素
	 */
	public native float getAccelerationX();

	/**
	 * 得到节点的y方向加速度
	 *
	 * @return y方向加速度, 单位是像素
	 */
	public native float getAccelerationY();

	/**
	 * 得到节点的加速度
	 *
	 * @return 节点的加速度, 单位是像素
	 */
	public WYPoint getAcceleration() {
		WYPoint p = WYPoint.makeZero();
		nativeGetAcceleration(p);
		return p;
	}
	
	private native void nativeGetAcceleration(WYPoint p);
	
	/**
	 * 设置java层的位置事件回调接口
	 *
	 * @param listener java层的位置事件回调接口实现类
	 */
	public native void setPositionListener(IPositionListener listener);
	
	/**
	 * 设置clip矩形, 这可以用来使节点的内容只在指定矩形范围内可见.
	 *
	 * @param clip clip矩形
	 * @param relativeToSelf true表示参数\c clip 代表的是一个相对于节点自身坐标的矩形, false表示
	 * 		参数\c clip 代表的是一个全局坐标矩形. 这是可选参数, 缺省情况下是false.
	 */
	public native void setClipRect(WYRect clip, boolean relativeToSelf);
	
	/**
	 * 设置clip矩形, 这可以用来使节点的内容只在指定矩形范围内可见.
	 *
	 * @param clip clip矩形
	 */
	public void setClipRect(WYRect clip) {
		setClipRect(clip, false);
	}
	
	/**
	 * \if English
	 * Clear clip rect
	 * \else
	 * 标记当前节点没有裁剪矩形
	 * \endif
	 */
	public native void clearClipRect();

	/**
	 * 得到clip矩形
	 *
	 * @return clip矩形. 如果矩形的宽或高为0表示没有clip
	 */
	public WYRect getClipRect() {
		WYRect r = WYRect.makeZero();
		nativeGetClipRect(r);
		return r;
	}
	
	private native void nativeGetClipRect(WYRect r);
	
	public boolean wyTouchesBegan(MotionEvent event) {
		return false; 
	}

	public boolean wyTouchesMoved(MotionEvent event) {
		return false;
	}

	public boolean wyTouchesEnded(MotionEvent event) {
		return false;
	}

	public boolean wyTouchesCancelled(MotionEvent event) {
		return false;
	}
	
	public boolean wyTouchesPointerBegan(MotionEvent event) {
		return false;
	}
	
	public boolean wyTouchesPointerEnded(MotionEvent event) {
		return false;
	}
	
	public void wyAccelerometerChanged(float accelX, float accelY, float accelZ) {
	}

	public boolean wyKeyDown(KeyEvent event) {
		switch(event.getKeyCode()) {
			case KeyEvent.KEYCODE_BACK:
				mBackKeyTracking = true;
				return true;
			default:
				return false;
		}
	}
	
	public boolean wyKeyUp(KeyEvent event) {
		switch(event.getKeyCode()) {
			case KeyEvent.KEYCODE_BACK:
				if(mBackKeyTracking) {
					mBackKeyTracking = false;
					return onBackButton();
				} else {
					return false;
				}
			default:
				return false;
		}
	}
	
	public boolean wyKeyMultiple(KeyEvent event) {
		return false;
	}

	protected boolean onBackButton() {
		return false;
	}

	public boolean onDown(MotionEvent e) {
		return false;
	}

	public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY) {
		return false;
	}

	public void onLongPress(MotionEvent e) {
	}

	public boolean onScroll(MotionEvent e1, MotionEvent e2, float distanceX, float distanceY) {
		return false;
	}

	public void onShowPress(MotionEvent e) {
	}

	public boolean onSingleTapUp(MotionEvent e) {
		return false;
	}

	public boolean onDoubleTap(MotionEvent e) {
		return false;
	}

	public boolean onDoubleTapEvent(MotionEvent e) {
		return false;
	}

	public boolean onSingleTapConfirmed(MotionEvent e) {
		return false;
	}
	
	/**
	 * 把当前节点的大小调整为能完整包含所有子节点，如果当前节点有一个子节点，它
	 * 相对于当前节点的坐标是(10, 10), 大小是(100, 100), 那么实际上要把当前
	 * 节点的大小改成(110, 110). 如果子节点在该方法调用时还具有旋转或缩放的属性，
	 * 则实际计算的是子节点的外接矩形。
	 */
	public native void sizeToFit();
	
	/**
	 * 将节点扩大, 扩大的尺寸通过四个方向的距离指定. 这个方法配合sizeToFit使用, 可以较方便的
	 * 控制父节点的大小.
	 *
	 * @param left 左边扩大的大小
	 * @param top 上边扩大的大小
	 * @param right 右边扩大的大小
	 * @param bottom 下边扩大的大小
	 */
	public native void enlargeNode(float left, float top, float right, float bottom);
	
	/**
	 * 判断当前节点是否是某个节点的父节点或更高的节点
	 *
	 * @param node 要检查的节点, 如果该节点是当前节点的子孙, 则返回true
	 * @return 如果\c node 是当前节点的子孙, 则返回true
	 */
	public native boolean isAncestor(Node node);
	
	/**
	 * 设置是否不让后续节点处理触摸事件. 缺省值是true, 即不让后续节点继续处理事件.
	 *
	 * \note
	 * 这个值控制的是native层的事件行为, 如果事件是在java端处理的(即您在java端调用过
	 * setTouchEnabled(true), 则这个方法无效, 因为事件已经被重新定向到java端.
	 * 
	 * @param flag true表示不让后续节点继续处理事件
	 */
	public native void setInterceptTouch(boolean flag);
	
	/**
	 * 设置节点是否在非第一触点的情况下也触发点击事件
	 *
	 * @param flag true表示在非第一触点的情况下也触发点击事件
	 */
	public native void setMultiTouchClickable(boolean flag);

	/**
	 * 节点是否在非第一触点的情况下也触发点击事件
	 *
	 * @return true表示在非第一触点的情况下也触发点击事件
	 */
	public native boolean isMultiTouchClickable();

	/**
	 * \if English
	 * Get current alpha
	 * \else
	 * 得到当前alpha值
	 * \endif
	 */
	public native int getAlpha();

	/**
	 * \if English
	 * Set node alpha
	 * \else
	 * 设置alpha值
	 * \endif
	 */
	public native void setAlpha(int alpha);
	
	/**
	 * \if English
	 * Get node color
	 * \else
	 * 得到当前颜色
	 * \endif
	 */
	public WYColor3B getColor() {
		WYColor3B c = new WYColor3B();
		nativeGetColor(c);
		return c;
	}

	private native void nativeGetColor(WYColor3B c);

	/**
	 * \if English
	 * Get node color
	 * \else
	 * 设置颜色
	 * \endif
	 */
	public native void setColor(WYColor3B color);

	/**
	 * \if English
	 * Set node color
	 * \else
	 * 设置颜色
	 * \endif
	 */
	public native void setColor(WYColor4B color);
	
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
	public native boolean isDither();

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
	public native void setDither(boolean flag);
	
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
	public BlendMode getBlendMode() {
		return BlendMode.values()[nativeGetBlendMode()];
	}
	
	private native int nativeGetBlendMode();

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
	public void setBlendMode(BlendMode mode) {
		nativeSetBlendMode(mode.ordinal());
	}
	
	private native void nativeSetBlendMode(int m);
	
	/**
	 * \if English
	 * Get texture of node
	 * \else
	 * 得到当前\link wyTexture2D wyTexture2D对象指针\endlink
	 * \endif
	 */
    public Texture2D getTexture() {
        return Texture2D.from(nativeGetTexture());
    }
    
    private native int nativeGetTexture();
    
	/**
	 * \if English
	 * Set texture of node
	 * \else
	 * 设置\link wyTexture2D wyTexture2D对象指针\endlink
	 * \endif
	 */
    public native void setTexture(Texture2D texture);
}