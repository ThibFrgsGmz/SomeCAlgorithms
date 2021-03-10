/**
 * @file
 * @brief Functions related to 3D quaternions and Euler angles.
 * Quaternions extend the concept of three-dimensional rotation to four-dimensional rotation.
 * This avoids the problem of "gimbal-lock" and allows a smooth and continuous rotation.
 *
 * Indeed, they can be considered as adding an additional rotation angle to the spherical coordinates,
 * i.e. longitude, latitude and rotation angles.
 * A Quaternion is defined using four floating point values |x y z w|.
 * They are calculated from the combination of the three coordinates of the rotation axis 
 * and the rotation angle.
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "quaternion_exp.h"

VOID_t
quaternion_test()
{
    EulerAngles_t   eul;
    Quaternion_t    test_quat;
    Quaternion_t    quat_prod_out;
    Quaternion_t    quat = { 0.7071f, 0.7071f, 0.f, 0.f };

    quaternion_to_euler(&quat, &eul);

    quaternion_from_euler(&eul, &test_quat);
    
    printf("Euler: %.4g, %.4g, %.4g\n", eul.fPitch, eul.fRoll, eul.fYaw);

    printf("Quaternion: %.4g %+.4g %+.4g %+.4g\n",  test_quat.dx,
                                                    test_quat.fy,
                                                    test_quat.fz,
                                                    test_quat.dt);
    
    quaternion_multiply(&quat, &test_quat, &quat_prod_out);
    assert(fabs(test_quat.dx - quat.dx) < .01);
    assert(fabs(test_quat.fy - quat.fy) < .01);
    assert(fabs(test_quat.fz - quat.fz) < .01);
    assert(fabs(test_quat.dt - quat.dt) < .01);
}
