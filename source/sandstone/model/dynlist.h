/**
 * @file   dynlist.h
 * @brief  Dynamic List Declarations.
 * @author harshjayprakash
 * @date   2025-08-03
 ****************************************************************************************/

#ifndef ST_DYNLIST_H
#define ST_DYNLIST_H

#include "vector.h"

/**
 * @brief List Node
 *
 * @remark
 * - This is a type to allow easier modification or addition to the list node.
 */
typedef struct _Node
{
    TVector2 data; /**< Point data. */
} TNode;

/**
 * @brief The Dynamic List.
 *
 * @details
 * Contains a heap allocated dynamically expanding list.
 *
 * @remark
 * - The data itself must not be modified directly. Please use the implemented helper
 *   functions (stDynList*).
 */
typedef struct _DynList
{
    TNode *pArr; /**< Dynamic list memory. */
    long head;   /**< Last added index. */
    long size;   /**< Current size. */
    long max;    /**< Maximum allocated size. */
} TDynList;

/**
 * @brief Initialise the Dynamic List.
 *
 * @details
 * Attempts to allocate the list of nodes based on the size provided. If and only if
 * allocation succeeds, the rest of the data is set.
 *
 * @param[out] pList   Pointer to the dynamic list.
 * @param[in]  size    Size of the list.
 * @return `1` for success, `0` for failure.
 *
 * @remark
 * - The caller is responsible for keeping the memory. The memory allocated must be
 *   cleaned up with the corresponding stDynListFree function.
 */
int stDynListInit(TDynList *pList, const long size);

/**
 * @brief Is Dynamic List Full.
 *
 * @details
 * Checks if the list is at full capacity.
 *
 * @param[in] pList   Pointer to the dynamic list.
 * @return `0` for not full, `1` for full, `-1` for failure.
 *
 * @remark
 * - The failure refers to a null pointer error.
 */
int stDynListIsFull(const TDynList *pList);

/**
 * @brief Is Dynamic List Empty.
 *
 * @details
 * Checks if the list is empty.
 *
 * @param[in] pList   Pointer to the dynamic list.
 * @return `0` for not empty, `1` for empty, `-1` for failure.
 *
 * @remark
 * - The failure refers to a null pointer error.
 */
int stDynListIsEmpty(const TDynList *pList);

/**
 * @brief Add Node to Dynamic List.
 *
 * @details
 * Attempts to add the given node to the list. If the list is full, it will be resized
 * automatically.
 *
 * @param[in, out] pList   Pointer to the dynamic list.
 * @param[in]      pNode   Pointer to the node to be added.
 * @return `-1` for failure, or the index of the new node for success.
 *
 * @remark
 * - Resizing could fail, meaning that the node will not be added.
 */
long stDynListAdd(TDynList *pList, const TNode *pNode);

/**
 * @brief Clear the Dynamic List.
 *
 * @details
 * Re-assigns the head and size of the list.
 *
 * @param[in, out] pList   Pointer to the dynamic list to be cleared.
 * @return `1` for success, `0` for failure.
 *
 * @remark
 * - Clearing does not affect the node data, but re-assigns the head and size. This means
 *   that the existing data will be overwritten.
 */
int stDynListClear(TDynList *pList);

/**
 * @brief Get Index of Node from Dynamic List.
 *
 * @details
 * Retrieves the index of the given node.
 *
 * @param[in] pList   Pointer to the dynamic list containing the node.
 * @param[in] pNode   Pointer to the node's index to be found.
 * @return `-2` for null pointer error, `-1` for not found, or the index of the node.
 */
long stDynListGetIndex(const TDynList *pList, const TNode *pNode);

/**
 * @brief Does Node Exist in Dynamic List.
 *
 * @details
 * A wrapper for the stDynListGetIndex, checking if the node exists.
 *
 * @param[in] pList   Pointer to the dynamic list to check.
 * @param[in] pNode   Pointer to the node to find.
 * @return `-1` for failure, `0` for not found, `1` for node exists.
 */
int stDynListExists(const TDynList *pList, const TNode *pNode);

/**
 * @brief Remove Node in Dynamic List.
 *
 * @details
 * Removes a node by replacing it with the node at the head.
 *
 * @param[in, out] pList   Pointer to the dynamic list.
 * @param[in]      node    Node to be removed.
 * @return `-1` for failure, or the index of the node removed.
 */
long stDynListRemove(TDynList *pList, const TNode node);

/**
 * @brief Free the Dynamic List.
 *
 * @details
 * Frees the array block of memory.
 *
 * @param[in, out] pList   Pointer to the dynamic list to be freed.
 * @return `0` for failure, `1` for success.
 */
int stDynListFree(TDynList *pList);

#endif /* ST_DYNLIST_H */