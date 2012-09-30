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
package com.wiyun.engine.types;

import java.io.IOException;
import java.io.Serializable;

public class WYAffineTransform implements Cloneable, Serializable, ICopyable {
    /**
     * The Constant serialVersionUID.
     */
    private static final long serialVersionUID = 1330973210523860834L;

    /**
     * The Constant TYPE_IDENTITY.
     */
    public static final int TYPE_IDENTITY = 0;

    /**
     * The Constant TYPE_TRANSLATION.
     */
    public static final int TYPE_TRANSLATION = 1;

    /**
     * The Constant TYPE_UNIFORM_SCALE.
     */
    public static final int TYPE_UNIFORM_SCALE = 2;

    /**
     * The Constant TYPE_GENERAL_SCALE.
     */
    public static final int TYPE_GENERAL_SCALE = 4;

    /**
     * The Constant TYPE_QUADRANT_ROTATION.
     */
    public static final int TYPE_QUADRANT_ROTATION = 8;

    /**
     * The Constant TYPE_GENERAL_ROTATION.
     */
    public static final int TYPE_GENERAL_ROTATION = 16;

    /**
     * The Constant TYPE_GENERAL_TRANSFORM.
     */
    public static final int TYPE_GENERAL_TRANSFORM = 32;

    /**
     * The Constant TYPE_FLIP.
     */
    public static final int TYPE_FLIP = 64;

    /**
     * The Constant TYPE_MASK_SCALE.
     */
    public static final int TYPE_MASK_SCALE = TYPE_UNIFORM_SCALE | TYPE_GENERAL_SCALE;

    /**
     * The Constant TYPE_MASK_ROTATION.
     */
    public static final int TYPE_MASK_ROTATION = TYPE_QUADRANT_ROTATION | TYPE_GENERAL_ROTATION;

    /**
     * The <code>TYPE_UNKNOWN</code> is an initial type value.
     */
    static final int TYPE_UNKNOWN = -1;

    /**
     * The min value equivalent to zero. If absolute value less then ZERO it
     * considered as zero.
     */
    static final double ZERO = 1E-10;
    
    /*
     * the matrix
     * a  b  0
     * c  d  0
     * tx ty 1
     */

    /**
     * The values of transformation matrix.
     */
    public double a;

    /**
     * The m10.
     */
    public double b;

    /**
     * The m01.
     */
    public double c;

    /**
     * The m11.
     */
    public double d;

    /**
     * The m02.
     */
    public double tx;

    /**
     * The m12.
     */
    public double ty;

    /**
     * The transformation <code>type</code>.
     */
    transient int type;

    public static WYAffineTransform makeIdentity() {
        return new WYAffineTransform();
    }

    /**
     * Instantiates a new affine transform of type <code>TYPE_IDENTITY</code>
     * (which leaves coordinates unchanged).
     */
    public WYAffineTransform() {
        type = TYPE_IDENTITY;
        a = d = 1.0;
        b = c = tx = ty = 0.0;
    }

    /**
     * Instantiates a new affine transform that has the same data as the given
     * AffineTransform.
     *
     * @param t the transform to copy.
     */
    public WYAffineTransform(WYAffineTransform t) {
        this.type = t.type;
        this.a = t.a;
        this.b = t.b;
        this.c = t.c;
        this.d = t.d;
        this.tx = t.tx;
        this.ty = t.ty;
    }

    /**
     * Instantiates a new affine transform by specifying the values of the 2x3
     * transformation matrix as floats. The type is set to the default type:
     * <code>TYPE_UNKNOWN</code>
     *
     * @param m00 the m00 entry in the transformation matrix.
     * @param m10 the m10 entry in the transformation matrix.
     * @param m01 the m01 entry in the transformation matrix.
     * @param m11 the m11 entry in the transformation matrix.
     * @param m02 the m02 entry in the transformation matrix.
     * @param m12 the m12 entry in the transformation matrix.
     */
    public WYAffineTransform(float m00, float m10, float m01, float m11, float m02, float m12) {
        this.type = TYPE_UNKNOWN;
        this.a = m00;
        this.b = m10;
        this.c = m01;
        this.d = m11;
        this.tx = m02;
        this.ty = m12;
    }

    /**
     * Instantiates a new affine transform by specifying the values of the 2x3
     * transformation matrix as doubles. The type is set to the default type:
     * <code>TYPE_UNKNOWN</code>
     *
     * @param m00 the m00 entry in the transformation matrix.
     * @param m10 the m10 entry in the transformation matrix.
     * @param m01 the m01 entry in the transformation matrix.
     * @param m11 the m11 entry in the transformation matrix.
     * @param m02 the m02 entry in the transformation matrix.
     * @param m12 the m12 entry in the transformation matrix.
     */
    public WYAffineTransform(double m00, double m10, double m01, double m11, double m02, double m12) {
        this.type = TYPE_UNKNOWN;
        this.a = m00;
        this.b = m10;
        this.c = m01;
        this.d = m11;
        this.tx = m02;
        this.ty = m12;
    }

