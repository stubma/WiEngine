package com.wiyun.engine.opengl;

import static android.opengl.GLES10.*;

import javax.microedition.khronos.opengles.GL10;

import android.graphics.Bitmap;
import android.graphics.Bitmap.Config;
import android.graphics.Canvas;
import android.opengl.GLUtils;

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.filters.ColorFilter;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.utils.BitmapRawData;

/**
 * 2D贴图对象的代理, 可以认为这是一个贴图的句柄, 它的作用是引用一个真正的贴图.<br>
 *
 * 贴图的管理是由WiEngine自动维护的, 每当上层调用Texture2D::makeXXX时, WiEngine会
 * 首先检查这个贴图是否存在, 如果存在, 则不会创建新的贴图, 而是返回同样的句柄. 句柄其实
 * 是一个整数, 它被包装在\link Texture2D Texture2D\endlink类中. 所以\link Texture2D Texture2D\endlink
 * 的实例可能不同, 但是它们都可能拥有同样的句柄, 也就指向同样的贴图. 而当\link Texture2D Texture2D\endlink
 * 被销毁时, 通常情况下并不意味着真实的贴图也被销毁了, 因为可能还有其它\link Texture2D Texture2D\endlink
 * 实例指向了真实的贴图.<br>
 *
 * 当然您也可以通过\link TextureManager TextureManager\endlink的方法删除贴图, 但是如果
 * 删除贴图后, 这个贴图又在某个地方被访问了, 则这个贴图会被重新载入. 这是WiEngine的自动管理
 * 机制, 它一方面可以让你手动控制贴图的释放以便及时释放内存, 同时又可以按需载入贴图以保证程序正常
 * 运行.<br>
 */
public class Texture2D extends BaseWYObject {
	/**
	 * \if English
	 * Left alignment
	 * \else
	 * 文字左对齐
	 * \endif
	 */
	public static final int LEFT = 0;

	/**
	 * \if English
	 * center alignment
	 * \else
	 * 居中对齐
	 * \endif
	 */
	public static final int CENTER = 1;

	/**
	 * \if English
	 * right alignment
	 * \else
	 * 右对齐
	 * \endif
	 */
	public static final int RIGHT = 2;
	
	public static final int SOURCE_BMP = 1;
	public static final int SOURCE_JPG = 2;
	public static final int SOURCE_PNG = 3;
	public static final int SOURCE_PVR = 4;
	public static final int SOURCE_LABEL = 5;
	public static final int SOURCE_OPENGL = 6;
	public static final int SOURCE_RAW = 7;
	
