#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "vector_3d_exp.h"

/**
 * Obtain unit vector in the same direction as given vector.
 *
 * @param[in] a input vector
 * @returns n unit vector in the direction of @f$\vec{a}@f$
 */
VOID_t
vector3d_get_unit(const Vect3D_t *a, Vect3D_t* out)
{
    assert((a != NULL) && (out != NULL));

    Real64_t dInVecNorm   =   vector3d_get_norm(a);

    if (fabs(dInVecNorm) < EPSILON)
    {  
        /* Detect possible divide by 0 */
        ;
    }
    else
    {
        vector3d_set(a->fx / dInVecNorm, a->fy / dInVecNorm, a->fz / dInVecNorm, out);
    }
    
    return;
}
