#include "state.h"
#include "../model/vector.h"

void BlokStateInit(State *state, const VectorII scale)
{
    if (!state) { return; }

    VectorII defaultBoxState = {0, 0};
    VectorII defaultBoxSize = scale;
    BlokVectorIICopy(&state->box.size, defaultBoxSize);
    BlokVectorIICopy(&state->box.position, defaultBoxState);

    BlokDynListInit(&state->obstructives, 10);
}

void BlokStateFree(State *state)
{
    if (!state) { return; }

    BlokDynListFree(&state->obstructives);
}

void BlokStateMoveBox(Square *box, const Direction direction)
{
    if (!box) { return; }

    VectorII vector = BlokDirectionToVector(direction);
    VectorII scaled = BlokVectorIIMultiply(vector, box->size);
    VectorII newpos = BlokVectorIIAdd(box->position, scaled);
    BlokVectorIICopy(&box->position, newpos);
}

int BlokStateBoxMovableInDirection(State *state, const Direction direction)
{
    if (!state) { return -1; }

    state->boxProjected = state->box;
    BlokStateMoveBox(&state->boxProjected, direction);

    int checkIdx = BlokDynListGetIndex(
        &state->obstructives, 
        &((Node){state->boxProjected.position}));
    
    if (checkIdx == -1) { return 1; }

    return 0;
}