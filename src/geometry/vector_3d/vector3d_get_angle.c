#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "vector_3d_exp.h"
#include "geometry_utils_exp.h"

/**
 * Calculates the angle between two vectors (not radiant!).
 */
Real64_t
vector3d_get_angle(Vect3D_t* a, Vect3D_t* b)
{
    Real64_t dAngle;

    dAngle = mtRadToDeg(acos(vector3d_scalar_prod(a, b)));

    dAngle = dAngle / ( vector3d_get_norm(a) * vector3d_get_norm(b));

    return(dAngle);
}