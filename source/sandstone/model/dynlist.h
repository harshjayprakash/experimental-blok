/**
 * @file dynlist.h
 * @brief Dynamic List Declarations.
 * @author harshjayprakash
 * @date 2025-07-20
 ****************************************************************************************/

#ifndef ST_DYNLIST_H
#define ST_DYNLIST_H

#include "vector.h"

/**
 * @brief List Node
 *
 * @remark
 *  This is a type to allow easier modification or addition to the list node.
 */
typedef struct _Node
{
    /**
     * @brief The point data.
     */
    TVector2 data;
} TNode;

/**
 * @brief The Dynamic List.
 *
 * @details
 *  Contains a heap allocated dynamically expanding list.
 *
 * @remark
 *  The data itself must not be modified directly. Please use the implemented helper
 *  functions (stDynList*).
 */
typedef struct _DynList
{
    /**
     * @brief Dynamic list memory.
     */
    TNode *pArr;

    /**
     * @brief Last added index.
     */
    long head;

    /**
     * @brief Current size.
     */
    long size;

    /**
     * @brief Maximum allocated size.
     */
    long max;
} TDynList;

/**
 * @brief Initialise the Dynamic List.
 *
 * @details
 *  Attempts to allocate the list of nodes based on the size provided. If and only if
 *  allocation succeeds, the rest of the data is set.
 *
 * @param[out] pList A valid pointer to TDynList.
 * @param[in]  size  The size of the list.
 * @return One for success, zero for failure.
 *
 * @remark
 *  The caller is responsible for keeping the memory. The memory allocated must be cleaned
 *  up with the corresponding stDynListFree function.
 */
int stDynListInit(TDynList *pList, const long size);

/**
 * @brief Is Dynamic List Full.
 *
 * @details
 *  Checks if the list is at full capacity.
 *
 * @param[in] pList A valid pointer to the TDynList to be checked.
 * @return 0 for not full, 1 for full, -1 for failure.
 *
 * @remark
 *  The failure refers to a null pointer error.
 */
int stDynListIsFull(const TDynList *pList);

/**
 * @brief Is Dynamic List Empty.
 *
 * @details
 *  Checks if the list is empty.
 *
 * @param[in] pList A valid pointer to the TDynList to be checked.
 * @return 0 for not empty, 1 for empty, -1 for failure.
 *
 * @remark
 *  The failure refers to a null pointer error.
 */
int stDynListIsEmpty(const TDynList *pList);

/**
 * @brief Add Node to Dynamic List.
 *
 * @details
 *  Attempts to add the given node to the list. If the list is full, it will be resized
 *  automatically.
 *
 * @param[in, out] pList A valid pointer to TDynList for the node to be added into.
 * @param[in]      pNode A valid pointer to TNode to be added.
 * @return -1 for failure, or the index of the new node for success.
 *
 * @remark
 *  Resizing could fail, meaning that the node will not be added.
 */
long stDynListAdd(TDynList *pList, const TNode *pNode);

/**
 * @brief Clear the Dynamic List.
 *
 * @details
 *  Re-assigns the head and size of the list.
 *
 * @param[in, out] pList A valid pointer to TDynList to be cleared.
 * @return One for success, zero for failure.
 *
 * @remark
 *  Clearing does not affect the node data, but re-assigns the head and size. This means
 *  that the existing data will be overwritten.
 */
int stDynListClear(TDynList *pList);

/**
 * @brief Get Index of Node from Dynamic List.
 *
 * @details
 *  Retrieves the index of the given node.
 *
 * @param[in] pList A valid pointer to TDynList containing the node.
 * @param[in] pNode A valid pointer to TNode's index to be found.
 * @return -2 for null pointer error, -1 for not found, or the index of the node.
 */
long stDynListGetIndex(const TDynList *pList, const TNode *pNode);

/**
 * @brief Does Node Exist in Dynamic List.
 *
 * @details
 *  A wrapper for the stDynListGetIndex, checking if the node exists.
 *
 * @param[in] pList A valid pointer to TDynList to check.
 * @param[in] pNode A valid pointer to TNode to find.
 * @return -1 for failure, 0 for not found, 1 for node exists.
 */
int stDynListExists(const TDynList *pList, const TNode *pNode);

/**
 * @brief Remove Node in Dynamic List.
 *
 * @details
 *  Removes a node by replacing it with the node at the head.
 *
 * @param[in, out] pList A valid pointer to TDynList.
 * @param[in]      node The node to be removed.
 * @return -1 for failure, or the index of the node removed.
 */
long stDynListRemove(TDynList *pList, const TNode node);

/**
 * @brief Free the Dynamic List.
 *
 * @details
 *  Frees the array block of memory.
 *
 * @param[in, out] pList A valid pointer to the TDynList to be freed.
 * @return 0 for failure, 1 for success.
 */
int stDynListFree(TDynList *pList);

#endif /* ST_DYNLIST_H */