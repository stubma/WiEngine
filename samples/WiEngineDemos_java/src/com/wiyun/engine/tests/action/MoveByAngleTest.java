package com.wiyun.engine.tests.action;

import javax.microedition.khronos.opengles.GL10;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.MoveByAngle;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.INodeVirtualMethods;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Primitives;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;

public class MoveByAngleTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
	    return new MyLayer();
	}
	
    class MyLayer extends Layer implements INodeVirtualMethods {
    	Sprite mSprite;
    	
        public MyLayer() {
        	setJavaVirtualMethods(this);
        	setNoDraw(true);
        	
            WYSize s = Director.getInstance().getWindowSize();
        	mSprite = Sprite.make(R.drawable.grossini);
            addChild(mSprite, -1);
            mSprite.setPosition(60, s.height / 2);
            
            int velocity = (int)(s.width - 60 * 2)/2;
            MoveByAngle move = (MoveByAngle)MoveByAngle.make(2, 0, velocity).autoRelease();
            move.setPinPoint(DP(100), s.height - DP(100));
            move.setPinAngleDelta(90);
            MoveByAngle back = (MoveByAngle)move.reverse().autoRelease();
            Sequence seq = (Sequence)Sequence.make(move, back).autoRelease();
            RepeatForever repeat = (RepeatForever)RepeatForever.make(seq).autoRelease();
            mSprite.runAction(repeat);
        }
        
        private float DP(float v) {
        	return ResolutionIndependent.resolveDp(v);
        }

		@Override
		public void jDraw() {
        	// draw pin point
			WYSize s = Director.getInstance().getWindowSize();
			GL10 gl = Director.getInstance().gl;
        	gl.glColor4f(1, 0, 0, 1);
        	gl.glPointSize(5);
        	Primitives.drawPoint(DP(100), s.height - DP(100));

        	// draw anchor point
        	WYPoint anchor = mSprite.convertToWorldSpace(mSprite.getAnchorPointX(), mSprite.getAnchorPointY());
        	Primitives.drawPoint(anchor.x, anchor.y);

        	// draw line between pin point and anchor point
        	gl.glColor4f(0, 1, 0, 1);
        	Primitives.drawDashLine(DP(100), s.height - DP(100), anchor.x, anchor.y, 5);
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
