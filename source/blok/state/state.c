/**
 * @file STATE.C
 * @date 26-05-2025
 * @brief Implementation of object state functions.
 */

#include "state.h"
#include "../model/vector.h"
#include <stdlib.h>

/**
 * @brief Move the Box (Actual Implementation).
 * 
 * @param[in out] pBox        The box to be moved.
 * @param[in]     direction   The direction the box to move.
 * @return                    0 for failure, 1 for success.
 */
static int _blokStateMoveBoxImpl(
    Square *pBox,
    Direction direction) 
{
    if (pBox == NULL) {
        return 0;
    }

    VectorII dirv = blokDirectionToVector(direction);
    VectorII scaled = blokVectorIIMultiply(dirv, pBox->size);
    VectorII newpos = blokVectorIIOffset(pBox->position, scaled);
    return blokVectorIICopy(&pBox->position, newpos);
}

int blokStateInit(
    State *pState,
    const VectorII scale)
{
    if (pState == NULL) {
        return 0;
    }

    VectorII defaultBoxState = { 0, 0 };
    VectorII defaultBoxSize = scale;
    blokVectorIICopy(&pState->box.size, defaultBoxSize);
    blokVectorIICopy(&pState->box.position, defaultBoxState);

    blokDynListInit(&pState->obstructs, 10);

    return 1;
}

int blokStateFree(
    State *pState)
{
    if (pState == NULL) {
        return 0;
    }

    return blokDynListFree(&pState->obstructs);
}

int blokStateMoveBox(
    State *pState,
    Direction direction)
{
    if (pState == NULL) {
        return 0;
    }

    return _blokStateMoveBoxImpl(&pState->box, direction);
}

int blokStateIsBoxMovable(
    State *pState,
    Direction direction)
{
    if (pState == NULL) {
        return 0;
    }

    Square projected = pState->box;
    int moved = _blokStateMoveBoxImpl(&projected, direction);
    if (!moved) {
        return 0;
    }

    Node poschk = { projected.position };
    int eidx = blokDynListGetIndex(&pState->obstructs, &poschk);

    if (eidx == -1) {
        return 1;
    }

    return 0;
}

int blokStateAddObstruct(
    State *pState,
    const VectorII point)
{
    if (pState == NULL) {
        return -1;
    }

    Node newPoint = { point };
    int exists = blokDynListExists(&pState->obstructs, &newPoint);
    if (exists) {
        return -1;
    }

    return blokDynListAdd(&pState->obstructs, &newPoint);
}

int blokStateRemoveObstruct(
    State *pState,
    const VectorII point)
{
    if (pState == NULL) {
        return 0;
    }

    Node removePoint = { point };
    return blokDynListRemove(&pState->obstructs, removePoint);
}

int blokStateClearObstructs(
    State *pState)
{
    if (pState == NULL) {
        return 0;
    }

    return blokDynListClear(&pState->obstructs);
}