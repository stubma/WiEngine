package com.wiyun.engine.utils;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.IntBuffer;

/**
 * <p>用来表示一个图片的raw数据, 数据的格式是RGBA8888, 通过{@link Utilities}的
 * 方法可以载入某个png或者jpg图片的数据. 大部分情况这么做并无意义, 可能只在你需要
 * 针对图片像素做一些逻辑操作时才有用. 注意这个返回的只是图片数据, 不是OpenGL贴图
 * 中的数据, 修改里面的内容并不会导致贴图变化. 另外在不需要使用时要调用destroy方法
 * 销毁资源.</p><br>
 */
public class BitmapRawData {
	/**
	 * 图片的像素宽度
	 */
	public int width;
	
	/**
	 * 图片的像素高度
	 */
	public int height;
	
	/**
	 * 图片数据, 从上面的行开始, 每四个字节为一个像素, RGBA8888格式, 
	 * 这个数组的长度应该等于width * height * 4
	 */
	public byte[] data;
	
	/**
	 * 销毁资源, 释放内存
	 */
	public void destroy() {
		data = null;
	}
	
	/**
	 * 把图片的原始数据包装成一个整数型缓冲区, 这样可以用整数操作像素, 一个像素是一个
	 * int. 如果你觉得用int操作像素方便些, 可以使用这个方法
	 * 
	 * @return {@link IntBuffer}对象
	 */
	public IntBuffer asIntBuffer() {
		ByteBuffer bb = ByteBuffer.wrap(data);
		bb.order(ByteOrder.BIG_ENDIAN);
		return bb.asIntBuffer();
	}
}
