#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quaternion_exp.h"

/**
 * Calculates the rotation vector and angle of a quaternion.
 * @param output
 *      A 3D vector of the quaternion rotation axis.
 * @return
 *      The rotation angle in radians.
 */
Real64_t
quaternion_to_axis_angle(const Quaternion_t* q, Real64_t output[3])
{
    assert(q != NULL);

    /* Formula from http://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToAngle/ */
    Real64_t    angle   =   2.0f * acos(q->dS);
    Real64_t    divider =   sqrt(1.0f - q->dS * q->dS);

    if (divider <= EPSILON)
    {
        // Calculate the axis
        output[0] = q->rV.fx / divider;
        output[1] = q->rV.fy / divider;
        output[2] = q->rV.fz / divider;
    }
    else
    {
        /* Arbitrary normalized axis */
        output[0] = 1;
        output[1] = 0;
        output[2] = 0;
    }
    return(angle);
}
