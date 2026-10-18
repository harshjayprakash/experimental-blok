#ifndef BLOK_VECTOR_H
#define BLOK_VECTOR_H

typedef struct _Vector2
{
    long x;
    long y;
} TVector2;

int BlokVector2Copy(TVector2 *pDest, const TVector2 src);

int BlokVector2Equals(const TVector2 veca, const TVector2 vecb);

TVector2 BlokVector2Offset(const TVector2 vec, const TVector2 offsetVec);

TVector2 BlokVector2Multiply(const TVector2 veca, const TVector2 vecb);

#endif /* BLOK_VECTOR_H */