	/**
	 * 从BMP文件创建贴图，BMP文件通过资源id指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param resId 资源id
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeBMP(int resId) {
		return makeBMP(resId, 0);
	}
	
	/**
	 * 从BMP文件创建贴图，BMP文件通过资源id指定, 创建的贴图格式由format参数指定.
	 *
	 * @param resId 资源id
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeBMP(int resId, int transparentColor) {
		return makeBMP(resId, transparentColor, TextureManager.getInstance().getTexturePixelFormat());
	}
	
	/**
	 * 从BMP文件创建贴图，BMP文件通过资源id指定, 创建的贴图格式由format参数指定.
	 *
	 * @param resId 资源id
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeBMP(int resId, int transparentColor, int format) {
		Texture2D tex = new Texture2D(SOURCE_BMP, resId, transparentColor, format);
		return tex;
	}
	
	/**
	 * 从BMP文件创建贴图，BMP文件通过assets路径指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param path BMP文件在assets下的路径
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeBMP(String path) {
		return makeBMP(path, 0);
	}
	
	/**
	 * 从BMP文件创建贴图，BMP文件通过assets路径指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param path BMP文件在assets下的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeBMP(String path, int transparentColor) {
		return makeBMP(path, transparentColor, TextureManager.getInstance().getTexturePixelFormat());
	}
	
	/**
	 * 从BMP文件创建贴图，BMP文件通过assets路径指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param path BMP文件在assets下的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeBMP(String path, int transparentColor, int format) {
		return makeBMP(path, transparentColor, format, Director.getDefaultInDensity());
	}
	
	/**
	 * 从BMP文件创建贴图，BMP文件通过assets路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param path BMP文件在assets下的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 缺省为0, 表示使用缺省设置，缺省设置是1，可以通过Director::setDefaultInDensity指定
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeBMP(String path, int transparentColor, int format, float inDensity) {
		Texture2D tex = new Texture2D(SOURCE_BMP, path, transparentColor, format, inDensity);
		return tex;
	}
	
	/**
	 * 从JPG文件创建贴图，JPG文件通过资源id指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param resId 资源id
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeJPG(int resId) {
		return makeJPG(resId, 0);
	}
	
	/**
	 * 从JPG文件创建贴图，JPG文件通过资源id指定, 创建的贴图格式由format参数指定.
	 *
	 * @param resId 资源id
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeJPG(int resId, int transparentColor) {
		return makeJPG(resId, transparentColor, TextureManager.getInstance().getTexturePixelFormat());
	}
	
	/**
	 * 从JPG文件创建贴图，JPG文件通过资源id指定, 创建的贴图格式由format参数指定.
	 *
	 * @param resId 资源id
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeJPG(int resId, int transparentColor, int format) {
		Texture2D tex = new Texture2D(SOURCE_JPG, resId, transparentColor, format);
		return tex;
	}
	
	/**
	 * 从JPG文件创建贴图，JPG文件通过assets路径指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param path JPG文件在assets下的路径
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeJPG(String path) {
		return makeJPG(path, 0);
	}
	
	/**
	 * 从JPG文件创建贴图，JPG文件通过assets路径指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param path JPG文件在assets下的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeJPG(String path, int transparentColor) {
		return makeJPG(path, transparentColor, TextureManager.getInstance().getTexturePixelFormat());
	}
	
	/**
	 * 从JPG文件创建贴图，JPG文件通过assets路径指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param path JPG文件在assets下的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeJPG(String path, int transparentColor, int format) {
		return makeJPG(path, transparentColor, format, Director.getDefaultInDensity());
	}
	
	/**
	 * 从JPG文件创建贴图，JPG文件通过assets路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param path JPG文件在assets下的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 缺省为0, 表示使用缺省设置，缺省设置是1，可以通过Director::setDefaultInDensity指定
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeJPG(String path, int transparentColor, int format, float inDensity) {
		Texture2D tex = new Texture2D(SOURCE_JPG, path, transparentColor, format, inDensity);
		return tex;
	}
	
	/**
	 * 通过一个{@link BitmapRawData}对象创建贴图. 通过这种方法创建的贴图最好在不用的手动删除，不然有可能
	 * 造成内存浪费
	 * 
	 * @param raw {@link BitmapRawData}
	 * @return {@link Texture2D}
	 */
	public static Texture2D make(BitmapRawData raw) {
		return make(raw, TextureManager.getInstance().getTexturePixelFormat());
	}
	
	/**
	 * \if English
	 * Create a {@link Texture2D} object from an Android bitmap. However, if you create
	 * {@link Texture2D} this way, the texture is not density awared, which means it will
	 * not be auto scaled by WiEngine. Second defect is the texture will not cached.
	 *
	 * @param b {@link Bitmap}, caller should recycle it after returns
	 * @return {@link Texture2D}
	 * \else
	 * 通过一个android的{@link Bitmap}对象创建{@link Texture2D}. 但是, 通过这种方式创建的贴图
	 * 是不会被WiEngine自动拉伸的. 其次, 通过这种方式创建的贴图不会被底层缓冲.
	 * 
	 * @param b {@link Bitmap}, 调用者需要在方法返回后自己回收该位图对象
	 * @return {@link Texture2D}
	 * \endif
	 */
	public static Texture2D make(Bitmap b) {
		// The bitmap may not POT size, so we need update it
		int w = b.getWidth();
		int h = b.getHeight();
		int potW = getNextPOT(w);
		int potH = getNextPOT(h);
		boolean notPOT = w != potW || h != potH;
		if(notPOT) {
			Bitmap newB = Bitmap.createBitmap(potW, potH, Config.ARGB_8888);
			Canvas c = new Canvas(newB);
			newB.eraseColor(0);
			c.drawBitmap(b, 0, 0, null);
			b = newB;
			c = null;
		}
		
		// generate texture
        int[] textures = new int[1];
        glGenTextures(1, textures, 0);
        glBindTexture(GL_TEXTURE_2D, textures[0]);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
        // generate texture
        GLUtils.texImage2D(GL_TEXTURE_2D, 0, b, 0);
        
        // generate texture 2d object
		Texture2D t = makeGL(textures[0], w, h);
		
		// release bitmap
		if(notPOT) {
			b.recycle();
			b = null;
		}
		
		return t;
	}
	
