#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quaternion_exp.h"

 /**
  * Sets the given values to the output quaternion.
  */
VOID_t
quaternion_set(Real64_t w, Real64_t v1, Real64_t v2, Real64_t v3, Quaternion_t* output)
{
    assert(output != NULL);
    output->dx = w;
    output->fy = v1;
    output->fz = v2;
    output->dt = v3;
    return;
}
