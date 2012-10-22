package com.wiyun.engine.tests.gridaction;

import com.wiyun.engine.WiEngineTestActivity;

public class LineShrinkOutTest extends WiEngineTestActivity {
	private native void nativeStart();

	@Override
	protected void runDemo() {
		nativeStart();
	}
}

