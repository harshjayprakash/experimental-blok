/**
 * @file   vector.h
 * @brief  Vector Declarations.
 * @author harshjayprakash
 * @date   2025-07-22
 ****************************************************************************************/

#ifndef ST_VECTOR_H
#define ST_VECTOR_H

/**
 * @brief Two Dimensional Vector.
 */
typedef struct _Vector2
{
    /**
     * @brief X coordinate or Width.
     */
    long x;

    /**
     * @brief Y Coordinate or Height.
     */
    long y;
} TVector2;

/**
 * @brief Copy a vector.
 *
 * @details
 *  Copies the given vectors from source to destination.
 *
 * @param[in, out] pDest A valid pointer to the destination of the vector to be copied to.
 * @param[in]      src   The vector to be copied.
 * @return 1 for success, 0 for failure.
 */
int stVector2Copy(TVector2 *pDest, const TVector2 src);

/**
 * @brief Are vectors are equal.
 *
 * @details
 *  Compares the two given vectors, checking if they are equal.
 *
 * @param[in] veca The vector to be compared.
 * @param[in] vecb The vector to be compared to.
 * @return 1 for equal, 0 for not equal.
 */
int stVector2Equals(const TVector2 veca, const TVector2 vecb);

/**
 * @brief Offset the vector.
 *
 * @details
 *  The first parameter's vector is offset by the second.
 *
 * @param[in] vec       The vector to be offset.
 * @param[in] offsetVec The vector offset.
 * @return The resulting vector after performing the offset.
 *
 * @remark
 *  The vector is offset by adding the second to the first. For subtraction, please use a
 *  negative offset. If needed use the stVector2Multiply with TVector2 of {-1, -1}.
 */
TVector2 stVector2Offset(const TVector2 vec, const TVector2 offsetVec);

/**
 * @brief Multiply vectors.
 *
 * @details
 *  Multiplies the given vectors together.
 *
 * @param[in] veca The vector to be multiplied.
 * @param[in] vecb The vector to multiply by.
 * @return The resulting vector after the multiplication.
 */
TVector2 stVector2Multiply(const TVector2 veca, const TVector2 vecb);

#endif /* ST_VECTOR_H */