package com.wiyun.engine.tests.gridaction;

import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.actions.grid.StopGrid;
import com.wiyun.engine.actions.grid.Suck;
import com.wiyun.engine.nodes.ColorLayer;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYGridSize;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;

public class SuckTest extends WiEngineTestActivity {
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
        	Sprite sprite = Sprite.make(R.drawable.background);
            addChild(sprite);
            sprite.setPosition(s.width / 2, s.height / 2);
            
            setTouchEnabled(true);
        }
        
        @Override
        public boolean wyTouchesBegan(MotionEvent event) {
        	if(getGrid() == null) {
            	WYPoint loc = Director.getInstance().convertToGL(event.getX(), event.getY());
                Suck suck = Suck.make(0.6f, WYGridSize.make(20, 20), loc);
                suck.autoRelease();
                StopGrid stop = StopGrid.make();
                stop.autoRelease();
                Sequence s = Sequence.make(suck, stop);
                s.autoRelease();
                runAction(s);
        	}
            
        	return super.wyTouchesBegan(event);
        }
    }
}
