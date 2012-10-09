package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.utils.TargetSelector;

/**
 * 图片集文字菜单。这种菜单显示文字内容，但是文字的样式是来自某图片集，因此可以用这种菜单
 * 实现各种字体的样式。 从文字到图片的映射是通过<code>startCharMap</code>指定的，比如
 * 菜单文字内容是"again", <code>startCharMap</code>是'a', 图片集横向和纵向都包含3个图
 * 片， 那么字符g和a的差是6，字符g将会映射到第三行第一列的图片。因为 6 / 3 = 2, 6 % 3 = 0。
 */
public class MenuItemAtlasLabel extends MenuItem {
    /**
     * 创建图片集文字菜单
     * 
     * @param value 文字内容
     * @param texture {@link Texture2D}
     * @param map {@link CharMap}
     * @return 菜单项实例
     */
    public static MenuItemAtlasLabel make(String value, Texture2D texture, CharMap map) {
        AtlasLabel label = (AtlasLabel)AtlasLabel.make(value, texture, map).autoRelease();
    	return new MenuItemAtlasLabel(label, null, null);
    }

    /**
     * 创建图片集文字菜单
     * 
     * @param value 文字内容
     * @param texture {@link Texture2D}
     * @param map {@link CharMap}
     * @param target 回调函数所属对象
     * @param selector 回调函数名称，必须是public，且无参数
     * @return 菜单项实例
     */
    public static MenuItemAtlasLabel make(String value, Texture2D texture, CharMap map, Node target, String selector) {
    	return make(value, texture, map, new TargetSelector(target, selector, null));
    }
    
    /**
     * 创建图片集文字菜单
     * 
     * @param value 文字内容
     * @param texture {@link Texture2D}
     * @param map {@link CharMap}
     * @param selector {@link TargetSelector}，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     * @return 菜单项实例
     */
    public static MenuItemAtlasLabel make(String value, Texture2D texture, CharMap map, TargetSelector selector) {
    	AtlasLabel label = (AtlasLabel)AtlasLabel.make(value, texture, map).autoRelease();
    	return new MenuItemAtlasLabel(label, null, selector);
    }
    
    /**
     * 创建图片集文字菜单
     * 
     * @param value 文字内容
     * @param texture {@link Texture2D}
     * @param map {@link CharMap}
     * @param downSelector {@link TargetSelector}对象，将在ACTION_DOWN发生时被调用。回调方法必须是public方法，参数不限。
     * @param upSelector {@link TargetSelector}对象，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     * @return 菜单项实例
     */
    public static MenuItemAtlasLabel make(String value, Texture2D texture, CharMap map, TargetSelector downSelector, TargetSelector upSelector) {
    	AtlasLabel label = (AtlasLabel)AtlasLabel.make(value, texture, map).autoRelease();
    	return new MenuItemAtlasLabel(label, downSelector, upSelector);
    }
    
    /**
     * 创建图片集文字菜单
     * 
     * @param label {@link AtlasLabel}
     * @param downSelector {@link TargetSelector}对象，将在ACTION_DOWN发生时被调用。回调方法必须是public方法，参数不限。
     * @param upSelector {@link TargetSelector}对象，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     * @return 菜单项实例
     */
    public static MenuItemAtlasLabel make(AtlasLabel label, TargetSelector downSelector, TargetSelector upSelector) {
    	return new MenuItemAtlasLabel(label, downSelector, upSelector);
    }

    /**
     * 构造函数
     * 
     * @param label {@link AtlasLabel}
     * @param downSelector {@link TargetSelector}对象，将在ACTION_DOWN发生时被调用。回调方法必须是public方法，参数不限。
     * @param upSelector {@link TargetSelector}对象，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     */
    protected MenuItemAtlasLabel(AtlasLabel label, TargetSelector downSelector, TargetSelector upSelector) {
    	nativeInit(downSelector, upSelector, label);
    }
    
    /**
     * 从底层指针获得一个MenuItemAtlasLabel的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link MenuItemAtlasLabel}
     */
    public static MenuItemAtlasLabel from(int pointer) {
    	return pointer == 0 ? null : new MenuItemAtlasLabel(pointer);
    }
    
    protected MenuItemAtlasLabel(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(TargetSelector downSelector, TargetSelector upSelector, AtlasLabel label);
    
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
     * 获得禁止状态时的文字颜色
     * 
     * @return {@link WYColor3B}
     */
    public WYColor3B getDisabledColor() {
		WYColor3B color = new WYColor3B();
		nativeGetDisabledColor(color);
		return color;
    }
    
    private native void nativeGetDisabledColor(WYColor3B color);
    private native void nativeSetDisabledColor(int r, int g, int b);

    /**
     * 设置禁止状态时的文字颜色
     * 
     * @param color {@link WYColor3B}
     */
    public void setDisabledColor(WYColor3B color) {
    	nativeSetDisabledColor(color.r, color.g, color.b);
    }
}
