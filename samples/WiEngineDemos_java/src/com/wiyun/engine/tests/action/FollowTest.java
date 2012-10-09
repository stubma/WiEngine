package com.wiyun.engine.tests.action;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.Follow;
import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.MoveTo;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.nodes.TiledSprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;

public class FollowTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
	    return new MyLayer();
	}

    class MyLayer extends Layer {
        public MyLayer() {
            WYSize s = Director.getInstance().getWindowSize();
        	Sprite sprite = Sprite.make(R.drawable.grossini);
            addChild(sprite);
            float startx = ResolutionIndependent.resolveDp(60);
            float y = s.height / 2;
            float endx = s.width + ResolutionIndependent.resolveDp(100);
            sprite.setPosition(startx, y);
            
            IntervalAction move = (IntervalAction)MoveTo.make(3, startx, y, endx, y).autoRelease();
            IntervalAction back = (IntervalAction)move.reverse().autoRelease();
            IntervalAction seq = (IntervalAction)Sequence.make(move, back).autoRelease();
            Action repeat = (Action)RepeatForever.make(seq).autoRelease();
            sprite.runAction(repeat);
            
            Follow fAction = Follow.make(sprite, 0, 0, (int)(s.width + ResolutionIndependent.resolveDp(160)), (int)(s.height));
            runAction(fAction);
            fAction.autoRelease();
            
            // background layer: another image
			TiledSprite ts = TiledSprite.make(Texture2D.makePNG(R.drawable.tiled_bg));
			ts.setContentSize(s.width, ResolutionIndependent.resolveDp(115));
			ts.setTileDirection(true, false);
			ts.setAnchor(0, 0);
			ts.setPosition(0, 100);
			addChild(ts);
        }
    }
}
