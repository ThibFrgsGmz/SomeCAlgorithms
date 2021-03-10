#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "vector_3d_exp.h"

/**
 * Compute the norm a vector.

 * @param[in] a input vector
 * @returns norm of the given vector
 */
Real64_t
vector3d_get_norm(const Vect3D_t *a)
{
    assert((a != NULL));

    Real64_t dVectNorm = vector3d_scalar_prod(a, a);

    dVectNorm = sqrt(dVectNorm);
    
    return (dVectNorm);
}