    /**
     * <p>
     * Instantiates a new affine transform by reading the values of the
     * transformation matrix from an array of floats. The mapping from the array
     * to the matrix starts with <code>matrix[0]</code> giving the top-left
     * entry of the matrix and proceeds with the usual left-to-right and
     * top-down ordering.
     * </p>
     * 
     * If the array has only four entries, then the two entries of the last row
     * of the transformation matrix default to zero.
     *
     * @param matrix the array of four or six floats giving the values of the
     *               matrix.
     * @throws ArrayIndexOutOfBoundsException if the size of the array is 0, 1, 2, 3, or 5.
     */
    public WYAffineTransform(float[] matrix) {
        this.type = TYPE_UNKNOWN;
        a = matrix[0];
        b = matrix[1];
        c = matrix[2];
        d = matrix[3];
        if (matrix.length > 4) {
            tx = matrix[4];
            ty = matrix[5];
        }
    }

    /**
     * Instantiates a new affine transform by reading the values of the
     * transformation matrix from an array of doubles. The mapping from the
     * array to the matrix starts with <code>matrix[0]</code> giving the
     * top-left entry of the matrix and proceeds with the usual left-to-right
     * and top-down ordering.
     * 
     * If the array has only four entries, then the two entries of the last row
     * of the transformation matrix default to zero.
     *
     * @param matrix the array of four or six doubles giving the values of the
     *               matrix.
     * @throws ArrayIndexOutOfBoundsException if the size of the array is 0, 1, 2, 3, or 5.
     */
    public WYAffineTransform(double[] matrix) {
        this.type = TYPE_UNKNOWN;
        a = matrix[0];
        b = matrix[1];
        c = matrix[2];
        d = matrix[3];
        if (matrix.length > 4) {
            tx = matrix[4];
            ty = matrix[5];
        }
    }

    /**
     * Returns type of the affine transformation.
     * 
     * The type is computed as follows: Label the entries of the transformation
     * matrix as three rows (m00, m01), (m10, m11), and (m02, m12). Then if the
     * original basis vectors are (1, 0) and (0, 1), the new basis vectors after
     * transformation are given by (m00, m01) and (m10, m11), and the
     * translation vector is (m02, m12).
     * 
     * The types are classified as follows: <br/> TYPE_IDENTITY - no change<br/>
     * TYPE_TRANSLATION - The translation vector isn't zero<br/>
     * TYPE_UNIFORM_SCALE - The new basis vectors have equal length<br/>
     * TYPE_GENERAL_SCALE - The new basis vectors dont' have equal length<br/>
     * TYPE_FLIP - The new basis vector orientation differs from the original
     * one<br/> TYPE_QUADRANT_ROTATION - The new basis is a rotation of the
     * original by 90, 180, 270, or 360 degrees<br/> TYPE_GENERAL_ROTATION - The
     * new basis is a rotation of the original by an arbitrary angle<br/>
     * TYPE_GENERAL_TRANSFORM - The transformation can't be inverted.<br/>
     * 
     * Note that multiple types are possible, thus the types can be combined
     * using bitwise combinations.
     *
     * @return the type of the Affine Transform.
     */
    public int getType() {
        if (type != TYPE_UNKNOWN) {
            return type;
        }

        int type = 0;

        if (a * c + b * d != 0.0) {
            type |= TYPE_GENERAL_TRANSFORM;
            return type;
        }

        if (tx != 0.0 || ty != 0.0) {
            type |= TYPE_TRANSLATION;
        } else if (a == 1.0 && d == 1.0 && c == 0.0 && b == 0.0) {
            type = TYPE_IDENTITY;
            return type;
        }

        if (a * d - c * b < 0.0) {
            type |= TYPE_FLIP;
        }

        double dx = a * a + b * b;
        double dy = c * c + d * d;
        if (dx != dy) {
            type |= TYPE_GENERAL_SCALE;
        } else if (dx != 1.0) {
            type |= TYPE_UNIFORM_SCALE;
        }

        if ((a == 0.0 && d == 0.0) || (b == 0.0 && c == 0.0 && (a < 0.0 || d < 0.0))) {
            type |= TYPE_QUADRANT_ROTATION;
        } else if (c != 0.0 || b != 0.0) {
            type |= TYPE_GENERAL_ROTATION;
        }

        return type;
    }

