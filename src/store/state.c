#include "state.h"
#include "../model/vector.h"

void blokStateInit(State *pState, const VectorII scale)
{
    if (!pState) { return; }

    VectorII defaultBoxState = {0, 0};
    VectorII defaultBoxSize = scale;
    blokVectorIICopy(&pState->box.size, defaultBoxSize);
    blokVectorIICopy(&pState->box.position, defaultBoxState);

    blokDynListInit(&pState->obstructives, 10);
}

void blokStateFree(State *pState)
{
    if (!pState) { return; }

    blokDynListFree(&pState->obstructives);
}

void blokStateMoveBox(Square *pBox, const Direction direction)
{
    if (!pBox) { return; }

    VectorII vector = blokDirectionToVector(direction);
    VectorII scaled = blokVectorIIMultiply(vector, pBox->size);
    VectorII newpos = blokVectorIIAdd(pBox->position, scaled);
    blokVectorIICopy(&pBox->position, newpos);
}

int blokStateBoxMovableInDirection(State *pState, const Direction direction)
{
    if (!pState) { return -1; }

    pState->boxProjected = pState->box;
    blokStateMoveBox(&pState->boxProjected, direction);

    int checkIdx = blokDynListGetIndex(
        &pState->obstructives, 
        &((Node){pState->boxProjected.position}));
    
    if (checkIdx == -1) { return 1; }

    return 0;
}