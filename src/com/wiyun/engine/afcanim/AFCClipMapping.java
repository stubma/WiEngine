package com.wiyun.engine.afcanim;

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;

/**
 * \if English
 * Clip mapping defines a set of rules of replacing a clip to another clip. Then
 * you can use clip mapping to change animation easily and dynamically.
 * \else
 * 分片映射的含义是把一个分片替换成其它分片, 这样可以实现所谓的换装功能.
 * \endif
 */
public class AFCClipMapping extends BaseWYObject {
	public static AFCClipMapping from(int pointer) {
		return pointer == 0 ? null : new AFCClipMapping(pointer);
	}
	
	protected AFCClipMapping() {
	}
	
	protected AFCClipMapping(int pointer) {
		super(pointer);
	}
	
	/**
	 * \if English
	 * static constructor
	 *
	 * @param tag tag of this mapping rules
	 * @return \link AFCClipMapping AFCClipMapping\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param tag 该应该规则对象的tag
	 * @return \link AFCClipMapping AFCClipMapping\endlink
	 * \endif
	 */
	public static AFCClipMapping make(int tag) {
		return new AFCClipMapping(0, tag);
	}
	
	/**
	 * \if English
	 * static constructor
	 *
	 * @param tag tag of this mapping rules
	 * @param ammId resource id of aurora module mapping file
	 * @return \link AFCClipMapping AFCClipMapping\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param tag 该映射规则对象的tag
	 * @param ammId AuroraGT导出的module mapping文件的资源id
	 * @return \link AFCClipMapping AFCClipMapping\endlink
	 * \endif
	 */
	public static AFCClipMapping makeAurora(int tag, int ammId) {
		return new AFCClipMapping(0, tag, ammId);
	}
	
	/**
	 * \if English
	 * static constructor
	 *
	 * @param tag tag of this mapping rules
	 * @param ammPath path of aurora module mapping file
	 * @param isFile true means \c ammPath is an absolute path in file system, or false means
	 * 		\c ammPath is a relative path under assets
	 * @return \link AFCClipMapping AFCClipMapping\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param tag 该映射规则对象的tag
	 * @param ammPath AuroraGT导出的module mapping文件的路径
	 * @param isFile true表示\c ammPath是一个文件系统上的绝对路径, false表示\c ammPath是相对于assets的相对路径
	 * @return \link AFCClipMapping AFCClipMapping\endlink
	 * \endif
	 */
	public static AFCClipMapping makeAurora(int tag, String ammPath, boolean isFile) {
		return new AFCClipMapping(tag, ammPath, isFile);
	}
	
	/**
	 * \if English
	 * static constructor
	 *
	 * @param tag tag of this mapping rules
	 * @param mfsName memory file name of aurora module mapping file
	 * @return \link AFCClipMapping AFCClipMapping\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param tag 该映射规则对象的tag
	 * @param mfsName AuroraGT导出的module mapping的内存文件名
	 * @return \link AFCClipMapping AFCClipMapping\endlink
	 * \endif
	 */
	public static AFCClipMapping makeMemoryAurora(int tag, String mfsName) {
		return new AFCClipMapping(tag, mfsName);
	}
	
	protected AFCClipMapping(int dummy, int tag) {
		nativeInit(tag);
	}
	
	protected AFCClipMapping(int dummy, int tag, int ammId) {
		nativeInit(tag, ammId);
	}
	
	public AFCClipMapping(int tag, String ammPath, boolean isFile) {
		nativeInit(tag, ammPath, isFile);
	}
	
	public AFCClipMapping(int tag, String mfsName) {
		nativeInit(tag, mfsName);
	}

	private native void nativeInit(int tag, String mfsName);
	private native void nativeInit(int tag, String ammPath, boolean isFile);
	private native void nativeInit(int tag, int ammId);
	private native void nativeInit(int tag);
	
	/**
	 * \if English
	 * Map a clip to another clip. Source and dest clip are all in same sheet
	 *
	 * @param fromClipIndex source clip index
	 * @param toClipIndex dest clip index
	 * \else
	 * 映射分片到另一个分片, 两个分片必须是属于同一个图片集的
	 *
	 * @param fromClipIndex 被映射的分片索引
	 * @param toClipIndex 映射到的分片索引
	 * \endif
	 */
	public native void mapClip(int fromClipIndex, int toClipIndex);

