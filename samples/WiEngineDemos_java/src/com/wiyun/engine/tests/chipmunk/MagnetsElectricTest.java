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
import static com.wiyun.engine.types.WYPoint.lengthsq;
import static com.wiyun.engine.types.WYPoint.mul;
import static com.wiyun.engine.types.WYPoint.normalize;
import static com.wiyun.engine.types.WYPoint.rotate;
import static com.wiyun.engine.types.WYPoint.sub;
import static com.wiyun.engine.types.WYPoint.toRadian;
import static java.lang.Math.cos;
import static java.lang.Math.pow;
import static java.lang.Math.sin;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.chipmunk.Poly;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.chipmunk.Body.IPositionUpdater;
import com.wiyun.engine.chipmunk.Body.IVelocityUpdater;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 这个例子在java端有性能问题，因此尚未显示在Demo列表中
// 在native demo中这个例子可以正常运行
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

public class MagnetsElectricTest extends WiEngineTestActivity {
	static float WIDTH;
	static float HEIGHT;

	// Maximum number of singularities per body
	static final int SINGMAX = 10;

	// Number of magnets
	static final int NMAG = 10;

	// Number of charged bodies
	static final int NCHG = 10;

	// Number of charged magnets
	static final int NMIX = 10;

	// Some physical constants
	static final float COU_MKS = 8.987551787e9f;
	static final float MAG_MKS = 1e-7f;

	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	static final class ForceData {
		//Everything in global coordinates
		// Position of the source
		WYPoint p0 = WYPoint.makeZero();

		// Observed position
		WYPoint p = WYPoint.makeZero();

		// Relative position source-observed
		WYPoint relp = WYPoint.makeZero();

		// distance, distance^2, distance ^3
		float[] r = new float[3];

		// angle of the source
		float ang0;

		// angle of the observed singularity
		float ang;

		// Force value
		WYPoint F = WYPoint.makeZero();

		// Torque value
		float T;
	}

	static interface SingularityForce {
		public void singForce(ForceData data);
	}

	static final class Sing {
		// Number of singularities 
		int Nsing;

		// Value of the singularities 
		float[] value = new float[SINGMAX];

		// Type of the singularities 
		String[] type = new String[SINGMAX];

		// Global position of the singularities
		WYPoint[] Gpos = new WYPoint[SINGMAX];

		// Local position of the singularities
		WYPoint[] position = new WYPoint[SINGMAX];

		// Angle of the singularities measured in the body axes
		float[] angle = new float[SINGMAX];

		// Angle of the singularities measured from x
		float[] Gangle = new float[SINGMAX];

		// Force function
		SingularityForce[] force_func = new SingularityForce[SINGMAX];

		// Force function
		SingularityForce[] torque_func = new SingularityForce[SINGMAX];
	}

	static final class MagDipoleForce implements SingularityForce {
		static float phi, alpha, beta, Fr, Fphi;

		public void singForce(ForceData data) {

			// Angle of the relative position vector
			phi = toRadian(data.relp);
			alpha = data.ang0;
			beta = data.ang;

			alpha = phi - alpha;
			beta = phi - beta;

			// Components in polar coordinates
			Fr = (float)(2.0e0f * cos(alpha) * cos(beta) - sin(alpha) * sin(beta));
			Fphi = (float)sin(alpha + beta);

			// Cartesian coordinates
			data.F = WYPoint.make((float)(Fr * cos(phi) - Fphi * sin(phi)), (float)(Fr * sin(phi) + Fphi * cos(phi)));
			data.F = mul(data.F, -3.e0f * MAG_MKS / (data.r[1] * data.r[1]));
		}
	}

	static final class CoulombForce implements SingularityForce {
		public void singForce(ForceData data) {
			data.F = mul(normalize(data.relp), COU_MKS / data.r[1]);
		}
	}

	static final class MagDipoleTorque implements SingularityForce {
		static float phi, alpha, beta;

