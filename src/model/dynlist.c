#include "dynlist.h"
#include <stdlib.h>
#include <memory.h>

static long _blokDynListGenerateNewSize(const long currentSize)
{
    return (long) (currentSize + (currentSize / 2));
}

static int _blokDynListResize(DynList *pList, const long newSize)
{
    if (!pList) { return 0; }
    if (!pList->pArr) { return 0; }
    if (newSize+1 < pList->max) { return 0; }

    Node *newMemory = realloc(pList->pArr, newSize*sizeof(Node));

    if (!newMemory) { return 0; }

    pList->pArr = newMemory;
    pList->max = newSize;

    return 1;
}

void blokDynListInit(DynList *pList, const long size)
{
    if (!pList) { return; }

    pList->pArr = calloc(size, sizeof(Node));

    if (!pList->pArr) { return; }

    pList->head = -1;
    pList->max = size;
    pList->size = 0;
}

int blokDynListIsFull(const DynList *pList)
{
    if (!pList) { return -1; }
    if (!pList->pArr) { return -1; }

    return (pList->size == pList->max);
}

int blokDynListIsEmpty(const DynList *pList)
{
    if (!pList) { return -1; }
    if (!pList->pArr) { return -1; }

    return (pList->head == -1);
}

long blokDynListAdd(DynList *pList, const Node *pNode)
{
    if (!pList) { return -1; }
    if (!pNode) { return -1; }

    if (blokDynListIsFull(pList)) 
    { 
        int newSize = _blokDynListGenerateNewSize(pList->max);
        int success = _blokDynListResize(pList, newSize);

        if (!success)
            return (-1L);
    }

    ++pList->head;
    ++pList->size;

    blokVectorIICopy(&(pList->pArr + pList->head)->data, pNode->data);

    return pList->head;
}

void blokDynListClear(DynList *pList)
{
    if (!pList) { return; }
    if (!pList->pArr) { return; }

    pList->head = -1;
    pList->size = 0;
}

int blokDynListGetIndex(const DynList *pList, const Node *pNode)
{
    if (!pList) { return -2; }
    if (!pList->pArr) { return -2; }
    if (!pNode) { return -2; }

    for (long arrIdx = 0; arrIdx < pList->size; arrIdx++)
    {
        if (blokVectorIIEquals(pList->pArr[arrIdx].data, pNode->data))
        {
            return arrIdx;
        }
    }

    return -1;
}  

int blokDynListExists(const DynList *pList, const Node *pNode)
{
    if (!pList) { return -1; }
    if (!pNode) { return -1; }

    int result = blokDynListGetIndex(pList, pNode);
    if (result == -2) { return -1; }
    if (result == -1) { return 0; }
    return 1;
}

void blokDynListCombine(DynList *pDest, const DynList *pSrc)
{
    if (!pDest) { return; }
    if (!pDest->pArr) { return; }
    if (!pSrc) { return; }
    if (!pSrc->pArr) { return; }

    for (long arrIdx = 0; arrIdx < pSrc->size; arrIdx++)
    {
        int exists = blokDynListExists(pDest, pSrc->pArr+arrIdx);
        if (exists == 1) { blokDynListAdd(pDest, pSrc->pArr+arrIdx); }
    }
}

int blokDynListRemove(DynList *pList, const Node node)
{
    if (!pList) { return -1; }

    long idx = blokDynListGetIndex(pList, &node);
    if (idx < 0) { return -1; }

    blokVectorIICopy( &(pList->pArr + idx)->data, (pList->pArr + pList->head)->data);
    --pList->head;
    --pList->size;

    return idx;
}

void blokDynListFree(DynList *pList)
{
    if (!pList) { return; }

    if (pList->pArr != NULL)
    {
        free(pList->pArr);
    }
}