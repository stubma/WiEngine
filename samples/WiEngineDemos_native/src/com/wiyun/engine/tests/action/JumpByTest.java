package com.wiyun.engine.tests.action;

import com.wiyun.engine.WiEngineTestActivity;

public class JumpByTest extends WiEngineTestActivity {
	private native void nativeStart();

	@Override
	protected void runDemo() {
		nativeStart();
	}
}

