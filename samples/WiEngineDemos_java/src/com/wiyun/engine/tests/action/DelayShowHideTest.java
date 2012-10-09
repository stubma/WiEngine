package com.wiyun.engine.tests.action;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.DelayTime;
import com.wiyun.engine.actions.FiniteTimeAction;
import com.wiyun.engine.actions.Hide;
import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.actions.Show;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYSize;

public class DelayShowHideTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
	
    class MyLayer extends Layer {
        public MyLayer() {
            WYSize s = Director.getInstance().getWindowSize();
        	Sprite sprite = Sprite.make(R.drawable.grossini);
            addChild(sprite);
            sprite.setPosition(s.width / 2, s.height / 2);
            
            IntervalAction seq = (IntervalAction)Sequence.make(
            		(FiniteTimeAction)DelayTime.make(1).autoRelease(),
            		(FiniteTimeAction)Hide.make().autoRelease(),
            		(FiniteTimeAction)DelayTime.make(1).autoRelease(),
            		(FiniteTimeAction)Show.make().autoRelease()).autoRelease();
            Action repeat = (Action)RepeatForever.make(seq).autoRelease();
            sprite.runAction(repeat);
        }
    }
}
