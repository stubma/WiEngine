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
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.particle.ParticleSystem;
import com.wiyun.engine.particle.QuadParticleSystem;

public class ParticleRain extends QuadParticleSystem {
    public static ParticleSystem make() {
        return new ParticleRain();
    }

    protected ParticleRain() {
        this(1000);
    }

    protected ParticleRain(int p) {
        super(p);

        // duration
        setDuration(PARTICLE_DURATION_INFINITY);

        // gravity
        setParticleGravity(10, -10);

        // angle
        setDirectionAngleVariance(-90, 5);

        // speed of particles
        setSpeedVariance(130, 30);

        // radial
        setRadialAccelerationVariance(0, 1);

        // tagential
        setTangentialAccelerationVariance(0, 1);

        setParticlePositionVariance(0, 0, Director.getInstance().getWindowSize().width / 2, 0);

        // life of particles
        setLifeVariance(4.5f, 0);

        // size, in pixels
        setStartSizeVariance(4f, 2f);

        // emits per second
        setEmissionRate(20);

        // color of particles
        setStartColorVariance(0.7f, 0.8f, 1f, 1f, 0f, 0f, 0f, 0f);
        setEndColorVariance(0.7f, 0.8f, 1f, 0.5f, 0f, 0f, 0f, 0f);

        // TODO support fire.pvr
        setTexture(Texture2D.makePNG(R.drawable.fire));

        // additive
        setBlendAdditive(false);
    }

}