    /**
     * Gets the scale x entry of the transformation matrix (the upper left
     * matrix entry).
     *
     * @return the scale x value.
     */
    public double getScaleX() {
        return a;
    }

    /**
     * Gets the scale y entry of the transformation matrix (the lower right
     * entry of the linear transformation).
     *
     * @return the scale y value.
     */
    public double getScaleY() {
        return d;
    }

    /**
     * Gets the shear x entry of the transformation matrix (the upper right
     * entry of the linear transformation).
     *
     * @return the shear x value.
     */
    public double getShearX() {
        return c;
    }

    /**
     * Gets the shear y entry of the transformation matrix (the lower left entry
     * of the linear transformation).
     *
     * @return the shear y value.
     */
    public double getShearY() {
        return b;
    }

    /**
     * Gets the x coordinate of the translation vector.
     *
     * @return the x coordinate of the translation vector.
     */
    public double getTranslateX() {
        return tx;
    }

    /**
     * Gets the y coordinate of the translation vector.
     *
     * @return the y coordinate of the translation vector.
     */
    public double getTranslateY() {
        return ty;
    }

    /**
     * Checks if the AffineTransformation is the identity.
     *
     * @return true, if the AffineTransformation is the identity.
     */
    public boolean isIdentity() {
        return getType() == TYPE_IDENTITY;
    }

    /**
     * Writes the values of the transformation matrix into the given array of
     * doubles. If the array has length 4, only the linear transformation part
     * will be written into it. If it has length greater than 4, the translation
     * vector will be included as well.
     *
     * @param matrix the array to fill with the values of the matrix.
     * @throws ArrayIndexOutOfBoundsException if the size of the array is 0, 1, 2, 3, or 5.
     */
    public void getMatrix(double[] matrix) {
        matrix[0] = a;
        matrix[1] = b;
        matrix[2] = c;
        matrix[3] = d;
        if (matrix.length > 4) {
            matrix[4] = tx;
            matrix[5] = ty;
        }
    }

    /**
     * Gets the determinant of the linear transformation matrix.
     *
     * @return the determinant of the linear transformation matrix.
     */
    public double getDeterminant() {
        return a * d - c * b;
    }

    /**
     * Sets the transform in terms of a list of double values.
     *
     * @param m00 the m00 coordinate of the transformation matrix.
     * @param m10 the m10 coordinate of the transformation matrix.
     * @param m01 the m01 coordinate of the transformation matrix.
     * @param m11 the m11 coordinate of the transformation matrix.
     * @param m02 the m02 coordinate of the transformation matrix.
     * @param m12 the m12 coordinate of the transformation matrix.
     */
    public void setTransform(double m00, double m10, double m01, double m11, double m02, double m12) {
        this.type = TYPE_UNKNOWN;
        this.a = m00;
        this.b = m10;
        this.c = m01;
        this.d = m11;
        this.tx = m02;
        this.ty = m12;
    }

    /**
     * Sets the transform's data to match the data of the transform sent as a
     * parameter.
     *
     * @param t the transform that gives the new values.
     */
    public void setTransform(WYAffineTransform t) {
        type = t.type;
        setTransform(t.a, t.b, t.c, t.d, t.tx, t.ty);
    }

    /**
     * Sets the transform to the identity transform.
     */
    public void setToIdentity() {
        type = TYPE_IDENTITY;
        a = d = 1.0;
        b = c = tx = ty = 0.0;
    }

    /**
     * Sets the transformation to a translation alone. Sets the linear part of
     * the transformation to identity and the translation vector to the values
     * sent as parameters. Sets the type to <code>TYPE_IDENTITY</code> if the
     * resulting AffineTransformation is the identity transformation, otherwise
     * sets it to <code>TYPE_TRANSLATION</code>.
     *
     * @param mx the distance to translate in the x direction.
     * @param my the distance to translate in the y direction.
     */
    public void setToTranslation(double mx, double my) {
        a = d = 1.0;
        c = b = 0.0;
        tx = mx;
        ty = my;
        if (mx == 0.0 && my == 0.0) {
            type = TYPE_IDENTITY;
        } else {
            type = TYPE_TRANSLATION;
        }
    }

    /**
     * Sets the transformation to being a scale alone, eliminating rotation,
     * shear, and translation elements. Sets the type to
     * <code>TYPE_IDENTITY</code> if the resulting AffineTransformation is the
     * identity transformation, otherwise sets it to <code>TYPE_UNKNOWN</code>.
     *
     * @param scx the scaling factor in the x direction.
     * @param scy the scaling factor in the y direction.
     */
    public void setToScale(double scx, double scy) {
        a = scx;
        d = scy;
        b = c = tx = ty = 0.0;
        if (scx != 1.0 || scy != 1.0) {
            type = TYPE_UNKNOWN;
        } else {
            type = TYPE_IDENTITY;
        }
    }

