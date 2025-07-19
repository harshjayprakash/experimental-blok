#ifndef ST_DYNLIST_H
#define ST_DYNLIST_H

#include "vector.h"

typedef struct _Node
{
    TVector2 data;
} TNode;

typedef struct _DynList
{
    TNode *pArr;
    long head;
    long size;
    long max;
} TDynList;

int stDynListInit(TDynList *pList, const long size);

int stDynListIsFull(const TDynList *pList);

int stDynListIsEmpty(const TDynList *pList);

long stDynListAdd(TDynList *pList, const TNode *pNode);

int stDynListClear(TDynList *pList);

long stDynListGetIndex(const TDynList *pList, const TNode *pNode);

int stDynListExists(const TDynList *pList, const TNode *pNode);

long stDynListRemove(TDynList *pList, const TNode node);

int stDynListFree(TDynList *pList);

#endif /* ST_DYNLIST_H */