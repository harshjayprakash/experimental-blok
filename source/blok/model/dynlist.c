#include "dynlist.h"
#include <stdlib.h>
#include <memory.h>

static long _blokDynListGenerateNewSize(
    const long currentSize)
{
    return (long)(currentSize + (currentSize / 2));
}

static int _blokDynListResize(
    TDynList *pList,
    const long newSize)
{
    if (pList == NULL) {
        return 0;
    }

    if (pList->pArr == NULL) {
        return 0;
    }

    if (newSize + 1 < pList->max) {
        return 0;
    }

    TNode *pNewMemory = realloc(pList->pArr, newSize * sizeof(TNode));

    if (pNewMemory == NULL) {
        return 0;
    }

    pList->pArr = pNewMemory;
    pList->max = newSize;

    return 1;
}

int blokDynListInit(
    TDynList *pList,
    const long size)
{
    if (pList == NULL) {
        return 0;
    }

    pList->pArr = calloc(size, sizeof(TNode));

    if (pList->pArr == NULL) {
        return 0;
    }

    pList->head = -1;
    pList->max = size;
    pList->size = 0;

    return 1;
}

int blokDynListIsFull(
    const TDynList *pList)
{
    if (pList == NULL) {
        return -1;
    }

    if (pList->pArr == NULL) {
        return -1;
    }

    return (pList->size == pList->max);
}

int blokDynListIsEmpty(
    const TDynList *pList)
{
    if (pList == NULL) {
        return -1;
    }

    if (pList->pArr == NULL) {
        return -1;
    }

    return (pList->head == -1);
}

long blokDynListAdd(
    TDynList *pList,
    const TNode *pNode)
{
    if (pList == NULL) {
        return -1L;
    }

    if (pNode == NULL) {
        return -1L;
    }

    if (blokDynListIsFull(pList))  { 
        int newSize = _blokDynListGenerateNewSize(pList->max);
        int success = _blokDynListResize(pList, newSize);

        if (!success) {
            return -1L;
        }
    }

    ++pList->head;
    ++pList->size;

    blokVector2Copy(&(pList->pArr + pList->head)->data, pNode->data);

    return pList->head;
}

int blokDynListClear(
    TDynList *pList)
{
    if (pList == NULL) {
        return 0;
    }

    if (pList->pArr == NULL) {
        return 0;
    }

    pList->head = -1;
    pList->size = 0;

    return 1;
}

long blokDynListGetIndex(
    const TDynList *pList,
    const TNode *pNode)
{
    if (pList == NULL) {
        return -2L;
    }

    if (pList->pArr == NULL) {
        return -2L;
    }

    if (pNode == NULL) {
        return -2L;
    }

    for (long idx = 0; idx < pList->size; idx++) {
        if (blokVector2Equals(pList->pArr[idx].data, pNode->data)) {
            return idx;
        }
    }

    return -1L;
}  

int blokDynListExists(
    const TDynList *pList,
    const TNode *pNode)
{
    if (pList == NULL) {
        return -1;
    }

    if (pNode == NULL) {
        return -1;
    }

    int result = blokDynListGetIndex(pList, pNode);
    
    if (result == -2) {
        return -1;
    }

    if (result == -1) {
        return 0;
    }

    return 1;
}

long blokDynListRemove(
    TDynList *pList,
    const TNode node)
{
    if (pList == NULL) {
        return -1;
    }

    long idx = blokDynListGetIndex(pList, &node);

    if (idx < 0) {
        return -1;
    }

    blokVector2Copy(&(pList->pArr + idx)->data, (pList->pArr + pList->head)->data);
    --pList->head;
    --pList->size;

    return idx;
}

int blokDynListFree(
    TDynList *pList)
{
    if (pList == NULL) {
        return 0;
    }

    if (pList->pArr != NULL) {
        (void)free(pList->pArr);
    }

    return 1;
}