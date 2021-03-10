#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quaternion_exp.h"

/**
 * Function to convert given Euler angles to a quaternion.
 * 
 * Converting Euler rotation angles to quaterions can be achieved through
 * the use of quaternion multiplication. Each rotation angle is converted 
 * to an axis-angle pair, with the axis corresponding to one of the 
 * Euclidean axii. The axis-angle pairs are converted to quaternions and 
 * multiplied together. The final quaternion is the desired result.
 * 
 * @param [in] in_euler input Euler angles instance
 * @returns converted quaternion
 */
VOID_t
quaternion_from_euler(const EulerAngles_t *in_euler, Quaternion_t* out_quat)
{
    assert(in_euler != NULL);

    Real64_t fCosYaw;
    Real64_t sSinYaw;
    Real64_t fCosPitch;
    Real64_t fSinPitch;
    Real64_t fCosRoll;
    Real64_t fSinRoll;

    fCosYaw     =   cos(in_euler->fYaw * 0.5f);
    sSinYaw     =   sin(in_euler->fYaw * 0.5f);
    fCosPitch   =   cos(in_euler->fPitch * 0.5f);
    fSinPitch   =   sin(in_euler->fPitch * 0.5f);
    fCosRoll    =   cos(in_euler->fRoll * 0.5f);
    fSinRoll    =   sin(in_euler->fRoll * 0.5f);

    out_quat->dx = fCosRoll * fCosPitch * fCosYaw + fSinRoll * fSinPitch * sSinYaw;
    out_quat->fy = fSinRoll * fCosPitch * fCosYaw - fCosRoll * fSinPitch * sSinYaw;
    out_quat->fz = fCosRoll * fSinPitch * fCosYaw + fSinRoll * fCosPitch * sSinYaw;
    out_quat->dt = fCosRoll * fCosPitch * sSinYaw - fSinRoll * fSinPitch * fCosYaw;

    /*
    * From https://math.stackexchange.com/questions/2975109/how-to-convert-euler-angles-to-quaternions-and-get-the-same-euler-angles-back-fr
    *
    (yaw, pitch, roll) = (r[0], r[1], r[2])
    qx = np.sin(roll / 2) * np.cos(pitch / 2) * np.cos(yaw / 2) - np.cos(roll / 2) * np.sin(pitch / 2) * np.sin(yaw / 2)
    qy = np.cos(roll / 2) * np.sin(pitch / 2) * np.cos(yaw / 2) + np.sin(roll / 2) * np.cos(pitch / 2) * np.sin(yaw / 2)
    qz = np.cos(roll / 2) * np.cos(pitch / 2) * np.sin(yaw / 2) - np.sin(roll / 2) * np.sin(pitch / 2) * np.cos(yaw / 2)
    qw = np.cos(roll / 2) * np.cos(pitch / 2) * np.cos(yaw / 2) + np.sin(roll / 2) * np.sin(pitch / 2) * np.sin(yaw / 2)
    return[qx, qy, qz, qw]
    */

    /*
    out_quat.fw = fSinRoll * fCosPitch * fCosYaw - fCosRoll * fSinPitch * sSinYaw;
    out_quat.fq1 = fCosRoll * fSinPitch * fCosYaw + fSinRoll * fCosPitch * sSinYaw;
    out_quat.fq2 = fCosRoll * fCosPitch * sSinYaw - fSinRoll * fSinPitch * fCosYaw;
    out_quat.fq3 = fCosRoll * fCosPitch * fCosYaw + fSinRoll * fSinPitch * sSinYaw;
    */
    return;
}