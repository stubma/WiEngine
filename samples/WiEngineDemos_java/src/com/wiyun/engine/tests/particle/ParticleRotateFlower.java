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
package com.wiyun.engine.tests.particle;

import com.wiyun.engine.R;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.particle.ParticleSystem;
import com.wiyun.engine.particle.QuadParticleSystem;

public class ParticleRotateFlower extends QuadParticleSystem {
    public static ParticleSystem make() {
        return new ParticleRotateFlower();
    }

    protected ParticleRotateFlower() {
        this(50);
    }

    protected ParticleRotateFlower(int p) {
        super(p);

    	// duration
        setDuration(PARTICLE_DURATION_INFINITY);
    	
    	// Gravity mode: speed of particles
        setSpeedVariance(160, 20);
    	
    	// Gravity mode: radial
        setRadialAccelerationVariance(-120, 0);
    	
    	// Gravity mode: tagential
        setTangentialAccelerationVariance(30, 0);
    	
    	// angle
        setDirectionAngleVariance(90, 360);
    		
    	// life of particles
        setLifeVariance(3, 1);

    	// spin of particles
        setEndSpinVariance(0, 2000);
    	
        // color of particles
        setStartColorVariance(0.5f, 0.5f, 0.5f, 1f, 0.5f, 0.5f, 0.5f, 1f);
        setEndColorVariance(0.1f, 0.1f, 0.1f, 0.2f, 0.1f, 0.1f, 0.1f, 0.2f);

    	// size, in pixels
        setStartSizeVariance(30, 0);
        setEndSizeVariance(PARTICLE_START_SIZE_EQUAL_TO_END_SIZE, 0);
    	
    	// emits per second
        setEmissionRate(getMaxParticleCount() / getLife());
    	
        setTexture(Texture2D.makePNG(R.drawable.stars2));

    	// additive
    	setBlendAdditive(false);
    }
}
