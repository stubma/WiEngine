package com.wiyun.engine.tests.node;

import com.wiyun.engine.WiEngineTestActivity;

public class SpriteX2011Test extends WiEngineTestActivity {
	private native void nativeStart();

	@Override
	protected void runDemo() {
		nativeStart();
	}
}
