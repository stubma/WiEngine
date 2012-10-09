package com.wiyun.engine.tests.other;

import android.os.Environment;

import com.wiyun.engine.WiEngineTestActivity;

public class ScreenshotTest extends WiEngineTestActivity {
	private native void nativeStart();
	
	@Override
	protected String checkPrecondition() {
		String t = Environment.getExternalStorageState();
		if(!Environment.MEDIA_MOUNTED.equals(t)) {
			return "This demo requires a SD card";
		} else {
			return null;
		}
	}

	@Override
	protected void runDemo() {
		nativeStart();
	}
}

