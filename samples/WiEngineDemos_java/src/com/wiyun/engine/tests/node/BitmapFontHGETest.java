package com.wiyun.engine.tests.node;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.BitmapFontLabel;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.BitmapFont;
import com.wiyun.engine.utils.ResolutionIndependent;

public class BitmapFontHGETest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
        public MyLayer() {
        	WYSize s = Director.getInstance().getWindowSize();
            BitmapFont font = BitmapFont.loadFont(R.raw.bitmapfont);
            BitmapFontLabel label = BitmapFontLabel.make(font,
            		"微云游戏引擎abcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()ABCDEFGHIJKLMNOPQRSTUVWXYZ");
            label.setPosition(s.width / 2, s.height / 2);
            label.setLineWidth(s.width / 2);
            label.setColor(WYColor3B.make(0, 255, 0));
            addChild(label);
            
            BitmapFontLabel chinese = BitmapFontLabel.make(font, "微云 游戏\t引擎微\n云游戏引擎");
        	chinese.setColor(new WYColor3B(255, 255, 0));
        	chinese.setPosition(s.width / 2, ResolutionIndependent.resolveDp(100));
            addChild(chinese);
        }
    }
}
