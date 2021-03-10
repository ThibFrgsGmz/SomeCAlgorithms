#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "vector_3d_exp.h"

 /**
  * Creates a new vector from three given values.
  */
VOID_t
vector3d_set(Real64_t x, Real64_t y, Real64_t z, Vect3D_t* output)
{
    assert(output != NULL);
    output->fx = x;
    output->fy = y;
    output->fz = z;
    return;
}
