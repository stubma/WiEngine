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

#ifndef __cpSpace_h__
#define __cpSpace_h__

struct cpSpace;

// Number of frames that contact information should persist.
extern CHIPMUNK_API cpTimestamp cp_contact_persistence;

// User collision handler function types.
typedef cpBool (*cpCollisionBeginFunc)(cpArbiter *arb, struct cpSpace *space, void *data);
typedef cpBool (*cpCollisionPreSolveFunc)(cpArbiter *arb, struct cpSpace *space, void *data);
typedef void (*cpCollisionPostSolveFunc)(cpArbiter *arb, struct cpSpace *space, void *data);
typedef void (*cpCollisionSeparateFunc)(cpArbiter *arb, struct cpSpace *space, void *data);

// Structure for holding collision pair function information.
// Used internally.
typedef struct CHIPMUNK_API cpCollisionHandler {
	cpCollisionType a;
	cpCollisionType b;
	cpCollisionBeginFunc begin;
	cpCollisionPreSolveFunc preSolve;
	cpCollisionPostSolveFunc postSolve;
	cpCollisionSeparateFunc separate;
	void *data;
} cpCollisionHandler;

typedef struct CHIPMUNK_API cpContactBufferHeader {
	cpTimestamp stamp;
	struct cpContactBufferHeader *next;
	unsigned int numContacts;
} cpContactBufferHeader;

typedef struct CHIPMUNK_API cpSpace{
	// *** User definable fields
	
	// Number of iterations to use in the impulse solver to solve contacts.
	int iterations;
	
	// Number of iterations to use in the impulse solver to solve elastic collisions.
	int elasticIterations;
	
	// Default gravity to supply when integrating rigid body motions.
	cpVect gravity;
	
	// Default damping to supply when integrating rigid body motions.
	cpFloat damping;
	
	// Speed threshold for a body to be considered idle.
	// The default value of 0 means to let the space guess a good threshold based on gravity.
	cpFloat idleSpeedThreshold;
	
	// Time a group of bodies must remain idle in order to fall asleep
	// The default value of INFINITY disables the sleeping algorithm.
	cpFloat sleepTimeThreshold;
	
	// *** Internally Used Fields
	
	// When the space lock count is non zero you cannot add or remove objects
	CP_PRIVATE(int locked);
	
	// Time stamp. Is incremented on every call to cpSpaceStep().
	CP_PRIVATE(cpTimestamp stamp);

	// The static and active shape spatial hashes.
	CP_PRIVATE(cpSpaceHash *staticShapes);
	CP_PRIVATE(cpSpaceHash *activeShapes);
	
	// List of bodies in the system.
	CP_PRIVATE(cpArray *bodies);
	
	// List of groups of sleeping bodies.
	CP_PRIVATE(cpArray *sleepingComponents);
	
	// List of bodies that have been flagged to be awoken.
	CP_PRIVATE(cpArray *rousedBodies);
	
	// List of active arbiters for the impulse solver.
	CP_PRIVATE(cpArray *arbiters);
	CP_PRIVATE(cpArray *pooledArbiters);
	
	// Linked list ring of contact buffers.
	// Head is the newest buffer, and each buffer points to a newer buffer.
	// Head wraps around and points to the oldest (tail) buffer.
	CP_PRIVATE(cpContactBufferHeader *contactBuffersHead);
	CP_PRIVATE(cpContactBufferHeader *_contactBuffersTail_Deprecated);
	
	// List of buffers to be free()ed when destroying the space.
	CP_PRIVATE(cpArray *allocatedBuffers);
	
	// Persistant contact set.
	CP_PRIVATE(cpHashSet *contactSet);
	
	// List of constraints in the system.
	CP_PRIVATE(cpArray *constraints);
	
	// Set of collisionpair functions.
	CP_PRIVATE(cpHashSet *collFuncSet);
	// Default collision handler.
	CP_PRIVATE(cpCollisionHandler defaultHandler);
	
	CP_PRIVATE(cpHashSet *postStepCallbacks);
	
	cpBody staticBody;
} cpSpace;

// Basic allocation/destruction functions.
CHIPMUNK_API cpSpace* cpSpaceAlloc(void);
CHIPMUNK_API cpSpace* cpSpaceInit(cpSpace *space);
CHIPMUNK_API cpSpace* cpSpaceNew(void);

CHIPMUNK_API void cpSpaceDestroy(cpSpace *space);
CHIPMUNK_API void cpSpaceFree(cpSpace *space);

// Convenience function. Frees all referenced entities. (bodies, shapes and constraints)
CHIPMUNK_API void cpSpaceFreeChildren(cpSpace *space);

// Collision handler management functions.
CHIPMUNK_API void cpSpaceSetDefaultCollisionHandler(
	cpSpace *space,
	cpCollisionBeginFunc begin,
	cpCollisionPreSolveFunc preSolve,
	cpCollisionPostSolveFunc postSolve,
	cpCollisionSeparateFunc separate,
	void *data
);
CHIPMUNK_API void cpSpaceAddCollisionHandler(
	cpSpace *space,
	cpCollisionType a, cpCollisionType b,
	cpCollisionBeginFunc begin,
	cpCollisionPreSolveFunc preSolve,
	cpCollisionPostSolveFunc postSolve,
	cpCollisionSeparateFunc separate,
	void *data
);
CHIPMUNK_API void cpSpaceRemoveCollisionHandler(cpSpace *space, cpCollisionType a, cpCollisionType b);