	/**
	 * \if English
	 * Create a {@link Texture2D} object from a OpenGL texture. However, if you create
	 * {@link Texture2D} this way, the texture is not density awared, which means it will
	 * not be auto scaled by WiEngine. Second defect is the texture will not cached.
	 * 
	 * @param tex OpenGL texture id
	 * @param w width of OpenGL texture
	 * @param h height of OpenGL texture
	 * @return {@link Texture2D}
	 * \else
	 * 通过一个OpenGL贴图id创建{@link Texture2D}. 但是, 通过这种方式创建的贴图
	 * 是不会被WiEngine自动拉伸的. 其次, 通过这种方式创建的贴图不会被底层缓冲.
	 * 
	 * @param tex OpenGL贴图id
	 * @param w OpenGL贴图的宽度
	 * @param h OpenGL贴图的高度
	 * @return {@link Texture2D}
	 * \endif
	 */
	public static Texture2D makeGL(int tex, int w, int h) {
		return new Texture2D(tex, w, h);
	}
	
	/**
	 * 通过一个{@link BitmapRawData}对象创建贴图. 通过这种方法创建的贴图最好在不用的手动删除，不然有可能
	 * 造成内存浪费
	 * 
	 * @param raw {@link BitmapRawData}
	 * @param format 期望生成的贴图格式
	 * @return {@link Texture2D}
	 */
	public static Texture2D make(BitmapRawData raw, int format) {
		Texture2D tex = new Texture2D(raw, format);
		return tex;
	}
	
