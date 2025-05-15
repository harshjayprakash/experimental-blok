#include "state.h"
#include "../model/vector.h"
#include <stdlib.h>

static int blokStateMoveBoxImpl(Square *pBox, Direction direction) 
{
    if (pBox == NULL) {
        return 0;
    }

    VectorII dirv = blokDirectionToVector(direction);
    VectorII scaled = blokVectorIIMultiply(dirv, pBox->size);
    VectorII newpos = blokVectorIIAdd(pBox->position, scaled);
    return blokVectorIICopy(&pBox->position, newpos);
}

int blokStateInit(State *pState, const VectorII scale)
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

int blokStateFree(State *pState)
{
    if (pState == NULL) {
        return 0;
    }

    return blokDynListFree(&pState->obstructs);
}

int blokStateMoveBox(State *pState, Direction direction)
{
    if (pState == NULL) {
        return 0;
    }

    return blokStateMoveBoxImpl(&pState->box, direction);
}

int blokStateIsBoxMovable(State *pState, Direction direction)
{
    if (pState == NULL) {
        return 0;
    }

    Square projected = pState->box;
    int moved = blokStateMoveBoxImpl(&projected, direction);
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

int blokStateAddObstruct(State *pState, const VectorII point)
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

int blokStateRemoveObstruct(State *pState, const VectorII point)
{
    if (pState == NULL) {
        return 0;
    }

    Node removePoint = { point };
    return blokDynListRemove(&pState->obstructs, removePoint);
}

int blokStateClearObstructs(State *pState)
{
    if (pState == NULL) {
        return 0;
    }

    return blokDynListClear(&pState->obstructs);
}