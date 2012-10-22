package com.wiyun.engine.tests.gridaction;

import com.wiyun.engine.WiEngineTestActivity;

public class GridFlipXTest extends WiEngineTestActivity {
	private native void nativeStart();

	@Override
	protected void runDemo() {
		nativeStart();
	}
}

