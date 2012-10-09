package com.wiyun.engine.tests.node;

import android.os.Build;

import com.wiyun.engine.WiEngineTestActivity;

public class TiledSpriteTest extends WiEngineTestActivity {
	private native void nativeStart();

    @Override
    protected String checkPrecondition() {
    	return Build.VERSION.SDK_INT > 4 ? null : "This demo requires Android 2.0 or higher version";
    }
    
	@Override
	protected void runDemo() {
		nativeStart();
	}
}

