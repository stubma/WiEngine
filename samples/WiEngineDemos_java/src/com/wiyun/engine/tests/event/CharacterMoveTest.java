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
import com.wiyun.engine.actions.Animate;
import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.MoveBy;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.Action.Callback;
import com.wiyun.engine.nodes.Animation;
import com.wiyun.engine.nodes.ColorLayer;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.INodeVirtualMethods;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.nodes.SpriteFrame;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;

public class CharacterMoveTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	static float ITEM_WIDTH;
	static float ITEM_HEIGHT;
	
	class MyLayer extends ColorLayer implements Callback, INodeVirtualMethods {
		static final int NONE = 0;
		static final int LEFT = 1;
		static final int RIGHT = 2;
		static final int UP = 3;
		static final int DOWN = 4;
		
		Sprite mPlayer;
		
		// last direction
		int mLastDirection = NONE;
		
		// animation
		Animation mAnimUp, mAnimDown, mAnimLeft, mAnimRight;
		
		// face direction
		SpriteFrame mFaceUp, mFaceDown, mFaceLeft, mFaceRight;
		
		public MyLayer() {
			super(new WYColor4B(0, 0, 255, 255));
			setJavaVirtualMethods(this);
			
			ITEM_WIDTH = ResolutionIndependent.resolveDp(24);
			ITEM_HEIGHT = ResolutionIndependent.resolveDp(32);
			
			// add player
			WYSize s = Director.getInstance().getWindowSize();
			Texture2D tex = Texture2D.makePNG(R.drawable.player);
			mPlayer = Sprite.make(tex, WYRect.make(0, ITEM_HEIGHT * 2, ITEM_WIDTH, ITEM_HEIGHT));
			mPlayer.setPosition(s.width / 2, s.height / 2);
			addChild(mPlayer);
			
			// create animation
			// 这里不能调用autoRelease, 因为这些对象现在不会使用，而是在用户点击屏幕时陆续被用到
			// 如果这里调用了autoRelease, 而这些对象又暂时没有其他对象引用，则这些对象有可能在某个
			// 时间被销毁, 所以这些对象的销毁，可以放到jOnExit中，或者由director退出时自动销毁
			mAnimUp = new Animation(0);
			mAnimUp.addFrame(0.3f, frameAt(0, 0), frameAt(2, 0));
			mAnimDown = new Animation(1);
			mAnimDown.addFrame(0.3f, frameAt(0, 2), frameAt(2, 2));
			mAnimLeft = new Animation(2);
			mAnimLeft.addFrame(0.2f, frameAt(0, 3), frameAt(1, 3), frameAt(2, 3));
			mAnimRight = new Animation(3);
			mAnimRight.addFrame(0.2f, frameAt(0, 1), frameAt(1, 1), frameAt(2, 1));
			
			// create directional frame
			// 这里不能调用autoRelease, 因为这些对象现在不会使用，而是在用户点击屏幕时陆续被用到
			// 如果这里调用了autoRelease, 而这些对象又暂时没有其他对象引用，则这些对象有可能在某个
			// 时间被销毁, 所以这些对象的销毁，可以放到jOnExit中，或者由director退出时自动销毁
			mFaceUp = SpriteFrame.make(0f, frameAt(1, 0));
			mFaceDown = SpriteFrame.make(0f, frameAt(1, 2));
			mFaceRight = SpriteFrame.make(0f, frameAt(1, 1));
			mFaceLeft = SpriteFrame.make(0f, frameAt(1, 3));
			
			setTouchEnabled(true);
		}

		@Override
		public boolean wyTouchesBegan(MotionEvent event) {
			// get delta between touch location and player position
			WYPoint loc = Director.getInstance().convertToGL(event.getX(), event.getY());
			float deltaX = loc.x - mPlayer.getPositionX();
			float deltaY = loc.y - mPlayer.getPositionY();
			
			// move horizontal or vertical?
			boolean horizontal = Math.abs(deltaX) > Math.abs(deltaY);
			
			// decide direction
			int direction = NONE;
			if(horizontal) {
				deltaY = 0f;
				if(deltaX != 0)
					direction = deltaX > 0 ? RIGHT : LEFT;
			} else {
				deltaX = 0f;
				if(deltaY != 0)
					direction = deltaY > 0 ? UP : DOWN;
			}
			
			// get moving velocity
			float velocityX = 0f;
			float velocityY = 0f;
			float duration = 0f;
			Animation animation = null;
			switch(direction) {
				case LEFT:
					velocityX = -100f;
					duration = deltaX / velocityX;
					animation = mAnimLeft;
					break;
				case RIGHT:
					velocityX = 100f;
					duration = deltaX / velocityX;
					animation = mAnimRight;
					break;
				case UP:
					velocityY = 100f;
					duration = deltaY / velocityY;
					animation = mAnimUp;
					break;
				case DOWN:
					velocityY = -100f;
					duration = deltaY / velocityY;
					animation = mAnimDown;
					break;
			}
			
			// if same as last direction
			if(direction != mLastDirection) {
				mLastDirection = direction;
				
				// stop old actions
				mPlayer.stopAllActions();
				
				// create action
				IntervalAction move = (IntervalAction)MoveBy.make(duration, deltaX, deltaY).autoRelease();
				IntervalAction anim = (IntervalAction)Animate.make(animation, true).autoRelease();
				mPlayer.runAction(move);
				mPlayer.runAction((Action)RepeatForever.make(anim).autoRelease());
				move.setCallback(this);
			}
			
			return true;
		}
        
        private WYRect frameAt(int x, int y) {
        	return WYRect.make(x * ITEM_WIDTH, y * ITEM_HEIGHT, ITEM_WIDTH, ITEM_HEIGHT);
        }

		public void onStart(int actionPointer) {
		}

		public void onStop(int actionPointer) {
			mPlayer.stopAllActions();
			
			switch(mLastDirection) {
				case UP:
					mPlayer.setDisplayFrame(mFaceUp);
					break;
				case DOWN:
					mPlayer.setDisplayFrame(mFaceDown);
					break;
				case LEFT:
					mPlayer.setDisplayFrame(mFaceLeft);
					break;
				case RIGHT:
					mPlayer.setDisplayFrame(mFaceRight);
					break;
			}
		}

		public void onUpdate(int actionPointer, float t) {
		}

		public void jDraw() {
			
		}

		public void jOnEnter() {
			
		}

		public void jOnEnterTransitionDidFinish() {
			
		}

		public void jOnExit() {
			// 可以在这里销毁，也可以在director退出时自动销毁
			mAnimUp.autoRelease();
			mAnimDown.autoRelease();
			mAnimLeft.autoRelease();
			mAnimRight.autoRelease();
			mFaceUp.autoRelease();
			mFaceDown.autoRelease();
			mFaceLeft.autoRelease();
			mFaceRight.autoRelease();
		}
	}
}
