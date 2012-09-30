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

#ifndef __wyEvents_h__
#define __wyEvents_h__

#include <pthread.h>
#if ANDROID
	#include <jni.h>
#endif

class wyGLTexture2D;
class wyRunnable;
class wyAutoReleasePool;

/**
 * @typedef wyKeyCode
 *
 * \if English
 * Key code defined in Android
 * \else
 * 按键代码
 * \endif
 */
typedef enum {
	KEYCODE_UNKNOWN         = 0,
	KEYCODE_SOFT_LEFT       = 1,
	KEYCODE_SOFT_RIGHT      = 2,
	KEYCODE_HOME            = 3,
	KEYCODE_BACK            = 4,
	KEYCODE_CALL            = 5,
	KEYCODE_ENDCALL         = 6,
	KEYCODE_0               = 7,
	KEYCODE_1               = 8,
	KEYCODE_2               = 9,
	KEYCODE_3               = 10,
	KEYCODE_4               = 11,
	KEYCODE_5               = 12,
	KEYCODE_6               = 13,
	KEYCODE_7               = 14,
	KEYCODE_8               = 15,
	KEYCODE_9               = 16,
	KEYCODE_STAR            = 17,
	KEYCODE_POUND           = 18,
	KEYCODE_DPAD_UP         = 19,
	KEYCODE_DPAD_DOWN       = 20,
	KEYCODE_DPAD_LEFT       = 21,
	KEYCODE_DPAD_RIGHT      = 22,
	KEYCODE_DPAD_CENTER     = 23,
	KEYCODE_VOLUME_UP       = 24,
	KEYCODE_VOLUME_DOWN     = 25,
	KEYCODE_POWER           = 26,
	KEYCODE_CAMERA          = 27,
	KEYCODE_CLEAR           = 28,
	KEYCODE_A               = 29,
	KEYCODE_B               = 30,
	KEYCODE_C               = 31,
	KEYCODE_D               = 32,
	KEYCODE_E               = 33,
	KEYCODE_F               = 34,
	KEYCODE_G               = 35,
	KEYCODE_H               = 36,
	KEYCODE_I               = 37,
	KEYCODE_J               = 38,
	KEYCODE_K               = 39,
	KEYCODE_L               = 40,
	KEYCODE_M               = 41,
	KEYCODE_N               = 42,
	KEYCODE_O               = 43,
	KEYCODE_P               = 44,
	KEYCODE_Q               = 45,
	KEYCODE_R               = 46,
	KEYCODE_S               = 47,
	KEYCODE_T               = 48,
	KEYCODE_U               = 49,
	KEYCODE_V               = 50,
	KEYCODE_W               = 51,
	KEYCODE_X               = 52,
	KEYCODE_Y               = 53,
	KEYCODE_Z               = 54,
	KEYCODE_COMMA           = 55,
	KEYCODE_PERIOD          = 56,
	KEYCODE_ALT_LEFT        = 57,
	KEYCODE_ALT_RIGHT       = 58,
	KEYCODE_SHIFT_LEFT      = 59,
	KEYCODE_SHIFT_RIGHT     = 60,
	KEYCODE_TAB             = 61,
	KEYCODE_SPACE           = 62,
	KEYCODE_SYM             = 63,
	KEYCODE_EXPLORER        = 64,
	KEYCODE_ENVELOPE        = 65,
	KEYCODE_ENTER           = 66,
	KEYCODE_DEL             = 67,
	KEYCODE_GRAVE           = 68,
	KEYCODE_MINUS           = 69,
	KEYCODE_EQUALS          = 70,
	KEYCODE_LEFT_BRACKET    = 71,
	KEYCODE_RIGHT_BRACKET   = 72,
	KEYCODE_BACKSLASH       = 73,
	KEYCODE_SEMICOLON       = 74,
	KEYCODE_APOSTROPHE      = 75,
	KEYCODE_SLASH           = 76,
	KEYCODE_AT              = 77,
	KEYCODE_NUM             = 78,
	KEYCODE_HEADSETHOOK     = 79,
	KEYCODE_FOCUS           = 80,   // *Camera* focus
	KEYCODE_PLUS            = 81,
	KEYCODE_MENU            = 82,
	KEYCODE_NOTIFICATION    = 83,
	KEYCODE_SEARCH          = 84,
	KEYCODE_MEDIA_PLAY_PAUSE= 85,
	KEYCODE_MEDIA_STOP      = 86,
	KEYCODE_MEDIA_NEXT      = 87,
	KEYCODE_MEDIA_PREVIOUS  = 88,
	KEYCODE_MEDIA_REWIND    = 89,
	KEYCODE_MEDIA_FAST_FORWARD = 90,
	KEYCODE_MUTE            = 91,
	KEYCODE_PAGE_UP         = 92,
	KEYCODE_PAGE_DOWN       = 93,
	KEYCODE_PICTSYMBOLS     = 94,   // switch symbol-sets (Emoji,Kao-moji)
	KEYCODE_SWITCH_CHARSET  = 95   // switch char-sets (Kanji,Katakana)
} wyKeyCode;

