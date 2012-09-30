/* Copyright (c) 2007 Scott Lembcke
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
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include "chipmunk.h"
#include "wyPrimitives.h"
#include "drawSpace.h"
#include "wyTexture2D.h"
#include "wyTypes.h"
#include "wyGlobal.h"

/*
 IMPORTANT - READ ME!

 This file sets up a simple interface that the individual demos can use to get
 a Chipmunk space running and draw what's in it. In order to keep the Chipmunk
 examples clean and simple, they contain no graphics code. All drawing is done
 by accessing the Chipmunk structures at a very low level. It is NOT
 recommended to write a game or application this way as it does not scale
 beyond simple shape drawing and is very dependent on implementation details
 about Chipmunk which may change with little to no warning.
 */

#define LINE_COLOR 0.0f, 0.0f, 0.0f, 1.0f
#define COLLISION_COLOR 1.0f, 0.0f, 0.0f, 1.0f
#define BODY_COLOR 0.0f, 0.0f, 1.0f

static void glColor_from_pointer(void *ptr) {
	unsigned long val = (long) ptr;

	// hash the pointer up nicely
	val = (val + 0x7ed55d16) + (val << 12);
	val = (val ^ 0xc761c23c) ^ (val >> 19);
	val = (val + 0x165667b1) + (val << 5);
	val = (val + 0xd3a2646c) ^ (val << 9);
	val = (val + 0xfd7046c5) + (val << 3);
	val = (val ^ 0xb55a4f09) ^ (val >> 16);

	GLubyte r = (val >> 0) & 0xFF;
	GLubyte g = (val >> 8) & 0xFF;
	GLubyte b = (val >> 16) & 0xFF;

	GLubyte max = r > g ? (r > b ? r : b) : (g > b ? g : b);

	const int mult = 127;
	const int add = 63;
	r = (r * mult) / max + add;
	g = (g * mult) / max + add;
	b = (b * mult) / max + add;

	glColor4f(r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
}

static const GLfloat circleVAR[] = { 0.0000f, 0.0000f,
		0.0000f, 1.0000f, 0.2588f, 0.9659f, 0.5000f, 0.8660f, 0.7071f, 0.7071f, 0.8660f, 0.5000f, 0.9659f, 0.2588f,
		1.0000f, 0.0000f, 0.9659f, -0.2588f, 0.8660f, -0.5000f, 0.7071f, -0.7071f, 0.5000f, -0.8660f, 0.2588f, -0.9659f,
		0.0000f, -1.0000f, -0.2588f, -0.9659f, -0.5000f, -0.8660f, -0.7071f, -0.7071f, -0.8660f, -0.5000f, -0.9659f, -0.2588f,
		-1.0000f, -0.0000f, -0.9659f, 0.2588f, -0.8660f, 0.5000f, -0.7071f, 0.7071f, -0.5000f, 0.8660f, -0.2588f, 0.9659f,
		0.0000f, 1.0000f, 0.0f, 0.0f, // For an extra line to see the rotation.
		};
static const int circleVAR_count = sizeof(circleVAR) / sizeof(GLfloat) / 2;

static void debugDrawCircleShape(cpBody *body, cpCircleShape *circle) {
	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(2, GL_FLOAT, 0, circleVAR);

	glPushMatrix();
	{
		cpVect center = cpvadd(body->p, cpvrotate(circle->c, body->rot));
		glTranslatef(center.x, center.y, 0.0f);
		glRotatef(body->a * 180.0f / (cpFloat) M_PI, 0.0f, 0.0f, 1.0f);
		glScalef(circle->r, circle->r, 1.0f);

		if (!circle->shape.sensor) {
			glColor_from_pointer(circle);
			glDrawArrays(GL_TRIANGLE_FAN, 0, circleVAR_count - 1);
		}

		glColor4f(LINE_COLOR);
		glDrawArrays(GL_LINE_STRIP, 0, circleVAR_count);
	}
	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);
}

