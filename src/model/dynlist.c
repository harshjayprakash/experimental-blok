#include "dynlist.h"
#include <stdlib.h>
#include <memory.h>

static long __blokDynListGenerateNewSize(const long currentSize)
{
    return (long) (currentSize + (currentSize / 2));
}

static int __blokDynListResize(DynList *list, const long newSize)
{
    if (!list) { return 0; }
    if (!list->arr) { return 0; }
    if (newSize+1 < list->max) { return 0; }

    Node *newMemory = realloc(list->arr, newSize*sizeof(Node));

    if (!newMemory) { return 0; }

    list->arr = newMemory;
    list->max = newSize;

    return 1;
}

void blokDynListInit(DynList *list, const long size)
{
    if (!list) { return; }

    list->arr = calloc(size, sizeof(Node));

    if (!list->arr) { return; }

    list->head = -1;
    list->max = size;
    list->size = 0;
}

int blokDynListIsFull(const DynList *list)
{
    if (!list) { return -1; }
    if (!list->arr) { return -1; }

    return (list->size == list->max);
}

int blokDynListIsEmpty(const DynList *list)
{
    if (!list) { return -1; }
    if (!list->arr) { return -1; }

    return (list->head == -1);
}

long blokDynListAdd(DynList *list, const Node *node)
{
    if (!list) { return -1; }
    if (!node) { return -1; }

    if (blokDynListIsFull(list)) 
    { 
        int success = __blokDynListResize(list, __blokDynListGenerateNewSize(list->max));
        if (!success) { return -1; }
    }

    ++list->head;
    ++list->size;

    blokVectorIICopy(&(list->arr + list->head)->data, node->data);

    return list->head;
}

void blokDynListClear(DynList *list)
{
    if (!list) { return; }
    if (!list->arr) { return; }

    list->head = -1;
    list->size = 0;
}

int blokDynListGetIndex(const DynList *list, const Node *node)
{
    if (!list) { return -2; }
    if (!list->arr) { return -2; }
    if (!node) { return -2; }

    for (long arrIdx = 0; arrIdx < list->size; arrIdx++)
    {
        if (blokVectorIIEquals(list->arr[arrIdx].data, node->data))
        {
            return arrIdx;
        }
    }

    return -1;
}  

int blokDynListExists(const DynList *list, const Node *node)
{
    if (!list) { return -1; }
    if (!node) { return -1; }

    int result = blokDynListGetIndex(list, node);
    if (result == -2) { return -1; }
    if (result == -1) { return 0; }
    return 1;
}

void blokDynListCombine(DynList *dest, const DynList *src)
{
    if (!dest) { return; }
    if (!dest->arr) { return; }
    if (!src) { return; }
    if (!src->arr) { return; }

    for (long arrIdx = 0; arrIdx < src->size; arrIdx++)
    {
        int exists = blokDynListExists(dest, src->arr+arrIdx);
        if (exists == 1) { blokDynListAdd(dest, src->arr+arrIdx); }
    }
}

int blokDynListRemove(DynList *list, const Node node)
{
    if (!list) { return -1; }

    long idx = blokDynListGetIndex(list, &node);
    if (idx < 0) { return -1; }

    blokVectorIICopy( &(list->arr + idx)->data, (list->arr + list->head)->data);
    --list->head;
    --list->size;

    return idx;
}

void blokDynListFree(DynList *list)
{
    if (!list) { return; }

    if (list->arr != NULL)
    {
        free(list->arr);
    }
}