
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "quaternion_exp.h"

/**
 * Applies quaternion rotation to a given vector.
 */
VOID_t
quaternion_rotate(const Quaternion_t* q1, const Vect3D_t* v1, Vect3D_t* v_output)
{
    assert((q1 != NULL) && (v1 != NULL) && (v_output != NULL));

    Real64_t    output_x;
    Real64_t    output_y;
    Real64_t    output_z;

    Real64_t ww = q1->dx * q1->dx;
    Real64_t xx = q1->fy * q1->fy;
    Real64_t yy = q1->fz * q1->fz;
    Real64_t zz = q1->dt * q1->dt;
    Real64_t wx = q1->dx * q1->fy;
    Real64_t wy = q1->dx * q1->fz;
    Real64_t wz = q1->dx * q1->dt;
    Real64_t xy = q1->fy * q1->fz;
    Real64_t xz = q1->fy * q1->dt;
    Real64_t yz = q1->fy * q1->dt;

    // Formula from http://www.euclideanspace.com/maths/algebra/realNormedAlgebra/quaternions/transforms/index.htm
    // p2.x = w*w*p1.x + 2*y*w*p1.z - 2*z*w*p1.y + x*x*p1.x + 2*y*x*p1.y + 2*z*x*p1.z - z*z*p1.x - y*y*p1.x;
    // p2.y = 2*x*y*p1.x + y*y*p1.y + 2*z*y*p1.z + 2*w*z*p1.x - z*z*p1.y + w*w*p1.y - 2*x*w*p1.z - x*x*p1.y;
    // p2.z = 2*x*z*p1.x + 2*y*z*p1.y + z*z*p1.z - 2*w*y*p1.x - y*y*p1.z + 2*w*x*p1.y - x*x*p1.z + w*w*p1.z;

    output_x    =   ww * v1->fx + 2 * wy * v1->fz - 2 * wz * v1->fy +
                    xx * v1->fx + 2 * xy * v1->fy + 2 * xz * v1->fz -
                    zz * v1->fx - yy * v1->fx;

    output_y    =   2 * xy * v1->fx + yy * v1->fy + 2 * yz * v1->fz +
                    2 * wz * v1->fx - zz * v1->fy + ww * v1->fy -
                    2 * wx * v1->fz - xx * v1->fy;

    output_z    =   2 * xz * v1->fx + 2 * yz * v1->fy + zz * v1->fz -
                    2 * wy * v1->fx - yy * v1->fz + 2 * wx * v1->fy -
                    xx * v1->fz + ww * v1->fz;

    vector3d_set(   output_x,
                    output_y,
                    output_z,
                    v_output);

    return;
}