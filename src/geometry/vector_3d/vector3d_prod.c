#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "vector_3d_exp.h"

/**
 * Compute the vector product of two 3d vectors.
 *
 * @param[in] a first vector @f$\vec{a}@f$
 * @param[in] b second vector @f$\vec{b}@f$
 * @returns resultant vector @f$\vec{o}=\vec{a}\times\vec{b}@f$
 */
VOID_t
vector3d_prod(const Vect3D_t *a, const Vect3D_t *b, Vect3D_t* out)
{
    assert((a != NULL) && (b != NULL) && (out != NULL));

    Real64_t fOutputX;
    Real64_t fOutputY;
    Real64_t fOutputZ;

    fOutputX =  a->fy * b->fz - a->fz * b->fy;
    fOutputY =  -a->fx * b->fz + a->fz * b->fx;
    fOutputZ =  a->fx * b->fy - a->fy * b->fx;
    
    vector3d_set(fOutputX, fOutputY, fOutputZ, out);
        
    return;
}
