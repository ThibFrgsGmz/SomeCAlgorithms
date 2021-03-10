#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quaternion_exp.h"

 /* The quaternion magnitude is a scalar value that is equal to the four dimensional Euclidean norm
  which is simply the square root of the sum of the squares of the four components. */
Real64_t
quaternion_magnitude(const Quaternion_t* quat)
{
    assert(quat != NULL);

    Real64_t fQuatMag;
    Real64_t fq0Square;
    Real64_t fq1Square;
    Real64_t fq2Square;
    Real64_t fq3Square;
    
    fq0Square = quat->dx * quat->dx;
    fq1Square = quat->fy * quat->fy;
    fq2Square = quat->fz * quat->fz;
    fq3Square = quat->dt * quat->dt;

    fQuatMag = sqrt(fq0Square + fq1Square + fq2Square + fq3Square);

    return(fQuatMag);
}