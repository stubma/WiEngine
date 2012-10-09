package com.wiyun.engine.tests.performance;

import android.os.Bundle;
import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.tmx.TMXTileMap;

public class BigTMXTest extends WiEngineTestActivity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		mGLSurfaceView.disableSystemHandleMenuKey();
	}
	
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
    	TMXTileMap mMap;
    	
    	private float mLastX;
    	private float mLastY;
    	
    	public MyLayer() {
    		Texture2D tex1 = Texture2D.makePNG(R.drawable.tileset0);
    		tex1.autoRelease();
    		mMap = TMXTileMap.make(R.raw.b0, tex1);
    		mMap.setDebugDrawObjects(true);
            addChild(mMap);
            
            setTouchEnabled(true);
		}
        
        @Override
        public boolean wyTouchesBegan(MotionEvent event) {
        	mLastX = event.getX();
        	mLastY = event.getY();
        	return true;
        }
        
        @Override
        public boolean wyTouchesMoved(MotionEvent event) {
        	// remember android event origin is not same as OpenGL
        	// you can use Director.getInstance().convertToGL(event.getX(), event.getY()) to convert it to GL coordinate
        	float x = event.getX();
        	float y = event.getY();
        	float deltaX = x - mLastX;
        	float deltaY = y - mLastY;
        	mLastX = x;
        	mLastY = y;
        	
        	mMap.translate(deltaX, -deltaY);
        	return true;
        }
    }
}
