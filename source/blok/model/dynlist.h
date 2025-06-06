#ifndef _BLOK_DYNLIST_H_
#define _BLOK_DYNLIST_H_

#include "vector.h"

typedef struct _Node {
    TVector2 data;
} TNode;

typedef struct _DynList {
    TNode *pArr;
    long head;
    long size;
    long max;
} TDynList;

int blokDynListInit(TDynList *pList, const long size);

int blokDynListIsFull(const TDynList *pList);

int blokDynListIsEmpty(const TDynList *pList);

long blokDynListAdd(TDynList *pList, const TNode *pNode);

int blokDynListClear(TDynList *pList);

long blokDynListGetIndex(const TDynList *pList, const TNode *pNode);

int blokDynListExists(const TDynList *pList, const TNode *pNode);

long blokDynListRemove(TDynList *pList, const TNode node);

int blokDynListFree(TDynList *pList);

#endif /* _BLOK_DYNLIST_H_ */