    /**
     * Sets the transformation to being a shear alone, eliminating rotation,
     * scaling, and translation elements. Sets the type to
     * <code>TYPE_IDENTITY</code> if the resulting AffineTransformation is the
     * identity transformation, otherwise sets it to <code>TYPE_UNKNOWN</code>.
     *
     * @param shx the shearing factor in the x direction.
     * @param shy the shearing factor in the y direction.
     */
    public void setToShear(double shx, double shy) {
        a = d = 1.0;
        tx = ty = 0.0;
        c = shx;
        b = shy;
        if (shx != 0.0 || shy != 0.0) {
            type = TYPE_UNKNOWN;
        } else {
            type = TYPE_IDENTITY;
        }
    }

    /**
     * Sets the transformation to being a rotation alone, eliminating shearing,
     * scaling, and translation elements. Sets the type to
     * <code>TYPE_IDENTITY</code> if the resulting AffineTransformation is the
     * identity transformation, otherwise sets it to <code>TYPE_UNKNOWN</code>.
     *
     * @param angle the angle of rotation in radians.
     */
    public void setToRotation(double angle) {
        double sin = Math.sin(angle);
        double cos = Math.cos(angle);
        if (Math.abs(cos) < ZERO) {
            cos = 0.0;
            sin = sin > 0.0 ? 1.0 : -1.0;
        } else if (Math.abs(sin) < ZERO) {
            sin = 0.0;
            cos = cos > 0.0 ? 1.0 : -1.0;
        }
        a = d = cos;
        c = -sin;
        b = sin;
        tx = ty = 0.0;
        type = TYPE_UNKNOWN;
    }

    /**
     * Sets the transformation to being a rotation followed by a translation.
     * Sets the type to <code>TYPE_UNKNOWN</code>.
     *
     * @param angle the angle of rotation in radians.
     * @param px    the distance to translate in the x direction.
     * @param py    the distance to translate in the y direction.
     */
    public void setToRotation(double angle, double px, double py) {
        setToRotation(angle);
        tx = px * (1.0 - a) + py * b;
        ty = py * (1.0 - a) - px * b;
        type = TYPE_UNKNOWN;
    }

    /**
     * Creates a new AffineTransformation that is a translation alone with the
     * translation vector given by the values sent as parameters. The new
     * transformation's type is <code>TYPE_IDENTITY</code> if the
     * AffineTransformation is the identity transformation, otherwise it's
     * <code>TYPE_TRANSLATION</code>.
     *
     * @param mx the distance to translate in the x direction.
     * @param my the distance to translate in the y direction.
     * @return the new AffineTransformation.
     */
    public static WYAffineTransform makeTranslate(double mx, double my) {
        WYAffineTransform t = new WYAffineTransform();
        t.setToTranslation(mx, my);
        return t;
    }

    /**
     * Creates a new AffineTransformation that is a scale alone. The new
     * transformation's type is <code>TYPE_IDENTITY</code> if the
     * AffineTransformation is the identity transformation, otherwise it's
     * <code>TYPE_UNKNOWN</code>.
     *
     * @param scx the scaling factor in the x direction.
     * @param scY the scaling factor in the y direction.
     * @return the new AffineTransformation.
     */
    public static WYAffineTransform makeScale(double scx, double scY) {
        WYAffineTransform t = new WYAffineTransform();
        t.setToScale(scx, scY);
        return t;
    }

    /**
     * Creates a new AffineTransformation that is a shear alone. The new
     * transformation's type is <code>TYPE_IDENTITY</code> if the
     * AffineTransformation is the identity transformation, otherwise it's
     * <code>TYPE_UNKNOWN</code>.
     *
     * @param shx the shearing factor in the x direction.
     * @param shy the shearing factor in the y direction.
     * @return the new AffineTransformation.
     */
    public static WYAffineTransform makeShear(double shx, double shy) {
        WYAffineTransform m = new WYAffineTransform();
        m.setToShear(shx, shy);
        return m;
    }

    /**
     * Creates a new AffineTransformation that is a rotation alone. The new
     * transformation's type is <code>TYPE_IDENTITY</code> if the
     * AffineTransformation is the identity transformation, otherwise it's
     * <code>TYPE_UNKNOWN</code>.
     *
     * @param angle the angle of rotation in radians.
     * @return the new AffineTransformation.
     */
    public static WYAffineTransform makeRotate(double angle) {
        WYAffineTransform t = new WYAffineTransform();
        t.setToRotation(angle);
        return t;
    }