static void drawCircleShape(cpBody *body, cpCircleShape *circle) {
	// if no texture, return
	cpShape* shape = (cpShape*)circle;
	if(shape->tex == NULL)
		return;

	// load texture info if has
	if(shape->tex != NULL)
		shape->tex->load();

	// create tex coords
	GLfloat TEX[circleVAR_count * 2];
	cpFloat off_s = shape->is_atlas ? (shape->tex_l / shape->tex->getPixelWidth()) : 0.0f;
	cpFloat off_t = shape->is_atlas ? (shape->tex_t / shape->tex->getPixelHeight()) : 0.0f;
	cpFloat wrap_s = shape->is_atlas ? ((shape->tex_r - shape->tex_l) / shape->tex->getPixelWidth()) :
			(shape->tex->getWidth() / shape->tex->getPixelWidth());
	cpFloat wrap_t = shape->is_atlas ? ((shape->tex_b - shape->tex_t) / shape->tex->getPixelHeight()) :
			(shape->tex->getHeight() / shape->tex->getPixelHeight());
	for(int i = 0; i < circleVAR_count * 2; i += 2) {
		TEX[i] = off_s + (circleVAR[i] / 2.0f + 0.5f) * wrap_s;
		TEX[i + 1] = off_t + (0.5f - circleVAR[i + 1] / 2.0f) * wrap_t;
	}

	// set state
	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_POINT_SMOOTH);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);
	glVertexPointer(2, GL_FLOAT, 0, circleVAR);
	glTexCoordPointer(2, GL_FLOAT, 0, TEX);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	// ensure current texture is active
	glBindTexture(GL_TEXTURE_2D, shape->tex->getTexture());

	// repeat texture in both direction
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// push matrix because we will change matrix
	glPushMatrix();

	// construct transform matrix stack
	cpVect center = cpvadd(body->p, cpvrotate(circle->c, body->rot));
	glTranslatef(center.x, center.y, 0.0f);
	glRotatef(body->a * 180.0f / (cpFloat) M_PI, 0.0f, 0.0f, 1.0f);
	glScalef(circle->r, circle->r, 1.0f);

	// draw circle
	glDrawArrays(GL_TRIANGLE_FAN, 0, circleVAR_count);

	// restore matrix
	glPopMatrix();

	// restore old state
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
}

static const GLfloat pillVAR[] = { 0.0000f, 1.0000f, 0.2588f, 0.9659f, 0.5000f,
		0.8660f, 0.7071f, 0.7071f, 0.8660f, 0.5000f, 0.9659f, 0.2588f, 1.0000f,
		0.0000f, 0.9659f, -0.2588f, 0.8660f, -0.5000f, 0.7071f, -0.7071f,
		0.5000f, -0.8660f, 0.2588f, -0.9659f, 0.0000f, -1.0000f,

		0.0000f, -1.0000f, -0.2588f, -0.9659f, -0.5000f, -0.8660f, -0.7071f,
		-0.7071f, -0.8660f, -0.5000f, -0.9659f, -0.2588f, -1.0000f, -0.0000f,
		-0.9659f, 0.2588f, -0.8660f, 0.5000f, -0.7071f, 0.7071f, -0.5000f,
		0.8660f, -0.2588f, 0.9659f, 0.0000f, 1.0000f, };
static const int pillVAR_count = sizeof(pillVAR) / sizeof(GLfloat) / 2;

