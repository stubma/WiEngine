package com.wiyun.engine.skeleton;

import android.app.Activity;
import android.media.AudioManager;
import android.os.Bundle;
import android.view.Window;
import android.view.WindowManager;

import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.opengl.WYGLSurfaceView;

/**
 * 最简化的C++版WiEngine工程主activity
 */
public class Skeleton extends Activity {
	static {
		/*
		 * 这里您可以去掉你不要的库, 但是wiskia, xml2和wiengine是一定要保留的, 
		 * wiengineskeleton替换成您工程中的库名就行. 如果您在这里删掉了某个库, 务必也
		 * 修改Android.mk把库的链接去掉
		 */
		System.loadLibrary("wiskia");
		System.loadLibrary("xml2");
		System.loadLibrary("wiengine");
		System.loadLibrary("lua");
		System.loadLibrary("box2d");
		System.loadLibrary("wisound");
		System.loadLibrary("json");
		System.loadLibrary("iap");
		System.loadLibrary("winetwork");
		System.loadLibrary("wiengineskeleton");
	}
	
	protected WYGLSurfaceView mGLView;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN);

        mGLView = new WYGLSurfaceView(this);
        setContentView(mGLView);
        
        // demo controls music stream
        setVolumeControlStream(AudioManager.STREAM_MUSIC);
        
        // native
        nativeStart();
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
}
