#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quaternion_exp.h"

Bool_t
quaternion_is_non_zero(const Quaternion_t* q)
{
    assert(q != NULL);
 
    Bool_t  bIsNonZero;

    /* If at least one of the components is not null */
    if ( (q->dx <= EPSILON) || (q->fy <= EPSILON) || (q->fz <= EPSILON) || (q->dt <= EPSILON))
    {
        /* The quaternion is not null */
        bIsNonZero  =   TRUE;
    }
    /* Else all components are null */
    else
    {
        /* The quaternion is null */
        bIsNonZero  =   FALSE;
    }
    return (bIsNonZero);
}