	/**
	 * 从PNG文件创建贴图，PNG文件通过资源id指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param resId 资源id
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makePNG(int resId) {
		Texture2D tex = new Texture2D(SOURCE_PNG, resId, 0, TextureManager.getInstance().getTexturePixelFormat());
		return tex;
	}
	
	/**
	 * 从PNG文件创建贴图，PNG文件通过资源id指定, 创建的贴图格式由format参数指定.
	 *
	 * @param resId 资源id
	 * @param format 贴图格式
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makePNG(int resId, int format) {
		Texture2D tex = new Texture2D(SOURCE_PNG, resId, 0, format);
		return tex;
	}
	
	/**
	 * 从PNG文件创建贴图，PNG文件通过assets路径指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param path PNG文件在assets下的路径
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makePNG(String path) {
		return makePNG(path, Director.getDefaultInDensity());
	}
	
	/**
	 * 从PNG文件创建贴图，PNG文件通过assets路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param path PNG文件在assets下的路径
	 * @param format 贴图格式
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makePNG(String path, int format) {
		return makePNG(path, format, Director.getDefaultInDensity());
	}
	
	/**
	 * 从PNG文件创建贴图，PNG文件通过assets路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param path PNG文件在assets下的路径
	 * @param inDensity 图片的density, 缺省为0, 表示使用缺省设置，缺省设置是1，可以通过Director::setDefaultInDensity指定
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makePNG(String path, float inDensity) {
		Texture2D tex = new Texture2D(SOURCE_PNG, path, 0, TextureManager.getInstance().getTexturePixelFormat(), inDensity);
		return tex;
	}
	
	/**
	 * 从PNG文件创建贴图，PNG文件通过assets路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param path PNG文件在assets下的路径
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 缺省为0, 表示使用缺省设置，缺省设置是1，可以通过Director::setDefaultInDensity指定
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makePNG(String path, int format, float inDensity) {
		Texture2D tex = new Texture2D(SOURCE_PNG, path, 0, format, inDensity);
		return tex;
	}
	
	/**
	 * 从PNG文件创建贴图，PNG文件通过文件系统路径指定, 创建的贴图格式由当前缺省贴图格式确定
	 *
	 * @param path PNG文件在文件系统中的路径
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeFilePNG(String path) {
		return makeFilePNG(path, Director.getDefaultInDensity());
	}
	
	/**
	 * 从PNG文件创建贴图，PNG文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param path PNG文件在文件系统中的路径
	 * @param format 贴图格式
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeFilePNG(String path, int format) {
		return makeFilePNG(path, format, Director.getDefaultInDensity());
	}
	
	/**
	 * 从PNG文件创建贴图，PNG文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param path PNG文件在文件系统中的路径
	 * @param inDensity 图片的density, 缺省为0, 表示使用缺省设置，缺省设置是1，可以通过Director::setDefaultInDensity指定
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeFilePNG(String path, float inDensity) {
		Texture2D tex = new Texture2D(0, SOURCE_PNG, path, 0, TextureManager.getInstance().getTexturePixelFormat(), inDensity);
		return tex;
	}
	
	/**
	 * 从PNG文件创建贴图，PNG文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param path PNG文件在文件系统中的路径
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 缺省为0, 表示使用缺省设置，缺省设置是1，可以通过Director::setDefaultInDensity指定
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeFilePNG(String path, int format, float inDensity) {
		Texture2D tex = new Texture2D(0, SOURCE_PNG, path, 0, format, inDensity);
		return tex;
	}
	
	/**
	 * 从BMP文件创建贴图，BMP文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param path BMP文件在文件系统中的路径
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeFileBMP(String path) {
		return makeFileBMP(path, 0);
	}
	
	/**
	 * 从BMP文件创建贴图，BMP文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param path BMP文件在文件系统中的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeFileBMP(String path, int transparentColor) {
		return makeFileBMP(path, transparentColor, TextureManager.getInstance().getTexturePixelFormat());
	}
	
	/**
	 * 从BMP文件创建贴图，BMP文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param path BMP文件在文件系统中的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeFileBMP(String path, int transparentColor, int format) {
		return makeFileBMP(path, transparentColor, format, Director.getDefaultInDensity());
	}
	
	/**
	 * 从BMP文件创建贴图，BMP文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param path BMP文件在文件系统中的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 缺省为0, 表示使用缺省设置，缺省设置是1，可以通过Director::setDefaultInDensity指定
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeFileBMP(String path, int transparentColor, int format, float inDensity) {
		Texture2D tex = new Texture2D(0, SOURCE_BMP, path, transparentColor, format, inDensity);
		return tex;
	}
	
	/**
	 * 从JPG文件创建贴图，JPG文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param path JPG文件在文件系统中的路径
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeFileJPG(String path) {
		return makeFileJPG(path, 0);
	}
	
	/**
	 * 从JPG文件创建贴图，JPG文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param path JPG文件在文件系统中的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeFileJPG(String path, int transparentColor) {
		return makeFileJPG(path, transparentColor, TextureManager.getInstance().getTexturePixelFormat());
	}
	
	/**
	 * 从JPG文件创建贴图，JPG文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param path JPG文件在文件系统中的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeFileJPG(String path, int transparentColor, int format) {
		return makeFileJPG(path, transparentColor, format, Director.getDefaultInDensity());
	}
	
	/**
	 * 从JPG文件创建贴图，JPG文件通过文件系统路径指定, 创建的贴图格式由format参数指定.
	 *
	 * @param path JPG文件在文件系统中的路径
	 * @param transparentColor 透明色, 格式为0xaarrggbb, 但是检查时会忽略alpha字段, 只要
	 * 		匹配rgb值的地方都会被设置为透明
	 * @param format 贴图格式
	 * @param inDensity 图片的density, 缺省为0, 表示使用缺省设置，缺省设置是1，可以通过Director::setDefaultInDensity指定
	 * @return \link Texture2D Texture2D\endlink
	 */
	public static Texture2D makeFileJPG(String path, int transparentColor, int format, float inDensity) {
		Texture2D tex = new Texture2D(0, SOURCE_JPG, path, transparentColor, format, inDensity);
		return tex;
	}
	
