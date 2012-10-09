package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYColor4B;

/**
 * 绘制一个连续的，不等宽的条状带，头部还带有箭头效果。其效果类似于水果忍者
 * 中的刀痕，因此叫做blade ribbon
 */
public class BladeRibbon extends Ribbon {
    /**
	 * 静态构造函数
	 *
	 * @param tex 贴图\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param color 贴图渲染颜色
	 * @param fade 这里的fade时间对blade ribbon来说有不同的意义，它的实际意思是每个点存活的时间，而不是淡出。
	 * 		blade ribbon本身不进行淡出操作，但是路径上的点会根据这个fade时间逐渐消失。
	 */
	public static BladeRibbon make(Texture2D tex, WYColor4B color, float fade) {
		return new BladeRibbon(tex, color, fade);
	}
	
    public static BladeRibbon from(int pointer) {
    	return pointer == 0 ? null : new BladeRibbon(pointer);
    }
    
    protected BladeRibbon(int pointer) {
    	super(pointer);
    }
    
    protected BladeRibbon(Texture2D tex, WYColor4B color, float fade) {
    	nativeInit(tex, color, fade);
    }

	private native void nativeInit(Texture2D tex, WYColor4B color, float fade);
	
	/**
	 * 设置最大点数限制, 缺省是50个. 最大点数会影响轨迹的长度，允许的最大点数越多，
	 * 轨迹也就拖的越长
	 *
	 * @param max 最大点数限制
	 */
	public native void setMaxPointCount(int max);

	/**
	 * 得到最大点数限制
	 *
	 * @return 最大点数限制
	 */
	public native int getMaxPointCount();
	
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
}