		public void singForce(ForceData data) {

			phi = toRadian(data.relp);
			alpha = data.ang0;
			beta = data.ang;
			alpha = phi - alpha;
			beta = phi - beta;

			// Torque. Though we could use a component of F to save some space, 
			// we use another variables for the sake of clarity.
			data.T = (MAG_MKS / data.r[2]) * (3.0e0f * (float)cos(alpha) * (float)sin(beta) + (float)sin(alpha - beta));
		}
	}

	static ForceData fdata = new ForceData();
	static Body B;
	
	class MyLayer extends Layer implements IPositionUpdater, IVelocityUpdater {
		Space mSpace;

		Random mRandom;
		
		List<Body> mBodies;

		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			WIDTH = s.width;
			HEIGHT = s.height;
			Chipmunk chipmunk = Chipmunk.make();
			chipmunk.setDebugDraw(true);
			chipmunk.setPosition(s.width / 2, s.height / 2);
			addChild(chipmunk);

			mRandom = new Random();
			mBodies = new ArrayList<Body>();

			Shape.resetShapeIdCounter();

			mSpace = chipmunk.getSpace();
			mSpace.resizeActiveHash(30f, 2999);
			mSpace.setIterations(5);

			Body.make(Float.MAX_VALUE, Float.MAX_VALUE);

			// Create magnets
			for(int i = 0; i < NMAG; i++) {
				WYPoint p = WYPoint.makeZero();
				p.x = (2.0e0f * frand() - 1.0e0f) * WIDTH / 2.0f;
				p.y = (2.0e0f * frand() - 1.0e0f) * HEIGHT / 2.0f;
				float ang = (2.0e0f * frand() - 1.0e0f) * 3.1415f;
				make_mag(p, ang, 1.0e7f);
			}

			// Create charged objects
			for(int i = 0; i < NCHG; i++) {
				WYPoint p = WYPoint.makeZero();
				p.x = (2.0e0f * frand() - 1.0e0f) * WIDTH / 2.0f;
				p.y = (2.0e0f * frand() - 1.0e0f) * HEIGHT / 2.0f;
				make_charged(p, 1.0e-3f * (float)pow(-1.0f, i % 2));
			}

			// Create charged magnets objects
			for(int i = 0; i < NMIX; i++) {
				WYPoint p = WYPoint.makeZero();
				p.x = (2.0e0f * frand() - 1.0e0f) * WIDTH / 2.0f;
				p.y = (2.0e0f * frand() - 1.0e0f) * HEIGHT / 2.0f;
				float ang = (2.0e0f * frand() - 1.0e0f) * 3.1415f;
				make_mix(p, ang, 1.0e7f * (float)pow(-1.0f, i % 2), 1.0e-3f * (float)pow(-1.0f, i % 2));
			}

			mBodies = mSpace.getBodies();
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}

		private void make_mix(WYPoint p, float ang, float mag, float chg) {
			WYPoint[] verts = {
					WYPoint.make(-10, -10), WYPoint.make(-10, 10), WYPoint.make(10, 10), WYPoint.make(20, 0), WYPoint.make(10, -10)
			};

			Body body = Body.make(1.0f, Chipmunk.calculateMomentForPoly(1.0f, verts, WYPoint.makeZero()));
			body.setPosition(p);
			body.setAngle(ang);

			// Load the singularities
			Sing mix = new Sing();
			mix.Nsing = 2;
			mix.value[0] = mag;
			mix.value[1] = chg;
			mix.type[0] = "magdipole";
			mix.type[1] = "electrical";

			// The position and angle could be different form the one of the body
			mix.position[0] = WYPoint.makeZero();
			mix.Gpos[0] = add(p, mix.position[0]);
			mix.position[1] = WYPoint.makeZero();
			mix.Gpos[1] = add(p, mix.position[1]);
			mix.Gangle[0] = ang;
			mix.Gangle[1] = ang;

			mix.force_func[0] = new MagDipoleForce();
			mix.force_func[1] = new CoulombForce();
			mix.torque_func[0] = new MagDipoleTorque();
			mix.torque_func[1] = null;

			body.setData(mix);

			body.setPositionUpdater(this);
			body.setVelocityUpdater(this);
			mSpace.addBody(body);

			Shape shape = Poly.make(body, verts, WYPoint.makeZero());
			shape.setFriction(0.7f);
			mSpace.addShape(shape);
		}

