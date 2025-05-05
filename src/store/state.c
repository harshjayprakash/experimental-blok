#include "state.h"
#include "../model/vector.h"
#include <stdlib.h>

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

int blokStateMoveBox(Square *pBox, const Direction direction)
{
    if (pBox == NULL)
        return 0;

    VectorII vector = blokDirectionToVector(direction);
    VectorII scaled = blokVectorIIMultiply(vector, pBox->size);
    VectorII newpos = blokVectorIIAdd(pBox->position, scaled);
    blokVectorIICopy(&pBox->position, newpos);

    return 1;
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