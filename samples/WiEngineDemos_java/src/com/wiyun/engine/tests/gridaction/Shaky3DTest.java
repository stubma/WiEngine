package com.wiyun.engine.tests.gridaction;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.FiniteTimeAction;
import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.actions.grid.ReuseGrid;
import com.wiyun.engine.actions.grid.Shaky3D;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYGridSize;
import com.wiyun.engine.types.WYSize;

public class Shaky3DTest extends WiEngineTestActivity {
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
	
    class MyLayer extends Layer {
        public MyLayer() {
            WYSize s = Director.getInstance().getWindowSize();
        	Sprite sprite = Sprite.make(R.drawable.grossini);
            addChild(sprite);
            sprite.setPosition(s.width / 2, s.height / 2);
            sprite.setScale(4);
            
            IntervalAction a = (IntervalAction)Sequence.make(
            		(IntervalAction)Shaky3D.make(1200, WYGridSize.make(12, 20), 5, false).autoRelease(),
            		(FiniteTimeAction)ReuseGrid.make(1).autoRelease()).autoRelease();
            runAction((Action)RepeatForever.make(a).autoRelease());
        }
    }
}