		private void make_charged(WYPoint p, float chg) {
			WYPoint[] verts = {
					WYPoint.make(-10, -10), WYPoint.make(-10, 10), WYPoint.make(10, 10), WYPoint.make(10, -10)
			};

			Body body = Body.make(1.0f, Chipmunk.calculateMomentForPoly(1.0f, verts, WYPoint.makeZero()));
			body.setPosition(p);

			// Load the singularities
			Sing charge = new Sing();
			charge.Nsing = 1;
			charge.value[0] = chg;
			charge.type[0] = "electrical";

			// The position and angle could be different form the one of the body
			charge.position[0] = WYPoint.makeZero();
			charge.Gpos[0] = add(p, charge.position[0]);
			charge.Gangle[0] = 0;

			charge.force_func[0] = new CoulombForce();
			charge.torque_func[0] = null;

			body.setData(charge);
			body.setPositionUpdater(this);
			body.setVelocityUpdater(this);
			mSpace.addBody(body);

			Shape shape = Poly.make(body, verts, WYPoint.makeZero());
			shape.setFriction(0.7f);
			mSpace.addShape(shape);
		}

		private void make_mag(WYPoint p, float ang, float mag) {
			WYPoint[] verts = {
					WYPoint.make(-10, -10), WYPoint.make(-10, 10), WYPoint.make(10, 10), WYPoint.make(15, 5), WYPoint.make(15, -5), WYPoint.make(10, -10)
			};

			Body body = Body.make(1.0f, Chipmunk.calculateMomentForPoly(1.0f, verts, WYPoint.makeZero()));
			body.setPosition(p);
			body.setAngle(ang);

			// Load the singularities
			Sing magnet = new Sing();
			magnet.Nsing = 1;
			magnet.value[0] = mag;
			magnet.type[0] = "magdipole";

			// The position and angle could be different form the one of the body
			magnet.position[0] = WYPoint.makeZero();
			magnet.Gpos[0] = add(p, magnet.position[0]);
			magnet.angle[0] = 0.0f;
			magnet.Gangle[0] = ang;

			magnet.force_func[0] = new MagDipoleForce();
			magnet.torque_func[0] = new MagDipoleTorque();

			body.setData(magnet);

			body.setPositionUpdater(this);
			body.setVelocityUpdater(this);
			mSpace.addBody(body);

			Shape shape = Poly.make(body, verts, WYPoint.makeZero());
			shape.setFriction(0.7f);
			mSpace.addShape(shape);
		}

		public void update(float delta) {
			int steps = 3;
			float dt = delta / steps;

			int count = mBodies.size();
			for(int i = 0; i < count; i++)
				mBodies.get(i).resetForces();

			for(int i = 0; i < steps; i++) {
				mSpace.step(dt);
			}
		}

		private float frand() {
			return mRandom.nextFloat();
		}

		private void LRangeForceApply(Body a, Body b) {
			Sing aux = (Sing)a.getData();
			Sing aux2 = (Sing)b.getData();
			WYPoint delta;

			// General data needed to calculate interaction
			fdata.F = WYPoint.makeZero();

			// Calculate the forces between the charges of different bodies
			for(int i = 0; i < aux.Nsing; i++) {
				for(int j = 0; j < aux2.Nsing; j++) {
					if(aux.type[i].equals(aux2.type[j])) {
						FillForceData(aux2, j, aux, i, fdata);

						//Force applied to body A
						delta = sub(aux.Gpos[i], a.getPosition());
						a.applyForce(fdata.F, delta);

						if(aux.torque_func[i] != null) {
							//Torque on A
							aux.torque_func[i].singForce(fdata);
							a.setTorque(a.getTorque() + aux.value[i] * aux2.value[j] * fdata.T);

						}
					}
				}
			}
		}

