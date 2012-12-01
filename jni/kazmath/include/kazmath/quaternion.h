/*
Copyright (c) 2008, Luke Benstead.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef QUATERNION_H_INCLUDED
#define QUATERNION_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "kazmath/utility.h"

struct kmMat4;
struct kmMat3;
struct kmVec3;

typedef struct kmQuaternion {
	kmScalar x;
	kmScalar y;
	kmScalar z;
	kmScalar w;
} kmQuaternion;

KAZMATH_API kmQuaternion* const kmQuaternionConjugate(kmQuaternion* pOut, const kmQuaternion* pIn); ///< Returns pOut, sets pOut to the conjugate of pIn

KAZMATH_API const kmScalar 	kmQuaternionDot(const kmQuaternion* q1, const kmQuaternion* q2); ///< Returns the dot product of the 2 quaternions

KAZMATH_API kmQuaternion* kmQuaternionExp(kmQuaternion* pOut, const kmQuaternion* pIn); ///< Returns the exponential of the quaternion

///< Makes the passed quaternion an identity quaternion

KAZMATH_API kmQuaternion* kmQuaternionIdentity(kmQuaternion* pOut);

///< Returns the inverse of the passed Quaternion

KAZMATH_API kmQuaternion* kmQuaternionInverse(kmQuaternion* pOut,
											const kmQuaternion* pIn);

///< Returns true if the quaternion is an identity quaternion

KAZMATH_API int kmQuaternionIsIdentity(const kmQuaternion* pIn);

///< Returns the length of the quaternion

KAZMATH_API kmScalar kmQuaternionLength(const kmQuaternion* pIn);

///< Returns the length of the quaternion squared (prevents a sqrt)

KAZMATH_API kmScalar kmQuaternionLengthSq(const kmQuaternion* pIn);

///< Returns the natural logarithm

KAZMATH_API kmQuaternion* kmQuaternionLn(kmQuaternion* pOut, const kmQuaternion* pIn);

///< Multiplies 2 quaternions together

KAZMATH_API kmQuaternion* kmQuaternionMultiply(kmQuaternion* pOut, const kmQuaternion* q1, const kmQuaternion* q2);

///< Normalizes a quaternion

KAZMATH_API kmQuaternion* kmQuaternionNormalize(kmQuaternion* pOut, const kmQuaternion* pIn);

///< Rotates a quaternion around an axis

KAZMATH_API kmQuaternion* kmQuaternionRotationAxis(kmQuaternion* pOut, const struct kmVec3* pV, kmScalar angle);

///< Creates a quaternion from a rotation matrix

KAZMATH_API kmQuaternion* kmQuaternionRotationMatrix(kmQuaternion* pOut, const struct kmMat3* pIn);

///< Create a quaternion from yaw, pitch and roll

KAZMATH_API kmQuaternion* kmQuaternionRotationYawPitchRoll(kmQuaternion* pOut, kmScalar yaw, kmScalar pitch, kmScalar roll);
///< Interpolate between 2 quaternions
KAZMATH_API kmQuaternion* kmQuaternionSlerp(kmQuaternion* pOut, const kmQuaternion* q1, const kmQuaternion* q2, kmScalar t);

///< Get the axis and angle of rotation from a quaternion
KAZMATH_API void kmQuaternionToAxisAngle(const kmQuaternion* pIn, struct kmVec3* pVector, kmScalar* pAngle);

///< Scale a quaternion
KAZMATH_API kmQuaternion* kmQuaternionScale(kmQuaternion* pOut, const kmQuaternion* pIn, kmScalar s);
KAZMATH_API kmQuaternion* kmQuaternionAssign(kmQuaternion* pOut, const kmQuaternion* pIn);
KAZMATH_API kmQuaternion* kmQuaternionAdd(kmQuaternion* pOut, const kmQuaternion* pQ1, const kmQuaternion* pQ2);
KAZMATH_API kmQuaternion* kmQuaternionRotationBetweenVec3(kmQuaternion* pOut, const struct kmVec3* vec1, const struct kmVec3* vec2, const struct kmVec3* fallback);
KAZMATH_API struct kmVec3* kmQuaternionMultiplyVec3(struct kmVec3* pOut, const kmQuaternion* q, const struct kmVec3* v);

#ifdef __cplusplus
}
#endif

#endif
