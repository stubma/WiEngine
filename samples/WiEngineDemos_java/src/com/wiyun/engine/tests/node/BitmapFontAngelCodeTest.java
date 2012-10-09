package com.wiyun.engine.tests.node;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.BitmapFontLabel;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.BitmapFont;

public class BitmapFontAngelCodeTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
        public MyLayer() {
        	WYSize s = Director.getInstance().getWindowSize();
            BitmapFont font = BitmapFont.loadFont(R.raw.bitmapfont2_angelcode_txt, BitmapFont.BFF_ANGELCODE_TXT);
            BitmapFontLabel label = BitmapFontLabel.make(font, "微 云\t游戏\n引擎");
            label.setPosition(s.width / 2, s.height * 3 / 4);
            addChild(label);
            
            BitmapFont font2 = BitmapFont.loadFont(R.raw.bitmapfont2_angelcode_xml, BitmapFont.BFF_ANGELCODE_XML);
            BitmapFontLabel label2 = BitmapFontLabel.make(font2, "Test Label");
            label2.setPosition(s.width / 2, s.height / 2);
            addChild(label2);
            
            BitmapFont font3 = BitmapFont.loadFont(R.raw.bitmapfont3, BitmapFont.BFF_ANGELCODE_XML);
            BitmapFontLabel label3 = BitmapFontLabel.make(font3, "微云游戏引擎Test");
            label3.setPosition(s.width / 2, s.height / 4);
            addChild(label3);
        }
    }
}
