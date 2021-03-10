#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "vector_3d_exp.h"

/**
 * The cross product of vectors can be represented as a matrix
 * multiplication operation. This function obtains the `3x3` matrix
 * of the cross-product operator from the first vector.
 * 
 */
VOID_t
vector3d_get_cross_matrix(const Vect3D_t *a, Matrix3x3_t* out)
{
    Matrix3x3_t A = { 0.0f, -a->fz, a->fy, a->fz, 0.0f, -a->fx, -a->fy, a->fx, 0.0f };

    *out = A;

    return;
}