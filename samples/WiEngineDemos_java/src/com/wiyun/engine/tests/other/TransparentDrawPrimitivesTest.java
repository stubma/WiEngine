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

import static javax.microedition.khronos.opengles.GL10.GL_LINE_SMOOTH;

import javax.microedition.khronos.opengles.GL10;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.RotateBy;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.INodeVirtualMethods;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.opengl.Primitives;
import com.wiyun.engine.types.WYBezierConfig;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;

public class TransparentDrawPrimitivesTest extends WiEngineTestActivity {
	@Override
	protected void createScene() {
		super.createScene();
		mScene.runAction(RotateBy.make(4, -360));
	}
	
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
	
	protected boolean isTransparent() {
		return true;
	}

	public class MyLayer extends Layer implements INodeVirtualMethods {
		MyLayer() {
			setNoDraw(true);
			setJavaVirtualMethods(this);
		}

		public void jDraw() {
			GL10 gl = Director.getInstance().gl;
			WYSize s = Director.getInstance().getWindowSize();

			// draw a simple line
			// The default state is:
			// Line Width: 1
			// color: 255,255,255,255 (white, non-transparent)
			// Anti-Aliased
			gl.glEnable(GL_LINE_SMOOTH);

			Primitives.drawLine(WYPoint.make(0, 0), WYPoint.make(s.width, s.height));

			// line: color, width, aliased
			// glLineWidth > 1 and GL_LINE_SMOOTH are not compatible
			// GL_SMOOTH_LINE_WIDTH_RANGE = (1,1) on iPhone
			gl.glDisable(GL_LINE_SMOOTH);
			gl.glLineWidth(5.0f);
			gl.glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
			Primitives.drawLine(WYPoint.make(0, s.height), WYPoint.make(s.width, 0));

			// TIP:
			// If you are going to use always the same color or width, you don't
			// need to call it before every draw
			//
			// Remember: OpenGL is a state-machine.

			// draw big point in the center
			gl.glPointSize(64);
			gl.glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
			Primitives.drawPoint(s.width / 2, s.height / 2);

			// draw 4 small points
			WYPoint points[] = {
					WYPoint.make(60, 60), WYPoint.make(70, 70), WYPoint.make(60, 70), WYPoint.make(70, 60)
			};
			gl.glPointSize(4);
			gl.glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
			Primitives.drawPoints(points);

			// draw a green circle with 10 segments
			gl.glLineWidth(16);
			gl.glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
			Primitives.drawCircle(s.width / 2, s.height / 2, 100, 0, 10, false);

			// draw a green circle with 50 segments with line to center
			gl.glLineWidth(2);
			gl.glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
			Primitives.drawCircle(s.width / 2, s.height / 2, 50, 90, 50, true);

			// open yellow poly
			gl.glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
			gl.glLineWidth(10);
			WYPoint vertices[] = {
					WYPoint.make(0, 0), WYPoint.make(50, 50), WYPoint.make(100, 50), WYPoint.make(100, 100), WYPoint.make(50, 100)
			};
			Primitives.drawPoly(vertices, false);

			// closed purple poly
			gl.glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
			gl.glLineWidth(2);
			WYPoint vertices2[] = {
					WYPoint.make(30, 130), WYPoint.make(30, 230), WYPoint.make(50, 200)
			};
			Primitives.drawPoly(vertices2, true);

			// draw quad bezier path
			WYBezierConfig c = WYBezierConfig.makeQuad(0, s.height, s.width / 2, s.height / 2, s.width, s.height);
			Primitives.drawBezier(c, 50);

			// draw cubic bezier path
			c = WYBezierConfig.makeCubic(s.width / 2,
					s.height / 2,
					s.width / 2 + 30,
					s.height / 2 + 50,
					s.width / 2 + 60,
					s.height / 2 - 50,
					s.width,
					s.height / 2);
			Primitives.drawBezier(c, 100);

			// restore original values
			gl.glLineWidth(1);
			gl.glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			gl.glPointSize(1);
		}

		public void jOnEnter() {
		}

		public void jOnExit() {
		}
		
		public void jOnEnterTransitionDidFinish() {
		}
	}
}
