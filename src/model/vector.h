#ifndef _BLOK_VECTOR_H_
#define _BLOK_VECTOR_H_

typedef struct _VectorII {
    int x;
    int y;
} VectorII;

int blokVectorIICopy(VectorII *pDest, const VectorII src);

int blokVectorIIEquals(const VectorII veca, const VectorII vecb);

VectorII blokVectorIIOffset(const VectorII veca, const VectorII vecb);

VectorII blokVectorIIAdd(const VectorII veca, const VectorII vecb);

VectorII blokVectorIISubtract(const VectorII veca, const VectorII vecb);

VectorII blokVectorIIMultiply(const VectorII veca, const VectorII vecb);

#endif // _BLOK_VECTOR_H_