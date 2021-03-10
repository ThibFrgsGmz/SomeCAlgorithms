#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "vector_3d_exp.h"

/**
 * Normalises the specified vector.
 */
VOID_t
vector3d_normalize(Vect3D_t *a)
{
    assert((a != NULL));

    Real64_t dInVecNorm   =   vector3d_get_norm(a);

    if (fabs(dInVecNorm) < EPSILON)
    {  
        /* Detect possible divide by 0 */
        ;
    }
    else
    {
        vector3d_set(a->fx / dInVecNorm, a->fy / dInVecNorm, a->fz / dInVecNorm, a);
    }
    
    return;
}
