#ifndef _BLOK_VECTOR_H_
#define _BLOK_VECTOR_H_

typedef struct _Vector2 {
    long x;
    long y;
} TVector2;

int blokVector2Copy(TVector2 *pDest, const TVector2 src);

int blokVector2Equals(const TVector2 veca, const TVector2 vecb);

TVector2 blokVector2Offset(const TVector2 vec, const TVector2 offsetVec);

TVector2 blokVector2Multiply(const TVector2 veca, const TVector2 vecb);

#endif /* _BLOK_VECTOR_H_ */