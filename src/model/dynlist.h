#ifndef _BLOK_DYNLIST_H_
#define _BLOK_DYNLIST_H_

#include "vector.h"

typedef struct _Node Node;

typedef struct _Node {
    VectorII data;
} Node;

typedef struct _DynList {
    Node *pArr;
    long head;
    long size;
    long max;
} DynList;

void blokDynListInit(DynList *pList, const long size);

int blokDynListIsFull(const DynList *pList);

int blokDynListIsEmpty(const DynList *pList);

long blokDynListAdd(DynList *pList, const Node *pNode);

void blokDynListClear(DynList *pList);

int blokDynListGetIndex(const DynList *pList, const Node *pNode);

int blokDynListExists(const DynList *pList, const Node *pNode);

void blokDynListCombine(DynList *pDest, const DynList *pSrc);

int blokDynListRemove(DynList *pList, const Node node);

void blokDynListFree(DynList *pList);

#endif // _BLOK_DYNLIST_H_