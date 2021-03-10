/**
 * @file
 * @brief Functions related to 3D vector operations.
 * @author Krishna Vedala
 */

#include <stdio.h>
#ifdef __arm__  // if compiling for ARM-Cortex processors
#define LIBQUAT_ARM
#include <arm_math.h>
#else
#include <math.h>
#endif
#include <assert.h>

#include "vector_3d_exp.h"

/**
 * @brief Testing function
 * @returns `VOID_t`
 */
VOID_t
vector3d_test()
{
    Vect3D_t a = {1., 2., 3.};
    Vect3D_t b = {1., 1., 1.};
    Real64_t d;
    Vect3D_t c;
    // printf("%s", vecto3d_print_vector(&a, "a"));
    // printf("%s", vecto3d_print_vector(&b, "b"));

    d = vector3d_get_norm(&a);
    // printf("|a| = %.4g\n", d);
    assert(fabs(d - 3.742f) < 0.01);
    d = vector3d_get_norm(&b);
    // printf("|b| = %.4g\n", d);
    assert(fabs(d - 1.732f) < 0.01);

    d = vector3d_scalar_prod(&a, &b);
    // printf("Dot product: %f\n", d);
    assert(fabs(d - 6.f) < 0.01);

    vector3d_prod(&a, &b, &c);
    printf("Vector product ");
    printf("%s", vector3d_print_vector(&c, "c"));
    assert(fabs(c.fx - (-1.f)) < 0.01);
    assert(fabs(c.fy - (2.f)) < 0.01);
    assert(fabs(c.fz - (-1.f)) < 0.01);
}

