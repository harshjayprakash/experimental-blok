#include "dynlist.h"
#include <memory.h>
#include <stdint.h>
#include <stdlib.h>

static long _BlokDynListGenerateNewSize(const long currentSize)
{
    return (long)(currentSize + (currentSize / 2));
}

static int _BlokDynListResize(TDynList *pList, const long newSize)
{
    if (pList == NULL)
    {
        return 0;
    }

    if (pList->pArr == NULL)
    {
        return 0;
    }

    if (newSize + 1 < pList->max)
    {
        return 0;
    }

    if (newSize > LONG_MAX)
    {
        return 0;
    }

    TNode *pNewMemory = realloc(pList->pArr, newSize * sizeof(TNode));

    if (pNewMemory == NULL)
    {
        return 0;
    }

    pList->pArr = pNewMemory;
    pList->max = newSize;

    return 1;
}

int BlokDynListInit(TDynList *pList, const long size)
{
    if (pList == NULL)
    {
        return 0;
    }

    if (size < 0 || size > LONG_MAX)
    {
        return 0;
    }

    pList->pArr = calloc(size, sizeof(TNode));

    if (pList->pArr == NULL)
    {
        return 0;
    }

    pList->head = -1;
    pList->max = size;
    pList->size = 0;

    return 1;
}

int BlokDynListIsFull(const TDynList *pList)
{
    if (pList == NULL)
    {
        return -1;
    }

    if (pList->pArr == NULL)
    {
        return -1;
    }

    return (pList->size == pList->max);
}

int BlokDynListIsEmpty(const TDynList *pList)
{
    if (pList == NULL)
    {
        return -1;
    }

    if (pList->pArr == NULL)
    {
        return -1;
    }

    return (pList->head == -1);
}

long BlokDynListAdd(TDynList *pList, const TNode *pNode)
{
    if (pList == NULL || pNode == NULL)
    {
        return -1L;
    }

    if (BlokDynListIsFull(pList))
    {
        if (!_BlokDynListResize(pList, _BlokDynListGenerateNewSize(pList->max)))
        {
            return -1L;
        }
    }

    ++pList->head;
    ++pList->size;

    int success = BlokVector2Copy(&(pList->pArr + pList->head)->data, pNode->data);

    if (!success)
    {
        return -1L;
    }

    return pList->head;
}

int BlokDynListClear(TDynList *pList)
{
    if (pList == NULL)
    {
        return 0;
    }

    if (pList->pArr == NULL)
    {
        return 0;
    }

    pList->head = -1;
    pList->size = 0;

    return 1;
}

long BlokDynListGetIndex(const TDynList *pList, const TNode *pNode)
{
    if (pList == NULL || pNode == NULL)
    {
        return -2L;
    }

    if (pList->pArr == NULL)
    {
        return -2L;
    }

    for (long idx = 0; idx < pList->size; idx++)
    {
        if (BlokVector2Equals(pList->pArr[idx].data, pNode->data))
        {
            return idx;
        }
    }

    return -1L;
}

int BlokDynListExists(const TDynList *pList, const TNode *pNode)
{
    if (pList == NULL || pNode == NULL)
    {
        return -1;
    }

    int result = BlokDynListGetIndex(pList, pNode);

    if (result == -2)
    {
        return -1;
    }

    if (result == -1)
    {
        return 0;
    }

    return 1;
}

long BlokDynListRemove(TDynList *pList, const TNode node)
{
    if (pList == NULL)
    {
        return -1L;
    }

    long idx = BlokDynListGetIndex(pList, &node);

    if (idx < 0)
    {
        return -1L;
    }

    int success =
        BlokVector2Copy(&(pList->pArr + idx)->data, (pList->pArr + pList->head)->data);

    if (!success)
    {
        return -1L;
    }

    --pList->head;
    --pList->size;

    return idx;
}

int BlokDynListFree(TDynList *pList)
{
    if (pList == NULL)
    {
        return 0;
    }

    if (pList->pArr != NULL)
    {
        free(pList->pArr);
        pList->pArr = NULL;
    }

    return 1;
}