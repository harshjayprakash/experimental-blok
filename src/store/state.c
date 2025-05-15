#include "state.h"
#include "../model/vector.h"
#include <stdlib.h>

static int blokStateMoveBoxImpl(Square *pBox, Direction direction) 
{
    if (pBox == NULL)
        return 0;

    VectorII dirv = blokDirectionToVector(direction);
    VectorII scaled = blokVectorIIMultiply(dirv, pBox->size);
    VectorII newpos = blokVectorIIAdd(pBox->position, scaled);
    return blokVectorIICopy(&pBox->position, newpos);
}

int blokStateInit(State *pState, const VectorII scale)
{
    if (pState == NULL)
        return 0;

    VectorII defaultBoxState = {0, 0};
    VectorII defaultBoxSize = scale;
    blokVectorIICopy(&pState->box.size, defaultBoxSize);
    blokVectorIICopy(&pState->box.position, defaultBoxState);

    blokDynListInit(&pState->obstructives, 10);

    return 1;
}

int blokStateFree(State *pState)
{
    if (pState == NULL)
        return 0;

    return blokDynListFree(&pState->obstructives);
}

int blokStateBoxMovableInDirection(State *pState, const Direction direction)
{
    if (pState == NULL)
        return (-1);

    pState->boxProjected = pState->box;
    blokStateMoveBox(&pState->boxProjected, direction);

    int checkIdx = blokDynListGetIndex(
        &pState->obstructives, 
        &((Node){pState->boxProjected.position}));
    
    if (checkIdx == -1)
        return 1;

    return 0;
}

int blokStateMoveBox(State *pState, Direction direction)
{
    if (pState == NULL)
        return 0;

    return blokStateMoveBoxImpl(&(pState->box), direction);
}

int blokStateIsBoxMovable(State *pState, Direction direction)
{
    if (pState == NULL)
        return 0;

    Square projected = pState->box;
    int moved = blokStateMoveBoxImpl(&projected, direction);
    if (!moved)
        return 0;

    Node poschk = { projected.position };
    int eidx = blokDynListGetIndex(&(pState->obstructives), &poschk);

    if (eidx == -1)
        return 1;

    return 0;
}

int blokStateAddObstruct(State *pState, const VectorII point)
{
    if (pState == NULL)
        return (-1);

    Node newPoint = {point};
    int exists = blokDynListExists(&(pState->obstructives), &newPoint);
    if (exists)
        return (-1);

    return blokDynListAdd(&(pState->obstructives), &newPoint);
}

int blokStateRemoveObstruct(State *pState, const VectorII point)
{
    if (pState == NULL)
        return 0;

    Node removePoint = {point};
    return blokDynListRemove(&(pState->obstructives), removePoint);
}

int blokStateClearObstructs(State *pState)
{
    if (pState == NULL)
        return 0;

    return blokDynListClear(&(pState->obstructives));
}