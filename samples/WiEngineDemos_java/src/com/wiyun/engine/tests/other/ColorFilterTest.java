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
package com.wiyun.engine.tests.other;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.filters.AreaColorFilter;
import com.wiyun.engine.filters.BlurColorFilter;
import com.wiyun.engine.filters.ColorMatrix;
import com.wiyun.engine.filters.ColorMatrixColorFilter;
import com.wiyun.engine.filters.CombineColorFilter;
import com.wiyun.engine.filters.CustomColorFilter;
import com.wiyun.engine.filters.DropShadowColorFilter;
import com.wiyun.engine.filters.EmbossColorFilter;
import com.wiyun.engine.filters.GlowColorFilter;
import com.wiyun.engine.filters.LightingColorFilter;
import com.wiyun.engine.filters.MappingColorFilter;
import com.wiyun.engine.filters.CustomColorFilter.IColorFilterDelegate;
import com.wiyun.engine.nodes.BitmapFontLabel;
import com.wiyun.engine.nodes.Button;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.NinePatchSprite;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.BitmapFont;
import com.wiyun.engine.utils.ResolutionIndependent;

public class ColorFilterTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	public class MyLayer extends Layer implements IColorFilterDelegate {
		Texture2D mTex;
		int mNextFilter;
		
		MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			
			// load texture and create sprite
			mTex = Texture2D.makePNG(R.drawable.grossini);
			mTex.autoRelease();
			Sprite sprite = Sprite.make(mTex);
			sprite.setPosition(s.width / 2, s.height / 2);
			addChild(sprite);
			