    /**
     * Creates a new AffineTransformation that is a rotation followed by a
     * translation. Sets the type to <code>TYPE_UNKNOWN</code>.
     *
     * @param angle the angle of rotation in radians.
     * @param x     the distance to translate in the x direction.
     * @param y     the distance to translate in the y direction.
     * @return the new AffineTransformation.
     */
    public static WYAffineTransform makeRotate(double angle, double x, double y) {
        WYAffineTransform t = new WYAffineTransform();
        t.setToRotation(angle, x, y);
        return t;
    }

    /**
     * Applies a translation to this AffineTransformation.
     *
     * @param mx the distance to translate in the x direction.
     * @param my the distance to translate in the y direction.
     */
    public void translate(double mx, double my) {
    	double tx1 = mx * a + my * c + tx;
    	double ty1 = mx * b + my * d + ty;
    	tx = tx1;
    	ty = ty1;
    }

    /**
     * Applies a scaling transformation to this AffineTransformation.
     *
     * @param scx the scaling factor in the x direction.
     * @param scy the scaling factor in the y direction.
     */
    public void scale(double scx, double scy) {
    	a *= scx;
    	d *= scy;
    }

    /**
     * Applies a shearing transformation to this AffineTransformation.
     *
     * @param shx the shearing factor in the x direction.
     * @param shy the shearing factor in the y direction.
     */
    public void shear(double shx, double shy) {
        concat(WYAffineTransform.makeShear(shx, shy));
    }

    /**
     * Applies a rotation transformation to this AffineTransformation.
     *
     * @param angle the angle of rotation in radians.
     */
    public void rotate(double angle) {
        double sin = Math.sin(angle);
        double cos = Math.cos(angle);
        double a1 = a * cos + b * -sin;
        double b1 = a * sin + b * cos;
        double c1 = c * cos + d * -sin;
        double d1 = c * sin + d * cos;
        a = a1;
        b = b1;
        c = c1;
        d = d1;
    }

    /**
     * Applies a rotation and translation transformation to this
     * AffineTransformation.
     *
     * @param angle the angle of rotation in radians.
     * @param px    the distance to translate in the x direction.
     * @param py    the distance to translate in the y direction.
     */
    public void rotate(double angle, double px, double py) {
        concat(WYAffineTransform.makeRotate(angle, px, py));
    }

    /**
     * Multiplies the matrix representations of two AffineTransform objects.
     *
     * @return t2 an AffineTransform object that is the result of t1 multiplied by
     *         the matrix t2.
     */
    private WYAffineTransform multiply(WYAffineTransform t2) {
        double a1 = a * t2.a + b * t2.c;
        double b1 = a * t2.b + b * t2.d;
        double c1 = c * t2.a + d * t2.c;
        double d1 = c * t2.b + d * t2.d;
        double tx1 = tx * t2.a + ty * t2.c + t2.tx;
        double ty1 = tx * t2.b + ty * t2.d + t2.ty;
        a = a1;
        b = b1;
        c = c1;
        d = d1;
        tx = tx1;
        ty = ty1;
        return this;
    }

    /**
     * Applies the given AffineTransform to this AffineTransform via matrix
     * multiplication.
     *
     * @param t the AffineTransform to apply to this AffineTransform.
     */
    public WYAffineTransform concat(WYAffineTransform t) {
    	multiply(t);
    	return this;
    }

    /**
     * Changes the current AffineTransform the one obtained by taking the
     * transform t and applying this AffineTransform to it.
     *
     * @param t the AffineTransform that this AffineTransform is multiplied
     *          by.
     */
    public WYAffineTransform preConcat(WYAffineTransform t) {
    	setTransform(t.multiply(this));
        return this;
    }

    /**
     * Convert this AffineTransform to the inverse of this transform.
     *
     * @return this affine transform for convenience
     */
    public WYAffineTransform inverse() {
        double det = getDeterminant();
        if (Math.abs(det) < ZERO) {
            setToIdentity();
        }
        double a1 = d / det;
        double b1 = -b / det;
        double c1 = -c / det;
        double d1 = a / det;
        double tx1 = (c * ty - d * tx) / det;
        double ty1 = (b * tx - a * ty) / det;
        a = a1;
        b = b1;
        c = c1;
        d = d1;
        tx = tx1;
        ty = ty1;
        return this;
    }
    
    public WYPoint transform(float x, float y) {
    	WYPoint p = WYPoint.make(0, 0);
        p.x = (float) (x * a + y * c + tx);
        p.y = (float) (x * b + y * d + ty);
        return p;
    }

