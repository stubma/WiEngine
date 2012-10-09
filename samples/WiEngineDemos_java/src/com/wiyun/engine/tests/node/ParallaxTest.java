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
package com.wiyun.engine.tests.node;

import android.os.Build;
import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.ParallaxNode;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.nodes.TiledSprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;

public class ParallaxTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
	
    @Override
    protected String checkPrecondition() {
    	return Build.VERSION.SDK_INT > 4 ? null : "This demo requires Android 2.0 or higher version";
    }

	class MyLayer extends Layer {
		static final int TAG_PARALLAX = 1;

		WYPoint previousLocation;

		public MyLayer() {
			setTouchEnabled(true);
			WYSize s = Director.getInstance().getWindowSize();
			
			// Top Layer, a simple image
			Sprite image = Sprite.make(R.drawable.powered);
			image.setAnchor(0, 0);
			image.setPosition(s.width, 100);

			// background layer: another image
			TiledSprite ts = TiledSprite.make(Texture2D.makePNG(R.drawable.tiled_bg));
			ts.setContentSize(s.width, ResolutionIndependent.resolveDp(115));
			ts.setTileDirection(true, false);
			ts.setAnchor(0, 0);
			ts.setPosition(0, 100);
			
			/*
			 * 我们要允许整个场景能往右移动，最开始场景在最左边
			 * 假设场景有3个屏幕宽，场景的基准点在左下角, 那么当场景移动到最右边的时候，
			 * 场景的左下角应该是在屏幕左侧两个屏幕宽的位置。在左边，我们规定为负值，所以
			 * 场景的偏移合法访问是-2个屏幕到0, 不是正2个屏幕，要分清
			 */
			ParallaxNode parallax = ParallaxNode.make();
			parallax.setMaxX(0);
			parallax.setMinX(-(int)s.width * 2);
			parallax.setMinY(0);
			parallax.setMaxY(0);
			
			// background image is moved at a ratio of 0.4x, 0.5y
			parallax.addChild(ts, -1, 1f, 1f);

			// top image is moved at a ratio of 2.0x, 2.0y
			parallax.addChild(image, 2, 3.0f, 3.0f);
			addChild(parallax, 0, TAG_PARALLAX);
			
			setGestureEnabled(true);
		}

		@Override
		public boolean wyTouchesBegan(MotionEvent event) {
			previousLocation = WYPoint.make(event.getX(), event.getY());
			ParallaxNode node = ParallaxNode.from(getChildPointer(TAG_PARALLAX));
			node.stopFling();
			return true;
		}

		@Override
		public boolean wyTouchesEnded(MotionEvent event) {
			return true;
		}

		@Override
		public boolean wyTouchesCancelled(MotionEvent event) {
			return false;
		}

		@Override
		public boolean wyTouchesMoved(MotionEvent event) {
			WYPoint diff = WYPoint.makeZero();

			WYPoint touchLocation = WYPoint.make(event.getX(), event.getY());

			WYPoint location = Director.getInstance().convertToGL(touchLocation.x, touchLocation.y);
			WYPoint prevLocation = Director.getInstance().convertToGL(previousLocation.x, previousLocation.y);

			diff.x = location.x - prevLocation.x;
			diff.y = location.y - prevLocation.y;

			ParallaxNode node = ParallaxNode.from(getChildPointer(TAG_PARALLAX));
			node.offsetBy(diff.x, 0);

			previousLocation = touchLocation;

			return true;
		}
		
		@Override
		public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX,
				float velocityY) {
			ParallaxNode node = ParallaxNode.from(getChildPointer(TAG_PARALLAX));
			node.fling(velocityX, velocityY);
			return true;
		}
	}
}
