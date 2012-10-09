package com.wiyun.engine.utils;

import java.lang.reflect.Field;
import java.lang.reflect.Method;

import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.hardware.Camera;
import android.os.Build;

import com.wiyun.engine.nodes.Director;

/**
 * \if English
 * helper class to provide Android image picking functionality. Image
 * can be picked from camera, or album, in RGBA8888 format. \link wyTexture2D wyTexture2D\endlink
 * can generate texture from the returned raw data.
 * \else
 * 工具类，用来封装Android平台的选择图片接口。图片可以从摄像头或相册中选取，返回
 * RGBA8888的图片数据，\link wyTexture2D wyTexture2D\endlink有makeRaw方法
 * 可以直接从RGBA8888数据中生成贴图
 * \endif
 */
class ImagePicker {
	// native callback and data
	static int sCallback;
	static int sData;
	
	/**
	 * 设备是否有摄像头
	 *
	 * @return true表示设备至少有一个摄像头
	 */
	public static boolean hasCamera() {
		if(Build.VERSION.SDK_INT > 8) {
			return hasSystemFeature(FEATURE_CAMERA());
		} else {
			Camera camera = null;
			try {
				camera = Camera.open();
				return camera != null;
			} catch (Exception e) {
				return false;
			} finally {
				// close camera if opened
				try {
					if(camera != null) {
						camera.release();
						camera = null;
					}
				} catch (Exception e) {
				}
			}
		}
	}
	
	/**
	 * 设备是否有前置摄像头
	 *
	 * @return true表示设备有前置摄像头
	 */
	public static boolean hasFrontCamera() {
		if(Build.VERSION.SDK_INT > 8) {
			return hasSystemFeature(FEATURE_CAMERA_FRONT());
		} else {
			return false;
		}
	}
	
	private static boolean hasSystemFeature(String feature) {
		try {
			Context context = Director.getInstance().getContext();
			if(context == null)
				return false;
			PackageManager pm = context.getPackageManager();
			Method m = PackageManager.class.getMethod("hasSystemFeature", new Class[] { String.class });
			return (Boolean)m.invoke(pm, new Object[] { feature });
		} catch (Exception e) {
			return false;
		}
	}
	
	private static String FEATURE_CAMERA() {
		try {
			Field f = PackageManager.class.getField("FEATURE_CAMERA");
			return (String)f.get(null);
		} catch (Exception e) {
			return "";
		}
	}
	
	private static String FEATURE_CAMERA_FRONT() {
		try {
			Field f = PackageManager.class.getField("FEATURE_CAMERA_FRONT");
			return (String)f.get(null);
		} catch (Exception e) {
			return "";
		}
	}
	
	/**
	 * 从摄像头拍摄一个照片并返回, 照片将以RGBA8888格式的数据返回. 可以指定一个期望的大小，
	 * 如果照片的实际大小不合，则会在返回时进行缩放. 如果设备没有摄像头，则不做任何事.
	 *
	 * @param callback 事件回调
	 * @param data 额外数据指针，会在回调中传回，可以为NULL
	 * @param w 期望返回的照片宽度
	 * @param h 期望返回的照片高度
	 * @param keepRatio true表示在缩放时保持图片宽高比例，false表示不保持
	 * @param front true表示从前置摄像头中获取
	 */
	static void pickFromCamera(int callback, int data, int w, int h, boolean keepRatio, boolean front) {
		// must have context
		Context context = Director.getInstance().getContext();
		if(context == null)
			return;
		
		// save callback
		sCallback = callback;
		sData = data;
		
		// create intent
		Intent intent = new Intent(context, ImagePickerActivity.class);
		intent.putExtra(ImagePickerActivity.EXTRA_IN_FROM_CAMERA, true);
		intent.putExtra(ImagePickerActivity.EXTRA_IN_EXPECTED_WIDTH, w);
		intent.putExtra(ImagePickerActivity.EXTRA_IN_EXPECTED_HEIGHT, h);
		intent.putExtra(ImagePickerActivity.EXTRA_IN_KEEP_RATIO, keepRatio);
		intent.putExtra(ImagePickerActivity.EXTRA_IN_USE_FRONT, front);
		
		// start activity
		try {
			context.startActivity(intent);
		} catch (Exception e) {
		}
	}
	
	/**
	 * 从相册中选择一个照片并返回, 照片将以RGBA8888格式的数据返回. 可以指定一个期望的大小，
	 * 如果照片的实际大小不合，则会在返回时进行缩放.
	 *
	 * @param callback 事件回调
	 * @param data 额外数据指针，会在回调中传回，可以为NULL
	 * @param w 期望返回的照片宽度
	 * @param h 期望返回的照片高度
	 * @param keepRatio true表示在缩放时保持图片宽高比例，false表示不保持
	 */
	static void pickFromAlbum(int callback, int data, int w, int h, boolean keepRatio) {
		// must have context
		Context context = Director.getInstance().getContext();
		if(context == null)
			return;
		
		// save callback
		sCallback = callback;
		sData = data;
		
		// create intent
		Intent intent = new Intent(context, ImagePickerActivity.class);
		intent.putExtra(ImagePickerActivity.EXTRA_IN_FROM_CAMERA, false);
		intent.putExtra(ImagePickerActivity.EXTRA_IN_EXPECTED_WIDTH, w);
		intent.putExtra(ImagePickerActivity.EXTRA_IN_EXPECTED_HEIGHT, h);
		intent.putExtra(ImagePickerActivity.EXTRA_IN_KEEP_RATIO, keepRatio);
		
		// start activity
		try {
			context.startActivity(intent);
		} catch (Exception e) {
		}
	}
}