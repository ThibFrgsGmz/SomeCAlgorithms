#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "vector_3d_exp.h"

/**
 * Add one vector to another.
 *
 * @param[in] a vector to add to
 * @param[in] b vector to add
 * @returns resultant vector
 */
VOID_t
vector3d_add(const Vect3D_t *a, const Vect3D_t *b, Vect3D_t* out)
{
    assert((a != NULL) && (b != NULL) && (out != NULL));

    vector3d_set(a->fx + b->fx, a->fy + b->fy, a->fz + b->fz, out);
    
    return;
}
