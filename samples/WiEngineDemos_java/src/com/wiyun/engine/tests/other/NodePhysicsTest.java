package com.wiyun.engine.tests.other;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Node;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.nodes.Node.IPositionListener;
import com.wiyun.engine.types.WYSize;

public class NodePhysicsTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer implements IPositionListener {
    	private Label mLabel;
    	
        public MyLayer() {
        	Sprite sprite = Sprite.make(R.drawable.grossini);
        	sprite.setVelocity(100, 100);
        	sprite.setAcceleration(100, 100);
        	sprite.setPositionListener(this);
        	addChild(sprite);

            // hint label
        	WYSize s = Director.getInstance().getWindowSize();
            mLabel = Label.make("callback display label", 20);
            mLabel.setPosition(s.width / 2, 100);
            addChild(mLabel);
        }

		public void onPositionChanged(int nodePointer) {
			Node node = Node.from(nodePointer);
			WYSize s = Director.getInstance().getWindowSize();
			float px = node.getPositionX();
			float py = node.getPositionY();
			if(px > s.width || py > s.height) {
				node.setVelocity(-100, -100);
				node.setAcceleration(-100, -100);
			} else if(px < 0 || py < 0) {
				node.setVelocity(100, 100);
				node.setAcceleration(100, 100);
			}
			
			mLabel.setText(String.format("pos: %.1f, %.1f", px, py));
		}
    }
}
