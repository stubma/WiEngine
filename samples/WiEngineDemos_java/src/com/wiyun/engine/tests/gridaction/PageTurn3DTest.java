package com.wiyun.engine.tests.gridaction;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.FiniteTimeAction;
import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.actions.grid.PageTurn3D;
import com.wiyun.engine.actions.grid.ReuseGrid;
import com.wiyun.engine.nodes.ColorLayer;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYGridSize;
import com.wiyun.engine.types.WYSize;

public class PageTurn3DTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
    
	@Override
	protected String checkPrecondition() {
		return Director.getInstance().isExtensionSupported("GL_OES_framebuffer_object")
			? null
			: "Your device doesn't support frame buffer object, this demo will not work";
	}

    class MyLayer extends ColorLayer {
        public MyLayer() {
        	super(new WYColor4B(0, 0, 255, 255));
            WYSize s = Director.getInstance().getWindowSize();
        	Sprite sprite = Sprite.make(R.drawable.grossini);
            addChild(sprite);
            sprite.setPosition(s.width / 2, s.height / 2);
            sprite.setScale(4);
            
            IntervalAction a = (IntervalAction)PageTurn3D.make(2f, WYGridSize.make(12, 20)).autoRelease();
            IntervalAction r = (IntervalAction)a.reverse().autoRelease();
            IntervalAction seq = (IntervalAction)Sequence.make(a, (FiniteTimeAction)ReuseGrid.make(2).autoRelease(), r).autoRelease();
            Action repeat = (Action)RepeatForever.make(seq).autoRelease();
            runAction(repeat);
        }
    }
}
