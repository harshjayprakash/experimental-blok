/**
 * @file VECTOR.H
 * @date 24-05-2025
 * @brief Provides the VectorII object and operation routines.
 */

#ifndef _BLOK_VECTOR_H_
#define _BLOK_VECTOR_H_

/**
 * @brief 2D Vector.
 * 
 * @details
 * Represents a point, coordinate or size.
 */
typedef struct _VectorII {
    long x;   /**< The x coordinate or width. */
    long y;   /**< The y coordinate or height. */
} VectorII;

/**
 * @brief Duplicate the vector.
 * 
 * @details
 * Copies the vector to the given destination.
 * 
 * @param[in out] pDest   The vector to be copied to.
 * @param[in]     src     The vector to be copied.
 * @return                0 for failure, 1 for success.
 */
int blokVectorIICopy(VectorII *pDest, const VectorII src);

/**
 * @brief Is vector equal.
 * 
 * @details
 * Checks if the given vectors are the same.
 * 
 * @param[in] veca   The first vector.
 * @param[in] vecb   The second vector.
 * @return           1 for equal, 0 for not equal.
 */
int blokVectorIIEquals(const VectorII veca, const VectorII vecb);

/**
 * @brief Offsets the vector position.
 * 
 * @details
 * Adds the "offsetVec" vector to the "vec" vector.
 * 
 * @param[in] vec         The vector to be offset.
 * @param[in] offsetVec   The offset.
 * @return                The resulting vector.
 */
VectorII blokVectorIIOffset(const VectorII vec, const VectorII offsetVec);

/**
 * @brief Multiply vectors.
 * 
 * @details
 * Multiples the values of the two given vectors.
 * 
 * @param[in] veca   The first vector. 
 * @param[in] vecb   The second vector.
 * @return           The resulting vector.
 */
VectorII blokVectorIIMultiply(const VectorII veca, const VectorII vecb);

#endif // _BLOK_VECTOR_H_