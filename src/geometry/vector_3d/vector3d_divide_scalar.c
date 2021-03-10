#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "vector_3d_exp.h"

/**
 * Divides all values of the vector by s and returnes new vector.
 */
VOID_t
vecto3d_divide_scalar(const Vect3D_t *a, Real64_t scalar, Vect3D_t* out)
{
    assert((a != NULL) && (out != NULL));

    if (scalar < EPSILON)
    {
        vector3d_set(0, 0, 0, out);
    }
    else
    {
        vector3d_multiply_scalar(a, (1.0f / scalar), out);
    }
    
    return;
}
