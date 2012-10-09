package com.wiyun.engine.tests.sound;

import com.wiyun.engine.WiEngineTestActivity;

public class MP3Test extends WiEngineTestActivity{
	private native void nativeStart();
	
	@Override
	protected void runDemo() {
		nativeStart();
	}
}
