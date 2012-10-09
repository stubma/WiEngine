package com.wiyun.engine.tests.ease;

import com.wiyun.engine.WiEngineTestActivity;

public class EaseInTest extends WiEngineTestActivity {
	private native void nativeStart();

	@Override
	protected void runDemo() {
		nativeStart();
	}
}
