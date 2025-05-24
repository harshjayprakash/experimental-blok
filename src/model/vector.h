#ifndef _BLOK_VECTOR_H_
#define _BLOK_VECTOR_H_

typedef struct _VectorII {
    long x;
    long y;
} VectorII;

int blokVectorIICopy(VectorII *pDest, const VectorII src);

int blokVectorIIEquals(const VectorII veca, const VectorII vecb);

VectorII blokVectorIIOffset(const VectorII vec, const VectorII offsetVec);

VectorII blokVectorIIMultiply(const VectorII veca, const VectorII vecb);

#endif // _BLOK_VECTOR_H_