package com.wiyun.engine.tests.action;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.Blink;
import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYSize;

public class BlinkTest extends WiEngineTestActivity {
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
            
            IntervalAction a = (IntervalAction)Blink.make(1, 2).autoRelease();
            Action repeat = (Action)RepeatForever.make(a).autoRelease();
            sprite.runAction(repeat);
        }
    }
}
