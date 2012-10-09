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
package com.wiyun.engine.tests.chipmunk;

import static com.wiyun.engine.types.WYPoint.add;
import static com.wiyun.engine.types.WYPoint.distance;
import static com.wiyun.engine.types.WYPoint.sub;
import static java.lang.Math.PI;
import static java.lang.Math.cos;
import static java.lang.Math.sin;
import android.util.Log;
import android.view.MotionEvent;

import com.wiyun.engine.WiEngine;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.chipmunk.Circle;
import com.wiyun.engine.chipmunk.Poly;
import com.wiyun.engine.chipmunk.Segment;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.chipmunk.Space.SegmentQueryInfo;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class QueryTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends Layer {
		Space mSpace;
		Segment querySeg;
		WYPoint mousePoint = WYPoint.makeZero();

		public MyLayer() {
			setTouchEnabled(true);

			// create and add chipmunk
			WYSize s = Director.getInstance().getWindowSize();
			Chipmunk chipmunk = Chipmunk.make();
			chipmunk.setDebugDraw(true);
			chipmunk.setPosition(s.width / 2, s.height / 2);
			addChild(chipmunk);

			Shape.resetShapeIdCounter();

			// create space
			mSpace = chipmunk.getSpace();
			mSpace.setIterations(5);
			mSpace.resizeActiveHash(30f, 2999);
			mSpace.resizeStaticHash(40f, 999);

			// add static body
			Body staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);

			// add a non-collidable segment as a quick and dirty way to draw the query line
			Shape shape = Segment.make(staticBody, WYPoint.makeZero(), WYPoint.make(100f, 0f), 4f);
			shape.setLayerMask(0);
			mSpace.addStaticShape(shape);
			querySeg = (Segment)shape;

			// add a fat segment
			float mass = 1.0f;
			float length = 100.0f;
			WYPoint a = WYPoint.make(-length / 2.0f, 0.0f), b = WYPoint.make(length / 2.0f, 0.0f);
			float moment = Chipmunk.calculateMomentForSegment(mass, a, b);
			Body body = Body.make(mass, moment);
			body.setPosition(0, 100);
			mSpace.addBody(body);
			shape = Segment.make(body, a, b, 20f);
			mSpace.addShape(shape);

			// add a static segment
			shape = Segment.make(staticBody, WYPoint.make(0, s.height / 2), WYPoint.make(s.width / 2, 0), 2f);
			mSpace.addStaticShape(shape);

			// add a pentagon
			WYPoint[] verts = new WYPoint[5];
			for(int i = 0; i < verts.length; i++) {
				float angle = -2 * (float)PI * i / (verts.length);
				verts[i] = WYPoint.make(30 * (float)cos(angle), 30 * (float)sin(angle));
			}
			moment = Chipmunk.calculateMomentForPoly(mass, verts, WYPoint.makeZero());
			body = Body.make(mass, moment);
			body.setPosition(150f, 50f);
			mSpace.addBody(body);
			shape = Poly.make(body, verts, WYPoint.makeZero());
			mSpace.addShape(shape);

			// add a circle
			float r = 20.0f;
			moment = Chipmunk.calculateMomentForCircle(mass, 0, r, WYPoint.makeZero());
			body = Body.make(mass, moment);
			body.setPosition(100, 100);
			mSpace.addBody(body);
			shape = Circle.make(body, r);
			mSpace.addShape(shape);

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}

		public void update(float delta) {
			StringBuilder messageString = new StringBuilder();

			WYPoint start = WYPoint.makeZero();
			WYPoint end = mousePoint;
			WYPoint lineEnd = end;

			messageString.append("Query: Dist(");
			messageString.append(distance(start, end));
			messageString.append(") Point");
			messageString.append(end.toString());
			messageString.append('\n');

			SegmentQueryInfo info = new SegmentQueryInfo();
			mSpace.querySegmentFirst(start, end, Chipmunk.CP_ALL_LAYERS, Chipmunk.CP_NO_GROUP, info);
			if(info.shapePointer != 0) {
				WYPoint point = Chipmunk.querySegmentHitPoint(start, end, info);
				lineEnd = add(point, WYPoint.makeZero());

				messageString.append("Segment Query: Dist(");
				messageString.append(Chipmunk.querySegmentHitPoint(start, end, info));
				messageString.append(") Point<");
				messageString.append(info.normalX);
				messageString.append(", ");
				messageString.append(info.normalY);
				messageString.append(">");
			} else {
				messageString.append("Segment Query (None)");
			}

			Log.d(WiEngine.LOG, messageString.toString());

			querySeg.setEndpoints(start, lineEnd);
			querySeg.updateBoundingBox();

			mSpace.step(delta);
		}

		@Override
		public boolean wyTouchesBegan(MotionEvent event) {
			mousePoint = Director.getInstance().convertToGL(event.getX(), event.getY());
			WYSize s = Director.getInstance().getWindowSize();
			mousePoint = sub(mousePoint, WYPoint.make(s.width / 2, s.height / 2));
			return super.wyTouchesBegan(event);
		}

		@Override
		public boolean wyTouchesMoved(MotionEvent event) {
			mousePoint = Director.getInstance().convertToGL(event.getX(), event.getY());
			WYSize s = Director.getInstance().getWindowSize();
			mousePoint = sub(mousePoint, WYPoint.make(s.width / 2, s.height / 2));
			return super.wyTouchesMoved(event);
		}

		@Override
		public boolean wyTouchesEnded(MotionEvent event) {
			mousePoint = Director.getInstance().convertToGL(event.getX(), event.getY());
			WYSize s = Director.getInstance().getWindowSize();
			mousePoint = sub(mousePoint, WYPoint.make(s.width / 2, s.height / 2));
			return super.wyTouchesEnded(event);
		}

		@Override
		public boolean wyTouchesCancelled(MotionEvent event) {
			mousePoint = Director.getInstance().convertToGL(event.getX(), event.getY());
			WYSize s = Director.getInstance().getWindowSize();
			mousePoint = sub(mousePoint, WYPoint.make(s.width / 2, s.height / 2));
			return super.wyTouchesCancelled(event);
		}
	}
}
