package com.wiyun.engine.lua;


/**
 * WiEngine的Lua封装类, 这个类封装了一个lua_State实例. 当然你也可以直接lua的
 * api. Lua提供了较为简单的接口, 封装了lua的常用操作.<br>
 *
 * 如果使用Lua执行lua脚本, WiEngine的所有API都可以从lua中访问. 如果您自己创建
 * lua_State, 则只要调用Lua的init方法对state初始化后就可以访问WiEngine的API.<br>
 *
 * 使用Lua之前必须调用Lua::init方法, 不再使用时必须调用Lua::destroy方法.
 */
public class Lua {
	/**
	 * 初始化Lua. 使用Lua之前必须调用此方法. 该方法会进行有效性检查, 因此
	 * 多次调用是安全的.
	 */
	public native static void init();

	/**
	 * 释放Lua维护的单一lua_State实例, 程序退出之前必须调用此方法. 该方法会进行有效性检查, 因此
	 * 多次调用是安全的.
	 */
	public native static void destroy();

	/**
	 * 执行一个lua脚本
	 *
	 * @param resId lua脚本的资源id
	 */
	public native static void execute(int resId);

	/**
	 * 执行一个lua脚本
	 *
	 * @param path lua脚本的路径
	 * @param isFile true表示path是一个文件系统路径, false表示path是一个assets下的相对路径
	 */
	public native static void execute(String path, boolean isFile);

	/**
	 * 执行一个lua脚本
	 *
	 * @param s 已经被载入内存的lua脚本的c字符串, 调用者要负责释放指针
	 */
	public native static void execute(String s);

	/**
	 * 设置一个全局对象, 完成后可以在lua脚本中可以访问这个对象
	 *
	 * @param name 全局对象名
	 * @param obj 对象
	 * @param type 对象类型, 可以为null, 如果为null, 则对象会被注册成light userdata, 否则会注册
	 * 		为tolua usertype
	 */
	public native static void setGlobal(String name, Object obj, String type);
	
	/**
	 * 设置一个全局用户数据对象, 完成后可以在lua脚本中使用这个对象. 这个全局
	 * 对象在lua层是一个light userdata, 不是tolua的usertype. lua层不会保持
	 * 这个java对象的引用, 因为调用者要保证对象在lua运行期间不会被释放.
	 * 
	 * @param name 全局对象名
	 * @param obj 对象指针
	 */
	public static void setGlobal(String name, Object obj) {
		setGlobal(name, obj, null);
	}
	
	/**
	 * 设置一个全局整数参数
	 *
	 * @param name 参数名称
	 * @param value 参数值
	 */
	public native static void setGlobal(String name, int value);

	/**
	 * 设置一个全局浮点参数
	 *
	 * @param name 参数名称
	 * @param value 参数值
	 */
	public native static void setGlobal(String name, float value);
	
	/**
	 * 设置一个全局字符串参数
	 *
	 * @param name 参数名称
	 * @param value 字符串, lua底层会拷贝一份, 所以该方法返回后该字符串可以被释放掉.
	 */
	public native static void setGlobal(String name, String value);
	
	/**
	 * 获得一个全局对象
	 *
	 * @param name 参数名称
	 * @return 底层对象的指针
	 */
	public native static int getGlobalObject(String name);

	/**
	 * 获得一个全局整数参数
	 *
	 * @param name 参数名称
	 * @param def 如果不存在这个参数或者其它原因导致失败, 返回这个缺省值, 缺省值是-1
	 * @return 整数值, 如果失败返回传入的缺省值
	 */
	public native static int getGlobalInt(String name, int def);
	
	/**
	 * 获得一个全局整数参数
	 *
	 * @param name 参数名称
	 * @return 整数值, 如果失败则返回-1
	 */
	public static int getGlobalInt(String name) {
		return getGlobalInt(name, -1);
	}
	
	/**
	 * 获得一个全局浮点参数
	 *
	 * @param name 参数名称
	 * @param def 如果不存在这个参数或者其它原因导致失败, 返回这个缺省值, 缺省值是0
	 * @return 整数值, 如果失败返回传入的缺省值
	 */
	public native static float getGlobalFloat(String name, float def);
	
	/**
	 * 获得一个全局浮点参数
	 *
	 * @param name 参数名称
	 * @return 整数值, 如果失败返回0
	 */
	public static float getGlobalFloat(String name) {
		return getGlobalFloat(name, 0);
	}

	/**
	 * 获得一个全局字符串参数
	 *
	 * @param name 参数名称
	 * @return 字符串, 调用者要负责释放字符串内存. 如果失败, 返回NULL
	 */
	public native static String getGlobalString(String name);
}
