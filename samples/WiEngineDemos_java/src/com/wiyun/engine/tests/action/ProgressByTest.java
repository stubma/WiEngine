package com.wiyun.engine.tests.action;

import static com.wiyun.engine.utils.Utilities.rand;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.ProgressBy;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.ProgressTimer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;

public class ProgressByTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
	    return new MyLayer();
	}
	
	private static float ITEM_WIDTH = 0;
	private static float ITEM_HEIGHT = 0;

    class MyLayer extends Layer {
        public MyLayer() {
            ITEM_WIDTH = ResolutionIndependent.resolveDp(85);
            ITEM_HEIGHT = ResolutionIndependent.resolveDp(121);
            WYSize s = Director.getInstance().getWindowSize();
            
        	ProgressTimer left = ProgressTimer.make(R.drawable.grossini);
        	left.setStyle(ProgressTimer.RADIAL_CW);
        	addChild(left);
        	left.setPosition(100, s.height / 2);
        	left.runAction((Action)ProgressBy.make(2, 100).autoRelease());
        	
            int idx = rand(14);
            float x = (idx % 5) * ITEM_WIDTH;
            float y = (idx / 5) * ITEM_HEIGHT;
            Texture2D tex = Texture2D.makePNG(R.drawable.grossini_dance_atlas);
            tex.autoRelease();
            Sprite sprite = Sprite.make(tex, WYRect.make(x, y, ITEM_WIDTH, ITEM_HEIGHT));
            sprite.autoRelease();
            ProgressTimer right = ProgressTimer.make(sprite);
        	right.setStyle(ProgressTimer.VERTICAL_BAR_BT);
        	addChild(right);
        	right.setPosition(s.width - 100, s.height / 2);
        	right.runAction((Action)ProgressBy.make(2, 100).autoRelease());
        }
    }
}
