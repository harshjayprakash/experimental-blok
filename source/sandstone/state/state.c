/**
 * @file   state.c
 * @brief  Object State Implementation.
 * @author harshjayprakash
 * @date   2025-08-03
 ****************************************************************************************/

#include "state.h"
#include "../model/vector.h"
#include <stdlib.h>

/**
 * @brief Implementation of moving the box.
 *
 * @details
 * Attempts to move the given box by the dimensions of the box itself.
 *
 * @param[in, out] pBox        Pointer to the box to be moved.
 * @param[in]      direction   Direction to move the box.
 * @return `1` for success, `0` for failure.
 */
static int _stStateMoveBoxImpl(TSquare *pBox, TDirection direction)
{
    if (pBox == NULL)
    {
        return 0;
    }

    TVector2 dirv = stDirectionToVector(direction);
    TVector2 scaled = stVector2Multiply(dirv, pBox->size);
    TVector2 newpos = stVector2Offset(pBox->position, scaled);
    return stVector2Copy(&pBox->position, newpos);
}

int stStateInit(TObjectState *pState, const TVector2 scale)
{
    if (pState == NULL)
    {
        return 0;
    }

    pState->box.position = (TVector2){0, 0};
    pState->box.size = scale;

    return stDynListInit(&pState->obstructs, 10);
}

int stStateFree(TObjectState *pState)
{
    if (pState == NULL)
    {
        return 0;
    }

    return stDynListFree(&pState->obstructs);
}

int stStateMoveBox(TObjectState *pState, TDirection direction)
{
    if (pState == NULL)
    {
        return 0;
    }

    return _stStateMoveBoxImpl(&pState->box, direction);
}

int stStateIsBoxMovable(TObjectState *pState, TDirection direction)
{
    if (pState == NULL)
    {
        return 0;
    }

    TSquare projected = pState->box;
    if (!_stStateMoveBoxImpl(&projected, direction))
    {
        return 0;
    }

    TNode pos = {projected.position};
    if (stDynListGetIndex(&pState->obstructs, &pos) == -1)
    {
        return 1;
    }

    return 0;
}

int stStateAddObstruct(TObjectState *pState, const TVector2 point)
{
    if (pState == NULL)
    {
        return -1;
    }

    TNode newPoint = {point};
    if (stDynListExists(&pState->obstructs, &newPoint) == 1)
    {
        return -1;
    }

    return stDynListAdd(&pState->obstructs, &newPoint);
}

int stStateRemoveObstruct(TObjectState *pState, const TVector2 point)
{
    if (pState == NULL)
    {
        return 0;
    }

    TNode removePoint = {point};
    return stDynListRemove(&pState->obstructs, removePoint);
}

int stStateClearObstructs(TObjectState *pState)
{
    if (pState == NULL)
    {
        return 0;
    }

    return stDynListClear(&pState->obstructs);
}