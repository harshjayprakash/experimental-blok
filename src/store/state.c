#include "state.h"
#include "../model/vector.h"

void blokStateInit(State *state, const VectorII scale)
{
    if (!state) { return; }

    VectorII defaultBoxState = {0, 0};
    VectorII defaultBoxSize = scale;
    blokVectorIICopy(&state->box.size, defaultBoxSize);
    blokVectorIICopy(&state->box.position, defaultBoxState);

    blokDynListInit(&state->obstructives, 10);
}

void blokStateFree(State *state)
{
    if (!state) { return; }

    blokDynListFree(&state->obstructives);
}

void blokStateMoveBox(Square *box, const Direction direction)
{
    if (!box) { return; }

    VectorII vector = blokDirectionToVector(direction);
    VectorII scaled = blokVectorIIMultiply(vector, box->size);
    VectorII newpos = blokVectorIIAdd(box->position, scaled);
    blokVectorIICopy(&box->position, newpos);
}

int blokStateBoxMovableInDirection(State *state, const Direction direction)
{
    if (!state) { return -1; }

    state->boxProjected = state->box;
    blokStateMoveBox(&state->boxProjected, direction);

    int checkIdx = blokDynListGetIndex(
        &state->obstructives, 
        &((Node){state->boxProjected.position}));
    
    if (checkIdx == -1) { return 1; }

    return 0;
}