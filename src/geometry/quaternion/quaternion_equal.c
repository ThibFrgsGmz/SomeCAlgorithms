#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quaternion_exp.h"

/**
 * Tests if all quaternion values are equal (using QUATERNION_EPS).
 */
Flag_t
quaternion_equal(const Quaternion_t* q1, const Quaternion_t* q2)
{
    Flag_t  bRetValue   =   FALSE;
    Flag_t  bequalW     =   (fabs(q1->dx - q2->dx) <= QUATERNION_EPS);
    Flag_t  bequalV0    =   (fabs(q1->fy - q2->fy) <= QUATERNION_EPS);
    Flag_t  bequalV1    =   (fabs(q1->fz - q2->fz) <= QUATERNION_EPS);
    Flag_t  bequalV2    =   (fabs(q1->dt - q2->dt) <= QUATERNION_EPS);

    /* bRetValue = ((equalW && equalV0) && equalV1) && equalV2)); */
    bRetValue = (bequalW && bequalV0);
    bRetValue = (bRetValue && bequalV1);
    bRetValue = (bRetValue && bequalV2);

    return (bRetValue);
}