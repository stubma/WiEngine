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
package com.wiyun.engine.skeleton;

import android.app.Activity;
import android.content.pm.ActivityInfo;
import android.media.AudioManager;
import android.os.Bundle;
import android.view.Window;
import android.view.WindowManager;

import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Director.IDirectorLifecycleListener;
import com.wiyun.engine.opengl.WYGLSurfaceView;

/**
 * 最简化的C++版WiEngine工程主activity
 */
public class Skeleton extends Activity implements IDirectorLifecycleListener {
	static {
		System.loadLibrary("wiengine");
		System.loadLibrary("wiengineskeleton");
	}
	
	protected WYGLSurfaceView mGLView;
	
	// true表示初始场景已经被启动了
	private boolean mStarted;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN);

        mGLView = new WYGLSurfaceView(this);
        setContentView(mGLView);
        
        // demo controls music stream
        setVolumeControlStream(AudioManager.STREAM_MUSIC);
        
        // add lifecycle listener
        Director.getInstance().addLifecycleListener(this);
    }

	private native void nativeStart();

	@Override
    public void onPause() {
        super.onPause();

        Director.getInstance().pause();
    }

    @Override
    public void onResume() {
        super.onResume();

        Director.getInstance().resume();
    }

    @Override
    public void onDestroy() {
    	Director.getInstance().end();
    	
    	super.onDestroy();
    }

	@Override
	public void onDirectorEnded() {
	}

	@Override
	public void onDirectorPaused() {
	}

	@Override
	public void onDirectorResumed() {
	}

	@Override
	public void onDirectorScreenCaptured(String path) {
	}

	@Override
	public void onSurfaceChanged(int w, int h) {
    	/*
    	 * 把runDemo放在这里, 可以避免一些屏幕尺寸问题. 因为一开始WiEngine并不知道
    	 * SurfaceView的尺寸, 所以是假设为全屏大小. 在之后的onSurfaceChanged事件中, 
    	 * 正确的大小会被设置. 但是往往在onSurfaceChanged之前, 场景就已经被创建了, 
    	 * 所以如果因为某种原因不是全屏大小, 那么之前创建的场景位置就有误了.
    	 * 
    	 * 由于onSurfaceChanged有可能被调用多次, 用一个标志来防止多次运行. 而且这可能
    	 * 还不够, 有些情况下onSurfaceChanged可能连续被调用两次, 第一次传入的尺寸不对, 
    	 * 而第二次是对的. 这种情况下, 还需要做更多的检查, 可以通过尺寸大小和屏幕朝向来检查.
    	 * 比如游戏如果是横屏的, 则w必须要大于h才认为是可以的, 反之则必须要h大于w才可以.
    	 */
    	boolean landscape = getRequestedOrientation() == ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE;
    	if(!mStarted && (landscape && w >= h || !landscape && h >= w)) {
    		mStarted = true;
    		nativeStart();
    	}
	}

	@Override
	public void onSurfaceCreated() {
	}

	@Override
	public void onSurfaceDestroyed() {
	}
}
