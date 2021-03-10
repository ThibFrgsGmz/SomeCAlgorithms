#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "vector_3d_exp.h"

/**
 * Multiplies vector with scalar and returnes new vector.
 */
VOID_t
vector3d_multiply_scalar(const Vect3D_t *a, Real64_t scalar, Vect3D_t* out)
{
    assert((a != NULL) && (out != NULL));

    out->fx = a->fx * scalar;
    out->fy = a->fy * scalar;
    out->fz = a->fz * scalar;
    
    return;
}
