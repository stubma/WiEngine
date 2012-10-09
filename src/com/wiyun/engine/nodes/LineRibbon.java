package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYPoint;

/**
 * 线状连续图形，等宽，头尾有圆角效果
 */
public class LineRibbon extends Ribbon {
    /**
	 * 静态构造函数
	 *
	 * @param tex 贴图\link Texture2D Texture2D对象指针\endlink
	 * @param color 贴图渲染颜色
	 */
	public static LineRibbon make(Texture2D tex, WYColor4B color) {
		return new LineRibbon(tex, color);
	}
	
    public static LineRibbon from(int pointer) {
    	return pointer == 0 ? null : new LineRibbon(pointer);
    }
    
    protected LineRibbon(int pointer) {
    	super(pointer);
    }
    
    protected LineRibbon(Texture2D tex, WYColor4B color) {
    	nativeInit(tex, color);
    }

	private native void nativeInit(Texture2D tex, WYColor4B color);
	
    public Texture2D getTexture() {
        return Texture2D.from(nativeGetTexture());
    }
    
    private native int nativeGetTexture();
    public native void setTexture(Texture2D texture);
    
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
	 * 设置线宽，如果不设置，则缺省为贴图的有效高度. 该设置不影响已经存在的线. 设置之后创建的
	 * 线将变成该宽度
	 *
	 * @param width 线宽, 单位像素
	 */
	public native void setLineWidth(float width);

	/**
	 * 得到某条线的宽度
	 *
	 * @param index 线的索引
	 * @return 线的宽度, 单位像素. 如果索引不合法，返回0
	 */
	public native float getLineWidth(int index);

	/**
	 * 得到某条线的颜色
	 *
	 * @param index 线的索引
	 * @return \link WYColor4B WYColor4B\endlink
	 */
	public WYColor4B getLineColor(int index) {
		WYColor4B c = new WYColor4B();
		nativeGetLineColor(index, c);
		return c;
	}
	
	private native void nativeGetLineColor(int index, WYColor4B color);
	
	/**
	 * 得到线的个数
	 *
	 * @return 线段的个数
	 */
	public native int getLineCount();

	/**
	 * 得到某条线的点个数
	 *
	 * @param index 线的索引
	 * @return 线的点个数. 如果索引不合法，返回0
	 */
	public native int getLinePointCount(int index);

	/**
	 * 得到线的点列表
	 *
	 * @param index 线的索引
	 * @return \link WYPoint WYPoint\endlink数组，调用者不需要负责释放. 如果索引不合法，返回null
	 */
	public WYPoint[] getLinePointList(int index) {
		if(index < 0 || index >= getLineCount())
			return null;
		
		WYPoint[] list = new WYPoint[getLinePointCount(index)];
		for(int i = 0; i < list.length; i++)
			list[i] = WYPoint.makeZero();
		nativeGetLinePointList(index, list);
		return list;
	}
	
	private native void nativeGetLinePointList(int index, WYPoint[] list);
}
