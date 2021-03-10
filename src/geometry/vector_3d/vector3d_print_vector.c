#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "vector_3d_exp.h"

/**
 * Print formatted vector on stdout.
 *
 * @param[in] a vector to print
 * @param[in] name  name of the vector
 * @returns string representation of vector
 */
const PChar_t*
vector3d_print_vector(const Vect3D_t *a, const PChar_t*name)
{
    static PChar_t vec_str[100];  // static to ensure the string life extends the
                               // life of function

    snprintf(vec_str, 99, "vec(%s) = (%.3g)i + (%.3g)j + (%.3g)k\n", name, a->fx,
             a->fy, a->fz);
    return (vec_str);
}
