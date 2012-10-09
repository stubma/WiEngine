package com.wiyun.engine.tests.other;

import android.os.Environment;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.RotateBy;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Menu;
import com.wiyun.engine.nodes.MenuItemLabel;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.opengl.TextureManager;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;

public class ScreenshotTest extends WiEngineTestActivity {
	private MyLayer mLayer;
	private Sprite mScreenshotSprite;
	
	@Override
	protected Layer createLayer() {
		mLayer = new MyLayer();
		return mLayer;
	}

	@Override
	protected String checkPrecondition() {
		String t = Environment.getExternalStorageState();
		if(!Environment.MEDIA_MOUNTED.equals(t)) {
			return "This demo requires a SD card";
		} else {
			return null;
		}
	}
	
	@Override
	public void onDirectorScreenCaptured(String path) {
    	// 之前截屏过的贴图应该已经在缓冲中, 所以先删掉缓冲中的贴图, 由于这个贴图是从文件系统中载入的, 它的路径就是它的key
    	// 截屏可以生成png或者jpg格式, 这是根据传入的路径来自动决定的, 如果想存为jpg, 就
    	// 改成screenshot.jpg或者screenshot.jpeg即可
		TextureManager.getInstance().removeTexture("/sdcard/WiEngine/screenshot.png");
		
		// 从新的截图中创建贴图对象, texture2d对象其实不调用autoRelease也没事, 为了风格统一, 调用一下无妨
    	Texture2D tex = Texture2D.makeFilePNG("/sdcard/WiEngine/screenshot.png");
    	tex.autoRelease();
    	
    	// 创建新的截图sprite, 添加到屏幕下方
    	// 这个sprite设置了自动拉伸, 因此看起来是缩小了, 为了看的清楚一些, 这个截图渲染时用红色
    	WYSize s = Director.getInstance().getWindowSize();
    	mScreenshotSprite = Sprite.make(tex);
    	mScreenshotSprite.setContentSize(s.width * 0.4f, s.height * 0.4f);
    	mScreenshotSprite.setAutoFit(true);
    	mScreenshotSprite.setAnchor(0.5f, 0.f);
    	mScreenshotSprite.setPosition(s.width / 2, 0);
    	mScreenshotSprite.setColor(new WYColor3B(255, 0, 0));
    	mScreenshotSprite.autoRelease();
    	mLayer.addChild(mScreenshotSprite);
	}

    class MyLayer extends Layer {
        public MyLayer() {
            WYSize s = Director.getInstance().getWindowSize();
        	Sprite sprite = Sprite.make(R.drawable.grossini);
            addChild(sprite);
            sprite.setPosition(s.width / 2, s.height - ResolutionIndependent.resolveDp(150));
            
            IntervalAction a = (IntervalAction)RotateBy.make(2, 360).autoRelease();
            Action repeat = (Action)RepeatForever.make(a).autoRelease();
            sprite.runAction(repeat);
            
            MenuItemLabel item3 = MenuItemLabel.make("Make Screenshot", this, "onMakeScreenshot");
            Menu menu = Menu.make(item3);
            menu.alignItemsVertically();
            addChild(menu);
        }
        
        public void onMakeScreenshot() {
        	// 如果之前的截图预览还在, 删除掉, 这样的话, 就不会被截进去了
        	if(mScreenshotSprite != null) {
        		removeChild(mScreenshotSprite, true);
        		mScreenshotSprite = null;
        	}
        	
        	// 截屏, 截屏操作是异步的, 可以在onDirectorScreenCaptured中处理截屏成功事件
        	Director.getInstance().makeScreenshot("/sdcard/WiEngine/screenshot.png");
        }
    }
}
