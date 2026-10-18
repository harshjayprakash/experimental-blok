#ifndef BLOK_DYNLIST_H
#define BLOK_DYNLIST_H

#include "vector.h"

typedef struct _Node
{
    TVector2 data; /**< Point data. */
} TNode;

typedef struct _DynList
{
    TNode *pArr;
    long head;
    long size;
    long max;
} TDynList;

int BlokDynListInit(TDynList *pList, const long size);

int BlokDynListIsFull(const TDynList *pList);

int BlokDynListIsEmpty(const TDynList *pList);

long BlokDynListAdd(TDynList *pList, const TNode *pNode);

int BlokDynListClear(TDynList *pList);

long BlokDynListGetIndex(const TDynList *pList, const TNode *pNode);

int BlokDynListExists(const TDynList *pList, const TNode *pNode);

long BlokDynListRemove(TDynList *pList, const TNode node);

int BlokDynListFree(TDynList *pList);

#endif /* BLOK_DYNLIST_H */