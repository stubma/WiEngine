#include <memory.h>
#include <stdlib.h>
#include "kazmath/utility.h"
#include "kazmath/vec3.h"
#include "kazmath/triangle.h"

static void calculateCenter(kmTriangle* pIn) {
	pIn->center = pIn->a;
	kmVec3Add(&(pIn->center), &(pIn->center), &(pIn->b));
	kmVec3Add(&(pIn->center), &(pIn->center), &(pIn->c));
	kmVec3Scale(&(pIn->center), &(pIn->center), kmOneThird);
}

static void calculateNormal(kmTriangle* pIn) {
	kmVec3 ca;

	pIn->normal = pIn->b;
	kmVec3Subtract(&(pIn->normal), &(pIn->normal), &(pIn->a));
	kmVec3Subtract(&ca, &(pIn->c), &(pIn->a));
	kmVec3Cross(&(pIn->normal), &(pIn->normal), &ca);
	kmVec3Normalize(&(pIn->normal), &(pIn->normal));
}

kmTriangle* kmTriangleCopy(kmTriangle* pOut, const kmTriangle* pIn) {
	memcpy(pOut, pIn, sizeof(kmTriangle));
	return pOut;
}

kmTriangle* kmTriangleFill(kmTriangle* pOut, const kmVec3* a, const kmVec3* b, const kmVec3* c) {
	memset(pOut, 0, sizeof(kmTriangle));
	kmVec3Fill(&(pOut->a), a->x, a->y, a->z);
	kmVec3Fill(&(pOut->b), b->x, b->y, b->z);
	kmVec3Fill(&(pOut->c), c->x, c->y, c->z);
	calculateCenter(pOut);
	calculateNormal(pOut);
	return pOut;
}

kmVec3* kmTriangleGetPoint(kmTriangle* pIn, int index) {
	switch(index) {
		case 0:
			return &(pIn->a);
		case 1:
			return &(pIn->b);
		case 2:
			return &(pIn->c);
		default:
			return NULL;
	}
}

kmTriangle* kmTriangleSetPoint(kmTriangle* pIn, int index, const kmVec3* p) {
	switch(index) {
		case 0:
			kmVec3Fill(&(pIn->a), p->x, p->y, p->z);
			break;
		case 1:
			kmVec3Fill(&(pIn->b), p->x, p->y, p->z);
			break;
		case 2:
			kmVec3Fill(&(pIn->c), p->x, p->y, p->z);
			break;
	}

	calculateCenter(pIn);
	calculateNormal(pIn);

	return pIn;
}

kmTriangle* kmTriangleSet(kmTriangle* pIn, const kmVec3* a, const kmVec3* b, const kmVec3* c) {
	kmVec3Fill(&(pIn->a), a->x, a->y, a->z);
	kmVec3Fill(&(pIn->b), b->x, b->y, b->z);
	kmVec3Fill(&(pIn->c), c->x, c->y, c->z);
	calculateCenter(pIn);
	calculateNormal(pIn);
	return pIn;
}
