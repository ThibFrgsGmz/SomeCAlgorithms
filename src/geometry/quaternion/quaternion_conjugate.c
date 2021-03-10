#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quaternion_exp.h"

/* The conjugate of a quaternion is calculated by by reversing the polarity (or negating) the
  vector part of the quaternion (w, -v)
 */
VOID_t
quaternion_conjugate(const Quaternion_t* q, Quaternion_t* output)
{
    assert(output != NULL);
    output->dx = q->dx;

    output->fy = -q->fy;
    output->fz = -q->fz;
    output->dt = -q->dt;

    /* A TESTER */
    output->dS = q->dS;
    vector3d_multiply_scalar(&q->rV, -1.0, &output->rV);

    return;
}
