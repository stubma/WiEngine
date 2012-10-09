package com.wiyun.engine.tests.sound;

import com.wiyun.engine.WiEngineTestActivity;

public class OGGTest extends WiEngineTestActivity{
	private native void nativeStart();

	@Override
	protected void runDemo() {
		nativeStart();
	}

}