/**
 * @typedef wyModifierFlag
 *
 * \if English
 * General modifier flag definition
 * \else
 * 通用辅助按键标志
 * \endif
 */
typedef enum {
	WY_CTRL = 1 << 0,
	WY_ALT = 1 << 1,
	WY_SHIFT = 1 << 2,
	WY_COMMAND = 1 << 3,
	WY_CAPSLOCK = 1 << 4
} wyModifierFlag;

/**
 * @struct wyKeyEvent
 *
 * \if English
 * Key event definition
 * \else
 * 按键事件
 * \endif
 */
typedef struct wyKeyEvent {
	/**
	 * \if English
	 * key code
	 * \else
	 * 按键代码
	 * \endif
	 */
	wyKeyCode keyCode;
	
	/**
	 * \if English
	 * int repeat count
	 * \else
	 * 按键重复次数
	 * \endif
	 */
	int repeatCount;
	
	/**
	 * \if English
	 * event time
	 * \else
	 * 事件发生时间
	 * \endif
	 */
	int64_t eventTime;
	
	/**
	 * \if English
	 * down time
	 * \else
	 * 按键按下时间
	 * \endif
	 */
	int64_t downTime;
	
#if MACOSX || WINDOWS
	/**
	 * \if English
	 * modifier key flags
	 * \else
	 * 按键附属键
	 * \endif
	 */
	int modifierFlags;
#endif
	
#if MACOSX
	/**
	 * \if English
	 * keycode defined by carbon
	 * \else
	 * carbon key code in mac os x
	 * \endif
	 */
	int carbonKeyCode;
#endif
} wyKeyEvent;

#define ACTION_MASK 0xff
#define ACTION_POINTER_ID_MASK 0xff00
#define ACTION_POINTER_ID_SHIFT 8

/**
 * @struct wyMotionEvent
 *
 * \if English
 * Touch event structure, it is a platform-independent abstraction
 * \else
 * 触摸事件结构. 这个事件结构相当于对不同平台事件的适配层. 里面有些内容有的是通用的, 有的
 * 也是和平台相关的, 如果要使用平台相关的内容, 要注意在进行跨平台移植的时候是不兼容的.
 * \endif
 */
