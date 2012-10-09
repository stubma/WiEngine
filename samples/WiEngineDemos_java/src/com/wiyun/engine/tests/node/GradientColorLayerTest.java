/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
package com.wiyun.engine.tests.node;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.CallFunc;
import com.wiyun.engine.actions.DelayTime;
import com.wiyun.engine.actions.FiniteTimeAction;
import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.nodes.GradientColorLayer;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYColor4B;

public class GradientColorLayerTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends GradientColorLayer {
        public MyLayer() {
        	super(new WYColor4B(0, 60, 90, 255), new WYColor4B(0, 15, 46, 255), 0);
        	
        	/*
        	 * 这里放一个delaytime动作，因为callfunc是瞬间动作，不停的执行那太快了
        	 */
    		IntervalAction a = (IntervalAction)Sequence.make((FiniteTimeAction)DelayTime.make(0.03f).autoRelease(),
    				(FiniteTimeAction)CallFunc.make(this, "changeLayer").autoRelease()).autoRelease();
    		Action repeat = (Action)RepeatForever.make(a).autoRelease();
    		runAction(repeat);
        }
        
    	public void changeLayer() {
    		setDegree(getDegree() + 1);
    	}
    }
}
