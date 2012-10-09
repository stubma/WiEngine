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

public class ParticleGalaxy extends QuadParticleSystem {
    public static ParticleSystem make() {
        return new ParticleGalaxy();
    }

    protected ParticleGalaxy() {
        this(200);
    }

    protected ParticleGalaxy(int p) {
        super(p);

        // duration
        setDuration(PARTICLE_DURATION_INFINITY);

        // angle
        setDirectionAngleVariance(90, 360);

        // speed of particles
        setSpeedVariance(60, 10);

        // radial
        setRadialAccelerationVariance(-80, 0);

        // tagential
        setTangentialAccelerationVariance(80, 0);

        // life of particles
        setLifeVariance(4, 1);

        // size, in pixels
        setStartSizeVariance(37f, 10f);

        // emits per second
        setEmissionRate(getMaxParticleCount() / getLife());

        // color of particles
        setStartColorVariance(0.12f, 0.25f, 0.76f, 1f, 0f, 0f, 0f, 0f);
        setEndColorVariance(0f, 0f, 0f, 1f, 0f, 0f, 0f, 0f);

        // TODO support fire.pvr
        setTexture(Texture2D.makePNG(R.drawable.fire));

        // additive
        setBlendAdditive(true);
    }
}
