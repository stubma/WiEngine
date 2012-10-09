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
 
 struct cpArbiter;
 struct cpSpace;
 struct cpCollisionHandler;

// Determines how fast penetrations resolve themselves.
extern CHIPMUNK_API cpFloat cp_bias_coef;
// Amount of allowed penetration. Used to reduce vibrating contacts.
extern CHIPMUNK_API cpFloat cp_collision_slop;

// Data structure for contact points.
typedef struct CHIPMUNK_API cpContact {
	// Contact point and normal.
	cpVect CP_PRIVATE(p), CP_PRIVATE(n);
	// Penetration distance.
	CP_PRIVATE(cpFloat dist);
	
	// Calculated by cpArbiterPreStep().
	cpVect CP_PRIVATE(r1), CP_PRIVATE(r2);
	cpFloat CP_PRIVATE(nMass), CP_PRIVATE(tMass), CP_PRIVATE(bounce);

	// Persistant contact information.
	cpFloat CP_PRIVATE(jnAcc), CP_PRIVATE(jtAcc), CP_PRIVATE(jBias);
	CP_PRIVATE(cpFloat bias);
	
	// Hash value used to (mostly) uniquely identify a contact.
	CP_PRIVATE(cpHashValue hash);
} cpContact;

// Contacts are always allocated in groups.
CHIPMUNK_API cpContact* cpContactInit(cpContact *con, cpVect p, cpVect n, cpFloat dist, cpHashValue hash);

// Sum the contact impulses. (Can be used after cpSpaceStep() returns)
CHIPMUNK_API cpVect CP_PRIVATE(cpContactsSumImpulses)(cpContact *contacts, int numContacts);
CHIPMUNK_API cpVect CP_PRIVATE(cpContactsSumImpulsesWithFriction)(cpContact *contacts, int numContacts);

#define CP_MAX_CONTACTS_PER_ARBITER 6

typedef enum cpArbiterState {
	cpArbiterStateNormal,
	cpArbiterStateFirstColl,
	cpArbiterStateIgnore,
	cpArbiterStateSleep,
	cpArbiterStateCached,
} cpArbiterState;

// Data structure for tracking collisions between shapes.
typedef struct CHIPMUNK_API cpArbiter {
	// Information on the contact points between the objects.
	CP_PRIVATE(int numContacts);
	CP_PRIVATE(cpContact *contacts);
	
	// The two shapes and bodies involved in the collision.
	// These variables are NOT in the order defined by the collision handler.
	// Using CP_ARBITER_GET_SHAPES and CP_ARBITER_GET_BODIES will save you from
	// many headaches
	cpShape CP_PRIVATE(*a), CP_PRIVATE(*b);
	
	// Calculated before calling the pre-solve collision handler
	// Override them with custom values if you want specialized behavior
	CP_PRIVATE(cpFloat e);
	CP_PRIVATE(cpFloat u);
	 // Used for surface_v calculations, implementation may change
	CP_PRIVATE(cpVect surface_vr);
	
	// Time stamp of the arbiter. (from cpSpace)
	CP_PRIVATE(cpTimestamp stamp);
	
	CP_PRIVATE(struct cpCollisionHandler *handler);
	
	// Are the shapes swapped in relation to the collision handler?
	CP_PRIVATE(cpBool swappedColl);
	CP_PRIVATE(cpArbiterState state);
} cpArbiter;

// Arbiters are allocated in large buffers by the space and don't require a destroy function
CHIPMUNK_API cpArbiter* CP_PRIVATE(cpArbiterInit)(cpArbiter *arb, cpShape *a, cpShape *b);

// These functions are all intended to be used internally.
// Inject new contact points into the arbiter while preserving contact history.
CHIPMUNK_API void CP_PRIVATE(cpArbiterUpdate)(cpArbiter *arb, cpContact *contacts, int numContacts, struct cpCollisionHandler *handler, cpShape *a, cpShape *b);
// Precalculate values used by the solver.
CHIPMUNK_API void CP_PRIVATE(cpArbiterPreStep)(cpArbiter *arb, cpFloat dt_inv);
CHIPMUNK_API void CP_PRIVATE(cpArbiterApplyCachedImpulse)(cpArbiter *arb);
// Run an iteration of the solver on the arbiter.
CHIPMUNK_API void CP_PRIVATE(cpArbiterApplyImpulse)(cpArbiter *arb, cpFloat eCoef);

// Arbiter Helper Functions
CHIPMUNK_API cpVect cpArbiterTotalImpulse(cpArbiter *arb);
CHIPMUNK_API cpVect cpArbiterTotalImpulseWithFriction(cpArbiter *arb);
CHIPMUNK_API void cpArbiterIgnore(cpArbiter *arb);


static inline void
cpArbiterGetShapes(const cpArbiter *arb, cpShape **a, cpShape **b)
{
	if(arb->CP_PRIVATE(swappedColl)){
		(*a) = arb->CP_PRIVATE(b), (*b) = arb->CP_PRIVATE(a);
	} else {
		(*a) = arb->CP_PRIVATE(a), (*b) = arb->CP_PRIVATE(b);
	}
}
#define CP_ARBITER_GET_SHAPES(arb, a, b) cpShape *a, *b; cpArbiterGetShapes(arb, &a, &b);

static inline void
cpArbiterGetBodies(const cpArbiter *arb, cpBody **a, cpBody **b)
{
	CP_ARBITER_GET_SHAPES(arb, shape_a, shape_b);
	(*a) = shape_a->body;
	(*b) = shape_b->body;
}
#define CP_ARBITER_GET_BODIES(arb, a, b) cpBody *a, *b; cpArbiterGetBodies(arb, &a, &b);

static inline cpBool
cpArbiterIsFirstContact(const cpArbiter *arb)
{
	return arb->CP_PRIVATE(state) == cpArbiterStateFirstColl;
}

static inline int
cpArbiterGetCount(const cpArbiter *arb)
{
	return arb->CP_PRIVATE(numContacts);
}

static inline cpVect
cpArbiterGetNormal(const cpArbiter *arb, int i)
{
	cpVect n = arb->CP_PRIVATE(contacts)[i].CP_PRIVATE(n);
	return arb->CP_PRIVATE(swappedColl) ? cpvneg(n) : n;
}

static inline cpVect
cpArbiterGetPoint(const cpArbiter *arb, int i)
{
	return arb->CP_PRIVATE(contacts)[i].CP_PRIVATE(p);
}

static inline cpFloat
cpArbiteGetDepth(const cpArbiter *arb, int i)
{
	return arb->CP_PRIVATE(contacts)[i].CP_PRIVATE(dist);
}

typedef struct CHIPMUNK_API cpContactPointSet {
	int count;
	
	struct {
		cpVect point, normal;
		cpFloat dist;
	} points[CP_MAX_CONTACTS_PER_ARBITER];
} cpContactPointSet;

static inline cpContactPointSet
cpArbiterGetContactPointSet(const cpArbiter *arb)
{
	cpContactPointSet set;
	set.count = cpArbiterGetCount(arb);
	
	int i;
	for(i=0; i<set.count; i++){
		set.points[i].point = arb->CP_PRIVATE(contacts)[i].CP_PRIVATE(p);
		set.points[i].normal = arb->CP_PRIVATE(contacts)[i].CP_PRIVATE(n);
		set.points[i].dist = arb->CP_PRIVATE(contacts)[i].CP_PRIVATE(dist);
	}
	
	return set;
}
