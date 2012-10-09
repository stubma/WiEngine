package com.wiyun.engine.tests.gridaction;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;

public class TilesShrinkOutTest extends WiEngineTestActivity {
	private native void nativeStart();

	@Override
	protected String checkPrecondition() {
		return Director.getInstance().isExtensionSupported("GL_OES_framebuffer_object")
			? null
			: "Your device doesn't support frame buffer object, this demo will not work";
	}

	@Override
	protected void runDemo() {
		nativeStart();
	}
}

