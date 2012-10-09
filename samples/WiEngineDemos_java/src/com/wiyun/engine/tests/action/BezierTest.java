package com.wiyun.engine.tests.action;

import javax.microedition.khronos.opengles.GL10;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.Bezier;
import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.INodeVirtualMethods;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Primitives;
import com.wiyun.engine.types.WYBezierConfig;
import com.wiyun.engine.types.WYSize;

public class BezierTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
    
    class MyLayer extends Layer implements INodeVirtualMethods {
    	WYBezierConfig m_config;
    	
        public MyLayer() {
        	setJavaVirtualMethods(this);
        	setNoDraw(true);
        	
            WYSize s = Director.getInstance().getWindowSize();
        	Sprite sprite = Sprite.make(R.drawable.grossini);
            addChild(sprite);
            sprite.setPosition(60, s.height / 2);
            
            m_config = WYBezierConfig.makeCubic(sprite.getPositionX(), 
            		sprite.getPositionY(), 
            		s.width - 60, 
            		s.height / 2, 
            		s.width / 2, 
            		s.height * 3 / 4, 
            		s.width / 2, 
            		s.height / 4);
            Bezier a = (Bezier)Bezier.make(3, m_config).autoRelease();
            a.setAutoRotate(true, 90);
			/*
			 * 如果不启用auto rotate, 可以指定pin point, 注意pin point只在auto rotate为false的时候生效
			 * 下面两句取消注释时必须把a.setAutoRotate(true, 90);注释掉才行
			 */
//            a.setPinPoint(DP(100), s.height - DP(100));
//            a.setPinAngleDelta(90);
            IntervalAction r = (IntervalAction)a.reverse().autoRelease();
            IntervalAction seq = (IntervalAction)Sequence.make(a, r).autoRelease();
            Action repeat = (Action)RepeatForever.make(seq).autoRelease();
            sprite.runAction(repeat);
        }

		@Override
		public void jDraw() {
        	// draw bezier curve so we can see the node is follow the track
			GL10 gl = Director.getInstance().gl;
        	gl.glColor4f(0, 1, 0, 1);
        	Primitives.drawBezier(m_config, 30);

        	// draw bezier start, end, and control points
        	gl.glColor4f(1, 0, 0, 1);
        	gl.glPointSize(5);
        	Primitives.drawPoint(m_config.startX, m_config.startY);
        	Primitives.drawPoint(m_config.cp1X, m_config.cp1Y);
        	Primitives.drawPoint(m_config.cp2X, m_config.cp2Y);
        	Primitives.drawPoint(m_config.endX, m_config.endY);

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
