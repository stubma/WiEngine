package com.wiyun.engine.tests.other;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Scheduler;
import com.wiyun.engine.nodes.Timer;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class SchedulerTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
    	Label mLabel1;
    	Label mLabel2;
    	Label mLabel3;
    	TargetSelector mSelector1;
    	TargetSelector mSelector2;
    	
        public MyLayer() {
        	WYSize s = Director.getInstance().getWindowSize();
        	mLabel1 = Label.make("Lable1: 0");
        	mLabel1.setPosition(s.width / 2, s.height / 2 + 80);
        	addChild(mLabel1);
        	
        	mLabel2 = Label.make("Label2: 0");
        	mLabel2.setPosition(s.width / 2, s.height / 2);
        	addChild(mLabel2);
        	
        	mLabel3 = Label.make("Label3: 0");
        	mLabel3.setPosition(s.width / 2, s.height / 2 - 80);
        	addChild(mLabel3);
        	
        	// 创建selector, 通过scheduler调用的selector有一个特殊要求，第一个参数必须是float, 表示上一次
        	// 调用到现在过去的时间，由于在创建selector时这个参数无法确定，因此传入0值就可以，调度器会自动维护的。
        	mSelector1 = new TargetSelector(this, "updateLabel(float,int)", new Object[] { 0f, 1 });
        	Timer t = new Timer(mSelector1, 1f);
        	Scheduler.getInstance().schedule(t);
        	
        	// 每10帧调用一次updateLabel2，来更新第二个label
        	mSelector2 = new TargetSelector(this, "updateLabel2(float,int)", new Object[] { 0f, 1 });
        	t = new Timer(mSelector2, 10);
        	Scheduler.getInstance().schedule(t);
        	
        	// 只更新Label 3一次, 延迟2秒
        	scheduleOnce(new TargetSelector(this, "updateLabel3Once(float)", new Object[] { 0f }), 2f);
        }
        
        public void updateLabel(float delta, int v) {
        	mLabel1.setText(String.format("Label1: %d", v));
        	mSelector1.setArgument(1, v + 1);
        }
        
        public void updateLabel2(float delta, int v) {
        	mLabel2.setText(String.format("Label2: %d", v));
        	mSelector2.setArgument(1, v + 1);
        }
        
        public void updateLabel3Once(float delta) {
        	mLabel3.setText("Label3: Once");
        }
    }
}