typedef struct wyMotionEvent {
	/**
	 * \if English
	 * touch pointer count in this event
	 * \else
	 * 触摸点数, 大于1表示多点触摸
	 * \endif
	 */
	int pointerCount;
	
	/**
	 * \if English
	 * If event is touch pointer began or end, then this index is the pointer which
	 * is beginning or ending. You can get pointer id by pid[index]
	 * \else
	 * 如果当前的事件是touch pointer began或end, 则这个index代表的是正在began或end
	 * 的触摸点索引, 通过pid[index]可以得到这个触摸点的id
	 * \endif
	 */
	int index;
	
	/**
	 * \if English
	 * Pointer id list of touch, max capacity is five
	 * \else
	 * 触摸点id, 最多5个
	 * \endif
	 */
	int pid[5];
	
	/**
	 * \if English
	 * Pointer x location in OpenGL coordinate system, max capacity is five
	 * \else
	 * 触摸点x坐标, 最多5个, 相对于OpenGL坐标系
	 * \endif
	 */
	float x[5];
	
	/**
	 * \if English
	 * Pointer y location in OpenGL coordinate system, max capacity is five
	 * \else
	 * 触摸点y坐标, 最多5个, 相对于OpenGL坐标系
	 * \endif
	 */
	float y[5];
	
#if ANDROID
	/**
	 * \if English
	 * touch pressure
	 * \else
	 * 压力
	 * \endif
	 */
	float pressure;
	
	/**
	 * \if English
	 * touch down time in milliseconds from 1970-1-1
	 * \else
	 * 按下时间, 单位毫秒, 从1970-1-1开始
	 * \endif
	 */
	int64_t downTime;
#elif IOS || WINDOWS
	/**
	 * \if English
	 * tap count of this touch pointer
	 * \else
	 * 这个触摸点的点击次数
	 * \endif
	 */
	int tap[5];
#endif
	
#if MACOSX || WINDOWS
	/**
	 * \if English
	 * modifier key flags
	 * \else
	 * 修饰键值
	 * \endif
	 */
	int modifierFlags;
#endif
	
	/**
	 * \if English
	 * Event time in milliseconds from 1970-1-1
	 * \else
	 * 事件发生时间, 单位毫秒, 从1970-1-1开始
	 * \endif
	 */
	int64_t eventTime;
} wyMotionEvent;

/**
 * @typedef wyEventType
 *
 * \if English
 * General event type definition
 * \else
 * 通用事件类型定义, 内部使用
 * \endif
 */
typedef enum {
	// accelerometer
	ET_ACCELEROMETER,
	
	// touch
	ET_TOUCH_BEGAN,
	ET_TOUCH_MOVED,
	ET_TOUCH_ENDED,
	ET_TOUCH_CANCELLED,
	ET_TOUCH_POINTER_BEGAN,
	ET_TOUCH_POINTER_END,
	
	// key
	ET_KEY_DOWN,
	ET_KEY_UP,
	ET_KEY_MULTIPLE,
	
	// double tap
	ET_DOUBLE_TAP,
	ET_DOUBLE_TAP_EVENT,
	ET_SINGLE_TAP_CONFIRMED,
	
	// gesture
	ET_ON_DOWN,
	ET_ON_FLING,
	ET_ON_SCROLL,
	ET_ON_LONG_PRESS,
	ET_ON_SHOW_PRESS,
	ET_ON_SINGLE_TAP_UP,
	
	// custom event for texture
	ET_LOAD_TEXTURE,
	ET_DELETE_TEXTURE,
	ET_UPDATE_TEXTURE,
	ET_APPLY_COLOR_FILTER,
	
	// custom event for object
	ET_DRAIN_AUTO_RELEASE_POOL,

	// custom event for runnable
	ET_RUNNABLE,
	ET_JAVA_RUNNABLE
} wyEventType;

/**
 * @struct wyEvent
 *
 * \if English
 * General event structure
 * \else
 * 通用事件结构
 * \endif
 */
typedef struct wyEvent {
	wyEventType type;
	
	union {
		// motion event
		struct {
			wyPlatformKeyEvent pe;
		} ke;
		
		// motion event
		struct {
			wyPlatformMotionEvent pe;
		} me;
		
		// accelerometer event
		struct {
			// for accelerometer
			float accelX;
			float accelY;
			float accelZ;
		} ae;
		
		// gesture event
		struct {
			wyPlatformMotionEvent pe1;
			wyPlatformMotionEvent pe2;
			float vx;
			float vy;
		} ge;
		
		// texture event
		struct {
			wyGLTexture2D* tex;
			pthread_cond_t* cond;
		} lte;
		
		// runnable
		struct {
			wyRunnable* runnable;
		} r;
		
		// object related event
		struct {
			wyObject* obj;
		} oe;

#if ANDROID
		// java runnable
		struct {
			jobject runnable;
		} jr;
#endif // #if ANDROID
	};
} wyEvent;

#endif // __wyEvents_h__