static void debugDrawSegmentShape(cpBody *body, cpSegmentShape *seg) {
	cpVect a = cpvadd(body->p, cpvrotate(seg->a, body->rot));
	cpVect b = cpvadd(body->p, cpvrotate(seg->b, body->rot));

	if (seg->r) {
		cpVect delta = cpvsub(b, a);
		cpFloat len = cpvlength(delta) / seg->r;

		GLfloat VAR[pillVAR_count * 2];
		memcpy(VAR, pillVAR, sizeof(pillVAR));

		for (int i = 0; i < pillVAR_count; i += 2)
			VAR[i] += len;

		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(2, GL_FLOAT, 0, VAR);

		glPushMatrix();
		{
			GLfloat x = a.x;
			GLfloat y = a.y;
			GLfloat cos = delta.x / len;
			GLfloat sin = delta.y / len;

			const GLfloat matrix[] = { cos, sin, 0.0f, 0.0f, -sin, cos, 0.0f,
					0.0f, 0.0f, 0.0f, 1.0f, 1.0f, x, y, 0.0f, 1.0f, };

			glMultMatrixf(matrix);

			if (!seg->shape.sensor) {
				glColor_from_pointer(seg);
				glDrawArrays(GL_TRIANGLE_FAN, 0, pillVAR_count);
			}

			// GL_LINE_LOOP is very slow in Desire HD, use GL_LINE_STRIP instead
			glColor4f(LINE_COLOR);
			glDrawArrays(GL_LINE_STRIP, 0, pillVAR_count);
		}
		glPopMatrix();

		glDisableClientState(GL_VERTEX_ARRAY);
	} else {
		glColor4f(LINE_COLOR);
		wyDrawLine(a.x, a.y, b.x, b.y);
	}
}

static void drawSegmentShape(cpBody *body, cpSegmentShape *seg) {
	// if no thickness, return
	if(!seg->r)
		return;

	// if no texture, return
	cpShape* shape = (cpShape*)seg;
	if(shape->tex == NULL)
		return;

	// load texture info if has
	shape->tex->load();

	// rotate endpoints
	cpVect a = cpvadd(body->p, cpvrotate(seg->a, body->rot));
	cpVect b = cpvadd(body->p, cpvrotate(seg->b, body->rot));

	// get delta between a and b
	cpVect delta = cpvsub(b, a);

	// get ratio of length and thickness
	cpFloat len = cpvlength(delta) / seg->r;

	// get segment vertices
	GLfloat VAR[pillVAR_count * 2];
	memcpy(VAR, pillVAR, sizeof(pillVAR));

	// stretch half side of segment
	for (int i = 0; i < pillVAR_count; i += 2)
		VAR[i] += len;

	// get tex coords
	cpFloat w = len + 2;
	cpFloat h = 2;
	GLfloat TEX[pillVAR_count * 2];
	cpFloat off_s = shape->is_atlas ? (shape->tex_l / shape->tex->getPixelWidth()) : 0.0f;
	cpFloat off_t = shape->is_atlas ? (shape->tex_t / shape->tex->getPixelHeight()) : 0.0f;
	cpFloat wrap_s = shape->is_atlas ? ((shape->tex_r - shape->tex_l) / shape->tex->getPixelWidth()) :
			(shape->tex->getWidth() / shape->tex->getPixelWidth());
	cpFloat wrap_t = shape->is_atlas ? ((shape->tex_b - shape->tex_t) / shape->tex->getPixelHeight()) :
			(shape->tex->getHeight() / shape->tex->getPixelHeight());
	for(int i = 0; i < pillVAR_count * 2; i += 2) {
		TEX[i] = VAR[i] + 1.0f;
		TEX[i + 1] = VAR[i + 1] + 1.0f;
		TEX[i] = off_s + TEX[i] / w * wrap_s;
		TEX[i + 1] = off_t + (h - TEX[i + 1]) / h * wrap_t;
	}

	// set state
	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_POINT_SMOOTH);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);
	glVertexPointer(2, GL_FLOAT, 0, VAR);
	glTexCoordPointer(2, GL_FLOAT, 0, TEX);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	// ensure current texture is active
	glBindTexture(GL_TEXTURE_2D, shape->tex->getTexture());

	// repeat texture in both direction
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// push matrix because we will change matrix
	glPushMatrix();

	// construct transform matrix and apply it
	GLfloat x = a.x;
	GLfloat y = a.y;
	GLfloat cos = delta.x / len;
	GLfloat sin = delta.y / len;
	const GLfloat matrix[] = { cos, sin, 0.0f, 0.0f, -sin, cos, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f, 1.0f, x, y, 0.0f, 1.0f, };
	glMultMatrixf(matrix);

	// draw segment
	glDrawArrays(GL_TRIANGLE_FAN, 0, pillVAR_count);

	// restore matrix
	glPopMatrix();

	// restore old state
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
}

