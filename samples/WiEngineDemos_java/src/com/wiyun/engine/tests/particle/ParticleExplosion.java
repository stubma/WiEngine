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

public class ParticleExplosion extends QuadParticleSystem {
    public static ParticleSystem make() {
        return new ParticleExplosion();
    }

    protected ParticleExplosion() {
        this(700);
    }

    protected ParticleExplosion(int p) {
        super(p);

        // duration
        setDuration(0.1f);

        // gravity
        setParticleGravity(0, -100);

        // angle
        setDirectionAngleVariance(90, 360);

        // speed of particles
        setSpeedVariance(70, 40);

        // life of particles
        setLifeVariance(5f, 2f);

        // size, in pixels
        setStartSizeVariance(15f, 10f);

        // emits per second
        setEmissionRate(getMaxParticleCount() / getDuration());

        // color of particles
        setStartColorVariance(0.7f, 0.1f, 0.2f, 1f, 0.5f, 0.5f, 0.5f, 0f);
        setEndColorVariance(0.5f, 0.5f, 0.5f, 0f, 0.5f, 0.5f, 0.5f, 0f);

        setTexture(Texture2D.makePNG(R.drawable.stars));
    }
}
