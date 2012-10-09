package com.wiyun.engine.tests.gridaction;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.FiniteTimeAction;
import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.actions.grid.ReuseGrid;
import com.wiyun.engine.actions.grid.SplitCols;
import com.wiyun.engine.actions.grid.SplitRows;
import com.wiyun.engine.nodes.ColorLayer;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYGridSize;
import com.wiyun.engine.types.WYSize;

public class SplitRowsColsTest extends WiEngineTestActivity {
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
        	Sprite sprite = Sprite.make(R.drawable.grossini);
            addChild(sprite);
            sprite.setPosition(s.width / 2, s.height / 2);
            sprite.setScale(4);
            
            IntervalAction splitRows = (IntervalAction)SplitRows.make(2, WYGridSize.make(4, 8)).autoRelease();
            IntervalAction splitCols = (IntervalAction)SplitCols.make(2, WYGridSize.make(4, 8)).autoRelease();
            Action a = (Action)RepeatForever.make(
            	(IntervalAction)Sequence.make(splitRows,
            		(FiniteTimeAction)ReuseGrid.make(4).autoRelease(),
            		(IntervalAction)splitRows.reverse().autoRelease(),
            		splitCols,
            		(IntervalAction)splitCols.reverse().autoRelease()).autoRelease()).autoRelease();
            runAction(a);
        }
    }
}