	/**
	 * 创建一个贴图代理对象
	 * 
	 * @param path pvr图片在文件系统中的路径
	 * @return {@link Texture2D}，如果打开文件失败，则返回null
	 */
	public static Texture2D makeFilePVR(String path) {
		return makeFilePVR(path, Director.getDefaultInDensity());
	}
	
	/**
	 * 创建一个贴图代理对象
	 * 
	 * @param path pvr图片在文件系统中的路径
	 * @param inDensity 
	 * 				得到图片的缺省density, 如果不设置, 缺省值是1.0f, 也就是把缺省图片做为
	 * 				mdpi处理
	 * @return {@link Texture2D}，如果打开文件失败，则返回null
	 */
	public static Texture2D makeFilePVR(String path, float inDensity) {
		Texture2D tex = new Texture2D(0, SOURCE_PVR, path, 0, TextureManager.getInstance().getTexturePixelFormat(), inDensity);
		return tex;
	}
	
	/**
	 * 从PVR文件创建一个Texture2D对象。Texture2D不能被直接创建，必须通过TextureManager创建
	 * 
	 * @param resId
	 *            PVR文件的资源id
	 * @return {@link Texture2D}
	 */
	public static Texture2D makePVR(int resId) {
		Texture2D tex = new Texture2D(SOURCE_PVR, resId, 0, TextureManager.getInstance().getTexturePixelFormat());
		return tex;
	}
	
	/**
	 * 创建一个贴图代理对象
	 * 
	 * @param path PVR文件在assets目录下的路径
	 * @return {@link Texture2D}
	 */
	public static Texture2D makePVR(String path) {
		return makePVR(path, Director.getDefaultInDensity());
	}
	
	/**
	 * 创建一个贴图代理对象
	 * 
	 * @param path PVR文件在assets目录下的路径
	 * @param inDensity 
	 * 				得到图片的缺省density, 如果不设置, 缺省值是1.0f, 也就是把缺省图片做为
	 * 				mdpi处理
	 * @return {@link Texture2D}
	 */
	public static Texture2D makePVR(String path, float inDensity) {
		Texture2D tex = new Texture2D(SOURCE_PVR, path, 0, TextureManager.getInstance().getTexturePixelFormat(), inDensity);
		return tex;
	}

	/**
	 * 创建一个贴图代理对象
	 * 
	 * @param text 文字
	 * @param fontSize 字体大小，单位是像素
	 * @param fontPath 自定义字体文件的路径
	 * @param isFile true表示\c fontPath是一个文件系统的绝对路径, false表示\c fontPath是一个assets下的相对路径
	 * @param width 字符串最大宽度，超过这个宽度将折行
	 * @param alignment 文字对齐方式
	 * @return {@link Texture2D}
	 * @see Texture2D::LEFT
	 * @see Texture2D::CENTER
	 * @see Texture2D::RIGHT
	 */
	public static Texture2D make(String text, float fontSize, String fontPath, boolean isFile, float width, int alignment) {
		Texture2D tex = new Texture2D(text, fontSize, fontPath, isFile, width, alignment);
		return tex;
	}
	
