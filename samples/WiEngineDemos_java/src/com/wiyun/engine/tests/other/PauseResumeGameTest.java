package com.wiyun.engine.tests.other;

import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.MoveBy;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.RotateBy;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;

public class PauseResumeGameTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
	    return new MyLayer();
	}
	
    class MyLayer extends Layer {
    	Sprite mSprite;
    	Label mLabel;
    	
        public MyLayer() {
        	// create sprite
            WYSize s = Director.getInstance().getWindowSize();
            mSprite = Sprite.make(R.drawable.grossini);
            addChild(mSprite);
            
            // execute rotate action
            IntervalAction a = (IntervalAction)RotateBy.make(2, 360).autoRelease();
            RepeatForever repeat1 = (RepeatForever)RepeatForever.make(a).autoRelease();
            repeat1.setTag(100);
            mSprite.runAction(repeat1);
            
            // execute move action
            MoveBy move = (MoveBy)MoveBy.make(2, s.width - 120, 0).autoRelease();
            MoveBy back = (MoveBy)move.reverse().autoRelease();
            Sequence seq = (Sequence)Sequence.make(move, back).autoRelease();
            RepeatForever repeat = (RepeatForever)RepeatForever.make(seq).autoRelease();
            mSprite.setPosition(60, s.height / 2);
            mSprite.runAction(repeat);
            
            // create hint label
            mLabel = Label.make("Paused");
            mLabel.setPosition(s.width / 2, DP(100));
            mLabel.setVisible(false);
            addChild(mLabel);
            
            // enable touch
            setTouchEnabled(true);
        }
        
        @Override
        public boolean wyTouchesBegan(MotionEvent event) {
        	Director d = Director.getInstance();
        	if(d.isUIPaused()) {
        		mLabel.setVisible(false);
        		d.resumeUI();
        	} else {
        		mLabel.setVisible(true);
        		d.pauseUI();
        	}
        	
        	return super.wyTouchesBegan(event);
        }
        
        private float DP(float v) {
        	return ResolutionIndependent.resolveDp(v);
        }
    }
}
