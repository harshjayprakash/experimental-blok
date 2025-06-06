#ifndef _BLOK_VECTOR_H_
#define _BLOK_VECTOR_H_

typedef struct _Vector2 {
    long x;
    long y;
} TVector2;

int blokVectorIICopy(TVector2 *pDest, const TVector2 src);

int blokVectorIIEquals(const TVector2 veca, const TVector2 vecb);

TVector2 blokVectorIIOffset(const TVector2 vec, const TVector2 offsetVec);

TVector2 blokVectorIIMultiply(const TVector2 veca, const TVector2 vecb);

#endif /* _BLOK_VECTOR_H_ */