    /**
     * Apply the current AffineTransform to the point.
     *
     * @param src the original point.
     * @return the point in the AffineTransform's image space where the original
     *         point is sent.
     */
    public WYPoint transform(WYPoint src) {
        float x = src.x;
        float y = src.y;

        src.x = (float) (x * a + y * c + tx);
        src.y = (float) (x * b + y * d + ty);
        return src;
    }

    /**
     * Applies this AffineTransform to an array of points.
     *
     * @param src    the array of points to be transformed.
     * @param srcOff the offset in the source point array of the first point to be
     *               transformed.
     * @param dst    the point array where the images of the points (after applying
     *               the AffineTransformation) should be placed.
     * @param dstOff the offset in the destination array where the new values
     *               should be written.
     * @param length the number of points to transform.
     * @throws ArrayIndexOutOfBoundsException if <code>srcOff + length > src.length</code> or
     *                                        <code>dstOff + length > dst.length</code>.
     */
    public void transform(WYPoint[] src, int srcOff, WYPoint[] dst, int dstOff, int length) {
        while (--length >= 0) {
            WYPoint srcPoint = src[srcOff++];
            double x = srcPoint.x;
            double y = srcPoint.y;
            WYPoint dstPoint = dst[dstOff];
            if (dstPoint == null) {
                dstPoint = WYPoint.makeZero();
            }
            dstPoint.x = (float) (x * a + y * c + tx);
            dstPoint.y = (float) (x * b + y * d + ty);
            dst[dstOff++] = dstPoint;
        }
    }

    /**
     * Applies this AffineTransform to a set of points given as an array of
     * double values where every two values in the array give the coordinates of
     * a point; the even-indexed values giving the x coordinates and the
     * odd-indexed values giving the y coordinates.
     *
     * @param src    the array of points to be transformed.
     * @param srcOff the offset in the source point array of the first point to be
     *               transformed.
     * @param dst    the point array where the images of the points (after applying
     *               the AffineTransformation) should be placed.
     * @param dstOff the offset in the destination array where the new values
     *               should be written.
     * @param length the number of points to transform.
     * @throws ArrayIndexOutOfBoundsException if <code>srcOff + length*2 > src.length</code> or
     *                                        <code>dstOff + length*2 > dst.length</code>.
     */
    public void transform(double[] src, int srcOff, double[] dst, int dstOff, int length) {
        int step = 2;
        if (src == dst && srcOff < dstOff && dstOff < srcOff + length * 2) {
            srcOff = srcOff + length * 2 - 2;
            dstOff = dstOff + length * 2 - 2;
            step = -2;
        }
        while (--length >= 0) {
            double x = src[srcOff + 0];
            double y = src[srcOff + 1];
            dst[dstOff + 0] = x * a + y * c + tx;
            dst[dstOff + 1] = x * b + y * d + ty;
            srcOff += step;
            dstOff += step;
        }
    }

    /**
     * Applies this AffineTransform to a set of points given as an array of
     * float values where every two values in the array give the coordinates of
     * a point; the even-indexed values giving the x coordinates and the
     * odd-indexed values giving the y coordinates.
     *
     * @param src    the array of points to be transformed.
     * @param srcOff the offset in the source point array of the first point to be
     *               transformed.
     * @param dst    the point array where the images of the points (after applying
     *               the AffineTransformation) should be placed.
     * @param dstOff the offset in the destination array where the new values
     *               should be written.
     * @param length the number of points to transform.
     * @throws ArrayIndexOutOfBoundsException if <code>srcOff + length*2 > src.length</code> or
     *                                        <code>dstOff + length*2 > dst.length</code>.
     */
    public void transform(float[] src, int srcOff, float[] dst, int dstOff, int length) {
        int step = 2;
        if (src == dst && srcOff < dstOff && dstOff < srcOff + length * 2) {
            srcOff = srcOff + length * 2 - 2;
            dstOff = dstOff + length * 2 - 2;
            step = -2;
        }
        while (--length >= 0) {
            double x = src[srcOff + 0];
            double y = src[srcOff + 1];
            dst[dstOff + 0] = (float) (x * a + y * c + tx);
            dst[dstOff + 1] = (float) (x * b + y * d + ty);
            srcOff += step;
            dstOff += step;
        }
    }