	/**
	 * 创建一个贴图代理对象
	 * 
	 * @param text 文字
	 * @param fontSize 字体大小，单位是像素
	 * @param style 字体样式，定义在{@link android.graphics.Typeface}中
	 * @param fontName 字体名称，为null表示缺省字体
	 * @param width 字符串最大宽度，超过这个宽度将折行
	 * @param alignment 文字对齐方式
	 * @return {@link Texture2D}
	 * @see Texture2D::LEFT
	 * @see Texture2D::CENTER
	 * @see Texture2D::RIGHT
	 */
	public static Texture2D make(String text, float fontSize, int style, String fontName, float width, int alignment) {
		Texture2D tex = new Texture2D(text, fontSize, style, fontName, width, alignment);
		return tex;
	}

	private native int nativeNew(BitmapRawData raw, int pixelFormat);
	private native int nativeNew(int tex, int w, int h);
	private native int nativeNew(int source, int resId, int transparentColor, int pixelFormat);
	private native int nativeNew(int source, String path, int transparentColor, int pixelFormat, float inDensity);
	private native int nativeNew(String text, float fontSize, String fontPath, boolean isFile, float width, int alignment);
	private native int nativeNew(String text, float fontSize, int style, String fontName, float width, int alignment);
	private native int nativeNewFile(int source, String path, int transparentColor, int pixelFormat, float inDensity);

	/**
	 * 设置贴图的反锯齿效果，缺省情况下是true
	 * 
	 * @param flag true表示反锯齿，false表示不反锯齿
	 */
	public native void setAntiAlias(boolean flag);
	
	/**
	 * 设置贴图渲染时是否平铺。只能设置都平铺或者都不平铺，如果想要针对不同的方向做不同的设置，
	 * 请使用setTexParameters方法。缺省情况下是true。
	 * 
	 * @param flag true表示在水平和垂直方向都平铺，false表示都不平铺
	 */
	public native void setRepeat(boolean flag);
	
	/**
	 * 设置贴图参数，这是更为高级的设置方法，对于比较熟悉OpenGL贴图原理的开发者，可以直接使用
	 * 这个方法。对于不太熟悉的开发者，建议使用setAntiAlias和setRepeat这样的方法。
	 * 
	 * @param min 缩小操作参数
	 * @param mag 放大操作参数
	 * @param wrapS 水平翻卷参数
	 * @param wrapT 垂直翻卷参数
	 */
	public native void setTexParameters(int min, int mag, int wrapS, int wrapT);

	/**
	 * 构造函数
	 * 
	 * @param raw {@link BitmapRawData}
	 * @param pixelFormat 贴图格式
	 */
	Texture2D(BitmapRawData raw, int pixelFormat) {
		mPointer = nativeNew(raw, pixelFormat);
	}
	
	Texture2D(int source, int resId, int transparentColor, int pixelFormat) {
		mPointer = nativeNew(source, resId, transparentColor, pixelFormat);
	}
	
	Texture2D(int source, String path, int transparentColor, int pixelFormat, float inDensity) {
		mPointer = nativeNew(source, path, transparentColor, pixelFormat, inDensity);
	}
	
	Texture2D(int dummy, int source, String path, int transparentColor, int pixelFormat, float inDensity) {
		mPointer = nativeNewFile(source, path, transparentColor, pixelFormat, inDensity);
	}

	Texture2D(String text, float fontSize, String fontPath, boolean isFile, float width, int alignment) {
		mPointer = nativeNew(text, fontSize, fontPath, isFile, width, alignment);
	}
	
	Texture2D(String text, float fontSize, int style, String fontName, float width, int alignment) {
		mPointer = nativeNew(text, fontSize, style, fontName, width, alignment);
	}
	
	public static Texture2D from(int pointer) {
		return pointer == 0 ? null : new Texture2D(pointer);
	}
	
	/**
	 * for internal use, wrap an underlying pointer
	 */
	protected Texture2D(int pointer) {
		super(pointer);
	}
	
	protected Texture2D(int tex, int w, int h) {
		mPointer = nativeNew(tex, w, h);
	}

	/**
	 * 在OpenGL中设置贴图参数
	 */
	public native void applyTexParameters();

	/**
	 * 在指定位置绘制贴图
	 * 
	 * @param gl {@link GL10}
	 * @param point
	 *            指定位置，相对于当前的坐标系
	 */
	public void drawAtPoint(GL10 gl, WYPoint point) {
		drawAtPoint(gl, point.x, point.y);
	}
	
