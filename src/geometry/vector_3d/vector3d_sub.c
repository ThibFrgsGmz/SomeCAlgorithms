#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "vector_3d_exp.h"

/**
 * Subtract one vector from another.
 *
 * @param[in] a vector to subtract from
 * @param[in] b vector to subtract
 * @returns resultant vector
 */
VOID_t
vector3d_sub(const Vect3D_t *a, const Vect3D_t *b, Vect3D_t* out)
{
    assert( (a != NULL) && (b != NULL) && (out != NULL));

    vector3d_set(a->fx - b->fx, a->fy - b->fy, a->fz - b->fz, out);
    
    return;
}
