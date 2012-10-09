package com.wiyun.engine.utils;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import android.util.Log;

import com.wiyun.engine.WiEngine;

/**
 * <p>用于模拟Objective C的target-selector机制，但是在selector的书写上和Objective C有一些不同。
 * selector对方法的可见性不做指定，必须都是public方法才可以。书写的方式很简单，基本只要去掉参数名称，
 * 只写参数类型即可。在WiEngine中，只有通过Scheduler调用的方法才要求第一个参数必须是float，其他情况下
 * 任意参数即可。</p>
 * 
 * <p>
 * 下面是一些例子:
 * <ul>
 * <li>public void test(): 写成selector是"test"</li>
 * <li>public void test(int a, String b): 写成selector是"test(int,String)"</li>
 * <li>public void test(int a, String b, Object... c): 写成selector是"test(int,String,Object...)"</li>
 * <li>public void test(int a, String b, Date c): 写成selector是"test(int,String,java.util.Date)"，即对于非String类和原生类型封装类，需要写类全名</li>
 * </ul>
 * </p> 
 */
public class TargetSelector {
	private Object mTarget;
	private String mSelector;
	private Method mMethod;
	private Object[] mArgs;
	private boolean isClass;
	
	/**
	 * 构造一个TargetSelector实例
	 * 
	 * @param target 方法所属的目标对象实例
	 * @param selector 方法选择子
	 * @param args 方法的参数，如果没有参数，传null
	 */
	public TargetSelector(Object target, String selector, Object[] args) {
		mTarget = target;
		mSelector = selector;
		mArgs = args;
		isClass = mTarget instanceof Class;
		
		resolve();
	}
	
	private void resolve() {
		if(mTarget == null || mSelector == null)
			return;
		
		// 找括号
		int index = mSelector.indexOf('(');
		if(index == -1) {
			try {
				Class<?> cls = isClass ? (Class<?>)mTarget : mTarget.getClass();
				mMethod = cls.getMethod(mSelector);
			} catch(Exception e) {
				Log.w(WiEngine.LOG, "unable to find method: " + mSelector);
			}
		} else {
			// collect argument classes
			String argStr = mSelector.substring(index + 1, mSelector.length() - 1);
			String[] arguments = argStr.split(",");
			Class<?>[] argClasses = new Class[arguments.length];
			for(int i = 0; i < arguments.length; i++) {
				String a = arguments[i].trim();
				boolean isVar = a.endsWith("...");
				if(isVar)
					a = a.substring(0, a.length() - 3);
				
				// find class
				if(isVar) {
					if("int".equals(a))
						argClasses[i] = int[].class;
					else if("char".equals(a))
						argClasses[i] = char[].class;
					else if("boolean".equals(a))
						argClasses[i] = boolean[].class;
					else if("long".equals(a))
						argClasses[i] = long[].class;
					else if("float".equals(a))
						argClasses[i] = float[].class;
					else if("double".equals(a))
						argClasses[i] = double[].class;
					else if("byte".equals(a))
						argClasses[i] = byte[].class;
					else if("short".equals(a))
						argClasses[i] = short[].class;
					else if("Integer".equals(a))
						argClasses[i] = Integer[].class;
					else if("Short".equals(a))
						argClasses[i] = Short[].class;
					else if("Float".equals(a))
						argClasses[i] = Float[].class;
					else if("Double".equals(a))
						argClasses[i] = Double[].class;
					else if("Byte".equals(a))
						argClasses[i] = Byte[].class;
					else if("Long".equals(a))
						argClasses[i] = Long[].class;
					else if("Void".equals(a))
						argClasses[i] = Void[].class;
					else if("String".equals(a))
						argClasses[i] = String[].class;
					else if("Object".equals(a))
						argClasses[i] = Object[].class;
					else {
						String aArray = a + "[]";
						try {
							argClasses[i] = Class.forName(aArray);
						} catch(ClassNotFoundException e) {
							// force end
							throw new IllegalArgumentException("Illegel selector, can't find class for name: " + aArray);
						}
					}
				} else {
					if("int".equals(a))
						argClasses[i] = int.class;
					else if("char".equals(a))
						argClasses[i] = char.class;
					else if("boolean".equals(a))
						argClasses[i] = boolean.class;
					else if("long".equals(a))
						argClasses[i] = long.class;
					else if("float".equals(a))
						argClasses[i] = float.class;
					else if("double".equals(a))
						argClasses[i] = double.class;
					else if("byte".equals(a))
						argClasses[i] = byte.class;
					else if("short".equals(a))
						argClasses[i] = short.class;
					else if("void".equals(a))
						argClasses[i] = void.class;
					else if("Integer".equals(a))
						argClasses[i] = Integer.TYPE;
					else if("Short".equals(a))
						argClasses[i] = Short.TYPE;
					else if("Float".equals(a))
						argClasses[i] = Float.TYPE;
					else if("Double".equals(a))
						argClasses[i] = Double.TYPE;
					else if("Byte".equals(a))
						argClasses[i] = Byte.TYPE;
					else if("Long".equals(a))
						argClasses[i] = Long.TYPE;
					else if("Void".equals(a))
						argClasses[i] = Void.TYPE;
					else if("String".equals(a))
						argClasses[i] = String.class;
					else if("Object".equals(a))
						argClasses[i] = Object.class;
					else {
						try {
							argClasses[i] = Class.forName(a);
						} catch(ClassNotFoundException e) {
							// force end
							throw new IllegalArgumentException("Illegel selector, can't find class for name: " + a);
						}
					}
				}
			}
			
			// get method
			try {
				String func = mSelector.substring(0, index);
				Class<?> cls = isClass ? (Class<?>)mTarget : mTarget.getClass();
				mMethod = cls.getMethod(func, argClasses);
			} catch(Exception e) {
				Log.w(WiEngine.LOG, "unable to find method: " + mSelector);
			}
		}
	}
	
