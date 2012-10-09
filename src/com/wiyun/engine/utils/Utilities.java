package com.wiyun.engine.utils;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;
import java.util.Random;

import android.content.Context;
import android.util.Log;

import com.wiyun.engine.WiEngine;


/**
 * Utilities class
 */
public class Utilities {
	private static final Random sRandom = new Random();
	
	/**
	 * returns a random float between -1 and 1
	 */
	public static float randMinusOneToOne() {
		return (float)Math.random() * 2.0f - 1.0f;
	}

	/**
	 * returns a random float between 0 and 1
	 */
	public static float randZeroToOne() {
		return (float)Math.random();
	}
	
	public static int rand(int max) {
		return sRandom.nextInt(max);
	}
	
	/**
	 * 把角度转换为弧度
	 * 
	 * @param angle 角度
	 * @return 弧度
	 */
	public static float d2r(float angle) {
		return (angle / 180.0f * (float)Math.PI);
	}

	/**
	 * 把弧度转换为角度
	 * 
	 * @param angle 弧度
	 * @return 角度
	 */
	public static float r2d(float angle) {
		return (angle / (float)Math.PI * 180.0f);
	}
	
	public static String getFileNameWithoutExt(String filename) {
		int index = filename.lastIndexOf('.');
		if(index != -1 && index != 0) {
			return filename.substring(0, index);
		} else {
			return filename;
		}
	}
	
	public static int getInt(int radix, String value, int faultValue) {
		if(value == null) {
			return faultValue;
		}
		
		try {
			/*
			 * Integer.parseInt("ffffffff", 16) will fail, have to use
			 * Long..., -_-
			 */
			return (int)Long.parseLong(value.trim(), radix);
		} catch(NumberFormatException e) {
			return faultValue;
		}
    }
	
	public static int getInt(int radix, String value) {
		return getInt(radix, value, 0);
    }
	
	public static int getInt(String value, int faultValue) {
		return getInt(10, value, faultValue);
	}
	
	public static float getFloat(String value) {
		if(value == null)
			return 0f;
		
		try {
	        return Float.parseFloat(value.trim());
        } catch (NumberFormatException e) {
	        return 0f;
        }
	}
	
	public static float getFloat(String value, float fault) {
		if(value == null)
			return fault;
		
		try {
			return Float.parseFloat(value.trim());
		} catch (NumberFormatException e) {
			return fault;
		}
	}
	
	/**
	 * <p>Parse int value from string</p>
	 * 
	 * @param value string 
	 * @return int value
	 */
	public static int getInt(String value) {
		return getInt(10, value);
	}
	
	public static long getLong(String value) {
		if(value == null)
			return 0L;
		
		try {
	        return Long.parseLong(value.trim());
        } catch (NumberFormatException e) {
        	return 0L;
        }
	}
	
	/**
	 * <p>Get string in UTF-8 encoding</p>
	 * 
	 * @param b byte array
	 * @return string in utf-8 encoding, or empty if the byte array is not encoded
	 * 		with UTF-8
	 */
	public static String getUTF8String(byte[] b) {
		if(b == null)
			return "";
		return getUTF8String(b, 0, b.length);
	}
	
	/**
	 * <p>Get string in UTF-8 encoding</p>
	 */
	public static String getUTF8String(byte[] b, int start, int length) {
		if(b == null) {
			return "";
		} else {
			try {
				return new String(b, start, length, "UTF-8");
			} catch(UnsupportedEncodingException e) {
				return "";
			}
		}
	}
	
	/**
	 * Get a number which is power of 2 and closest to specified number
	 */
	public static int getNextPOT(int x) {
		x = x - 1;
		x = x | (x >> 1);
		x = x | (x >> 2);
		x = x | (x >> 4);
		x = x | (x >> 8);
		x = x | (x >> 16);
		return x + 1;
	}
	
	/**
	 * 交换浮点数组中两个字节的位置
	 * 
	 * @param v 浮点数组 
	 * @param index1 位置1
	 * @param index2 位置2
	 */
	public static void swap(float[] v, int index1, int index2) {
		float tmp = v[index1];
		v[index1] = v[index2];
		v[index2] = tmp;
	}
	
