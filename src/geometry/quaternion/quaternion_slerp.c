
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "quaternion_exp.h"

/**
 * Interpolates between two quaternions.
 * @param t
 *      Interpolation between the two quaternions [0, 1].
 *      0 is equal with q1, 1 is equal with q2, 0.5 is the middle between q1 and q2.
 */
VOID_t
quaternion_slerp(const Quaternion_t* q1, const Quaternion_t* q2, Real64_t t, Quaternion_t* output)
{
    assert((q1 != NULL) && (q2 != NULL) && (output != NULL));

    Real64_t    cosHalfTheta;
    Real64_t    halfTheta;
    Real64_t    sinHalfTheta;
    Real64_t    ratioA;
    Real64_t    ratioB;

    // Based on http://www.euclideanspace.com/maths/algebra/realNormedAlgebra/quaternions/slerp/index.htm
    cosHalfTheta = q1->dx * q2->dx + q1->fy * q2->fy + q1->fz * q2->fz + q1->dt * q2->dt;

    // if q1=q2 or q1=-q2 then theta = 0 and we can return q1
    if (fabs(cosHalfTheta) >= 1.0)
    {
        quaternion_copy(q1, output);
    }
    else
    {
        halfTheta       =   acos(cosHalfTheta);
        sinHalfTheta    =   sqrt(1.0 - cosHalfTheta * cosHalfTheta);

        // If theta = 180 degrees then result is not fully defined
        // We could rotate around any axis normal to q1 or q2
        if (fabs(sinHalfTheta) < QUATERNION_EPS)
        {
            quaternion_set( (q1->dx  * 0.5 + q2->dx  * 0.5),
                            (q1->fy * 0.5 + q2->fy * 0.5),
                            (q1->fz * 0.5 + q2->fz * 0.5),
                            (q1->dt * 0.5 + q2->dt * 0.5),
                            output);
            
            /*
            output->dx = (q1->dx * 0.5 + q2->dx * 0.5);
            output->fy = (q1->fy * 0.5 + q2->fy * 0.5);
            output->fz = (q1->fz * 0.5 + q2->fz * 0.5);
            output->dt = (q1->dt * 0.5 + q2->dt * 0.5);
            */
        }
        else
        {        
            /* Calculate Quaternion */
            ratioA = sin((1 - t) * halfTheta) / sinHalfTheta;
            ratioB = sin(t * halfTheta) / sinHalfTheta;

            /*
            output->dx = (q1->dx * ratioA + q2->dx * ratioB);
            output->fy = (q1->fy * ratioA + q2->fy * ratioB);
            output->fz = (q1->fz * ratioA + q2->fz * ratioB);
            output->dt = (q1->dt * ratioA + q2->dt * ratioB);
            */
            quaternion_set((q1->dx * ratioA + q2->dx * ratioB),
                (q1->fy * ratioA + q2->fy * ratioB),
                (q1->fz * ratioA + q2->fz * ratioB),
                (q1->dt * ratioA + q2->dt * ratioB),
                output);
        }
    }
    return;
}