    /**
     * Applies this AffineTransform to a set of points given as an array of
     * float values where every two values in the array give the coordinates of
     * a point; the even-indexed values giving the x coordinates and the
     * odd-indexed values giving the y coordinates. The destination coordinates
     * are given as values of type <code>double</code>.
     *
     * @param src    the array of points to be transformed.
     * @param srcOff the offset in the source point array of the first point to be
     *               transformed.
     * @param dst    the point array where the images of the points (after applying
     *               the AffineTransformation) should be placed.
     * @param dstOff the offset in the destination array where the new values
     *               should be written.
     * @param length the number of points to transform.
     * @throws ArrayIndexOutOfBoundsException if <code>srcOff + length*2 > src.length</code> or
     *                                        <code>dstOff + length*2 > dst.length</code>.
     */
    public void transform(float[] src, int srcOff, double[] dst, int dstOff, int length) {
        while (--length >= 0) {
            float x = src[srcOff++];
            float y = src[srcOff++];
            dst[dstOff++] = x * a + y * c + tx;
            dst[dstOff++] = x * b + y * d + ty;
        }
    }

    /**
     * Applies this AffineTransform to a set of points given as an array of
     * double values where every two values in the array give the coordinates of
     * a point; the even-indexed values giving the x coordinates and the
     * odd-indexed values giving the y coordinates. The destination coordinates
     * are given as values of type <code>float</code>.
     *
     * @param src    the array of points to be transformed.
     * @param srcOff the offset in the source point array of the first point to be
     *               transformed.
     * @param dst    the point array where the images of the points (after applying
     *               the AffineTransformation) should be placed.
     * @param dstOff the offset in the destination array where the new values
     *               should be written.
     * @param length the number of points to transform.
     * @throws ArrayIndexOutOfBoundsException if <code>srcOff + length*2 > src.length</code> or
     *                                        <code>dstOff + length*2 > dst.length</code>.
     */
    public void transform(double[] src, int srcOff, float[] dst, int dstOff, int length) {
        while (--length >= 0) {
            double x = src[srcOff++];
            double y = src[srcOff++];
            dst[dstOff++] = (float) (x * a + y * c + tx);
            dst[dstOff++] = (float) (x * b + y * d + ty);
        }
    }

    /**
     * Transforms the point according to the linear transformation part of this
     * AffineTransformation (without applying the translation).
     *
     * @param src the original point.
     * @param dst the point object where the result of the delta transform is
     *            written.
     * @return the result of applying the delta transform (linear part only) to
     *         the original point.
     */
    // TODO: is this right? if dst is null, we check what it's an
    // instance of? Shouldn't it be src instanceof Point2D.Double?
    public WYPoint deltaTransform(WYPoint src, WYPoint dst) {
        if (dst == null) {
            dst = WYPoint.makeZero();
        }

        double x = src.x;
        double y = src.y;

        dst.x = (float) (x * a + y * c);
        dst.y = (float) (x * b + y * d);
        return dst;
    }

    /**
     * Applies the linear transformation part of this AffineTransform (ignoring
     * the translation part) to a set of points given as an array of double
     * values where every two values in the array give the coordinates of a
     * point; the even-indexed values giving the x coordinates and the
     * odd-indexed values giving the y coordinates.
     *
     * @param src    the array of points to be transformed.
     * @param srcOff the offset in the source point array of the first point to be
     *               transformed.
     * @param dst    the point array where the images of the points (after applying
     *               the delta transformation) should be placed.
     * @param dstOff the offset in the destination array where the new values
     *               should be written.
     * @param length the number of points to transform.
     * @throws ArrayIndexOutOfBoundsException if <code>srcOff + length*2 > src.length</code> or
     *                                        <code>dstOff + length*2 > dst.length</code>.
     */
    public void deltaTransform(double[] src, int srcOff, double[] dst, int dstOff, int length) {
        while (--length >= 0) {
            double x = src[srcOff++];
            double y = src[srcOff++];
            dst[dstOff++] = x * a + y * c;
            dst[dstOff++] = x * b + y * d;
        }
    }

    /**
     * Transforms the point according to the inverse of this
     * AffineTransformation.
     *
     * @param src the original point.
     * @param dst the point object where the result of the inverse transform is
     *            written (may be null).
     * @return the result of applying the inverse transform. Inverse transform.
     * @throws IllegalStateException
     *          if this AffineTransform cannot be inverted (the determinant
     *          of the linear transformation part is zero).
     */
    public WYPoint inverseTransform(WYPoint src, WYPoint dst) {
        double det = getDeterminant();
        if (Math.abs(det) < ZERO) {
            throw new IllegalStateException("Determinant is zero"); //$NON-NLS-1$
        }

        if (dst == null) {
            dst = WYPoint.makeZero();
        }

        double x = src.x - tx;
        double y = src.y - ty;

        dst.x = (float) ((x * d - y * c) / det);
        dst.y = (float) ((y * a - x * b) / det);
        return dst;
    }

