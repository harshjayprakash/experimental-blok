/**
 * @file dynlist.c
 * @brief Dynamic List Implementation.
 * @author harshjayprakash
 * @date 2025-07-20
 ****************************************************************************************/

#include "dynlist.h"
#include <stdlib.h>
#include <memory.h>
#include <stdint.h>

/**
 * @brief Generate a new list size.
 * 
 * @details
 *  Generates a new list size that is 1.5 larger.
 * 
 * @param[in] currentSize The current list size.
 * @return The new size.
 */
static long _stDynListGenerateNewSize(
    const long currentSize)
{
    return (long)(currentSize + (currentSize / 2));
}

/**
 * @brief Resize the dynamic list.
 * 
 * @details
 *  Attempts to re-allocate the array memory block.
 * 
 * @param[in, out] pList   A valid pointer to the TDynList structure to be resized.
 * @param[in]      newSize The new array size.
 * @return 0 for failure, 1 for success.
 */
static int _stDynListResize(
    TDynList *pList,
    const long newSize)
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

int stDynListInit(
    TDynList *pList,
    const long size)
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

int stDynListIsFull(
    const TDynList *pList)
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

int stDynListIsEmpty(
    const TDynList *pList)
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

long stDynListAdd(
    TDynList *pList,
    const TNode *pNode)
{
    if (pList == NULL)
    {
        return -1L;
    }

    if (pNode == NULL)
    {
        return -1L;
    }

    if (stDynListIsFull(pList)) 
    { 
        int newSize = _stDynListGenerateNewSize(pList->max);
        int success = _stDynListResize(pList, newSize);

        if (!success)
        {
            return -1L;
        }
    }

    ++pList->head;
    ++pList->size;

    int success = stVector2Copy(&(pList->pArr + pList->head)->data, pNode->data);
    
    if (!success)
    {
        return -1L;
    }

    return pList->head;
}

int stDynListClear(
    TDynList *pList)
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

long stDynListGetIndex(
    const TDynList *pList,
    const TNode *pNode)
{
    if (pList == NULL)
    {
        return -2L;
    }

    if (pList->pArr == NULL)
    {
        return -2L;
    }

    if (pNode == NULL)
    {
        return -2L;
    }

    for (long idx = 0; idx < pList->size; idx++)
    {
        if (stVector2Equals(pList->pArr[idx].data, pNode->data))
        {
            return idx;
        }
    }

    return -1L;
}  

int stDynListExists(
    const TDynList *pList,
    const TNode *pNode)
{
    if (pList == NULL)
    {
        return -1;
    }

    if (pNode == NULL)
    {
        return -1;
    }

    int result = stDynListGetIndex(pList, pNode);
    
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

long stDynListRemove(
    TDynList *pList,
    const TNode node)
{
    if (pList == NULL)
    {
        return -1L;
    }

    long idx = stDynListGetIndex(pList, &node);

    if (idx < 0)
    {
        return -1L;
    }

    int success = stVector2Copy(
        &(pList->pArr + idx)->data, 
        (pList->pArr + pList->head)->data);

    if (!success)
    {
        return -1L;
    }

    --pList->head;
    --pList->size;

    return idx;
}

int stDynListFree(
    TDynList *pList)
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