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
package com.wiyun.engine.tests.box2d;

import javax.microedition.khronos.opengles.GL10;

import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.MoveBy;
import com.wiyun.engine.actions.RotateBy;
import com.wiyun.engine.box2d.CDResult;
import com.wiyun.engine.box2d.CollisionDetector;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.INodeVirtualMethods;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Primitives;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;
import com.wiyun.engine.utils.TargetSelector;
import com.wiyun.engine.utils.Utilities;

public class CollisionDetectionTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer implements INodeVirtualMethods {
    	Sprite m_sprite1;
    	Sprite m_sprite2;
    	CollisionDetector m_detector;
    	CDResult m_result = new CDResult();
    	
		public MyLayer() {
			// create sprite1
			float size = DP(32.0f);
			Texture2D tex = Texture2D.makePNG(R.drawable.blocks);
			m_sprite1 = Sprite.make(tex, WYRect.make(Utilities.rand(2) * size, Utilities.rand(2) * size, size, size));
			addChild(m_sprite1, -1);

			// create sprite2
			m_sprite2 = Sprite.make(tex, WYRect.make(Utilities.rand(2) * size, Utilities.rand(2) * size, size, size));
			addChild(m_sprite2, -1);

			// init and begin
			reset();

			// create collision detector
			m_detector = CollisionDetector.make();
			
			// we need release detector when exit
			setJavaVirtualMethods(this);
			setNoDraw(true);
			
			schedule(new TargetSelector(this, "checkCollision(float)", new Object[] { 0f }));
			setTouchEnabled(true);
		}
		
		public void checkCollision(float delta) {
			if(m_result.pointCount == 0) {
				if(m_detector.isCollided(m_sprite1, m_sprite2, m_result)) {
					m_sprite1.stopAllActions();
					m_sprite2.stopAllActions();
				}
			}
		}
		
		private float DP(float v) {
			return ResolutionIndependent.resolveDp(v);
		}
		
		void reset() {
			// clear result
			m_result.clear();

			// relocate sprite
			WYSize s = Director.getInstance().getWindowSize();
			m_sprite1.setRotation(Utilities.rand(360));
			m_sprite1.setPosition(0, 0);
			m_sprite2.setRotation(Utilities.rand(360));
			m_sprite2.setPosition(s.width, s.height);

			// re-run actions
			MoveBy move1 = MoveBy.make(4, s.width, s.height);
			move1.autoRelease();
			RotateBy rotate1 = RotateBy.make(4, Utilities.rand(360));
			rotate1.autoRelease();
			m_sprite1.runAction(move1);
			m_sprite1.runAction(rotate1);
			MoveBy move2 = MoveBy.make(4, -s.width, -s.height);
			move2.autoRelease();
			RotateBy rotate2 = RotateBy.make(4, Utilities.rand(360));
			rotate2.autoRelease();
			m_sprite2.runAction(move2);
			m_sprite2.runAction(rotate2);
		}
		
		@Override
		public boolean wyTouchesBegan(MotionEvent event) {
			if(m_result.pointCount > 0) {
				reset();
			}
			return super.wyTouchesBegan(event);
		}

		@Override
		public void jDraw() {
			if(m_result.pointCount > 0) {
				// draw collision point
				GL10 gl = Director.getInstance().gl;
	        	gl.glColor4f(1, 0, 0, 1);
	        	gl.glPointSize(5);
	        	Primitives.drawPoints(m_result.getPoints());

	        	// draw normal
				Primitives.drawLine(m_result.points[0].x, m_result.points[0].y,
						   m_result.points[0].x + m_result.normal.x * 50, m_result.points[0].y + m_result.normal.y * 50);

				gl.glColor4f(1, 1, 1, 1);
			}
		}

		@Override
		public void jOnEnter() {
		}

		@Override
		public void jOnEnterTransitionDidFinish() {
		}

		@Override
		public void jOnExit() {
			m_detector.autoRelease();
		}
    }
}
