package com.wiyun.engine.nodes;

import android.graphics.Typeface;

import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.utils.TargetSelector;

/**
 * 文字式菜单。指定一个字符串，根据该字符串生成菜单项，可以指定字体名称和字体大小。 
 */
public class MenuItemLabel extends MenuItem {
    /**
     * 创建文字菜单, 使用缺省字体和大小。 
     * 
     * @param value 菜单文字内容 
     * @return 菜单项实例
     */
    public static MenuItemLabel make(String value) {
        return new MenuItemLabel((Label)Label.make(value, DEFAULT_FONT_SIZE).autoRelease(), null, null);
    }
    
    /**
     * 创建文字菜单，使用自定义字体和大小。
     * 
     * @param value 菜单文字内容 
     * @param fontName 字体名称
     * @param fontSize 字体大小，单位是SP
     * @return 菜单项实例
     */
    public static MenuItemLabel make(String value, String fontName, float fontSize) {
    	return new MenuItemLabel((Label)Label.make(value, fontSize, Typeface.NORMAL, fontName).autoRelease(), null, null);
    }
    
    /**
     * 创建文字菜单, 使用缺省字体和大小。 
     * 
     * @param value 菜单文字内容 
     * @param target 回调函数所属对象
     * @param selector 回调函数名称，必须是public，且无参数
     * @return 菜单项实例
     */
    public static MenuItemLabel make(String value, Node target, String selector) {
        return make(value, new TargetSelector(target, selector, null));
    }
    
    /**
     * 创建文字菜单, 使用缺省字体和大小。 
     * 
     * @param value 菜单文字内容 
     * @param selector {@link TargetSelector}，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     * @return 菜单项实例
     */
    public static MenuItemLabel make(String value, TargetSelector selector) {
    	return new MenuItemLabel(
    			(Label)Label.make(value, DEFAULT_FONT_SIZE).autoRelease(), 
    			null, 
    			selector);
    }
    
    /**
     * 创建文字菜单, 使用缺省字体和大小。 
     * 
     * @param value 菜单文字内容 
     * @param downSelector {@link TargetSelector}对象，将在ACTION_DOWN发生时被调用。回调方法必须是public方法，参数不限。
     * @param upSelector {@link TargetSelector}对象，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     * @return 菜单项实例
     */
    public static MenuItemLabel make(String value, TargetSelector downSelector, TargetSelector upSelector) {
    	return new MenuItemLabel(
    			(Label)Label.make(value, DEFAULT_FONT_SIZE).autoRelease(), 
    			downSelector, 
    			upSelector);
    }
    
    /**
     * 创建文字菜单，使用自定义字体和大小。
     * 
     * @param value 菜单文字内容 
     * @param fontName 字体名称
     * @param fontSize 字体大小，单位是SP
     * @param target 回调函数所属对象
     * @param selector 回调函数名称，必须是public，且无参数
     * @return 菜单项实例
     */
    public static MenuItemLabel make(String value, String fontName, float fontSize, Node target, String selector) {
    	return make(value, fontName, fontSize, new TargetSelector(target, selector, null));
    }
    
    /**
     * 创建文字菜单，使用自定义字体和大小。
     * 
     * @param value 菜单文字内容 
     * @param fontName 字体名称
     * @param fontSize 字体大小，单位是SP
     * @param selector {@link TargetSelector}，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     * @return 菜单项实例
     */
    public static MenuItemLabel make(String value, String fontName, float fontSize, TargetSelector selector) {
    	return new MenuItemLabel(
    			(Label)Label.make(value, fontSize, Typeface.NORMAL, fontName).autoRelease(), 
    			null,
    			selector);
    }
    
    /**
     * 创建文字菜单，使用自定义字体和大小。
     * 
     * @param value 菜单文字内容 
     * @param fontName 字体名称
     * @param fontSize 字体大小，单位是SP
     * @param downSelector {@link TargetSelector}对象，将在ACTION_DOWN发生时被调用。回调方法必须是public方法，参数不限。
     * @param upSelector {@link TargetSelector}对象，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     * @return 菜单项实例
     */
    public static MenuItemLabel make(String value, String fontName, float fontSize, TargetSelector downSelector, TargetSelector upSelector) {
    	return new MenuItemLabel(
    			(Label)Label.make(value, fontSize, Typeface.NORMAL, fontName).autoRelease(), 
    			downSelector, 
    			upSelector);
    }
    
    /**
     * 创建文字菜单
     * 
     * @param label 一个实现了{@link Node.ILabel}接口的节点对象
     * @param target 回调函数所属对象
     * @param selector 回调函数名称，必须是public，且无参数
     * @return 菜单项实例
     */
    public static MenuItemLabel make(Node label, Node target, String selector) {
        return make(label, new TargetSelector(target, selector, null));
    }
    
    /**
     * 创建文字菜单
     * 
     * @param label 一个实现了{@link Node.ILabel}接口的节点对象
     * @param selector {@link TargetSelector}，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     * @return 菜单项实例
     */
    public static MenuItemLabel make(Node label, TargetSelector selector) {
    	return new MenuItemLabel(label, null, selector);
    }
    
    /**
     * 创建文字菜单
     * 
     * @param label 一个实现了{@link Node.ILabel}接口的节点对象
     * @param downSelector {@link TargetSelector}对象，将在ACTION_DOWN发生时被调用。回调方法必须是public方法，参数不限。
     * @param upSelector {@link TargetSelector}对象，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     * @return 菜单项实例
     */
    public static MenuItemLabel make(Node label, TargetSelector downSelector, TargetSelector upSelector) {
    	return new MenuItemLabel(label, downSelector, upSelector);
    }

    /**
     * 构造函数
     * 
     * @param label 一个实现了{@link Node.ILabel}接口的节点对象
     * @param downSelector {@link TargetSelector}对象，将在ACTION_DOWN发生时被调用。回调方法必须是public方法，参数不限。
     * @param upSelector {@link TargetSelector}对象，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     */
    protected MenuItemLabel(Node label, TargetSelector downSelector, TargetSelector upSelector) {
    	nativeInit(downSelector, upSelector, label);
    }
    
    /**
     * 从底层指针获得一个MenuItemLabel的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link MenuItemLabel}
     */
    public static MenuItemLabel from(int pointer) {
    	return pointer == 0 ? null : new MenuItemLabel(pointer);
    }
    
    protected MenuItemLabel(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(TargetSelector downSelector, TargetSelector upSelector, Node label);

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
