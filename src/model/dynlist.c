/**
 * \file DYNLIST.C
 * \date 22-05-2025
 * \brief Implementation of list routines.
 */

#include "dynlist.h"
#include <stdlib.h>
#include <memory.h>

/**
 * \brief Generate new list size.
 * 
 * \details
 * The new returned size if 1.5 times larger.
 * 
 * \param[in] currentSize   The current size.
 * \return                  The new size.
 */
static long _blokDynListGenerateNewSize(
    const long currentSize)
{
    return (long) (currentSize + (currentSize / 2));
}

/**
 * \brief Resizes the list.
 * 
 * \details
 * Attempts to reallocate the memory based on the new provided size.
 * 
 * \param[in out] pList     The pointer to the list.
 * \param[in]     newSize   The new size.
 * \return                  0 for failure, 1 for success.
 */
static int _blokDynListResize(
    DynList *pList,
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

    Node *pNewMemory = realloc(pList->pArr, newSize * sizeof(Node));

    if (pNewMemory == NULL) {
        return 0;
    }

    pList->pArr = pNewMemory;
    pList->max = newSize;

    return 1;
}

int blokDynListInit(
    DynList *pList,
    const long size)
{
    if (pList == NULL) {
        return 0;
    }

    pList->pArr = calloc(size, sizeof(Node));

    if (pList->pArr == NULL) {
        return 0;
    }

    pList->head = -1;
    pList->max = size;
    pList->size = 0;

    return 1;
}

int blokDynListIsFull(
    const DynList *pList)
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
    const DynList *pList)
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
    DynList *pList,
    const Node *pNode)
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

    blokVectorIICopy(&(pList->pArr + pList->head)->data, pNode->data);

    return pList->head;
}

int blokDynListClear(
    DynList *pList)
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
    const DynList *pList,
    const Node *pNode)
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
        if (blokVectorIIEquals(pList->pArr[idx].data, pNode->data)) {
            return idx;
        }
    }

    return -1L;
}  

int blokDynListExists(
    const DynList *pList,
    const Node *pNode)
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
    DynList *pList,
    const Node node)
{
    if (pList == NULL) {
        return -1;
    }

    long idx = blokDynListGetIndex(pList, &node);

    if (idx < 0) {
        return -1;
    }

    blokVectorIICopy(&(pList->pArr + idx)->data, (pList->pArr + pList->head)->data);
    --pList->head;
    --pList->size;

    return idx;
}

int blokDynListFree(
    DynList *pList)
{
    if (pList == NULL) {
        return 0;
    }

    if (pList->pArr != NULL) {
        (void)free(pList->pArr);
    }

    return 1;
}