static void debugDrawPolyShape(cpBody *body, cpPolyShape *poly) {
	int count = poly->numVerts;
	GLfloat* VAR = (GLfloat*)malloc((count + 1) * 2 * sizeof(GLfloat));

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, VAR);

	cpVect *verts = poly->verts;
	for (int i = 0; i < count; i++) {
		cpVect v = cpvadd(body->p, cpvrotate(verts[i], body->rot));
		VAR[2 * i] = v.x;
		VAR[2 * i + 1] = v.y;
	}

	// add first point to close polygon, GL_LINE_LOOP is very slow in Desire HD so we have to use GL_LINE_STRIP
	cpVect v = cpvadd(body->p, cpvrotate(verts[0], body->rot));
	VAR[2 * count] = v.x;
	VAR[2 * count + 1] = v.y;

	if (!poly->shape.sensor) {
		glColor_from_pointer(poly);
		glDrawArrays(GL_TRIANGLE_FAN, 0, count);
	}

	// draw GL_LINE_STRIP
	glColor4f(LINE_COLOR);
	glDrawArrays(GL_LINE_STRIP, 0, count + 1);

	glDisableClientState(GL_VERTEX_ARRAY);

	free(VAR);
}

static void drawPolyShape(cpBody *body, cpPolyShape *poly) {
	int count = poly->numVerts;
	GLfloat* VAR = (GLfloat*)malloc(count * 2 * sizeof(GLfloat));
	GLfloat* TEX = (GLfloat*)malloc(count * 2 * sizeof(GLfloat));

	// if no texture, return
	cpShape* shape = (cpShape*)poly;
	if(shape->tex == NULL)
		return;

	// load texture info if has
	shape->tex->load();

	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_POINT_SMOOTH);

	// enable state
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);
	glVertexPointer(2, GL_FLOAT, 0, VAR);
	glTexCoordPointer(2, GL_FLOAT, 0, TEX);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	// ensure current texture is active
	glBindTexture(GL_TEXTURE_2D, shape->tex->getTexture());

	// repeat texture in both direction
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterx(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	cpVect *verts = poly->verts;
	cpFloat off_s = shape->is_atlas ? (shape->tex_l / shape->tex->getPixelWidth()) : 0.0f;
	cpFloat off_t = shape->is_atlas ? (shape->tex_t / shape->tex->getPixelHeight()) : 0.0f;
	cpFloat wrap_s = shape->is_atlas ? ((shape->tex_r - shape->tex_l) / shape->tex->getPixelWidth()) :
			(shape->tex->getWidth() / shape->tex->getPixelWidth());
	cpFloat wrap_t = shape->is_atlas ? ((shape->tex_b - shape->tex_t) / shape->tex->getPixelHeight()) :
			(shape->tex->getHeight() / shape->tex->getPixelHeight());
	for (int i = 0; i < count; i++) {
		cpVect v = cpvadd(body->p, cpvrotate(verts[i], body->rot));
		VAR[2 * i] = v.x;
		VAR[2 * i + 1] = v.y;

		TEX[2 * i] = off_s + (verts[i].x / poly->origin_w + 0.5f) * wrap_s;
		TEX[2 * i + 1] = off_t + (poly->origin_h / 2.0f - verts[i].y) / poly->origin_h * wrap_t;
	}

	// drawing
	glDrawArrays(GL_TRIANGLE_FAN, 0, count);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POINT_SMOOTH);

	free(VAR);
	free(TEX);
}

