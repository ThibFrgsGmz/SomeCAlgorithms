#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quaternion_exp.h"

/**
 * Set the quaternion to the equivalent of axis-angle rotation.
 * @param axis
 *      The axis of the rotation (should be normalized).
 * @param angle
 *      Rotation angle in radians.
 */
VOID_t
quaternion_from_axis_angle(Real64_t axis[3], Real64_t angle, Quaternion_t* output)
{
    assert(output != NULL);

    Real64_t ScalarPart;
    Real64_t VectorPartFactor;

    ScalarPart          =   cos(angle / 2.0);
    VectorPartFactor    =   sin(angle / 2.0);

    quaternion_set( ScalarPart,
                    VectorPartFactor * axis[0],
                    VectorPartFactor * axis[1],
                    VectorPartFactor * axis[2],
                    output);
    return;
}
