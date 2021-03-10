#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quaternion_exp.h"

/**
 * Function to multiply two quaternions.
 *
 * @param [in] in_quat1 first input quaternion instance
 * @param [in] in_quat2 second input quaternion instance
 * @returns resultant quaternion
 */
VOID_t
quaternion_multiply(const Quaternion_t *in_quat1, const Quaternion_t *in_quat2, Quaternion_t* out_quat)
{
    assert((in_quat1 != NULL) && (in_quat2 != NULL) && (out_quat != NULL));

    out_quat->dx =  in_quat1->dx  * in_quat2->dx  - 
                    in_quat1->fy * in_quat2->fy   -
                    in_quat1->fz * in_quat2->fz   -
                    in_quat1->dt * in_quat2->dt;

    out_quat->fy = in_quat1->dx * in_quat2->fy    + 
                    in_quat1->fy * in_quat2->dx   +
                    in_quat1->fz * in_quat2->dt   - 
                    in_quat1->dt * in_quat2->fz;

    out_quat->fz = in_quat1->dx * in_quat2->fz    - 
                    in_quat1->fy * in_quat2->dt   +
                    in_quat1->fz * in_quat2->dx   + 
                    in_quat1->dt * in_quat2->fy;

    out_quat->dt = in_quat1->dx * in_quat2->dt    +
                    in_quat1->fy * in_quat2->fz   -
                    in_quat1->fz * in_quat2->fy   +
                    in_quat1->dt * in_quat2->dx;

    printf("Origine Quaternion: %.g %+.g %+.g %+.g\n", out_quat->dx,
        out_quat->fy,
        out_quat->fz,
        out_quat->dt);
    /* A VOIR AVEC LA FORMULE DE https://fr.mathworks.com/help/aeroblks/quaternionmultiplication.html */
    /* TODO */

    out_quat->dx =  in_quat1->dx * in_quat2->dx -
                    in_quat1->fy * in_quat2->fy -
                    in_quat1->fz * in_quat2->fz -
                    in_quat1->dt * in_quat2->dt;

    out_quat->fy =  in_quat1->dx * in_quat2->fy +
                    in_quat1->fy * in_quat2->dx - /* changement là */
                    in_quat1->fz * in_quat2->dt + /* changement là */
                    in_quat1->dt * in_quat2->fz;

    out_quat->fz =  in_quat1->dx * in_quat2->fz + /* changement là */
                    in_quat1->fy * in_quat2->dt +
                    in_quat1->fz * in_quat2->dx - /* changement là */
                    in_quat1->dt * in_quat2->fy;

    out_quat->dt =  in_quat1->dx * in_quat2->dt - /* changement là */
                    in_quat1->fy * in_quat2->fz + /* changement là */
                    in_quat1->fz * in_quat2->fy +
                    in_quat1->dt * in_quat2->dx;

    printf("Matlab Quaternion: %.g %+.g %+.g %+.g\n", out_quat->dx,
        out_quat->fy,
        out_quat->fz,
        out_quat->dt);
    /* OK AVEC LES VECTEURS */

    quaternion_set(0, 0, 0, 0, out_quat);

    out_quat->dS = in_quat1->dS * in_quat2->dS - vector3d_scalar_prod(&in_quat1->rV, &in_quat2->rV);

    Vect3D_t vres;
    Vect3D_t vres2;
    Vect3D_t tmp;

    vector3d_cross_product(&in_quat1->rV, &in_quat2->rV, &vres);

    vector3d_multiply_scalar(&in_quat2->rV, in_quat1->dS, &tmp);

    vector3d_add(&vres, &tmp, &vres2);

    vector3d_multiply_scalar(&in_quat1->rV, in_quat2->dS, &tmp);

    vector3d_add(&vres2, &tmp, &out_quat->rV);

    printf("MT  Quaternion: %.g %+.g %+.g %+.g\n", out_quat->dx,
        out_quat->fy,
        out_quat->fz,
        out_quat->dt);

    return;
}