static void drawObject(void *ptr, void *data) {
	cpShape *shape = (cpShape *) ptr;
	cpBody *body = shape->body;
	drawSpaceOptions* options = (drawSpaceOptions*)data;

	switch (shape->klass->type) {
		case CP_CIRCLE_SHAPE:
			if(options->debugDraw)
				debugDrawCircleShape(body, (cpCircleShape *) shape);
			else
				drawCircleShape(body, (cpCircleShape *) shape);
			break;
		case CP_SEGMENT_SHAPE:
			if(options->debugDraw)
				debugDrawSegmentShape(body, (cpSegmentShape *) shape);
			else
				drawSegmentShape(body, (cpSegmentShape *) shape);
			break;
		case CP_POLY_SHAPE:
			if(options->debugDraw)
				debugDrawPolyShape(body, (cpPolyShape*)shape);
			else
				drawPolyShape(body, (cpPolyShape *) shape);
			break;
		default:
			printf("Bad enumeration in drawObject().\n");
	}
}

static const GLfloat springVAR[] = { 0.00f, 0.0f, 0.20f, 0.0f, 0.25f, 3.0f,
		0.30f, -6.0f, 0.35f, 6.0f, 0.40f, -6.0f, 0.45f, 6.0f, 0.50f, -6.0f,
		0.55f, 6.0f, 0.60f, -6.0f, 0.65f, 6.0f, 0.70f, -3.0f, 0.75f, 6.0f,
		0.80f, 0.0f, 1.00f, 0.0f, };
static const int springVAR_count = sizeof(springVAR) / sizeof(GLfloat) / 2;

static void drawSpring(cpDampedSpring *spring, cpBody *body_a, cpBody *body_b) {
	cpVect a = cpvadd(body_a->p, cpvrotate(spring->anchr1, body_a->rot));
	cpVect b = cpvadd(body_b->p, cpvrotate(spring->anchr2, body_b->rot));

	glPointSize(5.0f);
	wyDrawLine(a.x, a.y, b.x, b.y);

	cpVect delta = cpvsub(b, a);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, springVAR);
	glPushMatrix();
	{
		GLfloat x = a.x;
		GLfloat y = a.y;
		GLfloat cos = delta.x;
		GLfloat sin = delta.y;
		GLfloat s = 1.0f / cpvlength(delta);

		const GLfloat matrix[] = { cos, sin, 0.0f, 0.0f, -sin * s, cos * s,
				0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, x, y, 0.0f, 1.0f, };

		glMultMatrixf(matrix);
		glDrawArrays(GL_LINE_STRIP, 0, springVAR_count);
	}
	glPopMatrix();
	glDisableClientState(GL_VERTEX_ARRAY);
}

static void drawConstraint(cpConstraint *constraint) {
	cpBody *body_a = constraint->a;
	cpBody *body_b = constraint->b;

	const cpConstraintClass *klass = constraint->klass;
	if (klass == cpPinJointGetClass()) {
		cpPinJoint *joint = (cpPinJoint *) constraint;

		cpVect a = cpvadd(body_a->p, cpvrotate(joint->anchr1, body_a->rot));
		cpVect b = cpvadd(body_b->p, cpvrotate(joint->anchr2, body_b->rot));

		glPointSize(5.0f);
		wyDrawPoint(a.x, a.y);
		wyDrawPoint(b.x, b.y);

		wyDrawLine(a.x, a.y, b.x, b.y);
	} else if (klass == cpSlideJointGetClass()) {
		cpSlideJoint *joint = (cpSlideJoint *) constraint;

		cpVect a = cpvadd(body_a->p, cpvrotate(joint->anchr1, body_a->rot));
		cpVect b = cpvadd(body_b->p, cpvrotate(joint->anchr2, body_b->rot));

		glPointSize(5.0f);
		wyDrawPoint(a.x, a.y);
		wyDrawPoint(b.x, b.y);

		wyDrawLine(a.x, a.y, b.x, b.y);
	} else if (klass == cpPivotJointGetClass()) {
		cpPivotJoint *joint = (cpPivotJoint *) constraint;

		cpVect a = cpvadd(body_a->p, cpvrotate(joint->anchr1, body_a->rot));
		cpVect b = cpvadd(body_b->p, cpvrotate(joint->anchr2, body_b->rot));

		glPointSize(10.0f);
		wyDrawPoint(a.x, a.y);
		wyDrawPoint(b.x, b.y);
	} else if (klass == cpGrooveJointGetClass()) {
		cpGrooveJoint *joint = (cpGrooveJoint *) constraint;

		cpVect a = cpvadd(body_a->p, cpvrotate(joint->grv_a, body_a->rot));
		cpVect b = cpvadd(body_a->p, cpvrotate(joint->grv_b, body_a->rot));
		cpVect c = cpvadd(body_b->p, cpvrotate(joint->anchr2, body_b->rot));

		glPointSize(5.0f);
		wyDrawPoint(c.x, c.y);
		wyDrawLine(a.x, a.y, b.x, b.y);
	} else if (klass == cpDampedSpringGetClass()) {
		drawSpring((cpDampedSpring *) constraint, body_a, body_b);
	} else {
		//		printf("Cannot draw constraint\n");
	}
}

