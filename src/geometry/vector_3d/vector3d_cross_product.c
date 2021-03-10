#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "vector_3d_exp.h"

/**
 * Computes the cross-product of the vectors axb and returnes a new vector.
 */
VOID_t
vector3d_cross_product(const Vect3D_t *a, const Vect3D_t* b, Vect3D_t* out)
{
    assert((a != NULL) && (b != NULL) && (out != NULL));

    Real64_t dOutput_x;
    Real64_t dOutput_y;
    Real64_t dOutput_z;

    dOutput_x = (a->fy * b->fz - a->fz * b->fy);
    dOutput_y = (a->fz * b->fx - a->fx * b->fz);
    dOutput_z = (a->fx * b->fy - a->fy * b->fx);

    vector3d_set(dOutput_x, dOutput_y, dOutput_z, out);
    
    return;
}
