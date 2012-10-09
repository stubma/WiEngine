package com.wiyun.engine.tests.other;

import com.wiyun.engine.WiEngineTestActivity;

public class MemoryFileSystemTest extends WiEngineTestActivity {
	private native void nativeStart();

	@Override
	protected void runDemo() {
		nativeStart();
	}
}

