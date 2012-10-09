package com.wiyun.engine.tests.ease;

import com.wiyun.engine.WiEngineTestActivity;

public class EaseSineInOutTest extends WiEngineTestActivity {
	private native void nativeStart();

	@Override
	protected void runDemo() {
		nativeStart();
	}
}