#if ANDROID
CHIPMUNK_API void cpSpaceAddCollisionHandler_jni(
	cpSpace *space,
	cpCollisionType a, cpCollisionType b,
	cpCollisionBeginFunc begin,
	cpCollisionPreSolveFunc preSolve,
	cpCollisionPostSolveFunc postSolve,
	cpCollisionSeparateFunc separate,
	void *data
);
CHIPMUNK_API void cpSpaceRemoveCollisionHandler_jni(cpSpace *space, cpCollisionType a, cpCollisionType b);
#endif

// Add and remove entities from the system.
CHIPMUNK_API cpShape *cpSpaceAddShape(cpSpace *space, cpShape *shape);
CHIPMUNK_API cpShape *cpSpaceAddStaticShape(cpSpace *space, cpShape *shape);
CHIPMUNK_API cpBody *cpSpaceAddBody(cpSpace *space, cpBody *body);
CHIPMUNK_API cpConstraint *cpSpaceAddConstraint(cpSpace *space, cpConstraint *constraint);

CHIPMUNK_API void cpSpaceRemoveShape(cpSpace *space, cpShape *shape);
CHIPMUNK_API void cpSpaceRemoveStaticShape(cpSpace *space, cpShape *shape);
CHIPMUNK_API void cpSpaceRemoveBody(cpSpace *space, cpBody *body);
CHIPMUNK_API void cpSpaceRemoveConstraint(cpSpace *space, cpConstraint *constraint);

// Post Step function definition
typedef void (*cpPostStepFunc)(cpSpace *space, void *obj, void *data);
// Register a post step function to be called after cpSpaceStep() has finished.
// obj is used a key, you can only register one callback per unique value for obj
CHIPMUNK_API void cpSpaceAddPostStepCallback(cpSpace *space, cpPostStepFunc func, void *obj, void *data);

// Point query callback function
typedef void (*cpSpacePointQueryFunc)(cpShape *shape, void *data);
CHIPMUNK_API void cpSpacePointQuery(cpSpace *space, cpVect point, cpLayers layers, cpGroup group, cpSpacePointQueryFunc func, void *data);
CHIPMUNK_API cpShape *cpSpacePointQueryFirst(cpSpace *space, cpVect point, cpLayers layers, cpGroup group);

// Segment query callback function
typedef void (*cpSpaceSegmentQueryFunc)(cpShape *shape, cpFloat t, cpVect n, void *data);
CHIPMUNK_API void cpSpaceSegmentQuery(cpSpace *space, cpVect start, cpVect end, cpLayers layers, cpGroup group, cpSpaceSegmentQueryFunc func, void *data);
CHIPMUNK_API cpShape *cpSpaceSegmentQueryFirst(cpSpace *space, cpVect start, cpVect end, cpLayers layers, cpGroup group, cpSegmentQueryInfo *out);

// BB query callback function
typedef void (*cpSpaceBBQueryFunc)(cpShape *shape, void *data);
CHIPMUNK_API void cpSpaceBBQuery(cpSpace *space, cpBB bb, cpLayers layers, cpGroup group, cpSpaceBBQueryFunc func, void *data);

// Shape query callback function
typedef void (*cpSpaceShapeQueryFunc)(cpShape *shape, cpContactPointSet *points, void *data);
CHIPMUNK_API cpBool cpSpaceShapeQuery(cpSpace *space, cpShape *shape, cpSpaceShapeQueryFunc func, void *data);


CHIPMUNK_API void cpSpaceActivateShapesTouchingShape(cpSpace *space, cpShape *shape);


// Iterator function for iterating the bodies in a space.
typedef void (*cpSpaceBodyIterator)(cpBody *body, void *data);
CHIPMUNK_API void cpSpaceEachBody(cpSpace *space, cpSpaceBodyIterator func, void *data);

// Spatial hash management functions.
CHIPMUNK_API void cpSpaceResizeStaticHash(cpSpace *space, cpFloat dim, int count);
CHIPMUNK_API void cpSpaceResizeActiveHash(cpSpace *space, cpFloat dim, int count);
CHIPMUNK_API void cpSpaceRehashStatic(cpSpace *space);

CHIPMUNK_API void cpSpaceRehashShape(cpSpace *space, cpShape *shape);

// Update the space.
CHIPMUNK_API void cpSpaceStep(cpSpace *space, cpFloat dt);

CHIPMUNK_API void cpSpacePostStepRemoveAndFreeShapeAndBody(cpSpace *space, cpShape *shape);
CHIPMUNK_API void cpSpaceRemoveAndDestroyShapesOfBody(cpSpace* space, cpBody* body);
CHIPMUNK_API cpArray* cpSpaceGetShapesOfBody(cpSpace* space, cpBody* body);

#endif // __cpSpace_h__
