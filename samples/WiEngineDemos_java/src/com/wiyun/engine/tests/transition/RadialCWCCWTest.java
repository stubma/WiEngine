/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
package com.wiyun.engine.tests.transition;

import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Scene;
import com.wiyun.engine.transitions.RadialCCWTransition;
import com.wiyun.engine.transitions.RadialCWTransition;
import com.wiyun.engine.transitions.TransitionScene;


public class RadialCWCCWTest extends TransitionTestActivity {
	@Override
	protected String checkPrecondition() {
		return Director.getInstance().isExtensionSupported("GL_OES_framebuffer_object")
			? null
			: "Your device doesn't support frame buffer object, this demo will not work";
	}
	
	@Override
    protected TransitionScene getBackTransition(Scene scene) {
	    return (TransitionScene)RadialCWTransition.make(1, scene).autoRelease();
    }

	@Override
    protected TransitionScene getTransition(Scene scene) {
	    return (TransitionScene)RadialCCWTransition.make(1, scene).autoRelease();
    }
}
