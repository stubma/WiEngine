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
package com.wiyun.engine.tests.event;

import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.FadeIn;
import com.wiyun.engine.actions.FadeOut;
import com.wiyun.engine.actions.JumpTo;
import com.wiyun.engine.actions.MoveTo;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.RotateTo;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.nodes.ColorLayer;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Node;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.utils.Utilities;

public class ClickAndMoveTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends Layer {
		static final int TAG_SPRITE = 1;

		public MyLayer() {
			Sprite sprite = Sprite.make(R.drawable.grossini);
			
			Layer layer = ColorLayer.make(new WYColor4B(255, 255, 0, 255));
			addChild(layer);

			addChild(sprite, 0, TAG_SPRITE);
			sprite.setPosition(20, 150);
			
			sprite.runAction((Action)JumpTo.make(4, sprite.getPositionX(), sprite.getPositionY(), 300, 48, 100, 4).autoRelease());

			layer.runAction((Action)RepeatForever.make(Sequence.make(FadeIn.make(1), FadeOut.make(1))).autoRelease());
			
			setTouchEnabled(true);
		}

		@Override
		public boolean wyTouchesBegan(MotionEvent event) {
			WYPoint convertedLocation = Director.getInstance().convertToGL(event.getX(), event.getY());

			Node s = getChild(TAG_SPRITE);
			s.stopAllActions();
			s.runAction(MoveTo.make(1.0f, s.getPositionX(), s.getPositionY(), convertedLocation.x, convertedLocation.y));
			float o = convertedLocation.x - s.getPositionX();
			float a = convertedLocation.y - s.getPositionY();
			float at = Utilities.r2d((float)Math.atan(o / a));

			if(a < 0) {
				if(o < 0)
					at = 180 + Math.abs(at);
				else
					at = 180 - Math.abs(at);
			}

			s.runAction(RotateTo.make(1, s.getRotation(), at));

			return true;
		}
	}
}
