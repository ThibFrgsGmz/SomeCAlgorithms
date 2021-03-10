#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quaternion_exp.h"

 /**
 * Function to convert given quaternion to Euler angles.
 *
 * @param [in] in_quat input quaternion instance
 * @returns converted euler angles
 */
VOID_t
quaternion_to_euler(const Quaternion_t *in_quat, EulerAngles_t* out_euler)
{
    assert(in_quat != NULL);
 
    out_euler->fRoll    = atan2( 2.f * (in_quat->dx * in_quat->fy + in_quat->fz * in_quat->dt),
                                 1.f - 2.f * (in_quat->fy * in_quat->fy + in_quat->fz * in_quat->fz));

    out_euler->fPitch   = asin(2.f * (in_quat->dx * in_quat->fz + in_quat->fy * in_quat->dt));

    out_euler->fYaw     = atan2( 2.f * (in_quat->dx * in_quat->dt + in_quat->fy * in_quat->fz),
                                 1.f - 2.f * (in_quat->fz * in_quat->fz + in_quat->dt * in_quat->dt));
    return;
}