static void drawBB(void *ptr, void *unused) {
	cpShape *shape = (cpShape *) ptr;

	float vertices[] = {
			shape->bb.l, shape->bb.b,
			shape->bb.l, shape->bb.t,
			shape->bb.r, shape->bb.t,
			shape->bb.r, shape->bb.b
	};

	wyDrawPoly(vertices, 8, false);
}

static void drawCollisions(void *ptr, void *data) {
	cpArbiter *arb = (cpArbiter *) ptr;
	for (int i = 0; i < arb->numContacts; i++) {
		cpVect v = arb->contacts[i].p;
		wyDrawPoint(v.x, v.y);
	}
}

// copied from cpSpaceHash.c
static inline cpHashValue hash_func(cpHashValue x, cpHashValue y, cpHashValue n) {
	return (x * 1640531513ul ^ y * 2654435789ul) % n;
}

static void drawSpatialHash(cpSpaceHash *hash) {
	cpBB bb = cpBBNew(-320, -240, 320, 240);

	cpFloat dim = hash->celldim;
	int n = hash->numcells;

	int l = (int) floor(bb.l / dim);
	int r = (int) floor(bb.r / dim);
	int b = (int) floor(bb.b / dim);
	int t = (int) floor(bb.t / dim);

	for (int i = l; i <= r; i++) {
		for (int j = b; j <= t; j++) {
			int cell_count = 0;

			int index = hash_func(i, j, n);
			for (cpSpaceHashBin *bin = hash->table[index]; bin; bin = bin->next)
				cell_count++;

			GLfloat v = 1.0f - (GLfloat) cell_count / 10.0f;
			glColor4f(v, v, v, 1.0f);
		}
	}
}

void drawSpace(cpSpace *space, drawSpaceOptions *options) {
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
	glHint(GL_POINT_SMOOTH_HINT, GL_DONT_CARE);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	if (options->drawHash)
		drawSpatialHash(space->activeShapes);

	glLineWidth(1.0f);
	if (options->drawBBs) {
		cpSpaceHashEach(space->activeShapes, &drawBB, NULL);
		cpSpaceHashEach(space->staticShapes, &drawBB, NULL);
	}

	glLineWidth(options->lineThickness);
	if (options->drawShapes) {
		cpSpaceHashEach(space->activeShapes, &drawObject, options);
		cpSpaceHashEach(space->staticShapes, &drawObject, options);
	}

	if(options->debugDraw) {
		cpArray *constraints = space->constraints;
		for (int i = 0, count = constraints->num; i < count; i++) {
			drawConstraint((cpConstraint*)constraints->arr[i]);
		}
	}

	if (options->bodyPointSize) {
		cpArray *bodies = space->bodies;

		glPointSize(options->bodyPointSize);
		glColor4f(LINE_COLOR);
		for (int i = 0, count = bodies->num; i < count; i++) {
			cpBody *body = (cpBody *) bodies->arr[i];
			wyDrawPoint(body->p.x, body->p.y);
		}
	}

	if (options->collisionPointSize) {
		glPointSize(options->collisionPointSize);
		glColor4f(COLLISION_COLOR);
		cpArrayEach(space->arbiters, &drawCollisions, NULL);
	}

	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_POINT_SMOOTH);
}
