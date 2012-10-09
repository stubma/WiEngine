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
 * 最简化的java版WiEngine工程主activity
 */
public class Skeleton extends Activity implements IDirectorLifecycleListener {
	static {
		/*
		 * 这里您可以去掉你不要的库, 但是wiskia, xml2和wiengine是一定要保留的
		 */
		System.loadLibrary("wiskia");
		System.loadLibrary("xml2");
		System.loadLibrary("wiengine");
		System.loadLibrary("wiengine_binding");
		System.loadLibrary("lua");
		System.loadLibrary("chipmunk");
		System.loadLibrary("box2d");
		System.loadLibrary("wisound");
	}
	
	protected WYGLSurfaceView mGLView;
	
	// true表示场景已经被启动了
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
        
        // 设置显示帧率，程序发布时应该去掉
        Director.getInstance().setDisplayFPS(true);
    }

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
    	 * 把起始代码放在这里, 可以避免一些屏幕尺寸问题. 因为一开始WiEngine并不知道
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
    		Director.getInstance().runWithScene(new FirstScene());
    	}
	}

	@Override
	public void onSurfaceCreated() {
	}

	@Override
	public void onSurfaceDestroyed() {
	}
}
