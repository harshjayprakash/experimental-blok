/**
 * \file DYNLIST.H
 * \date 22-05-2025
 * \brief Provides the dynamic list and node structure and routines.
 */

#ifndef _BLOK_DYNLIST_H_
#define _BLOK_DYNLIST_H_

#include "vector.h"

/**
 * \brief List node.
 * 
 * \details
 * Provides a wrapper for the node data for easier modification without heavy
 * refactoring.
 */
typedef struct _Node {
    VectorII data;   /**< The point data. */
} Node;

/**
 * \brief Dynamic list.
 * 
 * \details
 * A implementation of dynamically sizing list based on memory allocated to a pointer
 * allowing offsets.
 */
typedef struct _DynList {
    Node *pArr;   /**< The dynamic data array. */
    long head;    /**< The reading head of the last element. */
    long size;    /**< The current size. */
    long max;     /**< The maximum size allocated. */
} DynList;

/**
 * \brief Initialise the dynamic list.
 * 
 * \details
 * Allocates memory to the internal pointer based on the size provided.
 * 
 * \param[in out] pList   The pointer to list to be initialised.
 * \param[in]     size    The starting size of the list.
 * \return                0 for failure, 1 for success.
 */
int blokDynListInit(DynList *pList, const long size);

/**
 * \brief Is list full.
 * 
 * \details
 * Calculates whether the capacity of the list is full.
 * 
 * \param[in] pList   The pointer to the list.
 * \return            0 for failure, 1 for success.
 */
int blokDynListIsFull(const DynList *pList);

/**
 * \brief Is list empty.
 * 
 * \details
 * Calculates whether the capacity of the list is empty.
 * 
 * \param[in] pList   The pointer to the list.
 * \return            0 for failure, 1 for success.
 */
int blokDynListIsEmpty(const DynList *pList);

/**
 * \brief Add node to list.
 * 
 * \details
 * Adds the given node to the list. If the list is full, the list is resized
 * automatically.
 * 
 * \param[in out] pList   The pointer to the list.
 * \param[in]     pNode   The pointer to the node to be added.
 * \return                The index of the added node, -1 for failure, 
 */
long blokDynListAdd(DynList *pList, const Node *pNode);

/**
 * \brief Clear the list.
 * 
 * \details
 * Resets the size counter to 0 and the head pointer to -1. The previous nodes still
 * exist but will be overwritten with newly added nodes.
 * 
 * \param[in out] pList   The pointer to the list.
 * \return                0 for failure, 1 for success.
 */
int blokDynListClear(DynList *pList);

/**
 * \brief Get index of node from list.
 * 
 * \details
 * Retrieves the index of the given node if it exists in the given list.
 * 
 * \param[in] pList   The pointer to the list.
 * \param[in] pNode   The pointer to the node to retrieve the index of.
 * \return            The index of the node,
 *                    -2 for nullptr error,
 *                    -1 for cannot find the node.
 */
long blokDynListGetIndex(const DynList *pList, const Node *pNode);

/**
 * \brief Node exists in the list.
 * 
 * \details
 * Checks if the given node exists in the list.
 * 
 * \param[in] pList   The pointer to the list.
 * \param[in] pNode   The node to check.
 * \return            -1 for nullptr error,
 *                    0 for node does not exist,
 *                    1 for exists.
 */
int blokDynListExists(const DynList *pList, const Node *pNode);

/**
 * \brief Remove node from the list.
 * 
 * \details
 * Overwrites the index of the given node with the head pointer's node, decrementing
 * the head pointer position and size.
 * 
 * \param[in out] pList   The pointer to the list.
 * \param[in]     node    The node to be removed.
 * \return                -1 for not found or nullptr error,
 *                        the index of the removed node.
 */
long blokDynListRemove(DynList *pList, const Node node);

/**
 * \brief Frees the list.
 * 
 * \details
 * Frees the memory allocated to the list.
 * 
 * \param[in out] pList   The pointer to the list.
 * \return                0 for failure, 1 for success.
 */
int blokDynListFree(DynList *pList);

#endif // _BLOK_DYNLIST_H_