			// add a button to manipulate line
    		NinePatchSprite normal = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_normal), 
    				ResolutionIndependent.resolve(WYRect.make(9, 7, 22, 28)));
    		NinePatchSprite pressed = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_pressed), 
    				ResolutionIndependent.resolve(WYRect.make(9, 7, 22, 28)));
    		normal.setContentSize(DP(300), DP(44));
    		pressed.setContentSize(DP(300), DP(44));
    		
    		// button
    		Button button = Button.make(normal, pressed, null, null, this, "onButtonClicked");
    		button.setPosition(s.width / 2, DP(70));
    		
    		// label for button
    		BitmapFont font = BitmapFont.loadFont(R.raw.bitmapfont);
            BitmapFontLabel label = BitmapFontLabel.make(font, "Change Color Filter");
            label.setColor(new WYColor3B(255, 255, 0));
            label.setPosition(s.width / 2, DP(70));
            
    		// add
    		addChild(button);
    		addChild(label);
		}
		
        public void onButtonClicked() {
        	switch(mNextFilter) {
        		case 0:
        		{
					// 将贴图变为黑白
					ColorMatrix m = ColorMatrix.make();
					m.setSaturation(0);
					m.autoRelease();
					ColorMatrixColorFilter filter = ColorMatrixColorFilter.make(m);
					filter.autoRelease();
					mTex.setColorFilter(filter);
					mTex.applyFilter();
        			break;
        		}
        		case 1:
        		{
        			// 提高贴图的对比度
					ColorMatrix m = ColorMatrix.make();
					m.setScale(2, 2, 2, 1);
					m.autoRelease();
					ColorMatrixColorFilter filter = ColorMatrixColorFilter.make(m);
					filter.autoRelease();
					mTex.setColorFilter(filter);
					mTex.applyFilter();
        			break;
        		}
				case 2:
				{
					// 增强红色
					ColorMatrix m = ColorMatrix.make();
					m.setScale(2, 1, 1, 1);
					m.autoRelease();
					ColorMatrixColorFilter filter = ColorMatrixColorFilter.make(m);
					filter.autoRelease();
					mTex.setColorFilter(filter);
					mTex.applyFilter();
        			break;
				}
				case 3:
				{
					// 底片效果
					ColorMatrix m = ColorMatrix.make();
					m.setNegative();
					m.autoRelease();
					ColorMatrixColorFilter filter = ColorMatrixColorFilter.make(m);
					filter.autoRelease();
					mTex.setColorFilter(filter);
					mTex.applyFilter();
        			break;
				}
				case 4:
				{
					// 只留下蓝色
					LightingColorFilter filter = LightingColorFilter.make(0xff0000ff, 0x0);
					filter.autoRelease();
					mTex.setColorFilter(filter);
					mTex.applyFilter();
					break;
				}
				case 5:
				{
					// 对图片的轮廓做一个红色的剪影
					LightingColorFilter filter = LightingColorFilter.make(0xff000000, 0xffff0000);
					filter.autoRelease();
					mTex.setColorFilter(filter);
					mTex.applyFilter();
					break;
				}
				case 6:
				{
					// 给它换一身颜色的衣服, 预先已经知道衣服颜色是0xff330033
					MappingColorFilter filter = MappingColorFilter.make();
					filter.mapColor(0xff330033, 0xff319c7a, 0x00ffffff, 0x00ffffff);
					mTex.setColorFilter(filter);
					mTex.applyFilter();
					break;
				}
				case 7:
				{
					// 通过组合式过滤器, 先把图片变黑白, 再做底片, 相当于得到图像的黑白底片

					// 变成黑白
					ColorMatrix m1 = ColorMatrix.make();
					m1.autoRelease();
					m1.setSaturation(0);
					ColorMatrixColorFilter filter1 = ColorMatrixColorFilter.make(m1);
					filter1.autoRelease();

					// 变成底片
					ColorMatrix m2 = ColorMatrix.make();
					m2.autoRelease();
					m2.setNegative();
					ColorMatrixColorFilter filter2 = ColorMatrixColorFilter.make(m2);
					filter2.autoRelease();

					// 组合
					CombineColorFilter filter = CombineColorFilter.make(filter1, filter2);
					filter.autoRelease();
					mTex.setColorFilter(filter);
					mTex.applyFilter();

					break;
				}
				case 8:
				{
					// 浮雕效果
					EmbossColorFilter filter = EmbossColorFilter.make(50);
					filter.autoRelease();
					mTex.setColorFilter(filter);
					mTex.applyFilter();

					break;
				}
				case 9:
				{
					// 模糊效果
					BlurColorFilter filter = BlurColorFilter.make(1);
					filter.autoRelease();
					mTex.setColorFilter(filter);
					mTex.applyFilter();

					break;
				}
				case 10:
				{
					// 图片周围产生一个光环
					GlowColorFilter filter = GlowColorFilter.make(new WYColor3B(0, 0, 255), (int)DP(10), (int)DP(5), 128);
					mTex.setColorFilter(filter);
					mTex.applyFilter();
					break;
				}
				case 11:
				{
					/*
					 * 给图片做一个背景阴影, 同时背景色改为红色, 以便让图片看起来有边框形成立体感
					 * 背景色是0x00990033, 这是预先知道的, 由于必须判断和替换alpha值, 但是我们不能设置掩码为0xffffffff
					 * 
					 * 这是因为在Android和iOS上, 载入图片后, 纯透明的区域像素值有差异.
					 * 在Android上, 目前即使alpha为全0, rgb值也保持和原始数据相同
					 * 而在iOS上, 目前如果alpha为0, 则rgb也是0
					 * 因此为了平台一致, 当你需要替换纯透明区域时, 应该把fromMask设置为0xff000000, 这样只比较alpha值, 可以
					 * 得到平台一致的结果 
					 */
					MappingColorFilter filter1 = MappingColorFilter.make();
					filter1.mapColor(0x00990033, 0xffff0000, 0xff000000, 0xffffffff);
					DropShadowColorFilter filter2 = DropShadowColorFilter.make(new WYColor3B(0, 0, 255), (int)DP(5), (int)DP(2), 128);
					CombineColorFilter filter = CombineColorFilter.make(filter1, filter2);
					mTex.setColorFilter(filter);
					mTex.applyFilter();
					break;
				}
				case 12:
				{
					// 在图像上加了一个红色的框
					AreaColorFilter filter = AreaColorFilter.make();
					filter.mapRect(10, 10, 30, 40, 0, 0xffff0000, 0, 0xffffffff);
					filter.removeRect(15, 15, 20, 30);
					mTex.setColorFilter(filter);
					mTex.applyFilter();
					break;
				}
				case 13:
				{
					// 自定义的滤镜, 给图片加个红色边界
					CustomColorFilter filter = CustomColorFilter.make(this);
					mTex.setColorFilter(filter);
					mTex.applyFilter();
					break;
				}
				case 14:
				{
					mNextFilter = -1;
					mTex.setColorFilter(null);
					mTex.applyFilter();
					break;
				}
        	}
        	
        	mNextFilter++;
        }
		
		private float DP(float v) {
			return ResolutionIndependent.resolveDp(v);
		}

		@Override
		public void apply(byte[] imageData, int width, int height) {
			// 上边框
			int start = 0;
			for(int x = 0; x < width; x++) {
				imageData[start] = (byte)0xFF;
				imageData[start + 1] = 0;
				imageData[start + 2] = 0;
				imageData[start + 3] = (byte)0xFF;
				start += 4;
			}

			// 下边框
			start = (height - 1) * width * 4;
			for(int x = 0; x < width; x++) {
				imageData[start] = (byte)0xFF;
				imageData[start + 1] = 0;
				imageData[start + 2] = 0;
				imageData[start + 3] = (byte)0xFF;
				start += 4;
			}

			// 左边框
			start = 0;
			for(int y = 0; y < height; y++) {
				imageData[start] = (byte)0xFF;
				imageData[start + 1] = 0;
				imageData[start + 2] = 0;
				imageData[start + 3] = (byte)0xFF;
				start += width * 4;
			}

			// 右边框
			start = (width - 1) * 4;
			for(int y = 0; y < height; y++) {
				imageData[start] = (byte)0xFF;
				imageData[start + 1] = 0;
				imageData[start + 2] = 0;
				imageData[start + 3] = (byte)0xFF;
				start += width * 4;
			}
		}
	}
}
