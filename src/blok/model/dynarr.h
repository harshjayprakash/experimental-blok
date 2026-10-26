#ifndef BLOK_DYNLIST_H
#define BLOK_DYNLIST_H

#include "vector.h"

typedef struct _Node
{
    TVector2 data; /**< Point data. */
} TNode;

typedef struct _DynArr
{
    long head;
    long size;
    long max;
    TNode *arr;
} TDynArr;

int BlokDynArrInit(TDynArr *da, const long size);

int BlokDynArrIsFull(const TDynArr *da);

int BlokDynArrIsEmpty(const TDynArr *da);

long BlokDynArrAdd(TDynArr *da, const TNode *node);

int BlokDynArrClear(TDynArr *da);

long BlokDynArrGetIndex(const TDynArr *da, const TNode *node);

int BlokDynArrExists(const TDynArr *da, const TNode *node);

long BlokDynArrRemove(TDynArr *da, const TNode node);

int BlokDynArrFree(TDynArr *da);

#endif /* BLOK_DYNLIST_H */