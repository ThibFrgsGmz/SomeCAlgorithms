#include <assert.h>
#include "quaternion_exp.h"

VOID_t
quaternion_sub(const Quaternion_t* quat1, const Quaternion_t* quat2, Quaternion_t* output)
{
    assert((quat1 != NULL) && (quat2 != NULL) && (output != NULL));

    output->dS = (quat1->dS - quat2->dS);

    vector3d_sub(&quat1->rV, &quat2->rV, &output->rV);

    return;
}
