package com.wiyun.engine.tests.action;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action.Callback;
import com.wiyun.engine.actions.ClipIn;
import com.wiyun.engine.actions.ClipOut;
import com.wiyun.engine.actions.RotateBy;
import com.wiyun.engine.nodes.Button;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;
import com.wiyun.engine.utils.TargetSelector;

public class ClipInOutTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
	    return new MyLayer();
	}
	
    class MyLayer extends Layer implements Callback {
    	boolean m_expanded;
    	boolean m_toggling;
    	Button m_button;
    	Sprite m_sprite;
    	
        public MyLayer() {
        	WYSize s = Director.getInstance().getWindowSize();
    		Sprite normal = Sprite.make(Texture2D.makePNG(R.drawable.icon));
    		m_button = Button.make(normal, null, null, null, null, new TargetSelector(this, "onToggle(float)", new Object[] { 0f }));
    		m_button.setPosition(DP(40), s.height / 2);
    		addChild(m_button);

    		m_sprite = Sprite.make(Texture2D.makeJPG(R.drawable.test_jpg));
    		m_sprite.setAnchor(0, 0.5f);
    		m_sprite.setPosition(m_button.getOriginX() + m_button.getWidth(), s.height / 2);
    		m_sprite.setClipRect(WYRect.makeZero(), true);
    		addChild(m_sprite);
        }
        
        float DP(float v) {
        	return ResolutionIndependent.resolveDp(v);
        }
        
        public void onToggle(float delta) {
    		if(m_toggling)
    			return;

    		if(m_expanded) {
    			m_expanded = false;
    			m_toggling = true;

    			ClipOut clip = ClipOut.make(0.5f, ClipOut.RIGHT_TO_LEFT);
    			clip.autoRelease();
    			m_sprite.runAction(clip);
    			RotateBy rotate = RotateBy.make(0.5f, -90);
    			rotate.setCallback(this);
    			rotate.autoRelease();
    			m_button.runAction(rotate);
    		} else {
    			m_expanded = true;
    			m_toggling = true;

    			ClipIn clip = ClipIn.make(0.5f, ClipIn.LEFT_TO_RIGHT);
    			clip.autoRelease();
    			m_sprite.runAction(clip);
    			RotateBy rotate = RotateBy.make(0.5f, 90);
    			rotate.setCallback(this);
    			rotate.autoRelease();
    			m_button.runAction(rotate);
    		}
        }

		@Override
		public void onStart(int actionPointer) {
		}

		@Override
		public void onStop(int actionPointer) {
			m_toggling = false;
		}

		@Override
		public void onUpdate(int actionPointer, float t) {
		}
    }
}
