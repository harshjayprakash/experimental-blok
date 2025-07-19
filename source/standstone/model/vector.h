#ifndef ST_VECTOR_H
#define ST_VECTOR_H

typedef struct _Vector2
{
    long x;
    long y;
} TVector2;

int stVector2Copy(TVector2 *pDest, const TVector2 src);

int stVector2Equals(const TVector2 veca, const TVector2 vecb);

TVector2 stVector2Offset(const TVector2 vec, const TVector2 offsetVec);

TVector2 stVector2Multiply(const TVector2 veca, const TVector2 vecb);

#endif /* ST_VECTOR_H */