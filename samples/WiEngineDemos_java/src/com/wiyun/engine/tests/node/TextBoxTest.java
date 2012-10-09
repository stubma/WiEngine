package com.wiyun.engine.tests.node;

import android.graphics.Typeface;
import android.util.Log;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.NinePatchSprite;
import com.wiyun.engine.nodes.TextBox;
import com.wiyun.engine.nodes.TextBox.ITextBoxCallback;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;

public class TextBoxTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends Layer implements ITextBoxCallback {
        public MyLayer() {
            // add label
            WYSize s = Director.getInstance().getWindowSize();
            Label label = Label.make("", 22, Typeface.BOLD);
            label.setColor(new WYColor3B(0, 0, 0));
            
    		// sprite for button
    		NinePatchSprite normal = NinePatchSprite.make(Texture2D.makePNG(R.drawable.textbox_normal), 
    				ResolutionIndependent.resolve(WYRect.make(11, 21, 1, 1)));
    		NinePatchSprite pressed = NinePatchSprite.make(Texture2D.makePNG(R.drawable.textbox_pressed), 
    				ResolutionIndependent.resolve(WYRect.make(11, 21, 1, 1)));
    		NinePatchSprite focused = NinePatchSprite.make(Texture2D.makePNG(R.drawable.textbox_focused), 
    				ResolutionIndependent.resolve(WYRect.make(11, 21, 1, 1)));
    		normal.setContentSize(DP(280), DP(42));
    		pressed.setContentSize(DP(280), DP(42));
    		focused.setContentSize(DP(280), DP(42));
            
        	// 通过addContentView添加一个EditText到场景中，它实际上是盖在WYGLSurfaceView上面
    		TextBox box = TextBox.make(normal, pressed, null, focused, label);
    		box.setPosition(s.width / 2, s.height / 2);
            box.setTitle("Input something!");
            box.setMessage("试试中文的提示怎么样");
            box.setPositiveButton("想修改就点我");
            box.setNegativeButton("Oh No!");
            box.setPadding(DP(10), DP(3), DP(10), DP(6));
    		box.setCallback(this);
            addChild(box);
        }
        
        private float DP(float v) {
        	return ResolutionIndependent.resolveDp(v);
        }

		@Override
		public void onBeginEditing(int pointer) {
			Log.d("libwiengine", "onBeginEditing");
		}

		@Override
		public void onEndEditing(int pointer) {
			TextBox box = TextBox.from(pointer);
			Log.d("libwiengine", "onEndEditing: " + box.getText());
		}

		@Override
		public void onTextChanged(int pointer) {
			TextBox box = TextBox.from(pointer);
			Log.d("libwiengine", "onTextChanged: " + box.getText());
		}
    }
}
