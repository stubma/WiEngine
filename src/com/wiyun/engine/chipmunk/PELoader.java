package com.wiyun.engine.chipmunk;

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.types.WYPoint;

public class PELoader extends BaseObject {
	public static PELoader from(int pointer) {
		return pointer == 0 ? null : new PELoader(pointer);
	}
	
	protected PELoader(int pointer) {
		super(pointer);
	}
	
	/**
	 * 根据文件路径加载
	 *
	 * @param filePath 工具PhysicsEditor导出文件的路径
	 * @param isFile true表示filePaht为系统路径，false表示asset路径
	 */
	public static PELoader make(String filePath, boolean isFile) {
		int pointer = nativeNewBodyLoader(filePath, isFile);
		return PELoader.from(pointer);
	}

	private static native int nativeNewBodyLoader(String filePath, boolean isFile);
	
	/**
	 * 根据资源id加载
	 *
	 * @param resId 资源id
	 */
	public static PELoader make(int resId) {
		int pointer = nativeNewBodyLoader(resId);
		return from(pointer);
	}

	private static native int nativeNewBodyLoader(int resId);

	/**
	 * 根据名字创建一个chipmunk物体
	 *
	 * @param chipmunk wyChipmunk类型的节点
	 * @param name 物体名字，不能任意指定，必须是导出文件中存在的物体名
	 */
	public Body createBodyByName(Chipmunk chipmunk, String name) {
		int pointer = nativeCreateBodyByName(chipmunk, name);
		return Body.from(pointer);
	}
	
	private native int nativeCreateBodyByName(Chipmunk chipmunk, String name);

	/**
	 * 获得name所指定的物体对应的图片的锚点
	 *
	 * @param name 物体名字，不能任意指定，必须是导出文件中存在的物体名
	 */
	public WYPoint getAnchorPercent(String name) {
		WYPoint point = WYPoint.makeZero();
		nativeGetAnchorPercent(name, point);
		return point;
	}
	
	private native void nativeGetAnchorPercent(String name, WYPoint point);

	/**
	 * 获得PhysicsEditor导出文件的格式
	 */
	public native int getPlistFormat();
	
	/**
	 * 释放底层资源
	 */
	public native void destroy();
}
