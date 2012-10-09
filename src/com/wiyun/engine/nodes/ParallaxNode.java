package com.wiyun.engine.nodes;


/**
 * <p>视差滚动支持。可以为子节点指定视差比率，视差比率越大的子节点移动越迅速，所以会产生一种
 * 远近程度不同的感觉。视差节点的缺省大小是全屏幕, 在移动子节点时, 使用offsetBy方法, 不要
 * 使用setPosition方法, 因为setPosition是改变视差节点的位置, 而offsetBy是改变子节点的位置.<p><br>
 *
 * <p>视差节点维护了一个偏移值, 刚创建时偏移值是0且无限制, 可以调用相关方法设置最大和最小偏移,
 * 这在某些情况下, 比如使用fling时, 可以控制滚动的范围. 对于范围的计算, 设定一个基准点为0,
 * 如果这个基准点往左移, 则是负的偏移, 如果基准点往右移, 则是正偏移.</p><br>
 *
 * <p>视差对象还可以设定一个缩放范围, 举例来说, 如果设定一个视差对象的水平缩放范围是0到2,
 * 那么当ParallaxNode的偏移为最小值时, 这个对象对应的节点是看不见的, 而ParallaxNode的偏移
 * 为最大值时, 这个对象对应节点有两倍大.</p>
 */
public class ParallaxNode extends Node {
	/**
	 * 创建视差节点对象
	 * 
	 * @return 视差节点
	 */
	public static ParallaxNode make() {
		return new ParallaxNode();
	}

	/**
	 * 构造函数
	 */
	protected ParallaxNode() {
		nativeInit();
	}
	
    /**
     * 从底层指针获得一个ParallaxNode的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ParallaxNode}
     */
    public static ParallaxNode from(int pointer) {
    	return pointer == 0 ? null : new ParallaxNode(pointer);
    }
    
    protected ParallaxNode(int pointer) {
    	super(pointer);
    }
    
	private native void nativeInit();
	
	@Override
	protected void doNativeInit() {
	}

	@Override
	public native void addChild(Node child, int z, int tag);

	/**
	 * 添加子节点
	 * 
	 * @param child 子节点
	 * @param z 子节点的z order值
	 * @param ratioX x视差比例
	 * @param ratioY y视差比例
	 */
	public native void addChild(Node child, int z, float ratioX, float ratioY);

	@Override
	public native void removeChild(Node node, boolean cleanup);
	
	@Override
	public native void removeAllChildren(boolean cleanup);
	
	/**
	 * 对视差节点进行内部位移, 这个方法不改变视差节点的位置, 只是改变视差字节内子节点的位置
	 *
	 * @param dx x位移
	 * @param dy y位移
	 */
	public native void offsetBy(float dx, float dy);
	
	/**
	 * 开始fling, 如果当前正在fling，则不做任何事.
	 *
	 * @param velocityX x方向的fling速度, 如果没有设置水平平铺，则被忽略
	 * @param velocityY y方向的fling速度, 如果没有设置垂直平铺，则被忽略
	 */
	public native void fling(float velocityX, float velocityY);

	/**
	 * 中止fling，如果当前没有在fling，则不做任何事
	 */
	public native void stopFling();

	public native float getOffsetX();

	public native float getOffsetY();

	public native void setMinX(float x);

	public native void setMinY(float y);

	public native float getMinX();

	public native float getMinY();

	public native void setMaxX(float x);

	public native void setMaxY(float y);

	public native float getMaxX();

	public native float getMaxY();
}
