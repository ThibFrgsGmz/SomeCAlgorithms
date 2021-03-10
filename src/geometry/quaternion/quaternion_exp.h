 /**
  * @file
  * @brief Functions related to 3D quaternions and Euler angles.
  * Quaternions extend the concept of three-dimensional rotation to four-dimensional rotation.
  * This avoids the problem of "gimbal-lock" and allows a smooth and continuous rotation.
  *
  * Indeed, they can be considered as adding an additional rotation angle to the spherical coordinates,
  * i.e. longitude, latitude and rotation angles.
  * A Quaternion is defined using four floating point values |x y z w|.
  * They are calculated from the combination of the three coordinates of the rotation axis
  * and the rotation angle.
  */

#ifndef __QUATERNIONS_H_
#   define __QUATERNIONS_H_
 
#   include "sw-prelude.h"
#   include "vector_3d_exp.h"

/** Minimum recognizable value. Any value less than this is considered to be equal to 0 */
#   define EPSILON 1e-9

/**
 * Maximum floating point difference that is considered as equal.
 */
#   define QUATERNION_EPS   (1e-4)
#   define _QUATERNION_EPS  (1e-14)

/** quats 3D Quaternion operations */
/** an Hamilton Quaternion type represented using a scalar w or q_0 and a 3D vector
 *   q = w + xi + yj + zk where i2 = j2 = k2 = ijk= −1
 */
typedef struct _Quaternion_t
{
#if 0
    Real64_t dx;  /* Scalar part of the quaternion, which is the analogue of the real part of a complex number.
                   * It also represents the magnitude of a rotation */

                   /* Vector part of the quaternion, which is the analog of the imaginary part of a complex number. */
    Real64_t fy; /* imaginary i part of quaternion */
    Real64_t fz; /* imaginary j part of quaternion */
    Real64_t dt; /* imaginary k part of quaternion */
#endif
    union
    {
        Real64_t dx;  /* Scalar part of the quaternion, which is the analogue of the real part of a complex number.
                       * It also represents the magnitude of a rotation */
        Real64_t dS;
    };
    union
    { 
        struct
        {
            /* Vector part of the quaternion, which is the analog of the imaginary part of a complex number. */
            Real64_t fy; /* imaginary i part of quaternion */
            Real64_t fz; /* imaginary j part of quaternion */
            Real64_t dt; /* imaginary k part of quaternion */
        };

        Vect3D_t rV;
    };

} Quaternion_t;

/** 3D Euler or Tait-Bryan angles (in radian) */
typedef struct _EulerAngles_t
{
    Real64_t fRoll;                    /**< or roll phi = rotation about X axis */
    Real64_t fPitch;                   /**< or pitch theta = rotation about Y axis */
    Real64_t fYaw;                     /**< or yaw psi = rotation about Z axis */
} EulerAngles_t;

extern
VOID_t          quaternion_create(const Vect3D_t* v1, Real64_t angle, Quaternion_t* output);
extern
VOID_t          quaternion_set(Real64_t w, Real64_t v1, Real64_t v2, Real64_t v3, Quaternion_t* output);
extern
VOID_t          quaternion_set_identity(Quaternion_t* q);
extern
VOID_t          quaternion_normalize(const Quaternion_t* q, Quaternion_t* output);
extern
VOID_t          quaternion_multiply(const Quaternion_t* in_quat1, const Quaternion_t* in_quat2, Quaternion_t* output);
extern
VOID_t          quaternion_multiply_scalar(const Quaternion_t* q, Real64_t fScalar, Quaternion_t* output);
extern
Real64_t        quaternion_magnitude(const Quaternion_t* quat);
extern
VOID_t          quaternion_inverse(const Quaternion_t* q, Quaternion_t* output);
extern
Flag_t          quaternion_equal(const Quaternion_t* q1, const Quaternion_t* q2);
extern
VOID_t          quaternion_copy(const Quaternion_t* q, Quaternion_t* output);
extern
VOID_t          quaternion_conjugate(const Quaternion_t* q, Quaternion_t* output);
extern
VOID_t          quaternion_to_euler(const Quaternion_t* in_quat, EulerAngles_t* out_euler);
extern
VOID_t          quaternion_from_euler(const EulerAngles_t* in_euler, Quaternion_t* out_quat);
extern
VOID_t          quaternion_exp(const Quaternion_t* q, Quaternion_t* output);
extern
VOID_t          quaternion_from_spherical_coords(Real64_t fTheta, Real64_t fPhi, Quaternion_t* output);
extern
VOID_t          quaternion_divide(const Quaternion_t* quat1, const Quaternion_t* quat2, Quaternion_t* output);
extern
Bool_t          quaternion_is_non_zero(const Quaternion_t* q);
extern
VOID_t          quaternion_test();
extern
VOID_t          quaternion_slerp(const Quaternion_t* q1, const Quaternion_t* q2, Real64_t t, Quaternion_t* output);
extern
VOID_t          quaternion_rotate(const Quaternion_t* q1, const Vect3D_t* v1, Vect3D_t* v_output);
extern
Bool_t          quaternion_is_versor(const Quaternion_t* q);
#endif  // __QUATERNIONS_H_
