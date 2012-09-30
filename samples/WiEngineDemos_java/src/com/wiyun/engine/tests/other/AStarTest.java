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
/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
package com.wiyun.engine.tests.other;

import java.util.ArrayList;

import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.MoveTo;
import com.wiyun.engine.actions.Action.Callback;
import com.wiyun.engine.astar.AStar;
import com.wiyun.engine.astar.AStarMap;
import com.wiyun.engine.astar.AStarStep;
import com.wiyun.engine.astar.RectAStarMap;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.nodes.SpriteBatchNode;
import com.wiyun.engine.nodes.SpriteEx;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.utils.ResolutionIndependent;
import com.wiyun.engine.utils.ZwoptexManager;

public class AStarTest extends WiEngineTestActivity {

	static int TILE_WIDTH = 32;
	static int TILE_HEIGHT = 32;

	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends Layer {

		boolean m_isRunning;
		float m_tile_width;
		float m_tile_height;
		int m_tile_x;
		int m_tile_y;

		int m_endx;
		int m_endy;
		int m_findStartx;
		int m_findStarty;
		int m_startx;
		int m_starty;

		ArrayList<SpriteEx> m_bgs;
		AStarMap m_map;
		AStar m_astar;
		ArrayList<AStarStep> m_paths;
		Sprite m_moveSprite;
		
		WYRect m_rect_free;
		WYRect m_rect_block;
		WYRect m_rect_r1;

		public MyLayer() {
			m_isRunning = false;
			m_paths = null;

			m_tile_width = ResolutionIndependent.resolveDp(TILE_WIDTH);
			m_tile_height = ResolutionIndependent.resolveDp(TILE_HEIGHT);
			
			ZwoptexManager.addZwoptex("astar", R.raw.astar);
			
			Texture2D tex = Texture2D.makePNG(R.drawable.astar);
			SpriteBatchNode batchNode = SpriteBatchNode.make(tex);
			addChild(batchNode);

			m_tile_x = (int) (Director.getInstance().getWindowSize().width / m_tile_width);
			m_tile_y = (int) (Director.getInstance().getWindowSize().height / m_tile_height);
			
			m_rect_free = WYRect.make(0, m_tile_height, m_tile_height, m_tile_height);
			m_rect_block = WYRect.make(m_tile_height, 0, m_tile_height, m_tile_height);
			m_rect_r1 = WYRect.make(0, 0, m_tile_height, m_tile_height);

			m_findStartx = m_startx = m_tile_x / 2;
			m_endx = m_tile_x / 2;
			m_findStarty = m_starty = m_tile_y - 1;
			m_endy = 0;

			m_bgs = new ArrayList<SpriteEx>(m_tile_x * m_tile_y);
			for (int x = 0; x < m_tile_x; x++) {
				for (int y = 0; y < m_tile_y; y++) {
					SpriteEx sprite = ZwoptexManager.makeSpriteEx("astar", "tile_free.png", tex);
					sprite.setPosition(x * m_tile_width + m_tile_width / 2, y
							* m_tile_height + m_tile_height / 2);
					batchNode.addChild(sprite);
					m_bgs.add(sprite);
				}
			}

			m_moveSprite = Sprite.make(R.drawable.r1);
			setStartPosition();
			addChild(m_moveSprite);

			m_map = RectAStarMap.make(m_tile_x, m_tile_y, false);
			m_astar = AStar.make(m_map);
			runPath();

			// start Texture2D
			SpriteEx sprite = m_bgs.get(m_startx * m_tile_y + m_starty);
			sprite.setTextureRect(m_rect_r1);

			// end
			sprite = m_bgs.get(m_endx * m_tile_y + m_endy);
			sprite.setTextureRect(m_rect_r1);
			setTouchEnabled(true);
		}

		boolean canRunning() {
			return m_isRunning;
		}

		void runPath() {
			m_isRunning = false;
			m_moveSprite.stopAllActions();
			m_findStartx = (int) (m_moveSprite.getPositionX() / m_tile_width);
			m_findStarty = (int) (m_moveSprite.getPositionY() / m_tile_height);

			m_paths = m_astar.findPath(m_findStartx, m_findStarty, m_endx,
					m_endy, false);

			if (m_paths != null && m_paths.size() > 0) {
				m_isRunning = true;
				runNextMove();
			}
		}

		void runNextMove() {
			if (m_paths != null && m_paths.size() > 0) {
				AStarStep step = m_paths.get(m_paths.size() - 1);
				MoveTo move = (MoveTo)MoveTo.make(0.618f, 
						m_moveSprite.getPositionX(),
						m_moveSprite.getPositionY(), 
						step.getX() * m_tile_width + m_tile_width / 2, 
						step.getY() * m_tile_height	+ m_tile_height / 2).autoRelease();
				m_paths.remove(m_paths.size() - 1);

				Callback callback = new Callback() {
					public void onStart(int actionPointer) {
					}

					public void onStop(int actionPointer) {
						if (canRunning()) {
							if (isEndPosition()) {
								setStartPosition();
								runPath();
							} else {
								runNextMove();
							}
						}
					}

					public void onUpdate(int actionPointer, float t) {
					}
				};
				move.setCallback(callback);
				m_moveSprite.runAction(move);
			}
		}

		boolean isEndPosition() {
			if (m_moveSprite.getPositionX() == m_endx * m_tile_width
					+ m_tile_width / 2
					&& m_moveSprite.getPositionY() == m_endy * m_tile_height
							+ m_tile_height / 2) {
				return true;
			}
			return false;
		}

		void setStartPosition() {
			m_moveSprite.setPosition(
					m_startx * m_tile_width + m_tile_width / 2, m_starty
							* m_tile_height + m_tile_height / 2);
			m_findStartx = m_startx;
			m_findStarty = m_starty;
		}

		@Override
		public boolean wyTouchesEnded(MotionEvent event) {
			WYPoint e = Director.getInstance().convertToGL(event.getX(), event.getY());

			int tile_x = (int) (e.x / m_tile_width);
			int tile_y = (int) (e.y / m_tile_height);

			if (tile_x == m_startx && tile_y == m_starty) {
				return true;
			}

			if (tile_x == m_endx && tile_y == m_endy) {
				return true;
			}

			int s_x = (int) (m_moveSprite.getPositionX() / m_tile_width);
			int s_y = (int) (m_moveSprite.getPositionY() / m_tile_height);

			if (tile_x == s_x && tile_y == s_y) {
				return true;
			}

			SpriteEx sprite = m_bgs.get(tile_x * m_tile_y + tile_y);

			if (m_map.isBlockedAt(tile_x, tile_y)) {
				m_map.freeTile(tile_x, tile_y);
				sprite.setTextureRect(m_rect_free);
			} else {
				m_map.blockTile(tile_x, tile_y);
				sprite.setTextureRect(m_rect_block);
			}

			if (s_x != m_endx || s_y != m_endy) {
				runPath();
			}
			return false;
		}
	}
}
