#ifndef _BLOK_VECTOR_H_
#define _BLOK_VECTOR_H_

typedef struct _VectorII {
    int x;
    int y;
} VectorII;

typedef struct _VectorIV {
    int x;
    int y;
    int z;
    int w;
} VectorIV;

void blokVectorIICopy(VectorII *dest, const VectorII src);

void blokVectorIVCopy(VectorIV *dest, const VectorIV src);

int blokVectorIIEquals(const VectorII veca, const VectorII vecb);

VectorII blokVectorIIAdd(const VectorII veca, const VectorII vecb);

VectorII blokVectorIISubtract(const VectorII veca, const VectorII vecb);

VectorII blokVectorIIMultiply(const VectorII veca, const VectorII vecb);

#endif // _BLOK_VECTOR_H_