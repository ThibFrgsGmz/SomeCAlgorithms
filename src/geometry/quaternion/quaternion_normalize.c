#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quaternion_exp.h"

/**
 * Normalizes the quaternion.
 * 
 * A quaternion shall be normalized to represent a valid 3D orientation or to compute valid vector rotations.
 * Normalized quaternions, or versors, have the special property that their conjugate is equal to 
 * their inverse.
 * When quaternions are used in numerical simulations to represent orientations,
 * the quaternion must be renormalized at frequent intervals to account for the accumulation of
 * numerical round off error.
 * A normalized quaternion (or unit quaternion) is computed by simply dividing the quaternion by its magnitude.
 */
VOID_t
quaternion_normalize(const Quaternion_t* q, Quaternion_t* output)
{
    assert((q != NULL) && (output != NULL));

    Real64_t len;

    len = quaternion_magnitude(q);

    if (len < QUATERNION_EPS)
    {
        quaternion_set(0, 0, 0, 0, output);
    }
    else
    {
        quaternion_set(
            q->dx / len,
            q->fy / len,
            q->fz / len,
            q->dt / len,
            output);

        /* OR */
        output->dS = q->dx / len;

        vector3d_multiply_scalar(&q->rV, 1.0 / len, &output->rV);
    }

    return;
}
