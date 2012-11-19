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
 * Key code defined in Android
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
 * General modifier flag definition
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
 * Key event definition
 */
typedef struct wyKeyEvent {
	/**
	 * key code
	 */
	wyKeyCode keyCode;
	
	/**
	 * int repeat count
	 */
	int repeatCount;
	
	/**
	 * event time
	 */
	int64_t eventTime;
	
	/**
	 * down time
	 */
	int64_t downTime;
	
#if MACOSX || WINDOWS
	/**
	 * modifier key flags
	 */
	int modifierFlags;
#endif
	
#if MACOSX
	/**
	 * keycode defined by carbon
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
 * Touch event structure, it is a platform-independent abstraction
 */
typedef struct wyMotionEvent {
	/**
	 * touch pointer count in this event
	 */
	int pointerCount;
	
	/**
	 * If event is touch pointer began or end, then this index is the pointer which
	 * is beginning or ending. You can get pointer id by pid[index]
	 */
	int index;
	
	/**
	 * Pointer id list of touch, max capacity is five
	 */
	int pid[5];
	
	/**
	 * Pointer x location in OpenGL coordinate system, max capacity is five
	 */
	float x[5];
	
	/**
	 * Pointer y location in OpenGL coordinate system, max capacity is five
	 */
	float y[5];
	
#if ANDROID
	/**
	 * touch pressure
	 */
	float pressure;
	
	/**
	 * touch down time in milliseconds from 1970-1-1
	 */
	int64_t downTime;
#elif IOS || WINDOWS
	/**
	 * tap count of this touch pointer
	 */
	int tap[5];
#endif
	
#if MACOSX || WINDOWS
	/**
	 * modifier key flags
	 */
	int modifierFlags;
#endif
	
	/**
	 * Event time in milliseconds from 1970-1-1
	 */
	int64_t eventTime;
} wyMotionEvent;

/**
 * @typedef wyEventType
 *
 * General event type definition
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
 * General event structure
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
