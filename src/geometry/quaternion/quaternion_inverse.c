
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quaternion_exp.h"

/* The quaternion inverse is computed by dividing its conjugate by its magnitude squared */
VOID_t
quaternion_inverse(const Quaternion_t* q, Quaternion_t* output)
{
    assert((q != NULL) && (output != NULL));
    
    Real64_t fMagnitudeSquared;

    Quaternion_t quat_conjugate;

    quaternion_conjugate(q, &quat_conjugate);

    fMagnitudeSquared = quaternion_magnitude(q) * quaternion_magnitude(q);

    if (fMagnitudeSquared < QUATERNION_EPS)
    {
        quaternion_set(0, 0, 0, 0, output);
    }
    else
    {
        quaternion_multiply_scalar(&quat_conjugate, 1.0 / fMagnitudeSquared, output);
    }

    return;
}