	/**
	 * 调用该TargetSelector指定的方法
	 */
	public void invoke() {
		if(mMethod != null) {
			try {
				if(isClass)
					mMethod.invoke(null, mArgs);
				else
					mMethod.invoke(mTarget, mArgs);
			} catch(InvocationTargetException e) {
				// throw the exception if underlying method has error
				Throwable cause = e.getCause();
				if(cause != null)
					throw new RuntimeException(cause);
			} catch(Exception e) {
				Log.w(WiEngine.LOG, e.toString());
			}
		}
	}
	
	/**
	 * 在指定的索引位置插入一个参数
	 * 
	 * @param index 索引位置，可以从0到现在的参数个数，如果超出范围则不做任何事
	 * @param type 参数类型字符串
	 * @param arg 参数对象
	 */
	public void insertArgument(int index, String type, Object arg) {
		if(index < 0 && index > mArgs.length) 
			return;
			
		// insert object
		if(mArgs == null) {
			mArgs = new Object[] {
					arg
			};
		} else {
			Object[] tmp = new Object[mArgs.length + 1];
			for(int i = 0; i < index; i++)
				tmp[i] = mArgs[i];
			tmp[index] = arg;
			for(int i = index + 1; i < tmp.length; i++) {
				tmp[i] = mArgs[i - 1];
			}
			mArgs = tmp;
		}
		
		// insert to selector
		int p = mSelector.indexOf('(');
		if(p == -1) {
			StringBuilder buf = new StringBuilder(mSelector);
			buf.append('(').append(type).append(')');
			mSelector = buf.toString();
		} else {
			// find insertion point
			while(index-- > 0) {
				p = mSelector.indexOf(',', p);
			}
			
			// rebuild selector string
			StringBuilder buf = new StringBuilder();
			buf.append(mSelector, 0, p + 1);
			buf.append(type).append(mSelector, p + 1, mSelector.length());
			mSelector = buf.toString();
		}
		
		// reflect
		resolve();
	}
	
	/**
	 * 替换一个参数
	 * 
	 * @param index 参数的索引，不能超出参数数据的范围，如果超出，则该方法无效果
	 * @param arg 新的参数对象
	 */
	public void setArgument(int index, Object arg) {
		if(mArgs != null) {
			if(index >= 0 && index < mArgs.length) {
				mArgs[index] = arg;
			}
		}
	}
	
	/**
	 * 替换一个参数，这个方法由内部调用，主要是为了方便jni层设置delta参数, delta参数必须是第一个
	 * 
	 * @param arg 新的浮点参数对象
	 */
	void setDelta(float arg) {
		if(mArgs != null && mArgs.length > 0) {
			mArgs[0] = Float.valueOf(arg);
		} else {
			Log.w(WiEngine.LOG, "TargetSelector doesn't have arguments, can't set first argument as delta");
		}
	}
	
	/**
	 * 设置一个新的选择子
	 * 
	 * @param selector 方法选择子
	 */
	public void setSelector(String selector) {
		mSelector = selector;
		resolve();
	}
	
	/**
	 * 设置一个新的Target对象
	 * 
	 * @param target 方法所属的目标对象
	 */
	public void setTarget(Object target) {
		mTarget = target;
		resolve();
	}

	/**
	 * 得到这个选择子绑定的目标对象
	 * 
	 * @return 方法所属的目标对象
	 */
	public Object getTarget() {
		return mTarget;
	}

	/**
	 * 得到selector字符串
	 * 
	 * @return 方法的selector字符串
	 */
	public String getSelector() {
		return mSelector;
	}

	/**
	 * 得到目前的参数列表
	 * 
	 * @return 参数对象数组
	 */
	public Object[] getArguments() {
		return mArgs;
	}
	
	@Override
	public String toString() {
		return (isClass ? ((Class<?>)mTarget).getName() : mTarget.getClass().getName()) + '.' + mSelector;
	}
	
	@Override
	public int hashCode() {
		return toString().hashCode();
	}
	
	@Override
	public boolean equals(Object o) {
		if(o instanceof TargetSelector) {
			return toString().equals(o.toString());
		} else {
			return false;
		}
	}
}
