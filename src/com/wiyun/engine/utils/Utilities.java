/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
package com.wiyun.engine.utils;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;
import java.nio.ByteBuffer;
import java.util.LinkedList;
import java.util.Random;

import android.content.Context;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.Bitmap.Config;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Paint.FontMetricsInt;
import android.graphics.Typeface;
import android.text.TextPaint;
import android.text.TextUtils;
import android.util.Log;

import com.wiyun.engine.WiEngine;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYSize;


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
	 * 载入一个图像文件，得到这个图像文件的RGBA8888数据，得到的数据遵循当前适配模式的缩放规则。
	 * 图像的格式引擎会自动判断. 这个方法不支持PVR图片格式
	 * 
	 * @param resId 图像文件的资源id
	 * @return {@link BitmapRawData}
	 */
	public static BitmapRawData loadImage(int resId) {
		BitmapRawData data = new BitmapRawData();
		nativeloadImage(resId, data);
		return data;
	}
	
	private static native void nativeloadImage(int resId, BitmapRawData data);
	
	/**
	 * 载入一个图像文件，得到这个图像文件的RGBA8888数据，得到的数据遵循当前适配模式的缩放规则。
	 * 图像的格式引擎会自动判断. 这个方法不支持PVR图片格式
	 * 
	 * @param path 图像文件的路径
	 * @param isFile true表示path是一个文件系统路径，false表示是一个assets路径
	 * @return {@link BitmapRawData}
	 */
	public static BitmapRawData loadImage(String path, boolean isFile) {
		BitmapRawData data = new BitmapRawData();
		nativeloadImage(path, isFile, data);
		return data;
	}
	
	private static native void nativeloadImage(String path, boolean isFile, BitmapRawData data);
	
	public static WYSize calculateTextSize(String text, float fontSize, String fontPath, boolean isFile, float w) {
		// create paint
		Paint paint = new TextPaint();
		paint.setAntiAlias(true);
		paint.setTextSize(fontSize);
		if(!TextUtils.isEmpty(fontPath)) {
			Typeface tf = null;
			if(isFile)
				tf = Typeface.createFromFile(fontPath);
			else
				tf = Typeface.createFromAsset(Director.getInstance().getContext().getAssets(), fontPath);
			paint.setTypeface(tf);
		}
		
		// break lines and total height
		String[] lines = null;
		FontMetricsInt fm = paint.getFontMetricsInt();
		int lineHeight = fm.descent - fm.ascent;
		int height = 0;
		int width = (int)w;
		if(width <= 0) {
			width = (int)paint.measureText(text);
			lines = new String[] { text };
			height = lineHeight;
		} else {
			lines = breakIntoLines(paint, text, width);
			height = lineHeight * lines.length;
		}
		
		return WYSize.make(width, height);
	}
	
	public static WYSize calculateTextSize(String text, float fontSize, int style, String fontName, float w) {
		// create paint
		Paint paint = new TextPaint();
		paint.setAntiAlias(true);
		paint.setTextSize(fontSize);
		paint.setColor(Color.WHITE);
		switch(style) {
			case Texture2D.BOLD:
				paint.setTypeface(Typeface.defaultFromStyle(Typeface.BOLD));
				break;
			case Texture2D.ITALIC:
				paint.setTypeface(Typeface.defaultFromStyle(Typeface.ITALIC));
				break;
			case Texture2D.BOLD_ITALIC:
				paint.setTypeface(Typeface.defaultFromStyle(Typeface.BOLD_ITALIC));
				break;
		}
		
		// break lines and total height
		String[] lines = null;
		FontMetricsInt fm = paint.getFontMetricsInt();
		int lineHeight = fm.descent - fm.ascent;
		int height = 0;
		int width = (int)w;
		if(width <= 0) {
			width = (int)paint.measureText(text);
			lines = new String[] { text };
			height = lineHeight;
		} else {
			lines = breakIntoLines(paint, text, width);
			height = lineHeight * lines.length;
		}
		
		return WYSize.make(width, height);
	}
	
	public static byte[] createLabelBitmap(String text, float fontSize, String fontPath, boolean isFile, float w, int alignment) {
		// create paint
		Paint paint = new TextPaint();
		paint.setAntiAlias(true);
		paint.setTextSize(fontSize);
		paint.setColor(Color.WHITE);
		if(!TextUtils.isEmpty(fontPath)) {
			Typeface tf = null;
			if(isFile)
				tf = Typeface.createFromFile(fontPath);
			else
				tf = Typeface.createFromAsset(Director.getInstance().getContext().getAssets(), fontPath);
			paint.setTypeface(tf);
		}
		
		// break lines and total height
		String[] lines = null;
		FontMetricsInt fm = paint.getFontMetricsInt();
		int lineHeight = fm.descent - fm.ascent;
		int height = 0;
		int width = (int)w;
		if(width <= 0) {
			width = (int)paint.measureText(text);
			lines = new String[] { text };
			height = lineHeight;
		} else {
			lines = breakIntoLines(paint, text, width);
			height = lineHeight * lines.length;
		}
		
		// pot size
		int potWidth = getNextPOT(width);
		int potHeight = getNextPOT(height);
		
		// create bitmap
		Bitmap bitmap = Bitmap.createBitmap(potWidth, potHeight, Bitmap.Config.ARGB_8888);
		Canvas canvas = new Canvas(bitmap);
		
		// draw
		float y = 0;
		float tw = 0;
		for(String line : lines) {
			switch(alignment) {
				case Texture2D.CENTER:
					tw = paint.measureText(line);
					canvas.drawText(line, (width - tw) / 2, y, paint);
					break;
				case Texture2D.RIGHT:
					tw = paint.measureText(line);
					canvas.drawText(line, width - tw, y, paint);
					break;
				default:
					canvas.drawText(line, 0, y - fm.ascent, paint);
					break;
			}
			y += lineHeight;
		}
		
		// to byte
		byte[] p = new byte[4 * potWidth * potHeight];
		ByteBuffer buffer = ByteBuffer.wrap(p);
		bitmap.copyPixelsToBuffer(buffer);
		
		// convert to un-premultiplied
		int index = 0;
		for(int r = 0; r < potHeight; r++) {
			for(int c = 0; c < potWidth; c++) {
				if(p[index + 3] != 0) {
					p[index] = (byte)(((p[index] & 0xff) * 255 / (p[index + 3] & 0xff)) & 0xff);
					p[index + 1] = (byte)(((p[index + 1] & 0xff) * 255 / (p[index + 3] & 0xff)) & 0xff);
					p[index + 2] = (byte)(((p[index + 2] & 0xff) * 255 / (p[index + 3] & 0xff)) & 0xff);
				}
				index += 4;
			}
		}
		
		// release bitmap
		bitmap.recycle();
		
		// return
		return p;
	}
	
	public static byte[] createLabelBitmap(String text, float fontSize, int style, String fontName, float w, int alignment) {
		// create paint
		Paint paint = new TextPaint();
		paint.setAntiAlias(true);
		paint.setTextSize(fontSize);
		paint.setColor(Color.WHITE);
		switch(style) {
			case Texture2D.BOLD:
				paint.setTypeface(Typeface.defaultFromStyle(Typeface.BOLD));
				break;
			case Texture2D.ITALIC:
				paint.setTypeface(Typeface.defaultFromStyle(Typeface.ITALIC));
				break;
			case Texture2D.BOLD_ITALIC:
				paint.setTypeface(Typeface.defaultFromStyle(Typeface.BOLD_ITALIC));
				break;
		}
		
		// break lines and total height
		String[] lines = null;
		FontMetricsInt fm = paint.getFontMetricsInt();
		int lineHeight = fm.descent - fm.ascent;
		int height = 0;
		int width = (int)w;
		if(width <= 0) {
			width = (int)paint.measureText(text);
			lines = new String[] { text };
			height = lineHeight;
		} else {
			lines = breakIntoLines(paint, text, width);
			height = lineHeight * lines.length;
		}
		
		// pot size
		int potWidth = getNextPOT(width);
		int potHeight = getNextPOT(height);
		
		// create bitmap
		Bitmap bitmap = Bitmap.createBitmap(potWidth, potHeight, Bitmap.Config.ARGB_8888);
		Canvas canvas = new Canvas(bitmap);
		
		// draw
		float y = 0;
		float tw = 0;
		for(String line : lines) {
			switch(alignment) {
				case Texture2D.CENTER:
					tw = paint.measureText(line);
					canvas.drawText(line, (width - tw) / 2, y, paint);
					break;
				case Texture2D.RIGHT:
					tw = paint.measureText(line);
					canvas.drawText(line, width - tw, y, paint);
					break;
				default:
					canvas.drawText(line, 0, y - fm.ascent, paint);
					break;
			}
			y += lineHeight;
		}
		
		// to byte
		byte[] p = new byte[4 * potWidth * potHeight];
		ByteBuffer buffer = ByteBuffer.wrap(p);
		bitmap.copyPixelsToBuffer(buffer);
		
		// convert to un-premultiplied
		int index = 0;
		for(int r = 0; r < potHeight; r++) {
			for(int c = 0; c < potWidth; c++) {
				if(p[index + 3] != 0) {
					p[index] = (byte)(((p[index] & 0xff) * 255 / (p[index + 3] & 0xff)) & 0xff);
					p[index + 1] = (byte)(((p[index + 1] & 0xff) * 255 / (p[index + 3] & 0xff)) & 0xff);
					p[index + 2] = (byte)(((p[index + 2] & 0xff) * 255 / (p[index + 3] & 0xff)) & 0xff);
				}
				index += 4;
			}
		}
		
		// release bitmap
		bitmap.recycle();
		
		// return
		return p;
	}
	
	public static byte[] scaleImage(byte[] originData, int originWidth, int originHeight, float scaleX, float scaleY) {
		int[] colors = new int[originWidth * originHeight];
		for(int i = 0; i < originData.length; i += 4) {
			int j = i / 4;
			colors[j] = ((originData[i] << 16) & 0xff0000) |
					((originData[i + 1] << 8) & 0xff00) |
					((originData[i + 2] << 0) & 0xff) |
					((originData[i + 3] << 24) & 0xff000000);
		}
		Bitmap originBitmap = Bitmap.createBitmap(colors, originWidth, originHeight, Config.ARGB_8888);
		
		int w = (int)(originWidth * scaleX + 0.5f);
		int h = (int)(originHeight * scaleY + 0.5f);
		Bitmap newBitmap = Bitmap.createScaledBitmap(originBitmap, w, h, true);
		
		// to byte
		byte[] p = new byte[4 * w * h];
		ByteBuffer buffer = ByteBuffer.wrap(p);
		newBitmap.copyPixelsToBuffer(buffer);
		
		// convert to un-premultiplied
		int index = 0;
		for(int r = 0; r < w; r++) {
			for(int c = 0; c < h; c++) {
				if(p[index + 3] != 0) {
					p[index] = (byte)(((p[index] & 0xff) * 255 / (p[index + 3] & 0xff)) & 0xff);
					p[index + 1] = (byte)(((p[index + 1] & 0xff) * 255 / (p[index + 3] & 0xff)) & 0xff);
					p[index + 2] = (byte)(((p[index + 2] & 0xff) * 255 / (p[index + 3] & 0xff)) & 0xff);
				}
				index += 4;
			}
		}
		
		// release bitmap
		newBitmap.recycle();
		originBitmap.recycle();
		
		return p;
	}
	
	private static String[] breakIntoLines(Paint paint, String string, float width) {
		String[] lines = null;

		if (string != null) {
			// A container for holding lines as we parse them.
			LinkedList<String> parsedLines = new LinkedList<String>();
			String newLine;

			// Flag indicating if the current line starts a paragraph.
			// Spaces at the beginning of a paragraph are kept for
			// indentation or labels used as spacers.
			boolean startsParagraph = true;

			// The index of the character that starts this line.
			int lineStart = 0;

			// The index of a character that may appear on the
			// next line. For example a space can appear on this
			// line or the next, but a letter in the middle of the
			// word must stay on the same line as the entire word.
			int lastBreakableSpot = 0;

			// The index of the last character that wasn't a
			// whitespace character such as ' '.
			int lastNonWhiteSpace = 0;

			// The width of a wide character used as a safety
			// margin in calculating the line width. Not all font
			// width calculations are reliable (e.g. the default
			// font on the Motorola SLVR). Adjusting the line
			// width by this amount assures no text will get clipped.
			float charWidth = paint.measureText("0");
			width -= charWidth;

			// Scan lengths character-by-character.
			char[] chars = string.toCharArray();

			for (int i = 0; i < chars.length; i++) {
				boolean isSeparator = (chars[i] == '-') || (chars[i] == '/');
				boolean isWhiteSpace = (chars[i] == ' ');

				boolean isNewLine = (chars[i] == '\n');
				boolean isCarrageReturn = (chars[i] == '\r');

				boolean isLineBreak = isNewLine || isCarrageReturn;
				float lineWidth = paint.measureText(chars, lineStart, i - lineStart);

				// Are we done with this line?
				if ((isLineBreak) || (lineWidth > width)) {
					int lineEnd;

					if (isLineBreak) {
						lineEnd = i;
					} else if (lastBreakableSpot > lineStart) {
						lineEnd = lastBreakableSpot;
					} else {
						// This word is longer than the line so do a mid-word
						// break
						// with the current letter on the next line.
						lineEnd = i - 1;
					}

					// Record the line.
					newLine = string.substring(lineStart, lineEnd);
					newLine = smartTrim(newLine, startsParagraph);
					parsedLines.add(newLine);

					// Setup for the next line.
					if (isLineBreak) {
						lineStart = lineEnd + 1; // +1 to advance over the
						// '\n'

						startsParagraph = true;
					} else {
						// line break in the middle of a paragraph
						lineStart = lineEnd;
						startsParagraph = false;
					}
				}

				// Is this a good place for a line-break?
				if (isSeparator) {
					// Put the separator char on this line (e.g. "full-").
					lastBreakableSpot = i + 1;
				}

				if (isWhiteSpace) {
					// Break at the whitespace. It will be trimmed later.
					lastBreakableSpot = lastNonWhiteSpace + 1;
				} else {
					// Record this character as the last non-whitespace
					// processed.
					lastNonWhiteSpace = i;
				}
			}

			// Add the last line.
			newLine = string.substring(lineStart);
			newLine = smartTrim(newLine, startsParagraph);
			parsedLines.add(newLine);

			// Convert the vector into a string array.
			lines = new String[parsedLines.size()];
			parsedLines.toArray(lines);
		}

		return lines;
	}
	
	private static String smartTrim(String string, boolean startsParagraph) {
		String trimmed;

		if (startsParagraph) {
			// Trim the right side of the string only.
			int len = string.length() - 1;

			while ((len >= 0) && (string.charAt(len) <= ' ')) {
				len--;
			}

			if (len <= 0) {
				// All spaces.
				trimmed = string;
			} else {
				trimmed = string.substring(0, len + 1);
			}
		} else {
			trimmed = string.trim();
		}

		return trimmed;
	}
	
	private static byte[] dataOfStream(InputStream is) {
		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		
		if(is != null) {
			try {
		        byte[] buf = new byte[4096];
		        for(int i = 0; i != -1; i = is.read(buf)) {
		        	baos.write(buf, 0, i);
		        }
	        } catch (IOException e) {
	        } finally {
	        	if(is != null) {
	        		try {
		                is.close();
	                } catch (IOException e) {
	                }
	        	}
	        }
		}
		
		return baos.toByteArray();
	}
	
	public static byte[] loadAsset(String path, boolean isFile) {
		try {
	        AssetManager am = Director.getInstance().getContext().getAssets();
	        if(isFile) {
	        	return dataOfFile(new File(path));
	        } else {
	        	return dataOfStream(am.open(path));
	        }
        } catch (IOException e) {
        	return new byte[0];
        }
	}
}