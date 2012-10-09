package com.wiyun.engine.tests.action;

import java.util.Arrays;
import java.util.Date;

import android.widget.Toast;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.CallFunc;
import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.utils.TargetSelector;

public class CallFuncTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
	    return new MyLayer();
	}
	
    class MyLayer extends Layer {
        public MyLayer() {
        	CallFunc call1 = (CallFunc)CallFunc.make(this, "func1").autoRelease();
        	CallFunc call2 = (CallFunc)CallFunc.make(new TargetSelector(this, "func2(int)", new Object[] { 100 })).autoRelease();
        	CallFunc call3 = (CallFunc)CallFunc.make(new TargetSelector(this, "func3(int,Object)", new Object[] { 200, "test" })).autoRelease();
        	CallFunc call4 = (CallFunc)CallFunc.make(new TargetSelector(this, "func4(int,String...)", new Object[] { 300, new String[] { "test1", "test2", "test3" }})).autoRelease();
        	CallFunc call5 = (CallFunc)CallFunc.make(new TargetSelector(this, "func5(int,String,java.util.Date)", new Object[] { 400, "test", new Date(2010, 0, 1) })).autoRelease();
        	IntervalAction seq = (IntervalAction)Sequence.make(call1, call2, call3, call4, call5).autoRelease();
        	runAction(seq);
        }
        
        public void func1() {
        	runOnUiThread(new Runnable() {
				public void run() {
					Toast.makeText(Director.getInstance().getContext(), "func1 is called", Toast.LENGTH_SHORT).show();
				}
			});
        }
        
        public void func2(final int value) {
        	runOnUiThread(new Runnable() {
        		public void run() {
        			Toast.makeText(Director.getInstance().getContext(), "func2 is called, value is: " + value, Toast.LENGTH_SHORT).show();
        		}
        	});
        }
        
        public void func3(final int value, final Object str) {
        	runOnUiThread(new Runnable() {
        		public void run() {
        			Toast.makeText(Director.getInstance().getContext(), "func3 is called, value is: " + value + ", string is: " + str,
        				Toast.LENGTH_SHORT).show();
        		}
        	});
        }
        
        public void func4(final int value, final String... str) {
        	runOnUiThread(new Runnable() {
        		public void run() {
        			Toast.makeText(Director.getInstance().getContext(), "func4 is called, value is: " + value + ", string is: " + Arrays.toString(str),
        				Toast.LENGTH_SHORT).show();
        		}
        	});
        }
        
        public void func5(final int value, final String str, final Date date) {
        	runOnUiThread(new Runnable() {
        		public void run() {
        			Toast.makeText(Director.getInstance().getContext(), "func4 is called, value is: " + value + ", string is: " + str + ", date is " + date,
        				Toast.LENGTH_SHORT).show();
        		}
        	});
        }
    }
}
