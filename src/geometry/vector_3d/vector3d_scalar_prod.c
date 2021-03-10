#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "vector_3d_exp.h"

/**
 * Obtain the dot product of two 3D vectors.
 *
 * @param[in] a first vector
 * @param[in] b second vector
 * @returns resulting dot product
 */
Real64_t
vector3d_scalar_prod(const Vect3D_t *vect_a, const Vect3D_t *vect_b)
{
    assert((vect_a != NULL) && (vect_b != NULL));

    Real64_t fProdRes;

    fProdRes = vect_a->fx * vect_b->fx;
    fProdRes = fProdRes + (vect_a->fy * vect_b->fy);
    fProdRes = fProdRes + (vect_a->fz * vect_b->fz);
    
    return (fProdRes);
}
