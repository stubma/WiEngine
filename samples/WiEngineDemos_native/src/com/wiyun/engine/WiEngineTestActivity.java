package com.wiyun.engine;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.AlertDialog.Builder;
import android.content.DialogInterface;
import android.content.DialogInterface.OnClickListener;
import android.media.AudioManager;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;

import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.opengl.WYGLSurfaceView;

public abstract class WiEngineTestActivity extends Activity {
	static {
		System.loadLibrary("wiskia");
		System.loadLibrary("xml2");
		System.loadLibrary("wiengine");
		System.loadLibrary("lua");
		System.loadLibrary("box2d");
		System.loadLibrary("wisound");
		System.loadLibrary("winetwork");
		System.loadLibrary("json");
		System.loadLibrary("iap");
		System.loadLibrary("cegui");
		System.loadLibrary("wienginedemos");
	}
	
	// surface view
	protected WYGLSurfaceView mGLView;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);

        /*
         * 可以指定是否使用透明的surface view, 除此之外相应的activity必须要设置android:theme为
         * @android:style/Theme.Translucent. 如果希望通过xml指定是否透明, 则需要在attrs.xml中添加
         * transparent属性, 如下:
         * <declare-styleable name="com.wiyun.engine.opengl.WYGLSurfaceView">
         * 		<attr name="transparent" format="boolean" />
         * </declare-styleable>
         * 
         * 使用透明surface view可能带来兼容性问题, 有些机型可能对此支持不好.
         * 
         * 该功能目前仅可在Android上使用, 因此不具备可移植性
         */
        mGLView = (WYGLSurfaceView)createContentView();
        
        // demo controls music stream
        setVolumeControlStream(AudioManager.STREAM_MUSIC);
        
        // run demo
        runDemo();
    }

    @Override
    protected void onPostCreate(Bundle savedInstanceState) {
        super.onPostCreate(savedInstanceState);
        
    	final String error = checkPrecondition();
    	if(!TextUtils.isEmpty(error)) {
    		runOnUiThread(new Runnable() {
	            public void run() {
	            	AlertDialog.Builder builder = new Builder(WiEngineTestActivity.this);
	            	builder.setMessage(error)
	            	.setNegativeButton("OK", new OnClickListener() {
	            		public void onClick(DialogInterface dialog, int which) {
	            			finish();
	            		}
	            	}).show();
	            }
            });
    	}
    }
    
    protected View createContentView() {
    	WYGLSurfaceView v = new WYGLSurfaceView(this, isTransparent());
        setContentView(v);
        return v;
    }

	protected abstract void runDemo();
	
	/**
	 * 检查这个demo是否需要一些前提条件
	 * 
	 * @return 如果前提条件满足, 返回null, 如果不满足, 返回一个错误信息
	 */
	protected String checkPrecondition() {
		return null;
	}
	
	protected boolean isTransparent() {
		return false;
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
}
