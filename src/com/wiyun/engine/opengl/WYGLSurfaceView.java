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
package com.wiyun.engine.opengl;

import java.lang.reflect.Field;

import javax.microedition.khronos.egl.EGL10;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.egl.EGLDisplay;

import android.app.Activity;
import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.PixelFormat;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;
import android.view.GestureDetector;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.inputmethod.InputMethodManager;

import com.wiyun.engine.events.EventDispatcher;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.sound.AudioManager;

/**
 * WiEngine的自定义GLSurfaceView子类，封装了与Director交互的逻辑以及事件转发逻辑。
 */ 
public class WYGLSurfaceView extends GLSurfaceView {
	protected Director mDirector;
    private EventDispatcher mDispatcher;

	// gesture detector
	private GestureDetector mGestureDetector;
	
	// flag indicating system can handle volumn key event, default is true
	private boolean mSystemHandleVolumnKey;
	
	// flag indicating system can handle menu key event, default is true
	private boolean mSystemHandleMenuKey;
	
	// use z buffer or not, default is false
	private boolean mEnableZBuffer;
	
	// use stencil buffer or not, default is false
	private boolean mEnableStencilBuffer;
	
	// mute set flag for audiomanager
	static boolean sMuteSet = false;
	
    /**
     * 构造函数
     * 
     * @param context {@link Context}
     */
    public WYGLSurfaceView(Context context) {
        this(context, null, false, false, false);
    }
    
    /**
     * 构造函数
     * 
     * @param context {@link Context}
     * @param transparent true表示背景透明
     */
    public WYGLSurfaceView(Context context, boolean transparent) {
        this(context, null, false , false , transparent);
    }
    
    /**
     * 构造函数
     * 
     * @param context {@link Context}
     * @param attrs 属性集, 如果从xml创建WYGLSurfaceView, 会传入这个参数
     */
    public WYGLSurfaceView(Context context, AttributeSet attrs) {
    	this(context, attrs, false, false, false);
	}
    
    /**
     * 构造函数
     * 
     * @param context {@link Context}
     * @param attrs 属性集, 如果从xml创建WYGLSurfaceView, 会传入这个参数
     * @param enableZBuffer 是否打开Z-buffer
     * @param enableStencilBuffer 是否打开stencil buffer
     * @param transparent true表示使surface view透明
     */
    public WYGLSurfaceView(Context context, AttributeSet attrs, boolean enableZBuffer, boolean enableStencilBuffer, boolean transparent) {
		super(context, attrs);
		
		/*
		 * need check styleable by reflection, we can't access this attribute directly because
		 * WiEngine is a sdk and R class is not in com.wiyun.engine package
		 */
		if (attrs != null) {
			try {
	            String pkg = context.getPackageName();
	            String styleableName = pkg + ".R$styleable";
	            Class<?> styleableClass = Class.forName(styleableName);
	            Field f1 = styleableClass.getField("com_wiyun_engine_opengl_WYGLSurfaceView");
	            Field f2 = styleableClass.getField("com_wiyun_engine_opengl_WYGLSurfaceView_transparent");
				TypedArray a = context.obtainStyledAttributes(attrs, (int[])f1.get(null));  
				transparent = a.getBoolean(f2.getInt(null), false);
            } catch (Exception e) {
            }
		}
		
		// let system handle some keys
		mSystemHandleVolumnKey = true;
		mSystemHandleMenuKey = true;
		mEnableZBuffer = enableZBuffer;
		mEnableStencilBuffer = enableStencilBuffer;
		
        // create director instance
        mDirector = Director.getInstance();
        mDirector.attachContext(context);

        // get dispatcher
        mDispatcher = EventDispatcher.getInstance();
        
        // setup gesture detector
        mGestureDetector = new GestureDetector(context, mDispatcher);
        mGestureDetector.setIsLongpressEnabled(true);

        // set director as renderer
        setEGLConfigChooser(new WYConfigChooser(transparent));
        if (transparent) {
        	getHolder().setFormat(PixelFormat.TRANSLUCENT);
        }
        setRenderer(mDirector);

        // set focusable
        setFocusable(true);
        setFocusableInTouchMode(true);
    }
    
    /**
     * 让Android可以处理音量键，这样的话会使用系统缺省的
     * 调节音量界面。
     */
    public void enableSystemHandleVolumnKey() {
    	mSystemHandleVolumnKey = true;
    }
    
    /**
     * 不让Android可以处理音量键
     */
    public void disableSystemHandleVolumnKey() {
    	mSystemHandleVolumnKey = false;
    }
    
    /**
     * 让Android可以处理菜单键，这样的话不会影响Activity.onCreateOptionsMenu的功能
     */
    public void enableSystemHandleMenuKey() {
    	mSystemHandleMenuKey = true;
    }
    
