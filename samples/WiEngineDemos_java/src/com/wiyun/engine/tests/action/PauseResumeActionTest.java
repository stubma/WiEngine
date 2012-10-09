package com.wiyun.engine.tests.action;

import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.MoveBy;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.RotateBy;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYSize;

public class PauseResumeActionTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
	    return new MyLayer();
	}
	
    class MyLayer extends Layer {
    	Sprite mSprite;
    	
        public MyLayer() {
    		/*
    		 * 我们同时在sprite上运行两个动作, 点击屏幕时暂停旋转动作, 再点击恢复
    		 * 为什么不用Spawn来包装两个动作呢? 因为暂停动作对于组合类中的动作
    		 * 是无效的
    		 */
        	
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
            
            // enable touch
            setTouchEnabled(true);
        }
        
        @Override
        public boolean wyTouchesBegan(MotionEvent event) {
        	Action action = Action.from(mSprite.getActionPointer(100));
        	if(action.isPaused())
        		mSprite.resumeAction(100);
        	else
        		mSprite.pauseAction(100);
        	return super.wyTouchesBegan(event);
        }
    }
}
