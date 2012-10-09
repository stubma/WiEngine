package com.wiyun.engine.tests.action;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.actions.SkewTo;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYSize;

public class SkewToTest extends WiEngineTestActivity {
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
            
            SkewTo a1 = (SkewTo)SkewTo.make(2, 0, 90, 0, 0).autoRelease();
            SkewTo a2 = (SkewTo)a1.reverse().autoRelease();
            SkewTo a3 = (SkewTo)SkewTo.make(2, 0, 0, 0, 90).autoRelease();
            SkewTo a4 = (SkewTo)a3.reverse().autoRelease();
            Sequence seq = (Sequence)Sequence.make(a1, a2, a3, a4).autoRelease();
            Action repeat = (Action)RepeatForever.make(seq).autoRelease();
            sprite.runAction(repeat);
        }
    }
}