		private void FillForceData(Sing source, int inds, Sing obs, int indo, ForceData data) {
			// Global Position and orientation of the source singularity
			data.p0 = source.Gpos[inds];
			data.ang0 = source.Gangle[inds];

			// Global Position and orientation of the observed singularity
			data.p = obs.Gpos[indo];
			data.ang = obs.Gangle[indo];

			// Derived magnitudes
			data.relp = sub(data.p, data.p0); //Relative position
			data.r[0] = length(data.relp); // Distance
			data.r[1] = lengthsq(data.relp); // Square Distance
			data.r[2] = data.r[0] * data.r[1]; // Cubic distance

			source.force_func[inds].singForce(data); // The value of the force
			data.F = mul(data.F, source.value[inds] * obs.value[indo]);
		}

		public void updatePosition(int bodyPointer, float delta) {
			// Long range interaction
			Body body = Body.from(bodyPointer);
			Sing aux = (Sing)body.getData();

			// General data needed to calculate interaction
			fdata.F = WYPoint.makeZero();

			int count = mBodies.size();
			for(int i = 0; i < count; i++) {
				B = mBodies.get(i);

				if(B != body) {
					// Calculate the forces between the singularities of different bodies
					LRangeForceApply(body, B);
				}
			}

			WYPoint dp = mul(add(body.getVelocity(), body.getVelocityBias()), delta);
			dp = add(dp, mul(mul(body.getForce(), body.getMassInverse()), 0.5f * delta * delta));
			body.setPosition(add(body.getPosition(), dp));

			body.setAngle(body.getAngle() + (body.getAngularVelocity() + body.getAngularVelocityBias()) * delta + 0.5f * body.getTorque()
					* body.getMomentOfInertiaInverse() * delta * delta);

			// Update position of the singularities
			aux = (Sing)body.getData();
			for(int i = 0; i < aux.Nsing; i++) {
				aux.Gpos[i] = add(body.getPosition(), rotate(WYPoint.make(aux.position[i].x, aux.position[i].y), body.getAngleUnitVector()));
				aux.Gangle[i] = aux.angle[i] + body.getAngle();
			}

			body.setVelocityBias(0, 0);
			body.setAngularVelocityBias(0);
        }

		public void updateVelocity(int bodyPointer, float gravityX, float gravityY, float damping, float delta) {
			Body body = Body.from(bodyPointer);
			body.setVelocity(add(body.getVelocity(), mul(add(WYPoint.make(gravityX, gravityY), mul(body.getForce(), body.getMassInverse())), 0.5f * delta)));
			body.setAngularVelocity(body.getAngularVelocity() + body.getTorque() * body.getMomentOfInertiaInverse() * 0.5f * delta);

			body.setForce(0, 0);
			body.setTorque(0);

			// General data needed to calculate interaction
			fdata.F = WYPoint.makeZero();

			int count = mSpace.getBodyCount();
			for(int i = 0; i < count; i++) {
				B = mBodies.get(i);
				if(B != body) {
					// Calculate the forces between the singularities of different bodies
					LRangeForceApply(body, B);
				}
			}
			body.setVelocity(add(mul(body.getVelocity(), damping), mul(add(WYPoint.make(gravityX, gravityY), mul(body.getForce(), body.getMassInverse())),
				0.5f * delta)));
			body.setAngularVelocity(body.getAngularVelocity() * damping + body.getTorque() * body.getMomentOfInertiaInverse() * 0.5f * delta);
        }
	}
}