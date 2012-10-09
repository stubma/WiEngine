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
package com.wiyun.engine.tests.box2d;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.box2d.collision.CircleShape;
import com.wiyun.engine.box2d.collision.EdgeShape;
import com.wiyun.engine.box2d.collision.PolygonShape;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.FixtureDef;
import com.wiyun.engine.box2d.dynamics.joints.PrismaticJointDef;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class CollisionFilteringTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
    
    static int k_smallGroup = 1;
    static int k_largeGroup = -1;
    static int k_defaultCategory = 0x0001;
    static int k_triangleCategory = 0x0002;
    static int k_boxCategory = 0x0004;
    static int k_circleCategory = 0x0008;
    static int k_triangleMask = 0xFFFF;
    static int k_boxMask = 0xFFFF ^ k_triangleCategory;
    static int k_circleMask = 0xFFFF;
    
    class MyLayer extends Box2DLayer {
    	// This is a test of collision filtering.
    	// There is a triangle, a box, and a circle.
    	// There are 6 shapes. 3 large and 3 small.
    	// The 3 small ones always collide.
    	// The 3 large ones never collide.
    	// The boxes don't collide with triangles (except if both are small).
    	
		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			
			// set gravity
			mWorld.setGravity(0, -10);

			// place box2d to center of bottom edge
			mBox2D.setPosition(s.width / 2, 0);
			
			// Ground body
			{
				EdgeShape shape = EdgeShape.make();
				shape.setEndpoints(-40.0f, 0.0f, 40.0f, 0.0f);

				FixtureDef sd = FixtureDef.make();
				sd.setShape(shape);
				sd.setFriction(0.3f);

				BodyDef bd = BodyDef.make();
				Body ground = mWorld.createBody(bd);
				ground.createFixture(sd);
				bd.destroy();
				sd.destroy();
			}

			// Small triangle
			WYPoint[] vertices = new WYPoint[3];
			vertices[0] = WYPoint.make(-1.0f, 0.0f);
			vertices[1] = WYPoint.make(1.0f, 0.0f);
			vertices[2] = WYPoint.make(0.0f, 2.0f);
			PolygonShape polygon = PolygonShape.make();
			polygon.setVertices(vertices);

			FixtureDef triangleShapeDef = FixtureDef.make();
			triangleShapeDef.setShape(polygon);
			triangleShapeDef.setDensity(1.0f);

			triangleShapeDef.setFilter(k_triangleCategory, k_triangleMask, k_smallGroup);

			BodyDef triangleBodyDef = BodyDef.make();
			triangleBodyDef.setType(Body.TYPE_DYNAMIC);
			triangleBodyDef.setPosition(-5.0f, 2.0f);

			Body body1 = mWorld.createBody(triangleBodyDef);
			body1.createFixture(triangleShapeDef);

			// Large triangle (recycle definitions)
			vertices[0] = WYPoint.mul(vertices[0], 2.0f);
			vertices[1] = WYPoint.mul(vertices[1], 2.0f);
			vertices[2] = WYPoint.mul(vertices[2], 2.0f);
			polygon.setVertices(vertices);
			triangleShapeDef.setFilterGroupIndex(k_largeGroup);
			triangleBodyDef.setPosition(-5.0f, 6.0f);
			triangleBodyDef.setFixedRotation(true);

			Body body2 = mWorld.createBody(triangleBodyDef);
			body2.createFixture(triangleShapeDef);
			triangleShapeDef.destroy();
			triangleBodyDef.destroy();

			{
				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(-5.0f, 10.0f);
				Body body = mWorld.createBody(bd);
				bd.destroy();

				PolygonShape p = PolygonShape.make();
				p.setAsBox(0.5f, 1.0f);
				body.createFixture(p, 1.0f);

				PrismaticJointDef jd = PrismaticJointDef.make();
				jd.setBodyA(body2);
				jd.setBodyB(body);
				jd.setEnableLimit(true);
				jd.setLocalAnchorA(0.0f, 4.0f);
				jd.setLocalAnchorB(0, 0);
				jd.setLocalAxisA(0.0f, 1.0f);
				jd.setLowerTranslation(-1.0f);
				jd.setUpperTranslation(1.0f);

				mWorld.createJoint(jd);
				jd.destroy();
			}

			// Small box
			polygon.setAsBox(1.0f, 0.5f);
			FixtureDef boxShapeDef = FixtureDef.make();
			boxShapeDef.setShape(polygon);
			boxShapeDef.setDensity(1.0f);
			boxShapeDef.setRestitution(0.1f);

			boxShapeDef.setFilter(k_boxCategory, k_boxMask, k_smallGroup);

			BodyDef boxBodyDef = BodyDef.make();
			boxBodyDef.setType(Body.TYPE_DYNAMIC);
			boxBodyDef.setPosition(0.0f, 2.0f);

			Body body3 = mWorld.createBody(boxBodyDef);
			body3.createFixture(boxShapeDef);

			// Large box (recycle definitions)
			polygon.setAsBox(2.0f, 1.0f);
			boxShapeDef.setFilterGroupIndex(k_largeGroup);
			boxBodyDef.setPosition(0.0f, 6.0f);

			Body body4 = mWorld.createBody(boxBodyDef);
			body4.createFixture(boxShapeDef);
			boxBodyDef.destroy();
			boxShapeDef.destroy();

			// Small circle
			CircleShape circle = CircleShape.make();
			circle.setRadius(1.0f);

			FixtureDef circleShapeDef = FixtureDef.make();
			circleShapeDef.setShape(circle);
			circleShapeDef.setDensity(1.0f);

			circleShapeDef.setFilter(k_circleCategory, k_circleMask, k_smallGroup);

			BodyDef circleBodyDef = BodyDef.make();
			circleBodyDef.setType(Body.TYPE_DYNAMIC);
			circleBodyDef.setPosition(5.0f, 2.0f);

			Body body5 = mWorld.createBody(circleBodyDef);
			body5.createFixture(circleShapeDef);

			// Large circle
			circle.setRadius(circle.getRadius() * 2.0f);
			circleShapeDef.setFilterGroupIndex(k_largeGroup);
			circleBodyDef.setPosition(5.0f, 6.0f);

			Body body6 = mWorld.createBody(circleBodyDef);
			body6.createFixture(circleShapeDef);
			circleBodyDef.destroy();
			circleShapeDef.destroy();
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
    }
}
