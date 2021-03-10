
#include "geometry_utils_exp.h"


/**
 * Converts degree into radiant. Degree must be in the range of 0..359.
 */
Real64_t mtDegToRad(Real64_t deg)
{
    return deg * MT_PI / 180.0;
}

/**
 * Converts radiant to degree.
 */
Real64_t mtRadToDeg(Real64_t rad)
{
    return rad * 180.0 / MT_PI;
}