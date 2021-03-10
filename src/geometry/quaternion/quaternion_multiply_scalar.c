#include <assert.h>
#include "quaternion_exp.h"

VOID_t
quaternion_multiply_scalar(const Quaternion_t* q, Real64_t fScalar, Quaternion_t* output)
{
    assert((q != NULL) && (output != NULL));

    Vect3D_t        rv = {0.0f};

    quaternion_set( fScalar * q->dx,
                    fScalar * q->fy,
                    fScalar * q->fz,
                    fScalar * q->dt,
                    output);
    return;
}
