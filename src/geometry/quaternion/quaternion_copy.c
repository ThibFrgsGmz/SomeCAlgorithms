#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "quaternion_exp.h"

/**
 * Copies one quaternion to another.
 */
VOID_t
quaternion_copy(const Quaternion_t* q, Quaternion_t* output)
{
    quaternion_set(q->dx, q->fy, q->fz, q->dt, output);
    return;
}
