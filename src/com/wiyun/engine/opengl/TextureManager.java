package com.wiyun.engine.opengl;

import com.wiyun.engine.BaseWYObject;


/**
 * 贴图管理器，负责管理WiEngine中所有贴图的缓冲，以及释放，重新载入等逻辑。 
 */
public class TextureManager extends BaseWYObject {
	// singleton
	private static TextureManager sInstance;
	
	/**
	 * 贴图格式: RGBA8888
	 */
	public static final int TEXTURE_PIXEL_FORMAT_RGBA8888 = 0;
	
	/**
	 * 贴图格式: RGB565
	 */
	public static final int TEXTURE_PIXEL_FORMAT_RGB565 = 1;
	
	/**
	 * 贴图格式: RGBA4444
	 */
	public static final int TEXTURE_PIXEL_FORMAT_RGBA4444 = 2;
	
	/**
	 * 贴图格式: RGBA5551
	 */
	public static final int TEXTURE_PIXEL_FORMAT_RGBA5551 = 3;
	
	/**
	 * 贴图格式: A8
	 */
	public static final int TEXTURE_PIXEL_FORMAT_A8 = 4;

	/**
	 * 单例模式
	 * 
	 * @return 单例实例
	 */
	public static TextureManager getInstance() {
		synchronized(TextureManager.class) {
			if(sInstance == null) {
				sInstance = new TextureManager();
			} else {
				sInstance.setPointer(nativeGetInstance());
			}
			return sInstance;
		}
	}

	/**
	 * private constructor for singleton pattern
	 */
	private TextureManager() {
		nativeInit();
	}
	
	private native static int nativeGetInstance();
	
	private native void nativeInit();

	/**
	 * \if English
	 * Get currently cached texture count
	 *
	 * @return total number of cached texture
	 * \else
	 * 得到当前缓存的贴图数量
	 *
	 * @return 当前缓存的贴图数量
	 * \endif
	 */
	public native int getTextureCount();
	
	/**
	 * 这会导致所有的OpenGL贴图立刻全部被释放. 但是如果某个贴图在之后又被
	 * 访问了, 则贴图会被重新载入. 
	 */
	public native void removeAllTextures();

	/**
	 * 根据资源id删除一个关联的OpenGL贴图, 这个方法调用后, OpenGL的贴图被立刻释放.
	 * 如果在删除之后这个贴图又被某处访问, 则这个贴图将被重新载入.
	 *
	 * @param resId 图片的资源id
	 */
	public native void removeTexture(int resId);

	/**
	 * 根据名称删除一个关联的OpenGL贴图, 这个方法调用后, OpenGL的贴图被立刻释放.
	 * 如果在删除之后这个贴图又被某处访问, 则这个贴图将被重新载入.
	 *
	 * @param name 图片的名称, 这个名称可以是路径名或者内存文件系统名
	 */
	public native void removeTexture(String name);
	
	/**
	 * 删除一个贴图。方法会在底层去掉这个贴图，可以指定一个标志表示是否永久删除这个贴图，所谓永久删除
	 * 是指删除这个贴图的元数据记录。
	 * 
	 * @param texture {@link Texture2D}
	 * @param permanentDelete true表示永久删除这个贴图。如果设置为true，那么其它还在引用
	 * 		这个贴图的{@link Texture2D}对象都会无法显示贴图。如果设置为false，当其它引用这个贴图
	 * 		的{@link Texture2D}对象尝试访问贴图时，由于元数据还在，所以贴图会被重新载入。
	 */
	public native void removeTexture(Texture2D texture, boolean permanentDelete);
	
	/**
	 * 设置缺省贴图格式, 后续创建的贴图将使用这个贴图格式, 除非创建贴图时指定了一个另外的贴图格式.
	 * 缺省的贴图格式是RGBA8888. 适当的使用贴图格式可以提高渲染的效率, 比如RGBA4444的贴图就比
	 * RGBA8888的贴图渲染速度快很多, 当然这是通过损失颜色精度达到的.
	 *
	 * @param pixelFormat 贴图格式
	 */
	public native void setTexturePixelFormat(int pixelFormat);
	
	/**
	 * 获得当前缺省贴图格式
	 *
	 * @return 贴图格式
	 */
	public native int getTexturePixelFormat();
}
