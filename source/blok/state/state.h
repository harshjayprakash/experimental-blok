/**
 * \file STATE.H
 * \date 26-05-2025
 * \brief Provides the object state structure and functions.
 */

#ifndef _BLOK_STATE_H_
#define _BLOK_STATE_H_

#include "../model/direction.h"
#include "../model/square.h"
#include "../model/dynlist.h"

/**
 * \brief Object State.
 * 
 * \details
 * Represents the state of the runtime objects. 
 */
typedef struct _State {
    Square box;          /**< The box information. */
    DynList obstructs;   /**< The obstructs list. */
} State;

/**
 * \brief Initialise the object state.
 *
 * \details
 * Sets the default box state at (0, 0) and the given box size. An initial 10 items is
 * allocated to the dynamic obstructs list.
 * 
 * \param[in out] pState   The pointer to the object state.
 * \param[in]     scale    The grid scale.
 * \return                 0 for failure, 1 for success.
 */
int blokStateInit(State *pState, const VectorII scale);

/**
 * \brief Free the object state.
 * 
 * \details
 * Cleans up the dynamic obstructs list.
 *
 * \param[in out] pState   The pointer to the object state.
 * \return                 0 for failure, 1 for success. 
 */
int blokStateFree(State *pState);

/**
 * \brief Move the box.
 * 
 * \details
 * Moves the box position in the given direction.
 *
 * \param[in out] pState      The pointer to the object state.
 * \param[in]     direction   The direction to be moved.
 * \return                    0 for failure, 1 for success.
 */
int blokStateMoveBox(State *pState, Direction direction);

/**
 * \brief Check Box Movablity.
 *
 * \details
 * Checks if the box can be moved in the given direction, based on the list of obstructs.
 * 
 * \param[in out] pState      The pointer to the object state.
 * \param[in]     direction   The direction to be checked.
 * \return                    1 for movable, 0 for not movable.
 */
int blokStateIsBoxMovable(State *pState, Direction direction);

/**
 * \brief Add an Obstruct.
 *
 * \details
 * Add an obstruct to the list, if and only if the given position has not been marked. 
 * 
 * \param[in out] pState   The pointer to the object state.
 * \param[in]     point    The point to be added.
 * \return                 Negative number for failure, 
 *                         The index of the point in the list.
 */
int blokStateAddObstruct(State *pState, const VectorII point);

/**
 * \brief Remove an Obstruct.
 *
 * \details
 * Removes the given point from the obstructs list.
 * 
 * \param[in out] pState   The pointer to the object state. 
 * \param[in]     point    The point to be removed.
 * \return                 (__CONFLICT__)
 */
int blokStateRemoveObstruct(State *pState, const VectorII point);

/**
 * \brief Clear Obstructs.
 *
 * \details
 * Clears all the obstructs in the list.
 * 
 * \param[in out] pState   The pointer to the object state.
 * \return                 0 for failure, 1 for success.
 */
int blokStateClearObstructs(State *pState);


#endif // _BLOK_STATE_H_