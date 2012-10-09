package com.wiyun.engine;

import javax.microedition.khronos.opengles.GL10;

/**
 * \if English
 * some global constants
 * \else
 * 定义了一些全局常量
 * \endif
 */
public class WiEngine {
	/**
	 * \if English
	 * log tag for WiEngine
	 * \else
	 * WiEngine的log标记
	 * \endif
	 */
	public static final String LOG = "libwiengine";

	/**
	 * \if English
	 * trace flag, if set to true, more log is printed
	 * \else
	 * 调试标志
	 * \endif
	 */
	public static final boolean TRACE = false;
	
	/**
	 * \if English
	 * debug flag for output performance info
	 * \else
	 * 性能调试标志
	 * \endif
	 */
	public static final boolean LOG_PERFORMANCE = false;

	/**
	 * \if English
	 * Default source blending mode
	 * \else
	 * WiEngine缺省源渲染方式
	 * \endif
	 */
	public static final int DEFAULT_BLEND_SRC = GL10.GL_SRC_ALPHA;

	/**
	 * \if English
	 * Default target blending mode
	 * \else
	 * WiEngine缺省目标渲染方式
	 * \endif
	 */
	public static final int DEFAULT_BLEND_DST = GL10.GL_ONE_MINUS_SRC_ALPHA;
}