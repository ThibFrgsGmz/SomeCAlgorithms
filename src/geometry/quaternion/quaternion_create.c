#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quaternion_exp.h"

 /**
  * Creates a new Quaternion.
  */
VOID_t
quaternion_create(const Vect3D_t* v1, Real64_t angle, Quaternion_t* output)
{
    assert((v1 != NULL) && (output != NULL));

    output->dx = cos(angle / 2.0f);

    vector3d_multiply_scalar(v1, sin(angle / 2.0), &output->rV);

    return;
}