    /**
     * Applies the inverse of this AffineTransform to a set of points given as
     * an array of double values where every two values in the array give the
     * coordinates of a point; the even-indexed values giving the x coordinates
     * and the odd-indexed values giving the y coordinates.
     *
     * @param src    the array of points to be transformed.
     * @param srcOff the offset in the source point array of the first point to be
     *               transformed.
     * @param dst    the point array where the images of the points (after applying
     *               the inverse of the AffineTransformation) should be placed.
     * @param dstOff the offset in the destination array where the new values
     *               should be written.
     * @param length the number of points to transform.
     * @throws ArrayIndexOutOfBoundsException if <code>srcOff + length*2 > src.length</code> or
     *                                        <code>dstOff + length*2 > dst.length</code>.
     * @throws IllegalStateException
     *                                        if this AffineTransform cannot be inverted (the determinant
     *                                        of the linear transformation part is zero).
     */
    public void inverseTransform(double[] src, int srcOff, double[] dst, int dstOff, int length) {
        double det = getDeterminant();
        if (Math.abs(det) < ZERO) {
            throw new IllegalStateException("Determinant is zero"); //$NON-NLS-1$
        }

        while (--length >= 0) {
            double x = src[srcOff++] - tx;
            double y = src[srcOff++] - ty;
            dst[dstOff++] = (x * d - y * c) / det;
            dst[dstOff++] = (y * a - x * b) / det;
        }
    }

    @Override
    public String toString() {
    	StringBuilder sb = new StringBuilder();
    	sb.append("[[")
    		.append(a)
    		.append(", ")
    		.append(c)
    		.append(", ")
    		.append(tx)
    		.append("], [")
    		.append(b)
    		.append(", ")
    		.append(d)
    		.append(", ")
    		.append(ty)
    		.append("]]");
    	return sb.toString();
    }
    
    public WYAffineTransform copy() {
    	WYAffineTransform t = new WYAffineTransform();
    	t.a = a;
    	t.c = c;
    	t.tx = tx;
    	t.b = b;
    	t.d = d;
    	t.ty = ty;
    	t.type = type;
    	return t;
    }

    @Override
    public Object clone() {
    	return copy();
    }

    @Override
    public int hashCode() {
    	return toString().hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) {
            return true;
        }
        if (obj instanceof WYAffineTransform) {
            WYAffineTransform t = (WYAffineTransform) obj;
            return a == t.a && c == t.c && tx == t.tx && b == t.b && d == t.d
                    && ty == t.ty;
        }
        return false;
    }

    /**
     * Writes the AffineTrassform object to the output steam.
     *
     * @param stream - the output stream.
     * @throws java.io.IOException - if there are I/O errors while writing to the output stream.
     */
    private void writeObject(java.io.ObjectOutputStream stream) throws IOException {
        stream.defaultWriteObject();
    }

    /**
     * Read the AffineTransform object from the input stream.
     *
     * @param stream - the input stream.
     * @throws IOException            - if there are I/O errors while reading from the input
     *                                stream.
     * @throws ClassNotFoundException - if class could not be found.
     */
    private void readObject(java.io.ObjectInputStream stream) throws IOException,
            ClassNotFoundException {
        stream.defaultReadObject();
        type = TYPE_UNKNOWN;
    }
    
	/**
	 * Convert self to OpenGL transform matrix
	 * 
	 * @param m float array of OpenGL matrix
	 */
	public void toGL(float[] m) {
		// | m[0] m[4] m[8]  m[12] |     | m11 m21 m31 m41 |     | a c 0 tx |
		// | m[1] m[5] m[9]  m[13] |     | m12 m22 m32 m42 |     | b d 0 ty |
		// | m[2] m[6] m[10] m[14] | <=> | m13 m23 m33 m43 | <=> | 0 0 1  0 |
		// | m[3] m[7] m[11] m[15] |     | m14 m24 m34 m44 |     | 0 0 0  1 |

		m[2] = m[3] = m[6] = m[7] = m[8] = m[9] = m[11] = m[14] = 0.0f;
		m[10] = m[15] = 1.0f;
		m[0] = (float)a;
		m[4] = (float)c;
		m[12] = (float)tx;
		m[1] = (float)b;
		m[5] = (float)d;
		m[13] = (float)ty;
	}

	/**
	 * Convert OpenGL transform matrix to {@link WYAffineTransform} instance
	 * 
	 * @param m float array of OpenGL matrix
	 */
	public void fromGL(float[] m) {
		a = m[0];
		c = m[4];
		tx = m[12];
		b = m[1];
		d = m[5];
		ty = m[13];
	}
}