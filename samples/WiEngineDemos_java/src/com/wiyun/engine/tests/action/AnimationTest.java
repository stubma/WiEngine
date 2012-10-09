package com.wiyun.engine.tests.action;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.Animate;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.nodes.Animation;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.nodes.Animation.IAnimationCallback;
import com.wiyun.engine.types.WYSize;

public class AnimationTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer implements IAnimationCallback {
    	private Label mLabel;
    	
        public MyLayer() {
            WYSize s = Director.getInstance().getWindowSize();
            
            // add sprite
            Sprite sprite = Sprite.make(R.drawable.grossini);
            addChild(sprite);
            sprite.setPosition(s.width / 2, s.height / 2);
            
            // create animation
            Animation anim = (Animation)new Animation(0, 0.2f, 
            	R.drawable.grossini_dance_01,
            	R.drawable.grossini_dance_02,
            	R.drawable.grossini_dance_03,
            	R.drawable.grossini_dance_04,
            	R.drawable.grossini_dance_05,
            	R.drawable.grossini_dance_06,
            	R.drawable.grossini_dance_07,
            	R.drawable.grossini_dance_08,
            	R.drawable.grossini_dance_09,
            	R.drawable.grossini_dance_10,
            	R.drawable.grossini_dance_11,
            	R.drawable.grossini_dance_12,
            	R.drawable.grossini_dance_13,
            	R.drawable.grossini_dance_14).autoRelease();
            anim.setCallback(this);
            
            Animate a = (Animate)Animate.make(anim).autoRelease();
            sprite.runAction((Action)RepeatForever.make(a).autoRelease());
            
            // hint label
            mLabel = Label.make("callback display label", 20);
            mLabel.setPosition(s.width / 2, 100);
            addChild(mLabel);
        }

		public void onAnimationEnded(int animPointer) {
			mLabel.setText("animation ended");
		}

		public void onAnimationFrameChanged(int animPointer, int index) {
			mLabel.setText("frame changed: " + index);
		}
    }
}
