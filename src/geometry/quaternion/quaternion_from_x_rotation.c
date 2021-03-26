#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quaternion_exp.h"

/**
 * Set the quaternion to the equivalent a rotation around the X-axis.
 * @param angle
 *      Rotation angle in radians.
 */
VOID_t
quaternion_from_x_rotation(Real64_t angle, Quaternion_t* output)
{
    assert(output != NULL);

    Real64_t axis[3] = { 1.0f, 0.0f, 0.0f };

    quaternion_from_axis_angle(axis, angle, output);
    
    return;
}