	public static byte[] dataOfFile(File file) {
		InputStream in = null;
		byte[] bytes = null;
		
		try {
			// open the file
			in = new FileInputStream(file);

			// read the file
			byte[] buf = new byte[1024];
			ByteArrayOutputStream out = new ByteArrayOutputStream();
			for(int i = 0; i != -1; i = in.read(buf)) {
				out.write(buf, 0, i);
			}

			// convert to byte array
			bytes = out.toByteArray();

			// close stream
			out.flush();
			out.close();
		} catch(Throwable e) {
		} finally {
			try {
				if(in != null) {
					in.close();
				}
			} catch(IOException e) {
			}
		}
		return bytes;
	}
	
	/**
	 * 获得某个资源的数据，以字节数组形式
	 * 
	 * @param context {@link android.content.Context}
	 * @param id 资源id
	 * @return 资源的字节数组数据
	 */
	public static byte[] dataOfRawResource(Context context, int id) {
		InputStream in = null;
		byte[] bytes = null;
		try {
			// open the file
			in = context.getResources().openRawResource(id);

			// read the file
			byte[] buf = new byte[1024];
			ByteArrayOutputStream out = new ByteArrayOutputStream();
			for(int i = 0; i != -1; i = in.read(buf)) {
				out.write(buf, 0, i);
			}

			// convert to byte array
			bytes = out.toByteArray();

			// close stream
			out.flush();
			out.close();
		} catch(Throwable e) {
			Log.e(WiEngine.LOG, "Can't read the raw resource: " + id);
		} finally {
			try {
				if(in != null) {
					in.close();
				}
			} catch(IOException e) {
			}
		}
		return bytes;
	}
	
	/**
	 * 载入一个png文件，得到这个png文件的RGBA8888数据，得到的数据遵循当前适配模式的缩放规则。
	 * 
	 * @param resId png文件的资源id
	 * @return {@link BitmapRawData}
	 */
	public static BitmapRawData loadPNG(int resId) {
		BitmapRawData data = new BitmapRawData();
		nativeLoadPNG(resId, data);
		return data;
	}
	
	private static native void nativeLoadPNG(int resId, BitmapRawData data);
	
	/**
	 * 载入一个png文件，得到这个png文件的RGBA8888数据，得到的数据遵循当前适配模式的缩放规则。
	 * 
	 * @param path png文件的路径
	 * @param isFile true表示path是一个文件系统路径，false表示是一个assets路径
	 * @return {@link BitmapRawData}
	 */
	public static BitmapRawData loadPNG(String path, boolean isFile) {
		BitmapRawData data = new BitmapRawData();
		nativeLoadPNG(path, isFile, data);
		return data;
	}
	
	private static native void nativeLoadPNG(String path, boolean isFile, BitmapRawData data);
	
	/**
	 * 载入一个jpg文件，得到这个jpg文件的RGBA8888数据，得到的数据遵循当前适配模式的缩放规则。
	 * 
	 * @param resId jpg文件的资源id
	 * @return {@link BitmapRawData}
	 */
	public static BitmapRawData loadJPG(int resId) {
		BitmapRawData data = new BitmapRawData();
		nativeLoadJPG(resId, data);
		return data;
	}
	
	private static native void nativeLoadJPG(int resId, BitmapRawData data);
	
	/**
	 * 载入一个jpg文件，得到这个jpg文件的RGBA8888数据，得到的数据遵循当前适配模式的缩放规则。
	 * 
	 * @param path jpg文件的路径
	 * @param isFile true表示path是一个文件系统路径，false表示是一个assets路径
	 * @return {@link BitmapRawData}
	 */
	public static BitmapRawData loadJPG(String path, boolean isFile) {
		BitmapRawData data = new BitmapRawData();
		nativeLoadJPG(path, isFile, data);
		return data;
	}
	
	private static native void nativeLoadJPG(String path, boolean isFile, BitmapRawData data);
}