#include <assert.h>
#include <math.h>
#include "quaternion_exp.h"


VOID_t
quaternion_exp(const Quaternion_t* q, Quaternion_t* output)
{
    assert(output != NULL);
    Real64_t s;
    Real64_t e;
    Real64_t fq1Squared = q->fy * q->fy;
    Real64_t fq2Squared = q->fz * q->fz;
    Real64_t fq3Squared = q->dt * q->dt;

    Real64_t fVectSquaredNorm = fq1Squared + fq2Squared + fq3Squared;

    Real64_t fVectNorm = sqrt(fVectSquaredNorm);

    if (fVectNorm > _QUATERNION_EPS)
    {
        s = sin(fVectNorm) / fVectNorm;
        e = exp(q->dx);

        quaternion_set(e * cos(fVectNorm), e * s * q->fy, e * s * q->fz, e * s * q->dt, output);
    }
    else
    {
        quaternion_set(exp(q->dx), 0, 0, 0, output);
    }
    return;
}
