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
import static com.wiyun.engine.types.WYPoint.length;
import static com.wiyun.engine.types.WYPoint.mul;
import static com.wiyun.engine.types.WYPoint.sub;
import static java.lang.Math.max;
import static java.lang.Math.min;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.chipmunk.Constraint;
import com.wiyun.engine.chipmunk.DampedSpring;
import com.wiyun.engine.chipmunk.PivotJoint;
import com.wiyun.engine.chipmunk.Segment;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.chipmunk.DampedSpring.IForceUpdater;
import com.wiyun.engine.nodes.ColorLayer;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class SpringTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends ColorLayer implements IForceUpdater {
		Space mSpace;

		public MyLayer() {
			super(new WYColor4B(0, 0, 255, 255));
			
			WYSize s = Director.getInstance().getWindowSize();
			Chipmunk chipmunk = Chipmunk.make();
			chipmunk.setDebugDraw(true);
			chipmunk.setPosition(s.width / 2, s.height / 2);
			addChild(chipmunk);

			Shape.resetShapeIdCounter();

			mSpace = chipmunk.getSpace();

			Body staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);

			Body body1 = addBar(WYPoint.make(-240, 160), WYPoint.make(-160, 80), 1);
			Body body2 = addBar(WYPoint.make(-160, 80), WYPoint.make(-80, 160), 1);
			Body body3 = addBar(WYPoint.make(0, 160), WYPoint.make(80, 0), 0);
			Body body4 = addBar(WYPoint.make(160, 160), WYPoint.make(240, 160), 0);
			Body body5 = addBar(WYPoint.make(-240, 0), WYPoint.make(-160, -80), 2);
			Body body6 = addBar(WYPoint.make(-160, -80), WYPoint.make(-80, 0), 2);
			Body body7 = addBar(WYPoint.make(-80, 0), WYPoint.make(0, 0), 2);
			Body body8 = addBar(WYPoint.make(0, -80), WYPoint.make(80, -80), 0);
			Body body9 = addBar(WYPoint.make(240, 80), WYPoint.make(160, 0), 3);
			Body body10 = addBar(WYPoint.make(160, 0), WYPoint.make(240, -80), 3);
			Body body11 = addBar(WYPoint.make(-240, -80), WYPoint.make(-160, -160), 4);
			Body body12 = addBar(WYPoint.make(-160, -160), WYPoint.make(-80, -160), 0);
			Body body13 = addBar(WYPoint.make(0, -160), WYPoint.make(80, -160), 0);
			Body body14 = addBar(WYPoint.make(160, -160), WYPoint.make(240, -160), 0);

			Constraint constraint = PivotJoint.make(body1, body2, WYPoint.make(40, -40), WYPoint.make(-40, -40));
			mSpace.addConstraint(constraint);
			constraint = PivotJoint.make(body5, body6, WYPoint.make(40, -40), WYPoint.make(-40, -40));
			mSpace.addConstraint(constraint);
			constraint = PivotJoint.make(body6, body7, WYPoint.make(40, 40), WYPoint.make(-40, 0));
			mSpace.addConstraint(constraint);
			constraint = PivotJoint.make(body9, body10, WYPoint.make(-40, -40), WYPoint.make(-40, 40));
			mSpace.addConstraint(constraint);
			constraint = PivotJoint.make(body11, body12, WYPoint.make(40, -40), WYPoint.make(-40, 0));
			mSpace.addConstraint(constraint);

			float stiff = 100.0f;
			float damp = 0.5f;
			mSpace.addConstraint(newSpring(staticBody,  body1, WYPoint.make(-320,  240), WYPoint.make(-40, 40), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody,  body1, WYPoint.make(-320,   80), WYPoint.make(-40, 40), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody,  body1, WYPoint.make(-160,  240), WYPoint.make(-40, 40), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody,  body2, WYPoint.make(-160,  240), WYPoint.make( 40, 40), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody,  body2, WYPoint.make(   0,  240), WYPoint.make( 40, 40), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody,  body3, WYPoint.make(  80,  240), WYPoint.make(-40, 80), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody,  body4, WYPoint.make(  80,  240), WYPoint.make(-40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody,  body4, WYPoint.make( 320,  240), WYPoint.make( 40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody,  body5, WYPoint.make(-320,   80), WYPoint.make(-40, 40), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody,  body9, WYPoint.make( 320,  80), WYPoint.make( 40, 40), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody, body10, WYPoint.make( 320,   0), WYPoint.make( 40,-40), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody, body10, WYPoint.make( 320,-160), WYPoint.make( 40,-40), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody, body11, WYPoint.make(-320,-160), WYPoint.make(-40, 40), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody, body12, WYPoint.make(-240,-240), WYPoint.make(-40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody, body12, WYPoint.make(   0,-240), WYPoint.make( 40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody, body13, WYPoint.make(   0,-240), WYPoint.make(-40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody, body13, WYPoint.make(  80,-240), WYPoint.make( 40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody, body14, WYPoint.make(  80,-240), WYPoint.make(-40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody, body14, WYPoint.make( 240,-240), WYPoint.make( 40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(staticBody, body14, WYPoint.make( 320,-160), WYPoint.make( 40,  0), 0.0f, stiff, damp));

			mSpace.addConstraint(newSpring( body1,  body5, WYPoint.make( 40,-40), WYPoint.make(-40, 40), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring( body1,  body6, WYPoint.make( 40,-40), WYPoint.make( 40, 40), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring( body2,  body3, WYPoint.make( 40, 40), WYPoint.make(-40, 80), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring( body3,  body4, WYPoint.make(-40, 80), WYPoint.make(-40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring( body3,  body4, WYPoint.make( 40,-80), WYPoint.make(-40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring( body3,  body7, WYPoint.make( 40,-80), WYPoint.make( 40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring( body3,  body7, WYPoint.make(-40, 80), WYPoint.make(-40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring( body3,  body8, WYPoint.make( 40,-80), WYPoint.make( 40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring( body3,  body9, WYPoint.make( 40,-80), WYPoint.make(-40,-40), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring( body4,  body9, WYPoint.make( 40,  0), WYPoint.make( 40, 40), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring( body5, body11, WYPoint.make(-40, 40), WYPoint.make(-40, 40), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring( body5, body11, WYPoint.make( 40,-40), WYPoint.make( 40,-40), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring( body7,  body8, WYPoint.make( 40,  0), WYPoint.make(-40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring( body8, body12, WYPoint.make(-40,  0), WYPoint.make( 40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring( body8, body13, WYPoint.make(-40,  0), WYPoint.make(-40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring( body8, body13, WYPoint.make( 40,  0), WYPoint.make( 40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring( body8, body14, WYPoint.make( 40,  0), WYPoint.make(-40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(body10, body14, WYPoint.make( 40,-40), WYPoint.make(-40,  0), 0.0f, stiff, damp));
			mSpace.addConstraint(newSpring(body10, body14, WYPoint.make( 40,-40), WYPoint.make(-40,  0), 0.0f, stiff, damp));
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}

		public void update(float delta) {
			mSpace.step(delta);
		}

		private Body addBar(WYPoint a, WYPoint b, int group) {
			WYPoint center = mul(add(a, b), 1.0f / 2.0f);
			float length = length(sub(b, a));
			float mass = length / 160.0f;

			Body body = Body.make(mass, mass * length * length / 12.0f);
			body.setPosition(center);
			mSpace.addBody(body);

			Shape shape = Segment.make(body, sub(a, center), sub(b, center), 10f);
			shape.setGroup(group);
			mSpace.addShape(shape);

			return body;
		}

		private Constraint newSpring(Body a, Body b, WYPoint anchr1, WYPoint anchr2, float restLength, float stiff, float damp) {
			DampedSpring spring = DampedSpring.make(a, b, anchr1, anchr2, restLength, stiff, damp);
			spring.setForceUpdater(this);

			return spring;
		}

		public float updateForce(int springPointer, float distance) {
			DampedSpring spring = DampedSpring.from(springPointer);
			float clamp = 20.0f;
			return min(max(spring.getRestLength() - distance, -clamp), clamp) * spring.getStiffness();
		}
	}
}