	/**
	 * 在指定位置绘制贴图
	 * 
	 * @param gl {@link GL10}
	 * @param x x位置
	 * @param y y位置
	 */
	public void drawAtPoint(GL10 gl, float x, float y) {
		nativeDrawAtPoint(x, y);
	}
	
	/**
	 * 在指定位置绘制贴图
	 * 
	 * @param x x位置
	 * @param y y位置
	 */
	private native void nativeDrawAtPoint(float x, float y);

	/**
	 * 在指定位置绘制贴图
	 * 
	 * @param gl {@link GL10}
	 * @param point
	 *            指定位置，相对于当前的坐标系
	 * @param flipX
	 *            true表示渲染时要在x方向翻转图片
	 * @param flipY
	 *            true表示渲染时要在y方向翻转图片
	 */
	public void drawAtPoint(GL10 gl, WYPoint point, boolean flipX, boolean flipY) {
		drawAtPoint(gl, point.x, point.y, flipX, flipY);
	}
	
	/**
	 * 在指定位置绘制贴图
	 * 
	 * @param gl {@link GL10}
	 * @param x x位置
	 * @param y y位置
	 * @param flipX
	 *            true表示渲染时要在x方向翻转图片
	 * @param flipY
	 *            true表示渲染时要在y方向翻转图片
	 */
	public void drawAtPoint(GL10 gl, float x, float y, boolean flipX, boolean flipY) {
		nativeDrawAtPoint(x, y, flipX, flipY);
	}
	
	/**
	 * 底层绘制方法
	 * 
	 * @param x x位置
	 * @param y y位置
	 * @param flipX
	 *            true表示渲染时要在x方向翻转图片
	 * @param flipY
	 *            true表示渲染时要在y方向翻转图片
	 */
	private native void nativeDrawAtPoint(float x, float y, boolean flipX, boolean flipY);

	/**
	 * 得到原始图片的高度
	 */
	public native float getHeight();

	/**
	 * 得到原始图片的宽度
	 */
	public native float getWidth();

	/**
	 * 贴图是否是pre-multiplied alpha的。 注意：目前生成的贴图都不是pre-multiplied
	 * alpha的，因此总是返回false
	 * 
	 * @return true表示是，false表示不是
	 */
	public boolean hasPremultipliedAlpha() {
		// TODO: Implement me
		return false;
	}

	/**
	 * 确保贴图对象已经被载入，这个方法将把贴图对应的图象资源转换成OpenGL中的贴图对象
	 */
	public native void loadTexture();
	
	/**
	 * 得到原始图片和贴图实际大小的宽度比例
	 * 
	 * @return 宽度比例
	 */
	public native float getWidthScale();
	
	/**
	 * 得到原始图片和贴图实际大小的高度比例
	 * 
	 * @return 高度比例
	 */
	public native float getHeightScale();
	
	/**
	 * 得到贴图实际高度
	 */
	public native int getPixelHeight();

	/**
	 * 得到贴图实际宽度
	 */
	public native int getPixelWidth(); 
	
	/**
	 * 得到是否渲染的时候要反向x轴
	 * 
	 * @return true表示渲染时要在x方向翻转图片
	 */
	public native boolean isFlipX();

	/**
	 * 是否渲染的时候要反向x轴
	 * 
	 * @param flipX true表示渲染时要在x方向翻转图片
	 */
	public native void setFlipX(boolean flipX);

	/**
	 * 得到是否渲染的时候要反向y轴
	 * 
	 * @return true表示渲染时要在y方向翻转图片
	 */
	public native boolean isFlipY();

	/**
	 * 是否渲染的时候要反向y轴
	 * 
	 * @param flipY true表示渲染时要在y方向翻转图片
	 */
	public native void setFlipY(boolean flipY);
	
	/**
	 * 通过原始像素数据更新贴图内容
	 *
	 * @param raw {@link BitmapRawData}
	 */
	public native void updateRaw(BitmapRawData raw);
	
