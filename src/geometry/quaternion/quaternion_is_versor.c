#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quaternion_exp.h"

/**
 * Check if the quaternion is a versor.
 * NOTE: a versor is a quaternion of norm one (a unit quaternion).
 */
Bool_t
quaternion_is_versor(const Quaternion_t* q)
{
    assert(q != NULL);
 
    Bool_t  IsVersor;
    Real64_t fQuat2Norm = 0.0f;

    fQuat2Norm = (q->dx * q->dx);
    fQuat2Norm = fQuat2Norm + (q->fy * q->fy);
    fQuat2Norm = fQuat2Norm + (q->fz * q->fz);
    fQuat2Norm = fQuat2Norm + (q->dt * q->dt);

    if ( (fQuat2Norm + EPSILON >= 1.0f ) && (fQuat2Norm - EPSILON >= 1.0f))
    {
        IsVersor  =   TRUE;
    }
    else
    {
        IsVersor  =   FALSE;
    }
    return (IsVersor);
}