	/**
	 * \if English
	 * Map a clip to another clip. Source and dest clip are all in different file data
	 *
	 * @param fromClipIndex source clip index
	 * @param externalFileDataId data id of dest clip file data
	 * @param toClipIndex dest clip index
	 * \else
	 * 映射分片到另一个分片, 两个分片不属于同一个文件数据
	 *
	 * @param fromClipIndex 被映射的分片索引
	 * @param externalFileDataId 包含目标分片的文件数据id
	 * @param toClipIndex 映射到的分片索引
	 * \endif
	 */
	public native void mapClip(int fromClipIndex, int externalFileDataId, int toClipIndex);

	/**
	 * \if English
	 * Map a clip to external atlas texture
	 *
	 * @param fromClipIndex source clip index
	 * @param tex external texture
	 * @param pos clip center position, default is zero
	 * @param texRect texture rect in atlas, default is zero which means use whole texture
	 * @param flipX flip clip in x axis or not
	 * @param rotation clip rotation degree, positive value means clockwise
	 * \else
	 * 映射一个分片到外部的图片集上
	 *
	 * @param fromClipIndex 被映射的分片索引
	 * @param tex 图片集的贴图对象
	 * @param pos 分片中心位置, 缺省是0
	 * @param texRect 图片集中的贴图矩形, 缺省是全0, 表示映射到整个贴图范围内
	 * @param flipX 是否让分片在x轴翻转
	 * @param rotation 分片的旋转角度, 正值表示
	 * \endif
	 */
	public native void mapClip(int fromClipIndex, Texture2D tex, WYPoint pos, WYRect texRect, boolean flipX, float rotation);
	
	/**
	 * \if English
	 * Map a clip to external atlas texture
	 *
	 * @param fromClipIndex source clip index
	 * @param tex external texture
	 * @param pos clip center position, default is zero
	 * @param texRect texture rect in atlas, default is zero which means use whole texture
	 * \else
	 * 映射一个分片到外部的图片集上
	 *
	 * @param fromClipIndex 被映射的分片索引
	 * @param tex 图片集的贴图对象
	 * @param pos 分片中心位置, 缺省是0
	 * @param texRect 图片集中的贴图矩形, 缺省是全0, 表示映射到整个贴图范围内
	 * \endif
	 */
	public void mapClip(int fromClipIndex, Texture2D tex, WYPoint pos, WYRect texRect) {
		mapClip(fromClipIndex, tex, pos, texRect, false, 0);
	}
	
	/**
	 * \if English
	 * Map a clip to external atlas texture
	 *
	 * @param fromClipIndex source clip index
	 * @param tex external texture
	 * @param pos clip center position, default is zero
	 * \else
	 * 映射一个分片到外部的图片集上
	 *
	 * @param fromClipIndex 被映射的分片索引
	 * @param tex 图片集的贴图对象
	 * @param pos 分片中心位置, 缺省是0
	 * \endif
	 */
	public void mapClip(int fromClipIndex, Texture2D tex, WYPoint pos) {
		mapClip(fromClipIndex, tex, pos, WYRect.make(0, 0, tex.getWidth(), tex.getHeight()));
	}
	
	/**
	 * \if English
	 * Map a clip to external atlas texture
	 *
	 * @param fromClipIndex source clip index
	 * @param tex external texture
	 * \else
	 * 映射一个分片到外部的图片集上
	 *
	 * @param fromClipIndex 被映射的分片索引
	 * @param tex 图片集的贴图对象
	 * \endif
	 */
	public void mapClip(int fromClipIndex, Texture2D tex) {
		mapClip(fromClipIndex, tex, WYPoint.makeZero());
	}

	/**
	 * \if English
	 * Get tag
	 *
	 * @return tag
	 * \else
	 * 得到tag
	 *
	 * @return 标签
	 * \endif
	 */
	public native int getTag();
}
