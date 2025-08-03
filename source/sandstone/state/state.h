/**
 * @file   state.h
 * @brief  Object State Declarations.
 * @author harshjayprakash
 * @date   2025-08-03
 ****************************************************************************************/

#ifndef ST_STATE_H
#define ST_STATE_H

#include "../model/direction.h"
#include "../model/dynlist.h"
#include "../model/square.h"

/**
 * @brief Object Entity State.
 *
 * @details
 * Represents the current state of entities rendered within the application. The
 * stState* functions manage the data and lifecycle of the state.
 */
typedef struct _State
{
    TSquare box;        /**< Movable box entity. */
    TDynList obstructs; /**< Obstructs list. */
} TObjectState;

/**
 * @brief Initialise the object state.
 *
 * @details
 * Sets the box sizing and attempts to initialise the obstructs dynamic list.
 *
 * @param[out] pState   Pointer to the object state.
 * @param[in]  scale    Grid scaling.
 * @return `1` for success, `0` for failure.
 *
 * @remark
 * - The result must be checked to ensure that the dynamic list has been initialised.
 */
int stStateInit(TObjectState *pState, const TVector2 scale);

/**
 * @brief Free the object state.
 *
 * @details
 * A wrapper for freeing the obstructs dynamic list.
 *
 * @param[in, out] pState   Pointer to the object state.
 * @return `1` for success, `0` for failure.
 */
int stStateFree(TObjectState *pState);

/**
 * @brief Move the box.
 *
 * @details
 * Attempts to move the box in the given direction by the dimensions.
 *
 * @param[in, out] pState      Pointer to the object state.
 * @param[in]      direction   Direction the box is to move.
 * @return `1` for success, `0` for failure.
 */
int stStateMoveBox(TObjectState *pState, TDirection direction);

/**
 * @brief Is box movable in direction.
 *
 * @details
 * Checks if the box is movable in the given direction. This is done by cloning the box,
 * then moving the clone to check if the new position clashes with one of the obstruct
 * walls.
 *
 * @param[in, out] pState      Pointer to the object state.
 * @param[in]      direction   Direction to be checked.
 * @return `1` for movable, `0` for not movable or error.
 */
int stStateIsBoxMovable(TObjectState *pState, TDirection direction);

/**
 * @brief Add an obstruct wall.
 *
 * @details
 * Attempts to add the obstruct point to the list, checking if it exists before
 * performing the operation.
 *
 * @param[in, out] pState   Pointer to the object state.
 * @param[in]      point    Vector2 point to be added.
 * @return `-1` for failure, or the index of the node that was added.
 */
int stStateAddObstruct(TObjectState *pState, const TVector2 point);

/**
 * @brief Remove an obstruct wall.
 *
 * @details
 * Attempts to remove the obstruct point to the list. This is a wrapper for the
 * stDynListRemove.
 *
 * @param[in, out] pState   Pointer to the object state.
 * @param[in]      point    Vector2 point to be removed.
 * @return `-1` for failure, or the index of the node that was removed.
 */
int stStateRemoveObstruct(TObjectState *pState, const TVector2 point);

/**
 * @brief Clear all obstructs.
 *
 * @details
 * Attempts to clear the dynamic list of obstructs.
 *
 * @param[in, out] pState   Pointer to the object state.
 * @return `1` for success, `0` for failure.
 */
int stStateClearObstructs(TObjectState *pState);

#endif /* ST_STATE_H */