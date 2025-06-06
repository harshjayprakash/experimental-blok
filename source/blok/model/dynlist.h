#ifndef _BLOK_DYNLIST_H_
#define _BLOK_DYNLIST_H_

#include "vector.h"

typedef struct _Node {
    VectorII data;
} Node;

typedef struct _DynList {
    Node *pArr;
    long head;
    long size;
    long max;
} DynList;

int blokDynListInit(DynList *pList, const long size);

int blokDynListIsFull(const DynList *pList);

int blokDynListIsEmpty(const DynList *pList);

long blokDynListAdd(DynList *pList, const Node *pNode);

int blokDynListClear(DynList *pList);

long blokDynListGetIndex(const DynList *pList, const Node *pNode);

int blokDynListExists(const DynList *pList, const Node *pNode);

long blokDynListRemove(DynList *pList, const Node node);

int blokDynListFree(DynList *pList);

#endif /* _BLOK_DYNLIST_H_ */