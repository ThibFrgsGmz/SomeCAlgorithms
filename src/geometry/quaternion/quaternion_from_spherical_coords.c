#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quaternion_exp.h"


VOID_t
quaternion_from_spherical_coords(Real64_t fTheta, Real64_t fPhi, Quaternion_t* output)
{
    assert(output != NULL);
    Real64_t ct;
    Real64_t cp;
    Real64_t st;
    Real64_t sp;

    Real64_t fw;
    Real64_t fq1;
    Real64_t fq2;
    Real64_t fq3;

    ct = cos(fTheta / 2.0f);
    cp = cos(fPhi / 2.0f);
    st = sin(fTheta / 2.0f);
    sp = sin(fPhi / 2.0f);

    fw = cp * ct;
    fq1 = -sp * st;
    fq2 = st * cp;
    fq3 = sp * ct;

    quaternion_set(fw, fq1, fq2, fq3, output);

    return;
}
