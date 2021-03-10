#include <assert.h>
#include "quaternion_exp.h"

VOID_t
quaternion_divide(const Quaternion_t* quat1, const Quaternion_t* quat2, Quaternion_t* output)
{
    assert(output != NULL);

    Real64_t fQuat2Norm =   0.0f;
    Real64_t fqwOutput  =   0.0f;
    Real64_t fq1Output  =   0.0f;
    Real64_t fq2Output  =   0.0f;
    Real64_t fq3Output  =   0.0f;

    fQuat2Norm = (quat2->dx * quat2->dx);
    fQuat2Norm = fQuat2Norm + (quat2->fy * quat2->fy);
    fQuat2Norm = fQuat2Norm + (quat2->fz * quat2->fz);
    fQuat2Norm = fQuat2Norm + (quat2->dt * quat2->dt);

    if (fQuat2Norm <= EPSILON)
    {
        /*
        qwOutput = (quat1->dx * quat2->dx + quat1->fy * quat2->fy + quat1->fz * quat2->fz + quat1->dt * quat2->dt) / fQuat2Norm;
        fq1Output = (-quat1->dx * quat2->fy + quat1->fy * quat2->dx - quat1->fz * quat2->dt + quat1->dt * quat2->fz) / fQuat2Norm;
        fq2Output = (-quat1->dx * quat2->fz + quat1->fy * quat2->dt + quat1->fz * quat2->dx - quat1->dt * quat2->fy) / fQuat2Norm;
        fq3Output = (-quat1->dx * quat2->dt - quat1->fy * quat2->fz + quat1->fz * quat2->fy + quat1->dt * quat2->dx) / fQuat2Norm;
        */

        /* from https://fr.mathworks.com/help/aeroblks/quaterniondivision.html */

        fqwOutput = (quat1->dx * quat2->dx + quat1->fy * quat2->fy + quat1->fz * quat2->fz + quat1->dt * quat2->dt) / fQuat2Norm;
        
        fq1Output = (quat1->dx * quat2->fy - quat1->fy * quat2->dx - quat1->fz * quat2->dt + quat1->dt * quat2->fz) / fQuat2Norm;

        fq2Output = (quat1->dx * quat2->fz + quat1->fy * quat2->dt - quat1->fz * quat2->dx - quat1->dt * quat2->fy) / fQuat2Norm;

        fq3Output = (quat1->dx * quat2->dt - quat1->fy * quat2->fz + quat1->fz * quat2->fy - quat1->dt * quat2->dx) / fQuat2Norm;
    }
    else
    {
        /* Do nothing */
        ;
    }

    quaternion_set( fqwOutput, fq1Output, fq2Output, fq3Output, output);

    return;
}
