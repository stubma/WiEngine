package com.wiyun.engine.tests.action;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Animate;
import com.wiyun.engine.nodes.Animation;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.nodes.Animation.IAnimationCallback;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;

public class AtlasAnimationTest extends WiEngineTestActivity {
    private static float ITEM_WIDTH = 0;
    private static float ITEM_HEIGHT = 0;
    
    @Override
    protected Layer createLayer() {
    	return new MyLayer();
    }
    
    class MyLayer extends Layer implements IAnimationCallback {
    	public static final int TAG_SPRITE_MANAGER = 1;
    	
    	private Label mLabel;
    	
        public MyLayer() {
            // set width and height
            ITEM_WIDTH = ResolutionIndependent.resolveDp(85);
            ITEM_HEIGHT = ResolutionIndependent.resolveDp(121);

            WYSize s = Director.getInstance().getWindowSize();

			Texture2D tex = Texture2D.makePNG(R.drawable.grossini_dance_atlas);

            // add sprite
            Sprite sprite = Sprite.make(tex, WYRect.make(0, 0, ITEM_WIDTH, ITEM_HEIGHT));
            addChild(sprite);
            sprite.setPosition(s.width / 2, s.height / 2);
            
            // create animation and add it to atlas sprite
            Animation anim = new Animation(0);
            anim.addFrame(0.2f, 
            	frameAt(0, 0),
            	frameAt(1, 0),
            	frameAt(2, 0),
            	frameAt(3, 0),
            	frameAt(4, 0),
            	frameAt(0, 1),
            	frameAt(1, 1),
            	frameAt(2, 1),
            	frameAt(3, 1),
            	frameAt(4, 1),
            	frameAt(0, 2),
            	frameAt(1, 2),
            	frameAt(2, 2),
            	frameAt(3, 2));
            anim.setCallback(this);
            
            Animate a = (Animate)Animate.make(anim).autoRelease();
            sprite.runAction(a);
            
            // hint label
            mLabel = Label.make("callback display label", 20);
            mLabel.setPosition(s.width / 2, 100);
            addChild(mLabel);
        }
        
        private WYRect frameAt(int x, int y) {
        	return WYRect.make(x * ITEM_WIDTH, y * ITEM_HEIGHT, ITEM_WIDTH, ITEM_HEIGHT);
        }
        
		public void onAnimationEnded(int animPointer) {
			mLabel.setText("animation ended");
		}

		public void onAnimationFrameChanged(int animPointer, int index) {
			mLabel.setText("frame changed: " + index);
		}
    }
}
