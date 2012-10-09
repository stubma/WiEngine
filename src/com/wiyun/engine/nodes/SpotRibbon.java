package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor4B;

/**
 * 绘制一个不连续的点状带。这里说的点其实就是一个完整的贴图，并不是指一个像素点。这个渲染
 * 的效果类似于愤怒小鸟中的那种轨迹效果。
 */
public class SpotRibbon extends Ribbon {
    /**
	 * 静态构造函数
	 *
	 * @param tex 贴图\link Texture2D Texture2D对象指针\endlink
	 * @param color 贴图渲染颜色
	 * @param fade 淡出时间, 传入0表示不淡出一直保持，直到用reset清除
	 */
	public static SpotRibbon make(Texture2D tex, WYColor4B color, float fade) {
		return new SpotRibbon(tex, color, fade);
	}
	
    public static SpotRibbon from(int pointer) {
    	return pointer == 0 ? null : new SpotRibbon(pointer);
    }
    
    protected SpotRibbon(int pointer) {
    	super(pointer);
    }
    
    protected SpotRibbon(Texture2D tex, WYColor4B color, float fade) {
    	nativeInit(tex, color, fade);
    }

	private native void nativeInit(Texture2D tex, WYColor4B color, float fade);
	
	/**
	 * 设置渲染间隔，仅用于非连续渲染模式
	 *
	 * @param d 贴图渲染之间的间隔
	 */
	public native void setDistance(float d);

	/**
	 * 得到渲染间隔，仅用于非连续渲染模式
	 *
	 * @return 渲染间隔
	 */
	public native float getDistance();
}
