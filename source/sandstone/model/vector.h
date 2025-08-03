/**
 * @file   vector.h
 * @brief  Vector Declarations.
 * @author harshjayprakash
 * @date   2025-08-03
 ****************************************************************************************/

#ifndef ST_VECTOR_H
#define ST_VECTOR_H

/**
 * @brief Two Dimensional Vector.
 */
typedef struct _Vector2
{
    long x; /**< X coordinate or width. */
    long y; /**< Y coordinate or height. */
} TVector2;

/**
 * @brief Copy a vector.
 *
 * @details
 * Copies the given vectors from source to destination.
 *
 * @param[in, out] pDest   Pointer to the destination of the vector to be copied to.
 * @param[in]      src     Vector to be copied.
 * @return `1` for success, `0` for failure.
 */
int stVector2Copy(TVector2 *pDest, const TVector2 src);

/**
 * @brief Are vectors are equal.
 *
 * @details
 * Compares the two given vectors, checking if they are equal.
 *
 * @param[in] veca   Vector to be compared.
 * @param[in] vecb   Vector to be compared to.
 * @return `1` for equal, `0` for not equal.
 */
int stVector2Equals(const TVector2 veca, const TVector2 vecb);

/**
 * @brief Offset the vector.
 *
 * @details
 * The first parameter's vector is offset by the second.
 *
 * @param[in] vec         Vector to be offset.
 * @param[in] offsetVec   Vector offset.
 * @return The resulting vector after performing the offset.
 *
 * @remark
 * - The vector is offset by adding the second to the first. For subtraction, please use
 *   a negative offset. If needed use the stVector2Multiply with TVector2 of {-1, -1}.
 */
TVector2 stVector2Offset(const TVector2 vec, const TVector2 offsetVec);

/**
 * @brief Multiply vectors.
 *
 * @details
 * Multiplies the given vectors together.
 *
 * @param[in] veca   Vector to be multiplied.
 * @param[in] vecb   Vector to multiply by.
 * @return The resulting vector after the multiplication.
 */
TVector2 stVector2Multiply(const TVector2 veca, const TVector2 vecb);

#endif /* ST_VECTOR_H */