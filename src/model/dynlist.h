#ifndef _BLOK_DYNLIST_H_
#define _BLOK_DYNLIST_H_

#include "vector.h"

typedef struct _Node Node;

typedef struct _Node {
    VectorII data;
} Node;

typedef struct _DynList {
    Node *arr;
    long head;
    long size;
    long max;
} DynList;

void blokDynListInit(DynList *list, const long size);

int blokDynListIsFull(const DynList *list);

int blokDynListIsEmpty(const DynList *list);

long blokDynListAdd(DynList *list, const Node *node);

void blokDynListClear(DynList *list);

int blokDynListGetIndex(const DynList *list, const Node *node);

int blokDynListExists(const DynList *list, const Node *node);

void blokDynListCombine(DynList *dest, const DynList *src);

int blokDynListRemove(DynList *list, const Node node);

void blokDynListFree(DynList *list);

#endif // _BLOK_DYNLIST_H_