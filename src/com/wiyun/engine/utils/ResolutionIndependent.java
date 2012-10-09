package com.wiyun.engine.utils;

import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;

/**
 * A helper class for convert value based on current display resultions
 */
public class ResolutionIndependent {
	/**
	 * Convert a point to current resolution
	 * 
	 * @param p {@link WYPoint} object, the point object should use 160dpi value and its unit is
	 * 		assumed as DIP
	 * @return converted point object, actually it is same as point passed in
	 */
	public static WYPoint resolve(WYPoint p) {
		p.x = resolveDp(p.x);
		p.y = resolveDp(p.y);
		return p;
	}
	
	/**
	 * Convert a point to current resolution
	 * 
	 * @param s {@link WYSize} object, the size object should use 160dpi value and its unit is
	 * 		assumed as DIP
	 * @return converted size object, actually it is same as size passed in
	 */
	public static final WYSize resolve(WYSize s) {
		s.width = resolveDp(s.width);
		s.height = resolveDp(s.height);
		return s;
	}
	
	/**
	 * Convert a point to current resolution
	 * 
	 * @param r {@link WYRect} object, the rect object should use 160dpi value and its unit is
	 * 		assumed as DIP
	 * @return converted rect object, actually it is same as rect passed in
	 */
	public static WYRect resolve(WYRect r) {
		r.origin = resolve(r.origin);
		r.size = resolve(r.size);
		return r;
	}
	
	/**
	 * 把一个dp值转换为像素值
	 * 
	 * @param v dp值
	 * @return 像素值
	 */
	public native static float resolveDp(float v);
	
	/**
	 * 把一个sp值转换为像素值
	 * 
	 * @param v sp值
	 * @return 像素值
	 */
	public native static float resolveSp(float v);
}
