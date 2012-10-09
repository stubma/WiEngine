package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor4B;

/**
 * 等宽条状带，它渲染一个连续的，等宽的条。
 */
public class StripRibbon extends Ribbon {
    /**
	 * 静态构造函数
	 *
	 * @param tex 贴图\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param color 贴图渲染颜色
	 * @param fade 淡出时间, 传入0表示不淡出一直保持，直到用reset清除
	 */
	public static StripRibbon make(Texture2D tex, WYColor4B color, float fade) {
		return new StripRibbon(tex, color, fade);
	}
	
    public static StripRibbon from(int pointer) {
    	return pointer == 0 ? null : new StripRibbon(pointer);
    }
    
    protected StripRibbon(int pointer) {
    	super(pointer);
    }
    
    protected StripRibbon(Texture2D tex, WYColor4B color, float fade) {
    	nativeInit(tex, color, fade);
    }

	private native void nativeInit(Texture2D tex, WYColor4B color, float fade);
}
