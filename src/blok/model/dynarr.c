#include "dynarr.h"
#include <memory.h>
#include <stdint.h>
#include <stdlib.h>

static long _BlokDynArrGenerateNewSize(const long currentSize)
{
    return (long)(currentSize + (currentSize / 2));
}

static int _BlokDynArrResize(TDynArr *da, const long newSize)
{
    if (da == NULL)
    {
        return 0;
    }

    if (da->arr == NULL)
    {
        return 0;
    }

    if (newSize + 1 < da->max)
    {
        return 0;
    }

    if (newSize > LONG_MAX)
    {
        return 0;
    }

    TNode *pNewMemory = realloc(da->arr, newSize * sizeof(TNode));

    if (pNewMemory == NULL)
    {
        return 0;
    }

    da->arr = pNewMemory;
    da->max = newSize;

    return 1;
}

int BlokDynArrInit(TDynArr *da, const long size)
{
    if (da == NULL)
    {
        return 0;
    }

    if (size < 0 || size > LONG_MAX)
    {
        return 0;
    }

    da->arr = calloc(size, sizeof(TNode));

    if (da->arr == NULL)
    {
        return 0;
    }

    da->head = -1;
    da->max = size;
    da->size = 0;

    return 1;
}

int BlokDynArrIsFull(const TDynArr *da)
{
    if (da == NULL)
    {
        return -1;
    }

    if (da->arr == NULL)
    {
        return -1;
    }

    return (da->size == da->max);
}

int BlokDynArrIsEmpty(const TDynArr *da)
{
    if (da == NULL)
    {
        return -1;
    }

    if (da->arr == NULL)
    {
        return -1;
    }

    return (da->head == -1);
}

long BlokDynArrAdd(TDynArr *da, const TNode *pNode)
{
    if (da == NULL || pNode == NULL)
    {
        return -1L;
    }

    if (BlokDynArrIsFull(da))
    {
        if (!_BlokDynArrResize(da, _BlokDynArrGenerateNewSize(da->max)))
        {
            return -1L;
        }
    }

    ++da->head;
    ++da->size;

    int success = BlokVector2Copy(&(da->arr + da->head)->data, pNode->data);

    if (!success)
    {
        return -1L;
    }

    return da->head;
}

int BlokDynArrClear(TDynArr *da)
{
    if (da == NULL)
    {
        return 0;
    }

    if (da->arr == NULL)
    {
        return 0;
    }

    da->head = -1;
    da->size = 0;

    return 1;
}

long BlokDynArrGetIndex(const TDynArr *da, const TNode *pNode)
{
    if (da == NULL || pNode == NULL)
    {
        return -2L;
    }

    if (da->arr == NULL)
    {
        return -2L;
    }

    for (long idx = 0; idx < da->size; idx++)
    {
        if (BlokVector2Equals(da->arr[idx].data, pNode->data))
        {
            return idx;
        }
    }

    return -1L;
}

int BlokDynArrExists(const TDynArr *da, const TNode *pNode)
{
    if (da == NULL || pNode == NULL)
    {
        return -1;
    }

    int result = BlokDynArrGetIndex(da, pNode);

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

long BlokDynArrRemove(TDynArr *da, const TNode node)
{
    if (da == NULL)
    {
        return -1L;
    }

    long idx = BlokDynArrGetIndex(da, &node);

    if (idx < 0)
    {
        return -1L;
    }

    int success =
        BlokVector2Copy(&(da->arr + idx)->data, (da->arr + da->head)->data);

    if (!success)
    {
        return -1L;
    }

    --da->head;
    --da->size;

    return idx;
}

int BlokDynArrFree(TDynArr *da)
{
    if (da == NULL)
    {
        return 0;
    }

    if (da->arr != NULL)
    {
        free(da->arr);
        da->arr = NULL;
    }

    return 1;
}