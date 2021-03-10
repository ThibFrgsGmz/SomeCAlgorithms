#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quaternion_exp.h"

 /**
 * Sets quaternion to its identity.
 */
VOID_t
quaternion_set_identity(Quaternion_t* q)
{
    assert(q != NULL);
    quaternion_set(1, 0, 0, 0, q);
    return;
}