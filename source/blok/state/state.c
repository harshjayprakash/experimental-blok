#include "state.h"
#include "../model/vector.h"
#include <stdlib.h>

static int _blokStateMoveBoxImpl(
    TSquare *pBox,
    TDirection direction) 
{
    if (pBox == NULL) {
        return 0;
    }

    TVector2 dirv = blokDirectionToVector(direction);
    TVector2 scaled = blokVectorIIMultiply(dirv, pBox->size);
    TVector2 newpos = blokVectorIIOffset(pBox->position, scaled);
    return blokVectorIICopy(&pBox->position, newpos);
}

int blokStateInit(
    TObjectState *pState,
    const TVector2 scale)
{
    if (pState == NULL) {
        return 0;
    }

    TVector2 defaultBoxState = { 0, 0 };
    TVector2 defaultBoxSize = scale;
    blokVectorIICopy(&pState->box.size, defaultBoxSize);
    blokVectorIICopy(&pState->box.position, defaultBoxState);

    blokDynListInit(&pState->obstructs, 10);

    return 1;
}

int blokStateFree(
    TObjectState *pState)
{
    if (pState == NULL) {
        return 0;
    }

    return blokDynListFree(&pState->obstructs);
}

int blokStateMoveBox(
    TObjectState *pState,
    TDirection direction)
{
    if (pState == NULL) {
        return 0;
    }

    return _blokStateMoveBoxImpl(&pState->box, direction);
}

int blokStateIsBoxMovable(
    TObjectState *pState,
    TDirection direction)
{
    if (pState == NULL) {
        return 0;
    }

    TSquare projected = pState->box;
    int moved = _blokStateMoveBoxImpl(&projected, direction);
    if (!moved) {
        return 0;
    }

    TNode poschk = { projected.position };
    int eidx = blokDynListGetIndex(&pState->obstructs, &poschk);

    if (eidx == -1) {
        return 1;
    }

    return 0;
}

int blokStateAddObstruct(
    TObjectState *pState,
    const TVector2 point)
{
    if (pState == NULL) {
        return -1;
    }

    TNode newPoint = { point };
    int exists = blokDynListExists(&pState->obstructs, &newPoint);
    if (exists) {
        return -1;
    }

    return blokDynListAdd(&pState->obstructs, &newPoint);
}

int blokStateRemoveObstruct(
    TObjectState *pState,
    const TVector2 point)
{
    if (pState == NULL) {
        return 0;
    }

    TNode removePoint = { point };
    return blokDynListRemove(&pState->obstructs, removePoint);
}

int blokStateClearObstructs(
    TObjectState *pState)
{
    if (pState == NULL) {
        return 0;
    }

    return blokDynListClear(&pState->obstructs);
}