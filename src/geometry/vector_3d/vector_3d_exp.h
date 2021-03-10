/**
 * @addtogroup quaternions Library for 3D Vectors & Quaternions
 * @{
 * @file
 * @brief Generic header that provides data types for 3D vectors and quaternions
 */

#ifndef __3D_VECTORS_H__
#   define __3D_VECTORS_H__

#   include "sw-prelude.h"

/** Minimum recognizable value. Any value less than this is considered to be equal to 0 */
#   define EPSILON 1e-9

/**
 * @addtogroup vec_3d 3D Vector operations
 * @{
 */
/** 3D vector type */
typedef struct _Vect3D_t
{
    Real64_t fx; /**< X co-ordinate */
    Real64_t fy; /**< Y co-ordinate */
    Real64_t fz; /**< Z co-ordinate */
} Vect3D_t;
/** @} */

/**
 * @addtogroup matrix Matrix operations
 * @{
 */
/** A 3x3 Matrix type definition */
typedef struct _Matrix3x3_t
{
    union
    { /**< 3 element row 1 */
        Real64_t tfRow1[3];
        Vect3D_t rVect1;
    };
    union
    { /**< 3 element row 2 */
        Real64_t tfRow2[3];
        Vect3D_t rVect2;
    };
    union
    { /**< 3 element row 3 */
        Real64_t tfRow3[3];
        Vect3D_t rVect3;
    };
} Matrix3x3_t;
/** @} */

extern
VOID_t          vector3d_cross_product(const Vect3D_t* a, const Vect3D_t* b, Vect3D_t* out);
extern  
VOID_t          vecto3d_divide_scalar(const Vect3D_t* a, Real64_t scalar, Vect3D_t* out);
extern
VOID_t          vector3d_get_cross_matrix(const Vect3D_t* a, Matrix3x3_t* out);
extern
VOID_t          vector3d_get_unit(const Vect3D_t* a, Vect3D_t* out);
extern
VOID_t          vector3d_multiply_scalar(const Vect3D_t* a, Real64_t scalar, Vect3D_t* out);
extern
VOID_t          vector3d_normalize(Vect3D_t* a);
extern
const PChar_t* vector3d_print_vector(const Vect3D_t* a, const PChar_t* name);
extern
VOID_t          vector3d_test();
extern
VOID_t          vector3d_add(const Vect3D_t* a, const Vect3D_t* b, Vect3D_t* out);
extern
Real64_t        vector3d_get_angle(Vect3D_t* a, Vect3D_t* b);
extern
Real64_t        vector3d_get_norm(const Vect3D_t* a);
extern
VOID_t          vector3d_prod(const Vect3D_t* a, const Vect3D_t* b, Vect3D_t* output);
extern
Real64_t        vector3d_scalar_prod(const Vect3D_t* vect_a, const Vect3D_t* vect_b);
extern
VOID_t          vector3d_set(Real64_t x, Real64_t y, Real64_t z, Vect3D_t* output);
extern
VOID_t          vector3d_sub(const Vect3D_t* a, const Vect3D_t* b, Vect3D_t* out);


#endif  // __3D_VECTORS_H__

/** @} */
