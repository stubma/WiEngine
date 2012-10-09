package com.wiyun.engine.tests.action;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.JumpTo;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYSize;

public class JumpToTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
	    return new MyLayer();
	}

    class MyLayer extends Layer {
        public MyLayer() {
            WYSize s = Director.getInstance().getWindowSize();
        	Sprite sprite = Sprite.make(R.drawable.grossini);
            addChild(sprite);
            sprite.setPosition(60, s.height / 2);
            
            IntervalAction a = (IntervalAction)JumpTo.make(3, sprite.getPositionX(), sprite.getPositionY(), s.width - 60, s.height / 2, 200, 3).autoRelease();
            IntervalAction r = (IntervalAction)a.reverse().autoRelease();
            IntervalAction seq = (IntervalAction)Sequence.make(a, r).autoRelease();
            Action repeat = (Action)RepeatForever.make(seq).autoRelease();
            sprite.runAction(repeat);
        }
    }
}