    /**
     * 不让Android可以处理菜单键
     */
    public void disableSystemHandleMenuKey() {
    	mSystemHandleMenuKey = false;
    }
    
    @Override
    public void onWindowFocusChanged(boolean hasWindowFocus) {
        super.onWindowFocusChanged(hasWindowFocus);

        try {
        	// check current mute setting when window lost focus
	        if(!hasWindowFocus) {
	        	sMuteSet = AudioManager.isMuted();
	        }
	        
	        // only do right thing when must is not set by user
	        if(!sMuteSet) {
	            // enable music or not
	            // catch exception for it in case they don't use wisound
    	        AudioManager.setMute(!hasWindowFocus);
	        }
        } catch (Throwable e) {
        }
    }
    
    @Override
    public void setRenderer(Renderer renderer) {
    	((Director)renderer).attachInView(this);
    	super.setRenderer(renderer);
    }
    
    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
    	super.surfaceDestroyed(holder);
    	
    	// notify director
    	mDirector.onSurfaceDestroyed();
    }
    
    @Override
    public void surfaceCreated(SurfaceHolder holder) {
    	super.surfaceCreated(holder);
    	
    	// enable depth test if z buffer is switched on
		Director.getInstance().setDepthTest(mEnableZBuffer);
    }
    
    @Override
	public boolean onTouchEvent(MotionEvent event) {
		// Give everything to the gesture detector
		// it will call gesture or double tap listener
		mGestureDetector.onTouchEvent(event);
		
		MotionEvent e = MotionEvent.obtain(event);
		
		/*
		 * XXX: 事件调试输出代码，需要查看触摸事件信息时，可以取消注释
		 */
//		String names[] = { "DOWN", "UP", "MOVE", "CANCEL",
//				"OUTSIDE", "POINTER_DOWN", "POINTER_UP", "7?",
//				"8?", "9?" };
//		StringBuilder sb = new StringBuilder();
//		int action = event.getAction();
//		int actionCode = action & MotionEvent.ACTION_MASK;
//		sb.append("event ACTION_").append(names[actionCode]);
//		if (actionCode == MotionEvent.ACTION_POINTER_DOWN
//				|| actionCode == MotionEvent.ACTION_POINTER_UP) {
//			sb.append("(pid ").append(
//					event.getPointerId((action & MotionEvent.ACTION_POINTER_ID_MASK) >> MotionEvent.ACTION_POINTER_ID_SHIFT));
//			sb.append(")");
//		}
//		sb.append("[");
//		for (int i = 0; i < event.getPointerCount(); i++) {
//			sb.append("#").append(i);
//			sb.append("(pid ").append(event.getPointerId(i));
//			sb.append(")=").append((int) event.getX(i));
//			sb.append(",").append((int) event.getY(i));
//			if (i + 1 < event.getPointerCount())
//				sb.append(";");
//		}
//		sb.append("]");
//		Log.d("libwiengine", sb.toString());
		
        switch (e.getAction()) {
            case MotionEvent.ACTION_CANCEL:
            case MotionEvent.ACTION_OUTSIDE:
                mDispatcher.touchesCancelled(e);
                break;
            case MotionEvent.ACTION_DOWN:
            	// ensure the focus is in surface view
            	if(!isFocused()) {
            		requestFocus();
            		
            		// try to hide soft keyboard
            		Context context = getContext();
            		if(context instanceof Activity) {
            			Activity act = (Activity)context;
                		InputMethodManager imm = (InputMethodManager)context.getSystemService(Context.INPUT_METHOD_SERVICE);
                		if(imm != null) {
                			imm.hideSoftInputFromWindow(act.getWindow().getDecorView().getWindowToken(), 0);
                		}
            		}
            	}
            	
                mDispatcher.touchesBegan(e);
                break;
            case MotionEvent.ACTION_MOVE:
                mDispatcher.touchesMoved(e);
                break;
            case MotionEvent.ACTION_UP:
                mDispatcher.touchesEnded(e);
                break;
            default:
            	// XXX: use number so that it can be integrated by 1.6
        		switch(e.getAction() & 0xFF) {
        			case 5: // MotionEvent.ACTION_POINTER_DOWN:
        				mDispatcher.touchesPointerBegan(e);
        				break;
        			case 6: // MotionEvent.ACTION_POINTER_UP:
        				mDispatcher.touchesPointerEnded(e);
        				break;
        		}
            	break;
        }
        
        return true;
    }
    
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
    	switch(keyCode) {
    		case KeyEvent.KEYCODE_VOLUME_DOWN:
    		case KeyEvent.KEYCODE_VOLUME_UP:
    			if(mSystemHandleVolumnKey) {
    				return super.onKeyDown(keyCode, event);
    			} else {
        			mDispatcher.keyDown(event);
        			return true;
    			}
    		case KeyEvent.KEYCODE_MENU:
    			if(mSystemHandleMenuKey) {
    				return super.onKeyDown(keyCode, event);
    			} else {
    				mDispatcher.keyDown(event);
    				return true;
    			}
    		default:
    			mDispatcher.keyDown(event);
    			return true;
    	}
    }
    
    @Override
    public boolean onKeyUp(int keyCode, KeyEvent event) {
    	switch(keyCode) {
    		case KeyEvent.KEYCODE_VOLUME_DOWN:
    		case KeyEvent.KEYCODE_VOLUME_UP:
    			if(mSystemHandleVolumnKey) {
    				return super.onKeyUp(keyCode, event);
    			} else {
    		    	mDispatcher.keyUp(event);
    				return true;
    			}
    		case KeyEvent.KEYCODE_MENU:
    			if(mSystemHandleMenuKey) {
    				return super.onKeyUp(keyCode, event);
    			} else {
    				mDispatcher.keyUp(event);
    				return true;
    			}
    		default:
		    	mDispatcher.keyUp(event);
				return true;
    	}
    }
    
    @Override
    public boolean onKeyMultiple(int keyCode, int repeatCount, KeyEvent event) {
    	switch(keyCode) {
    		case KeyEvent.KEYCODE_VOLUME_DOWN:
    		case KeyEvent.KEYCODE_VOLUME_UP:
    			if(mSystemHandleVolumnKey) {
    				return super.onKeyMultiple(keyCode, repeatCount, event);
    			} else {
        			mDispatcher.keyMultiple(event);
        			return true;
    			}
    		case KeyEvent.KEYCODE_MENU:
    			if(mSystemHandleMenuKey) {
    				return super.onKeyMultiple(keyCode, repeatCount, event);
    			} else {
    				mDispatcher.keyMultiple(event);
    				return true;
    			}
    		default:
    			mDispatcher.keyMultiple(event);
    			return true;
    	}
    }
    
    /**
     * 选择EGL配置
     */
    private class WYConfigChooser implements GLSurfaceView.EGLConfigChooser {
    	private boolean mTransparent;
    	
    	WYConfigChooser(boolean transparent) {
    		mTransparent = transparent;
    	}
    	
		public EGLConfig chooseConfig(EGL10 egl, EGLDisplay display) {
			/*
			 * build a preferred config first
			 */
			
			// color bits
			int r = 5, g = 6, b = 5, a = 0;
			if (mTransparent) {
				r = 8;
				g = 8;
				b = 8;
				a = 8;
			}
			int i = 0;
			int[] config_attribs = new int[32];
			config_attribs[31] = EGL10.EGL_NONE;
        	config_attribs[i++] = EGL10.EGL_RED_SIZE;
			config_attribs[i++] = r;
			config_attribs[i++] = EGL10.EGL_GREEN_SIZE;
			config_attribs[i++] = g;
			config_attribs[i++] = EGL10.EGL_BLUE_SIZE;
			config_attribs[i++] = b;
			config_attribs[i++] = EGL10.EGL_ALPHA_SIZE;
			config_attribs[i++] = a;
			
			// z buffer
			if(mEnableZBuffer) {
				config_attribs[i++] = EGL10.EGL_DEPTH_SIZE;
				config_attribs[i++] = 16;
			}
			
			// stencil buffer
			if(mEnableStencilBuffer) {
				config_attribs[i++] = EGL10.EGL_STENCIL_SIZE;
				config_attribs[i++] = 8;
			}
			
			// surface type
			config_attribs[i++] = EGL10.EGL_SURFACE_TYPE;
			config_attribs[i++] = EGL10.EGL_WINDOW_BIT;
			
			// end
            config_attribs[i] = EGL10.EGL_NONE;

            // let system return a matched config
			int[] num_config = new int[1];
			egl.eglChooseConfig(display, config_attribs, null, 0, num_config);
			
			// no matched? throw error
			if(num_config[0] <= 0)
				throw new IllegalArgumentException("Failed to find a suitable config");
			
			// use matched config
			EGLConfig[] configs = new EGLConfig[num_config[0]];
			egl.eglChooseConfig(display, config_attribs, configs, num_config[0], num_config);
			
			// We need to find a suitable config that matches our pixel format
			int[] value = new int[1];
			for(int j = 0; j < num_config[0]; ++j) {
				if((egl.eglGetConfigAttrib(display, configs[j], EGL10.EGL_RED_SIZE,   value) && value[0] == r)
				&& (egl.eglGetConfigAttrib(display, configs[j], EGL10.EGL_GREEN_SIZE, value) && value[0] == g)
				&& (egl.eglGetConfigAttrib(display, configs[j], EGL10.EGL_BLUE_SIZE,  value) && value[0] == b)
				&& (egl.eglGetConfigAttrib(display, configs[j], EGL10.EGL_ALPHA_SIZE, value) && value[0] == a))
					return configs[j];
	        }
			return null;
        }
    }
}