	/**
	 * \if English
	 * set color filter. texture has many sources and it doesn't support label or opengl or pvr source. color filter
	 * won't be called when set until you call \c applyFilter. However, \c applyFilter will be automatically
	 * called when texture is loading.
	 *
	 * @param filter subclass of \link ColorFilter ColorFilter\endlink, or NULL if you want to
	 * 		remove filter
	 * \else
	 * 设置颜色过滤器, 贴图本身有一个来源标示其类型, 对于标签或opengl或pvr来源的贴图暂时不支持颜色过滤器. 在调用\c setColorFilter
	 * 的时候, 过滤器并不会立刻起作用. 想要过滤器发生效果需要调用\c applyFilter. 但是如果贴图正在被载入, 则\c applyFilter
	 * 会被自动调用.
	 *
	 * @param filter \link ColorFilter ColorFilter\endlink的子类, 或者NULL表示删除当前的过滤器
	 * \endif
	 */
	public native void setColorFilter(ColorFilter filter);

	/**
	 * \if English
	 * if current color filter is not NULL, apply this filter to texture. that will cause
	 * texture changed immediately.
	 * \else
	 * 如果当前的颜色过滤器不为空, 则应用这个过滤器, 这会导致OpenGL贴图立刻发生变化
	 * \endif
	 */
	public native void applyFilter();
	
	/**
	 * \if English
	 * Clone a texture. After returns, this object will point to a new OpenGL texture
	 * object. Every cloned texture should have a clone id to unique identify itself.
	 * If current proxy already points a cloned texture, then source texture will be cloned
	 *
	 * @param cloneId clone id
	 * @param proxy of cloned texture, NULL if clone is failed
	 * \else
	 * 克隆该贴图. 方法返回后, 该对象会指向一个新的OpenGL贴图对象. 每个克隆的贴图都有一个克隆id来
	 * 进行唯一的标识. 如果当前的贴图代理指向的已经是一个克隆贴图, 则该方法会克隆源贴图.
	 *
	 * @param cloneId 克隆id
	 * @return 克隆贴图代理对象, 如果克隆失败, 返回NULL
	 * \endif
	 */
	public Texture2D clone(int cloneId) {
		int pointer = nativeClone(cloneId);
		return Texture2D.from(pointer);
	}
	
	private native int nativeClone(int cloneId);

	/**
	 * \if English
	 * Change this proxy texture to a cloned texture proxy. Cloned texture proxy can
	 * not be created directly so you should call this method to switch a proxy to a
	 * cloned proxy. If clone id not found, do nothing
	 *
	 * @param cloneId clone id
	 * @return true means ok, false means there is no clone which has that id
	 * \else
	 * 把当前的贴图代理对象定位到某个克隆贴图对象上. 这是因为克隆贴图代理不能直接被创建, 只能先
	 * 创建原始贴图代理, 再调用这个方法重新定位. 如果指定的克隆id没有找到, 则该方法无效果
	 *
	 * @param cloneId 克隆贴图id
	 * @return true表示切换成功, false表示指定id的克隆不存在
	 * \endif
	 */
	public native boolean switchToClone(int cloneId);
	
	/**
	 * \if English
	 * Delete a cloned texture with specified id, it will immediately delete texture both
	 * in cache and in opengl.
	 *
	 * @param cloneId id of cloned texture
	 * @return true means ok, false means no clone has that id
	 * \else
	 * 删除某个克隆贴图. 该方法立刻从贴图缓冲和opengl中删除贴图资源
	 *
	 * @param cloneId 要删除的克隆贴图id
	 * @return true表示成功, false表示不存在该id的克隆
	 * \endif
	 */
	public native boolean deleteClone(int cloneId);
	
	private static int getNextPOT(int x) {
		x = x - 1;
		x = x | (x >> 1);
		x = x | (x >> 2);
		x = x | (x >> 4);
		x = x | (x >> 8);
		x = x | (x >> 16);
		return x + 1;
	}
}