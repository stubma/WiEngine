package com.wiyun.engine.tests.particle;

import com.wiyun.engine.WiEngineTestActivity;

public class HGETest extends WiEngineTestActivity {
	private native void nativeStart();

	@Override
	protected void runDemo() {
		nativeStart();
	}
}