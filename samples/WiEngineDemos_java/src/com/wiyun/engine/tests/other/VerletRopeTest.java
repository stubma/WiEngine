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
package com.wiyun.engine.tests.other;

import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.INodeVirtualMethods;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;
import com.wiyun.engine.utils.VerletRope;

public class VerletRopeTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	public class MyLayer extends Layer implements INodeVirtualMethods {
		VerletRope m_rope;
		WYPoint m_a;
		WYPoint m_b;
		
		MyLayer() {
			// create rope
			WYSize s = Director.getInstance().getWindowSize();
			m_a = WYPoint.make(s.width / 2, s.height - 100);
			m_b = WYPoint.make(50, s.height / 2);
			m_rope = VerletRope.make(m_a, m_b, Texture2D.makePNG(R.drawable.rope));

			// enable touch
			setTouchEnabled(true);

			// we need release detector when exit
			setJavaVirtualMethods(this);
			setNoDraw(true);
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
			setTouchEnabled(true);
		}
		
		@Override
		public boolean wyTouchesBegan(MotionEvent event) {
			m_b = Director.getInstance().convertToGL(event.getX(), event.getY());
			return super.wyTouchesBegan(event);
		}
		
		public void update(float delta) {
			m_rope.update(m_a, m_b, 1.0f / 30.f);
		}

		@Override
		public void jDraw() {
			m_rope.draw();
		}

		@Override
		public void jOnEnter() {
		}

		@Override
		public void jOnEnterTransitionDidFinish() {
		}

		@Override
		public void jOnExit() {
			m_rope.autoRelease();
		}
	}
}
