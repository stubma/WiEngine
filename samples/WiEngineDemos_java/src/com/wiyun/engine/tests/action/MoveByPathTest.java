package com.wiyun.engine.tests.action;

import java.nio.FloatBuffer;

import javax.microedition.khronos.opengles.GL10;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.MoveByPath;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.INodeVirtualMethods;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Primitives;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;

public class MoveByPathTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
	    return new MyLayer();
	}

    class MyLayer extends Layer implements INodeVirtualMethods {
    	MoveByPath mMove;
    	FloatBuffer mFB;
    	
        public MyLayer() {
        	setJavaVirtualMethods(this);
        	setNoDraw(true);
        	
            WYSize s = Director.getInstance().getWindowSize();
        	Sprite sprite = Sprite.make(R.drawable.grossini);
            addChild(sprite);
            sprite.setPosition(DP(30), s.height / 2);
            
            MoveByPath move = MoveByPath.make();
            mMove = move;
            move.autoRelease();
            move.setAutoRotate(true, 90);
			/*
			 * 如果不启用auto rotate, 可以指定pin point, 注意pin point只在auto rotate为false的时候生效
			 * 下面两句取消注释时必须把move.setAutoRotate(true, 90);注释掉才行
			 */
//            move.setPinPoint(DP(100), s.height - DP(100));
//            move.setPinAngleDelta(90);
            move.addPoint(DP(30), s.height / 2, 0);
			move.addPoint(s.width / 2, s.height / 2, 0.5f);
			move.addPoint(s.width / 2, s.height - DP(30), 1.f);
			move.addPoint(s.width - DP(30), s.height - DP(30), 2.f);
			move.addPoint(s.width - DP(30), DP(30), 3.f);
            
            IntervalAction back = (IntervalAction)move.reverse().autoRelease();
            IntervalAction seq = (IntervalAction)Sequence.make(move, back).autoRelease();
            Action repeat = (Action)RepeatForever.make(seq).autoRelease();
            sprite.runAction(repeat);
        }
        
        private float DP(float v) {
        	return ResolutionIndependent.resolveDp(v);
        }

		@Override
		public void jDraw() {
			float[] points = mMove.getPoints();
			GL10 gl = Director.getInstance().gl;
        	gl.glColor4f(0, 1, 0, 1);
        	Primitives.drawDashPath(points, 5);
        	
        	gl.glColor4f(1, 0, 0, 1);
        	gl.glPointSize(5);
        	Primitives.drawPoints(points);

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
