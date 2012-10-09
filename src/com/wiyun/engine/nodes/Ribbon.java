package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYBlendFunc;
import com.wiyun.engine.types.WYPoint;

/**
 * <p>Ribbon是一个动态多边形列表，在渲染时通过一系列三角形绘制出来，形成一个带状的效果。Ribbon
 * 主要的用途是和\link MotionStreak MotionStreak\endlink结合使用用来显示动作轨迹。Ribbon
 * 只是一个抽象的接口定义，每个子类都可能有不同的渲染效果. \link MotionStreak MotionStreak\endlink
 * 中定义了setStyle方法可以让您设置不同的轨迹样式，\link MotionStreak MotionStreak\endlink会根据
 * 轨迹样式使用不同的Ribbon子类</p>
 */
public class Ribbon extends Node {
    /**
     * 从底层指针获得一个Ribbon的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Ribbon}
     */
    public static Ribbon from(int pointer) {
    	return pointer == 0 ? null : new Ribbon(pointer);
    }
    
    protected Ribbon(int pointer) {
    	super(pointer);
    }
    
    protected Ribbon() {
    }
    
    @Override
    protected void doNativeInit() {
    }
    
    /**
     * 强制指定下一个新端点会产生一个新的RibbonSegment
     */
    public native void forceFirstPoint();

    /**
     * 添加一个新端点
     * 
     * @param location 新端点的位置
     */
    public native void addPoint(WYPoint location);

	/**
     * 被Scheduler调用的方法，不要手动调用
     */
    public native void update(float delta);

    public Texture2D getTexture() {
        return Texture2D.from(nativeGetTexture());
    }
    
    private native int nativeGetTexture();
    public native void setTexture(Texture2D texture);
    
    public WYBlendFunc getBlendFunc() {
    	return new WYBlendFunc(getBlendFuncSrc(), getBlendFuncDst());
    }
    
    private native int getBlendFuncSrc();
    private native int getBlendFuncDst();
    
    public void setBlendFunc(WYBlendFunc blendFunc) {
    	setBlendFunc(blendFunc.src, blendFunc.dst);
    }
    
    private native void setBlendFunc(int src, int dst);
	
	/**
	 * 重置ribbon，清除当前的点，擦除所有绘制内容
	 */
	public native void reset();
}
