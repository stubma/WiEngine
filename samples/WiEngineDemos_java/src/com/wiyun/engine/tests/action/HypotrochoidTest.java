package com.wiyun.engine.tests.action;

import javax.microedition.khronos.opengles.GL10;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.Hypotrochoid;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.INodeVirtualMethods;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Primitives;
import com.wiyun.engine.types.WYHypotrochoidConfig;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;

public class HypotrochoidTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
    
    class MyLayer extends Layer implements INodeVirtualMethods {
    	WYHypotrochoidConfig m_c;
    	WYHypotrochoidConfig m_circle;
    	WYHypotrochoidConfig m_ellipse;

    	
        public MyLayer() {
        	setJavaVirtualMethods(this);
        	setNoDraw(true);
            WYSize s = Director.getInstance().getWindowSize();
            
            m_c = WYHypotrochoidConfig.makeQuad(
            		ResolutionIndependent.resolveDp(100), 
            		ResolutionIndependent.resolveDp(40), 
            		ResolutionIndependent.resolveDp(100), 0, 720, s.width/2, s.height/2);
            addTrace(m_c);
            
            m_ellipse = WYHypotrochoidConfig.makeEllipse(
            		ResolutionIndependent.resolveDp(100), 
            		ResolutionIndependent.resolveDp(30), 0, 720, s.width/2, s.height/2);
            addTrace(m_ellipse);
            
            m_circle = WYHypotrochoidConfig.makeCircle(
            		ResolutionIndependent.resolveDp(80), 0, 720, s.width/2, s.height/2);
            addTrace(m_circle);
        }
        
        private void addTrace(WYHypotrochoidConfig c) {
        	Sprite sprite = Sprite.make(R.drawable.grossini);
        	sprite.setScale(0.2f);
            addChild(sprite);
            
            Hypotrochoid a = (Hypotrochoid)Hypotrochoid.make(6, c).autoRelease();
            a.setAutoRotate(true, 90);
			/*
			 * 如果不启用auto rotate, 可以指定pin point, 注意pin point只在auto rotate为false的时候生效
			 * 下面两句取消注释时必须把a.setAutoRotate(true, 90);注释掉才行
			 */
//            a.setPinPoint(DP(100), s.height - DP(100));
//            a.setPinAngleDelta(90);
            Action repeat = (Action)RepeatForever.make(a).autoRelease();
            sprite.runAction(repeat);
        }

		@Override
		public void jDraw() {
        	// draw bezier curve so we can see the node is follow the track
			GL10 gl = Director.getInstance().gl;
        	gl.glColor4f(0, 1, 0, 1);
        	Primitives.drawHypotrochoid(m_c, 100);
        	
        	gl.glColor4f(1, 0, 0, 1);
        	Primitives.drawHypotrochoid(m_ellipse, 100);
        	
        	gl.glColor4f(0, 0, 1, 1);
        	Primitives.drawHypotrochoid(m_circle, 100);

        	gl.glColor4f(1, 1, 1, 1);
		}

		@Override
		public void jOnEnter() {
		}

		@Override
		public void jOnEnterTransitionDidFinish() {
		}

		@Override
		public void jOnExit() {
		}
    }
}
